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

/* Include default crypto configuration.
 * You can use other configuration instead follows.
 */
#include "crypto/cy_crypto_config.h"

/* For CRYPTO client that can run on the both CPUs */
cy_stc_crypto_context_t        cryptoCtx;

/***********************************************************************************************************************
 * PRNG
 ***********************************************************************************************************************/
volatile uint32_t result[2][16];
void Run_PRNG(void)
{
    cy_stc_crypto_context_prng_t cryptoPrngContext;

    /* At first init PRNG */
    Cy_Crypto_Prng_Init
    (
        &cryptoCtx,
        &cryptoPrngContext,
        0xd8959bc9,
        0x2bb911f8,
        0x060c31b7
    );
    /* Wait for completion */
    Cy_Crypto_Sync(true, &cryptoCtx);

    /* Then generate psued random number */
    for (uint32_t i = 0; i < sizeof(result[0]) / sizeof(result[0][0]); i++)
    {
        Cy_Crypto_Prng_Generate
        (
            &cryptoCtx,
            &cryptoPrngContext,
            0xFFFFFFFu,
            (uint32_t*)&result[0][i]
        );
        /* Wait for completion */
        Cy_Crypto_Sync(true, &cryptoCtx);
    }

    /* Then generate psued random number with saturation. Maximum number is 0xFF */
    for (uint32_t i = 0; i < sizeof(result[1]) / sizeof(result[1][0]); i++)
    {
        Cy_Crypto_Prng_Generate
        (
            &cryptoCtx,
            &cryptoPrngContext,
            0xFFu,
            (uint32_t*)&result[1][i]
        );
        /* Wait for completion */
        Cy_Crypto_Sync(true, &cryptoCtx);
    }

    /* You can get the result from result array */
}

/***********************************************************************************************************************
 * main function
 ***********************************************************************************************************************/
int main(void)
{
    SystemInit();

    // Example had been originally tested with "cache off", so ensure that caches are turned off (may have been enabled by new startup.c module)
    SCB_DisableICache(); // Disables and invalidates instruction cache
    SCB_DisableDCache(); // Disables, cleans and invalidates data cache

    __enable_irq(); /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    /* Initialize and enable CRYPTO */
    {
        cy_en_crypto_status_t status;
        do
        {
            status = Cy_Crypto_Init(&cryptoConfig, &cryptoCtx);
        } while(status != CY_CRYPTO_SUCCESS);
        Cy_Crypto_Enable(&cryptoCtx);
    }

    /* Run PRNG */
    Run_PRNG();

    for(;;)
    {
    }
}



/* [] END OF FILE */
