/***************************************************************************//**
* \file cy_base_hdmi.h
* \version 1.0
*
* \brief
* Provides an API declaration of the base HDMI functions.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

/**
* Refer to the technical reference manual (TRM) and the device datasheet.
*
* \defgroup group_mw_base_hdmi_macros Macro
* \defgroup group_mw_base_hdmi_functions Functions
* \defgroup group_mw_base_hdmi_datastructure Data structures
* \defgroup group_mw_base_hdmi_enums Enumerated types
*/

#ifndef CY_BASE_HDMI_H_
#define CY_BASE_HDMI_H_

#include <stddef.h>
#include <stdbool.h>

/* Only applicable for the lite kit */
#ifdef CY_327BGA_EVKLITE_rev_a

#include "cy_device_headers.h"
#include "cy_i2c_hdmi.h"


#if defined(__cplusplus)
extern "C" {
#endif

/**
* \addtogroup group_mw_base_hdmi_macros
* \{
*/

/* Select the default HDMI capability */
//#define SUPPORT_EDID
//#define SUPPORT_HDCP
#define SUPPORT_INPUTRGB
#define DEBUG_IT6263

/* Select the VESA compatibality otherwise JEIDA */
#define SUPPORT_MAP3

/* Select the LVDS input and HDMI out, Dual In Single Out otherwise Single In Single Out */
//#define SUPPORT_DISO

/* Select the default lvds bits */
#define LVDS_COLOR_6_BIT                0
#define LVDS_COLOR_8_BIT                1
#define LVDS_COLOR_10_BIT               2
#define CY_LVDS_COLOR_DEPTH_BIT         LVDS_COLOR_8_BIT

/* Select the lvds format */
#define LVDS_FORMAT_JEIDA               0
#define LVDS_FORMAT_VESA                1
#define CY_LVDS_FORMAT_TYPE             LVDS_FORMAT_VESA

/* Select the lvds link mode */
#define LVDS_LINK_SISO_DIDO             0
#define LVDS_LINK_DISO                  1
#define CY_LVDS_LINK_MODE               LVDS_LINK_SISO_DIDO

/* Select the default input mode */
//#define SUPPORT_INPUTYUV444
//#define SUPPORT_INPUTYUV422

/* Macros for HDMI instance */
#define HDMITX_INSTANCE_MAX             1
#define SIZEOF_CSCMTX                   18
#define SIZEOF_CSCGAIN                  6
#define SIZEOF_CSCOFFSET                3

/* Macro for output Mode Type */
#define F_MODE_REPT_NO                  0
#define F_MODE_REPT_TWICE               1
#define F_MODE_REPT_QUATRO              3

/* Macro for ROM offset */
#define ROMOFF_INT_TYPE                 0
#define ROMOFF_INPUT_VIDEO_TYPE         1
#define ROMOFF_OUTPUT_AUDIO_MODE        8
#define ROMOFF_AUDIO_CH_SWAP            9

/* Macro for timer loop */
#define TIMER_LOOP_LEN                  10
#define MS(x)                           (((x)+(TIMER_LOOP_LEN-1))/TIMER_LOOP_LEN);

/* Macro for video data type */
#define F_MODE_RGB24                    0
#define F_MODE_RGB444                   0
#define F_MODE_YUV422                   1
#define F_MODE_YUV444                   2
#define F_MODE_CLRMOD_MASK              3

#define F_MODE_INTERLACE                1
#define F_MODE_ITU709                   (1<<4)
#define F_MODE_ITU601                   0
#define F_MODE_0_255                    0
#define F_MODE_16_235                   (1<<5)
#define F_MODE_EN_UDFILT                (1<<6) // output mode only,and loaded from EEPROM
#define F_MODE_EN_DITHER                (1<<7) // output mode only,and loaded from EEPROM

/* Macro for video timings */
#define T_MODE_CCIR656                  (1<<0)
#define T_MODE_SYNCEMB                  (1<<1)
#define T_MODE_INDDR                    (1<<2)
#define T_MODE_PCLKDIV2                 (1<<3)
#define T_MODE_DEGEN                    (1<<4)
#define T_MODE_SYNCGEN                  (1<<5)
#define NUM_OF_DISPLAY_TIMINGS          15

/* Packet and Info Frame definition */
#define VS3D_MODE_FRAME_PACKING         0x00
#define VS3D_MODE_TOP_AND_BOTTOM        0x06
#define VS3D_MODE_SIDE_BY_SIDE          0x08

#define VENDORSPEC_INFOFRAME_TYPE       0x01
#define AVI_INFOFRAME_TYPE              0x02
#define SPD_INFOFRAME_TYPE              0x03
#define AUDIO_INFOFRAME_TYPE            0x04
#define MPEG_INFOFRAME_TYPE             0x05

#define VENDORSPEC_INFOFRAME_VER        0x01
#define AVI_INFOFRAME_VER               0x02
#define SPD_INFOFRAME_VER               0x01
#define AUDIO_INFOFRAME_VER             0x01
#define MPEG_INFOFRAME_VER              0x01

#define VENDORSPEC_INFOFRAME_LEN        6
#define AVI_INFOFRAME_LEN               13
#define SPD_INFOFRAME_LEN               25
#define AUDIO_INFOFRAME_LEN             10
#define MPEG_INFOFRAME_LEN              10

#define ACP_PKT_LEN                     9
#define ISRC1_PKT_LEN                   16
#define ISRC2_PKT_LEN                   16

/* Macro definition for CEA support */
#define CEA_SUPPORT_UNDERSCAN           (1<<7)
#define CEA_SUPPORT_AUDIO               (1<<6)
#define CEA_SUPPORT_YUV444              (1<<5)
#define CEA_SUPPORT_YUV422              (1<<4)
#define CEA_NATIVE_MASK                 0x0F

/* HDMI IEEE standard */
#define HDMI_IEEEOUI                    0x0c03
  
/* HDMI resolution correction */
#define HDMI_DELTA_TIMINGS(x)           (x+((x*105)/100))
#define HDMI_VALIDATE_TIMINGS(x)        ((x < HDMI_DELTA_TIMINGS(x)) ? 1 : 0)
  
/* Macro for register operation */
#define HDMI_Switch_TX_Bank(x)                  Cy_IT6263_I2C_Write(CY_IT6263_I2C_ADRESS, 0x0f, ((x)& 1))

#define HDMI_Write_Byte(reg,value)              Cy_IT6263_I2C_Write(CY_IT6263_I2C_ADRESS, reg, value)
#define HDMI_Read_Byte(reg)                     Cy_IT6263_I2C_Read(CY_IT6263_I2C_ADRESS, reg)
#define HDMI_OrREG_TX_Byte(reg,ormask)          Cy_IT6263_I2C_ReadWrite(CY_IT6263_I2C_ADRESS, reg, ormask, CY_I2C_OP_OR)
#define HDMI_AndREG_TX_Byte(reg,andmask)        Cy_IT6263_I2C_ReadWrite(CY_IT6263_I2C_ADRESS, reg, andmask, CY_I2C_OP_AND)

#define LVDS_Write_Byte(reg,value)              Cy_IT6263_I2C_Write(CY_IT6263_LVDS_ADRESS, reg, value)
#define LVDS_Read_Byte(reg)                     Cy_IT6263_I2C_Read(CY_IT6263_LVDS_ADRESS, reg)
#define LVDS_OrREG_TX_Byte(reg,ormask)          Cy_IT6263_I2C_ReadWrite(CY_IT6263_LVDS_ADRESS, reg, ormask, CY_I2C_OP_OR)
#define LVDS_AndREG_TX_Byte(reg,andmask)        Cy_IT6263_I2C_ReadWrite(CY_IT6263_LVDS_ADRESS, reg, andmask, CY_I2C_OP_AND)

/** \} group_mw_base_hdmi_macros */

/**
* \addtogroup group_mw_base_hdmi_enums
* \{
*/

/* Values for the LVDS bit configuration */
typedef enum
{
    CY_SUPPORT_LVDS_6_BIT       = 0x00u,      /**< Set the 6-bit color depth */
    CY_SUPPORT_LVDS_8_BIT       = 0x00u,      /**< Set the 8-bit color depth */
    CY_SUPPORT_LVDS_10_BIT      = 0x00u,      /**< Set the 10-bit color depth */
    CY_SUPPORT_LVDS_12_BIT      = 0x00u,      /**< Set the 12-bit color depth */
} cy_en_lvds_color_depth_t;
  
/* Values for the video pclk levels */
typedef enum
{
    CY_HDMI_PCLK_LOW    = 0x00u,      /**< Returned successful */
    CY_HDMI_PCLK_MEDIUM = 0x01u,      /**< General error */
    CY_HDMI_PCLK_HIGH   = 0x02u,      /**< Bad parameter was passed */
} cy_en_hdmi_video_pclk_t;

/** \} group_mw_base_hdmi_enums */

/**
* \addtogroup group_mw_base_hdmi_datastructure
* \{
*/

/* Video format code structure */
typedef union
{
    struct
    {
        uint8_t colorfmt:2;
        uint8_t interlace:1;
        uint8_t Colorimetry:1;
        uint8_t Quantization:1;
        uint8_t UpDownFilter:1;
        uint8_t Dither:1;
    } VFCCode ;
    uint8_t VFCByte ;
} cy_un_hdmi_video_format_code_t;

/* Packet and info frame datastructure. */
typedef union
{
    struct {
        uint8_t Type;
        uint8_t Ver;
        uint8_t Len;
        uint8_t CheckSum;
        uint8_t IEEE_0;
        uint8_t IEEE_1;
        uint8_t IEEE_2;
        uint8_t Rsvd:5;
        uint8_t HDMI_Video_Format:3;
        uint8_t Reserved_PB5:4;
        uint8_t _3D_Structure:4;
        uint8_t Reserved_PB6:4;
        uint8_t _3D_Ext_Data:4;
    } info;
    struct {
        uint8_t VS_HB[3];
        uint8_t VS_DB[28];
    } pktbyte;
} cy_un_hdmi_vendor_infotrame_t ;

/* Packet and AVI info frame datastructure. */
typedef union
{
    struct {
        uint8_t Type;
        uint8_t Ver;
        uint8_t Len;
        uint8_t checksum;
        uint8_t Scan:2;
        uint8_t BarInfo:2;
        uint8_t ActiveFmtInfoPresent:1;
        uint8_t ColorMode:2;
        uint8_t FU1:1;
        uint8_t ActiveFormatAspectRatio:4;
        uint8_t PictureAspectRatio:2;
        uint8_t Colorimetry:2;
        uint8_t Scaling:2;
        uint8_t FU2:6;
        uint8_t VIC:7;
        uint8_t FU3:1;
        uint8_t PixelRepetition:4;
        uint8_t FU4:4;
        uint16_t Ln_End_Top;
        uint16_t Ln_Start_Bottom;
        uint16_t Pix_End_Left;
        uint16_t Pix_Start_Right;
    } info;
    struct {
        uint8_t AVI_HB[3];
        uint8_t checksum;
        uint8_t AVI_DB[AVI_INFOFRAME_LEN];
    } pktbyte;
} cy_un_hdmi_avi_infotrame_t ;

/* Packet and MPEG info frame datastructure. */
typedef union 
{
    struct {
        uint8_t Type;
        uint8_t Ver;
        uint8_t Len;
        uint8_t checksum;
        uint32_t MpegBitRate;
        uint8_t MpegFrame:2;
        uint8_t Rvsd1:2;
        uint8_t FieldRepeat:1;
        uint8_t Rvsd2:3;
    } info;
    struct {
        uint8_t MPG_HB[3];
        uint8_t checksum;
        uint8_t MPG_DB[MPEG_INFOFRAME_LEN];
    } pktbyte;
} cy_un_hdmi_mpeg_infotrame_t;

/* Source product description */
typedef union 
{
    struct {
        uint8_t Type;
        uint8_t Ver;
        uint8_t Len;
        uint8_t checksum;
        uint8_t VN[8];
        //uint8_t PD[16];
        uint8_t SourceDeviceInfomation;
    } info;
    struct {
        uint8_t SPD_HB[3];
        uint8_t checksum;
        uint8_t SPD_DB[SPD_INFOFRAME_LEN];
    } pktbyte;
} cy_un_hdmi_spd_infotrame_t;

/* Video interface clock description */
typedef struct 
{
    uint32_t VideoPixelClock;
    uint8_t VIC;
    uint8_t pixelrep;
    uint8_t outputVideoMode;
} cy_stc_hdmi_video_timings_t;

/* Video interface DVI description */
typedef union 
{
    struct {
        uint8_t DVI_Dual:1;
        uint8_t Rsvd:2;
        uint8_t DC_Y444:1;
        uint8_t DC_30Bit:1;
        uint8_t DC_36Bit:1;
        uint8_t DC_48Bit:1;
        uint8_t SUPPORT_AI:1;
    } info;
    uint8_t uc;
} cy_un_hdmi_dc_support_t;

/* Video interface latency description */
typedef union
{
    struct {
        uint8_t Rsvd:6;
        uint8_t I_Latency_Present:1;
        uint8_t Latency_Present:1;
    } info ;
    uint8_t uc ;
} cy_un_hdmi_latency_support_t;

/* Structure for the display timings */
typedef struct 
{
    uint8_t fmt;
    uint8_t interlaced;
    uint16_t  VEC[11];
} cy_stc_hdmi_display_timings_t;

/* Video interface rx capability description */
typedef struct
{
    uint8_t HDMI_VSDB[32];
    uint8_t VideoMode;
    uint8_t VDOModeCount;
    uint8_t idxNativeVDOMode;
    uint8_t VDOMode[32];
    uint32_t IEEEOUI;
    uint8_t MaxTMDSClock;
    uint8_t V_Latency;
    uint8_t A_Latency;
    uint8_t V_I_Latency;
    uint8_t A_I_Latency;
    uint8_t ValidCEA:1;
    uint8_t ValidHDMI:1;
    cy_un_hdmi_dc_support_t dc;
    cy_un_hdmi_latency_support_t lsupport;
} cy_un_hdmi_rx_cap_t;

/* Structure to configure the HDMI instance */
typedef struct
{
    uint8_t I2C_DEV;
    uint8_t I2C_ADDR;
    uint8_t bIntType;
    uint8_t bInputVideoSignalType;
    uint32_t TMDSClock;
    uint8_t bAuthenticated:1;
    uint8_t bHDMIMode:1;
    uint8_t bIntPOL:1;
    uint8_t bHPD:1;
    uint8_t TxEMEMStatus:1;
    uint8_t bSPDIF_OUT;
    uint8_t bVideoOut;
} cy_stc_hdmi_instance_config_t;

/** \} group_mw_base_hdmi_datastructure */

/**
* \addtogroup group_mw_base_hdmi_functions
* \{
*/

/* LVDS to HDMI transceiver base function definition */
void Cy_IT6263_Init(void);
void Cy_IT6263_DeInit(void);
void Cy_IT6263_InitInstance(cy_stc_hdmi_instance_config_t *pInstance);

bool Cy_IT6263_IsLvdsStable(void);
uint32_t Cy_IT6263_GetLvdsInputPclk(void);

bool Cy_IT6263_HDMI_GetEDIDData(uint8_t blockID, volatile uint8_t* pEDIDData);
bool Cy_IT6263_HdmiEnableVSInfoFrame(uint8_t bEnable, uint8_t *pVSInfoFrame);
bool Cy_IT6263_HdmiEnableAVIInfoFrame(uint8_t bEnable, volatile uint8_t *pAVIInfoFrame);

uint8_t Cy_IT6263_DetectVIC(void);
void Cy_IT6263_SetAVMute(uint8_t bEnable);
bool Cy_IT6263_HdmiReGenTiming(uint8_t fmtAssign);
void Cy_IT6263_HdmiDisableVideoOutput(void);
void Cy_IT6263_HdmiDisableAudioOutput(void);
void Cy_IT6263_HdmiSetVideoInput(uint8_t inSignalType);
void Cy_IT6263_HdmiEnableVideoOutput(cy_en_hdmi_video_pclk_t pclkLevel, uint8_t inColorMode, uint8_t outColorMode, uint8_t bHDMI);
void Cy_IT6263_HdmiSetColorOutputDepth(uint8_t colorDepth, uint8_t bPhase);
uint8_t Cy_IT6263_HdmiCheckStatus(uint8_t *pHPD, uint8_t *pHPDChange);

#ifdef DEBUG_IT6263
void Cy_IT6263_EnableDebugIO(void);
void Cy_IT6263_DumpLVDSReg(void);
void Cy_IT6263_DumpCatHDMITXReg(void);
#endif // DEBUG_IT6263

/** \} group_mw_base_hdmi_functions */


#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* CY_327BGA_EVKLITE_rev_a */

#endif  /* CY_BASE_HDMI_H_ */

/* [] END OF FILE */
