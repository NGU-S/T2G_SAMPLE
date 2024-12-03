/***************************************************************************//**
* \file main_cm7_0.c
*
* \version 1.0
*
* \brief Main example file for CM7_0
*
********************************************************************************
* \copyright
* Copyright 2016-2020, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

/*****************************************************************************
* Include files
*****************************************************************************/
#include <stdio.h>
#include "cy_project.h"
#include "cy_device_headers.h"


/*****************************************************************************
* Local pre-processor symbols/macros ('define')
*****************************************************************************/

//=============================================================================================
// The SMIF init step may cause issues and lock up the system if there are issues with the
// SMIF devices (e.g. not present on the connected board, or disabled by jumpers, etc.)
// With following defines you can quickly include/exclude SMIF init:
// Just set SMIF0_EXT_FREQ_MHZ/SMIF1_EXT_FREQ_MHZ to 0 or non-0
//=============================================================================================

#define DISP0_TYPE                      CY_GFXENV_DISP_TYPE_NONE
#define DISP1_TYPE                      CY_GFXENV_DISP_TYPE_800_480_60_FPD_VESA

#define SMIF0_EXT_FREQ_MHZ              0
#define SMIF1_EXT_FREQ_MHZ              0

#define USER_LED_PORT                   CY_USER_LED2_PORT
#define USER_LED_PIN                    CY_USER_LED2_PIN
#define USER_LED_PIN_MUX                CY_USER_LED2_PIN_MUX 

#define LED_TOGGLE_TIMER_ID             0
#define EXTMEM_TEST_TIMER_ID            1

#define EXTMEM_TEST_SIZE_KB             512
#define EXTMEM_FLASH_BASE               CY_GFXENV_FASTINIT_EXTMEM_FLASH_BASE
#define EXTMEM_RAM_BASE                 CY_GFXENV_FASTINIT_EXTMEM_RAM_BASE

#define EXTMEM_FLASH_ENABLED            (u8Smif0ExtClockMhz != 0)
#define EXTMEM_RAM_ENABLED              (u8Smif1ExtClockMhz != 0)

/*****************************************************************************
* Global variable definitions (declared in header file with 'extern')
*****************************************************************************/
cy_stc_gpio_pin_config_t user_led_port_pin_cfg =             
{                                                  
    .outVal = 0x00,                                
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,    
    .hsiom = USER_LED_PIN_MUX,                           
    .intEdge = 0,                                 
    .intMask = 0,                                  
    .vtrip = 0,                                    
    .slewRate = 0,                                 
    .driveSel = 0,                                 
    .vregEn = 0,                                   
    .ibufMode = 0,                                 
    .vtripSel = 0,                                 
    .vrefSel = 0,                                  
    .vohSel = 0,                                   
};


cy_stc_mpu_region_cfg_t astcMpuCfg[] =
{
    {.addr = EXTMEM_FLASH_BASE, .size = CY_MPU_SIZE_256MB, .permission = CY_MPU_ACCESS_P_FULL_ACCESS, .attribute = CY_MPU_ATTR_NORM_MEM_WB, .execute = CY_MPU_INST_ACCESS_EN, .srd = 0x00u, .enable = CY_MPU_ENABLE},
    {.addr = EXTMEM_RAM_BASE,   .size = CY_MPU_SIZE_256MB, .permission = CY_MPU_ACCESS_P_FULL_ACCESS, .attribute = CY_MPU_ATTR_NORM_MEM_WB, .execute = CY_MPU_INST_ACCESS_EN, .srd = 0x00u, .enable = CY_MPU_ENABLE},
};


// Create vars, so that frequencies can be easily changed by debugger without reflashing
uint8_t u8Smif0ExtClockMhz = SMIF0_EXT_FREQ_MHZ;
uint8_t u8Smif1ExtClockMhz = SMIF1_EXT_FREQ_MHZ;

/*****************************************************************************
* Local type definitions ('typedef')
*****************************************************************************/

/*****************************************************************************
* Local function prototypes ('static')
*****************************************************************************/
static void LedToggleCallback(void);
static void ButtonCallback(uint8_t u8ButtonId, cy_button_en_state_t enState);

/*****************************************************************************
* Local variable definitions ('static')
*****************************************************************************/


/*****************************************************************************
* Function implementation - global ('extern') and local ('static')
*****************************************************************************/


/*******************************************************************************
* Function Name: main
****************************************************************************//**
*
* \brief  Main function
*
* \return does not return
*
*******************************************************************************/
int main(void)
{
    __enable_irq();

    SystemInit();    

    // Ensure that the address space for the external memories is assigned the desired memory attributes
    Cy_MPU_Setup(astcMpuCfg, CY_GET_ARRAY_LEN(astcMpuCfg), CY_MPU_USE_DEFAULT_MAP_AS_BG, CY_MPU_DISABLED_DURING_FAULT_NMI);

    Cy_SMIF_SwitchBridge(SMIF0, false);

    Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led_port_pin_cfg);

    // Enable clocks/pin/buttons/semihosting/extmem
    cy_gfxenv_en_result_t result;
    result = Cy_GfxEnv_FastInit(u8Smif0ExtClockMhz, u8Smif1ExtClockMhz, ButtonCallback);
    CY_ASSERT(result == CY_GFXENV_SUCCESS);
    
    // Output test picture on Display #0 and #1
    result = Cy_GfxEnv_EnableTestImage(DISP0_TYPE, DISP1_TYPE);
    CY_ASSERT(result == CY_GFXENV_SUCCESS);
    
    printf("Hello World via UART Semihosting!\n");
    
    Cy_SwTmr_Wait(0, 500, NULL); // Wait 500 ms
    
    /* Start a periodic SW timer with 500ms interval */
    Cy_SwTmr_Start(LED_TOGGLE_TIMER_ID, 500, true, LedToggleCallback);

#ifdef CY_327BGA_EVKLITE_rev_a
    /* Initialize the HDMI transceiver */
    Cy_HDMI_Transceiver_Init(CY_HDMI_480i60_16x9);
#endif    

    for(;;)
    {
        /* Poll and operate on expired (non high-prio) SW timers */
        Cy_SwTmr_Main();

#ifdef CY_327BGA_EVKLITE_rev_a        
        /* Check for HDMI event */
        Cy_HDMI_Transceiver_DeviceLoop();
#endif        
    }
}


/*******************************************************************************
* Function Name: LedToggleCallback
****************************************************************************//**
*
* \brief  Toggles an LED
*
* \return none
*
*******************************************************************************/
static void LedToggleCallback(void)
{
    Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);    
}

/*******************************************************************************
* Function Name: ButtonCallback
****************************************************************************//**
*
* \brief  Handles button events
*
* \param  u8ButtonId : ID of the button that caused the callback
* \param  enState    : New state of the button
*
* \return none
*
*******************************************************************************/
static void ButtonCallback(uint8_t u8ButtonId, cy_button_en_state_t enState)
{
    // Return if button was released only
    if (enState == StateHigh)
    {
        return;
    }

    // Handle the pressed button
    switch (u8ButtonId)
    {
        case CY_GFXENV_BUTTON_ID_AB_CB:  
            break;
        case CY_GFXENV_BUTTON_ID_CEB:
            break;         
        case CY_GFXENV_BUTTON_ID_WAKE:
        case CY_GFXENV_BUTTON_ID_BB_1:
            break;
        case CY_GFXENV_BUTTON_ID_LEFT:
        case CY_GFXENV_BUTTON_ID_BB_2:
            break;
        case CY_GFXENV_BUTTON_ID_RIGHT:
        case CY_GFXENV_BUTTON_ID_BB_3:
            break;
        case CY_GFXENV_BUTTON_ID_UP:
        case CY_GFXENV_BUTTON_ID_BB_4:
            break;
        case CY_GFXENV_BUTTON_ID_DOWN:
        case CY_GFXENV_BUTTON_ID_BB_5:
            break;
        default:
            break;
    }
}

/* [] END OF FILE */
