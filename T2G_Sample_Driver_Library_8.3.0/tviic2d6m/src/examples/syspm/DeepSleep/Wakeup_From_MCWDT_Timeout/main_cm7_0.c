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

#include "cy_project.h"
#include "cy_device_headers.h"

#if (CY_USE_PSVP == 1)
    #define USER_LED1_PORT           CY_LED0_PORT
    #define USER_LED1_PIN            CY_LED0_PIN
    #define USER_LED1_PIN_MUX        CY_LED0_PIN_MUX

    #define USER_LED2_PORT           CY_LED1_PORT
    #define USER_LED2_PIN            CY_LED1_PIN
    #define USER_LED2_PIN_MUX        CY_LED1_PIN_MUX

    #define USER_LED3_PORT           CY_LED2_PORT
    #define USER_LED3_PIN            CY_LED2_PIN
    #define USER_LED3_PIN_MUX        CY_LED2_PIN_MUX
#else
    #define USER_LED1_PORT           CY_USER_LED1_PORT
    #define USER_LED1_PIN            CY_USER_LED1_PIN
    #define USER_LED1_PIN_MUX        CY_USER_LED1_PIN_MUX

    #define USER_LED2_PORT           CY_USER_LED2_PORT
    #define USER_LED2_PIN            CY_USER_LED2_PIN
    #define USER_LED2_PIN_MUX        CY_USER_LED2_PIN_MUX

    #define USER_LED3_PORT           CY_USER_LED3_PORT
    #define USER_LED3_PIN            CY_USER_LED3_PIN
    #define USER_LED3_PIN_MUX        CY_USER_LED3_PIN_MUX
#endif

#define CY_HF3_CLK_OUT_PORT     	GPIO_PRT1
#define CY_HF3_CLK_OUT_PIN      	(0ul)
#define CY_HF3_CLK_OUT_PIN_MUX  	P1_0_SRSS_EXT_CLK

cy_stc_gpio_pin_config_t user_led_port_pin_cfg =   
{                                                  
    .outVal = 0x00,                                
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,         
    .hsiom = USER_LED1_PIN_MUX ,                     
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

/******   Clock Output Utilities   ******/
cy_stc_gpio_pin_config_t clkOutPortConfig =
{
    .outVal    = 0ul,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom     = CY_HF3_CLK_OUT_PIN_MUX,
    .intEdge   = 0ul,
    .intMask   = 0ul,
    .vtrip     = 0ul,
    .slewRate  = 0ul,
    .driveSel  = 0ul,
};

void irqMCWDT1Handler(void)
{
    uint32_t masked;
    masked = Cy_MCWDT_GetInterruptStatusMasked(MCWDT1);

    if(MCWDT_INTR_MASKED_CTR0_INT_Msk & masked)
    {
        Cy_GPIO_Inv(USER_LED1_PORT, USER_LED1_PIN);
    }
    if(MCWDT_INTR_MASKED_CTR1_INT_Msk & masked)
    {
        Cy_GPIO_Inv(USER_LED3_PORT , USER_LED3_PIN );
    }
    if(MCWDT_INTR_MASKED_CTR2_INT_Msk & masked)
    {
        Cy_GPIO_Inv(USER_LED2_PORT , USER_LED2_PIN );
        Cy_GPIO_Inv(USER_LED3_PORT , USER_LED3_PIN );
    }
    
    Cy_MCWDT_ClearInterrupt(MCWDT1, masked);
}

int main(void)
{
    cy_stc_syspm_callback_params_t myParams; 
    cy_stc_syspm_callback_t myCallback = 
    {
        &Cy_SysClk_DeepSleepCallback,
        CY_SYSPM_DEEPSLEEP,
        CY_SYSPM_CHECK_FAIL,
        &myParams,
        NULL,
        NULL
    };
	
    SystemInit();

    // Example had been originally tested with "cache off", so ensure that caches are turned off (may have been enabled by new startup.c module)
    SCB_DisableICache(); // Disables and invalidates instruction cache
    SCB_DisableDCache(); // Disables, cleans and invalidates data cache

    cy_stc_mcwdt_config_t mcwdtConfig = {0};

    __enable_irq(); /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_GPIO_Pin_Init(USER_LED1_PORT, USER_LED1_PIN, &user_led_port_pin_cfg);
    
    user_led_port_pin_cfg.hsiom = USER_LED2_PIN_MUX;
    Cy_GPIO_Pin_Init(USER_LED2_PORT, USER_LED2_PIN, &user_led_port_pin_cfg);

    user_led_port_pin_cfg.hsiom = USER_LED3_PIN_MUX;
    Cy_GPIO_Pin_Init(USER_LED3_PORT, USER_LED3_PIN, &user_led_port_pin_cfg);
    

    /*********************************************************************/
    /*****                   Interrupt setting                       *****/
    /*********************************************************************/
    {
        cy_stc_sysint_irq_t irq_cfg;
        irq_cfg = (cy_stc_sysint_irq_t){
            .sysIntSrc  = srss_interrupt_mcwdt_1_IRQn,
            .intIdx     = CPUIntIdx4_IRQn,
            .isEnabled  = true,
        };
        irq_cfg.sysIntSrc = srss_interrupt_mcwdt_1_IRQn;
        Cy_SysInt_InitIRQ(&irq_cfg);
        Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, irqMCWDT1Handler);
        NVIC_SetPriority(CPUIntIdx4_IRQn, 0);
        NVIC_ClearPendingIRQ(CPUIntIdx4_IRQn);
        NVIC_EnableIRQ(CPUIntIdx4_IRQn);
    }

    Cy_MCWDT_DeInit(MCWDT1);

    mcwdtConfig.c0LowerLimit     = 0;
    mcwdtConfig.c0UpperLimit     = 60000;
    mcwdtConfig.c0WarnLimit      = 13333;
    mcwdtConfig.c0LowerAction    = CY_MCWDT_ACTION_NONE;
    mcwdtConfig.c0UpperAction    = CY_MCWDT_ACTION_NONE;
    mcwdtConfig.c0WarnAction     = CY_MCWDT_WARN_ACTION_INT;
    mcwdtConfig.c0AutoService    = CY_MCWDT_ENABLE;
    mcwdtConfig.c0SleepDeepPause = CY_MCWDT_ENABLE;
    mcwdtConfig.c0DebugRun       = CY_MCWDT_ENABLE;
    mcwdtConfig.c1LowerLimit     = 0;
    mcwdtConfig.c1UpperLimit     = 60000;
    mcwdtConfig.c1WarnLimit      = 26666;
    mcwdtConfig.c1LowerAction    = CY_MCWDT_ACTION_NONE;
    mcwdtConfig.c1UpperAction    = CY_MCWDT_ACTION_NONE;
    mcwdtConfig.c1WarnAction     = CY_MCWDT_WARN_ACTION_INT;
    mcwdtConfig.c1AutoService    = CY_MCWDT_ENABLE;
    mcwdtConfig.c1SleepDeepPause = CY_MCWDT_ENABLE;
    mcwdtConfig.c1DebugRun       = CY_MCWDT_ENABLE;
    mcwdtConfig.c2ToggleBit      = CY_MCWDT_CNT2_MONITORED_BIT15;
    mcwdtConfig.c2Action         = CY_MCWDT_CNT2_ACTION_INT;
    mcwdtConfig.c2SleepDeepPause = CY_MCWDT_ENABLE;
    mcwdtConfig.c2DebugRun       = CY_MCWDT_ENABLE;
    Cy_MCWDT_Init(MCWDT1, &mcwdtConfig);

    Cy_MCWDT_Unlock(MCWDT1);
    Cy_MCWDT_SetInterruptMask(MCWDT1, CY_MCWDT_CTR_Msk);
    Cy_MCWDT_Enable(MCWDT1, 
                    CY_MCWDT_CTR_Msk,  // enable all counter
                    0u);
    Cy_MCWDT_Lock(MCWDT1);
	
	Cy_SysPm_RegisterCallback(&myCallback);
    
    Cy_SysPm_DeepSleep(CY_SYSPM_WAIT_FOR_INTERRUPT);     

    for(;;)
    {
      Cy_GPIO_Inv(USER_LED1_PORT, USER_LED1_PIN);
      Cy_SysTick_DelayInUs(1000000UL);
          
      Cy_SysPm_DeepSleep(CY_SYSPM_WAIT_FOR_INTERRUPT);
    
    }
}

/* [] END OF FILE */
