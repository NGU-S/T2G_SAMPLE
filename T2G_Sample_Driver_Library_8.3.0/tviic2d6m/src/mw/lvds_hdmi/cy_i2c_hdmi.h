/***************************************************************************//**
* \file cy_i2c_hdmi.h
* \version 1.0
*
* \brief
* Provides an API declaration of the LVDS to HDMI transmission i2c interface.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

/**
* \defgroup group_mw_imgsensor Middleware MIPI Image Sensor (MW Image Sense)
* \{
* The MIPI_Sensor driver provides an API to configure the MIPI Image sensor.
* The MIPI has upto 4 Data lane and one differential Clock lane. About actual
* supported # or modules and channels, please refer to the technical reference
* manual (TRM) and device datasheet.
*
* \section group_mw_imgsensor_configuration Configuration Considerations
* Typical usage as is follows:
*  - Call Cy_Mipi_Image_Sensor_Init() to initialize MIPI Sensor module
*  - Call Cy_Mipi_Image_Sensor_Wakeup() to wakeup the sensor
*  - Call Cy_Mipi_Image_Sensor_Set_Resolution() to configure the resolution.
* After initialize sensor call, by default sensor will go in the Sleep mode.
* Note that before calling any other function, init() function should be called.
* 
* Init() will initiliaze the control path for Image Sensor and basic configuration
* for VGA at 60FPS. For control and config settings SCB7 is used, please do not 
* change this configuartion, because it need a level shifted signals.
* 
* The basic read and write mechanism explained below
*
*       Write Transaction
*       Device         Addr+W  | WriteRegister_high  | WriteRegister_Low  | WriteValue
*       Sensor               A                     A                    A             NA
*
*       Read Transaction
*       Device         Addr+W  | WriteRegister_high  | WriteRegister_Low  | Addr+R          | NA
*       Sensor               A                     A                    A         ReadValue             
*
* Refer to the technical reference manual (TRM) and the device datasheet.
*
* \defgroup group_mw_hdmi_macros Macro
* \defgroup group_mw_hdmi_functions Functions
* \defgroup group_mw_hdmi_enums Enumerated types
*/

#ifndef CY_I2C_HDMI_H_
#define CY_I2C_HDMI_H_

/* Only applicable for the lite kit */
#ifdef CY_327BGA_EVKLITE_rev_a

#include <stddef.h>
#include <stdbool.h>
#include "cy_device_headers.h"
#include "cy_it6263_config.h"


#if defined(__cplusplus)
extern "C" {
#endif

/**
* \addtogroup group_mw_i2c_hdmi_macros
* \{
*/

/* Value selection macro */
#define CY_IT6263_MAKEWORD(v1, v2)              ((v1<<8) | v2)
#define CY_IT6263_SWAP_U16(value)               (value = ((value>>8)&0x00FF) | ((value<<8)&0xFF00))

/* IT6263 Delay macros */
#define CY_IT6263_CMD_RETRY_COUNT               (3u)
#define CY_IT6263_CMD_IN_BW_DELAY               (5000u)
#define CY_IT6263_RESET_BOOT_DELAY              (80000u)
#define CY_IT6263_FLASH_FW_DELAY                (CY_IT6263_RESET_BOOT_DELAY*10)

/* I2C clock configuration macro */
#define CY_HDMI_I2C_DIVIDER_NO                  (1u)
#define CY_HDMI_I2C_SOURCE_CLK_FREQ             (80000000) // fixed
#define CY_HDMI_I2C_INCLK_TARGET_FREQ           (2000000)  // modifiable
#define CY_HDMI_I2C_DATARATE                    (100000)   // modifiable

/* I2C buffer size macro */  
#define CY_HDMI_I2C_WRITE_BUF_MAX               128u

/** \} group_mw_i2c_hdmi_macros */

/**
* \addtogroup group_mw_i2c_hdmi_enums
* \{
*/

/* Function return value types */
typedef enum
{
    CY_I2C_OP_AND    = 0x00u,      /**< AND operation on data */
    CY_I2C_OP_OR     = 0x01u,      /**< OR operation on data */
} cy_en_i2c_op_type_t;
  
/* Function return value types */
typedef enum
{
    CY_I2C_SUCCESS   = 0x00u,      /**< Returned successful */
    CY_I2C_ERROR     = 0x01u,      /**< General error */
    CY_I2C_BAD_PARAM = 0x02u,      /**< Bad parameter was passed */
} cy_en_i2c_result_t;


/** \} group_mw_i2c_hdmi_enums */


/**
* \addtogroup group_mw_i2c_hdmi_functions
* \{
*/

cy_en_i2c_result_t Cy_IT6263_I2C_Init(void);
uint8_t Cy_IT6263_I2C_Read(uint8_t deviceAddr, uint8_t regAddr);
cy_en_i2c_result_t Cy_IT6263_I2C_Write(uint8_t deviceAddr, uint8_t regAddr, uint8_t value);
cy_en_i2c_result_t Cy_IT6263_I2C_ReadWrite(uint8_t deviceAddr, uint8_t regAddr, uint8_t value, cy_en_i2c_op_type_t op);
cy_en_i2c_result_t Cy_IT6263_I2C_WriteConfigurationSettings(uint8_t deviceAddr, cy_stc_It6263_reg_t * configSettings, uint8_t configSettingsSize);

/** \} group_mw_i2c_hdmi_functions */


#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* CY_327BGA_EVKLITE_rev_a */

#endif  /* CY_I2C_HDMI_H_ */

/* [] END OF FILE */
