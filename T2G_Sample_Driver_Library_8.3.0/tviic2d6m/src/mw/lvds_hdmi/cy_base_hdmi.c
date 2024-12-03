/***************************************************************************//**
* \file cy_base_hdmi.c
* \version 1.0
*
* \brief
* Provides an API definition of the base HDMI functions.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include <stdio.h>
#include "cy_base_hdmi.h"
#include "cy_project.h"
#include "cy_device_headers.h"
#include "cy_it6263_config.h"

/* Only applicable for the lite kit */
#ifdef CY_327BGA_EVKLITE_rev_a

#include "cy_i2c_hdmi.h"
#include "cy_lvds_hdmi.h"


/* Local variable declaration */
static cy_stc_hdmi_instance_config_t hdmiInstance[HDMITX_INSTANCE_MAX];

/* Extern variable declaration */
extern cy_stc_hdmi_trx_status_t hdmiStatus;
extern cy_stc_hdmi_trx_config_t hdmiConfig;

/* HDMI display timings */
cy_stc_hdmi_display_timings_t displayTimings[NUM_OF_DISPLAY_TIMINGS] = 
{
//  { FMT                  ,  Int,        HT,  H_DEW,    H_FBH, H_SyncW,    H_BBH,    VTotal,      V_DEW,  V_FBH,  V_SyncW,  V_BBH,   Sync_pol,   }},
  //{ CY_HDMI_Unknown      ,    0,    { 800 ,    640,       16,      62,       60,       500,        480,      9,        6,     30,    0 } },
    { CY_HDMI_800x480p60   ,    0,    {1088 ,    800,       48,      40,      200,       560,        480,      3,       10,     67,    0 } },
    { CY_HDMI_640x480p60   ,    0,    { 800 ,    640,       16,      62,       60,       500,        480,      9,        6,     30,    0 } },   // HP_m27 
    { CY_HDMI_480p60       ,    0,    { 858 ,    720,       16,      62,       60,       525,        480,      9,        6,     30,    0 } },
    { CY_HDMI_480p60_16x9  ,    0,    { 858 ,    720,       16,      62,       60,       525,        480,      9,        6,     30,    0 } },
    { CY_HDMI_720p60       ,    0,    {1440 ,   1280,      110,      40,      220,       750,        720,      5,        5,     20,    3 } },   // HP_m27
    { CY_HDMI_1080i60      ,    1,    {2200 ,   1920,       88,      44,      148,      1125,        540,      2,        5,     15,    3 } },
  //{ CY_HDMI_480i60_16x9  ,    1,    { 858 ,    720,       19,      62,       57,       525,        240,      4,        3,     15,    0 } },
  //{ CY_HDMI_480i60_16x9  ,    1,    { 992 ,    800,       24,      72,       96,       500,        480,      3,        7,     10,    0 } },
    { CY_HDMI_480i60_16x9  ,    1,    {1088 ,    800,       48,      40,      200,       560,        480,      3,       10,     67,    0 } },
    { CY_HDMI_1080p60      ,    0,    {2200 ,   1920,       88,      44,      148,      1125,       1080,      4,        5,     36,    3 } },
    { CY_HDMI_576p50       ,    0,    { 864 ,    720,       12,      64,       68,       625,        576,      5,        5,     39,    0 } },
    { CY_HDMI_720p50       ,    0,    {1980 ,   1280,      440,      40,      220,       750,        720,      5,        5,     20,    3 } },
    { CY_HDMI_1080i50      ,    1,    {2640 ,   1920,      528,      44,      148,      1125,        540,      2,        5,     15,    3 } },
    { CY_HDMI_1080p50      ,    0,    {2640 ,   1920,      528,      44,      148,      1125,       1080,      4,        5,     36,    3 } },
    { CY_HDMI_1080p24      ,    0,    {2750 ,   1920,      638,      44,      148,      1125,       1080,      4,        5,     36,    3 } },
    { CY_HDMI_720p60_FP3D  ,    0,    {1650 ,   1280,      110,      40,      220,     2*750,    750+720,      5,        5,     20,    3 } },
    { CY_HDMI_720p50_FP3D  ,    0,    {1980 ,   1280,      440,      40,      220,     2*750,    750+720,      5,        5,     20,    3 } },
    /*
    { CY_HDMI_480p60       ,    0,    { 801 ,    640,       16,      62,       60,       501,        480,      9,        6,     30,    0 } },   // HP_m27 
    { CY_HDMI_480p60       ,    0,    { 858 ,    720,       16,      62,       60,       525,        480,      9,        6,     30,    0 } },
  //{ CY_HDMI_480p60_16x9  ,    0,    { 858 ,    720,       16,      62,       60,       525,        480,      9,        6,     30,    0 } },   // Default
    { CY_HDMI_480p60_16x9  ,    0,    { 859 ,    720,       16,      62,       60,       526,        480,      9,        6,     30,    0 } },   // WS7
  //{ CY_HDMI_600p60       ,    0,    {1344 ,   1024,       44,      88,      188,       625,        600,      3,        6,     16,    3 } }, 
  //{ CY_HDMI_720p60       ,    0,    {1650 ,   1280,      110,      40,      220,       750,        720,      5,        5,     20,    3 } },   // WS7
  //{ CY_HDMI_720p60       ,    0,    {1440 ,   1280,      110,      40,      220,       750,        720,      5,        5,     20,    3 } },   // Default
    { CY_HDMI_720p60       ,    0,    {1441 ,   1280,      110,      40,      220,       751,        720,      5,        5,     20,    3 } },   // HP_m27 
    { CY_HDMI_1080i60      ,    1,    {2200 ,   1920,       88,      44,      148,      1125,        540,      2,        5,     15,    3 } },
    { CY_HDMI_480i60_16x9  ,    1,    { 858 ,    720,       19,      62,       57,       525,        240,      4,        3,     15,    0 } },
    { CY_HDMI_1080p60      ,    0,    {2200 ,   1920,       88,      44,      148,      1125,       1080,      4,        5,     36,    3 } },
    //{ CY_HDMI_576p50       ,    0,    { 864 ,    720,       12,      64,       68,       525,        480,      5,        5,     36,    0 } },
    { CY_HDMI_576p50       ,    0,    { 864 ,    720,       12,      64,       68,       625,        576,      5,        5,     49,    0 } },   // WS7
    { CY_HDMI_720p50       ,    0,    {1980 ,   1280,      440,      40,      220,       750,        720,      5,        5,     20,    3 } },
    { CY_HDMI_1080i50      ,    1,    {2640 ,   1920,      528,      44,      148,      1125,        540,      2,        5,     15,    3 } },
    { CY_HDMI_1080p50      ,    0,    {2640 ,   1920,      528,      44,      148,      1125,       1080,      4,        5,     36,    3 } },
    { CY_HDMI_1080p24      ,    0,    {2750 ,   1920,      638,      44,      148,      1125,       1080,      4,        5,     36,    3 } },
    { CY_HDMI_720p60_FP3D  ,    0,    {1650 ,   1280,      110,      40,      220,     2*750,    750+720,      5,        5,     20,    3 } },
    { CY_HDMI_720p50_FP3D  ,    0,    {1980 ,   1280,      440,      40,      220,     2*750,    750+720,      5,        5,     20,    3 } },
    { CY_HDMI_1080p24_FP3D ,    0,    {2750 ,   1920,      638,      44,      148,    2*1125,  1125+1080,      4,        5,     36,    3 } },
    */
};

/* Local function declaration */

static void Cy_IT6263_SetLvds(void);
static void Cy_IT6263_InitLvds(void);
static void Cy_IT6263_ResetLvds(void);
static void Cy_IT6263_SetLvdsAFE(void);
static uint16_t Cy_IT6263_GetLvdsInputClockCount(void);

static void Cy_IT6263_SetNullPkt(bool isEnable);
static void Cy_IT6263_SetAcpPkt(bool isEnable);
static void Cy_IT6263_SetIsrc1Pkt(bool isEnable);
static void Cy_IT6263_SetIsrc2Pkt(bool isEnable);
static void Cy_IT6263_SetAviInfoframePkt(bool isEnable);
static void Cy_IT6263_SetAudioInfoframePkt(bool isEnable);
static void Cy_IT6263_SetSpdInfoframePkt(bool isEnable);
static void Cy_IT6263_SetMpgInfoframePkt(bool isEnable);
static void Cy_IT6263_SetVSInfoFrame(cy_un_hdmi_vendor_infotrame_t *pVSInfoFrame);
static void Cy_IT6263_SetAVIInfoFrame(cy_un_hdmi_avi_infotrame_t *pAVIInfoFrame);
static bool Cy_IT6263_ReadEDID(volatile uint8_t *pData, uint8_t bSegment, uint8_t offset, uint16_t count);
#ifdef SUPPORT_REGEN_TIMING
static void Cy_IT6263_EnableDeOnly(bool isDeOnly);
#endif

static void Cy_IT6263_SoftwareVideoReset(void);
static void Cy_IT6263_SetupAFE(cy_en_hdmi_video_pclk_t pclkLevel);
static void Cy_IT6263_FireAFE(void);

static void Cy_IT6263_AbortDDC(void);
static void Cy_IT6263_ClearDDC(void);

/*******************************************************************************
* Function Name: Cy_IT6263_GetLvdsInputClockCount
****************************************************************************//**
*
* \brief
* Get the LVDS interface clock count of the chip IT6263.
*
* \param
* uint16_t : clock counts
*
* \return none
*
*******************************************************************************/
static uint16_t Cy_IT6263_GetLvdsInputClockCount(void)
{
    uint8_t u1,u2;
    uint16_t temp1;
    u1 = LVDS_Read_Byte(0x58);
    u2 = LVDS_Read_Byte(0x57);
    temp1 = ((uint16_t) u1 << 8);
    temp1 += u2;
    return temp1;
}

/*******************************************************************************
* Function Name: Cy_IT6263_ResetLvds
****************************************************************************//**
*
* \brief
* Reset the LVDS interface of the chip IT6263.
*
* \param none
*
* \return none
*
*******************************************************************************/
static void Cy_IT6263_ResetLvds(void)
{
    /* Reset LVDS AFE and PLL */
    LVDS_AndREG_TX_Byte(0x3c, 0xfe);
    Cy_SysTick_DelayInUs(1000u);
    LVDS_OrREG_TX_Byte(0x3c, 0x01);

    /* Reset LVDS pclk */
    LVDS_OrREG_TX_Byte(0x05, 0x02);
    Cy_SysTick_DelayInUs(1000u);
    LVDS_AndREG_TX_Byte(0x05, 0xfd);

#ifdef IT626X_SSC
    /* Reset SRAM */
    LVDS_OrREG_TX_Byte(0x2c, 0x40);
    Cy_SysTick_DelayInUs(1000u);
    LVDS_AndREG_TX_Byte(0x2c, 0xbf);
#endif
}

/*******************************************************************************
* Function Name: Cy_IT6263_SetLvds
****************************************************************************//**
*
* \brief
* Configure the LVDS interface of the chip IT6263.
*
* \param none
*
* \return none
*
*******************************************************************************/
static void Cy_IT6263_SetLvds(void)
{
#if 0
    uint8_t uc;
    uc = LVDS_Read_Byte(0x2c) & 0x03;

    // HDMI_Switch_TX_Bank(0);
    // HDMI_Write_Byte(0x1d, 0x66);

#if (CY_LVDS_COLOR_DEPTH_BIT == LVDS_COLOR_6_BIT)
    if(0x00 != uc)
    {
        /* [1:0]=("00"-6 bit),("01"-8 bit),("10"-10 bit) */
        LVDS_AndREG_TX_Byte(0x2c, 0xfc);
        LVDS_OrREG_TX_Byte(0x2c, 0x00);
    }
#endif
    
#if (CY_LVDS_COLOR_DEPTH_BIT == LVDS_COLOR_8_BIT)
    if(0x01 != uc)
    {
        /* [1:0]=("00"-6 bit),("01"-8 bit),("10"-10 bit) */
        LVDS_AndREG_TX_Byte(0x2c, 0xfc);
        LVDS_OrREG_TX_Byte(0x2c, 0x01);
    }
#endif

#if (CY_LVDS_COLOR_DEPTH_BIT == LVDS_COLOR_10_BIT)
    if(0x02 != uc)
    {
        /* [1:0]=("00"-6 bit),("01"-8 bit),("10"-10 bit) */
        LVDS_AndREG_TX_Byte(0x2c, 0xfc);
        LVDS_OrREG_TX_Byte(0x2c, 0x02);
    }
#endif

    /* Check the Input and Output configuration */
    uc = LVDS_Read_Byte(0x2c) & (1<<7);

#ifdef SUPPORT_DISO
    /* If the Dual In and Single Out is configured */
    if(uc != (1<<7))
    {
        LVDS_OrREG_TX_Byte(0x2c, (1<<7));
        LVDS_OrREG_TX_Byte(0x52, (1<<1));
    }
#else
    /* If the Single In and Single Out is configured */
    if(uc != (0<<7))
    {
        uc = (uint8_t) ~(1<<7);
        LVDS_AndREG_TX_Byte(0x2c, uc);
        LVDS_AndREG_TX_Byte(0x52, (~(1<<1)));
    }
#endif
#else
    uint8_t uc;
    uc = LVDS_Read_Byte(0x2c) & 0x03;

    if ((0x00 != uc) && (hdmiConfig.colorBits == LVDS_COLOR_6_BIT))
    {
        /* [1:0]=("00"-6 bit),("01"-8 bit),("10"-10 bit) */
        LVDS_AndREG_TX_Byte(0x2c, 0xfc);
        LVDS_OrREG_TX_Byte(0x2c, 0x00);
    }
    if ((0x01 != uc) && (hdmiConfig.colorBits == LVDS_COLOR_8_BIT))
    {
        /* [1:0]=("00"-6 bit),("01"-8 bit),("10"-10 bit) */
        LVDS_AndREG_TX_Byte(0x2c, 0xfc);
        LVDS_OrREG_TX_Byte(0x2c, 0x01);
    }
    if ((0x02 != uc) && (hdmiConfig.colorBits == LVDS_COLOR_10_BIT))
    {
        /* [1:0]=("00"-6 bit),("01"-8 bit),("10"-10 bit) */
        LVDS_AndREG_TX_Byte(0x2c, 0xfc);
        LVDS_OrREG_TX_Byte(0x2c, 0x02);
    }

    /* Check the Input and Output configuration */
    uc = LVDS_Read_Byte(0x2c) & (1<<7);

    /* If the Dual In and Single Out is configured */
    if ((uc != (1<<7)) && (hdmiConfig.singleOrDual == CY_LVDS_LINK_DUAL))
    {
        LVDS_OrREG_TX_Byte(0x2c, (1<<7));
        LVDS_OrREG_TX_Byte(0x52, (1<<1));
    }
    /* If the Single In and Single Out is configured */
    if ((uc != (0<<7)) && (hdmiConfig.singleOrDual == CY_LVDS_LINK_SINGLE))
    {
        uc = (uint8_t) ~(1<<7);
        LVDS_AndREG_TX_Byte(0x2c, uc);
        LVDS_AndREG_TX_Byte(0x52, (~(1<<1)));
    }
#endif
}

/*******************************************************************************
* Function Name: Cy_IT6263_SetLvdsAFE
****************************************************************************//**
*
* \brief
* Configure analog front end for LVDS interface of the chip IT6263.
*
* \param none
*
* \return none
*
*******************************************************************************/
static void Cy_IT6263_SetLvdsAFE(void)
{
    LVDS_Write_Byte(0x3e, 0xaa); //dont ask me "What is it"
    LVDS_Write_Byte(0x3f, 0x02); //dont ask me "What is it"
    LVDS_Write_Byte(0x47, 0xaa); //dont ask me "What is it"
    LVDS_Write_Byte(0x48, 0x02); //dont ask me "What is it"
    LVDS_Write_Byte(0x4f, 0x11); //dont ask me "What is it"
    LVDS_OrREG_TX_Byte(0x0b,0x01);

#ifdef IT626X_SSC
    /* [1]PLL POWER DOWN [2]RCLK SELECT */
    LVDS_OrREG_TX_Byte(0x3c, 0x07);
    LVDS_AndREG_TX_Byte(0x2c, (~(1<<6)));

    /* Reset SRAM */
    LVDS_OrREG_TX_Byte(0x2c, 0x40);
    Cy_SysTick_DelayInUs(1000u);
    LVDS_AndREG_TX_Byte(0x2c, 0xbf);
#else
    LVDS_AndREG_TX_Byte(0x3c, (~0x07));
    LVDS_OrREG_TX_Byte(0x2c, (1<<6));
#endif

    if(100000000L < Cy_IT6263_GetLvdsInputPclk())
    {
        LVDS_AndREG_TX_Byte(0x39, 0x3f);
    }
    else
    {
        LVDS_OrREG_TX_Byte(0x39, 0xc0);
    }

    if (hdmiConfig.encodeFormat == CY_LVDS_FORMAT_VESA)
    {
        LVDS_OrREG_TX_Byte(0x2c, (1<<4));
    }
    else
    {
        LVDS_AndREG_TX_Byte(0x2c, ~(1<<4));   
    }

    LVDS_OrREG_TX_Byte(0x39, 0x02);
    LVDS_AndREG_TX_Byte(0x39, 0xfd);

    //LVDS_Write_Byte(0x2c,0x51); //dont ask me "What is it"
    Cy_SysTick_DelayInUs(20000u);
}

/*******************************************************************************
* Function Name: Cy_IT6263_InitLvds
****************************************************************************//**
*
* \brief
* Intitialize the LVDS interface of the chip IT6263.
*
* \param none
*
* \return none
*
*******************************************************************************/
static void Cy_IT6263_InitLvds(void)
{
    HDMI_Switch_TX_Bank(0);

    /* No available info for this */
    HDMI_Write_Byte(0x1d, 0x66);
    HDMI_Write_Byte(0x1E, 0x01);

#ifdef SUPPORT_REGEN_TIMING
    /* Disable DE only */
    Cy_IT6263_EnableDeOnly(false)
#endif

    /* Reset LVDS interface */
    Cy_IT6263_ResetLvds();
    Cy_SysTick_DelayInUs(10000u);

    /* Update LVDS interface */
    Cy_IT6263_SetLvds();
    Cy_SysTick_DelayInUs(10000u);

    /* Set analog front for LVDS interface */
    Cy_IT6263_SetLvdsAFE();
    Cy_SysTick_DelayInUs(500000u);
}

/*******************************************************************************
* Function Name: Cy_IT6263_IsLvdsStable
****************************************************************************//**
*
* \brief
* Check if the LVDS interface is stable to proceed further.
*
* \param none
*
* \return none
*
*******************************************************************************/
bool Cy_IT6263_IsLvdsStable(void)
{
    uint8_t isStable;
    static uint8_t lvdsUnStableCnt = 0;
    
    /* Set the default configuration for LVDS */
    Cy_IT6263_SetLvds();
    
    /* Check if the configuration is stable */
    isStable = (0x03 & LVDS_Read_Byte(0x30));
    
    /* 0x30[1] LVDS Lock [0] LVDS Stable */
    if(0x03 != isStable)
    {
        lvdsUnStableCnt++;
    }
    else
    {
        lvdsUnStableCnt = 0;
        return true;
    }
    
    /* If stable initialize the interface */
    if(lvdsUnStableCnt > 0)
    {
#ifdef DEBUG_IT6263
        printf("Reset LVDS\n\r");
#endif      
        Cy_IT6263_InitLvds();
        lvdsUnStableCnt = 0;
    }
    return false;
}

/*******************************************************************************
* Function Name: Cy_IT6263_GetLvdsInputPclk
****************************************************************************//**
*
* \brief
* Get the LVDS interface pixel clock of the chip IT6263.
*
* \param none
*
* \return
* uint8_t : api return status
*
*******************************************************************************/
uint8_t Cy_IT6263_DetectVIC(void)
{
    uint16_t hTotal, vTotal, hActive, vActive;

    for(uint8_t i=0; i<NUM_OF_DISPLAY_TIMINGS; i++)
    {
        HDMI_OrREG_TX_Byte(0xa8, (1<<3));

        hTotal = ((HDMI_Read_Byte(0x91)) << 4) + ((HDMI_Read_Byte(0x90)>>4)) + 1;
        vTotal = ((HDMI_Read_Byte(0x99) & 0x07) << 8) + (HDMI_Read_Byte(0x98)) + 1;;
        hActive = abs(((((HDMI_Read_Byte(0x94) & 0xf0)) << 4) + (HDMI_Read_Byte(0x93))) -
                      ((((HDMI_Read_Byte(0x94) & 0x0f)) << 8) + (HDMI_Read_Byte(0x92))));
        vActive = abs(((((HDMI_Read_Byte(0x9C) & 0x70)) << 4) + (HDMI_Read_Byte(0x9B))) -
                      ((((HDMI_Read_Byte(0x9C) & 0x07)) << 8) + (HDMI_Read_Byte(0x9A))));

#if 0
        if(( displayTimings[i].VEC[0] == hTotal ) &&
           ( displayTimings[i].VEC[1] == hActive ) &&
           ( (displayTimings[i].VEC[5]%2048) == vTotal ) &&
           ( (displayTimings[i].VEC[6]%2048) == vActive ))
#else
        if((displayTimings[i].VEC[1] == hActive) && ((displayTimings[i].VEC[6]%2048) == vActive))
#endif
        {
#ifdef DEBUG_IT6263
            printf("VIC = %d\n\r", displayTimings[i].fmt);
            printf("H TOTAL = %d\n\r", hTotal);
            printf("V TOTAL = %d\n\r", vTotal);
            printf("H_Active = %d\n\r", hActive);
            printf("V_Active = %d\n\r", vActive);
            printf("PCLK = %u0,000\n\r", (Cy_IT6263_GetLvdsInputPclk()/10000));
#endif            
            return displayTimings[i].fmt;
        }

    }
    return 0;
}

/*******************************************************************************
* Function Name: Cy_IT6263_GetLvdsInputPclk
****************************************************************************//**
*
* \brief
* Get the LVDS interface pixel clock of the chip IT6263.
*
* \param none
*
* \return none
*
*******************************************************************************/
uint32_t Cy_IT6263_GetLvdsInputPclk(void)
{
    uint8_t u3, stableCnt=0, loopCnt=20;
    uint16_t lastTemp=0;
    uint16_t temp1;

    while(loopCnt--)
    {
        temp1 = Cy_IT6263_GetLvdsInputClockCount();
        if((temp1 < (lastTemp-(lastTemp>>6))) || (temp1 > (lastTemp+(lastTemp>>6))))
        {
            stableCnt=0;
        }
        else
        {
            stableCnt++;
        }
        if(stableCnt > 5)
        {
            break;
        }
        lastTemp = temp1;
    }

    u3 = LVDS_Read_Byte(0x2c);
    if(u3 & 0x80)
        temp1 /= 2;

    if(0x40 & u3)
    {
        return ((49000000L/temp1) << 8);
    }
    else
    {
        return ((27000000L/temp1) << 10);
    }
}

/*******************************************************************************
* Function Name: Cy_IT6263_SetNullPkt
****************************************************************************//**
*
* \brief
* Set null packet for HDMI interface of the chip IT6263.
*
* \param
* isEnable : true or false
*
* \return none
*
*******************************************************************************/
static void Cy_IT6263_SetNullPkt(bool isEnable)
{
    if(isEnable)
    {
        HDMI_Write_Byte(REG_TX_NULL_CTRL, B_ENABLE_PKT|B_REPEAT_PKT);
    }
    else
    {
        HDMI_Write_Byte(REG_TX_NULL_CTRL, 0);
    }
}

/*******************************************************************************
* Function Name: Cy_IT6263_SetAcpPkt
****************************************************************************//**
*
* \brief
* Set ACP packet for HDMI interface of the chip IT6263.
*
* \param
* isEnable : true or false
*
* \return none
*
*******************************************************************************/
static void Cy_IT6263_SetAcpPkt(bool isEnable)
{
    if(isEnable)
    {
        HDMI_Write_Byte(REG_TX_ACP_CTRL, B_ENABLE_PKT|B_REPEAT_PKT);
    }
    else
    {
        HDMI_Write_Byte(REG_TX_ACP_CTRL,0);
    }
}

/*******************************************************************************
* Function Name: Cy_IT6263_SetIsrc1Pkt
****************************************************************************//**
*
* \brief
* Set ISRC1 packet for HDMI interface of the chip IT6263.
*
* \param
* isEnable : true or false
*
* \return none
*
*******************************************************************************/
static void Cy_IT6263_SetIsrc1Pkt(bool isEnable)
{
    if(isEnable)
    {
        HDMI_Write_Byte(REG_TX_ISRC1_CTRL,B_ENABLE_PKT|B_REPEAT_PKT);
    }
    else
    {
        HDMI_Write_Byte(REG_TX_ISRC1_CTRL,0);
    }
}

/*******************************************************************************
* Function Name: Cy_IT6263_SetIsrc2Pkt
****************************************************************************//**
*
* \brief
* Set ISRC2 packet for HDMI interface of the chip IT6263.
*
* \param
* isEnable : true or false
*
* \return none
*
*******************************************************************************/
static void Cy_IT6263_SetIsrc2Pkt(bool isEnable)
{
    if(isEnable)
    {
        HDMI_Write_Byte(REG_TX_ISRC2_CTRL,B_ENABLE_PKT|B_REPEAT_PKT);
    }
    else
    {
        HDMI_Write_Byte(REG_TX_ISRC2_CTRL, 0);
    }
}

/*******************************************************************************
* Function Name: Cy_IT6263_SetAviInfoframePkt
****************************************************************************//**
*
* \brief
* Set AVI packet for HDMI interface of the chip IT6263.
*
* \param
* isEnable : true or false
*
* \return none
*
*******************************************************************************/
static void Cy_IT6263_SetAviInfoframePkt(bool isEnable)
{
    if(isEnable)
    {
        HDMI_Write_Byte(REG_TX_AVI_INFOFRM_CTRL,B_ENABLE_PKT|B_REPEAT_PKT);
    }
    else
    {
        HDMI_Write_Byte(REG_TX_AVI_INFOFRM_CTRL, 0);
    }
}

/*******************************************************************************
* Function Name: Cy_IT6263_SetAudioInfoframePkt
****************************************************************************//**
*
* \brief
* Set audio packet for HDMI interface of the chip IT6263.
*
* \param
* isEnable : true or false
*
* \return none
*
*******************************************************************************/
static void Cy_IT6263_SetAudioInfoframePkt(bool isEnable)
{
    if(isEnable)
    {
        HDMI_Write_Byte(REG_TX_AUD_INFOFRM_CTRL,B_ENABLE_PKT|B_REPEAT_PKT);
    }
    else
    {
        HDMI_Write_Byte(REG_TX_NULL_CTRL, 0);
    }
}

/*******************************************************************************
* Function Name: Cy_IT6263_SetSpdInfoframePkt
****************************************************************************//**
*
* \brief
* Set SPD packet for HDMI interface of the chip IT6263.
*
* \param
* isEnable : true or false
*
* \return none
*
*******************************************************************************/
static void Cy_IT6263_SetSpdInfoframePkt(bool isEnable)
{
    if(isEnable)
    {
        HDMI_Write_Byte(REG_TX_SPD_INFOFRM_CTRL,B_ENABLE_PKT|B_REPEAT_PKT);
    }
    else
    {
        HDMI_Write_Byte(REG_TX_SPD_INFOFRM_CTRL, 0);
    }
}

/*******************************************************************************
* Function Name: Cy_IT6263_SetMpgInfoframePkt
****************************************************************************//**
*
* \brief
* Set MPEG packet for HDMI interface of the chip IT6263.
*
* \param
* isEnable : true or false
*
* \return none
*
*******************************************************************************/
static void Cy_IT6263_SetMpgInfoframePkt(bool isEnable)
{
    if(isEnable)
    {
        HDMI_Write_Byte(REG_TX_MPG_INFOFRM_CTRL,B_ENABLE_PKT|B_REPEAT_PKT);
    }
    else
    {
        HDMI_Write_Byte(REG_TX_MPG_INFOFRM_CTRL,0);
    }
}

#ifdef SUPPORT_REGEN_TIMING
/*******************************************************************************
* Function Name: Cy_IT6263_EnableDeOnly
****************************************************************************//**
*
* \brief
* Enable or disable the DE only mode of the chip IT6263.
*
* \param
* uint16_t : clock counts
*
* \return none
*
*******************************************************************************/
static void Cy_IT6263_EnableDeOnly(bool isDeOnly)
{
    if(isDeOnly)
    {
        HDMI_AndREG_TX_Byte(0xa8, ~(1<<3));
        HDMI_OrREG_TX_Byte(0xa5,(1<<5));
        hdmiStatus.hdmiReGenTimingEnable = true;
    }
    else
    {
        HDMI_OrREG_TX_Byte(0xa8, (1<<3));
        HDMI_AndREG_TX_Byte(0xa5, ~(1<<5));
        hdmiStatus.hdmiReGenTimingEnable = false;
    }
}
#endif

/*******************************************************************************
* Function Name: Cy_IT6263_SetVSInfoFrame
****************************************************************************//**
*
* \brief
* Set the vendor specific frame for IT6263.
*
* \param
* cy_un_hdmi_vendor_infotrame_t : pointer to the vs frame
*
* \return none
*
*******************************************************************************/
static void Cy_IT6263_SetVSInfoFrame(cy_un_hdmi_vendor_infotrame_t *pVSInfoFrame)
{
    int8_t i;
    uint8_t ucData=0 ;

    HDMI_Switch_TX_Bank(1);
    
    /* Check the validity */
    if(pVSInfoFrame->pktbyte.VS_HB[2] > 27) // HB[2] = Checksum ;
    {
        pVSInfoFrame->pktbyte.VS_HB[2] = 27 ;
    }

#ifdef DEBUG_IT6263      
    printf("SetVSIInfo(): \n\r");
#endif
    
    HDMI_Write_Byte(REG_TX_PKT_HB00, pVSInfoFrame->pktbyte.VS_HB[0]); 
    ucData -= pVSInfoFrame->pktbyte.VS_HB[0];
    HDMI_Write_Byte(REG_TX_PKT_HB01, pVSInfoFrame->pktbyte.VS_HB[1]); 
    ucData -= pVSInfoFrame->pktbyte.VS_HB[1];
    HDMI_Write_Byte(REG_TX_PKT_HB02, pVSInfoFrame->pktbyte.VS_HB[2]); 
    ucData -= pVSInfoFrame->pktbyte.VS_HB[2];

    for(i=0; i<(int)(pVSInfoFrame->pktbyte.VS_HB[2]); i++)
    {
        HDMI_Write_Byte(REG_TX_PKT_PB01+i, pVSInfoFrame->pktbyte.VS_DB[1+i]);
        ucData -= pVSInfoFrame->pktbyte.VS_DB[1+i];
    }

    for( ; i<27; i++)
    {
        HDMI_Write_Byte(REG_TX_PKT_PB01+i, 0);
    }

    // HDMI_Write_Byte(REG_TX_PKT_PB01, pVSInfoFrame->pktbyte.VS_DB[1]);
    // HDMI_Write_Byte(REG_TX_PKT_PB02, pVSInfoFrame->pktbyte.VS_DB[2]);
    // HDMI_Write_Byte(REG_TX_PKT_PB03, pVSInfoFrame->pktbyte.VS_DB[3]);
    // HDMI_Write_Byte(REG_TX_PKT_PB04, pVSInfoFrame->pktbyte.VS_DB[4]);
    // HDMI_Write_Byte(REG_TX_PKT_PB05, pVSInfoFrame->pktbyte.VS_DB[5]);
    // HDMI_Write_Byte(REG_TX_PKT_PB06, pVSInfoFrame->pktbyte.VS_DB[6]);

    // for(i = 1; i < VENDORSPEC_INFOFRAME_LEN+1 ; i++)
    // {
    //     ucData -= pVSInfoFrame->pktbyte.VS_DB[i] ;
    // }
    //
    // ucData -= 0x80+VENDORSPEC_INFOFRAME_VER+VENDORSPEC_INFOFRAME_TYPE+VENDORSPEC_INFOFRAME_LEN ;
    ucData &= 0xFF;
    pVSInfoFrame->pktbyte.VS_DB[0] = ucData;

    HDMI_Write_Byte(REG_TX_PKT_PB00, pVSInfoFrame->pktbyte.VS_DB[0]);
    HDMI_Switch_TX_Bank(0);
    Cy_IT6263_SetNullPkt(true);
}

/*******************************************************************************
* Function Name: Cy_IT6263_SetAVIInfoFrame
****************************************************************************//**
*
* \brief
* Set the AVI frame for IT6263.
*
* \param
* cy_un_hdmi_avi_infotrame_t : pointer to the AVI frame
*
* \return none
*
*******************************************************************************/
static void Cy_IT6263_SetAVIInfoFrame(cy_un_hdmi_avi_infotrame_t *pAVIInfoFrame)
{
    int8_t i;
    uint8_t ucData;

    HDMI_Switch_TX_Bank(1);
    HDMI_Write_Byte(REG_TX_AVIINFO_DB1, pAVIInfoFrame->pktbyte.AVI_DB[0]);
    HDMI_Write_Byte(REG_TX_AVIINFO_DB2, pAVIInfoFrame->pktbyte.AVI_DB[1]);
    HDMI_Write_Byte(REG_TX_AVIINFO_DB3, pAVIInfoFrame->pktbyte.AVI_DB[2]);
    HDMI_Write_Byte(REG_TX_AVIINFO_DB4, pAVIInfoFrame->pktbyte.AVI_DB[3]);
    HDMI_Write_Byte(REG_TX_AVIINFO_DB5, pAVIInfoFrame->pktbyte.AVI_DB[4]);
    HDMI_Write_Byte(REG_TX_AVIINFO_DB6, pAVIInfoFrame->pktbyte.AVI_DB[5]);
    HDMI_Write_Byte(REG_TX_AVIINFO_DB7, pAVIInfoFrame->pktbyte.AVI_DB[6]);
    HDMI_Write_Byte(REG_TX_AVIINFO_DB8, pAVIInfoFrame->pktbyte.AVI_DB[7]);
    HDMI_Write_Byte(REG_TX_AVIINFO_DB9, pAVIInfoFrame->pktbyte.AVI_DB[8]);
    HDMI_Write_Byte(REG_TX_AVIINFO_DB10, pAVIInfoFrame->pktbyte.AVI_DB[9]);
    HDMI_Write_Byte(REG_TX_AVIINFO_DB11, pAVIInfoFrame->pktbyte.AVI_DB[10]);
    HDMI_Write_Byte(REG_TX_AVIINFO_DB12, pAVIInfoFrame->pktbyte.AVI_DB[11]);
    HDMI_Write_Byte(REG_TX_AVIINFO_DB13, pAVIInfoFrame->pktbyte.AVI_DB[12]);
    for(i=0, ucData= 0; i<13; i++)
    {
        ucData -= pAVIInfoFrame->pktbyte.AVI_DB[i] ;
    }

    ucData -= 0x80 + AVI_INFOFRAME_VER + AVI_INFOFRAME_TYPE + AVI_INFOFRAME_LEN;
    HDMI_Write_Byte(REG_TX_AVIINFO_SUM, ucData);

    HDMI_Switch_TX_Bank(0);
    Cy_IT6263_SetAviInfoframePkt(true);
}

/*******************************************************************************
* Function Name: Cy_IT6263_InitInstance
****************************************************************************//**
*
* \brief
* Abort the DDC interface for IT6263.
*
* \param none
*
* \return none
*
*******************************************************************************/
static void Cy_IT6263_AbortDDC(void)
{
    uint8_t CPDesire, swReset, ddcMaster, uc;

    /* save the SW reset,DDC master,and CP Desire setting. */
    swReset = HDMI_Read_Byte(REG_TX_SW_RST);
    CPDesire = HDMI_Read_Byte(REG_TX_HDCP_DESIRE);
    ddcMaster = HDMI_Read_Byte(REG_TX_DDC_MASTER_CTRL);

    /* Write the default to the DDC register */
    HDMI_Write_Byte(REG_TX_HDCP_DESIRE, 0x08 | (CPDesire & (~B_CPDESIRE)));
    HDMI_Write_Byte(REG_TX_SW_RST, swReset | B_HDCP_RST);
    HDMI_Write_Byte(REG_TX_DDC_MASTER_CTRL, (B_MASTERDDC | B_MASTERHOST));

    /* do abort DDC twice. */
    for(uint8_t i=0; i<2; i++)
    {
        /* Write DDC abort command */
        HDMI_Write_Byte(REG_TX_DDC_CMD, CMD_DDC_ABORT);

        for(uint8_t timeout=0; timeout<200; timeout++)
        {
            /* Check if DDC is aborted */
            uc = HDMI_Read_Byte(REG_TX_DDC_STATUS);
            if (uc & B_DDC_DONE)
            {
                break ;
            }

            if( uc & (B_DDC_NOACK | B_DDC_WAITBUS | B_DDC_ARBILOSE))
            {
#ifdef DEBUG_IT6263      
                printf("AbortDDC Fail by reg16=%02X\n\r", uc);
#endif              
                break;
            }
            Cy_SysTick_DelayInUs(1000);
        }
    }

    /* restore the SW reset,DDC master,and CP Desire setting. */
    HDMI_Write_Byte(REG_TX_SW_RST, swReset);
    HDMI_Write_Byte(REG_TX_HDCP_DESIRE, 0x08 | CPDesire);
    HDMI_Write_Byte(REG_TX_DDC_MASTER_CTRL, ddcMaster);
}

/*******************************************************************************
* Function Name: Cy_IT6263_InitInstance
****************************************************************************//**
*
* \brief
* Clear the DDC interface for IT6263.
*
* \param none
*
* \return none
*
*******************************************************************************/
static void Cy_IT6263_ClearDDC(void)
{
    HDMI_Write_Byte(REG_TX_DDC_MASTER_CTRL, (B_MASTERDDC | B_MASTERHOST));
    HDMI_Write_Byte(REG_TX_DDC_CMD, CMD_FIFO_CLR);
}

/*******************************************************************************
* Function Name: Cy_IT6263_SetAVMute
****************************************************************************//**
*
* \brief
* Set the AV mute for IT6263.
*
* \param
* bEnable : enable the AV mute 
*
* \return none
*
*******************************************************************************/
void Cy_IT6263_SetAVMute(uint8_t bEnable)
{
    uint8_t uc ;

    HDMI_Switch_TX_Bank(0);

    uc = HDMI_Read_Byte(REG_TX_GCP);
    uc &= ~B_TX_SETAVMUTE ;
    uc |= bEnable ? B_TX_SETAVMUTE : 0;

    /* Write the AV mute status */
    HDMI_Write_Byte(REG_TX_GCP,uc);
    HDMI_Write_Byte(REG_TX_PKT_GENERAL_CTRL, B_ENABLE_PKT | B_REPEAT_PKT);
}

/*******************************************************************************
* Function Name: Cy_IT6263_SetupAFE
****************************************************************************//**
*
* \brief
* Intitialize the chip AFE for IT6263.
*
* \param
* cy_en_hdmi_video_pclk_t : pclk clock level
*
* \return none
*
*******************************************************************************/
static void Cy_IT6263_SetupAFE(cy_en_hdmi_video_pclk_t pclkLevel)
{
    /* Turn off reg61 before SetupAFE parameters. */
    HDMI_Write_Byte(REG_TX_AFE_DRV_CTRL, B_AFE_DRV_RST);

#ifdef DEBUG_IT6263      
    printf("SetupAFE()\n\r");
#endif
        
    //TMDS Clock < 80MHz    TMDS Clock > 80MHz
    //Reg61     0x03        0x03
    //Reg62     0x18        0x88
    //Reg63     Default     Default
    //Reg64     0x08        0x80
    //Reg65     Default     Default
    //Reg66     Default     Default
    //Reg67     Default     Default

    switch(pclkLevel)
    {
        case CY_HDMI_PCLK_HIGH:
            HDMI_Write_Byte(REG_TX_AFE_XP_CTRL, 0x88);  // reg62
            HDMI_Write_Byte(REG_TX_AFE_ISW_CTRL, 0x10); // reg63
            HDMI_Write_Byte(REG_TX_AFE_IP_CTRL, 0x84);  // reg64
            break;

        default:
            HDMI_Write_Byte(REG_TX_AFE_XP_CTRL, 0x18);  // reg62
            HDMI_Write_Byte(REG_TX_AFE_ISW_CTRL, 0x10); // reg63
            HDMI_Write_Byte(REG_TX_AFE_IP_CTRL, 0x0C);  // reg64
            break;
    }
}

/*******************************************************************************
* Function Name: Cy_IT6263_SoftwareVideoReset
****************************************************************************//**
*
* \brief
* Software reset of the video interface for IT6263.
*
* \param none
*
* \return none
*
*******************************************************************************/
static void Cy_IT6263_SoftwareVideoReset(void)
{
    uint8_t resetCount = 5, intClr = 0;

    /* Reset the video unit */
    HDMI_OrREG_TX_Byte(REG_TX_SW_RST, B_VID_RST);
    Cy_SysTick_DelayInUs(1000u);
    HDMI_AndREG_TX_Byte(REG_TX_SW_RST, ~(B_VID_RST));

    /* Check if the reset is done */
    while(0 == (HDMI_Read_Byte(REG_TX_SYS_STATUS) & B_TXVIDSTABLE))
    {
        Cy_SysTick_DelayInUs(100000u);
        resetCount--;

        if(resetCount == 0)
        {
            break;
        }
#ifdef DEBUG_IT6263_message
        printf("\n\r wait video stable.\n") ;
#endif        
    }
    
#ifdef DEBUG_IT6263_message
    printf("\n\r ====================== reset video =========================\n");
#endif    

    HDMI_OrREG_TX_Byte(REG_TX_INT_CLR1, B_CLR_VIDSTABLE);
    intClr |= (HDMI_Read_Byte(REG_TX_SYS_STATUS) & (~B_CLR_AUD_CTS)) | B_INTACTDONE;
    HDMI_Write_Byte(REG_TX_SYS_STATUS, intClr);
    intClr &= ~B_INTACTDONE;
    HDMI_Write_Byte(REG_TX_SYS_STATUS, intClr);
}

/*******************************************************************************
* Function Name: Cy_IT6263_FireAFE
****************************************************************************//**
*
* \brief
* Enable the AFE interface for IT6263.
*
* \param none
*
* \return none
*
*******************************************************************************/
static void Cy_IT6263_FireAFE(void)
{
    Cy_IT6263_SoftwareVideoReset();
    HDMI_Switch_TX_Bank(0) ;
    HDMI_Write_Byte(REG_TX_AFE_DRV_CTRL, 0);
    
#ifdef DEBUG_IT6263
    printf("Fire AFE:\n\r");
    for(uint8_t reg = 0x61 ; reg <= 0x67 ; reg++)
    {
        printf("Reg[%02X] = %02X\n\r", reg, HDMI_Read_Byte(reg));
    }
#endif
    
    hdmiInstance[0].bVideoOut = true;
}

/*******************************************************************************
* Function Name: Cy_IT6263_ReadEDID
****************************************************************************//**
*
* \brief
* Enable the AFE interface for IT6263.
*
* \param
* pData : pointer to data
*
* \param
* bSegment : segment number
*
* \param
* offset : EDID offset
*
* \param
* count : values in EDID
*
* \return
* bool : return status
*
*******************************************************************************/
static bool Cy_IT6263_ReadEDID(volatile uint8_t *pData, uint8_t bSegment, uint8_t offset, uint16_t count)
{
    uint16_t remainedCount, reqCount, timeOut;
    uint8_t bCurrOffset, ucdata;
    volatile uint8_t *pBuff = pData;

    if(!pData)
    {
        return false;
    }

    if(HDMI_Read_Byte(REG_TX_INT_STAT1) & B_INT_DDC_BUS_HANG)
    {
#ifdef DEBUG_IT6263      
        printf("Abort DDC()\n\r");
#endif
        Cy_IT6263_AbortDDC();
    }
    Cy_IT6263_ClearDDC();

    remainedCount = count;
    bCurrOffset = offset ;

    HDMI_Switch_TX_Bank(0);

    while(remainedCount > 0)
    {
        reqCount = (remainedCount > DDC_FIFO_MAXREQ) ? DDC_FIFO_MAXREQ : remainedCount;
        
#ifdef DEBUG_IT6263      
        printf("ReadEDID(): ReqCount = %d,bCurrOffset = %d\n\r", reqCount, bCurrOffset);
#endif
        
        HDMI_Write_Byte(REG_TX_DDC_MASTER_CTRL, B_MASTERDDC | B_MASTERHOST);
        HDMI_Write_Byte(REG_TX_DDC_CMD, CMD_FIFO_CLR);

        for(timeOut=0; timeOut<200; timeOut++)
        {
            ucdata = HDMI_Read_Byte(REG_TX_DDC_STATUS);
            if(ucdata & B_DDC_DONE)
            {
                break;
            }

            if((ucdata & B_DDC_ERROR) || (HDMI_Read_Byte(REG_TX_INT_STAT1) & B_INT_DDC_BUS_HANG))
            {
#ifdef DEBUG_IT6263      
                printf("Abort DDC()\n\r");
#endif              
                Cy_IT6263_AbortDDC();
                return false;
            }
        }

        HDMI_Write_Byte(REG_TX_DDC_MASTER_CTRL, B_MASTERDDC|B_MASTERHOST);
        HDMI_Write_Byte(REG_TX_DDC_HEADER, DDC_EDID_ADDRESS); // for EDID ucdata get
        HDMI_Write_Byte(REG_TX_DDC_REQOFF, bCurrOffset);
        HDMI_Write_Byte(REG_TX_DDC_REQCOUNT, (uint8_t) reqCount);
        HDMI_Write_Byte(REG_TX_DDC_EDIDSEG, bSegment);
        HDMI_Write_Byte(REG_TX_DDC_CMD, CMD_EDID_READ);

        bCurrOffset += reqCount;
        remainedCount -= reqCount;

        for(timeOut=250; timeOut>0; timeOut--)
        {
            Cy_SysTick_DelayInUs(1000u);
            ucdata = HDMI_Read_Byte(REG_TX_DDC_STATUS);
            if(ucdata & B_DDC_DONE)
            {
                break;
            }

            if(ucdata & B_DDC_ERROR)
            {
                return false;
            }
        }

        if(timeOut == 0)
        {
#ifdef DEBUG_IT6263      
            printf("ReadEDID(): DDC TimeOut. %02X\n\r", ucdata);
#endif          
            return false;
        }

        do
        {
            *(pBuff++) = HDMI_Read_Byte(REG_TX_DDC_READFIFO);
            reqCount--;
        } while(reqCount > 0);
    }

    return true;
}

/*******************************************************************************
* Function Name: Cy_IT6263_HDMI_GetEDIDData
****************************************************************************//**
*
* \brief
* Get the EDID data for IT6263.
*
* \param
* blockID : block id
*
* \param
* pEDIDData : pointer to EDID data
*
* \return
* bool : function result type
*
*******************************************************************************/
bool Cy_IT6263_HDMI_GetEDIDData(uint8_t blockID, volatile uint8_t* pEDIDData)
{
    if(!pEDIDData)
    {
        return false;
    }

    if(Cy_IT6263_ReadEDID(pEDIDData, blockID/2, (blockID%2)*128, 128) == false)
    {
        return false;
    }

    return true;
}

/*******************************************************************************
* Function Name: Cy_IT6263_HdmiEnableVSInfoFrame
****************************************************************************//**
*
* \brief
* Enable the vendor specific infoframe for IT6263.
*
* \param
* bEnable : enable or disable
*
* \param
* pVSInfoFrame : pointer to VS frame
*
* \return
* bool : function result type
*
*******************************************************************************/
bool Cy_IT6263_HdmiEnableVSInfoFrame(uint8_t bEnable, uint8_t *pVSInfoFrame)
{
    if(!bEnable)
    {
        Cy_IT6263_SetNullPkt(false);
        return true;
    }

    Cy_IT6263_SetVSInfoFrame((cy_un_hdmi_vendor_infotrame_t*) pVSInfoFrame);
    return true;
}

/*******************************************************************************
* Function Name: Cy_IT6263_HdmiEnableAVIInfoFrame
****************************************************************************//**
*
* \brief
* Enable the AVI infoframe for IT6263.
*
* \param
* bEnable : enable or disable
*
* \param
* pAVIInfoFrame : pointer to AVI frame
*
* \return
* bool : function result type
*
*******************************************************************************/
bool Cy_IT6263_HdmiEnableAVIInfoFrame(uint8_t bEnable, volatile uint8_t *pAVIInfoFrame)
{
    if(!bEnable)
    {
        Cy_IT6263_SetAviInfoframePkt(false);
        HDMI_Switch_TX_Bank(1);
        HDMI_AndREG_TX_Byte(REG_TX_AVIINFO_DB1, ~(3<<5));
        HDMI_Switch_TX_Bank(0);
        return true;
    }

    Cy_IT6263_SetAVIInfoFrame((cy_un_hdmi_avi_infotrame_t *)pAVIInfoFrame);
    return true;
}

#ifdef SUPPORT_REGEN_TIMING
/*******************************************************************************
* Function Name: Cy_IT6263_InitInstance
****************************************************************************//**
*
* \brief
* Intitialize the chip instance for IT6263.
*
* \param
* cy_stc_hdmi_instance_config_t : pointer to instance
*
* \return
* cy_en_hdmi_trx_status_t : function result type
*
*******************************************************************************/
bool Cy_IT6263_HdmiReGenTiming(uint8_t fmtAssign)
{
    uint8_t HRS, HRE ;
    uint8_t HDES, HDEE;
    uint8_t VRS, VRE;
    uint8_t VDES, VDEE   ;
    uint8_t VRS2ndRise, VRS2nd, VRE2nd;
    uint8_t VDES2nd, VDEE2nd;
    uint8_t HTotal, VTotal;
    uint8_t i;
    uint8_t H_Total, H_FBH, H_SyncW, H_BBH, H_DEW;
    uint8_t V_Total,  V_FBH,  V_SyncW,  V_BBH, V_DEW;
    uint8_t SyncPol;
    uint8_t fmt_index;
    uint8_t interlaced;
    uint8_t reg90, reg91, reg92, reg93, reg94, reg95, reg96, reg97, reg98;
    uint8_t reg99, reg9A, reg9B, reg9C, reg9D, reg9E, reg9F, regA0, regA1, regA2, regA3;
    uint8_t regA4, regA5;
    fmt_index=0;

    for(i=0; i<MaxIndex; i++)
    {
        if(TimingTable[i].fmt == fmt_assign) 
        {
            fmt_index = i;
        }
    }

    if((i == MaxIndex) && (fmt_index == 0))
    {
        Cy_IT6263_EnableDeOnly(false);
        return false;
    }
    interlaced = TimingTable[fmt_index].interlaced;

    H_Total =TimingTable[fmt_index].VEC[0];
    H_DEW   =TimingTable[fmt_index].VEC[1];
    H_FBH   =TimingTable[fmt_index].VEC[2];
    H_SyncW =TimingTable[fmt_index].VEC[3];
    H_BBH   =TimingTable[fmt_index].VEC[4];
    V_Total =TimingTable[fmt_index].VEC[5];
    V_DEW   =TimingTable[fmt_index].VEC[6];
    V_FBH   =TimingTable[fmt_index].VEC[7];
    V_SyncW =TimingTable[fmt_index].VEC[8];
    V_BBH   =TimingTable[fmt_index].VEC[9];
    SyncPol =TimingTable[fmt_index].VEC[10];

    HTotal = H_Total-1;
    VTotal = V_Total-1;
    HRS = H_FBH-1;
    HRE = HRS + H_SyncW;
    HDES = HRE + H_BBH;
    HDEE = HDES + H_DEW;

    VRS = V_FBH;
    VRE = VRS + V_SyncW;
    VDES = VRE + V_BBH;
    VDEE = (VDES + V_DEW)%V_Total;
    VRS2nd = VDEE + V_FBH;
    VRE2nd = VRS2nd + V_SyncW;
    VDES2nd = VRS2nd + V_BBH;
    VDEE2nd = (VDES2nd + V_DEW) % V_Total;
    VRS2ndRise =  H_Total/2 + HRS;
    VDES = VRE + V_BBH-1;
    VDEE = (VDES + V_DEW)%V_Total;
    VDES2nd = VRS2nd + V_SyncW + V_BBH ;
    VDEE2nd = (VDES2nd + V_DEW)%V_Total;

    reg90 = ((HTotal & 0xF) << 4) + (SyncPol << 1) ;
    reg91 = ((HTotal & 0xFF0) >> 4);
    reg92 = HDES & 0xFF;
    reg93 = HDEE & 0xFF;
    reg94 = ((HDEE & 0xF00) >> 4) + ((HDES & 0xF00) >> 8);

    reg95 = HRS & 0xFF;
    reg96 = HRE & 0xFF;
    reg97 = ((HRE & 0xF00) >> 4) + ((HRS & 0xF00) >> 8);
    reg98 = VTotal & 0xFF;
    reg99 = (VTotal & 0xF00) >> 8;
    reg9A = VDES & 0xFF;
    reg9B = VDEE & 0xFF;
    reg9C = ((VDEE & 0xF00) >> 4) + ((VDES & 0xF00) >> 8);
    reg9D = VDES2nd & 0xFF;
    reg9E = VDEE2nd & 0xFF;
    reg9F = ((VDEE2nd & 0xF00) >> 4) + ((VDES2nd & 0xF00) >> 8);
    regA0 = VRS & 0xFF;
    regA1 = ((VRE & 0xF) << 4) + ((VRS & 0xF00) >> 8);

    regA2 = VRS2nd & 0xFF;
    if(interlaced == 1u) 
    {
        regA3 = ((VRE2nd & 0xF) << 4) + ((VRS2nd & 0xF00) >> 8);
    }
	else 
    {
        regA3 = 0xFF;
    }

    regA4 = VRS2ndRise & 0xFF;
    regA5 = 0x20 + ((VRS2ndRise & 0xF00) >> 8);
    HDMI_AndREG_TX_Byte(0xa8, ~(1<<3));

    HDMI_Switch_TX_Bank(0);
    HDMI_Write_Byte(0x90, reg90);
    HDMI_Write_Byte(0x91, reg91);
    HDMI_Write_Byte(0x92, reg92);
    HDMI_Write_Byte(0x93, reg93);
    HDMI_Write_Byte(0x94, reg94);
    HDMI_Write_Byte(0x95, reg95);
    HDMI_Write_Byte(0x96, reg96);
    HDMI_Write_Byte(0x97, reg97);
    HDMI_Write_Byte(0x98, reg98);
    HDMI_Write_Byte(0x99, reg99);
    HDMI_Write_Byte(0x9a, reg9A);
    HDMI_Write_Byte(0x9b, reg9B);
    HDMI_Write_Byte(0x9c, reg9C);
    HDMI_Write_Byte(0x9d, reg9D);
    HDMI_Write_Byte(0x9e, reg9E);
    HDMI_Write_Byte(0x9f, reg9F);
    HDMI_Write_Byte(0xa0, regA0);
    HDMI_Write_Byte(0xa1, regA1);
    HDMI_Write_Byte(0xa2, regA2);
    HDMI_Write_Byte(0xa3, regA3);
    HDMI_Write_Byte(0xa4, regA4);
    
    //Cy_IT6263_EnableDeOnly(true);
    HDMI_Write_Byte(0xa5, regA5);
    HDMI_AndREG_TX_Byte(0xa8, ~(1<<3));
    return true;
}
#endif

/*******************************************************************************
* Function Name: Cy_IT6263_HdmiDisableVideoOutput
****************************************************************************//**
*
* \brief
* Disable the HDMI output for IT6263.
*
* \param none
*
* \return none
*
*******************************************************************************/
void Cy_IT6263_HdmiDisableVideoOutput(void)
{
    uint8_t uc = HDMI_Read_Byte(REG_TX_SW_RST) | B_VID_RST;
    HDMI_Write_Byte(REG_TX_SW_RST, uc);
    HDMI_Write_Byte(REG_TX_AFE_DRV_CTRL, (B_AFE_DRV_RST | B_AFE_DRV_PWD));
    hdmiInstance[0].bVideoOut = false;
}

/*******************************************************************************
* Function Name: Cy_IT6263_HdmiDisableAudioOutput
****************************************************************************//**
*
* \brief
* Disable the HDMI audio output for IT6263.
*
* \param none
*
* \return none
*
*******************************************************************************/
void Cy_IT6263_HdmiDisableAudioOutput(void)
{
    HDMI_OrREG_TX_Byte(REG_TX_PKT_SINGLE_CTRL, (1<<5));
    /*
    for(uint8_t msec=0; msec<32; msec++)
    {
        for(uint16_t count=0; count<2048; count++)
        {
            _nop_();_nop_();_nop_();_nop_();
            _nop_();_nop_();_nop_();_nop_();
        }
    }
    */
    HDMI_OrREG_TX_Byte(REG_TX_SW_RST, (B_AUD_RST|B_AREF_RST));
    //HDMI_AndREG_TX_Byte(0x59, ~(1<<2)); //for test
}

/*******************************************************************************
* Function Name: Cy_IT6263_HdmiSetColorOutputDepth
****************************************************************************//**
*
* \brief
* Set the HDMI output color depth and phase for IT6263.
*
* \param
* colorDepth : color depth
*
* \param
* bPhase : phase of the color
*
* \return none
*
*******************************************************************************/
void Cy_IT6263_HdmiSetColorOutputDepth(uint8_t colorDepth, uint8_t bPhase)
{
    uint8_t uc, bColorDepth;

    bPhase = (~bPhase);
    if(colorDepth == 30)
    {
        bColorDepth = B_CD_30 ;
    }
    else if (colorDepth == 36)
    {
        bColorDepth = B_CD_36 ;
    }/*
    else if (colorDepth == 24)
    {
        bColorDepth = B_CD_24 ;
    }*/
    else
    {
        bColorDepth = 0 ; // not indicated
    }

    /* Update the color depth and phase */
    HDMI_Switch_TX_Bank(0);
    uc = HDMI_Read_Byte(REG_TX_GCP);
    uc &= ~B_COLOR_DEPTH_MASK ;
    uc |= bColorDepth & B_COLOR_DEPTH_MASK;
    HDMI_Write_Byte(REG_TX_GCP, uc);
}

/*******************************************************************************
* Function Name: Cy_IT6263_HdmiSetVideoInput
****************************************************************************//**
*
* \brief
* Set the video input format for IT6263.
*
* \param
* inSignalType : input video signal type
*
* \return none
*
*******************************************************************************/
void Cy_IT6263_HdmiSetVideoInput(uint8_t inSignalType)
{
    hdmiInstance[0].bInputVideoSignalType = inSignalType;
}

/*******************************************************************************
* Function Name: Cy_IT6263_HdmiEnableVideoOutput
****************************************************************************//**
*
* \brief
* Set the video input format for IT6263.
*
* \param
* pclkLevel : pclk clock level
*
* \param
* inColorMode : input video color mode
*
* \param
* outColorMode : output video color mode
*
* \param
* bHDMI : hdmi mode
*
* \return none
*
*******************************************************************************/
void Cy_IT6263_HdmiEnableVideoOutput(cy_en_hdmi_video_pclk_t pclkLevel, uint8_t inColorMode, uint8_t outColorMode, uint8_t bHDMI)
{
    /* Update the HDMI mode */
    hdmiInstance[0].bHDMIMode = (uint8_t) bHDMI;
    Cy_IT6263_SetAVMute(true);

    HDMI_Switch_TX_Bank(1);
    HDMI_Write_Byte(REG_TX_AVIINFO_DB1, 0x10) ;
    HDMI_Switch_TX_Bank(0);
    HDMI_Write_Byte(0x70, 0) ;
    HDMI_Write_Byte(0x71, 0) ;
    if(hdmiInstance[0].bHDMIMode)
    {
        HDMI_Write_Byte(REG_TX_HDMI_MODE, B_TX_HDMI_MODE);
    }
    else
    {
        HDMI_Write_Byte(REG_TX_HDMI_MODE, B_TX_DVI_MODE);
    }

#ifdef INVERT_VID_LATCHEDGE
    uc = HDMI_Read_Byte(REG_TX_CLK_CTRL1);
    uc |= B_VDO_LATCH_EDGE ;
    HDMI_Write_Byte(REG_TX_CLK_CTRL1, uc);
#endif

    Cy_IT6263_SetupAFE(pclkLevel); // pass if High Freq request
    Cy_IT6263_FireAFE();

    HDMI_Write_Byte(REG_TX_INT_CLR0, 0);
    HDMI_Write_Byte(REG_TX_INT_CLR1, B_CLR_VIDSTABLE);
    HDMI_Write_Byte(REG_TX_SYS_STATUS, B_INTACTDONE);
}


/*******************************************************************************
* Function Name: Cy_IT6263_InitInstance
****************************************************************************//**
*
* \brief
* Intitialize the chip instance for IT6263.
*
* \param
* pHPD : pointer to HPD status
*
* \param
* pHPDChange : pointer to HPD change status
*
* \return
* uint8_t : HPD status return type
*
*******************************************************************************/
uint8_t Cy_IT6263_HdmiCheckStatus(uint8_t *pHPD, uint8_t *pHPDChange)
{
    uint8_t intData1, intData2, intData3, sysStat, intClr3=0;
    uint8_t statusHPD, prevHPD = hdmiInstance[0].bHPD;

    /* Read the system status */
    sysStat = HDMI_Read_Byte(REG_TX_SYS_STATUS);

    /* If HDMI plug in detected */
    if((sysStat & (B_HPDETECT/*|B_RXSENDETECT*/)) == (B_HPDETECT/*|B_RXSENDETECT*/))
    {
        statusHPD = true;
#ifdef DEBUG_IT6263
        //printf("\nREG_TX_SYS_STATUS = %X\r", sysStat);
#endif
    }
    else
    {
        statusHPD = false;
    }

    if(pHPDChange)
    {
        *pHPDChange = false;
    }

    if(statusHPD == false)
    {
        hdmiInstance[0].bAuthenticated = false;
    }

    /* If HDMI status is active */
    if(sysStat & B_INT_ACTIVE)
    {
        /* Check interrupt status1 register */
        intData1 = HDMI_Read_Byte(REG_TX_INT_STAT1);
#ifdef DEBUG_IT6263      
        printf("\nINT_Handler: reg%X = %X\r", REG_TX_INT_STAT1, intData1);
#endif        
        if(intData1 & B_INT_AUD_OVERFLOW)
        {
            HDMI_OrREG_TX_Byte(0xc5, (1<<4));
            HDMI_OrREG_TX_Byte(REG_TX_SW_RST, (B_AUD_RST|B_AREF_RST));
            HDMI_AndREG_TX_Byte(REG_TX_SW_RST, ~(B_AUD_RST|B_AREF_RST));
        }
        
        /* If error in DDC operation */
        if(intData1 & B_INT_DDCFIFO_ERR)
        {
#ifdef DEBUG_IT6263      
            printf("DDC FIFO Error.\n\r");
#endif          
            Cy_IT6263_ClearDDC();
        }

        /* If DDC bus is hanged */
        if(intData1 & B_INT_DDC_BUS_HANG)
        {
#ifdef DEBUG_IT6263      
            printf("DDC Bus Hang.\n\r");
#endif
            Cy_IT6263_AbortDDC();
        }

        /* If DDC bus is detected successfully */
        if(intData1 & (B_INT_HPD_PLUG|B_INT_RX_SENSE))
        {
            if(pHPDChange && (hdmiInstance[0].bHPD != statusHPD))
            {
#ifdef DEBUG_IT6263      
                printf("2-*pHPDChange = %X\n\r", *pHPDChange);
#endif
                *pHPDChange = true;
            }

            if(statusHPD == false)
            {
#ifdef DEBUG_IT6263      
                printf("HPD = %X\n\r", statusHPD);
#endif              
                HDMI_Write_Byte(REG_TX_SW_RST, (B_AREF_RST | B_VID_RST | B_AUD_RST | B_HDCP_RST));
                Cy_SysTick_DelayInUs(1000u);
                HDMI_Write_Byte(REG_TX_AFE_DRV_CTRL,B_AFE_DRV_RST|B_AFE_DRV_PWD);
            }
        }

        /* Check interrupt status2 register */
        intData2 = HDMI_Read_Byte(REG_TX_INT_STAT2);
        intData2 = intData2;
#ifdef DEBUG_IT6263      
        printf("INT_Handler: reg%x = %x\n\r", REG_TX_INT_STAT2, intData2);
#endif

        /* Check interrupt status3 register */
        intData3 = HDMI_Read_Byte(REG_TX_INT_STAT3);
#ifdef DEBUG_IT6263      
        printf("INT_Handler: reg%x = %x\n\r", REG_TX_INT_STAT3, intData3);
#endif        
        
        if(intData3 & B_INT_VIDSTABLE)
        {
            sysStat = HDMI_Read_Byte(REG_TX_SYS_STATUS);
            if(hdmiInstance[0].bVideoOut == false || (sysStat & B_TXVIDSTABLE))
            {
                hdmiStatus.hdmiIsChangeMode = true;
            }
            else
            {
                hdmiInstance[0].bVideoOut = false;
            }
        }

        /* Clear the interrupt control registers */
        HDMI_Write_Byte(REG_TX_INT_CLR0, 0xFF);
        HDMI_Write_Byte(REG_TX_INT_CLR1, 0xFF);
        intClr3 = (HDMI_Read_Byte(REG_TX_SYS_STATUS)) | B_CLR_AUD_CTS | B_INTACTDONE;
        HDMI_Write_Byte(REG_TX_SYS_STATUS, intClr3);
        intClr3 &= ~(B_INTACTDONE);
        HDMI_Write_Byte(REG_TX_SYS_STATUS, intClr3);
    }
    else
    {
        /* Check if HPD status is changed */
        if(pHPDChange)
        {
            if(statusHPD != prevHPD)
            {
                *pHPDChange = true;
            }
            else
            {
               *pHPDChange = false;
            }
        }
    }

    if(pHPDChange)
    {
        if((*pHPDChange == true) && (statusHPD == false))
        {
            HDMI_Write_Byte(REG_TX_AFE_DRV_CTRL, (B_AFE_DRV_RST | B_AFE_DRV_PWD));
        }
    }

    if(pHPD)
    {
         *pHPD = statusHPD;
    }

    /* Store and return the HPD status */
    hdmiInstance[0].bHPD = statusHPD ;
    return statusHPD ;
}

/*******************************************************************************
* Function Name: Cy_IT6263_InitInstance
****************************************************************************//**
*
* \brief
* Intitialize the chip instance for IT6263.
*
* \param
* cy_stc_hdmi_instance_config_t : pointer to instance
*
* \return none
*
*******************************************************************************/
void Cy_IT6263_InitInstance(cy_stc_hdmi_instance_config_t *pInstance)
{
    /* Update the instance init data */
    hdmiInstance[0] = *pInstance;
}

/*******************************************************************************
* Function Name: Cy_IT6263_DeInit
****************************************************************************//**
*
* \brief
* Disable the chip IT6263.
*
* \param none
*
* \return none
*
*******************************************************************************/
void Cy_IT6263_DeInit(void)
{
    HDMI_Write_Byte(REG_TX_SW_RST, (B_AREF_RST | B_VID_RST | B_AUD_RST | B_HDCP_RST));
    Cy_SysTick_DelayInUs(1000u);
    HDMI_Write_Byte(REG_TX_AFE_DRV_CTRL, (B_AFE_DRV_RST | B_AFE_DRV_PWD));
}

/*******************************************************************************
* Function Name: Cy_IT6263_Init
****************************************************************************//**
*
* \brief
* Intitialize the chip specific function for IT6263.
*
* \param none
*
* \return none
*
*******************************************************************************/
void Cy_IT6263_Init(void)
{
    uint8_t intclr;

    /* Software reset the transceiver */
    HDMI_Write_Byte(REG_TX_SW_RST,B_REF_RST|B_VID_RST|B_AUD_RST|B_AREF_RST|B_HDCP_RST);
    Cy_SysTick_DelayInUs(1000u);

    /* Swicth to HDMI bank 0 */
    HDMI_Switch_TX_Bank(0);
    HDMI_Write_Byte(REG_TX_INT_CTRL, hdmiInstance[0].bIntType);
    hdmiInstance[0].bIntPOL = (hdmiInstance[0].bIntType & B_INTPOL_ACTH) ? true : false;
    hdmiInstance[0].TxEMEMStatus = true;

    /* Software reset the transceiver */
    HDMI_Write_Byte(REG_TX_SW_RST,B_AUD_RST|B_AREF_RST|B_HDCP_RST);
    
    /* Initialize the LVDS interface */
    Cy_IT6263_InitLvds();

    /* Avoid power loading in un play status. */
    HDMI_Write_Byte(REG_TX_AFE_DRV_CTRL,B_AFE_DRV_RST|B_AFE_DRV_PWD);
    
    /* Setup HDCP ROM */
    HDMI_AndREG_TX_Byte(0xF3, ~0x30);
    HDMI_OrREG_TX_Byte(0xF3, 0x20);
    
    /* set interrupt mask,mask value 0 is interrupt available. */
    //HDMI_Write_Byte(REG_TX_INT_MASK1,0xB2);
    HDMI_Write_Byte(REG_TX_INT_MASK1, 0x30);
    HDMI_Write_Byte(REG_TX_INT_MASK2, 0xF8);
    HDMI_Write_Byte(REG_TX_INT_MASK3, 0x37);
    HDMI_Switch_TX_Bank(0);
    
    /* Disable all info packaet */
    Cy_IT6263_SetNullPkt(false);
    Cy_IT6263_SetAcpPkt(false);
    Cy_IT6263_SetIsrc1Pkt(false);
    Cy_IT6263_SetIsrc2Pkt(false);
    Cy_IT6263_SetAviInfoframePkt(false);
    Cy_IT6263_SetAudioInfoframePkt(false);
    Cy_IT6263_SetSpdInfoframePkt(false);
    Cy_IT6263_SetMpgInfoframePkt(false);

    HDMI_Switch_TX_Bank(1);
    HDMI_AndREG_TX_Byte(REG_TX_AVIINFO_DB1, ~(3<<5));
    HDMI_Switch_TX_Bank(0);
    
    /* Setup Output Audio format. */
    HDMI_Write_Byte(REG_TX_INT_CLR0, 0xFF);
    HDMI_Write_Byte(REG_TX_INT_CLR1, 0xFF);
    intclr = (HDMI_Read_Byte(REG_TX_SYS_STATUS)) | B_CLR_AUD_CTS | B_INTACTDONE;
    HDMI_Write_Byte(REG_TX_SYS_STATUS, intclr); // clear interrupt.
    intclr &= ~(B_INTACTDONE);
    HDMI_Write_Byte(REG_TX_SYS_STATUS, intclr); // INTACTDONE reset to zero.

    /* Audio control */
    uint32_t n = 6144L;
    HDMI_Switch_TX_Bank(1);
    HDMI_Write_Byte(REGPktAudN0, (uint8_t)((n) & 0xFF));
    HDMI_Write_Byte(REGPktAudN1, (uint8_t)((n>>8) & 0xFF));
    HDMI_Write_Byte(REGPktAudN2, (uint8_t)((n>>16) & 0x0F));
    HDMI_Switch_TX_Bank(0);
    HDMI_Write_Byte(0xc4, 0xfe);
    HDMI_OrREG_TX_Byte(REG_TX_PKT_SINGLE_CTRL, (1<<4) | (1<<5));
}

#ifdef DEBUG_IT6263

/*******************************************************************************
* Function Name: Cy_IT6263_EnableDebugIO
****************************************************************************//**
*
* \brief
* Enable the debug IOs I2S0, I2S1, I2S2 and I2S3 for debugging.
*
* \param none
*
* \return none
*
*******************************************************************************/
void Cy_IT6263_EnableDebugIO(void)
{
    uint8_t ucData;
    
    HDMI_Switch_TX_Bank(0);
    
    /* Enable the debug IO */
    ucData = LVDS_Read_Byte(0x0B);
    LVDS_Write_Byte(0x0B, ucData|0x40);
    ucData = LVDS_Read_Byte(0x0B);
    printf("\n\rDebug Enabled (%X)", ucData);
    
    ucData = HDMI_Read_Byte(0x09);
    ucData |= 0x01;
    ucData &= ~0x02;
    HDMI_Write_Byte(0x09, ucData);
    ucData = HDMI_Read_Byte(0x09);
    printf("\n\rInterrupt Mask (%X)\n\r", ucData);
}

/*******************************************************************************
* Function Name: Cy_IT6263_DumpLVDSReg
****************************************************************************//**
*
* \brief
* Dump the LVDS interface register for debugging.
*
* \param none
*
* \return none
*
*******************************************************************************/
void Cy_IT6263_DumpLVDSReg(void)
{
    uint16_t i, j;
    uint8_t ucData;
    
    printf("\n\r        -----------------------------------------------------\r");
    printf("\n        - LVDS Register Logs\r");
    printf("\n        -----------------------------------------------------\r");
    printf("\n\r        ");

    for( j=0; j<16; j++)
    {
        if(j < 0x10)
        {
            printf("0%X ", j);
        }
        else
        {
            printf("%X ", j);
        }
        if((j == 3) || (j==7) || (j==11))
        {
            printf("  ");
        }
    }
    printf("\n\r        -----------------------------------------------------\n");

    HDMI_Switch_TX_Bank(0);

    for(i=0; i<0x100; i+=16)
    {
        if(i<0x10)
        {
            printf("\n\r[ 0%X ]  ", i);
        }
        else 
        {
            printf("\n\r[ %X ]  ", i);
        }
        for( j=0; j<16; j++)
        {
            ucData = LVDS_Read_Byte(i+j);
            if(ucData < 0x10) 
            {
                printf("0%X ", (uint16_t)ucData);
            }
            else 
            {
                printf("%X ", (uint16_t)ucData);
            }
            if((j==3) || (j==7) || (j==11))
            {
                printf("  ");
            }
        }
        if((i % 0x40) == 0x30)
        {
            printf("\n\r        -----------------------------------------------------\n");
        }
    }
}

/*******************************************************************************
* Function Name: Cy_IT6263_DumpCatHDMITXReg
****************************************************************************//**
*
* \brief
* Dump the HDMI interface register for debugging.
*
* \param none
*
* \return none
*
*******************************************************************************/
void Cy_IT6263_DumpCatHDMITXReg(void)
{
    uint16_t i, j;
    uint8_t ucData;

    printf("\n\r        -----------------------------------------------------\r");
    printf("\n        - HDMI Register Logs\r");
    printf("\n        -----------------------------------------------------\r");
    printf("\n\r        ");
    for(j=0; j<16; j++)
    {
        if(j < 0x10)
        {
            printf("0%X ", j);
        }
        else
        {
            printf("%X ", j);
        }
        if((j==3) || (j==7) || (j==11))
        {
            printf("  ");
        }
    }
    printf("\n\r        -----------------------------------------------------\n");

    HDMI_Switch_TX_Bank(0);

    for(i=0; i<0x100; i+=16)
    {
        if(i<0x10) 
        {
            printf("\n\r[ 0%X ]  ", i);
        }
        else 
        {
            printf("\n\r[ %X ]  ", i);
        }
        for(j=0; j<16; j++)
        {
            ucData = HDMI_Read_Byte((i+j) & 0xFF);
            if(ucData < 0x10)
            {
                printf("0%X ", (uint16_t)ucData);
            }
            else 
            {
                printf("%X ", (uint16_t)ucData);
            }
            if((j==3) || (j==7) || (j==11))
            {
                printf("  ");
            }
        }
        if((i % 0x40) == 0x30)
        {
            printf("\n\r        -----------------------------------------------------\n");
        }
    }
    HDMI_Switch_TX_Bank(1);
    for(i = 0x00; i < 0x100 ; i+=16 )
    {
        if(i < 0x10)
        {
            printf("\n\r[10%X ]  ", i);
        }
        else 
        {
            printf("\n\r[1%X ]  ", i);
        }
        for(j=0; j<16; j++)
        {
            ucData = HDMI_Read_Byte((i+j) & 0xFF);
            if(ucData < 0x10)
            {
                printf("0%X ", (uint16_t)ucData);
            }
            else 
            {
                printf("%X ", (uint16_t)ucData);
            }
            if((j==3) || (j==7) || (j==11))
            {
                printf("  ");
            }
        }
        if((i % 0x40) == 0x30)
        {
            printf("\n\r        -----------------------------------------------------\n");
        }
    }
    HDMI_Switch_TX_Bank(0);
}

#endif  /* DEBUG_IT6263 */

#endif  /* CY_327BGA_EVKLITE_rev_a */

/******************************************************************************/
/* [] END OF FILE */
/******************************************************************************/

