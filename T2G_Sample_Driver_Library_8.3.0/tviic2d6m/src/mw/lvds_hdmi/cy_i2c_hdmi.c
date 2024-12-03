/***************************************************************************//**
* \file cy_i2c_hdmi.c
* \version 1.0
*
* \brief
* Provides an API definition of the LVDS to HDMI transmission i2c interface.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "cy_project.h"
#include "cy_device_headers.h"
#include "cy_i2c_hdmi.h"

/* Only applicable for the lite kit */
#ifdef CY_327BGA_EVKLITE_rev_a

#include "cy_it6263_config.h"

/* I2C port configuration macro */
static cy_stc_gpio_pin_config_t hdmi_i2c_port_pin_cfg =
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

/* I2C irq configuration macro */
static cy_stc_sysint_irq_t hdmi_i2c_irq_cfg =
{
    .sysIntSrc  = CY_FPD_HDMI_I2C_IRQN,
    .intIdx     = CPUIntIdx2_IRQn,
    .isEnabled  = true,
};

/* I2C master configuration macro */
static cy_stc_scb_i2c_config_t hdmi_i2c_stc_config =
{
    .i2cMode             = CY_SCB_I2C_MASTER,
    .useRxFifo           = true,
    .useTxFifo           = true,
    .acceptAddrInFifo    = false,
    .ackGeneralAddr      = false,
    .enableWakeFromSleep = false
};

/* I2C master configuration structure */
static cy_stc_scb_i2c_master_xfer_config_t hdmi_i2c_stc_master_config =
{
    .buffer       = 0,
    .bufferSize   = 0,
    .xferPending  = false
};


/* Sensor interface I2C contex */
static cy_stc_scb_i2c_context_t hdmi_i2c_stc_context;


/* Image Sensor local function definition */
static void Cy_IT6263_I2C_IntrISR (void);
static void Cy_IT6263_I2C_SetPeripheFracDiv24_5(uint64_t targetFreq, uint64_t sourceFreq, uint8_t divNum);
static void Cy_IT6263_I2C_MasterEvent(uint32_t locEvents);


/*******************************************************************************
* Function Name: Cy_IT6263_I2C_IntrISR
****************************************************************************//**
*
* \brief
* LVDS to HDMI transceiver i2c interrupt callback.
*
* \param  none
*
* \return none
*
*******************************************************************************/
static void Cy_IT6263_I2C_IntrISR(void)
{
    /* I2C interrupt handler for High-Level APIs */
    Cy_SCB_I2C_Interrupt(CY_FPD_HDMI_I2C_TYPE, &hdmi_i2c_stc_context);
}

/*******************************************************************************
* Function Name: Cy_IT6263_I2C_SetPeripheFracDiv24_5
****************************************************************************//**
*
* \brief
* LVDS to HDMI transceiver i2c set up clock fractional divider.
*
* \param
* targetFreq : frequency for i2c operation
*
* \param
* sourceFreq : frequency for scb block
* 
* \param
* divNum : divider no used for the target frequency
*
* \return none
*
*******************************************************************************/
static void Cy_IT6263_I2C_SetPeripheFracDiv24_5(uint64_t targetFreq, uint64_t sourceFreq, uint8_t divNum)
{
    uint64_t temp = ((uint64_t)sourceFreq << 5ull);
    uint32_t divSetting;

    divSetting = (uint32_t)(temp / targetFreq);
    Cy_SysClk_PeriphSetFracDivider(Cy_SysClk_GetClockGroup(CY_FPD_HDMI_I2C_PCLK), 
                                   CY_SYSCLK_DIV_24_5_BIT, divNum, 
                                   (((divSetting >> 5u) & 0x00000FFF) - 1u), 
                                   (divSetting & 0x0000001F));
}

/*******************************************************************************
* Function Name: Cy_IT6263_I2C_MasterEvent
****************************************************************************//**
*
* \brief
* LVDS to HDMI transceiver i2c event callback.
*
* \param
* locEvents : i2c block generated event id
*
* \return none
*
*******************************************************************************/
static void Cy_IT6263_I2C_MasterEvent(uint32_t locEvents)
{
    switch (locEvents)
    {
    case CY_SCB_I2C_MASTER_WR_IN_FIFO_EVENT:
        break;
    case CY_SCB_I2C_MASTER_WR_CMPLT_EVENT:
        break;
    case CY_SCB_I2C_MASTER_RD_CMPLT_EVENT:
        break;
    case CY_SCB_I2C_MASTER_ERR_EVENT:
        break;
    default:
        break;
    }
}

/*******************************************************************************
* Function Name: Cy_IT6263_I2C_Init
****************************************************************************//**
*
* \brief
* Function to initialize i2c control path for LVDS to HDMI transceiver.
*
* \param  none
*
* \return
* cy_en_i2c_result_t : function result type
*
* \note
* SCB1 is fixed for the LVDS to HDMI transceiver control path.
* 
*******************************************************************************/
cy_en_i2c_result_t Cy_IT6263_I2C_Init(void)
{
    cy_en_i2c_result_t status = CY_I2C_SUCCESS;

    /* Clock Configuration */
    Cy_SysClk_HfClkEnable(CY_SYSCLK_HFCLK_2);

    Cy_SysClk_PeriphAssignDivider(CY_FPD_HDMI_I2C_PCLK, CY_SYSCLK_DIV_24_5_BIT, CY_HDMI_I2C_DIVIDER_NO);
    Cy_IT6263_I2C_SetPeripheFracDiv24_5(CY_HDMI_I2C_INCLK_TARGET_FREQ, CY_HDMI_I2C_SOURCE_CLK_FREQ, CY_HDMI_I2C_DIVIDER_NO);
    Cy_SysClk_PeriphEnableDivider(Cy_SysClk_GetClockGroup(CY_FPD_HDMI_I2C_PCLK), CY_SYSCLK_DIV_24_5_BIT, CY_HDMI_I2C_DIVIDER_NO);

    /* Port Configuration */
    hdmi_i2c_port_pin_cfg.driveMode = CY_GPIO_DM_OD_DRIVESLOW;
    hdmi_i2c_port_pin_cfg.hsiom     = CY_FPD_HDMI_I2C_SDA_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_FPD_HDMI_I2C_SDA_PORT, CY_FPD_HDMI_I2C_SDA_PIN, &hdmi_i2c_port_pin_cfg);

    hdmi_i2c_port_pin_cfg.driveMode = CY_GPIO_DM_OD_DRIVESLOW;
    hdmi_i2c_port_pin_cfg.hsiom     = CY_FPD_HDMI_I2C_SCL_PIN_MUX;
    Cy_GPIO_Pin_Init(CY_FPD_HDMI_I2C_SCL_PORT, CY_FPD_HDMI_I2C_SCL_PIN, &hdmi_i2c_port_pin_cfg);

    /* Interrrupt Configuration */
    Cy_SysInt_InitIRQ(&hdmi_i2c_irq_cfg);
    Cy_SysInt_SetSystemIrqVector(hdmi_i2c_irq_cfg.sysIntSrc, Cy_IT6263_I2C_IntrISR);
    NVIC_EnableIRQ(hdmi_i2c_irq_cfg.intIdx);
    
    /*  Initilize & Enable I2C  */
    Cy_SCB_I2C_Init(CY_FPD_HDMI_I2C_TYPE, &hdmi_i2c_stc_config, &hdmi_i2c_stc_context);
    Cy_SCB_I2C_SetDataRate(CY_FPD_HDMI_I2C_TYPE, CY_HDMI_I2C_DATARATE, CY_HDMI_I2C_INCLK_TARGET_FREQ);
    Cy_SCB_I2C_RegisterEventCallback(CY_FPD_HDMI_I2C_TYPE, (scb_i2c_handle_events_t)Cy_IT6263_I2C_MasterEvent, &hdmi_i2c_stc_context);
    Cy_SCB_I2C_Enable(CY_FPD_HDMI_I2C_TYPE);

    return status;
}

/*******************************************************************************
* Function Name: Cy_IT6263_I2C_Read
****************************************************************************//**
*
* \brief
* Function to read register in image sensor.
*
* \param
* deviceAddr : address of the target device
*
* \param
* regAddr : register address of image sensor
*
* \return
* uint8_t : read value
*
*******************************************************************************/
uint8_t Cy_IT6263_I2C_Read(uint8_t deviceAddr, uint8_t regAddr)
{
    cy_en_i2c_result_t status = CY_I2C_SUCCESS;
    uint8_t *regadd = (uint8_t*)&regAddr;
    uint8_t buf[2];
    
    /* retry command */
    for(uint8_t cnt=0; cnt<CY_IT6263_CMD_RETRY_COUNT ; cnt++)
    {
        hdmi_i2c_stc_master_config.slaveAddress = deviceAddr;
        hdmi_i2c_stc_master_config.buffer = regadd;
        hdmi_i2c_stc_master_config.bufferSize = 1;
        status = (cy_en_i2c_result_t)Cy_SCB_I2C_MasterWrite(CY_FPD_HDMI_I2C_TYPE, &hdmi_i2c_stc_master_config, &hdmi_i2c_stc_context);
        Cy_SysTick_DelayInUs(CY_IT6263_CMD_IN_BW_DELAY);
        
        hdmi_i2c_stc_master_config.buffer = buf;
        hdmi_i2c_stc_master_config.bufferSize = 1;
        status = (cy_en_i2c_result_t) Cy_SCB_I2C_MasterRead(CY_FPD_HDMI_I2C_TYPE, &hdmi_i2c_stc_master_config, &hdmi_i2c_stc_context);
        Cy_SysTick_DelayInUs(CY_IT6263_CMD_IN_BW_DELAY);
        
        if (status == CY_I2C_SUCCESS)
        {
            break;
        }
    }
    return buf[0];
}

/*******************************************************************************
* Function Name: Cy_IT6263_I2C_Write
****************************************************************************//**
*
* \brief
* Function to write register in LVDS to HDMI transceiver.
*
* \param
* deviceAddr : address of the target device
*
* \param
* regAddr : register address of LVDS to HDMI transceiver.
*
* \param
* value : data value
*
* \return
* cy_en_i2c_result_t : function result type
*
*******************************************************************************/
cy_en_i2c_result_t Cy_IT6263_I2C_Write(uint8_t deviceAddr, uint8_t regAddr, uint8_t value)
{
    cy_en_i2c_result_t status = CY_I2C_SUCCESS;
    uint8_t dataWrite[2];

    dataWrite[0] = regAddr;
    dataWrite[1] = value;
    
    /* retry command */
    for(uint8_t cnt=0; cnt<CY_IT6263_CMD_RETRY_COUNT ; cnt++)
    {
        hdmi_i2c_stc_master_config.slaveAddress = deviceAddr;
        hdmi_i2c_stc_master_config.buffer = dataWrite;
        hdmi_i2c_stc_master_config.bufferSize = 2;
        status = (cy_en_i2c_result_t)Cy_SCB_I2C_MasterWrite(CY_FPD_HDMI_I2C_TYPE, &hdmi_i2c_stc_master_config, &hdmi_i2c_stc_context);
        Cy_SysTick_DelayInUs(CY_IT6263_CMD_IN_BW_DELAY);
        
        if (status == CY_I2C_SUCCESS)
        {
            break;
        }
    }
    return status;
}

/*******************************************************************************
* Function Name: Cy_IT6263_I2C_ReadWrite
****************************************************************************//**
*
* \brief
* Function to read and then write the I2C configuration.
*
* \param
* deviceAddr : address of the target device
*
* \param
* regAddr : register address of LVDS to HDMI transceiver.
*
* \param
* value : data value
*
* \param
* op : operation on read data value
*
* \return 
* cy_en_i2c_result_t : function result type
*
*******************************************************************************/
cy_en_i2c_result_t Cy_IT6263_I2C_ReadWrite(uint8_t deviceAddr, uint8_t regAddr, uint8_t value, cy_en_i2c_op_type_t op)
{
    uint8_t readValue = 0;
    cy_en_i2c_result_t status = CY_I2C_SUCCESS;
    
    /* Read the register value */
    readValue = Cy_IT6263_I2C_Read(deviceAddr, regAddr);
    
    /* Update the changes */
    if (op == CY_I2C_OP_AND)
    {
        readValue &= value;
    }
    else
    {
        readValue |= value;
    }
    
    /* Write updated value */
    Cy_IT6263_I2C_Write(deviceAddr, regAddr, readValue);
      
    return status;
}

/*******************************************************************************
* Function Name: Cy_IT6263_I2C_WriteConfigurationSettings
****************************************************************************//**
*
* \brief
* Function to write LVDS to HDMI transceiver default configuration.
*
* \param
* deviceAddr : address of the target device
*
* \param
* cy_stc_It6263_reg_t : set of register needs to be configured
*
* \param
* configSettingsSize : size of the register array
*
* \return 
* cy_en_i2c_result_t : function result type
*
*******************************************************************************/
cy_en_i2c_result_t Cy_IT6263_I2C_WriteConfigurationSettings(uint8_t deviceAddr, cy_stc_It6263_reg_t * configSettings, uint8_t configSettingsSize)
{
    uint16_t regCounter = 0;
    cy_en_i2c_result_t status = CY_I2C_SUCCESS;
    uint8_t rwBuffer;

    for (regCounter = 0; ((regCounter < configSettingsSize) && (status == CY_I2C_SUCCESS)); regCounter++)
    {
        rwBuffer = configSettings[regCounter].regValue;
        status = Cy_IT6263_I2C_Write(deviceAddr, configSettings[regCounter].regAddr, rwBuffer); 
    }

    return status;
}

#endif  /* CY_327BGA_EVKLITE_rev_a */

/******************************************************************************/
/* [] END OF FILE */
/******************************************************************************/
