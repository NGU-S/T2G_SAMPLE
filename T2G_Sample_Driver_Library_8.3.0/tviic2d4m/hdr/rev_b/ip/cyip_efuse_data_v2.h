/***************************************************************************//**
* \file cyip_efuse_data_v2.h
*
* \brief
* EFUSE_DATA IP definitions
*
* \note
* Generator version: 1.6.7822.24107
*
********************************************************************************
* \copyright
* Copyright 2016-2021, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef _CYIP_EFUSE_DATA_V2_H_
#define _CYIP_EFUSE_DATA_V2_H_

#include "cyip_headers.h"

/**
  * \brief Secure 128 bits HASH word 0 that is used for authentication in SECURE protection state. (SECURE_HASH_WORD0)
  */
typedef struct {
    uint8_t HASH_WORD0[32];
} cy_stc_secure_hash_word0_t;

/**
  * \brief Secure 128 bits HASH word 1 that is used for authentication in SECURE protection state. (SECURE_HASH_WORD1)
  */
typedef struct {
    uint8_t HASH_WORD1[32];
} cy_stc_secure_hash_word1_t;

/**
  * \brief Secure 128 bits HASH word 2 that is used for authentication in SECURE protection state. (SECURE_HASH_WORD2)
  */
typedef struct {
    uint8_t HASH_WORD2[32];
} cy_stc_secure_hash_word2_t;

/**
  * \brief Secure 128 bits HASH word 3 that is used for authentication in SECURE protection state. (SECURE_HASH_WORD3)
  */
typedef struct {
    uint8_t HASH_WORD3[32];
} cy_stc_secure_hash_word3_t;

/**
  * \brief Access restrictions for SECURE protection state in SECURE lifecycle stage (SECURE_ACCESS_RESTRICT)
  */
typedef struct {
    uint8_t AP_CTL_CM0_DISABLE[2];
    uint8_t AP_CTL_CMX_DISABLE[2];
    uint8_t AP_CTL_SYS_DISABLE[2];
    uint8_t SYS_AP_MPU_ENABLE;
    uint8_t DIRECT_EXECUTE_DISABLE;
    uint8_t FLASH_ALLOWED[3];
    uint8_t SRAM_ALLOWED[3];
    uint8_t WORK_FLASH_ALLOWED[2];
    uint8_t SFLASH_ALLOWED[2];
    uint8_t MMIO_ALLOWED[2];
    uint8_t SMIF_XIP_ENABLE;
    uint8_t RESEREVED[11];
} cy_stc_secure_access_restrict_t;

/**
  * \brief Access restrictions for DEAD protection state in SECURE lifecycle stage and number of zeros for Secure fuse group (SECURE_DEAD_ACCESS_RESTRICT_ZEROS)
  */
typedef struct {
    uint8_t AP_CTL_CM0_DISABLE[2];
    uint8_t AP_CTL_CMX_DISABLE[2];
    uint8_t AP_CTL_SYS_DISABLE[2];
    uint8_t SYS_AP_MPU_ENABLE;
    uint8_t DIRECT_EXECUTE_DISABLE;
    uint8_t FLASH_ALLOWED[3];
    uint8_t SRAM_ALLOWED[3];
    uint8_t WORK_FLASH_ALLOWED[2];
    uint8_t SFLASH_ALLOWED[2];
    uint8_t MMIO_ALLOWED[2];
    uint8_t SMIF_XIP_ENABLE;
    uint8_t RESERVED[3];
    uint8_t SECURE_GROUP_ZEROS[8];
} cy_stc_secure_dead_access_restrict_zeros_t;

/**
  * \brief Available EFUSE bits for customer usage.They can be programmed in NORMAL protection state via CMx/DAP and in SECURE protection state via CMx. (CUSTOMER_DATA)
  */
typedef struct {
    uint8_t DATA_BYTE[32];
} cy_stc_customer_data_t;


/**
  * \brief eFUSE memory (EFUSE_DATA)
  */
typedef struct {
    uint8_t RESERVED[352];
    cy_stc_secure_hash_word0_t SECURE_HASH_WORD0;
    cy_stc_secure_hash_word1_t SECURE_HASH_WORD1;
    cy_stc_secure_hash_word2_t SECURE_HASH_WORD2;
    cy_stc_secure_hash_word3_t SECURE_HASH_WORD3;
    cy_stc_secure_access_restrict_t SECURE_ACCESS_RESTRICT;
    cy_stc_secure_dead_access_restrict_zeros_t SECURE_DEAD_ACCESS_RESTRICT_ZEROS;
    uint8_t RESERVED1[288];
    cy_stc_customer_data_t CUSTOMER_DATA[6];
} cy_stc_efuse_data_t;


#endif /* _CYIP_EFUSE_DATA_V2_H_ */


/* [] END OF FILE */
