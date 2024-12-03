/***************************************************************************//**
* \file main_cm7_0.c
*
* \brief
* Main file for CM7 #0
*
********************************************************************************
* \copyright
* Copyright 2016-2019, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "cy_project.h"
#include "cy_device_headers.h"

#if (CY_USE_PSVP == 1)
    #define USER_LED_PORT           CY_LED8_PORT
    #define USER_LED_PIN            CY_LED8_PIN
    #define USER_LED_PIN_MUX        CY_LED8_PIN_MUX
#else
    #define USER_LED_PORT           CY_USER_LED2_PORT
    #define USER_LED_PIN            CY_USER_LED2_PIN
    #define USER_LED_PIN_MUX        CY_USER_LED2_PIN_MUX 
#endif


/* GFX display related macros definition */
#define DISP0_TYPE                      CY_GFXENV_DISP_TYPE_NONE
#define DISP1_TYPE                      CY_GFXENV_DISP_TYPE_800_480_60_TTL


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

/* Creating GFX result variable which will store the result of GFX_Init */
cy_gfxenv_en_result_t result;

int main(void)
{
    __enable_irq();
	
    SystemInit();

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led_port_pin_cfg);

    /* Initializing the GFX_ENV and saving the result of it in result variable */
    result = Cy_GfxEnv_Init(&stcGfxEnvCfg2);

    /* If GFX_Init fails then it will return false */
    if(result != CY_GFXENV_SUCCESS) 
        return false;

    /* Output test picture on Display #0 and #1 */
    result = Cy_GfxEnv_EnableTestImage(DISP0_TYPE, DISP1_TYPE);

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



/* [] END OF FILE */
