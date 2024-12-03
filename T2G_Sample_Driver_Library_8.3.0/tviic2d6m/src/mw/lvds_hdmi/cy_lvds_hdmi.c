/***************************************************************************//**
* \file cy_lvds_hdmi.c
* \version 1.0
*
* \brief
* Provides an API definition of the LVDS to HDMI transmission driver.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include <stdio.h>
#include "cy_project.h"
#include "cy_device_headers.h"
#include "cy_lvds_hdmi.h"

/* Only applicable for the lite kit */
#ifdef CY_327BGA_EVKLITE_rev_a

#include "cy_it6263_config.h"
#include "cy_i2c_hdmi.h"


/* Flag to check validity of sensor during initialization */
static bool glIsValidSensor = false;
volatile uint8_t cBuf[128];

static cy_un_hdmi_rx_cap_t hdmiRxCapability;
static cy_stc_hdmi_instance_config_t hdmiInstanceData;
static cy_un_hdmi_avi_infotrame_t aviInfoFrame;
static cy_un_hdmi_vendor_infotrame_t vsInfoFrame;

/* HDMI data structure for status */
cy_stc_hdmi_trx_status_t hdmiStatus = 
{
    .hdmiHpdStatus          = false,
    .hdmiHpdChangeStatus    = false,
    .hdmiReGenTimingEnable  = false,
    .hdmiIsChangeMode       = false,
    .hdmiVideoModeSelect    = 0u,
    .hdmiOutputColorDepth   = 24u,
    .hdmiVIC                = CY_HDMI_800x480p60,
    .hdmi3DFormat           = 0xFF,
    .hdmiPixelRep           = 0u,
    .hdmiVideoPixelClock    = 0u,
    .hdmiInputColorFormat   = 0u,
    .hdmiColorimetry        = CY_HDMI_COLORIMETRY_ITU601,
    .hdmiAspectRatio        = CY_HDMI_ASPECT_RATIO_4x3,
};

/* HDMI video default configuration */
cy_stc_hdmi_trx_config_t hdmiConfig =
{
    .colorBits      = CY_LVDS_LINK_8BIT,
    .singleOrDual   = CY_LVDS_LINK_SINGLE,
    .encodeFormat   = CY_LVDS_FORMAT_JEIDA,
    .colorFormat    = CY_HDMI_COLOR_RGB444,
    .videoType      = CY_HDMI_640x480p60,
};

/* HDMI data structure for vendor EDID */
cy_stc_hdmi_vendor_edid_t hdmiDisplayEDID[] = 
{
    {
      .hdmiVendorName = DELL_2408WPF,
      //.hdmiVIDC       = {0x10, 0xAC, 0x2C, 0xA0, 0x53, 0x33, 0x47, 0x31}
      .hdmiVIDC       = {0x53, 0x04, 0x00, 0x00, 0x45, 0x54, 0x00, 0x00}
    },
    {
      .hdmiVendorName = HP_E27_G4,
      .hdmiVIDC       = {0x22, 0x0E, 0x93, 0x36, 0x01, 0x01, 0x01, 0x01}
    },
    {
      .hdmiVendorName = HP_E27M_G4,
      .hdmiVIDC       = {0x22, 0x0E, 0x53, 0x37, 0x01, 0x01, 0x01, 0x01}
    },
    {
      .hdmiVendorName = LONTIUM_Semi,
      .hdmiVIDC       = {0x31, 0xEE, 0x02, 0x2C, 0x01, 0x01, 0x01, 0x01}
    },
    {
      .hdmiVendorName = WAVESHARE_7inch,
      .hdmiVIDC       = {0x30, 0xAE, 0x86, 0x10, 0x01, 0x01, 0x01, 0x01}
    },
    {
      .hdmiVendorName = WAVESHARE_5inch,
      .hdmiVIDC       = {0x04, 0x81, 0x04, 0x00, 0x01, 0x00, 0x00, 0x00}
    }
};


/* HDMI transceiver specific functions */
static cy_en_hdmi_trx_status_t Cy_IT6263_InitBase(cy_stc_hdmi_trx_config_t videoParam);
static cy_en_hdmi_trx_status_t Cy_IT6263_InitPeripherals(void);
static cy_en_hdmi_trx_status_t Cy_IT6263_Reset(void);
static cy_en_hdmi_trx_status_t Cy_IT6263_VerifyChipId(void);

/* HDMI interface specific functions */
static void Cy_IT6263_HDMI_ConfigVSInfoFrame(uint8_t hdmi3DMode);
static void Cy_IT6263_HDMI_ConfigAVIInfoFrame(uint8_t vid, uint8_t pixelRep);
static bool Cy_IT6263_HDMI_ParseEDID(void);
static bool Cy_IT6263_HDMI_ParseCEAEDID(volatile uint8_t* pCEAEDID);

static cy_en_hdmi_trx_status_t Cy_IT6263_HDMI_SetVideoOutput(void);
static cy_en_hdmi_trx_status_t Cy_IT6263_HDMI_DetectVideoMode(void);


/*******************************************************************************
* Function Name: Cy_IT6263_InitBase
****************************************************************************//**
*
* \brief
* Intitialize the chip specific function for IT6263.
*
* \param
* videoParam : video type parameters, refer cy_stc_hdmi_trx_config_t
*
* \return
* cy_en_hdmi_trx_status_t : function result type
*
*******************************************************************************/
static cy_en_hdmi_trx_status_t Cy_IT6263_InitBase(cy_stc_hdmi_trx_config_t videoParam)
{
    cy_en_hdmi_trx_status_t status = CY_HDMI_TRX_SUCCESS;

    /* Update the instance init data */
    hdmiInstanceData.I2C_DEV = 0;
    hdmiInstanceData.I2C_ADDR = CY_IT6263_I2C_ADRESS;
    hdmiInstanceData.bIntType = 0x40;
    hdmiInstanceData.bInputVideoSignalType = HDMI_INPUT_SIGNAL_TYPE;
    hdmiInstanceData.TMDSClock = 0;
    hdmiInstanceData.bAuthenticated = false;
    hdmiInstanceData.bHDMIMode = false;
    hdmiInstanceData.bIntPOL = false;
    hdmiInstanceData.bHPD = false;
    Cy_IT6263_InitInstance(&hdmiInstanceData);

    /* Update the status */
    hdmiStatus.hdmiHpdStatus = false;
    hdmiStatus.hdmiHpdChangeStatus = false;

    /* Copy lvds base configuration */
    memcpy(&hdmiConfig, &videoParam, sizeof(cy_stc_hdmi_trx_config_t));

    /* Initialize the base configuration */
    Cy_IT6263_Init();

    return status;
}

/*******************************************************************************
* Function Name: Cy_IT6263_InitPeripherals
****************************************************************************//**
*
* \brief
* Intitialize the chip specific peripherals IT6263 chip.
*
* \param  none
*
* \return
* cy_en_hdmi_trx_status_t : function result type
*
*******************************************************************************/
static cy_en_hdmi_trx_status_t Cy_IT6263_InitPeripherals(void)
{
    cy_stc_gpio_pin_config_t hdmi_trx_port_pin_cfg;
    cy_en_hdmi_trx_status_t status = CY_HDMI_TRX_SUCCESS;

    /* Configure the RST control for the chip */
    hdmi_trx_port_pin_cfg.driveMode = CY_GPIO_DM_STRONG_IN_OFF;
    hdmi_trx_port_pin_cfg.hsiom = CY_FPD_HDMI_RST_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_FPD_HDMI_RST_PORT, CY_FPD_HDMI_RST_PIN, &hdmi_trx_port_pin_cfg);

    /* Take the chip out from the reset */
    Cy_GPIO_Write(CY_FPD_HDMI_RST_PORT, CY_FPD_HDMI_RST_PIN, 1u);

    /* Initialize the corresponding SCB-I2C instance */
    Cy_IT6263_I2C_Init();
    
    /* Iitialize the timer for 1ms */

    return status;
}

/*******************************************************************************
* Function Name: Cy_IT6263_Reset
****************************************************************************//**
*
* \brief
* Function to reset an IT6263 chip.
*
* \param  none
*
* \return
* cy_en_hdmi_trx_status_t : function result type
*
*******************************************************************************/
static cy_en_hdmi_trx_status_t Cy_IT6263_Reset(void)
{
    cy_en_hdmi_trx_status_t status = CY_HDMI_TRX_SUCCESS;

    /* Pull the reset pin low */
    Cy_GPIO_Write(CY_FPD_HDMI_RST_PORT, CY_FPD_HDMI_RST_PIN, 0u);

    /* Delay to do complete reset */
    Cy_SysTick_DelayInUs(CY_IT6263_CMD_IN_BW_DELAY);

    /* Pull the reset pin high */
    Cy_GPIO_Write(CY_FPD_HDMI_RST_PORT, CY_FPD_HDMI_RST_PIN, 1u);

    return status;
}

/*******************************************************************************
* Function Name: Cy_IT6263_VerifyChipId
****************************************************************************//**
*
* \brief
* Function to verify that the streamer is an IT6263 chip.
*
* \param  none
*
* \return
* cy_en_hdmi_trx_status_t : function result type
*
* \note 
* Sets a global variable glIsValidSensor for further communication, needs
* to be called just after init();
*
*******************************************************************************/
static cy_en_hdmi_trx_status_t Cy_IT6263_VerifyChipId(void)
{
    uint8_t readBuffer[3] = {0};
    cy_en_hdmi_trx_status_t status = CY_HDMI_TRX_SUCCESS;

    readBuffer[0] = Cy_IT6263_I2C_Read(CY_IT6263_I2C_ADRESS, REG_TX_VENDOR_ID0);
    readBuffer[0] = Cy_IT6263_I2C_Read(CY_IT6263_I2C_ADRESS, REG_TX_VENDOR_ID0);
    readBuffer[1] = Cy_IT6263_I2C_Read(CY_IT6263_I2C_ADRESS, REG_TX_DEVICE_ID0);
    readBuffer[2] = Cy_IT6263_I2C_Read(CY_IT6263_I2C_ADRESS, REG_TX_DEVICE_ID1);

    if ((CY_IT6263_CHIP_VENDOR_ID != readBuffer[0]) || (CY_IT6263_CHIP_DEVICE_ID != readBuffer[1]) || (CY_IT6263_CHIP_REV_ID != readBuffer[2]))
    {
        status = CY_HDMI_TRX_BAD_PARAM;
    }
    else
    {
        glIsValidSensor = true;
    }
    return status;
}

/*******************************************************************************
* Function Name: Cy_IT6263_HDMI_DetectVideoMode
****************************************************************************//**
*
* \brief
* Function to detect the HDMI video configuration of the IT6263 chip.
*
* \param
* cy_en_hdmi_color_format_type_t : sensor color format and sequence type
*
* \return
* cy_en_hdmi_trx_status_t : function result type
*
*******************************************************************************/
static cy_en_hdmi_trx_status_t Cy_IT6263_HDMI_DetectVideoMode(void)
{
    cy_en_hdmi_trx_status_t status = CY_HDMI_TRX_SUCCESS;
    static bool forceUpdate = true;

    if(Cy_IT6263_IsLvdsStable() == false)
    {
        forceUpdate = true;
        return CY_HDMI_TRX_ERROR;
    }
    
    if(forceUpdate)
    {
#ifdef DEBUG_IT6263      
        printf("VideoModeDetect()\n\r");
#endif
        /* turn off Regentiming at first. */
        hdmiStatus.hdmiVIC = CY_HDMI_800x480p60;
        forceUpdate = false;
        
#ifdef SUPPORT_REGEN_TIMING
        if(Cy_IT6263_HdmiReGenTiming(hdmiStatus.hdmiVIC))
        {
            hdmiStatus.hdmiReGenTimingEnable = true;
    #ifdef DEBUG_IT6263            
            printf("USE RE GEN TIMING FORMAT %d\n\r", hdmiStatus.hdmiVIC);
    #endif
        }
        else
        {
            hdmiStatus.hdmiReGenTimingEnable = false;
    #ifdef DEBUG_IT6263            
            printf("NO RE GEN TIMING MTACH %d\n\r", hdmiStatus.hdmiVIC);
    #endif            
        }
#else
        hdmiStatus.hdmiVIC = (cy_en_hdmi_video_type_t) Cy_IT6263_DetectVIC();
#endif
        CY_HDMI_Transceiver_SetDisplayOption(hdmiStatus.hdmiVIC, CY_HDMI_COLOR_RGB444);
    }
    
    return status;
}

/*******************************************************************************
* Function Name: Cy_IT6263_HDMI_ParseEDID
****************************************************************************//**
*
* \brief
* Parse the EDID frame data for HDMI interface.
*
* \param none
*
* \return
* bool : status of the api
*
*******************************************************************************/
static bool Cy_IT6263_HDMI_ParseEDID(void)
{
    // collect the EDID ucdata of segment 0
    uint8_t i, checkSum, blockCount, monitorCnt, ccCnt;
    uint8_t bValidCEA = false;
    bool bForceCTS = false, err = false;

    hdmiRxCapability.ValidCEA = false;
    hdmiRxCapability.ValidHDMI = false;

#ifdef DEBUG_IT6263
    printf("Parsing EDID...\n\r");
#endif
            
    /* Get the EDID */
    Cy_IT6263_HDMI_GetEDIDData(0, cBuf);
    for(i=0, checkSum=0; i<128; i++)
    {
        checkSum += cBuf[i];
        checkSum &= 0xFF;
    }
    if(checkSum != 0)
    {
        return false;
    }

    if( cBuf[0] != 0x00 ||
        cBuf[1] != 0xFF ||
        cBuf[2] != 0xFF ||
        cBuf[3] != 0xFF ||
        cBuf[4] != 0xFF ||
        cBuf[5] != 0xFF ||
        cBuf[6] != 0xFF ||
        cBuf[7] != 0x00)
    {
        return false;
    }

    for(monitorCnt=0; monitorCnt<Unknown_Display; monitorCnt++)
    {
        for(ccCnt=0; ccCnt<8; ccCnt++)
        {
            if(cBuf[0x08+ccCnt] != hdmiDisplayEDID[monitorCnt].hdmiVIDC[ccCnt])
            {
                break;
            }
        }
        if(ccCnt == 8)
        {
#ifdef DEBUG_IT6263
            printf("Display EDID found <%d>.\n\r", monitorCnt);
#endif
            bForceCTS = true;
            err = bForceCTS;
            break;
        }
    }

    blockCount = cBuf[0x7E];
    if(blockCount == 0)
    {
        return true;
    }
    else if (blockCount > 4)
    {
        blockCount = 4;
    }

    hdmiRxCapability.ValidHDMI = false;

    /* read all segment for test */
    for(i=1; i<=blockCount; i++)
    {
        err = Cy_IT6263_HDMI_GetEDIDData(i, cBuf);
        if(err == true)
        {
            if( !hdmiRxCapability.ValidHDMI && cBuf[0] == 0x2 && cBuf[1] == 0x3)
            {
#ifdef DEBUG_IT6263
                printf("Parsing CEAEDID block <%d>.\n\r", blockCount);
#endif 
                err = Cy_IT6263_HDMI_ParseCEAEDID(cBuf);
                if(err == true)
                {
                    if(hdmiRxCapability.IEEEOUI == HDMI_IEEEOUI)
                    {
                        bValidCEA = true;
                        err = bValidCEA;
                    }

                }
            }
        }
    }

    for(i=0; i<128; i++)
    {
        cBuf[i] = 0;
    }

    return err;
}

/*******************************************************************************
* Function Name: Cy_IT6263_HDMI_ParseCEAEDID
****************************************************************************//**
*
* \brief
* Parse the CEAEDID frame data for HDMI interface.
*
* \param
* pCEAEDID : pointer to CEAEDID data
*
* \return
* bool : status of the api
*
*******************************************************************************/
static bool Cy_IT6263_HDMI_ParseCEAEDID(volatile uint8_t* pCEAEDID)
{
    uint8_t offset, end, count, tag;
    int8_t i;
/*
    uint8_t pCEAEDID [128] = {
        0x02, 0x03, 0x19, 0xB1, 0x49, 0x90, 0x1F, 0x04, 0x13, 0x03, 0x12, 0x02, 0x11, 0x01, 0x67, 0x03,
        0x0C, 0x00, 0x10, 0x00, 0x00, 0x22, 0xE2, 0x00, 0x6B, 0x02, 0x3A, 0x80, 0x18, 0x71, 0x38, 0x2D,
        0x40, 0x58, 0x2C, 0x45, 0x00, 0x56, 0x51, 0x21, 0x00, 0x00, 0x1E, 0x02, 0x3A, 0x80, 0xD0, 0x72,
        0x38, 0x2D, 0x40, 0x10, 0x2C, 0x45, 0x80, 0x56, 0x51, 0x21, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE1
    };
*/    
    /* Check if no CEA block */
    if( pCEAEDID[0] != 0x02 || pCEAEDID[1] != 0x03)
    {
        return true;
    }

    end = pCEAEDID[2]; // CEA description.
    hdmiRxCapability.VideoMode = pCEAEDID[3];
    hdmiRxCapability.VDOModeCount = 0;
    hdmiRxCapability.idxNativeVDOMode = 0xff;

#ifdef DEBUG_IT6263
    printf("Video data block:\n\r");
#endif    
    
    for(offset=4; offset<end; )
    {
        tag = pCEAEDID[offset] >> 5 ;
        count = pCEAEDID[offset] & 0x1f ;
        switch(tag)
        {
            // Audio Data Block
            case 0x01: 
                offset++;
                break;

            // Video Data Block
            case 0x02:
                //hdmiRxCapability.VDOModeCount = 0 ;
                offset++;
                for(i =0, hdmiRxCapability.idxNativeVDOMode = 0xff; i<count; i++, offset++)
                {
                    uint8_t VIC ;
                    VIC = pCEAEDID[offset] & (~0x80);
#ifdef DEBUG_IT6263
                    printf("VIC <%d>.\n\r", VIC);
#endif                    
                    //if(FindModeTableEntryByVIC(VIC) != -1)
                    {
                        hdmiRxCapability.VDOMode[hdmiRxCapability.VDOModeCount] = VIC;
                        if(pCEAEDID[offset] & 0x80)
                        {
                            hdmiRxCapability.idxNativeVDOMode = (uint8_t) hdmiRxCapability.VDOModeCount;
                        }
                        hdmiRxCapability.VDOModeCount++;
                    }
                }
                /////////////////////////////////////////////// AKSF: added workaround
                hdmiRxCapability.IEEEOUI = HDMI_IEEEOUI;
                hdmiRxCapability.ValidHDMI = true;
                hdmiRxCapability.ValidCEA = true;
                break;

            // Vendor Specific Data Block
            case 0x03:
                for(i=0; i<count; i++)
                {
                    hdmiRxCapability.HDMI_VSDB[i] = pCEAEDID[i+offset];
#ifdef DEBUG_IT6263
                    printf("HDMI_VSDB[%d]= %x\n\r", i, hdmiRxCapability.HDMI_VSDB[i]);
#endif                    
                }
                
                offset++;
                hdmiRxCapability.IEEEOUI = (uint32_t)pCEAEDID[offset+2];
                hdmiRxCapability.IEEEOUI <<= 8;
                hdmiRxCapability.IEEEOUI += (uint32_t)pCEAEDID[offset+1];
                hdmiRxCapability.IEEEOUI <<= 8;
                hdmiRxCapability.IEEEOUI += (uint32_t)pCEAEDID[offset];
                offset += count ; // ignore the remaind.

                if(hdmiRxCapability.IEEEOUI == HDMI_IEEEOUI)
                {
                    hdmiRxCapability.ValidHDMI = true;
                }
                break;

            // Speaker Data Block
            case 0x04:
                
                break;

            // VESA Data Block
            case 0x05:
                offset += count+1;
                break;

            // Extended Data Block
            case 0x07:
                offset += count+1;
                break;

            default:
                offset += count+1;
        }
    }
    hdmiRxCapability.ValidCEA = true;
    return true;
}

/*******************************************************************************
* Function Name: Cy_IT6263_HDMI_ConfigAVIInfoFrame
****************************************************************************//**
*
* \brief
* Configure the vendor specific info frames for HDMI interface.
*
* \param
* vic : vic value
*
* \param
* pixelRep : vic value
*
* \return none
*
*******************************************************************************/
static void Cy_IT6263_HDMI_ConfigAVIInfoFrame(uint8_t vic, uint8_t pixelRep)
{
#ifdef DEBUG_IT6263
    printf("ConfigAVIInfoFrame(%d)\n\r", vic) ;
#endif
    
    aviInfoFrame.pktbyte.AVI_HB[0] = AVI_INFOFRAME_TYPE | 0x80;
    aviInfoFrame.pktbyte.AVI_HB[1] = AVI_INFOFRAME_VER;
    aviInfoFrame.pktbyte.AVI_HB[2] = AVI_INFOFRAME_LEN;
    aviInfoFrame.pktbyte.AVI_DB[0] = (0<<5) | (1<<4);      // RGB Only
    aviInfoFrame.pktbyte.AVI_DB[1] = 8;
    if(vic)
    {
        aviInfoFrame.pktbyte.AVI_DB[1] |= (hdmiStatus.hdmiAspectRatio != CY_HDMI_ASPECT_RATIO_16x9) ? (1<<4) : (2<<4); // 4:3 or 16:9
    }
    else
    {
        aviInfoFrame.pktbyte.AVI_DB[1] &= (0xcf);
    }

    aviInfoFrame.pktbyte.AVI_DB[1] |= (hdmiStatus.hdmiColorimetry != CY_HDMI_COLORIMETRY_ITU709) ? (1<<6) : (2<<6); // 4:3 or 16:9
    aviInfoFrame.pktbyte.AVI_DB[2] = 0;
    aviInfoFrame.pktbyte.AVI_DB[3] = vic;
    aviInfoFrame.pktbyte.AVI_DB[4] = pixelRep & 3;
    aviInfoFrame.pktbyte.AVI_DB[5] = 0;
    aviInfoFrame.pktbyte.AVI_DB[6] = 0;
    aviInfoFrame.pktbyte.AVI_DB[7] = 0;
    aviInfoFrame.pktbyte.AVI_DB[8] = 0;
    aviInfoFrame.pktbyte.AVI_DB[9] = 0;
    aviInfoFrame.pktbyte.AVI_DB[10] = 0;
    aviInfoFrame.pktbyte.AVI_DB[11] = 0;
    aviInfoFrame.pktbyte.AVI_DB[12] = 0;

    Cy_IT6263_HdmiEnableAVIInfoFrame(true, (uint8_t*) &aviInfoFrame);
}

/*******************************************************************************
* Function Name: Cy_IT6263_HDMI_ConfigVSInfoFrame
****************************************************************************//**
*
* \brief
* Configure the vendor specific info frames for HDMI interface.
*
* \param
* hdmi3DMode : mode of thr frame
*
* \return none
*
*******************************************************************************/
static void Cy_IT6263_HDMI_ConfigVSInfoFrame(uint8_t hdmi3DMode)
{
    vsInfoFrame.pktbyte.VS_HB[0] = VENDORSPEC_INFOFRAME_TYPE | 0x80;
    vsInfoFrame.pktbyte.VS_HB[1] = VENDORSPEC_INFOFRAME_VER;

    vsInfoFrame.pktbyte.VS_DB[1] = 0x03;
    vsInfoFrame.pktbyte.VS_DB[2] = 0x0C;
    vsInfoFrame.pktbyte.VS_DB[3] = 0x00;
    vsInfoFrame.pktbyte.VS_DB[4] = 0x40;
    switch(hdmi3DMode)
    {
        case VS3D_MODE_SIDE_BY_SIDE:
            vsInfoFrame.pktbyte.VS_HB[2] = 6;
            vsInfoFrame.pktbyte.VS_DB[5] = (hdmi3DMode << 4);
            vsInfoFrame.pktbyte.VS_DB[6] = 0x00;
            break;

        case VS3D_MODE_TOP_AND_BOTTOM:
        case VS3D_MODE_FRAME_PACKING:
            vsInfoFrame.pktbyte.VS_HB[2] = 5;
            vsInfoFrame.pktbyte.VS_DB[5] = (hdmi3DMode << 4);
            break ;
        default:
            Cy_IT6263_HdmiEnableVSInfoFrame(false, NULL);
            return;
    }

    Cy_IT6263_HdmiEnableVSInfoFrame(true, (uint8_t*) &vsInfoFrame);
}

/*******************************************************************************
* Function Name: Cy_IT6263_HDMI_SetVideoOutput
****************************************************************************//**
*
* \brief
* Set the video mode output for HDMI interface.
*
* \param none
*
* \return
* cy_en_hdmi_trx_status_t : function result type
*
*******************************************************************************/
static cy_en_hdmi_trx_status_t Cy_IT6263_HDMI_SetVideoOutput(void)
{
    uint8_t uc, pclkLevel;
    uint32_t cTMDSClock = hdmiStatus.hdmiVideoPixelClock * (hdmiStatus.hdmiPixelRep + 1);
    cy_en_hdmi_trx_status_t status = CY_HDMI_TRX_SUCCESS;
    
    /* Disable audio output */
    Cy_IT6263_HdmiDisableAudioOutput();

    /* Get the PCLK clock info */
    uc = HDMI_Read_Byte(0xc1);
    switch(uc & 0x70)
    {
        case 0x50:
            cTMDSClock *= 5 ;
            cTMDSClock /= 4 ;
            break;
        case 0x60:
            cTMDSClock *= 3 ;
            cTMDSClock /= 2 ;
            break;
    }

    /* Set the PCLK clock level */
    if(cTMDSClock > 80000000L)
    {
        pclkLevel = CY_HDMI_PCLK_HIGH;
    }
    else if(cTMDSClock > 20000000L)
    {
        pclkLevel = CY_HDMI_PCLK_MEDIUM;
    }
    else
    {
        pclkLevel = CY_HDMI_PCLK_LOW;
    }

    /* Set the color depth and phase */
    Cy_IT6263_HdmiSetColorOutputDepth(hdmiStatus.hdmiOutputColorDepth, 0);

    /* Set HDMI video input mode */
    Cy_IT6263_HdmiSetVideoInput(hdmiInstanceData.bInputVideoSignalType);

    /* Enable the video output */
    Cy_IT6263_HdmiEnableVideoOutput((cy_en_hdmi_video_pclk_t) pclkLevel, CY_HDMI_COLOR_RGB444, CY_HDMI_COLOR_RGB444, (uint8_t)hdmiInstanceData.bHDMIMode);

    /* Check if the correct HDMI mode */
    if(hdmiInstanceData.bHDMIMode)
    {
        Cy_IT6263_HDMI_ConfigAVIInfoFrame(hdmiStatus.hdmiVIC, hdmiStatus.hdmiPixelRep);
        Cy_IT6263_HDMI_ConfigVSInfoFrame(hdmiStatus.hdmi3DFormat);
        // Cy_IT6263_HDMI_ConfigVSInfoFrame(VS3D_MODE_SIDE_BY_SIDE);
        // Cy_IT6263_HDMI_ConfigVSInfoFrame(VS3D_MODE_FRAME_PACKING);
        // Cy_IT6263_HDMI_ConfigVSInfoFrame(VS3D_MODE_TOP_AND_BOTTOM);
        Cy_IT6263_SetAVMute(false);
    }
    else
    {
        Cy_IT6263_HdmiEnableAVIInfoFrame(false, NULL);
        Cy_IT6263_HdmiEnableVSInfoFrame(false, NULL);
        Cy_IT6263_SetAVMute(false);
    }

    hdmiStatus.hdmiIsChangeMode = false;
    return status;
}

/*******************************************************************************
* Function Name: Cy_HDMI_Transceiver_Wakeup
****************************************************************************//**
*
* \brief
* LVDS to HDMI transceiver wakeup call.
*
* \param none
*
* \return
* cy_en_hdmi_trx_status_t : function result type
*
*******************************************************************************/
cy_en_hdmi_trx_status_t Cy_HDMI_Transceiver_Wakeup(void)
{
    cy_en_hdmi_trx_status_t status = CY_HDMI_TRX_SUCCESS;
      
    if (glIsValidSensor != true)
    {
        return CY_HDMI_TRX_ERROR;
    }

    
    return status;
}

/*******************************************************************************
* Function Name: Cy_HDMI_Transceiver_Sleep
****************************************************************************//**
*
* \brief
* LVDS to HDMI transceiver sleep call.
*
* \param none
*
* \return
* cy_en_hdmi_trx_status_t : function result type
*
*******************************************************************************/
cy_en_hdmi_trx_status_t Cy_HDMI_Transceiver_Sleep(void)
{
    cy_en_hdmi_trx_status_t status = CY_HDMI_TRX_SUCCESS;

    if (glIsValidSensor != true)
    {
        return CY_HDMI_TRX_ERROR;
    }

    return status;
}

/*******************************************************************************
* Function Name: CY_HDMI_Transceiver_SetDisplayOption
****************************************************************************//**
*
* \brief
* Initializes the LVDS to HDMI transceiver with configurable options.
*
* \param
* cy_en_hdmi_video_type_t : video mode type
*
* \param
* cy_en_hdmi_color_format_type_t : video color format
*
* \return
* cy_en_hdmi_trx_status_t : function result type
*
* \note 
* SCB7 is used as a sensor control interface, do not change it. Should be
* called before calling any other image sensor api.
*
*******************************************************************************/
cy_en_hdmi_trx_status_t CY_HDMI_Transceiver_SetDisplayOption(cy_en_hdmi_video_type_t videoMode, cy_en_hdmi_color_format_type_t colorMode)
{
    cy_en_hdmi_trx_status_t status = CY_HDMI_TRX_SUCCESS;

    hdmiStatus.hdmi3DFormat = 0xFF;
    
#ifdef DEBUG_IT6263
    printf("HDMITX_ChangeDisplayOption(%d)\n\r", videoMode);
#endif
    
    switch(videoMode)
    {
        case CY_HDMI_800x480p60:
            hdmiStatus.hdmiVIC              = CY_HDMI_800x480p60;
            hdmiStatus.hdmiVideoPixelClock  = 38000000L;
            hdmiStatus.hdmiPixelRep         = 0u;
            hdmiStatus.hdmiAspectRatio      = CY_HDMI_ASPECT_RATIO_4x3;
            hdmiStatus.hdmiColorimetry      = CY_HDMI_COLORIMETRY_ITU601;
            break;
            
        case CY_HDMI_640x480p60:
            hdmiStatus.hdmiVIC              = CY_HDMI_640x480p60;
            hdmiStatus.hdmiVideoPixelClock  = 25000000L;
            hdmiStatus.hdmiPixelRep         = 0u;
            hdmiStatus.hdmiAspectRatio      = CY_HDMI_ASPECT_RATIO_4x3;
            hdmiStatus.hdmiColorimetry      = CY_HDMI_COLORIMETRY_ITU601;
            break;

        case CY_HDMI_480p60:
            hdmiStatus.hdmiVIC              = CY_HDMI_480p60;
            hdmiStatus.hdmiVideoPixelClock  = 27000000L;
            hdmiStatus.hdmiPixelRep         = 0u;
            hdmiStatus.hdmiAspectRatio      = CY_HDMI_ASPECT_RATIO_4x3;
            hdmiStatus.hdmiColorimetry      = CY_HDMI_COLORIMETRY_ITU601;
            break;

        case CY_HDMI_480p60_16x9:
            hdmiStatus.hdmiVIC              = CY_HDMI_480p60_16x9;
            hdmiStatus.hdmiVideoPixelClock  = 27000000L;
            hdmiStatus.hdmiPixelRep         = 0u;
            hdmiStatus.hdmiAspectRatio      = CY_HDMI_ASPECT_RATIO_16x9;
            hdmiStatus.hdmiColorimetry      = CY_HDMI_COLORIMETRY_ITU601;
            break;
            
        case CY_HDMI_600p60:
            hdmiStatus.hdmiVIC              = CY_HDMI_600p60;
            //hdmiStatus.hdmiVideoPixelClock  = 48960000L;
            hdmiStatus.hdmiVideoPixelClock  = 50250000L;
            hdmiStatus.hdmiPixelRep         = 0u;
            //hdmiStatus.hdmiAspectRatio      = CY_HDMI_ASPECT_RATIO_4x3;
            hdmiStatus.hdmiAspectRatio      = CY_HDMI_ASPECT_RATIO_16x9;
            //hdmiStatus.hdmiColorimetry      = CY_HDMI_COLORIMETRY_ITU601;
            hdmiStatus.hdmiColorimetry      = CY_HDMI_COLORIMETRY_ITU709;
            break;

        case CY_HDMI_720p60:
            hdmiStatus.hdmiVIC              = CY_HDMI_720p60;
            hdmiStatus.hdmiVideoPixelClock  = 74250000L;
            hdmiStatus.hdmiPixelRep         = 0u;
            hdmiStatus.hdmiAspectRatio      = CY_HDMI_ASPECT_RATIO_16x9;
            hdmiStatus.hdmiColorimetry      = CY_HDMI_COLORIMETRY_ITU709;
            break;

        case CY_HDMI_720p60_FP3D:
            hdmiStatus.hdmiVIC              = CY_HDMI_720p60;
            hdmiStatus.hdmiVideoPixelClock  = 148500000L;
            hdmiStatus.hdmiPixelRep         = 0u;
            hdmiStatus.hdmiAspectRatio      = CY_HDMI_ASPECT_RATIO_16x9;
            hdmiStatus.hdmiColorimetry      = CY_HDMI_COLORIMETRY_ITU709;
            break;

        case CY_HDMI_1080i60:
            hdmiStatus.hdmiVIC              = CY_HDMI_1080i60;
            hdmiStatus.hdmiVideoPixelClock  = 74250000L;
            hdmiStatus.hdmiPixelRep         = 0u;
            hdmiStatus.hdmiAspectRatio      = CY_HDMI_ASPECT_RATIO_16x9;
            hdmiStatus.hdmiColorimetry      = CY_HDMI_COLORIMETRY_ITU709;
            break;

        case CY_HDMI_480i60:
            hdmiStatus.hdmiVIC              = CY_HDMI_480i60;
            hdmiStatus.hdmiVideoPixelClock  = 13500000L;
            hdmiStatus.hdmiPixelRep         = 1u;
            hdmiStatus.hdmiAspectRatio      = CY_HDMI_ASPECT_RATIO_4x3;
            hdmiStatus.hdmiColorimetry      = CY_HDMI_COLORIMETRY_ITU601;
            break;
            
        case CY_HDMI_480i60_16x9:
            hdmiStatus.hdmiVIC              = CY_HDMI_480i60_16x9;
            hdmiStatus.hdmiVideoPixelClock  = 33400000L;
            hdmiStatus.hdmiPixelRep         = 0u;
            hdmiStatus.hdmiAspectRatio      = CY_HDMI_ASPECT_RATIO_16x9;
            hdmiStatus.hdmiColorimetry      = CY_HDMI_COLORIMETRY_ITU601;
            break;
/*
        case CY_HDMI_480i60_16x9:
            hdmiStatus.hdmiVIC              = CY_HDMI_480i60_16x9;
            hdmiStatus.hdmiVideoPixelClock  = 13500000L;
            hdmiStatus.hdmiPixelRep         = 1u;
            hdmiStatus.hdmiAspectRatio      = CY_HDMI_ASPECT_RATIO_16x9;
            hdmiStatus.hdmiColorimetry      = CY_HDMI_COLORIMETRY_ITU601;
            break;
*/
        case CY_HDMI_1080p60:
            hdmiStatus.hdmiVIC              = CY_HDMI_1080p60;
            hdmiStatus.hdmiVideoPixelClock  = 148500000L;
            hdmiStatus.hdmiPixelRep         = 0u;
            hdmiStatus.hdmiAspectRatio      = CY_HDMI_ASPECT_RATIO_16x9;
            hdmiStatus.hdmiColorimetry      = CY_HDMI_COLORIMETRY_ITU709;
            break;

        case CY_HDMI_576p50:
            hdmiStatus.hdmiVIC              = CY_HDMI_576p50;
            hdmiStatus.hdmiVideoPixelClock  = 27000000L;
            hdmiStatus.hdmiPixelRep         = 0u;
            hdmiStatus.hdmiAspectRatio      = CY_HDMI_ASPECT_RATIO_4x3;
            hdmiStatus.hdmiColorimetry      = CY_HDMI_COLORIMETRY_ITU601;
            break;

        case CY_HDMI_576p50_16x9:
            hdmiStatus.hdmiVIC              = CY_HDMI_576p50_16x9;
            hdmiStatus.hdmiVideoPixelClock  = 27000000L;
            hdmiStatus.hdmiPixelRep         = 0u;
            hdmiStatus.hdmiAspectRatio      = CY_HDMI_ASPECT_RATIO_16x9;
            hdmiStatus.hdmiColorimetry      = CY_HDMI_COLORIMETRY_ITU601;
            break;

        case CY_HDMI_720p50:
            hdmiStatus.hdmiVIC              = CY_HDMI_720p50;
            hdmiStatus.hdmiVideoPixelClock  = 74250000L;
            hdmiStatus.hdmiPixelRep         = 0u;
            hdmiStatus.hdmiAspectRatio      = CY_HDMI_ASPECT_RATIO_16x9;
            hdmiStatus.hdmiColorimetry      = CY_HDMI_COLORIMETRY_ITU709;
            break;

        case CY_HDMI_720p50_FP3D:
            hdmiStatus.hdmiVIC              = CY_HDMI_720p50;
            hdmiStatus.hdmiVideoPixelClock  = 148500000L;
            hdmiStatus.hdmiPixelRep         = 0u;
            hdmiStatus.hdmiAspectRatio      = CY_HDMI_ASPECT_RATIO_16x9;
            hdmiStatus.hdmiColorimetry      = CY_HDMI_COLORIMETRY_ITU709;
            break;

        case CY_HDMI_1080i50:
            hdmiStatus.hdmiVIC              = CY_HDMI_1080i50;
            hdmiStatus.hdmiVideoPixelClock  = 74250000L;
            hdmiStatus.hdmiPixelRep         = 0u;
            hdmiStatus.hdmiAspectRatio      = CY_HDMI_ASPECT_RATIO_16x9;
            hdmiStatus.hdmiColorimetry      = CY_HDMI_COLORIMETRY_ITU709;
            break;

        case CY_HDMI_576i50:
            hdmiStatus.hdmiVIC              = CY_HDMI_576i50;
            hdmiStatus.hdmiVideoPixelClock  = 13500000L;
            hdmiStatus.hdmiPixelRep         = 0u;
            hdmiStatus.hdmiAspectRatio      = CY_HDMI_ASPECT_RATIO_4x3;
            hdmiStatus.hdmiColorimetry      = CY_HDMI_COLORIMETRY_ITU601;
            break;

        case CY_HDMI_576i50_16x9:
            hdmiStatus.hdmiVIC              = CY_HDMI_576i50_16x9;
            hdmiStatus.hdmiVideoPixelClock  = 13500000L;
            hdmiStatus.hdmiPixelRep         = 0u;
            hdmiStatus.hdmiAspectRatio      = CY_HDMI_ASPECT_RATIO_16x9;
            hdmiStatus.hdmiColorimetry      = CY_HDMI_COLORIMETRY_ITU709;
            break;

        case CY_HDMI_1080p50:
            hdmiStatus.hdmiVIC              = CY_HDMI_1080p50;
            hdmiStatus.hdmiVideoPixelClock  = 148500000L;
            hdmiStatus.hdmiPixelRep         = 0u;
            hdmiStatus.hdmiAspectRatio      = CY_HDMI_ASPECT_RATIO_16x9;
            hdmiStatus.hdmiColorimetry      = CY_HDMI_COLORIMETRY_ITU709;
            break;

        case CY_HDMI_1080p24:
            hdmiStatus.hdmiVIC              = CY_HDMI_1080p24;
            hdmiStatus.hdmiVideoPixelClock  = 74250000L;
            hdmiStatus.hdmiPixelRep         = 0u;
            hdmiStatus.hdmiAspectRatio      = CY_HDMI_ASPECT_RATIO_16x9;
            hdmiStatus.hdmiColorimetry      = CY_HDMI_COLORIMETRY_ITU709;
            break;

        case CY_HDMI_1080p24_FP3D:
            hdmiStatus.hdmiVIC              = CY_HDMI_1080p24;
            hdmiStatus.hdmiVideoPixelClock  = 2*74250000L;
            hdmiStatus.hdmiPixelRep         = 0u;
            hdmiStatus.hdmiAspectRatio      = CY_HDMI_ASPECT_RATIO_16x9;
            hdmiStatus.hdmiColorimetry      = CY_HDMI_COLORIMETRY_ITU709;
            break;

        case CY_HDMI_1080p25:
            hdmiStatus.hdmiVIC              = CY_HDMI_1080p25; // Need to check 33u;
            hdmiStatus.hdmiVideoPixelClock  = 74250000L;
            hdmiStatus.hdmiPixelRep         = 0u;
            hdmiStatus.hdmiAspectRatio      = CY_HDMI_ASPECT_RATIO_16x9;
            hdmiStatus.hdmiColorimetry      = CY_HDMI_COLORIMETRY_ITU709;
            break;

        case CY_HDMI_1080p30:
            hdmiStatus.hdmiVIC              = CY_HDMI_1080p30; // Need to check 34u;
            hdmiStatus.hdmiVideoPixelClock  = 74250000L;
            hdmiStatus.hdmiPixelRep         = 0u;
            hdmiStatus.hdmiAspectRatio      = CY_HDMI_ASPECT_RATIO_16x9;
            hdmiStatus.hdmiColorimetry      = CY_HDMI_COLORIMETRY_ITU709;
            break;

        default:
            hdmiStatus.hdmiVIC              = CY_HDMI_800x480p60;
            hdmiStatus.hdmiVideoPixelClock  = Cy_IT6263_GetLvdsInputPclk();
            hdmiStatus.hdmiPixelRep         = 0u;
            hdmiStatus.hdmiAspectRatio      = CY_HDMI_ASPECT_RATIO_4x3;
            hdmiStatus.hdmiColorimetry      = CY_HDMI_COLORIMETRY_ITU601;
            break;
    }
    
    /* Update the configuration parameter */
    //hdmiConfig.colorFormat = CY_HDMI_COLOR_RGB444;
    if(hdmiStatus.hdmiColorimetry == CY_HDMI_COLORIMETRY_ITU709 )
    {
        hdmiStatus.hdmiInputColorFormat |= F_MODE_ITU709 ;
    }
    else
    {
        hdmiStatus.hdmiInputColorFormat &= ~F_MODE_ITU709 ;
    }

    if(videoMode != CY_HDMI_640x480p60)
    {
        hdmiStatus.hdmiInputColorFormat |= F_MODE_16_235 ;
    }
    else
    {
        hdmiStatus.hdmiInputColorFormat &= ~F_MODE_16_235 ;
    }
    hdmiStatus.hdmiIsChangeMode = true;

    return status;
}

/*******************************************************************************
* Function Name: Cy_HDMI_Transceiver_DeviceLoop
****************************************************************************//**
*
* \brief
* Contineous loop to monitor HDMI device events for hot plugin.
*
* \param none
*
* \return
* cy_en_hdmi_trx_status_t : function result type
*
*******************************************************************************/
cy_en_hdmi_trx_status_t Cy_HDMI_Transceiver_DeviceLoop(void)
{
    cy_en_hdmi_trx_status_t status = CY_HDMI_TRX_SUCCESS;
    static uint8_t loopCnt=0;

    /* Check the HDMI interface status */
    Cy_IT6263_HdmiCheckStatus(&hdmiStatus.hdmiHpdStatus,&hdmiStatus.hdmiHpdChangeStatus);
    
    /* If HPD status is changed */
    if(hdmiStatus.hdmiHpdChangeStatus)
    {
        loopCnt = 0;

        /* Check HPD status */
        if(hdmiStatus.hdmiHpdStatus)
        {
            Cy_IT6263_HDMI_ParseEDID();
            //hdmiConfig.colorFormat = CY_HDMI_COLOR_RGB444;

            /* Check the HDMi capability */
            if(hdmiRxCapability.ValidHDMI)
            {
                hdmiInstanceData.bHDMIMode = true;

                if(hdmiRxCapability.VideoMode & (1<<6))
                {
                    /* Enable the audio */
                }
            }
            else
            {
                hdmiInstanceData.bHDMIMode = false;
            }
#ifdef DEBUG_IT6263
            printf("HPD change HDMITX_SetOutput();\n\r");
#endif
            hdmiStatus.hdmiIsChangeMode = true;
        }
        else
        {
#ifdef DEBUG_IT6263
            printf("HPD OFF DisableVideoOutput();\n\r");
#endif          
            Cy_IT6263_HdmiDisableVideoOutput();
        }
    }
    /* not stable but need to process mode change */
    else
    {
        loopCnt++;
        //CheckAudioVideoInput();
        if(0 == (loopCnt & 0x0F) || hdmiStatus.hdmiIsChangeMode)
        {
            if(CY_HDMI_TRX_SUCCESS != Cy_IT6263_HDMI_DetectVideoMode())
            {
                hdmiStatus.hdmiIsChangeMode = true;
                return status;
            }
        }
        if(hdmiStatus.hdmiIsChangeMode && hdmiStatus.hdmiHpdStatus)
        {
            Cy_IT6263_HDMI_SetVideoOutput();
        }
    }

    return status;
}

/*******************************************************************************
* Function Name: Cy_HDMI_Transceiver_Init
****************************************************************************//**
*
* \brief
* Initializes the LVDS to HDMI transceiver and control interface.
*
* \param
* videoParam : video timings, resolution and frame rate, refer cy_stc_hdmi_trx_config_t
*
* \return
* cy_en_hdmi_trx_status_t : function result type
*
* \note 
* SCB7 is used as a sensor control interface, do not change it. Should be
* called before calling any other image sensor api.
*
*******************************************************************************/
cy_en_hdmi_trx_status_t Cy_HDMI_Transceiver_Init(cy_stc_hdmi_trx_config_t videoFormat)
{
    cy_en_hdmi_trx_status_t status = CY_HDMI_TRX_SUCCESS;
    
    /* Initialize the related peripherals */
    Cy_IT6263_InitPeripherals();
    
    /* Reset the LVDS-HDMI transceiver */
    Cy_IT6263_Reset();
    
    /* Verify sensor chip id */
    status = Cy_IT6263_VerifyChipId();
    if (status != CY_HDMI_TRX_SUCCESS)
    {
        return status;
    }
    
    /* Initialize the chip */
    Cy_IT6263_InitBase(videoFormat);
    
#ifdef DEBUG_IT6263
    /* Enable the debug IO */
    Cy_IT6263_EnableDebugIO();
#endif
    
    /* Set default resolution */
    status = CY_HDMI_Transceiver_SetDisplayOption(videoFormat.videoType, videoFormat.colorFormat);
    if (status != CY_HDMI_TRX_SUCCESS)
    {
        return status;
    }

    /* Wakeup the transceiver */
    status = Cy_IT6263_HDMI_DetectVideoMode();
    if (status != CY_HDMI_TRX_SUCCESS)
    {
        return status;
    }

    return status;
}

/*******************************************************************************
* Function Name: Cy_HDMI_Transceiver_DeInit
****************************************************************************//**
*
* \brief
* De-Initializes the LVDS to HDMI transceiver Interface.
*
* \param none
*
* \return
* cy_en_hdmi_trx_status_t : function result type
*
*******************************************************************************/
cy_en_hdmi_trx_status_t Cy_HDMI_Transceiver_DeInit(void)
{
    cy_en_hdmi_trx_status_t status = CY_HDMI_TRX_SUCCESS;
    
    /* Sensor sleep will turn off camera */
    status = Cy_HDMI_Transceiver_Sleep();
    if (status != CY_HDMI_TRX_SUCCESS)
    {
        return status;
    }

    return status;
}

#endif  /* CY_327BGA_EVKLITE_rev_a */

/******************************************************************************/
/* [] END OF FILE */
/******************************************************************************/
