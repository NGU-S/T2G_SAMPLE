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

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include "cy_project.h" 
#include "cy_device_headers.h"


#if CY_USE_PSVP == 1
  #define USER_LED_PORT           CY_LED9_PORT
  #define USER_LED_PIN            CY_LED9_PIN
  #define USER_LED_PIN_MUX        CY_LED9_PIN_MUX
#else
  #define USER_LED_PORT           CY_CB_USER_LED2_PORT
  #define USER_LED_PIN            CY_CB_USER_LED2_PIN
  #define USER_LED_PIN_MUX        CY_CB_USER_LED2_PIN_MUX
#endif

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

cy_stc_gpio_pin_config_t sdhc_port_pin_cfg =             
{
    .outVal   = 0x00,
    .intEdge  = 0,
    .intMask  = 0,
    .vtrip    = 0,
    .slewRate = 0,
    .driveSel = 0,
    .vregEn   = 0,
    .ibufMode = 0,
    .vtripSel = 0,
    .vrefSel  = 0,
    .vohSel   = 0,
};

#define SECTORNUM  							(8)
#define TOTAL_SIZE 							(100*1024*1024)
#define SD_HOST_CLK_DIV_NUM   				(0U)
#define RETRY_WRITE_READ  					(8)
#define CY_SD_HOST_FUJE_TIMEOUT_MS          (1000U) /* The Fuje timeout for one block. */
#define CY_SD_HOST_RETRY_TIME               (1000U)  /* The number loops to make the timeout in msec. */
#define CY_SD_HOST_READ_TIMEOUT_MS          (100U)  /* The Read timeout for one block. */
#define CY_SD_HOST_WRITE_TIMEOUT_MS         (250U)  /* The Write timeout for one block. */
#define CY_SD_HOST_BUFFER_RDY_TIMEOUT_MS    (150U)  /* The Buffer read ready timeout. */

static uint8_t      u8RxBuff[CY_SD_HOST_BLOCK_SIZE*SECTORNUM];
static uint8_t      u8TxBuff[CY_SD_HOST_BLOCK_SIZE*SECTORNUM];
static uint8_t      gu8StartCh      = 0x5;
static uint32_t     gu8StartSector  = 0;
uint32_t gcount = 0;
uint32_t dataRx = 0;
uint32_t dataTx = 0x12345678;
uint32_t    rca = 0;
cy_en_sd_host_card_type_t cardType = CY_SD_HOST_UNUSABLE;
cy_stc_sd_host_context_t SDIF0_context;
cy_en_sd_host_card_capacity_t cardCapacity;
uint32_t scr[2];
uint32_t csd[4]; /* The Card-Specific Data register. */
uint32_t cardStatus = 0u;
uint32_t cid[4u];  /* The Device Indentification register. */
cy_en_sd_host_status_t         enRet           = CY_SD_HOST_SUCCESS;
bool           bSuccess        = true;

uint32_t test_temp = 0;

const cy_stc_sysint_irq_t irq_cfg =
{
    .sysIntSrc  = CY_SDHC_GENERAL_IRQN,
    .intIdx     = CPUIntIdx2_IRQn,
    .isEnabled = true
};

/* Implement ISR  */
void SD_Host_User_Isr(void)
{
    uint32_t normalStatus;
    uint32_t errorStatus;

    normalStatus = Cy_SD_Host_GetNormalInterruptStatus((stc_SDHC_t const *)CY_SDHC_TYPE);

    /* Check the Error event */
    if (0u < normalStatus)
    {
        /* Clear the normalStatus event */
        Cy_SD_Host_ClearNormalInterruptStatus((stc_SDHC_t *)CY_SDHC_TYPE, normalStatus);
    }

    errorStatus = Cy_SD_Host_GetErrorInterruptStatus((stc_SDHC_t const *)CY_SDHC_TYPE);

    /* Check the Error event */
    if (0u < errorStatus)
    {
        /* Clear the Error event */
        Cy_SD_Host_ClearErrorInterruptStatus((stc_SDHC_t *)CY_SDHC_TYPE, errorStatus);
    }
}

int main(void)
{
    cy_stc_sd_host_sd_card_config_t stcSdcardCfg;
    cy_stc_sd_host_write_read_config_t dataRead;
    cy_stc_sd_host_write_read_config_t dataWrite;
    cy_stc_sd_host_init_config_t   hostConfig      = { 0u };
    uint32_t retry   = CY_SD_HOST_RETRY_TIME;
	
    SystemInit();

    // Example had been originally tested with "cache off", so ensure that caches are turned off (may have been enabled by new startup.c module)
    SCB_DisableICache(); // Disables and invalidates instruction cache
    SCB_DisableDCache(); // Disables, cleans and invalidates data cache
    
    __enable_irq(); /* Enable global interrupts. */

    Cy_SysClk_HfClockSetDivider(CY_SYSCLK_HFCLK_6, CY_SYSCLK_HFCLK_DIVIDE_BY_2);
    Cy_SysClk_HfClkEnable(CY_SYSCLK_HFCLK_6);                   //CLK_HF6 enable   

    Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led_port_pin_cfg);
    
    Cy_SysInt_InitIRQ(&irq_cfg);
    /* Set the Interrupt Priority & Enable the Interrupt */
    NVIC_SetPriority(CPUIntIdx3_IRQn, 3u);
    NVIC_ClearPendingIRQ(CPUIntIdx3_IRQn);
    Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, SD_Host_User_Isr);
    
    NVIC_EnableIRQ(CPUIntIdx3_IRQn);
       
    /* Initialize the configuration */
    hostConfig.dmaType = CY_SD_HOST_DMA_ADMA2;
    hostConfig.enableLedControl = false;
    hostConfig.emmc = false;

    stcSdcardCfg.lowVoltageSignaling = false; // true;
    stcSdcardCfg.busWidth = CY_SD_HOST_BUS_WIDTH_4_BIT;
    stcSdcardCfg.cardType = &cardType;
    stcSdcardCfg.rca = &rca;
    stcSdcardCfg.cardCapacity = &cardCapacity;

    dataRead.data = (uint32_t*)u8RxBuff;            /**< The pointer to data. */
    dataRead.address = gu8StartSector;         /**< The address to write/read data on the card or eMMC. */
    dataRead.numberOfBlocks = 1u;  /**< The number of blocks to write/read. */
    dataRead.autoCommand = CY_SD_HOST_AUTO_CMD_NONE;     /**< Selects which auto commands are used if any. */
    dataRead.dataTimeout = 0xcu;     /**< The timeout value for the transfer. */
    dataRead.enReliableWrite = false; /**< For EMMC cards enable reliable write. */
    dataRead.enableDma = true;

    dataWrite.data = (uint32_t*)u8TxBuff;            /**< The pointer to data. */
    dataWrite.address = gu8StartSector;         /**< The address to write/read data on the card or eMMC. */
    dataWrite.numberOfBlocks = 1u;  /**< The number of blocks to write/read. */
    dataWrite.autoCommand = CY_SD_HOST_AUTO_CMD_NONE;     /**< Selects which auto commands are used if any. */
    dataWrite.dataTimeout = 0xcu;     /**< The timeout value for the transfer. */
    dataWrite.enReliableWrite = false; /**< For EMMC cards enable reliable write. */
    dataWrite.enableDma = true;

    (void)Cy_SD_Host_Enable((stc_SDHC_t *)CY_SDHC_TYPE);
    
    /**************************************/
    /* Port Setting for CY_SDHC_TYPE      */
    /**************************************/

	/* Connect SD Host CY_SDHC_TYPE function to pins */
    sdhc_port_pin_cfg.driveMode = CY_GPIO_DM_STRONG;
    sdhc_port_pin_cfg.hsiom = CY_SDHC_CARD_DETECT_N_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_SDHC_CARD_DETECT_N_PORT, CY_SDHC_CARD_DETECT_N_PIN, &sdhc_port_pin_cfg);
    sdhc_port_pin_cfg.hsiom = CY_SDHC_CARD_CMD_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_SDHC_CARD_CMD_PORT, CY_SDHC_CARD_CMD_PIN, &sdhc_port_pin_cfg);
    sdhc_port_pin_cfg.hsiom = CY_SDHC_CLK_CARD_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_SDHC_CLK_CARD_PORT, CY_SDHC_CLK_CARD_PIN, &sdhc_port_pin_cfg);
    sdhc_port_pin_cfg.hsiom = CY_SDHC_CARD_DAT_3TO00_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_SDHC_CARD_DAT_3TO00_PORT, CY_SDHC_CARD_DAT_3TO00_PIN, &sdhc_port_pin_cfg);
    sdhc_port_pin_cfg.hsiom = CY_SDHC_CARD_DAT_3TO01_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_SDHC_CARD_DAT_3TO01_PORT, CY_SDHC_CARD_DAT_3TO01_PIN, &sdhc_port_pin_cfg);
    sdhc_port_pin_cfg.hsiom = CY_SDHC_CARD_DAT_3TO02_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_SDHC_CARD_DAT_3TO02_PORT, CY_SDHC_CARD_DAT_3TO02_PIN, &sdhc_port_pin_cfg);
    sdhc_port_pin_cfg.hsiom = CY_SDHC_CARD_DAT_3TO03_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_SDHC_CARD_DAT_3TO03_PORT, CY_SDHC_CARD_DAT_3TO03_PIN, &sdhc_port_pin_cfg);
    
    while(1)
    {
      /* Configure SD Host to operate */
      enRet = Cy_SD_Host_Init((stc_SDHC_t *)CY_SDHC_TYPE, &hostConfig, &SDIF0_context);

      if (CY_SD_HOST_SUCCESS != enRet)
      {
          bSuccess = false;
      }

      enRet = Cy_SD_Host_InitCard((stc_SDHC_t *)CY_SDHC_TYPE, &stcSdcardCfg, &SDIF0_context);

      if (CY_SD_HOST_SUCCESS != enRet)
      {
          bSuccess = false;
      }

      if (CY_SD_HOST_SUCCESS == enRet)
      {
          break; // Initialization passed
      }
    }
    Cy_SysLib_Delay(1);
    Cy_SysTick_DelayInUs(50000);

    // Single block write test.
    memset(u8TxBuff, 0x21, sizeof(u8RxBuff));

    enRet = Cy_SD_Host_Write((stc_SDHC_t *)CY_SDHC_TYPE, &dataWrite, &SDIF0_context);

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

    enRet = CY_SD_HOST_ERROR;
    retry = RETRY_WRITE_READ;
    while (CY_SD_HOST_SUCCESS != enRet && (retry-- > 0u) )
    {
         enRet = Cy_SD_Host_PollTransferComplete((stc_SDHC_t *)CY_SDHC_TYPE);
    }

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

    retry = CY_SD_HOST_RETRY_TIME;

    while ((true == _FLD2BOOL(SDHC_CORE_PSTATE_REG_DAT_LINE_ACTIVE, CY_SDHC_TYPE->CORE.unPSTATE_REG.u32Register)) && (retry-- > 0u) )
    {
        Cy_SysLib_DelayUs(CY_SD_HOST_WRITE_TIMEOUT_MS);
    }

    if ( true == _FLD2BOOL(SDHC_CORE_PSTATE_REG_DAT_LINE_ACTIVE, CY_SDHC_TYPE->CORE.unPSTATE_REG.u32Register) )
    {
        enRet = CY_SD_HOST_ERROR_TIMEOUT;
    }

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

    // Single block read back & check.
    memset(u8RxBuff, 0x0, sizeof(u8RxBuff));

    enRet = Cy_SD_Host_Read((stc_SDHC_t *)CY_SDHC_TYPE, &dataRead, &SDIF0_context);

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }

    enRet = CY_SD_HOST_ERROR;
    retry = RETRY_WRITE_READ;
    while (CY_SD_HOST_SUCCESS != enRet && (retry-- > 0u) )
    {
         enRet = Cy_SD_Host_PollTransferComplete((stc_SDHC_t *)CY_SDHC_TYPE);
    }

    if (CY_SD_HOST_SUCCESS != enRet)
    {
        bSuccess = false;
    }
    else
    {
        //check value
        if (memcmp(u8RxBuff, u8TxBuff, CY_SD_HOST_BLOCK_SIZE))
        {
            bSuccess = false;
        }
        else
        {
            bSuccess = true;
        }
    }

    Cy_SD_Host_DisableCardVoltage((stc_SDHC_t *)CY_SDHC_TYPE);
    
    for(;;)
    {
        if(bSuccess == true)
        {
            Cy_SysTick_DelayInUs(50000);
            Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);
        }
    }
}
