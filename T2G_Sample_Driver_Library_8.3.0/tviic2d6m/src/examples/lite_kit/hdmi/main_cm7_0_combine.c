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
#define DISP1_TYPE                      CY_GFXENV_DISP_TYPE_1280_720_60_FPD_VESA//CY_GFXENV_DISP_TYPE_1024_600_60_FPD_VESA//CY_GFXENV_DISP_TYPE_1280_720_60_FPD_VESA//CY_GFXENV_DISP_TYPE_640_480_60_FPD_VESA

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

#define USER_BUTTON_PORT                CY_USER_BUTTON_UP_PORT
#define USER_BUTTON_PIN                 CY_USER_BUTTON_UP_PIN
#define USER_BUTTON_PIN_MUX             CY_USER_BUTTON_UP_PIN_MUX
#define USER_BUTTON_IRQN                CY_USER_BUTTON_UP_IRQN

#define LEVEL_LOW_FX3                   0
#define LEVEL_HIGH_HDMI                 1

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

cy_stc_gpio_pin_config_t user_button_port_pin_cfg =
{
    .outVal    = 0ul,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom     = USER_BUTTON_PIN_MUX,
    .intEdge   = CY_GPIO_INTR_FALLING,
    .intMask   = 1ul,
    .vtrip     = 0ul,
    .slewRate  = 0ul,
    .driveSel  = 0ul,
};

/* Graphics Display configuration */
cy_gfxenv_stc_cfg_t stcGfxEnvCfg2 =
{
    .bInitSwTimer         = true,
    .bInitSemihosting     = false, //true
    .pstcInitPortPins     = &(cy_gfxenv_stc_init_portpins_t)
    {
        .bInitDisplay0Ttl       = false, // usually the FPD-Link is used on silicon
        .bInitDisplay1Ttl       = true,  // FPD-Link #1 is not available on PSVP or on silicon for this device
        .bInitCapture0Ttl       = false,
        .bInitSmif0             = false,  // might be overriden by function parameter u8Smif0ExtClockMhz
        .bInitSmif1             = false,  // might be overriden by function parameter u8Smif1ExtClockMhz
        .bInitBacklightDisp0    = false, // backlights are enabled by jumper setting on CY boards, would only be needed for PWM dimming
        .bInitBacklightDisp1    = false, // backlights are enabled by jumper setting on CY boards, would only be needed for PWM dimming
        .bInitBacklightFpdLink0 = false, // backlights are enabled by jumper setting on CY boards, would only be needed for PWM dimming
        .bInitBacklightFpdLink1 = false, // backlights are enabled by jumper setting on CY boards, would only be needed for PWM dimming
        .bInitButtonGpios       = false,
    },
    .pstcInitExtMem       = NULL,
    .pstcInitButtons      = NULL,
};


cy_stc_mpu_region_cfg_t astcMpuCfg[] =
{
    {.addr = EXTMEM_FLASH_BASE, .size = CY_MPU_SIZE_256MB, .permission = CY_MPU_ACCESS_P_FULL_ACCESS, .attribute = CY_MPU_ATTR_NORM_MEM_WB, .execute = CY_MPU_INST_ACCESS_EN, .srd = 0x00u, .enable = CY_MPU_ENABLE},
    {.addr = EXTMEM_RAM_BASE,   .size = CY_MPU_SIZE_256MB, .permission = CY_MPU_ACCESS_P_FULL_ACCESS, .attribute = CY_MPU_ATTR_NORM_MEM_WB, .execute = CY_MPU_INST_ACCESS_EN, .srd = 0x00u, .enable = CY_MPU_ENABLE},
};



/*****************************************************************************
* Local variable definitions ('static')
*****************************************************************************/

// Create vars, so that frequencies can be easily changed by debugger without reflashing
uint8_t u8Smif0ExtClockMhz = SMIF0_EXT_FREQ_MHZ;
uint8_t u8Smif1ExtClockMhz = SMIF1_EXT_FREQ_MHZ;
cy_gfxenv_en_disp_type_t display1Type = CY_GFXENV_DISP_TYPE_1280_720_60_FPD_VESA;

/* Creating GFX result variable which will store the result of GFX_Init */
cy_gfxenv_en_result_t result;


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

    /* Initialize IO */
    Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led_port_pin_cfg);
    Cy_GPIO_Pin_Init(USER_BUTTON_PORT, USER_BUTTON_PIN, &user_button_port_pin_cfg);
    
    /* Check for the interface */
    uint32_t curLevel = Cy_GPIO_Read(USER_BUTTON_PORT, USER_BUTTON_PIN);
    if (curLevel == LEVEL_HIGH_HDMI)
    {
        display1Type = CY_GFXENV_DISP_TYPE_1280_720_60_FPD_VESA;
        
        /* Initializing the GFX_ENV and saving the result of it in result variable */
        cy_gfxenv_en_result_t result;
        result = Cy_GfxEnv_FastInit(u8Smif0ExtClockMhz, u8Smif1ExtClockMhz, NULL);
        CY_ASSERT(result == CY_GFXENV_SUCCESS);
        
        /* Output test picture on Display #0 and #1 */
        result = Cy_GfxEnv_EnableTestImage(DISP0_TYPE, display1Type);
        CY_ASSERT(result == CY_GFXENV_SUCCESS);
        printf("Hello World via UART Semihosting!\n\r");
        
        /* Initialize the HDMI transceiver */
        Cy_HDMI_Transceiver_Init(CY_HDMI_720p60);
        
        for(;;)
        {
            /* Poll and operate on expired (non high-prio) SW timers */
            Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);
            
            /* Check for HDMI event for hotplug in */
            Cy_HDMI_Transceiver_DeviceLoop();
        }
    }
    else
    {
        display1Type = CY_GFXENV_DISP_TYPE_800_480_60_TTL;
        
        /* Initializing the GFX_ENV and saving the result of it in result variable */
        result = Cy_GfxEnv_Init(&stcGfxEnvCfg2);
        
        /* If GFX_Init fails then it will return false */
        if(result != CY_GFXENV_SUCCESS) 
            return false;
        
        /* Output test picture on Display #0 and #1 */
        result = Cy_GfxEnv_EnableTestImage(DISP0_TYPE, display1Type);

        /* If GFX_EnableTestImage fails then it will return false */
        if(result != CY_GFXENV_SUCCESS) 
            return false;
        
        for(;;)
        {
            // Wait 0.05 [s]
            Cy_SysTick_DelayInUs(50000);
            Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);
        }
    }
}

/* [] END OF FILE */
