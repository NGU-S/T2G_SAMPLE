/***************************************************************************//**
* \file cyreg_smif.h
*
* \brief
* SMIF register definition header
*
* \note
* Generator version: 1.6.0.644
* Database revision: TVIIC2D4M_TO_A2
*
********************************************************************************
* \copyright
* Copyright 2016-2021, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef _CYREG_SMIF_H_
#define _CYREG_SMIF_H_

#include "cyip_smif_v3.h"

/**
  * \brief Cryptography registers (one set for each key) (SMIF_SMIF_CRYPTO0)
  */
#define CYREG_SMIF0_SMIF_CRYPTO0_CRYPTO_CMD ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_CMD_t*) 0x40420200UL)
#define CYREG_SMIF0_SMIF_CRYPTO0_CRYPTO_ADDR ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_ADDR_t*) 0x40420204UL)
#define CYREG_SMIF0_SMIF_CRYPTO0_CRYPTO_MASK ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_MASK_t*) 0x40420208UL)
#define CYREG_SMIF0_SMIF_CRYPTO0_CRYPTO_SUBREGION ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_SUBREGION_t*) 0x4042020CUL)
#define CYREG_SMIF0_SMIF_CRYPTO0_CRYPTO_INPUT0 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT0_t*) 0x40420220UL)
#define CYREG_SMIF0_SMIF_CRYPTO0_CRYPTO_INPUT1 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT1_t*) 0x40420224UL)
#define CYREG_SMIF0_SMIF_CRYPTO0_CRYPTO_INPUT2 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT2_t*) 0x40420228UL)
#define CYREG_SMIF0_SMIF_CRYPTO0_CRYPTO_INPUT3 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT3_t*) 0x4042022CUL)
#define CYREG_SMIF0_SMIF_CRYPTO0_CRYPTO_KEY0 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY0_t*) 0x40420240UL)
#define CYREG_SMIF0_SMIF_CRYPTO0_CRYPTO_KEY1 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY1_t*) 0x40420244UL)
#define CYREG_SMIF0_SMIF_CRYPTO0_CRYPTO_KEY2 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY2_t*) 0x40420248UL)
#define CYREG_SMIF0_SMIF_CRYPTO0_CRYPTO_KEY3 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY3_t*) 0x4042024CUL)
#define CYREG_SMIF0_SMIF_CRYPTO0_CRYPTO_OUTPUT0 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT0_t*) 0x40420260UL)
#define CYREG_SMIF0_SMIF_CRYPTO0_CRYPTO_OUTPUT1 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT1_t*) 0x40420264UL)
#define CYREG_SMIF0_SMIF_CRYPTO0_CRYPTO_OUTPUT2 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT2_t*) 0x40420268UL)
#define CYREG_SMIF0_SMIF_CRYPTO0_CRYPTO_OUTPUT3 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT3_t*) 0x4042026CUL)

/**
  * \brief Cryptography registers (one set for each key) (SMIF_SMIF_CRYPTO1)
  */
#define CYREG_SMIF0_SMIF_CRYPTO1_CRYPTO_CMD ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_CMD_t*) 0x40420280UL)
#define CYREG_SMIF0_SMIF_CRYPTO1_CRYPTO_ADDR ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_ADDR_t*) 0x40420284UL)
#define CYREG_SMIF0_SMIF_CRYPTO1_CRYPTO_MASK ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_MASK_t*) 0x40420288UL)
#define CYREG_SMIF0_SMIF_CRYPTO1_CRYPTO_SUBREGION ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_SUBREGION_t*) 0x4042028CUL)
#define CYREG_SMIF0_SMIF_CRYPTO1_CRYPTO_INPUT0 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT0_t*) 0x404202A0UL)
#define CYREG_SMIF0_SMIF_CRYPTO1_CRYPTO_INPUT1 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT1_t*) 0x404202A4UL)
#define CYREG_SMIF0_SMIF_CRYPTO1_CRYPTO_INPUT2 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT2_t*) 0x404202A8UL)
#define CYREG_SMIF0_SMIF_CRYPTO1_CRYPTO_INPUT3 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT3_t*) 0x404202ACUL)
#define CYREG_SMIF0_SMIF_CRYPTO1_CRYPTO_KEY0 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY0_t*) 0x404202C0UL)
#define CYREG_SMIF0_SMIF_CRYPTO1_CRYPTO_KEY1 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY1_t*) 0x404202C4UL)
#define CYREG_SMIF0_SMIF_CRYPTO1_CRYPTO_KEY2 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY2_t*) 0x404202C8UL)
#define CYREG_SMIF0_SMIF_CRYPTO1_CRYPTO_KEY3 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY3_t*) 0x404202CCUL)
#define CYREG_SMIF0_SMIF_CRYPTO1_CRYPTO_OUTPUT0 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT0_t*) 0x404202E0UL)
#define CYREG_SMIF0_SMIF_CRYPTO1_CRYPTO_OUTPUT1 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT1_t*) 0x404202E4UL)
#define CYREG_SMIF0_SMIF_CRYPTO1_CRYPTO_OUTPUT2 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT2_t*) 0x404202E8UL)
#define CYREG_SMIF0_SMIF_CRYPTO1_CRYPTO_OUTPUT3 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT3_t*) 0x404202ECUL)

/**
  * \brief Cryptography registers (one set for each key) (SMIF_SMIF_CRYPTO2)
  */
#define CYREG_SMIF0_SMIF_CRYPTO2_CRYPTO_CMD ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_CMD_t*) 0x40420300UL)
#define CYREG_SMIF0_SMIF_CRYPTO2_CRYPTO_ADDR ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_ADDR_t*) 0x40420304UL)
#define CYREG_SMIF0_SMIF_CRYPTO2_CRYPTO_MASK ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_MASK_t*) 0x40420308UL)
#define CYREG_SMIF0_SMIF_CRYPTO2_CRYPTO_SUBREGION ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_SUBREGION_t*) 0x4042030CUL)
#define CYREG_SMIF0_SMIF_CRYPTO2_CRYPTO_INPUT0 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT0_t*) 0x40420320UL)
#define CYREG_SMIF0_SMIF_CRYPTO2_CRYPTO_INPUT1 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT1_t*) 0x40420324UL)
#define CYREG_SMIF0_SMIF_CRYPTO2_CRYPTO_INPUT2 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT2_t*) 0x40420328UL)
#define CYREG_SMIF0_SMIF_CRYPTO2_CRYPTO_INPUT3 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT3_t*) 0x4042032CUL)
#define CYREG_SMIF0_SMIF_CRYPTO2_CRYPTO_KEY0 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY0_t*) 0x40420340UL)
#define CYREG_SMIF0_SMIF_CRYPTO2_CRYPTO_KEY1 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY1_t*) 0x40420344UL)
#define CYREG_SMIF0_SMIF_CRYPTO2_CRYPTO_KEY2 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY2_t*) 0x40420348UL)
#define CYREG_SMIF0_SMIF_CRYPTO2_CRYPTO_KEY3 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY3_t*) 0x4042034CUL)
#define CYREG_SMIF0_SMIF_CRYPTO2_CRYPTO_OUTPUT0 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT0_t*) 0x40420360UL)
#define CYREG_SMIF0_SMIF_CRYPTO2_CRYPTO_OUTPUT1 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT1_t*) 0x40420364UL)
#define CYREG_SMIF0_SMIF_CRYPTO2_CRYPTO_OUTPUT2 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT2_t*) 0x40420368UL)
#define CYREG_SMIF0_SMIF_CRYPTO2_CRYPTO_OUTPUT3 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT3_t*) 0x4042036CUL)

/**
  * \brief Cryptography registers (one set for each key) (SMIF_SMIF_CRYPTO3)
  */
#define CYREG_SMIF0_SMIF_CRYPTO3_CRYPTO_CMD ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_CMD_t*) 0x40420380UL)
#define CYREG_SMIF0_SMIF_CRYPTO3_CRYPTO_ADDR ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_ADDR_t*) 0x40420384UL)
#define CYREG_SMIF0_SMIF_CRYPTO3_CRYPTO_MASK ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_MASK_t*) 0x40420388UL)
#define CYREG_SMIF0_SMIF_CRYPTO3_CRYPTO_SUBREGION ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_SUBREGION_t*) 0x4042038CUL)
#define CYREG_SMIF0_SMIF_CRYPTO3_CRYPTO_INPUT0 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT0_t*) 0x404203A0UL)
#define CYREG_SMIF0_SMIF_CRYPTO3_CRYPTO_INPUT1 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT1_t*) 0x404203A4UL)
#define CYREG_SMIF0_SMIF_CRYPTO3_CRYPTO_INPUT2 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT2_t*) 0x404203A8UL)
#define CYREG_SMIF0_SMIF_CRYPTO3_CRYPTO_INPUT3 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT3_t*) 0x404203ACUL)
#define CYREG_SMIF0_SMIF_CRYPTO3_CRYPTO_KEY0 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY0_t*) 0x404203C0UL)
#define CYREG_SMIF0_SMIF_CRYPTO3_CRYPTO_KEY1 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY1_t*) 0x404203C4UL)
#define CYREG_SMIF0_SMIF_CRYPTO3_CRYPTO_KEY2 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY2_t*) 0x404203C8UL)
#define CYREG_SMIF0_SMIF_CRYPTO3_CRYPTO_KEY3 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY3_t*) 0x404203CCUL)
#define CYREG_SMIF0_SMIF_CRYPTO3_CRYPTO_OUTPUT0 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT0_t*) 0x404203E0UL)
#define CYREG_SMIF0_SMIF_CRYPTO3_CRYPTO_OUTPUT1 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT1_t*) 0x404203E4UL)
#define CYREG_SMIF0_SMIF_CRYPTO3_CRYPTO_OUTPUT2 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT2_t*) 0x404203E8UL)
#define CYREG_SMIF0_SMIF_CRYPTO3_CRYPTO_OUTPUT3 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT3_t*) 0x404203ECUL)

/**
  * \brief Device (only used for XIP acceses) (SMIF_DEVICE0)
  */
#define CYREG_SMIF0_DEVICE0_CTL         ((volatile un_SMIF_DEVICE_CTL_t*) 0x40420800UL)
#define CYREG_SMIF0_DEVICE0_ADDR        ((volatile un_SMIF_DEVICE_ADDR_t*) 0x40420808UL)
#define CYREG_SMIF0_DEVICE0_MASK        ((volatile un_SMIF_DEVICE_MASK_t*) 0x4042080CUL)
#define CYREG_SMIF0_DEVICE0_ADDR_CTL    ((volatile un_SMIF_DEVICE_ADDR_CTL_t*) 0x40420820UL)
#define CYREG_SMIF0_DEVICE0_DELAY_TAP_SEL ((volatile un_SMIF_DEVICE_DELAY_TAP_SEL_t*) 0x4042082CUL)
#define CYREG_SMIF0_DEVICE0_RD_CMD_CTL  ((volatile un_SMIF_DEVICE_RD_CMD_CTL_t*) 0x40420840UL)
#define CYREG_SMIF0_DEVICE0_RD_ADDR_CTL ((volatile un_SMIF_DEVICE_RD_ADDR_CTL_t*) 0x40420844UL)
#define CYREG_SMIF0_DEVICE0_RD_MODE_CTL ((volatile un_SMIF_DEVICE_RD_MODE_CTL_t*) 0x40420848UL)
#define CYREG_SMIF0_DEVICE0_RD_DUMMY_CTL ((volatile un_SMIF_DEVICE_RD_DUMMY_CTL_t*) 0x4042084CUL)
#define CYREG_SMIF0_DEVICE0_RD_DATA_CTL ((volatile un_SMIF_DEVICE_RD_DATA_CTL_t*) 0x40420850UL)
#define CYREG_SMIF0_DEVICE0_RD_BOUND_CTL ((volatile un_SMIF_DEVICE_RD_BOUND_CTL_t*) 0x40420858UL)
#define CYREG_SMIF0_DEVICE0_WR_CMD_CTL  ((volatile un_SMIF_DEVICE_WR_CMD_CTL_t*) 0x40420860UL)
#define CYREG_SMIF0_DEVICE0_WR_ADDR_CTL ((volatile un_SMIF_DEVICE_WR_ADDR_CTL_t*) 0x40420864UL)
#define CYREG_SMIF0_DEVICE0_WR_MODE_CTL ((volatile un_SMIF_DEVICE_WR_MODE_CTL_t*) 0x40420868UL)
#define CYREG_SMIF0_DEVICE0_WR_DUMMY_CTL ((volatile un_SMIF_DEVICE_WR_DUMMY_CTL_t*) 0x4042086CUL)
#define CYREG_SMIF0_DEVICE0_WR_DATA_CTL ((volatile un_SMIF_DEVICE_WR_DATA_CTL_t*) 0x40420870UL)

/**
  * \brief Device (only used for XIP acceses) (SMIF_DEVICE1)
  */
#define CYREG_SMIF0_DEVICE1_CTL         ((volatile un_SMIF_DEVICE_CTL_t*) 0x40420880UL)
#define CYREG_SMIF0_DEVICE1_ADDR        ((volatile un_SMIF_DEVICE_ADDR_t*) 0x40420888UL)
#define CYREG_SMIF0_DEVICE1_MASK        ((volatile un_SMIF_DEVICE_MASK_t*) 0x4042088CUL)
#define CYREG_SMIF0_DEVICE1_ADDR_CTL    ((volatile un_SMIF_DEVICE_ADDR_CTL_t*) 0x404208A0UL)
#define CYREG_SMIF0_DEVICE1_DELAY_TAP_SEL ((volatile un_SMIF_DEVICE_DELAY_TAP_SEL_t*) 0x404208ACUL)
#define CYREG_SMIF0_DEVICE1_RD_CMD_CTL  ((volatile un_SMIF_DEVICE_RD_CMD_CTL_t*) 0x404208C0UL)
#define CYREG_SMIF0_DEVICE1_RD_ADDR_CTL ((volatile un_SMIF_DEVICE_RD_ADDR_CTL_t*) 0x404208C4UL)
#define CYREG_SMIF0_DEVICE1_RD_MODE_CTL ((volatile un_SMIF_DEVICE_RD_MODE_CTL_t*) 0x404208C8UL)
#define CYREG_SMIF0_DEVICE1_RD_DUMMY_CTL ((volatile un_SMIF_DEVICE_RD_DUMMY_CTL_t*) 0x404208CCUL)
#define CYREG_SMIF0_DEVICE1_RD_DATA_CTL ((volatile un_SMIF_DEVICE_RD_DATA_CTL_t*) 0x404208D0UL)
#define CYREG_SMIF0_DEVICE1_RD_BOUND_CTL ((volatile un_SMIF_DEVICE_RD_BOUND_CTL_t*) 0x404208D8UL)
#define CYREG_SMIF0_DEVICE1_WR_CMD_CTL  ((volatile un_SMIF_DEVICE_WR_CMD_CTL_t*) 0x404208E0UL)
#define CYREG_SMIF0_DEVICE1_WR_ADDR_CTL ((volatile un_SMIF_DEVICE_WR_ADDR_CTL_t*) 0x404208E4UL)
#define CYREG_SMIF0_DEVICE1_WR_MODE_CTL ((volatile un_SMIF_DEVICE_WR_MODE_CTL_t*) 0x404208E8UL)
#define CYREG_SMIF0_DEVICE1_WR_DUMMY_CTL ((volatile un_SMIF_DEVICE_WR_DUMMY_CTL_t*) 0x404208ECUL)
#define CYREG_SMIF0_DEVICE1_WR_DATA_CTL ((volatile un_SMIF_DEVICE_WR_DATA_CTL_t*) 0x404208F0UL)

/**
  * \brief Serial Memory Interface (SMIF0)
  */
#define CYREG_SMIF0_CTL                 ((volatile un_SMIF_CTL_t*) 0x40420000UL)
#define CYREG_SMIF0_STATUS              ((volatile un_SMIF_STATUS_t*) 0x40420004UL)
#define CYREG_SMIF0_INT_CLOCK_DELAY_TAP_SEL0 ((volatile un_SMIF_INT_CLOCK_DELAY_TAP_SEL0_t*) 0x40420010UL)
#define CYREG_SMIF0_INT_CLOCK_DELAY_TAP_SEL1 ((volatile un_SMIF_INT_CLOCK_DELAY_TAP_SEL1_t*) 0x40420014UL)
#define CYREG_SMIF0_DL_CTL              ((volatile un_SMIF_DL_CTL_t*) 0x40420018UL)
#define CYREG_SMIF0_DL_STATUS0          ((volatile un_SMIF_DL_STATUS0_t*) 0x40420020UL)
#define CYREG_SMIF0_DL_STATUS1          ((volatile un_SMIF_DL_STATUS1_t*) 0x40420024UL)
#define CYREG_SMIF0_TX_CMD_FIFO_STATUS  ((volatile un_SMIF_TX_CMD_FIFO_STATUS_t*) 0x40420044UL)
#define CYREG_SMIF0_TX_CMD_MMIO_FIFO_STATUS ((volatile un_SMIF_TX_CMD_MMIO_FIFO_STATUS_t*) 0x40420048UL)
#define CYREG_SMIF0_TX_CMD_MMIO_FIFO_WR ((volatile un_SMIF_TX_CMD_MMIO_FIFO_WR_t*) 0x40420050UL)
#define CYREG_SMIF0_TX_DATA_MMIO_FIFO_CTL ((volatile un_SMIF_TX_DATA_MMIO_FIFO_CTL_t*) 0x40420080UL)
#define CYREG_SMIF0_TX_DATA_FIFO_STATUS ((volatile un_SMIF_TX_DATA_FIFO_STATUS_t*) 0x40420084UL)
#define CYREG_SMIF0_TX_DATA_MMIO_FIFO_STATUS ((volatile un_SMIF_TX_DATA_MMIO_FIFO_STATUS_t*) 0x40420088UL)
#define CYREG_SMIF0_TX_DATA_MMIO_FIFO_WR1 ((volatile un_SMIF_TX_DATA_MMIO_FIFO_WR1_t*) 0x40420090UL)
#define CYREG_SMIF0_TX_DATA_MMIO_FIFO_WR2 ((volatile un_SMIF_TX_DATA_MMIO_FIFO_WR2_t*) 0x40420094UL)
#define CYREG_SMIF0_TX_DATA_MMIO_FIFO_WR4 ((volatile un_SMIF_TX_DATA_MMIO_FIFO_WR4_t*) 0x40420098UL)
#define CYREG_SMIF0_TX_DATA_MMIO_FIFO_WR1ODD ((volatile un_SMIF_TX_DATA_MMIO_FIFO_WR1ODD_t*) 0x4042009CUL)
#define CYREG_SMIF0_RX_DATA_MMIO_FIFO_CTL ((volatile un_SMIF_RX_DATA_MMIO_FIFO_CTL_t*) 0x404200C0UL)
#define CYREG_SMIF0_RX_DATA_MMIO_FIFO_STATUS ((volatile un_SMIF_RX_DATA_MMIO_FIFO_STATUS_t*) 0x404200C4UL)
#define CYREG_SMIF0_RX_DATA_FIFO_STATUS ((volatile un_SMIF_RX_DATA_FIFO_STATUS_t*) 0x404200C8UL)
#define CYREG_SMIF0_RX_DATA_MMIO_FIFO_RD1 ((volatile un_SMIF_RX_DATA_MMIO_FIFO_RD1_t*) 0x404200D0UL)
#define CYREG_SMIF0_RX_DATA_MMIO_FIFO_RD2 ((volatile un_SMIF_RX_DATA_MMIO_FIFO_RD2_t*) 0x404200D4UL)
#define CYREG_SMIF0_RX_DATA_MMIO_FIFO_RD4 ((volatile un_SMIF_RX_DATA_MMIO_FIFO_RD4_t*) 0x404200D8UL)
#define CYREG_SMIF0_RX_DATA_MMIO_FIFO_RD1_SILENT ((volatile un_SMIF_RX_DATA_MMIO_FIFO_RD1_SILENT_t*) 0x404200E0UL)
#define CYREG_SMIF0_SLOW_CA_CTL         ((volatile un_SMIF_SLOW_CA_CTL_t*) 0x40420100UL)
#define CYREG_SMIF0_SLOW_CA_CMD         ((volatile un_SMIF_SLOW_CA_CMD_t*) 0x40420108UL)
#define CYREG_SMIF0_INTR                ((volatile un_SMIF_INTR_t*) 0x404207C0UL)
#define CYREG_SMIF0_INTR_SET            ((volatile un_SMIF_INTR_SET_t*) 0x404207C4UL)
#define CYREG_SMIF0_INTR_MASK           ((volatile un_SMIF_INTR_MASK_t*) 0x404207C8UL)
#define CYREG_SMIF0_INTR_MASKED         ((volatile un_SMIF_INTR_MASKED_t*) 0x404207CCUL)

/**
  * \brief Cryptography registers (one set for each key) (SMIF_SMIF_CRYPTO0)
  */
#define CYREG_SMIF1_SMIF_CRYPTO0_CRYPTO_CMD ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_CMD_t*) 0x40430200UL)
#define CYREG_SMIF1_SMIF_CRYPTO0_CRYPTO_ADDR ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_ADDR_t*) 0x40430204UL)
#define CYREG_SMIF1_SMIF_CRYPTO0_CRYPTO_MASK ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_MASK_t*) 0x40430208UL)
#define CYREG_SMIF1_SMIF_CRYPTO0_CRYPTO_SUBREGION ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_SUBREGION_t*) 0x4043020CUL)
#define CYREG_SMIF1_SMIF_CRYPTO0_CRYPTO_INPUT0 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT0_t*) 0x40430220UL)
#define CYREG_SMIF1_SMIF_CRYPTO0_CRYPTO_INPUT1 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT1_t*) 0x40430224UL)
#define CYREG_SMIF1_SMIF_CRYPTO0_CRYPTO_INPUT2 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT2_t*) 0x40430228UL)
#define CYREG_SMIF1_SMIF_CRYPTO0_CRYPTO_INPUT3 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT3_t*) 0x4043022CUL)
#define CYREG_SMIF1_SMIF_CRYPTO0_CRYPTO_KEY0 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY0_t*) 0x40430240UL)
#define CYREG_SMIF1_SMIF_CRYPTO0_CRYPTO_KEY1 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY1_t*) 0x40430244UL)
#define CYREG_SMIF1_SMIF_CRYPTO0_CRYPTO_KEY2 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY2_t*) 0x40430248UL)
#define CYREG_SMIF1_SMIF_CRYPTO0_CRYPTO_KEY3 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY3_t*) 0x4043024CUL)
#define CYREG_SMIF1_SMIF_CRYPTO0_CRYPTO_OUTPUT0 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT0_t*) 0x40430260UL)
#define CYREG_SMIF1_SMIF_CRYPTO0_CRYPTO_OUTPUT1 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT1_t*) 0x40430264UL)
#define CYREG_SMIF1_SMIF_CRYPTO0_CRYPTO_OUTPUT2 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT2_t*) 0x40430268UL)
#define CYREG_SMIF1_SMIF_CRYPTO0_CRYPTO_OUTPUT3 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT3_t*) 0x4043026CUL)

/**
  * \brief Cryptography registers (one set for each key) (SMIF_SMIF_CRYPTO1)
  */
#define CYREG_SMIF1_SMIF_CRYPTO1_CRYPTO_CMD ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_CMD_t*) 0x40430280UL)
#define CYREG_SMIF1_SMIF_CRYPTO1_CRYPTO_ADDR ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_ADDR_t*) 0x40430284UL)
#define CYREG_SMIF1_SMIF_CRYPTO1_CRYPTO_MASK ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_MASK_t*) 0x40430288UL)
#define CYREG_SMIF1_SMIF_CRYPTO1_CRYPTO_SUBREGION ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_SUBREGION_t*) 0x4043028CUL)
#define CYREG_SMIF1_SMIF_CRYPTO1_CRYPTO_INPUT0 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT0_t*) 0x404302A0UL)
#define CYREG_SMIF1_SMIF_CRYPTO1_CRYPTO_INPUT1 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT1_t*) 0x404302A4UL)
#define CYREG_SMIF1_SMIF_CRYPTO1_CRYPTO_INPUT2 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT2_t*) 0x404302A8UL)
#define CYREG_SMIF1_SMIF_CRYPTO1_CRYPTO_INPUT3 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT3_t*) 0x404302ACUL)
#define CYREG_SMIF1_SMIF_CRYPTO1_CRYPTO_KEY0 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY0_t*) 0x404302C0UL)
#define CYREG_SMIF1_SMIF_CRYPTO1_CRYPTO_KEY1 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY1_t*) 0x404302C4UL)
#define CYREG_SMIF1_SMIF_CRYPTO1_CRYPTO_KEY2 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY2_t*) 0x404302C8UL)
#define CYREG_SMIF1_SMIF_CRYPTO1_CRYPTO_KEY3 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY3_t*) 0x404302CCUL)
#define CYREG_SMIF1_SMIF_CRYPTO1_CRYPTO_OUTPUT0 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT0_t*) 0x404302E0UL)
#define CYREG_SMIF1_SMIF_CRYPTO1_CRYPTO_OUTPUT1 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT1_t*) 0x404302E4UL)
#define CYREG_SMIF1_SMIF_CRYPTO1_CRYPTO_OUTPUT2 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT2_t*) 0x404302E8UL)
#define CYREG_SMIF1_SMIF_CRYPTO1_CRYPTO_OUTPUT3 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT3_t*) 0x404302ECUL)

/**
  * \brief Cryptography registers (one set for each key) (SMIF_SMIF_CRYPTO2)
  */
#define CYREG_SMIF1_SMIF_CRYPTO2_CRYPTO_CMD ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_CMD_t*) 0x40430300UL)
#define CYREG_SMIF1_SMIF_CRYPTO2_CRYPTO_ADDR ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_ADDR_t*) 0x40430304UL)
#define CYREG_SMIF1_SMIF_CRYPTO2_CRYPTO_MASK ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_MASK_t*) 0x40430308UL)
#define CYREG_SMIF1_SMIF_CRYPTO2_CRYPTO_SUBREGION ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_SUBREGION_t*) 0x4043030CUL)
#define CYREG_SMIF1_SMIF_CRYPTO2_CRYPTO_INPUT0 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT0_t*) 0x40430320UL)
#define CYREG_SMIF1_SMIF_CRYPTO2_CRYPTO_INPUT1 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT1_t*) 0x40430324UL)
#define CYREG_SMIF1_SMIF_CRYPTO2_CRYPTO_INPUT2 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT2_t*) 0x40430328UL)
#define CYREG_SMIF1_SMIF_CRYPTO2_CRYPTO_INPUT3 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT3_t*) 0x4043032CUL)
#define CYREG_SMIF1_SMIF_CRYPTO2_CRYPTO_KEY0 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY0_t*) 0x40430340UL)
#define CYREG_SMIF1_SMIF_CRYPTO2_CRYPTO_KEY1 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY1_t*) 0x40430344UL)
#define CYREG_SMIF1_SMIF_CRYPTO2_CRYPTO_KEY2 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY2_t*) 0x40430348UL)
#define CYREG_SMIF1_SMIF_CRYPTO2_CRYPTO_KEY3 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY3_t*) 0x4043034CUL)
#define CYREG_SMIF1_SMIF_CRYPTO2_CRYPTO_OUTPUT0 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT0_t*) 0x40430360UL)
#define CYREG_SMIF1_SMIF_CRYPTO2_CRYPTO_OUTPUT1 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT1_t*) 0x40430364UL)
#define CYREG_SMIF1_SMIF_CRYPTO2_CRYPTO_OUTPUT2 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT2_t*) 0x40430368UL)
#define CYREG_SMIF1_SMIF_CRYPTO2_CRYPTO_OUTPUT3 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT3_t*) 0x4043036CUL)

/**
  * \brief Cryptography registers (one set for each key) (SMIF_SMIF_CRYPTO3)
  */
#define CYREG_SMIF1_SMIF_CRYPTO3_CRYPTO_CMD ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_CMD_t*) 0x40430380UL)
#define CYREG_SMIF1_SMIF_CRYPTO3_CRYPTO_ADDR ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_ADDR_t*) 0x40430384UL)
#define CYREG_SMIF1_SMIF_CRYPTO3_CRYPTO_MASK ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_MASK_t*) 0x40430388UL)
#define CYREG_SMIF1_SMIF_CRYPTO3_CRYPTO_SUBREGION ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_SUBREGION_t*) 0x4043038CUL)
#define CYREG_SMIF1_SMIF_CRYPTO3_CRYPTO_INPUT0 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT0_t*) 0x404303A0UL)
#define CYREG_SMIF1_SMIF_CRYPTO3_CRYPTO_INPUT1 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT1_t*) 0x404303A4UL)
#define CYREG_SMIF1_SMIF_CRYPTO3_CRYPTO_INPUT2 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT2_t*) 0x404303A8UL)
#define CYREG_SMIF1_SMIF_CRYPTO3_CRYPTO_INPUT3 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_INPUT3_t*) 0x404303ACUL)
#define CYREG_SMIF1_SMIF_CRYPTO3_CRYPTO_KEY0 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY0_t*) 0x404303C0UL)
#define CYREG_SMIF1_SMIF_CRYPTO3_CRYPTO_KEY1 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY1_t*) 0x404303C4UL)
#define CYREG_SMIF1_SMIF_CRYPTO3_CRYPTO_KEY2 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY2_t*) 0x404303C8UL)
#define CYREG_SMIF1_SMIF_CRYPTO3_CRYPTO_KEY3 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_KEY3_t*) 0x404303CCUL)
#define CYREG_SMIF1_SMIF_CRYPTO3_CRYPTO_OUTPUT0 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT0_t*) 0x404303E0UL)
#define CYREG_SMIF1_SMIF_CRYPTO3_CRYPTO_OUTPUT1 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT1_t*) 0x404303E4UL)
#define CYREG_SMIF1_SMIF_CRYPTO3_CRYPTO_OUTPUT2 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT2_t*) 0x404303E8UL)
#define CYREG_SMIF1_SMIF_CRYPTO3_CRYPTO_OUTPUT3 ((volatile un_SMIF_SMIF_CRYPTO_CRYPTO_OUTPUT3_t*) 0x404303ECUL)

/**
  * \brief Device (only used for XIP acceses) (SMIF_DEVICE0)
  */
#define CYREG_SMIF1_DEVICE0_CTL         ((volatile un_SMIF_DEVICE_CTL_t*) 0x40430800UL)
#define CYREG_SMIF1_DEVICE0_ADDR        ((volatile un_SMIF_DEVICE_ADDR_t*) 0x40430808UL)
#define CYREG_SMIF1_DEVICE0_MASK        ((volatile un_SMIF_DEVICE_MASK_t*) 0x4043080CUL)
#define CYREG_SMIF1_DEVICE0_ADDR_CTL    ((volatile un_SMIF_DEVICE_ADDR_CTL_t*) 0x40430820UL)
#define CYREG_SMIF1_DEVICE0_DELAY_TAP_SEL ((volatile un_SMIF_DEVICE_DELAY_TAP_SEL_t*) 0x4043082CUL)
#define CYREG_SMIF1_DEVICE0_RD_CMD_CTL  ((volatile un_SMIF_DEVICE_RD_CMD_CTL_t*) 0x40430840UL)
#define CYREG_SMIF1_DEVICE0_RD_ADDR_CTL ((volatile un_SMIF_DEVICE_RD_ADDR_CTL_t*) 0x40430844UL)
#define CYREG_SMIF1_DEVICE0_RD_MODE_CTL ((volatile un_SMIF_DEVICE_RD_MODE_CTL_t*) 0x40430848UL)
#define CYREG_SMIF1_DEVICE0_RD_DUMMY_CTL ((volatile un_SMIF_DEVICE_RD_DUMMY_CTL_t*) 0x4043084CUL)
#define CYREG_SMIF1_DEVICE0_RD_DATA_CTL ((volatile un_SMIF_DEVICE_RD_DATA_CTL_t*) 0x40430850UL)
#define CYREG_SMIF1_DEVICE0_RD_BOUND_CTL ((volatile un_SMIF_DEVICE_RD_BOUND_CTL_t*) 0x40430858UL)
#define CYREG_SMIF1_DEVICE0_WR_CMD_CTL  ((volatile un_SMIF_DEVICE_WR_CMD_CTL_t*) 0x40430860UL)
#define CYREG_SMIF1_DEVICE0_WR_ADDR_CTL ((volatile un_SMIF_DEVICE_WR_ADDR_CTL_t*) 0x40430864UL)
#define CYREG_SMIF1_DEVICE0_WR_MODE_CTL ((volatile un_SMIF_DEVICE_WR_MODE_CTL_t*) 0x40430868UL)
#define CYREG_SMIF1_DEVICE0_WR_DUMMY_CTL ((volatile un_SMIF_DEVICE_WR_DUMMY_CTL_t*) 0x4043086CUL)
#define CYREG_SMIF1_DEVICE0_WR_DATA_CTL ((volatile un_SMIF_DEVICE_WR_DATA_CTL_t*) 0x40430870UL)

/**
  * \brief Device (only used for XIP acceses) (SMIF_DEVICE1)
  */
#define CYREG_SMIF1_DEVICE1_CTL         ((volatile un_SMIF_DEVICE_CTL_t*) 0x40430880UL)
#define CYREG_SMIF1_DEVICE1_ADDR        ((volatile un_SMIF_DEVICE_ADDR_t*) 0x40430888UL)
#define CYREG_SMIF1_DEVICE1_MASK        ((volatile un_SMIF_DEVICE_MASK_t*) 0x4043088CUL)
#define CYREG_SMIF1_DEVICE1_ADDR_CTL    ((volatile un_SMIF_DEVICE_ADDR_CTL_t*) 0x404308A0UL)
#define CYREG_SMIF1_DEVICE1_DELAY_TAP_SEL ((volatile un_SMIF_DEVICE_DELAY_TAP_SEL_t*) 0x404308ACUL)
#define CYREG_SMIF1_DEVICE1_RD_CMD_CTL  ((volatile un_SMIF_DEVICE_RD_CMD_CTL_t*) 0x404308C0UL)
#define CYREG_SMIF1_DEVICE1_RD_ADDR_CTL ((volatile un_SMIF_DEVICE_RD_ADDR_CTL_t*) 0x404308C4UL)
#define CYREG_SMIF1_DEVICE1_RD_MODE_CTL ((volatile un_SMIF_DEVICE_RD_MODE_CTL_t*) 0x404308C8UL)
#define CYREG_SMIF1_DEVICE1_RD_DUMMY_CTL ((volatile un_SMIF_DEVICE_RD_DUMMY_CTL_t*) 0x404308CCUL)
#define CYREG_SMIF1_DEVICE1_RD_DATA_CTL ((volatile un_SMIF_DEVICE_RD_DATA_CTL_t*) 0x404308D0UL)
#define CYREG_SMIF1_DEVICE1_RD_BOUND_CTL ((volatile un_SMIF_DEVICE_RD_BOUND_CTL_t*) 0x404308D8UL)
#define CYREG_SMIF1_DEVICE1_WR_CMD_CTL  ((volatile un_SMIF_DEVICE_WR_CMD_CTL_t*) 0x404308E0UL)
#define CYREG_SMIF1_DEVICE1_WR_ADDR_CTL ((volatile un_SMIF_DEVICE_WR_ADDR_CTL_t*) 0x404308E4UL)
#define CYREG_SMIF1_DEVICE1_WR_MODE_CTL ((volatile un_SMIF_DEVICE_WR_MODE_CTL_t*) 0x404308E8UL)
#define CYREG_SMIF1_DEVICE1_WR_DUMMY_CTL ((volatile un_SMIF_DEVICE_WR_DUMMY_CTL_t*) 0x404308ECUL)
#define CYREG_SMIF1_DEVICE1_WR_DATA_CTL ((volatile un_SMIF_DEVICE_WR_DATA_CTL_t*) 0x404308F0UL)

/**
  * \brief Serial Memory Interface (SMIF1)
  */
#define CYREG_SMIF1_CTL                 ((volatile un_SMIF_CTL_t*) 0x40430000UL)
#define CYREG_SMIF1_STATUS              ((volatile un_SMIF_STATUS_t*) 0x40430004UL)
#define CYREG_SMIF1_INT_CLOCK_DELAY_TAP_SEL0 ((volatile un_SMIF_INT_CLOCK_DELAY_TAP_SEL0_t*) 0x40430010UL)
#define CYREG_SMIF1_INT_CLOCK_DELAY_TAP_SEL1 ((volatile un_SMIF_INT_CLOCK_DELAY_TAP_SEL1_t*) 0x40430014UL)
#define CYREG_SMIF1_DL_CTL              ((volatile un_SMIF_DL_CTL_t*) 0x40430018UL)
#define CYREG_SMIF1_DL_STATUS0          ((volatile un_SMIF_DL_STATUS0_t*) 0x40430020UL)
#define CYREG_SMIF1_DL_STATUS1          ((volatile un_SMIF_DL_STATUS1_t*) 0x40430024UL)
#define CYREG_SMIF1_TX_CMD_FIFO_STATUS  ((volatile un_SMIF_TX_CMD_FIFO_STATUS_t*) 0x40430044UL)
#define CYREG_SMIF1_TX_CMD_MMIO_FIFO_STATUS ((volatile un_SMIF_TX_CMD_MMIO_FIFO_STATUS_t*) 0x40430048UL)
#define CYREG_SMIF1_TX_CMD_MMIO_FIFO_WR ((volatile un_SMIF_TX_CMD_MMIO_FIFO_WR_t*) 0x40430050UL)
#define CYREG_SMIF1_TX_DATA_MMIO_FIFO_CTL ((volatile un_SMIF_TX_DATA_MMIO_FIFO_CTL_t*) 0x40430080UL)
#define CYREG_SMIF1_TX_DATA_FIFO_STATUS ((volatile un_SMIF_TX_DATA_FIFO_STATUS_t*) 0x40430084UL)
#define CYREG_SMIF1_TX_DATA_MMIO_FIFO_STATUS ((volatile un_SMIF_TX_DATA_MMIO_FIFO_STATUS_t*) 0x40430088UL)
#define CYREG_SMIF1_TX_DATA_MMIO_FIFO_WR1 ((volatile un_SMIF_TX_DATA_MMIO_FIFO_WR1_t*) 0x40430090UL)
#define CYREG_SMIF1_TX_DATA_MMIO_FIFO_WR2 ((volatile un_SMIF_TX_DATA_MMIO_FIFO_WR2_t*) 0x40430094UL)
#define CYREG_SMIF1_TX_DATA_MMIO_FIFO_WR4 ((volatile un_SMIF_TX_DATA_MMIO_FIFO_WR4_t*) 0x40430098UL)
#define CYREG_SMIF1_TX_DATA_MMIO_FIFO_WR1ODD ((volatile un_SMIF_TX_DATA_MMIO_FIFO_WR1ODD_t*) 0x4043009CUL)
#define CYREG_SMIF1_RX_DATA_MMIO_FIFO_CTL ((volatile un_SMIF_RX_DATA_MMIO_FIFO_CTL_t*) 0x404300C0UL)
#define CYREG_SMIF1_RX_DATA_MMIO_FIFO_STATUS ((volatile un_SMIF_RX_DATA_MMIO_FIFO_STATUS_t*) 0x404300C4UL)
#define CYREG_SMIF1_RX_DATA_FIFO_STATUS ((volatile un_SMIF_RX_DATA_FIFO_STATUS_t*) 0x404300C8UL)
#define CYREG_SMIF1_RX_DATA_MMIO_FIFO_RD1 ((volatile un_SMIF_RX_DATA_MMIO_FIFO_RD1_t*) 0x404300D0UL)
#define CYREG_SMIF1_RX_DATA_MMIO_FIFO_RD2 ((volatile un_SMIF_RX_DATA_MMIO_FIFO_RD2_t*) 0x404300D4UL)
#define CYREG_SMIF1_RX_DATA_MMIO_FIFO_RD4 ((volatile un_SMIF_RX_DATA_MMIO_FIFO_RD4_t*) 0x404300D8UL)
#define CYREG_SMIF1_RX_DATA_MMIO_FIFO_RD1_SILENT ((volatile un_SMIF_RX_DATA_MMIO_FIFO_RD1_SILENT_t*) 0x404300E0UL)
#define CYREG_SMIF1_SLOW_CA_CTL         ((volatile un_SMIF_SLOW_CA_CTL_t*) 0x40430100UL)
#define CYREG_SMIF1_SLOW_CA_CMD         ((volatile un_SMIF_SLOW_CA_CMD_t*) 0x40430108UL)
#define CYREG_SMIF1_INTR                ((volatile un_SMIF_INTR_t*) 0x404307C0UL)
#define CYREG_SMIF1_INTR_SET            ((volatile un_SMIF_INTR_SET_t*) 0x404307C4UL)
#define CYREG_SMIF1_INTR_MASK           ((volatile un_SMIF_INTR_MASK_t*) 0x404307C8UL)
#define CYREG_SMIF1_INTR_MASKED         ((volatile un_SMIF_INTR_MASKED_t*) 0x404307CCUL)

#endif /* _CYREG_SMIF_H_ */


/* [] END OF FILE */