/***************************************************************************//**
* \file main_cm4.c
*
* \version 1.0
*
* \brief Main example file for CM4
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

#define USER_LED1_PORT       CY_BSP_USER_LED2_PORT
#define USER_LED1_PIN        CY_BSP_USER_LED2_PIN
#define USER_LED1_PIN_MUX    CY_BSP_USER_LED2_PIN_MUX

#define USER_BUTTON1_PORT    CY_BSP_USER_BUTTON1_PORT
#define USER_BUTTON1_PIN     CY_BSP_USER_BUTTON1_PIN
#define USER_BUTTON1_PIN_MUX CY_BSP_USER_BUTTON1_PIN_MUX
#define USER_BUTTON1_IRQ     CY_BSP_USER_BUTTON1_IRQN


const cy_stc_gpio_pin_config_t user_led1_port_pin_cfg =
{
    .outVal    = 0u,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom     = USER_LED1_PIN_MUX,
    .intEdge   = 0u,
    .intMask   = 0u,
    .vtrip     = 0u,
    .slewRate  = 0u,
    .driveSel  = 0u,
};

const cy_stc_gpio_pin_config_t user_button1_port_pin_cfg = 
{
    .outVal    = 0u,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom     = USER_BUTTON1_PIN_MUX,
    .intEdge   = CY_GPIO_INTR_FALLING,
    .intMask   = 1u,
    .vtrip     = 0u,
    .slewRate  = 0u,
    .driveSel  = 0u,
};

cy_stc_sysint_irq_t irq_cfg =
{
    .sysIntSrc  = USER_BUTTON1_IRQ,
    .intIdx     = CPUIntIdx2_IRQn,
    .isEnabled  = true,
};

void ButtonIntHandler(void)
{
    uint32_t intStatus;

    /* If falling edge detected */
    intStatus = Cy_GPIO_GetInterruptStatusMasked(USER_BUTTON1_PORT, USER_BUTTON1_PIN);
    if (intStatus != 0ul)
    {
        Cy_GPIO_ClearInterrupt(USER_BUTTON1_PORT, USER_BUTTON1_PIN);
        /* Toggle LED */
        Cy_GPIO_Inv(USER_LED1_PORT, USER_LED1_PIN);
    }
}

/*
 * This is an example for GPIO edge detection interrupt.
 * This example uses 2 LED ports and 2 button ports on the base board.
 * Settings are:
 */
int main(void)
{
    SystemInit();

    __enable_irq(); /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_GPIO_Pin_Init(USER_LED1_PORT, USER_LED1_PIN, &user_led1_port_pin_cfg);
    Cy_GPIO_Pin_Init(USER_BUTTON1_PORT, USER_BUTTON1_PIN, &user_button1_port_pin_cfg);

    /* Setup GPIO for SW2 interrupt */
    Cy_SysInt_InitIRQ(&irq_cfg);
    Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, ButtonIntHandler);
    
    NVIC_SetPriority(irq_cfg.intIdx, 3ul);
    NVIC_EnableIRQ(irq_cfg.intIdx);

    for(;;)
    {
        Cy_SysPm_Sleep(CY_SYSPM_WAIT_FOR_INTERRUPT);
    }
}


/* [] END OF FILE */
