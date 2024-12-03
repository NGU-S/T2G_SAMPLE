/***************************************************************************//**
* \file cyreg_gpio.h
*
* \brief
* GPIO register definition header
*
* \note
* Generator version: 1.6.0.1229
* Database revision: chip_tviic2d6mddr_pr3_1
*
********************************************************************************
* \copyright
* Copyright 2016-2022, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef _CYREG_GPIO_H_
#define _CYREG_GPIO_H_

#include "cyip_gpio_v5.h"

/**
  * \brief GPIO port registers (GPIO_PRT0)
  */
#define CYREG_GPIO_PRT0_OUT             ((volatile un_GPIO_PRT_OUT_t*) 0x40310000UL)
#define CYREG_GPIO_PRT0_OUT_CLR         ((volatile un_GPIO_PRT_OUT_CLR_t*) 0x40310004UL)
#define CYREG_GPIO_PRT0_OUT_SET         ((volatile un_GPIO_PRT_OUT_SET_t*) 0x40310008UL)
#define CYREG_GPIO_PRT0_OUT_INV         ((volatile un_GPIO_PRT_OUT_INV_t*) 0x4031000CUL)
#define CYREG_GPIO_PRT0_IN              ((volatile un_GPIO_PRT_IN_t*) 0x40310010UL)
#define CYREG_GPIO_PRT0_INTR            ((volatile un_GPIO_PRT_INTR_t*) 0x40310014UL)
#define CYREG_GPIO_PRT0_INTR_MASK       ((volatile un_GPIO_PRT_INTR_MASK_t*) 0x40310018UL)
#define CYREG_GPIO_PRT0_INTR_MASKED     ((volatile un_GPIO_PRT_INTR_MASKED_t*) 0x4031001CUL)
#define CYREG_GPIO_PRT0_INTR_SET        ((volatile un_GPIO_PRT_INTR_SET_t*) 0x40310020UL)
#define CYREG_GPIO_PRT0_INTR_CFG        ((volatile un_GPIO_PRT_INTR_CFG_t*) 0x40310040UL)
#define CYREG_GPIO_PRT0_CFG             ((volatile un_GPIO_PRT_CFG_t*) 0x40310044UL)
#define CYREG_GPIO_PRT0_CFG_IN          ((volatile un_GPIO_PRT_CFG_IN_t*) 0x40310048UL)
#define CYREG_GPIO_PRT0_CFG_OUT         ((volatile un_GPIO_PRT_CFG_OUT_t*) 0x4031004CUL)
#define CYREG_GPIO_PRT0_CFG_IN_AUTOLVL  ((volatile un_GPIO_PRT_CFG_IN_AUTOLVL_t*) 0x40310058UL)

/**
  * \brief GPIO port registers (GPIO_PRT1)
  */
#define CYREG_GPIO_PRT1_OUT             ((volatile un_GPIO_PRT_OUT_t*) 0x40310080UL)
#define CYREG_GPIO_PRT1_OUT_CLR         ((volatile un_GPIO_PRT_OUT_CLR_t*) 0x40310084UL)
#define CYREG_GPIO_PRT1_OUT_SET         ((volatile un_GPIO_PRT_OUT_SET_t*) 0x40310088UL)
#define CYREG_GPIO_PRT1_OUT_INV         ((volatile un_GPIO_PRT_OUT_INV_t*) 0x4031008CUL)
#define CYREG_GPIO_PRT1_IN              ((volatile un_GPIO_PRT_IN_t*) 0x40310090UL)
#define CYREG_GPIO_PRT1_INTR            ((volatile un_GPIO_PRT_INTR_t*) 0x40310094UL)
#define CYREG_GPIO_PRT1_INTR_MASK       ((volatile un_GPIO_PRT_INTR_MASK_t*) 0x40310098UL)
#define CYREG_GPIO_PRT1_INTR_MASKED     ((volatile un_GPIO_PRT_INTR_MASKED_t*) 0x4031009CUL)
#define CYREG_GPIO_PRT1_INTR_SET        ((volatile un_GPIO_PRT_INTR_SET_t*) 0x403100A0UL)
#define CYREG_GPIO_PRT1_INTR_CFG        ((volatile un_GPIO_PRT_INTR_CFG_t*) 0x403100C0UL)
#define CYREG_GPIO_PRT1_CFG             ((volatile un_GPIO_PRT_CFG_t*) 0x403100C4UL)
#define CYREG_GPIO_PRT1_CFG_IN          ((volatile un_GPIO_PRT_CFG_IN_t*) 0x403100C8UL)
#define CYREG_GPIO_PRT1_CFG_OUT         ((volatile un_GPIO_PRT_CFG_OUT_t*) 0x403100CCUL)
#define CYREG_GPIO_PRT1_CFG_IN_AUTOLVL  ((volatile un_GPIO_PRT_CFG_IN_AUTOLVL_t*) 0x403100D8UL)

/**
  * \brief GPIO port registers (GPIO_PRT2)
  */
#define CYREG_GPIO_PRT2_OUT             ((volatile un_GPIO_PRT_OUT_t*) 0x40310100UL)
#define CYREG_GPIO_PRT2_OUT_CLR         ((volatile un_GPIO_PRT_OUT_CLR_t*) 0x40310104UL)
#define CYREG_GPIO_PRT2_OUT_SET         ((volatile un_GPIO_PRT_OUT_SET_t*) 0x40310108UL)
#define CYREG_GPIO_PRT2_OUT_INV         ((volatile un_GPIO_PRT_OUT_INV_t*) 0x4031010CUL)
#define CYREG_GPIO_PRT2_IN              ((volatile un_GPIO_PRT_IN_t*) 0x40310110UL)
#define CYREG_GPIO_PRT2_INTR            ((volatile un_GPIO_PRT_INTR_t*) 0x40310114UL)
#define CYREG_GPIO_PRT2_INTR_MASK       ((volatile un_GPIO_PRT_INTR_MASK_t*) 0x40310118UL)
#define CYREG_GPIO_PRT2_INTR_MASKED     ((volatile un_GPIO_PRT_INTR_MASKED_t*) 0x4031011CUL)
#define CYREG_GPIO_PRT2_INTR_SET        ((volatile un_GPIO_PRT_INTR_SET_t*) 0x40310120UL)
#define CYREG_GPIO_PRT2_INTR_CFG        ((volatile un_GPIO_PRT_INTR_CFG_t*) 0x40310140UL)
#define CYREG_GPIO_PRT2_CFG             ((volatile un_GPIO_PRT_CFG_t*) 0x40310144UL)
#define CYREG_GPIO_PRT2_CFG_IN          ((volatile un_GPIO_PRT_CFG_IN_t*) 0x40310148UL)
#define CYREG_GPIO_PRT2_CFG_OUT         ((volatile un_GPIO_PRT_CFG_OUT_t*) 0x4031014CUL)
#define CYREG_GPIO_PRT2_CFG_IN_AUTOLVL  ((volatile un_GPIO_PRT_CFG_IN_AUTOLVL_t*) 0x40310158UL)

/**
  * \brief GPIO port registers (GPIO_PRT3)
  */
#define CYREG_GPIO_PRT3_OUT             ((volatile un_GPIO_PRT_OUT_t*) 0x40310180UL)
#define CYREG_GPIO_PRT3_OUT_CLR         ((volatile un_GPIO_PRT_OUT_CLR_t*) 0x40310184UL)
#define CYREG_GPIO_PRT3_OUT_SET         ((volatile un_GPIO_PRT_OUT_SET_t*) 0x40310188UL)
#define CYREG_GPIO_PRT3_OUT_INV         ((volatile un_GPIO_PRT_OUT_INV_t*) 0x4031018CUL)
#define CYREG_GPIO_PRT3_IN              ((volatile un_GPIO_PRT_IN_t*) 0x40310190UL)
#define CYREG_GPIO_PRT3_INTR            ((volatile un_GPIO_PRT_INTR_t*) 0x40310194UL)
#define CYREG_GPIO_PRT3_INTR_MASK       ((volatile un_GPIO_PRT_INTR_MASK_t*) 0x40310198UL)
#define CYREG_GPIO_PRT3_INTR_MASKED     ((volatile un_GPIO_PRT_INTR_MASKED_t*) 0x4031019CUL)
#define CYREG_GPIO_PRT3_INTR_SET        ((volatile un_GPIO_PRT_INTR_SET_t*) 0x403101A0UL)
#define CYREG_GPIO_PRT3_INTR_CFG        ((volatile un_GPIO_PRT_INTR_CFG_t*) 0x403101C0UL)
#define CYREG_GPIO_PRT3_CFG             ((volatile un_GPIO_PRT_CFG_t*) 0x403101C4UL)
#define CYREG_GPIO_PRT3_CFG_IN          ((volatile un_GPIO_PRT_CFG_IN_t*) 0x403101C8UL)
#define CYREG_GPIO_PRT3_CFG_OUT         ((volatile un_GPIO_PRT_CFG_OUT_t*) 0x403101CCUL)
#define CYREG_GPIO_PRT3_CFG_IN_AUTOLVL  ((volatile un_GPIO_PRT_CFG_IN_AUTOLVL_t*) 0x403101D8UL)

/**
  * \brief GPIO port registers (GPIO_PRT4)
  */
#define CYREG_GPIO_PRT4_OUT             ((volatile un_GPIO_PRT_OUT_t*) 0x40310200UL)
#define CYREG_GPIO_PRT4_OUT_CLR         ((volatile un_GPIO_PRT_OUT_CLR_t*) 0x40310204UL)
#define CYREG_GPIO_PRT4_OUT_SET         ((volatile un_GPIO_PRT_OUT_SET_t*) 0x40310208UL)
#define CYREG_GPIO_PRT4_OUT_INV         ((volatile un_GPIO_PRT_OUT_INV_t*) 0x4031020CUL)
#define CYREG_GPIO_PRT4_IN              ((volatile un_GPIO_PRT_IN_t*) 0x40310210UL)
#define CYREG_GPIO_PRT4_INTR            ((volatile un_GPIO_PRT_INTR_t*) 0x40310214UL)
#define CYREG_GPIO_PRT4_INTR_MASK       ((volatile un_GPIO_PRT_INTR_MASK_t*) 0x40310218UL)
#define CYREG_GPIO_PRT4_INTR_MASKED     ((volatile un_GPIO_PRT_INTR_MASKED_t*) 0x4031021CUL)
#define CYREG_GPIO_PRT4_INTR_SET        ((volatile un_GPIO_PRT_INTR_SET_t*) 0x40310220UL)
#define CYREG_GPIO_PRT4_INTR_CFG        ((volatile un_GPIO_PRT_INTR_CFG_t*) 0x40310240UL)
#define CYREG_GPIO_PRT4_CFG             ((volatile un_GPIO_PRT_CFG_t*) 0x40310244UL)
#define CYREG_GPIO_PRT4_CFG_IN          ((volatile un_GPIO_PRT_CFG_IN_t*) 0x40310248UL)
#define CYREG_GPIO_PRT4_CFG_OUT         ((volatile un_GPIO_PRT_CFG_OUT_t*) 0x4031024CUL)
#define CYREG_GPIO_PRT4_CFG_IN_AUTOLVL  ((volatile un_GPIO_PRT_CFG_IN_AUTOLVL_t*) 0x40310258UL)

/**
  * \brief GPIO port registers (GPIO_PRT5)
  */
#define CYREG_GPIO_PRT5_OUT             ((volatile un_GPIO_PRT_OUT_t*) 0x40310280UL)
#define CYREG_GPIO_PRT5_OUT_CLR         ((volatile un_GPIO_PRT_OUT_CLR_t*) 0x40310284UL)
#define CYREG_GPIO_PRT5_OUT_SET         ((volatile un_GPIO_PRT_OUT_SET_t*) 0x40310288UL)
#define CYREG_GPIO_PRT5_OUT_INV         ((volatile un_GPIO_PRT_OUT_INV_t*) 0x4031028CUL)
#define CYREG_GPIO_PRT5_IN              ((volatile un_GPIO_PRT_IN_t*) 0x40310290UL)
#define CYREG_GPIO_PRT5_INTR            ((volatile un_GPIO_PRT_INTR_t*) 0x40310294UL)
#define CYREG_GPIO_PRT5_INTR_MASK       ((volatile un_GPIO_PRT_INTR_MASK_t*) 0x40310298UL)
#define CYREG_GPIO_PRT5_INTR_MASKED     ((volatile un_GPIO_PRT_INTR_MASKED_t*) 0x4031029CUL)
#define CYREG_GPIO_PRT5_INTR_SET        ((volatile un_GPIO_PRT_INTR_SET_t*) 0x403102A0UL)
#define CYREG_GPIO_PRT5_INTR_CFG        ((volatile un_GPIO_PRT_INTR_CFG_t*) 0x403102C0UL)
#define CYREG_GPIO_PRT5_CFG             ((volatile un_GPIO_PRT_CFG_t*) 0x403102C4UL)
#define CYREG_GPIO_PRT5_CFG_IN          ((volatile un_GPIO_PRT_CFG_IN_t*) 0x403102C8UL)
#define CYREG_GPIO_PRT5_CFG_OUT         ((volatile un_GPIO_PRT_CFG_OUT_t*) 0x403102CCUL)
#define CYREG_GPIO_PRT5_CFG_IN_AUTOLVL  ((volatile un_GPIO_PRT_CFG_IN_AUTOLVL_t*) 0x403102D8UL)

/**
  * \brief GPIO port registers (GPIO_PRT6)
  */
#define CYREG_GPIO_PRT6_OUT             ((volatile un_GPIO_PRT_OUT_t*) 0x40310300UL)
#define CYREG_GPIO_PRT6_OUT_CLR         ((volatile un_GPIO_PRT_OUT_CLR_t*) 0x40310304UL)
#define CYREG_GPIO_PRT6_OUT_SET         ((volatile un_GPIO_PRT_OUT_SET_t*) 0x40310308UL)
#define CYREG_GPIO_PRT6_OUT_INV         ((volatile un_GPIO_PRT_OUT_INV_t*) 0x4031030CUL)
#define CYREG_GPIO_PRT6_IN              ((volatile un_GPIO_PRT_IN_t*) 0x40310310UL)
#define CYREG_GPIO_PRT6_INTR            ((volatile un_GPIO_PRT_INTR_t*) 0x40310314UL)
#define CYREG_GPIO_PRT6_INTR_MASK       ((volatile un_GPIO_PRT_INTR_MASK_t*) 0x40310318UL)
#define CYREG_GPIO_PRT6_INTR_MASKED     ((volatile un_GPIO_PRT_INTR_MASKED_t*) 0x4031031CUL)
#define CYREG_GPIO_PRT6_INTR_SET        ((volatile un_GPIO_PRT_INTR_SET_t*) 0x40310320UL)
#define CYREG_GPIO_PRT6_INTR_CFG        ((volatile un_GPIO_PRT_INTR_CFG_t*) 0x40310340UL)
#define CYREG_GPIO_PRT6_CFG             ((volatile un_GPIO_PRT_CFG_t*) 0x40310344UL)
#define CYREG_GPIO_PRT6_CFG_IN          ((volatile un_GPIO_PRT_CFG_IN_t*) 0x40310348UL)
#define CYREG_GPIO_PRT6_CFG_OUT         ((volatile un_GPIO_PRT_CFG_OUT_t*) 0x4031034CUL)
#define CYREG_GPIO_PRT6_CFG_IN_AUTOLVL  ((volatile un_GPIO_PRT_CFG_IN_AUTOLVL_t*) 0x40310358UL)

/**
  * \brief GPIO port registers (GPIO_PRT7)
  */
#define CYREG_GPIO_PRT7_OUT             ((volatile un_GPIO_PRT_OUT_t*) 0x40310380UL)
#define CYREG_GPIO_PRT7_OUT_CLR         ((volatile un_GPIO_PRT_OUT_CLR_t*) 0x40310384UL)
#define CYREG_GPIO_PRT7_OUT_SET         ((volatile un_GPIO_PRT_OUT_SET_t*) 0x40310388UL)
#define CYREG_GPIO_PRT7_OUT_INV         ((volatile un_GPIO_PRT_OUT_INV_t*) 0x4031038CUL)
#define CYREG_GPIO_PRT7_IN              ((volatile un_GPIO_PRT_IN_t*) 0x40310390UL)
#define CYREG_GPIO_PRT7_INTR            ((volatile un_GPIO_PRT_INTR_t*) 0x40310394UL)
#define CYREG_GPIO_PRT7_INTR_MASK       ((volatile un_GPIO_PRT_INTR_MASK_t*) 0x40310398UL)
#define CYREG_GPIO_PRT7_INTR_MASKED     ((volatile un_GPIO_PRT_INTR_MASKED_t*) 0x4031039CUL)
#define CYREG_GPIO_PRT7_INTR_SET        ((volatile un_GPIO_PRT_INTR_SET_t*) 0x403103A0UL)
#define CYREG_GPIO_PRT7_INTR_CFG        ((volatile un_GPIO_PRT_INTR_CFG_t*) 0x403103C0UL)
#define CYREG_GPIO_PRT7_CFG             ((volatile un_GPIO_PRT_CFG_t*) 0x403103C4UL)
#define CYREG_GPIO_PRT7_CFG_IN          ((volatile un_GPIO_PRT_CFG_IN_t*) 0x403103C8UL)
#define CYREG_GPIO_PRT7_CFG_OUT         ((volatile un_GPIO_PRT_CFG_OUT_t*) 0x403103CCUL)
#define CYREG_GPIO_PRT7_CFG_IN_AUTOLVL  ((volatile un_GPIO_PRT_CFG_IN_AUTOLVL_t*) 0x403103D8UL)

/**
  * \brief GPIO port registers (GPIO_PRT8)
  */
#define CYREG_GPIO_PRT8_OUT             ((volatile un_GPIO_PRT_OUT_t*) 0x40310400UL)
#define CYREG_GPIO_PRT8_OUT_CLR         ((volatile un_GPIO_PRT_OUT_CLR_t*) 0x40310404UL)
#define CYREG_GPIO_PRT8_OUT_SET         ((volatile un_GPIO_PRT_OUT_SET_t*) 0x40310408UL)
#define CYREG_GPIO_PRT8_OUT_INV         ((volatile un_GPIO_PRT_OUT_INV_t*) 0x4031040CUL)
#define CYREG_GPIO_PRT8_IN              ((volatile un_GPIO_PRT_IN_t*) 0x40310410UL)
#define CYREG_GPIO_PRT8_INTR            ((volatile un_GPIO_PRT_INTR_t*) 0x40310414UL)
#define CYREG_GPIO_PRT8_INTR_MASK       ((volatile un_GPIO_PRT_INTR_MASK_t*) 0x40310418UL)
#define CYREG_GPIO_PRT8_INTR_MASKED     ((volatile un_GPIO_PRT_INTR_MASKED_t*) 0x4031041CUL)
#define CYREG_GPIO_PRT8_INTR_SET        ((volatile un_GPIO_PRT_INTR_SET_t*) 0x40310420UL)
#define CYREG_GPIO_PRT8_INTR_CFG        ((volatile un_GPIO_PRT_INTR_CFG_t*) 0x40310440UL)
#define CYREG_GPIO_PRT8_CFG             ((volatile un_GPIO_PRT_CFG_t*) 0x40310444UL)
#define CYREG_GPIO_PRT8_CFG_IN          ((volatile un_GPIO_PRT_CFG_IN_t*) 0x40310448UL)
#define CYREG_GPIO_PRT8_CFG_OUT         ((volatile un_GPIO_PRT_CFG_OUT_t*) 0x4031044CUL)
#define CYREG_GPIO_PRT8_CFG_IN_AUTOLVL  ((volatile un_GPIO_PRT_CFG_IN_AUTOLVL_t*) 0x40310458UL)

/**
  * \brief GPIO port registers (GPIO_PRT9)
  */
#define CYREG_GPIO_PRT9_OUT             ((volatile un_GPIO_PRT_OUT_t*) 0x40310480UL)
#define CYREG_GPIO_PRT9_OUT_CLR         ((volatile un_GPIO_PRT_OUT_CLR_t*) 0x40310484UL)
#define CYREG_GPIO_PRT9_OUT_SET         ((volatile un_GPIO_PRT_OUT_SET_t*) 0x40310488UL)
#define CYREG_GPIO_PRT9_OUT_INV         ((volatile un_GPIO_PRT_OUT_INV_t*) 0x4031048CUL)
#define CYREG_GPIO_PRT9_IN              ((volatile un_GPIO_PRT_IN_t*) 0x40310490UL)
#define CYREG_GPIO_PRT9_INTR            ((volatile un_GPIO_PRT_INTR_t*) 0x40310494UL)
#define CYREG_GPIO_PRT9_INTR_MASK       ((volatile un_GPIO_PRT_INTR_MASK_t*) 0x40310498UL)
#define CYREG_GPIO_PRT9_INTR_MASKED     ((volatile un_GPIO_PRT_INTR_MASKED_t*) 0x4031049CUL)
#define CYREG_GPIO_PRT9_INTR_SET        ((volatile un_GPIO_PRT_INTR_SET_t*) 0x403104A0UL)
#define CYREG_GPIO_PRT9_INTR_CFG        ((volatile un_GPIO_PRT_INTR_CFG_t*) 0x403104C0UL)
#define CYREG_GPIO_PRT9_CFG             ((volatile un_GPIO_PRT_CFG_t*) 0x403104C4UL)
#define CYREG_GPIO_PRT9_CFG_IN          ((volatile un_GPIO_PRT_CFG_IN_t*) 0x403104C8UL)
#define CYREG_GPIO_PRT9_CFG_OUT         ((volatile un_GPIO_PRT_CFG_OUT_t*) 0x403104CCUL)
#define CYREG_GPIO_PRT9_CFG_IN_AUTOLVL  ((volatile un_GPIO_PRT_CFG_IN_AUTOLVL_t*) 0x403104D8UL)

/**
  * \brief GPIO port registers (GPIO_PRT10)
  */
#define CYREG_GPIO_PRT10_OUT            ((volatile un_GPIO_PRT_OUT_t*) 0x40310500UL)
#define CYREG_GPIO_PRT10_OUT_CLR        ((volatile un_GPIO_PRT_OUT_CLR_t*) 0x40310504UL)
#define CYREG_GPIO_PRT10_OUT_SET        ((volatile un_GPIO_PRT_OUT_SET_t*) 0x40310508UL)
#define CYREG_GPIO_PRT10_OUT_INV        ((volatile un_GPIO_PRT_OUT_INV_t*) 0x4031050CUL)
#define CYREG_GPIO_PRT10_IN             ((volatile un_GPIO_PRT_IN_t*) 0x40310510UL)
#define CYREG_GPIO_PRT10_INTR           ((volatile un_GPIO_PRT_INTR_t*) 0x40310514UL)
#define CYREG_GPIO_PRT10_INTR_MASK      ((volatile un_GPIO_PRT_INTR_MASK_t*) 0x40310518UL)
#define CYREG_GPIO_PRT10_INTR_MASKED    ((volatile un_GPIO_PRT_INTR_MASKED_t*) 0x4031051CUL)
#define CYREG_GPIO_PRT10_INTR_SET       ((volatile un_GPIO_PRT_INTR_SET_t*) 0x40310520UL)
#define CYREG_GPIO_PRT10_INTR_CFG       ((volatile un_GPIO_PRT_INTR_CFG_t*) 0x40310540UL)
#define CYREG_GPIO_PRT10_CFG            ((volatile un_GPIO_PRT_CFG_t*) 0x40310544UL)
#define CYREG_GPIO_PRT10_CFG_IN         ((volatile un_GPIO_PRT_CFG_IN_t*) 0x40310548UL)
#define CYREG_GPIO_PRT10_CFG_OUT        ((volatile un_GPIO_PRT_CFG_OUT_t*) 0x4031054CUL)
#define CYREG_GPIO_PRT10_CFG_IN_AUTOLVL ((volatile un_GPIO_PRT_CFG_IN_AUTOLVL_t*) 0x40310558UL)

/**
  * \brief GPIO port registers (GPIO_PRT11)
  */
#define CYREG_GPIO_PRT11_OUT            ((volatile un_GPIO_PRT_OUT_t*) 0x40310580UL)
#define CYREG_GPIO_PRT11_OUT_CLR        ((volatile un_GPIO_PRT_OUT_CLR_t*) 0x40310584UL)
#define CYREG_GPIO_PRT11_OUT_SET        ((volatile un_GPIO_PRT_OUT_SET_t*) 0x40310588UL)
#define CYREG_GPIO_PRT11_OUT_INV        ((volatile un_GPIO_PRT_OUT_INV_t*) 0x4031058CUL)
#define CYREG_GPIO_PRT11_IN             ((volatile un_GPIO_PRT_IN_t*) 0x40310590UL)
#define CYREG_GPIO_PRT11_INTR           ((volatile un_GPIO_PRT_INTR_t*) 0x40310594UL)
#define CYREG_GPIO_PRT11_INTR_MASK      ((volatile un_GPIO_PRT_INTR_MASK_t*) 0x40310598UL)
#define CYREG_GPIO_PRT11_INTR_MASKED    ((volatile un_GPIO_PRT_INTR_MASKED_t*) 0x4031059CUL)
#define CYREG_GPIO_PRT11_INTR_SET       ((volatile un_GPIO_PRT_INTR_SET_t*) 0x403105A0UL)
#define CYREG_GPIO_PRT11_INTR_CFG       ((volatile un_GPIO_PRT_INTR_CFG_t*) 0x403105C0UL)
#define CYREG_GPIO_PRT11_CFG            ((volatile un_GPIO_PRT_CFG_t*) 0x403105C4UL)
#define CYREG_GPIO_PRT11_CFG_IN         ((volatile un_GPIO_PRT_CFG_IN_t*) 0x403105C8UL)
#define CYREG_GPIO_PRT11_CFG_OUT        ((volatile un_GPIO_PRT_CFG_OUT_t*) 0x403105CCUL)
#define CYREG_GPIO_PRT11_CFG_IN_AUTOLVL ((volatile un_GPIO_PRT_CFG_IN_AUTOLVL_t*) 0x403105D8UL)

/**
  * \brief GPIO port registers (GPIO_PRT12)
  */
#define CYREG_GPIO_PRT12_OUT            ((volatile un_GPIO_PRT_OUT_t*) 0x40310600UL)
#define CYREG_GPIO_PRT12_OUT_CLR        ((volatile un_GPIO_PRT_OUT_CLR_t*) 0x40310604UL)
#define CYREG_GPIO_PRT12_OUT_SET        ((volatile un_GPIO_PRT_OUT_SET_t*) 0x40310608UL)
#define CYREG_GPIO_PRT12_OUT_INV        ((volatile un_GPIO_PRT_OUT_INV_t*) 0x4031060CUL)
#define CYREG_GPIO_PRT12_IN             ((volatile un_GPIO_PRT_IN_t*) 0x40310610UL)
#define CYREG_GPIO_PRT12_INTR           ((volatile un_GPIO_PRT_INTR_t*) 0x40310614UL)
#define CYREG_GPIO_PRT12_INTR_MASK      ((volatile un_GPIO_PRT_INTR_MASK_t*) 0x40310618UL)
#define CYREG_GPIO_PRT12_INTR_MASKED    ((volatile un_GPIO_PRT_INTR_MASKED_t*) 0x4031061CUL)
#define CYREG_GPIO_PRT12_INTR_SET       ((volatile un_GPIO_PRT_INTR_SET_t*) 0x40310620UL)
#define CYREG_GPIO_PRT12_INTR_CFG       ((volatile un_GPIO_PRT_INTR_CFG_t*) 0x40310640UL)
#define CYREG_GPIO_PRT12_CFG            ((volatile un_GPIO_PRT_CFG_t*) 0x40310644UL)
#define CYREG_GPIO_PRT12_CFG_IN         ((volatile un_GPIO_PRT_CFG_IN_t*) 0x40310648UL)
#define CYREG_GPIO_PRT12_CFG_OUT        ((volatile un_GPIO_PRT_CFG_OUT_t*) 0x4031064CUL)
#define CYREG_GPIO_PRT12_CFG_IN_AUTOLVL ((volatile un_GPIO_PRT_CFG_IN_AUTOLVL_t*) 0x40310658UL)

/**
  * \brief GPIO port registers (GPIO_PRT13)
  */
#define CYREG_GPIO_PRT13_OUT            ((volatile un_GPIO_PRT_OUT_t*) 0x40310680UL)
#define CYREG_GPIO_PRT13_OUT_CLR        ((volatile un_GPIO_PRT_OUT_CLR_t*) 0x40310684UL)
#define CYREG_GPIO_PRT13_OUT_SET        ((volatile un_GPIO_PRT_OUT_SET_t*) 0x40310688UL)
#define CYREG_GPIO_PRT13_OUT_INV        ((volatile un_GPIO_PRT_OUT_INV_t*) 0x4031068CUL)
#define CYREG_GPIO_PRT13_IN             ((volatile un_GPIO_PRT_IN_t*) 0x40310690UL)
#define CYREG_GPIO_PRT13_INTR           ((volatile un_GPIO_PRT_INTR_t*) 0x40310694UL)
#define CYREG_GPIO_PRT13_INTR_MASK      ((volatile un_GPIO_PRT_INTR_MASK_t*) 0x40310698UL)
#define CYREG_GPIO_PRT13_INTR_MASKED    ((volatile un_GPIO_PRT_INTR_MASKED_t*) 0x4031069CUL)
#define CYREG_GPIO_PRT13_INTR_SET       ((volatile un_GPIO_PRT_INTR_SET_t*) 0x403106A0UL)
#define CYREG_GPIO_PRT13_INTR_CFG       ((volatile un_GPIO_PRT_INTR_CFG_t*) 0x403106C0UL)
#define CYREG_GPIO_PRT13_CFG            ((volatile un_GPIO_PRT_CFG_t*) 0x403106C4UL)
#define CYREG_GPIO_PRT13_CFG_IN         ((volatile un_GPIO_PRT_CFG_IN_t*) 0x403106C8UL)
#define CYREG_GPIO_PRT13_CFG_OUT        ((volatile un_GPIO_PRT_CFG_OUT_t*) 0x403106CCUL)
#define CYREG_GPIO_PRT13_CFG_IN_AUTOLVL ((volatile un_GPIO_PRT_CFG_IN_AUTOLVL_t*) 0x403106D8UL)

/**
  * \brief GPIO port registers (GPIO_PRT14)
  */
#define CYREG_GPIO_PRT14_OUT            ((volatile un_GPIO_PRT_OUT_t*) 0x40310700UL)
#define CYREG_GPIO_PRT14_OUT_CLR        ((volatile un_GPIO_PRT_OUT_CLR_t*) 0x40310704UL)
#define CYREG_GPIO_PRT14_OUT_SET        ((volatile un_GPIO_PRT_OUT_SET_t*) 0x40310708UL)
#define CYREG_GPIO_PRT14_OUT_INV        ((volatile un_GPIO_PRT_OUT_INV_t*) 0x4031070CUL)
#define CYREG_GPIO_PRT14_IN             ((volatile un_GPIO_PRT_IN_t*) 0x40310710UL)
#define CYREG_GPIO_PRT14_INTR           ((volatile un_GPIO_PRT_INTR_t*) 0x40310714UL)
#define CYREG_GPIO_PRT14_INTR_MASK      ((volatile un_GPIO_PRT_INTR_MASK_t*) 0x40310718UL)
#define CYREG_GPIO_PRT14_INTR_MASKED    ((volatile un_GPIO_PRT_INTR_MASKED_t*) 0x4031071CUL)
#define CYREG_GPIO_PRT14_INTR_SET       ((volatile un_GPIO_PRT_INTR_SET_t*) 0x40310720UL)
#define CYREG_GPIO_PRT14_INTR_CFG       ((volatile un_GPIO_PRT_INTR_CFG_t*) 0x40310740UL)
#define CYREG_GPIO_PRT14_CFG            ((volatile un_GPIO_PRT_CFG_t*) 0x40310744UL)
#define CYREG_GPIO_PRT14_CFG_IN         ((volatile un_GPIO_PRT_CFG_IN_t*) 0x40310748UL)
#define CYREG_GPIO_PRT14_CFG_OUT        ((volatile un_GPIO_PRT_CFG_OUT_t*) 0x4031074CUL)
#define CYREG_GPIO_PRT14_CFG_IN_AUTOLVL ((volatile un_GPIO_PRT_CFG_IN_AUTOLVL_t*) 0x40310758UL)
#define CYREG_GPIO_PRT14_CFG_OUT2       ((volatile un_GPIO_PRT_CFG_OUT2_t*) 0x40310760UL)
#define CYREG_GPIO_PRT14_CFG_SLEW_EXT   ((volatile un_GPIO_PRT_CFG_SLEW_EXT_t*) 0x40310764UL)

/**
  * \brief GPIO port registers (GPIO_PRT15)
  */
#define CYREG_GPIO_PRT15_OUT            ((volatile un_GPIO_PRT_OUT_t*) 0x40310780UL)
#define CYREG_GPIO_PRT15_OUT_CLR        ((volatile un_GPIO_PRT_OUT_CLR_t*) 0x40310784UL)
#define CYREG_GPIO_PRT15_OUT_SET        ((volatile un_GPIO_PRT_OUT_SET_t*) 0x40310788UL)
#define CYREG_GPIO_PRT15_OUT_INV        ((volatile un_GPIO_PRT_OUT_INV_t*) 0x4031078CUL)
#define CYREG_GPIO_PRT15_IN             ((volatile un_GPIO_PRT_IN_t*) 0x40310790UL)
#define CYREG_GPIO_PRT15_INTR           ((volatile un_GPIO_PRT_INTR_t*) 0x40310794UL)
#define CYREG_GPIO_PRT15_INTR_MASK      ((volatile un_GPIO_PRT_INTR_MASK_t*) 0x40310798UL)
#define CYREG_GPIO_PRT15_INTR_MASKED    ((volatile un_GPIO_PRT_INTR_MASKED_t*) 0x4031079CUL)
#define CYREG_GPIO_PRT15_INTR_SET       ((volatile un_GPIO_PRT_INTR_SET_t*) 0x403107A0UL)
#define CYREG_GPIO_PRT15_INTR_CFG       ((volatile un_GPIO_PRT_INTR_CFG_t*) 0x403107C0UL)
#define CYREG_GPIO_PRT15_CFG            ((volatile un_GPIO_PRT_CFG_t*) 0x403107C4UL)
#define CYREG_GPIO_PRT15_CFG_IN         ((volatile un_GPIO_PRT_CFG_IN_t*) 0x403107C8UL)
#define CYREG_GPIO_PRT15_CFG_OUT        ((volatile un_GPIO_PRT_CFG_OUT_t*) 0x403107CCUL)
#define CYREG_GPIO_PRT15_CFG_IN_AUTOLVL ((volatile un_GPIO_PRT_CFG_IN_AUTOLVL_t*) 0x403107D8UL)
#define CYREG_GPIO_PRT15_CFG_OUT2       ((volatile un_GPIO_PRT_CFG_OUT2_t*) 0x403107E0UL)
#define CYREG_GPIO_PRT15_CFG_SLEW_EXT   ((volatile un_GPIO_PRT_CFG_SLEW_EXT_t*) 0x403107E4UL)

/**
  * \brief GPIO port registers (GPIO_PRT16)
  */
#define CYREG_GPIO_PRT16_OUT            ((volatile un_GPIO_PRT_OUT_t*) 0x40310800UL)
#define CYREG_GPIO_PRT16_OUT_CLR        ((volatile un_GPIO_PRT_OUT_CLR_t*) 0x40310804UL)
#define CYREG_GPIO_PRT16_OUT_SET        ((volatile un_GPIO_PRT_OUT_SET_t*) 0x40310808UL)
#define CYREG_GPIO_PRT16_OUT_INV        ((volatile un_GPIO_PRT_OUT_INV_t*) 0x4031080CUL)
#define CYREG_GPIO_PRT16_IN             ((volatile un_GPIO_PRT_IN_t*) 0x40310810UL)
#define CYREG_GPIO_PRT16_INTR           ((volatile un_GPIO_PRT_INTR_t*) 0x40310814UL)
#define CYREG_GPIO_PRT16_INTR_MASK      ((volatile un_GPIO_PRT_INTR_MASK_t*) 0x40310818UL)
#define CYREG_GPIO_PRT16_INTR_MASKED    ((volatile un_GPIO_PRT_INTR_MASKED_t*) 0x4031081CUL)
#define CYREG_GPIO_PRT16_INTR_SET       ((volatile un_GPIO_PRT_INTR_SET_t*) 0x40310820UL)
#define CYREG_GPIO_PRT16_INTR_CFG       ((volatile un_GPIO_PRT_INTR_CFG_t*) 0x40310840UL)
#define CYREG_GPIO_PRT16_CFG            ((volatile un_GPIO_PRT_CFG_t*) 0x40310844UL)
#define CYREG_GPIO_PRT16_CFG_IN         ((volatile un_GPIO_PRT_CFG_IN_t*) 0x40310848UL)
#define CYREG_GPIO_PRT16_CFG_OUT        ((volatile un_GPIO_PRT_CFG_OUT_t*) 0x4031084CUL)
#define CYREG_GPIO_PRT16_CFG_IN_AUTOLVL ((volatile un_GPIO_PRT_CFG_IN_AUTOLVL_t*) 0x40310858UL)
#define CYREG_GPIO_PRT16_CFG_OUT2       ((volatile un_GPIO_PRT_CFG_OUT2_t*) 0x40310860UL)
#define CYREG_GPIO_PRT16_CFG_SLEW_EXT   ((volatile un_GPIO_PRT_CFG_SLEW_EXT_t*) 0x40310864UL)

/**
  * \brief GPIO port registers (GPIO_PRT17)
  */
#define CYREG_GPIO_PRT17_OUT            ((volatile un_GPIO_PRT_OUT_t*) 0x40310880UL)
#define CYREG_GPIO_PRT17_OUT_CLR        ((volatile un_GPIO_PRT_OUT_CLR_t*) 0x40310884UL)
#define CYREG_GPIO_PRT17_OUT_SET        ((volatile un_GPIO_PRT_OUT_SET_t*) 0x40310888UL)
#define CYREG_GPIO_PRT17_OUT_INV        ((volatile un_GPIO_PRT_OUT_INV_t*) 0x4031088CUL)
#define CYREG_GPIO_PRT17_IN             ((volatile un_GPIO_PRT_IN_t*) 0x40310890UL)
#define CYREG_GPIO_PRT17_INTR           ((volatile un_GPIO_PRT_INTR_t*) 0x40310894UL)
#define CYREG_GPIO_PRT17_INTR_MASK      ((volatile un_GPIO_PRT_INTR_MASK_t*) 0x40310898UL)
#define CYREG_GPIO_PRT17_INTR_MASKED    ((volatile un_GPIO_PRT_INTR_MASKED_t*) 0x4031089CUL)
#define CYREG_GPIO_PRT17_INTR_SET       ((volatile un_GPIO_PRT_INTR_SET_t*) 0x403108A0UL)
#define CYREG_GPIO_PRT17_INTR_CFG       ((volatile un_GPIO_PRT_INTR_CFG_t*) 0x403108C0UL)
#define CYREG_GPIO_PRT17_CFG            ((volatile un_GPIO_PRT_CFG_t*) 0x403108C4UL)
#define CYREG_GPIO_PRT17_CFG_IN         ((volatile un_GPIO_PRT_CFG_IN_t*) 0x403108C8UL)
#define CYREG_GPIO_PRT17_CFG_OUT        ((volatile un_GPIO_PRT_CFG_OUT_t*) 0x403108CCUL)
#define CYREG_GPIO_PRT17_CFG_IN_AUTOLVL ((volatile un_GPIO_PRT_CFG_IN_AUTOLVL_t*) 0x403108D8UL)
#define CYREG_GPIO_PRT17_CFG_OUT2       ((volatile un_GPIO_PRT_CFG_OUT2_t*) 0x403108E0UL)
#define CYREG_GPIO_PRT17_CFG_SLEW_EXT   ((volatile un_GPIO_PRT_CFG_SLEW_EXT_t*) 0x403108E4UL)

/**
  * \brief GPIO port registers (GPIO_PRT18)
  */
#define CYREG_GPIO_PRT18_OUT            ((volatile un_GPIO_PRT_OUT_t*) 0x40310900UL)
#define CYREG_GPIO_PRT18_OUT_CLR        ((volatile un_GPIO_PRT_OUT_CLR_t*) 0x40310904UL)
#define CYREG_GPIO_PRT18_OUT_SET        ((volatile un_GPIO_PRT_OUT_SET_t*) 0x40310908UL)
#define CYREG_GPIO_PRT18_OUT_INV        ((volatile un_GPIO_PRT_OUT_INV_t*) 0x4031090CUL)
#define CYREG_GPIO_PRT18_IN             ((volatile un_GPIO_PRT_IN_t*) 0x40310910UL)
#define CYREG_GPIO_PRT18_INTR           ((volatile un_GPIO_PRT_INTR_t*) 0x40310914UL)
#define CYREG_GPIO_PRT18_INTR_MASK      ((volatile un_GPIO_PRT_INTR_MASK_t*) 0x40310918UL)
#define CYREG_GPIO_PRT18_INTR_MASKED    ((volatile un_GPIO_PRT_INTR_MASKED_t*) 0x4031091CUL)
#define CYREG_GPIO_PRT18_INTR_SET       ((volatile un_GPIO_PRT_INTR_SET_t*) 0x40310920UL)
#define CYREG_GPIO_PRT18_INTR_CFG       ((volatile un_GPIO_PRT_INTR_CFG_t*) 0x40310940UL)
#define CYREG_GPIO_PRT18_CFG            ((volatile un_GPIO_PRT_CFG_t*) 0x40310944UL)
#define CYREG_GPIO_PRT18_CFG_IN         ((volatile un_GPIO_PRT_CFG_IN_t*) 0x40310948UL)
#define CYREG_GPIO_PRT18_CFG_OUT        ((volatile un_GPIO_PRT_CFG_OUT_t*) 0x4031094CUL)
#define CYREG_GPIO_PRT18_CFG_IN_AUTOLVL ((volatile un_GPIO_PRT_CFG_IN_AUTOLVL_t*) 0x40310958UL)
#define CYREG_GPIO_PRT18_CFG_OUT2       ((volatile un_GPIO_PRT_CFG_OUT2_t*) 0x40310960UL)
#define CYREG_GPIO_PRT18_CFG_SLEW_EXT   ((volatile un_GPIO_PRT_CFG_SLEW_EXT_t*) 0x40310964UL)

/**
  * \brief GPIO port registers (GPIO_PRT19)
  */
#define CYREG_GPIO_PRT19_OUT            ((volatile un_GPIO_PRT_OUT_t*) 0x40310980UL)
#define CYREG_GPIO_PRT19_OUT_CLR        ((volatile un_GPIO_PRT_OUT_CLR_t*) 0x40310984UL)
#define CYREG_GPIO_PRT19_OUT_SET        ((volatile un_GPIO_PRT_OUT_SET_t*) 0x40310988UL)
#define CYREG_GPIO_PRT19_OUT_INV        ((volatile un_GPIO_PRT_OUT_INV_t*) 0x4031098CUL)
#define CYREG_GPIO_PRT19_IN             ((volatile un_GPIO_PRT_IN_t*) 0x40310990UL)
#define CYREG_GPIO_PRT19_INTR           ((volatile un_GPIO_PRT_INTR_t*) 0x40310994UL)
#define CYREG_GPIO_PRT19_INTR_MASK      ((volatile un_GPIO_PRT_INTR_MASK_t*) 0x40310998UL)
#define CYREG_GPIO_PRT19_INTR_MASKED    ((volatile un_GPIO_PRT_INTR_MASKED_t*) 0x4031099CUL)
#define CYREG_GPIO_PRT19_INTR_SET       ((volatile un_GPIO_PRT_INTR_SET_t*) 0x403109A0UL)
#define CYREG_GPIO_PRT19_INTR_CFG       ((volatile un_GPIO_PRT_INTR_CFG_t*) 0x403109C0UL)
#define CYREG_GPIO_PRT19_CFG            ((volatile un_GPIO_PRT_CFG_t*) 0x403109C4UL)
#define CYREG_GPIO_PRT19_CFG_IN         ((volatile un_GPIO_PRT_CFG_IN_t*) 0x403109C8UL)
#define CYREG_GPIO_PRT19_CFG_OUT        ((volatile un_GPIO_PRT_CFG_OUT_t*) 0x403109CCUL)
#define CYREG_GPIO_PRT19_CFG_IN_AUTOLVL ((volatile un_GPIO_PRT_CFG_IN_AUTOLVL_t*) 0x403109D8UL)
#define CYREG_GPIO_PRT19_CFG_OUT2       ((volatile un_GPIO_PRT_CFG_OUT2_t*) 0x403109E0UL)
#define CYREG_GPIO_PRT19_CFG_SLEW_EXT   ((volatile un_GPIO_PRT_CFG_SLEW_EXT_t*) 0x403109E4UL)

/**
  * \brief GPIO port control/configuration (GPIO0)
  */
#define CYREG_GPIO_INTR_CAUSE0          ((volatile un_GPIO_INTR_CAUSE0_t*) 0x40314000UL)
#define CYREG_GPIO_VDD_ACTIVE           ((volatile un_GPIO_VDD_ACTIVE_t*) 0x40314010UL)
#define CYREG_GPIO_VDD_INTR             ((volatile un_GPIO_VDD_INTR_t*) 0x40314014UL)
#define CYREG_GPIO_VDD_INTR_MASK        ((volatile un_GPIO_VDD_INTR_MASK_t*) 0x40314018UL)
#define CYREG_GPIO_VDD_INTR_MASKED      ((volatile un_GPIO_VDD_INTR_MASKED_t*) 0x4031401CUL)
#define CYREG_GPIO_VDD_INTR_SET         ((volatile un_GPIO_VDD_INTR_SET_t*) 0x40314020UL)

#endif /* _CYREG_GPIO_H_ */


/* [] END OF FILE */
