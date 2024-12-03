/***************************************************************************//**
* \file cyreg_canfd.h
*
* \brief
* CANFD register definition header
*
* \note
* Generator version: 1.6.0.644
* Database revision: TVIIC26DM_B1_CFR
*
********************************************************************************
* \copyright
* Copyright 2016-2021, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef _CYREG_CANFD_H_
#define _CYREG_CANFD_H_

#include "cyip_canfd.h"

/**
  * \brief TTCAN 3PIP, includes FD (CANFD_CH_M_TTCAN0)
  */
#define CYREG_CANFD0_CH0_CREL           ((volatile un_CANFD_CH_CREL_t*) 0x40520000UL)
#define CYREG_CANFD0_CH0_ENDN           ((volatile un_CANFD_CH_ENDN_t*) 0x40520004UL)
#define CYREG_CANFD0_CH0_DBTP           ((volatile un_CANFD_CH_DBTP_t*) 0x4052000CUL)
#define CYREG_CANFD0_CH0_TEST           ((volatile un_CANFD_CH_TEST_t*) 0x40520010UL)
#define CYREG_CANFD0_CH0_RWD            ((volatile un_CANFD_CH_RWD_t*) 0x40520014UL)
#define CYREG_CANFD0_CH0_CCCR           ((volatile un_CANFD_CH_CCCR_t*) 0x40520018UL)
#define CYREG_CANFD0_CH0_NBTP           ((volatile un_CANFD_CH_NBTP_t*) 0x4052001CUL)
#define CYREG_CANFD0_CH0_TSCC           ((volatile un_CANFD_CH_TSCC_t*) 0x40520020UL)
#define CYREG_CANFD0_CH0_TSCV           ((volatile un_CANFD_CH_TSCV_t*) 0x40520024UL)
#define CYREG_CANFD0_CH0_TOCC           ((volatile un_CANFD_CH_TOCC_t*) 0x40520028UL)
#define CYREG_CANFD0_CH0_TOCV           ((volatile un_CANFD_CH_TOCV_t*) 0x4052002CUL)
#define CYREG_CANFD0_CH0_ECR            ((volatile un_CANFD_CH_ECR_t*) 0x40520040UL)
#define CYREG_CANFD0_CH0_PSR            ((volatile un_CANFD_CH_PSR_t*) 0x40520044UL)
#define CYREG_CANFD0_CH0_TDCR           ((volatile un_CANFD_CH_TDCR_t*) 0x40520048UL)
#define CYREG_CANFD0_CH0_IR             ((volatile un_CANFD_CH_IR_t*) 0x40520050UL)
#define CYREG_CANFD0_CH0_IE             ((volatile un_CANFD_CH_IE_t*) 0x40520054UL)
#define CYREG_CANFD0_CH0_ILS            ((volatile un_CANFD_CH_ILS_t*) 0x40520058UL)
#define CYREG_CANFD0_CH0_ILE            ((volatile un_CANFD_CH_ILE_t*) 0x4052005CUL)
#define CYREG_CANFD0_CH0_GFC            ((volatile un_CANFD_CH_GFC_t*) 0x40520080UL)
#define CYREG_CANFD0_CH0_SIDFC          ((volatile un_CANFD_CH_SIDFC_t*) 0x40520084UL)
#define CYREG_CANFD0_CH0_XIDFC          ((volatile un_CANFD_CH_XIDFC_t*) 0x40520088UL)
#define CYREG_CANFD0_CH0_XIDAM          ((volatile un_CANFD_CH_XIDAM_t*) 0x40520090UL)
#define CYREG_CANFD0_CH0_HPMS           ((volatile un_CANFD_CH_HPMS_t*) 0x40520094UL)
#define CYREG_CANFD0_CH0_NDAT1          ((volatile un_CANFD_CH_NDAT1_t*) 0x40520098UL)
#define CYREG_CANFD0_CH0_NDAT2          ((volatile un_CANFD_CH_NDAT2_t*) 0x4052009CUL)
#define CYREG_CANFD0_CH0_RXF0C          ((volatile un_CANFD_CH_RXF0C_t*) 0x405200A0UL)
#define CYREG_CANFD0_CH0_RXF0S          ((volatile un_CANFD_CH_RXF0S_t*) 0x405200A4UL)
#define CYREG_CANFD0_CH0_RXF0A          ((volatile un_CANFD_CH_RXF0A_t*) 0x405200A8UL)
#define CYREG_CANFD0_CH0_RXBC           ((volatile un_CANFD_CH_RXBC_t*) 0x405200ACUL)
#define CYREG_CANFD0_CH0_RXF1C          ((volatile un_CANFD_CH_RXF1C_t*) 0x405200B0UL)
#define CYREG_CANFD0_CH0_RXF1S          ((volatile un_CANFD_CH_RXF1S_t*) 0x405200B4UL)
#define CYREG_CANFD0_CH0_RXF1A          ((volatile un_CANFD_CH_RXF1A_t*) 0x405200B8UL)
#define CYREG_CANFD0_CH0_RXESC          ((volatile un_CANFD_CH_RXESC_t*) 0x405200BCUL)
#define CYREG_CANFD0_CH0_TXBC           ((volatile un_CANFD_CH_TXBC_t*) 0x405200C0UL)
#define CYREG_CANFD0_CH0_TXFQS          ((volatile un_CANFD_CH_TXFQS_t*) 0x405200C4UL)
#define CYREG_CANFD0_CH0_TXESC          ((volatile un_CANFD_CH_TXESC_t*) 0x405200C8UL)
#define CYREG_CANFD0_CH0_TXBRP          ((volatile un_CANFD_CH_TXBRP_t*) 0x405200CCUL)
#define CYREG_CANFD0_CH0_TXBAR          ((volatile un_CANFD_CH_TXBAR_t*) 0x405200D0UL)
#define CYREG_CANFD0_CH0_TXBCR          ((volatile un_CANFD_CH_TXBCR_t*) 0x405200D4UL)
#define CYREG_CANFD0_CH0_TXBTO          ((volatile un_CANFD_CH_TXBTO_t*) 0x405200D8UL)
#define CYREG_CANFD0_CH0_TXBCF          ((volatile un_CANFD_CH_TXBCF_t*) 0x405200DCUL)
#define CYREG_CANFD0_CH0_TXBTIE         ((volatile un_CANFD_CH_TXBTIE_t*) 0x405200E0UL)
#define CYREG_CANFD0_CH0_TXBCIE         ((volatile un_CANFD_CH_TXBCIE_t*) 0x405200E4UL)
#define CYREG_CANFD0_CH0_TXEFC          ((volatile un_CANFD_CH_TXEFC_t*) 0x405200F0UL)
#define CYREG_CANFD0_CH0_TXEFS          ((volatile un_CANFD_CH_TXEFS_t*) 0x405200F4UL)
#define CYREG_CANFD0_CH0_TXEFA          ((volatile un_CANFD_CH_TXEFA_t*) 0x405200F8UL)
#define CYREG_CANFD0_CH0_TTTMC          ((volatile un_CANFD_CH_TTTMC_t*) 0x40520100UL)
#define CYREG_CANFD0_CH0_TTRMC          ((volatile un_CANFD_CH_TTRMC_t*) 0x40520104UL)
#define CYREG_CANFD0_CH0_TTOCF          ((volatile un_CANFD_CH_TTOCF_t*) 0x40520108UL)
#define CYREG_CANFD0_CH0_TTMLM          ((volatile un_CANFD_CH_TTMLM_t*) 0x4052010CUL)
#define CYREG_CANFD0_CH0_TURCF          ((volatile un_CANFD_CH_TURCF_t*) 0x40520110UL)
#define CYREG_CANFD0_CH0_TTOCN          ((volatile un_CANFD_CH_TTOCN_t*) 0x40520114UL)
#define CYREG_CANFD0_CH0_TTGTP          ((volatile un_CANFD_CH_TTGTP_t*) 0x40520118UL)
#define CYREG_CANFD0_CH0_TTTMK          ((volatile un_CANFD_CH_TTTMK_t*) 0x4052011CUL)
#define CYREG_CANFD0_CH0_TTIR           ((volatile un_CANFD_CH_TTIR_t*) 0x40520120UL)
#define CYREG_CANFD0_CH0_TTIE           ((volatile un_CANFD_CH_TTIE_t*) 0x40520124UL)
#define CYREG_CANFD0_CH0_TTILS          ((volatile un_CANFD_CH_TTILS_t*) 0x40520128UL)
#define CYREG_CANFD0_CH0_TTOST          ((volatile un_CANFD_CH_TTOST_t*) 0x4052012CUL)
#define CYREG_CANFD0_CH0_TURNA          ((volatile un_CANFD_CH_TURNA_t*) 0x40520130UL)
#define CYREG_CANFD0_CH0_TTLGT          ((volatile un_CANFD_CH_TTLGT_t*) 0x40520134UL)
#define CYREG_CANFD0_CH0_TTCTC          ((volatile un_CANFD_CH_TTCTC_t*) 0x40520138UL)
#define CYREG_CANFD0_CH0_TTCPT          ((volatile un_CANFD_CH_TTCPT_t*) 0x4052013CUL)
#define CYREG_CANFD0_CH0_TTCSM          ((volatile un_CANFD_CH_TTCSM_t*) 0x40520140UL)

/**
  * \brief FIFO wrapper around M_TTCAN 3PIP, to enable DMA (CANFD_CH0)
  */
#define CYREG_CANFD0_CH0_RXFTOP_CTL     ((volatile un_CANFD_CH_RXFTOP_CTL_t*) 0x40520180UL)
#define CYREG_CANFD0_CH0_RXFTOP0_STAT   ((volatile un_CANFD_CH_RXFTOP0_STAT_t*) 0x405201A0UL)
#define CYREG_CANFD0_CH0_RXFTOP0_DATA   ((volatile un_CANFD_CH_RXFTOP0_DATA_t*) 0x405201A8UL)
#define CYREG_CANFD0_CH0_RXFTOP1_STAT   ((volatile un_CANFD_CH_RXFTOP1_STAT_t*) 0x405201B0UL)
#define CYREG_CANFD0_CH0_RXFTOP1_DATA   ((volatile un_CANFD_CH_RXFTOP1_DATA_t*) 0x405201B8UL)

/**
  * \brief TTCAN 3PIP, includes FD (CANFD_CH_M_TTCAN0)
  */
#define CYREG_CANFD0_CH1_CREL           ((volatile un_CANFD_CH_CREL_t*) 0x40520200UL)
#define CYREG_CANFD0_CH1_ENDN           ((volatile un_CANFD_CH_ENDN_t*) 0x40520204UL)
#define CYREG_CANFD0_CH1_DBTP           ((volatile un_CANFD_CH_DBTP_t*) 0x4052020CUL)
#define CYREG_CANFD0_CH1_TEST           ((volatile un_CANFD_CH_TEST_t*) 0x40520210UL)
#define CYREG_CANFD0_CH1_RWD            ((volatile un_CANFD_CH_RWD_t*) 0x40520214UL)
#define CYREG_CANFD0_CH1_CCCR           ((volatile un_CANFD_CH_CCCR_t*) 0x40520218UL)
#define CYREG_CANFD0_CH1_NBTP           ((volatile un_CANFD_CH_NBTP_t*) 0x4052021CUL)
#define CYREG_CANFD0_CH1_TSCC           ((volatile un_CANFD_CH_TSCC_t*) 0x40520220UL)
#define CYREG_CANFD0_CH1_TSCV           ((volatile un_CANFD_CH_TSCV_t*) 0x40520224UL)
#define CYREG_CANFD0_CH1_TOCC           ((volatile un_CANFD_CH_TOCC_t*) 0x40520228UL)
#define CYREG_CANFD0_CH1_TOCV           ((volatile un_CANFD_CH_TOCV_t*) 0x4052022CUL)
#define CYREG_CANFD0_CH1_ECR            ((volatile un_CANFD_CH_ECR_t*) 0x40520240UL)
#define CYREG_CANFD0_CH1_PSR            ((volatile un_CANFD_CH_PSR_t*) 0x40520244UL)
#define CYREG_CANFD0_CH1_TDCR           ((volatile un_CANFD_CH_TDCR_t*) 0x40520248UL)
#define CYREG_CANFD0_CH1_IR             ((volatile un_CANFD_CH_IR_t*) 0x40520250UL)
#define CYREG_CANFD0_CH1_IE             ((volatile un_CANFD_CH_IE_t*) 0x40520254UL)
#define CYREG_CANFD0_CH1_ILS            ((volatile un_CANFD_CH_ILS_t*) 0x40520258UL)
#define CYREG_CANFD0_CH1_ILE            ((volatile un_CANFD_CH_ILE_t*) 0x4052025CUL)
#define CYREG_CANFD0_CH1_GFC            ((volatile un_CANFD_CH_GFC_t*) 0x40520280UL)
#define CYREG_CANFD0_CH1_SIDFC          ((volatile un_CANFD_CH_SIDFC_t*) 0x40520284UL)
#define CYREG_CANFD0_CH1_XIDFC          ((volatile un_CANFD_CH_XIDFC_t*) 0x40520288UL)
#define CYREG_CANFD0_CH1_XIDAM          ((volatile un_CANFD_CH_XIDAM_t*) 0x40520290UL)
#define CYREG_CANFD0_CH1_HPMS           ((volatile un_CANFD_CH_HPMS_t*) 0x40520294UL)
#define CYREG_CANFD0_CH1_NDAT1          ((volatile un_CANFD_CH_NDAT1_t*) 0x40520298UL)
#define CYREG_CANFD0_CH1_NDAT2          ((volatile un_CANFD_CH_NDAT2_t*) 0x4052029CUL)
#define CYREG_CANFD0_CH1_RXF0C          ((volatile un_CANFD_CH_RXF0C_t*) 0x405202A0UL)
#define CYREG_CANFD0_CH1_RXF0S          ((volatile un_CANFD_CH_RXF0S_t*) 0x405202A4UL)
#define CYREG_CANFD0_CH1_RXF0A          ((volatile un_CANFD_CH_RXF0A_t*) 0x405202A8UL)
#define CYREG_CANFD0_CH1_RXBC           ((volatile un_CANFD_CH_RXBC_t*) 0x405202ACUL)
#define CYREG_CANFD0_CH1_RXF1C          ((volatile un_CANFD_CH_RXF1C_t*) 0x405202B0UL)
#define CYREG_CANFD0_CH1_RXF1S          ((volatile un_CANFD_CH_RXF1S_t*) 0x405202B4UL)
#define CYREG_CANFD0_CH1_RXF1A          ((volatile un_CANFD_CH_RXF1A_t*) 0x405202B8UL)
#define CYREG_CANFD0_CH1_RXESC          ((volatile un_CANFD_CH_RXESC_t*) 0x405202BCUL)
#define CYREG_CANFD0_CH1_TXBC           ((volatile un_CANFD_CH_TXBC_t*) 0x405202C0UL)
#define CYREG_CANFD0_CH1_TXFQS          ((volatile un_CANFD_CH_TXFQS_t*) 0x405202C4UL)
#define CYREG_CANFD0_CH1_TXESC          ((volatile un_CANFD_CH_TXESC_t*) 0x405202C8UL)
#define CYREG_CANFD0_CH1_TXBRP          ((volatile un_CANFD_CH_TXBRP_t*) 0x405202CCUL)
#define CYREG_CANFD0_CH1_TXBAR          ((volatile un_CANFD_CH_TXBAR_t*) 0x405202D0UL)
#define CYREG_CANFD0_CH1_TXBCR          ((volatile un_CANFD_CH_TXBCR_t*) 0x405202D4UL)
#define CYREG_CANFD0_CH1_TXBTO          ((volatile un_CANFD_CH_TXBTO_t*) 0x405202D8UL)
#define CYREG_CANFD0_CH1_TXBCF          ((volatile un_CANFD_CH_TXBCF_t*) 0x405202DCUL)
#define CYREG_CANFD0_CH1_TXBTIE         ((volatile un_CANFD_CH_TXBTIE_t*) 0x405202E0UL)
#define CYREG_CANFD0_CH1_TXBCIE         ((volatile un_CANFD_CH_TXBCIE_t*) 0x405202E4UL)
#define CYREG_CANFD0_CH1_TXEFC          ((volatile un_CANFD_CH_TXEFC_t*) 0x405202F0UL)
#define CYREG_CANFD0_CH1_TXEFS          ((volatile un_CANFD_CH_TXEFS_t*) 0x405202F4UL)
#define CYREG_CANFD0_CH1_TXEFA          ((volatile un_CANFD_CH_TXEFA_t*) 0x405202F8UL)
#define CYREG_CANFD0_CH1_TTTMC          ((volatile un_CANFD_CH_TTTMC_t*) 0x40520300UL)
#define CYREG_CANFD0_CH1_TTRMC          ((volatile un_CANFD_CH_TTRMC_t*) 0x40520304UL)
#define CYREG_CANFD0_CH1_TTOCF          ((volatile un_CANFD_CH_TTOCF_t*) 0x40520308UL)
#define CYREG_CANFD0_CH1_TTMLM          ((volatile un_CANFD_CH_TTMLM_t*) 0x4052030CUL)
#define CYREG_CANFD0_CH1_TURCF          ((volatile un_CANFD_CH_TURCF_t*) 0x40520310UL)
#define CYREG_CANFD0_CH1_TTOCN          ((volatile un_CANFD_CH_TTOCN_t*) 0x40520314UL)
#define CYREG_CANFD0_CH1_TTGTP          ((volatile un_CANFD_CH_TTGTP_t*) 0x40520318UL)
#define CYREG_CANFD0_CH1_TTTMK          ((volatile un_CANFD_CH_TTTMK_t*) 0x4052031CUL)
#define CYREG_CANFD0_CH1_TTIR           ((volatile un_CANFD_CH_TTIR_t*) 0x40520320UL)
#define CYREG_CANFD0_CH1_TTIE           ((volatile un_CANFD_CH_TTIE_t*) 0x40520324UL)
#define CYREG_CANFD0_CH1_TTILS          ((volatile un_CANFD_CH_TTILS_t*) 0x40520328UL)
#define CYREG_CANFD0_CH1_TTOST          ((volatile un_CANFD_CH_TTOST_t*) 0x4052032CUL)
#define CYREG_CANFD0_CH1_TURNA          ((volatile un_CANFD_CH_TURNA_t*) 0x40520330UL)
#define CYREG_CANFD0_CH1_TTLGT          ((volatile un_CANFD_CH_TTLGT_t*) 0x40520334UL)
#define CYREG_CANFD0_CH1_TTCTC          ((volatile un_CANFD_CH_TTCTC_t*) 0x40520338UL)
#define CYREG_CANFD0_CH1_TTCPT          ((volatile un_CANFD_CH_TTCPT_t*) 0x4052033CUL)
#define CYREG_CANFD0_CH1_TTCSM          ((volatile un_CANFD_CH_TTCSM_t*) 0x40520340UL)

/**
  * \brief FIFO wrapper around M_TTCAN 3PIP, to enable DMA (CANFD_CH1)
  */
#define CYREG_CANFD0_CH1_RXFTOP_CTL     ((volatile un_CANFD_CH_RXFTOP_CTL_t*) 0x40520380UL)
#define CYREG_CANFD0_CH1_RXFTOP0_STAT   ((volatile un_CANFD_CH_RXFTOP0_STAT_t*) 0x405203A0UL)
#define CYREG_CANFD0_CH1_RXFTOP0_DATA   ((volatile un_CANFD_CH_RXFTOP0_DATA_t*) 0x405203A8UL)
#define CYREG_CANFD0_CH1_RXFTOP1_STAT   ((volatile un_CANFD_CH_RXFTOP1_STAT_t*) 0x405203B0UL)
#define CYREG_CANFD0_CH1_RXFTOP1_DATA   ((volatile un_CANFD_CH_RXFTOP1_DATA_t*) 0x405203B8UL)

/**
  * \brief CAN Controller (CANFD0)
  */
#define CYREG_CANFD0_CTL                ((volatile un_CANFD_CTL_t*) 0x40521000UL)
#define CYREG_CANFD0_STATUS             ((volatile un_CANFD_STATUS_t*) 0x40521004UL)
#define CYREG_CANFD0_INTR0_CAUSE        ((volatile un_CANFD_INTR0_CAUSE_t*) 0x40521010UL)
#define CYREG_CANFD0_INTR1_CAUSE        ((volatile un_CANFD_INTR1_CAUSE_t*) 0x40521014UL)
#define CYREG_CANFD0_TS_CTL             ((volatile un_CANFD_TS_CTL_t*) 0x40521020UL)
#define CYREG_CANFD0_TS_CNT             ((volatile un_CANFD_TS_CNT_t*) 0x40521024UL)
#define CYREG_CANFD0_ECC_CTL            ((volatile un_CANFD_ECC_CTL_t*) 0x40521080UL)
#define CYREG_CANFD0_ECC_ERR_INJ        ((volatile un_CANFD_ECC_ERR_INJ_t*) 0x40521084UL)

/**
  * \brief TTCAN 3PIP, includes FD (CANFD_CH_M_TTCAN0)
  */
#define CYREG_CANFD1_CH0_CREL           ((volatile un_CANFD_CH_CREL_t*) 0x40540000UL)
#define CYREG_CANFD1_CH0_ENDN           ((volatile un_CANFD_CH_ENDN_t*) 0x40540004UL)
#define CYREG_CANFD1_CH0_DBTP           ((volatile un_CANFD_CH_DBTP_t*) 0x4054000CUL)
#define CYREG_CANFD1_CH0_TEST           ((volatile un_CANFD_CH_TEST_t*) 0x40540010UL)
#define CYREG_CANFD1_CH0_RWD            ((volatile un_CANFD_CH_RWD_t*) 0x40540014UL)
#define CYREG_CANFD1_CH0_CCCR           ((volatile un_CANFD_CH_CCCR_t*) 0x40540018UL)
#define CYREG_CANFD1_CH0_NBTP           ((volatile un_CANFD_CH_NBTP_t*) 0x4054001CUL)
#define CYREG_CANFD1_CH0_TSCC           ((volatile un_CANFD_CH_TSCC_t*) 0x40540020UL)
#define CYREG_CANFD1_CH0_TSCV           ((volatile un_CANFD_CH_TSCV_t*) 0x40540024UL)
#define CYREG_CANFD1_CH0_TOCC           ((volatile un_CANFD_CH_TOCC_t*) 0x40540028UL)
#define CYREG_CANFD1_CH0_TOCV           ((volatile un_CANFD_CH_TOCV_t*) 0x4054002CUL)
#define CYREG_CANFD1_CH0_ECR            ((volatile un_CANFD_CH_ECR_t*) 0x40540040UL)
#define CYREG_CANFD1_CH0_PSR            ((volatile un_CANFD_CH_PSR_t*) 0x40540044UL)
#define CYREG_CANFD1_CH0_TDCR           ((volatile un_CANFD_CH_TDCR_t*) 0x40540048UL)
#define CYREG_CANFD1_CH0_IR             ((volatile un_CANFD_CH_IR_t*) 0x40540050UL)
#define CYREG_CANFD1_CH0_IE             ((volatile un_CANFD_CH_IE_t*) 0x40540054UL)
#define CYREG_CANFD1_CH0_ILS            ((volatile un_CANFD_CH_ILS_t*) 0x40540058UL)
#define CYREG_CANFD1_CH0_ILE            ((volatile un_CANFD_CH_ILE_t*) 0x4054005CUL)
#define CYREG_CANFD1_CH0_GFC            ((volatile un_CANFD_CH_GFC_t*) 0x40540080UL)
#define CYREG_CANFD1_CH0_SIDFC          ((volatile un_CANFD_CH_SIDFC_t*) 0x40540084UL)
#define CYREG_CANFD1_CH0_XIDFC          ((volatile un_CANFD_CH_XIDFC_t*) 0x40540088UL)
#define CYREG_CANFD1_CH0_XIDAM          ((volatile un_CANFD_CH_XIDAM_t*) 0x40540090UL)
#define CYREG_CANFD1_CH0_HPMS           ((volatile un_CANFD_CH_HPMS_t*) 0x40540094UL)
#define CYREG_CANFD1_CH0_NDAT1          ((volatile un_CANFD_CH_NDAT1_t*) 0x40540098UL)
#define CYREG_CANFD1_CH0_NDAT2          ((volatile un_CANFD_CH_NDAT2_t*) 0x4054009CUL)
#define CYREG_CANFD1_CH0_RXF0C          ((volatile un_CANFD_CH_RXF0C_t*) 0x405400A0UL)
#define CYREG_CANFD1_CH0_RXF0S          ((volatile un_CANFD_CH_RXF0S_t*) 0x405400A4UL)
#define CYREG_CANFD1_CH0_RXF0A          ((volatile un_CANFD_CH_RXF0A_t*) 0x405400A8UL)
#define CYREG_CANFD1_CH0_RXBC           ((volatile un_CANFD_CH_RXBC_t*) 0x405400ACUL)
#define CYREG_CANFD1_CH0_RXF1C          ((volatile un_CANFD_CH_RXF1C_t*) 0x405400B0UL)
#define CYREG_CANFD1_CH0_RXF1S          ((volatile un_CANFD_CH_RXF1S_t*) 0x405400B4UL)
#define CYREG_CANFD1_CH0_RXF1A          ((volatile un_CANFD_CH_RXF1A_t*) 0x405400B8UL)
#define CYREG_CANFD1_CH0_RXESC          ((volatile un_CANFD_CH_RXESC_t*) 0x405400BCUL)
#define CYREG_CANFD1_CH0_TXBC           ((volatile un_CANFD_CH_TXBC_t*) 0x405400C0UL)
#define CYREG_CANFD1_CH0_TXFQS          ((volatile un_CANFD_CH_TXFQS_t*) 0x405400C4UL)
#define CYREG_CANFD1_CH0_TXESC          ((volatile un_CANFD_CH_TXESC_t*) 0x405400C8UL)
#define CYREG_CANFD1_CH0_TXBRP          ((volatile un_CANFD_CH_TXBRP_t*) 0x405400CCUL)
#define CYREG_CANFD1_CH0_TXBAR          ((volatile un_CANFD_CH_TXBAR_t*) 0x405400D0UL)
#define CYREG_CANFD1_CH0_TXBCR          ((volatile un_CANFD_CH_TXBCR_t*) 0x405400D4UL)
#define CYREG_CANFD1_CH0_TXBTO          ((volatile un_CANFD_CH_TXBTO_t*) 0x405400D8UL)
#define CYREG_CANFD1_CH0_TXBCF          ((volatile un_CANFD_CH_TXBCF_t*) 0x405400DCUL)
#define CYREG_CANFD1_CH0_TXBTIE         ((volatile un_CANFD_CH_TXBTIE_t*) 0x405400E0UL)
#define CYREG_CANFD1_CH0_TXBCIE         ((volatile un_CANFD_CH_TXBCIE_t*) 0x405400E4UL)
#define CYREG_CANFD1_CH0_TXEFC          ((volatile un_CANFD_CH_TXEFC_t*) 0x405400F0UL)
#define CYREG_CANFD1_CH0_TXEFS          ((volatile un_CANFD_CH_TXEFS_t*) 0x405400F4UL)
#define CYREG_CANFD1_CH0_TXEFA          ((volatile un_CANFD_CH_TXEFA_t*) 0x405400F8UL)
#define CYREG_CANFD1_CH0_TTTMC          ((volatile un_CANFD_CH_TTTMC_t*) 0x40540100UL)
#define CYREG_CANFD1_CH0_TTRMC          ((volatile un_CANFD_CH_TTRMC_t*) 0x40540104UL)
#define CYREG_CANFD1_CH0_TTOCF          ((volatile un_CANFD_CH_TTOCF_t*) 0x40540108UL)
#define CYREG_CANFD1_CH0_TTMLM          ((volatile un_CANFD_CH_TTMLM_t*) 0x4054010CUL)
#define CYREG_CANFD1_CH0_TURCF          ((volatile un_CANFD_CH_TURCF_t*) 0x40540110UL)
#define CYREG_CANFD1_CH0_TTOCN          ((volatile un_CANFD_CH_TTOCN_t*) 0x40540114UL)
#define CYREG_CANFD1_CH0_TTGTP          ((volatile un_CANFD_CH_TTGTP_t*) 0x40540118UL)
#define CYREG_CANFD1_CH0_TTTMK          ((volatile un_CANFD_CH_TTTMK_t*) 0x4054011CUL)
#define CYREG_CANFD1_CH0_TTIR           ((volatile un_CANFD_CH_TTIR_t*) 0x40540120UL)
#define CYREG_CANFD1_CH0_TTIE           ((volatile un_CANFD_CH_TTIE_t*) 0x40540124UL)
#define CYREG_CANFD1_CH0_TTILS          ((volatile un_CANFD_CH_TTILS_t*) 0x40540128UL)
#define CYREG_CANFD1_CH0_TTOST          ((volatile un_CANFD_CH_TTOST_t*) 0x4054012CUL)
#define CYREG_CANFD1_CH0_TURNA          ((volatile un_CANFD_CH_TURNA_t*) 0x40540130UL)
#define CYREG_CANFD1_CH0_TTLGT          ((volatile un_CANFD_CH_TTLGT_t*) 0x40540134UL)
#define CYREG_CANFD1_CH0_TTCTC          ((volatile un_CANFD_CH_TTCTC_t*) 0x40540138UL)
#define CYREG_CANFD1_CH0_TTCPT          ((volatile un_CANFD_CH_TTCPT_t*) 0x4054013CUL)
#define CYREG_CANFD1_CH0_TTCSM          ((volatile un_CANFD_CH_TTCSM_t*) 0x40540140UL)

/**
  * \brief FIFO wrapper around M_TTCAN 3PIP, to enable DMA (CANFD_CH0)
  */
#define CYREG_CANFD1_CH0_RXFTOP_CTL     ((volatile un_CANFD_CH_RXFTOP_CTL_t*) 0x40540180UL)
#define CYREG_CANFD1_CH0_RXFTOP0_STAT   ((volatile un_CANFD_CH_RXFTOP0_STAT_t*) 0x405401A0UL)
#define CYREG_CANFD1_CH0_RXFTOP0_DATA   ((volatile un_CANFD_CH_RXFTOP0_DATA_t*) 0x405401A8UL)
#define CYREG_CANFD1_CH0_RXFTOP1_STAT   ((volatile un_CANFD_CH_RXFTOP1_STAT_t*) 0x405401B0UL)
#define CYREG_CANFD1_CH0_RXFTOP1_DATA   ((volatile un_CANFD_CH_RXFTOP1_DATA_t*) 0x405401B8UL)

/**
  * \brief TTCAN 3PIP, includes FD (CANFD_CH_M_TTCAN0)
  */
#define CYREG_CANFD1_CH1_CREL           ((volatile un_CANFD_CH_CREL_t*) 0x40540200UL)
#define CYREG_CANFD1_CH1_ENDN           ((volatile un_CANFD_CH_ENDN_t*) 0x40540204UL)
#define CYREG_CANFD1_CH1_DBTP           ((volatile un_CANFD_CH_DBTP_t*) 0x4054020CUL)
#define CYREG_CANFD1_CH1_TEST           ((volatile un_CANFD_CH_TEST_t*) 0x40540210UL)
#define CYREG_CANFD1_CH1_RWD            ((volatile un_CANFD_CH_RWD_t*) 0x40540214UL)
#define CYREG_CANFD1_CH1_CCCR           ((volatile un_CANFD_CH_CCCR_t*) 0x40540218UL)
#define CYREG_CANFD1_CH1_NBTP           ((volatile un_CANFD_CH_NBTP_t*) 0x4054021CUL)
#define CYREG_CANFD1_CH1_TSCC           ((volatile un_CANFD_CH_TSCC_t*) 0x40540220UL)
#define CYREG_CANFD1_CH1_TSCV           ((volatile un_CANFD_CH_TSCV_t*) 0x40540224UL)
#define CYREG_CANFD1_CH1_TOCC           ((volatile un_CANFD_CH_TOCC_t*) 0x40540228UL)
#define CYREG_CANFD1_CH1_TOCV           ((volatile un_CANFD_CH_TOCV_t*) 0x4054022CUL)
#define CYREG_CANFD1_CH1_ECR            ((volatile un_CANFD_CH_ECR_t*) 0x40540240UL)
#define CYREG_CANFD1_CH1_PSR            ((volatile un_CANFD_CH_PSR_t*) 0x40540244UL)
#define CYREG_CANFD1_CH1_TDCR           ((volatile un_CANFD_CH_TDCR_t*) 0x40540248UL)
#define CYREG_CANFD1_CH1_IR             ((volatile un_CANFD_CH_IR_t*) 0x40540250UL)
#define CYREG_CANFD1_CH1_IE             ((volatile un_CANFD_CH_IE_t*) 0x40540254UL)
#define CYREG_CANFD1_CH1_ILS            ((volatile un_CANFD_CH_ILS_t*) 0x40540258UL)
#define CYREG_CANFD1_CH1_ILE            ((volatile un_CANFD_CH_ILE_t*) 0x4054025CUL)
#define CYREG_CANFD1_CH1_GFC            ((volatile un_CANFD_CH_GFC_t*) 0x40540280UL)
#define CYREG_CANFD1_CH1_SIDFC          ((volatile un_CANFD_CH_SIDFC_t*) 0x40540284UL)
#define CYREG_CANFD1_CH1_XIDFC          ((volatile un_CANFD_CH_XIDFC_t*) 0x40540288UL)
#define CYREG_CANFD1_CH1_XIDAM          ((volatile un_CANFD_CH_XIDAM_t*) 0x40540290UL)
#define CYREG_CANFD1_CH1_HPMS           ((volatile un_CANFD_CH_HPMS_t*) 0x40540294UL)
#define CYREG_CANFD1_CH1_NDAT1          ((volatile un_CANFD_CH_NDAT1_t*) 0x40540298UL)
#define CYREG_CANFD1_CH1_NDAT2          ((volatile un_CANFD_CH_NDAT2_t*) 0x4054029CUL)
#define CYREG_CANFD1_CH1_RXF0C          ((volatile un_CANFD_CH_RXF0C_t*) 0x405402A0UL)
#define CYREG_CANFD1_CH1_RXF0S          ((volatile un_CANFD_CH_RXF0S_t*) 0x405402A4UL)
#define CYREG_CANFD1_CH1_RXF0A          ((volatile un_CANFD_CH_RXF0A_t*) 0x405402A8UL)
#define CYREG_CANFD1_CH1_RXBC           ((volatile un_CANFD_CH_RXBC_t*) 0x405402ACUL)
#define CYREG_CANFD1_CH1_RXF1C          ((volatile un_CANFD_CH_RXF1C_t*) 0x405402B0UL)
#define CYREG_CANFD1_CH1_RXF1S          ((volatile un_CANFD_CH_RXF1S_t*) 0x405402B4UL)
#define CYREG_CANFD1_CH1_RXF1A          ((volatile un_CANFD_CH_RXF1A_t*) 0x405402B8UL)
#define CYREG_CANFD1_CH1_RXESC          ((volatile un_CANFD_CH_RXESC_t*) 0x405402BCUL)
#define CYREG_CANFD1_CH1_TXBC           ((volatile un_CANFD_CH_TXBC_t*) 0x405402C0UL)
#define CYREG_CANFD1_CH1_TXFQS          ((volatile un_CANFD_CH_TXFQS_t*) 0x405402C4UL)
#define CYREG_CANFD1_CH1_TXESC          ((volatile un_CANFD_CH_TXESC_t*) 0x405402C8UL)
#define CYREG_CANFD1_CH1_TXBRP          ((volatile un_CANFD_CH_TXBRP_t*) 0x405402CCUL)
#define CYREG_CANFD1_CH1_TXBAR          ((volatile un_CANFD_CH_TXBAR_t*) 0x405402D0UL)
#define CYREG_CANFD1_CH1_TXBCR          ((volatile un_CANFD_CH_TXBCR_t*) 0x405402D4UL)
#define CYREG_CANFD1_CH1_TXBTO          ((volatile un_CANFD_CH_TXBTO_t*) 0x405402D8UL)
#define CYREG_CANFD1_CH1_TXBCF          ((volatile un_CANFD_CH_TXBCF_t*) 0x405402DCUL)
#define CYREG_CANFD1_CH1_TXBTIE         ((volatile un_CANFD_CH_TXBTIE_t*) 0x405402E0UL)
#define CYREG_CANFD1_CH1_TXBCIE         ((volatile un_CANFD_CH_TXBCIE_t*) 0x405402E4UL)
#define CYREG_CANFD1_CH1_TXEFC          ((volatile un_CANFD_CH_TXEFC_t*) 0x405402F0UL)
#define CYREG_CANFD1_CH1_TXEFS          ((volatile un_CANFD_CH_TXEFS_t*) 0x405402F4UL)
#define CYREG_CANFD1_CH1_TXEFA          ((volatile un_CANFD_CH_TXEFA_t*) 0x405402F8UL)
#define CYREG_CANFD1_CH1_TTTMC          ((volatile un_CANFD_CH_TTTMC_t*) 0x40540300UL)
#define CYREG_CANFD1_CH1_TTRMC          ((volatile un_CANFD_CH_TTRMC_t*) 0x40540304UL)
#define CYREG_CANFD1_CH1_TTOCF          ((volatile un_CANFD_CH_TTOCF_t*) 0x40540308UL)
#define CYREG_CANFD1_CH1_TTMLM          ((volatile un_CANFD_CH_TTMLM_t*) 0x4054030CUL)
#define CYREG_CANFD1_CH1_TURCF          ((volatile un_CANFD_CH_TURCF_t*) 0x40540310UL)
#define CYREG_CANFD1_CH1_TTOCN          ((volatile un_CANFD_CH_TTOCN_t*) 0x40540314UL)
#define CYREG_CANFD1_CH1_TTGTP          ((volatile un_CANFD_CH_TTGTP_t*) 0x40540318UL)
#define CYREG_CANFD1_CH1_TTTMK          ((volatile un_CANFD_CH_TTTMK_t*) 0x4054031CUL)
#define CYREG_CANFD1_CH1_TTIR           ((volatile un_CANFD_CH_TTIR_t*) 0x40540320UL)
#define CYREG_CANFD1_CH1_TTIE           ((volatile un_CANFD_CH_TTIE_t*) 0x40540324UL)
#define CYREG_CANFD1_CH1_TTILS          ((volatile un_CANFD_CH_TTILS_t*) 0x40540328UL)
#define CYREG_CANFD1_CH1_TTOST          ((volatile un_CANFD_CH_TTOST_t*) 0x4054032CUL)
#define CYREG_CANFD1_CH1_TURNA          ((volatile un_CANFD_CH_TURNA_t*) 0x40540330UL)
#define CYREG_CANFD1_CH1_TTLGT          ((volatile un_CANFD_CH_TTLGT_t*) 0x40540334UL)
#define CYREG_CANFD1_CH1_TTCTC          ((volatile un_CANFD_CH_TTCTC_t*) 0x40540338UL)
#define CYREG_CANFD1_CH1_TTCPT          ((volatile un_CANFD_CH_TTCPT_t*) 0x4054033CUL)
#define CYREG_CANFD1_CH1_TTCSM          ((volatile un_CANFD_CH_TTCSM_t*) 0x40540340UL)

/**
  * \brief FIFO wrapper around M_TTCAN 3PIP, to enable DMA (CANFD_CH1)
  */
#define CYREG_CANFD1_CH1_RXFTOP_CTL     ((volatile un_CANFD_CH_RXFTOP_CTL_t*) 0x40540380UL)
#define CYREG_CANFD1_CH1_RXFTOP0_STAT   ((volatile un_CANFD_CH_RXFTOP0_STAT_t*) 0x405403A0UL)
#define CYREG_CANFD1_CH1_RXFTOP0_DATA   ((volatile un_CANFD_CH_RXFTOP0_DATA_t*) 0x405403A8UL)
#define CYREG_CANFD1_CH1_RXFTOP1_STAT   ((volatile un_CANFD_CH_RXFTOP1_STAT_t*) 0x405403B0UL)
#define CYREG_CANFD1_CH1_RXFTOP1_DATA   ((volatile un_CANFD_CH_RXFTOP1_DATA_t*) 0x405403B8UL)

/**
  * \brief CAN Controller (CANFD1)
  */
#define CYREG_CANFD1_CTL                ((volatile un_CANFD_CTL_t*) 0x40541000UL)
#define CYREG_CANFD1_STATUS             ((volatile un_CANFD_STATUS_t*) 0x40541004UL)
#define CYREG_CANFD1_INTR0_CAUSE        ((volatile un_CANFD_INTR0_CAUSE_t*) 0x40541010UL)
#define CYREG_CANFD1_INTR1_CAUSE        ((volatile un_CANFD_INTR1_CAUSE_t*) 0x40541014UL)
#define CYREG_CANFD1_ECC_CTL            ((volatile un_CANFD_ECC_CTL_t*) 0x40541080UL)
#define CYREG_CANFD1_ECC_ERR_INJ        ((volatile un_CANFD_ECC_ERR_INJ_t*) 0x40541084UL)

#endif /* _CYREG_CANFD_H_ */


/* [] END OF FILE */
