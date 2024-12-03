/***************************************************************************//**
* \file cyreg_ipc.h
*
* \brief
* IPC register definition header
*
* \note
* Generator version: 1.6.0.1423
* Database revision: TVIIBH16M_A0_390780
*
********************************************************************************
* \copyright
* Copyright 2016-2023, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef _CYREG_IPC_H_
#define _CYREG_IPC_H_

#include "cyip_ipc_v2.h"

/**
  * \brief IPC structure (IPC_STRUCT0)
  */
#define CYREG_IPC_STRUCT0_ACQUIRE       ((volatile un_IPC_STRUCT_ACQUIRE_t*) 0x40220000UL)
#define CYREG_IPC_STRUCT0_RELEASE       ((volatile un_IPC_STRUCT_RELEASE_t*) 0x40220004UL)
#define CYREG_IPC_STRUCT0_NOTIFY        ((volatile un_IPC_STRUCT_NOTIFY_t*) 0x40220008UL)
#define CYREG_IPC_STRUCT0_DATA0         ((volatile un_IPC_STRUCT_DATA0_t*) 0x4022000CUL)
#define CYREG_IPC_STRUCT0_DATA1         ((volatile un_IPC_STRUCT_DATA1_t*) 0x40220010UL)
#define CYREG_IPC_STRUCT0_LOCK_STATUS   ((volatile un_IPC_STRUCT_LOCK_STATUS_t*) 0x4022001CUL)

/**
  * \brief IPC structure (IPC_STRUCT1)
  */
#define CYREG_IPC_STRUCT1_ACQUIRE       ((volatile un_IPC_STRUCT_ACQUIRE_t*) 0x40220020UL)
#define CYREG_IPC_STRUCT1_RELEASE       ((volatile un_IPC_STRUCT_RELEASE_t*) 0x40220024UL)
#define CYREG_IPC_STRUCT1_NOTIFY        ((volatile un_IPC_STRUCT_NOTIFY_t*) 0x40220028UL)
#define CYREG_IPC_STRUCT1_DATA0         ((volatile un_IPC_STRUCT_DATA0_t*) 0x4022002CUL)
#define CYREG_IPC_STRUCT1_DATA1         ((volatile un_IPC_STRUCT_DATA1_t*) 0x40220030UL)
#define CYREG_IPC_STRUCT1_LOCK_STATUS   ((volatile un_IPC_STRUCT_LOCK_STATUS_t*) 0x4022003CUL)

/**
  * \brief IPC structure (IPC_STRUCT2)
  */
#define CYREG_IPC_STRUCT2_ACQUIRE       ((volatile un_IPC_STRUCT_ACQUIRE_t*) 0x40220040UL)
#define CYREG_IPC_STRUCT2_RELEASE       ((volatile un_IPC_STRUCT_RELEASE_t*) 0x40220044UL)
#define CYREG_IPC_STRUCT2_NOTIFY        ((volatile un_IPC_STRUCT_NOTIFY_t*) 0x40220048UL)
#define CYREG_IPC_STRUCT2_DATA0         ((volatile un_IPC_STRUCT_DATA0_t*) 0x4022004CUL)
#define CYREG_IPC_STRUCT2_DATA1         ((volatile un_IPC_STRUCT_DATA1_t*) 0x40220050UL)
#define CYREG_IPC_STRUCT2_LOCK_STATUS   ((volatile un_IPC_STRUCT_LOCK_STATUS_t*) 0x4022005CUL)

/**
  * \brief IPC structure (IPC_STRUCT3)
  */
#define CYREG_IPC_STRUCT3_ACQUIRE       ((volatile un_IPC_STRUCT_ACQUIRE_t*) 0x40220060UL)
#define CYREG_IPC_STRUCT3_RELEASE       ((volatile un_IPC_STRUCT_RELEASE_t*) 0x40220064UL)
#define CYREG_IPC_STRUCT3_NOTIFY        ((volatile un_IPC_STRUCT_NOTIFY_t*) 0x40220068UL)
#define CYREG_IPC_STRUCT3_DATA0         ((volatile un_IPC_STRUCT_DATA0_t*) 0x4022006CUL)
#define CYREG_IPC_STRUCT3_DATA1         ((volatile un_IPC_STRUCT_DATA1_t*) 0x40220070UL)
#define CYREG_IPC_STRUCT3_LOCK_STATUS   ((volatile un_IPC_STRUCT_LOCK_STATUS_t*) 0x4022007CUL)

/**
  * \brief IPC structure (IPC_STRUCT4)
  */
#define CYREG_IPC_STRUCT4_ACQUIRE       ((volatile un_IPC_STRUCT_ACQUIRE_t*) 0x40220080UL)
#define CYREG_IPC_STRUCT4_RELEASE       ((volatile un_IPC_STRUCT_RELEASE_t*) 0x40220084UL)
#define CYREG_IPC_STRUCT4_NOTIFY        ((volatile un_IPC_STRUCT_NOTIFY_t*) 0x40220088UL)
#define CYREG_IPC_STRUCT4_DATA0         ((volatile un_IPC_STRUCT_DATA0_t*) 0x4022008CUL)
#define CYREG_IPC_STRUCT4_DATA1         ((volatile un_IPC_STRUCT_DATA1_t*) 0x40220090UL)
#define CYREG_IPC_STRUCT4_LOCK_STATUS   ((volatile un_IPC_STRUCT_LOCK_STATUS_t*) 0x4022009CUL)

/**
  * \brief IPC structure (IPC_STRUCT5)
  */
#define CYREG_IPC_STRUCT5_ACQUIRE       ((volatile un_IPC_STRUCT_ACQUIRE_t*) 0x402200A0UL)
#define CYREG_IPC_STRUCT5_RELEASE       ((volatile un_IPC_STRUCT_RELEASE_t*) 0x402200A4UL)
#define CYREG_IPC_STRUCT5_NOTIFY        ((volatile un_IPC_STRUCT_NOTIFY_t*) 0x402200A8UL)
#define CYREG_IPC_STRUCT5_DATA0         ((volatile un_IPC_STRUCT_DATA0_t*) 0x402200ACUL)
#define CYREG_IPC_STRUCT5_DATA1         ((volatile un_IPC_STRUCT_DATA1_t*) 0x402200B0UL)
#define CYREG_IPC_STRUCT5_LOCK_STATUS   ((volatile un_IPC_STRUCT_LOCK_STATUS_t*) 0x402200BCUL)

/**
  * \brief IPC structure (IPC_STRUCT6)
  */
#define CYREG_IPC_STRUCT6_ACQUIRE       ((volatile un_IPC_STRUCT_ACQUIRE_t*) 0x402200C0UL)
#define CYREG_IPC_STRUCT6_RELEASE       ((volatile un_IPC_STRUCT_RELEASE_t*) 0x402200C4UL)
#define CYREG_IPC_STRUCT6_NOTIFY        ((volatile un_IPC_STRUCT_NOTIFY_t*) 0x402200C8UL)
#define CYREG_IPC_STRUCT6_DATA0         ((volatile un_IPC_STRUCT_DATA0_t*) 0x402200CCUL)
#define CYREG_IPC_STRUCT6_DATA1         ((volatile un_IPC_STRUCT_DATA1_t*) 0x402200D0UL)
#define CYREG_IPC_STRUCT6_LOCK_STATUS   ((volatile un_IPC_STRUCT_LOCK_STATUS_t*) 0x402200DCUL)

/**
  * \brief IPC structure (IPC_STRUCT7)
  */
#define CYREG_IPC_STRUCT7_ACQUIRE       ((volatile un_IPC_STRUCT_ACQUIRE_t*) 0x402200E0UL)
#define CYREG_IPC_STRUCT7_RELEASE       ((volatile un_IPC_STRUCT_RELEASE_t*) 0x402200E4UL)
#define CYREG_IPC_STRUCT7_NOTIFY        ((volatile un_IPC_STRUCT_NOTIFY_t*) 0x402200E8UL)
#define CYREG_IPC_STRUCT7_DATA0         ((volatile un_IPC_STRUCT_DATA0_t*) 0x402200ECUL)
#define CYREG_IPC_STRUCT7_DATA1         ((volatile un_IPC_STRUCT_DATA1_t*) 0x402200F0UL)
#define CYREG_IPC_STRUCT7_LOCK_STATUS   ((volatile un_IPC_STRUCT_LOCK_STATUS_t*) 0x402200FCUL)

/**
  * \brief IPC structure (IPC_STRUCT8)
  */
#define CYREG_IPC_STRUCT8_ACQUIRE       ((volatile un_IPC_STRUCT_ACQUIRE_t*) 0x40220100UL)
#define CYREG_IPC_STRUCT8_RELEASE       ((volatile un_IPC_STRUCT_RELEASE_t*) 0x40220104UL)
#define CYREG_IPC_STRUCT8_NOTIFY        ((volatile un_IPC_STRUCT_NOTIFY_t*) 0x40220108UL)
#define CYREG_IPC_STRUCT8_DATA0         ((volatile un_IPC_STRUCT_DATA0_t*) 0x4022010CUL)
#define CYREG_IPC_STRUCT8_DATA1         ((volatile un_IPC_STRUCT_DATA1_t*) 0x40220110UL)
#define CYREG_IPC_STRUCT8_LOCK_STATUS   ((volatile un_IPC_STRUCT_LOCK_STATUS_t*) 0x4022011CUL)

/**
  * \brief IPC structure (IPC_STRUCT9)
  */
#define CYREG_IPC_STRUCT9_ACQUIRE       ((volatile un_IPC_STRUCT_ACQUIRE_t*) 0x40220120UL)
#define CYREG_IPC_STRUCT9_RELEASE       ((volatile un_IPC_STRUCT_RELEASE_t*) 0x40220124UL)
#define CYREG_IPC_STRUCT9_NOTIFY        ((volatile un_IPC_STRUCT_NOTIFY_t*) 0x40220128UL)
#define CYREG_IPC_STRUCT9_DATA0         ((volatile un_IPC_STRUCT_DATA0_t*) 0x4022012CUL)
#define CYREG_IPC_STRUCT9_DATA1         ((volatile un_IPC_STRUCT_DATA1_t*) 0x40220130UL)
#define CYREG_IPC_STRUCT9_LOCK_STATUS   ((volatile un_IPC_STRUCT_LOCK_STATUS_t*) 0x4022013CUL)

/**
  * \brief IPC structure (IPC_STRUCT10)
  */
#define CYREG_IPC_STRUCT10_ACQUIRE      ((volatile un_IPC_STRUCT_ACQUIRE_t*) 0x40220140UL)
#define CYREG_IPC_STRUCT10_RELEASE      ((volatile un_IPC_STRUCT_RELEASE_t*) 0x40220144UL)
#define CYREG_IPC_STRUCT10_NOTIFY       ((volatile un_IPC_STRUCT_NOTIFY_t*) 0x40220148UL)
#define CYREG_IPC_STRUCT10_DATA0        ((volatile un_IPC_STRUCT_DATA0_t*) 0x4022014CUL)
#define CYREG_IPC_STRUCT10_DATA1        ((volatile un_IPC_STRUCT_DATA1_t*) 0x40220150UL)
#define CYREG_IPC_STRUCT10_LOCK_STATUS  ((volatile un_IPC_STRUCT_LOCK_STATUS_t*) 0x4022015CUL)

/**
  * \brief IPC structure (IPC_STRUCT11)
  */
#define CYREG_IPC_STRUCT11_ACQUIRE      ((volatile un_IPC_STRUCT_ACQUIRE_t*) 0x40220160UL)
#define CYREG_IPC_STRUCT11_RELEASE      ((volatile un_IPC_STRUCT_RELEASE_t*) 0x40220164UL)
#define CYREG_IPC_STRUCT11_NOTIFY       ((volatile un_IPC_STRUCT_NOTIFY_t*) 0x40220168UL)
#define CYREG_IPC_STRUCT11_DATA0        ((volatile un_IPC_STRUCT_DATA0_t*) 0x4022016CUL)
#define CYREG_IPC_STRUCT11_DATA1        ((volatile un_IPC_STRUCT_DATA1_t*) 0x40220170UL)
#define CYREG_IPC_STRUCT11_LOCK_STATUS  ((volatile un_IPC_STRUCT_LOCK_STATUS_t*) 0x4022017CUL)

/**
  * \brief IPC structure (IPC_STRUCT12)
  */
#define CYREG_IPC_STRUCT12_ACQUIRE      ((volatile un_IPC_STRUCT_ACQUIRE_t*) 0x40220180UL)
#define CYREG_IPC_STRUCT12_RELEASE      ((volatile un_IPC_STRUCT_RELEASE_t*) 0x40220184UL)
#define CYREG_IPC_STRUCT12_NOTIFY       ((volatile un_IPC_STRUCT_NOTIFY_t*) 0x40220188UL)
#define CYREG_IPC_STRUCT12_DATA0        ((volatile un_IPC_STRUCT_DATA0_t*) 0x4022018CUL)
#define CYREG_IPC_STRUCT12_DATA1        ((volatile un_IPC_STRUCT_DATA1_t*) 0x40220190UL)
#define CYREG_IPC_STRUCT12_LOCK_STATUS  ((volatile un_IPC_STRUCT_LOCK_STATUS_t*) 0x4022019CUL)

/**
  * \brief IPC structure (IPC_STRUCT13)
  */
#define CYREG_IPC_STRUCT13_ACQUIRE      ((volatile un_IPC_STRUCT_ACQUIRE_t*) 0x402201A0UL)
#define CYREG_IPC_STRUCT13_RELEASE      ((volatile un_IPC_STRUCT_RELEASE_t*) 0x402201A4UL)
#define CYREG_IPC_STRUCT13_NOTIFY       ((volatile un_IPC_STRUCT_NOTIFY_t*) 0x402201A8UL)
#define CYREG_IPC_STRUCT13_DATA0        ((volatile un_IPC_STRUCT_DATA0_t*) 0x402201ACUL)
#define CYREG_IPC_STRUCT13_DATA1        ((volatile un_IPC_STRUCT_DATA1_t*) 0x402201B0UL)
#define CYREG_IPC_STRUCT13_LOCK_STATUS  ((volatile un_IPC_STRUCT_LOCK_STATUS_t*) 0x402201BCUL)

/**
  * \brief IPC structure (IPC_STRUCT14)
  */
#define CYREG_IPC_STRUCT14_ACQUIRE      ((volatile un_IPC_STRUCT_ACQUIRE_t*) 0x402201C0UL)
#define CYREG_IPC_STRUCT14_RELEASE      ((volatile un_IPC_STRUCT_RELEASE_t*) 0x402201C4UL)
#define CYREG_IPC_STRUCT14_NOTIFY       ((volatile un_IPC_STRUCT_NOTIFY_t*) 0x402201C8UL)
#define CYREG_IPC_STRUCT14_DATA0        ((volatile un_IPC_STRUCT_DATA0_t*) 0x402201CCUL)
#define CYREG_IPC_STRUCT14_DATA1        ((volatile un_IPC_STRUCT_DATA1_t*) 0x402201D0UL)
#define CYREG_IPC_STRUCT14_LOCK_STATUS  ((volatile un_IPC_STRUCT_LOCK_STATUS_t*) 0x402201DCUL)

/**
  * \brief IPC structure (IPC_STRUCT15)
  */
#define CYREG_IPC_STRUCT15_ACQUIRE      ((volatile un_IPC_STRUCT_ACQUIRE_t*) 0x402201E0UL)
#define CYREG_IPC_STRUCT15_RELEASE      ((volatile un_IPC_STRUCT_RELEASE_t*) 0x402201E4UL)
#define CYREG_IPC_STRUCT15_NOTIFY       ((volatile un_IPC_STRUCT_NOTIFY_t*) 0x402201E8UL)
#define CYREG_IPC_STRUCT15_DATA0        ((volatile un_IPC_STRUCT_DATA0_t*) 0x402201ECUL)
#define CYREG_IPC_STRUCT15_DATA1        ((volatile un_IPC_STRUCT_DATA1_t*) 0x402201F0UL)
#define CYREG_IPC_STRUCT15_LOCK_STATUS  ((volatile un_IPC_STRUCT_LOCK_STATUS_t*) 0x402201FCUL)

/**
  * \brief IPC interrupt structure (IPC_INTR_STRUCT0)
  */
#define CYREG_IPC_INTR_STRUCT0_INTR     ((volatile un_IPC_INTR_STRUCT_INTR_t*) 0x40221000UL)
#define CYREG_IPC_INTR_STRUCT0_INTR_SET ((volatile un_IPC_INTR_STRUCT_INTR_SET_t*) 0x40221004UL)
#define CYREG_IPC_INTR_STRUCT0_INTR_MASK ((volatile un_IPC_INTR_STRUCT_INTR_MASK_t*) 0x40221008UL)
#define CYREG_IPC_INTR_STRUCT0_INTR_MASKED ((volatile un_IPC_INTR_STRUCT_INTR_MASKED_t*) 0x4022100CUL)

/**
  * \brief IPC interrupt structure (IPC_INTR_STRUCT1)
  */
#define CYREG_IPC_INTR_STRUCT1_INTR     ((volatile un_IPC_INTR_STRUCT_INTR_t*) 0x40221020UL)
#define CYREG_IPC_INTR_STRUCT1_INTR_SET ((volatile un_IPC_INTR_STRUCT_INTR_SET_t*) 0x40221024UL)
#define CYREG_IPC_INTR_STRUCT1_INTR_MASK ((volatile un_IPC_INTR_STRUCT_INTR_MASK_t*) 0x40221028UL)
#define CYREG_IPC_INTR_STRUCT1_INTR_MASKED ((volatile un_IPC_INTR_STRUCT_INTR_MASKED_t*) 0x4022102CUL)

/**
  * \brief IPC interrupt structure (IPC_INTR_STRUCT2)
  */
#define CYREG_IPC_INTR_STRUCT2_INTR     ((volatile un_IPC_INTR_STRUCT_INTR_t*) 0x40221040UL)
#define CYREG_IPC_INTR_STRUCT2_INTR_SET ((volatile un_IPC_INTR_STRUCT_INTR_SET_t*) 0x40221044UL)
#define CYREG_IPC_INTR_STRUCT2_INTR_MASK ((volatile un_IPC_INTR_STRUCT_INTR_MASK_t*) 0x40221048UL)
#define CYREG_IPC_INTR_STRUCT2_INTR_MASKED ((volatile un_IPC_INTR_STRUCT_INTR_MASKED_t*) 0x4022104CUL)

/**
  * \brief IPC interrupt structure (IPC_INTR_STRUCT3)
  */
#define CYREG_IPC_INTR_STRUCT3_INTR     ((volatile un_IPC_INTR_STRUCT_INTR_t*) 0x40221060UL)
#define CYREG_IPC_INTR_STRUCT3_INTR_SET ((volatile un_IPC_INTR_STRUCT_INTR_SET_t*) 0x40221064UL)
#define CYREG_IPC_INTR_STRUCT3_INTR_MASK ((volatile un_IPC_INTR_STRUCT_INTR_MASK_t*) 0x40221068UL)
#define CYREG_IPC_INTR_STRUCT3_INTR_MASKED ((volatile un_IPC_INTR_STRUCT_INTR_MASKED_t*) 0x4022106CUL)

/**
  * \brief IPC interrupt structure (IPC_INTR_STRUCT4)
  */
#define CYREG_IPC_INTR_STRUCT4_INTR     ((volatile un_IPC_INTR_STRUCT_INTR_t*) 0x40221080UL)
#define CYREG_IPC_INTR_STRUCT4_INTR_SET ((volatile un_IPC_INTR_STRUCT_INTR_SET_t*) 0x40221084UL)
#define CYREG_IPC_INTR_STRUCT4_INTR_MASK ((volatile un_IPC_INTR_STRUCT_INTR_MASK_t*) 0x40221088UL)
#define CYREG_IPC_INTR_STRUCT4_INTR_MASKED ((volatile un_IPC_INTR_STRUCT_INTR_MASKED_t*) 0x4022108CUL)

/**
  * \brief IPC interrupt structure (IPC_INTR_STRUCT5)
  */
#define CYREG_IPC_INTR_STRUCT5_INTR     ((volatile un_IPC_INTR_STRUCT_INTR_t*) 0x402210A0UL)
#define CYREG_IPC_INTR_STRUCT5_INTR_SET ((volatile un_IPC_INTR_STRUCT_INTR_SET_t*) 0x402210A4UL)
#define CYREG_IPC_INTR_STRUCT5_INTR_MASK ((volatile un_IPC_INTR_STRUCT_INTR_MASK_t*) 0x402210A8UL)
#define CYREG_IPC_INTR_STRUCT5_INTR_MASKED ((volatile un_IPC_INTR_STRUCT_INTR_MASKED_t*) 0x402210ACUL)

/**
  * \brief IPC interrupt structure (IPC_INTR_STRUCT6)
  */
#define CYREG_IPC_INTR_STRUCT6_INTR     ((volatile un_IPC_INTR_STRUCT_INTR_t*) 0x402210C0UL)
#define CYREG_IPC_INTR_STRUCT6_INTR_SET ((volatile un_IPC_INTR_STRUCT_INTR_SET_t*) 0x402210C4UL)
#define CYREG_IPC_INTR_STRUCT6_INTR_MASK ((volatile un_IPC_INTR_STRUCT_INTR_MASK_t*) 0x402210C8UL)
#define CYREG_IPC_INTR_STRUCT6_INTR_MASKED ((volatile un_IPC_INTR_STRUCT_INTR_MASKED_t*) 0x402210CCUL)

/**
  * \brief IPC interrupt structure (IPC_INTR_STRUCT7)
  */
#define CYREG_IPC_INTR_STRUCT7_INTR     ((volatile un_IPC_INTR_STRUCT_INTR_t*) 0x402210E0UL)
#define CYREG_IPC_INTR_STRUCT7_INTR_SET ((volatile un_IPC_INTR_STRUCT_INTR_SET_t*) 0x402210E4UL)
#define CYREG_IPC_INTR_STRUCT7_INTR_MASK ((volatile un_IPC_INTR_STRUCT_INTR_MASK_t*) 0x402210E8UL)
#define CYREG_IPC_INTR_STRUCT7_INTR_MASKED ((volatile un_IPC_INTR_STRUCT_INTR_MASKED_t*) 0x402210ECUL)

/**
  * \brief IPC interrupt structure (IPC_INTR_STRUCT8)
  */
#define CYREG_IPC_INTR_STRUCT8_INTR     ((volatile un_IPC_INTR_STRUCT_INTR_t*) 0x40221100UL)
#define CYREG_IPC_INTR_STRUCT8_INTR_SET ((volatile un_IPC_INTR_STRUCT_INTR_SET_t*) 0x40221104UL)
#define CYREG_IPC_INTR_STRUCT8_INTR_MASK ((volatile un_IPC_INTR_STRUCT_INTR_MASK_t*) 0x40221108UL)
#define CYREG_IPC_INTR_STRUCT8_INTR_MASKED ((volatile un_IPC_INTR_STRUCT_INTR_MASKED_t*) 0x4022110CUL)

/**
  * \brief IPC interrupt structure (IPC_INTR_STRUCT9)
  */
#define CYREG_IPC_INTR_STRUCT9_INTR     ((volatile un_IPC_INTR_STRUCT_INTR_t*) 0x40221120UL)
#define CYREG_IPC_INTR_STRUCT9_INTR_SET ((volatile un_IPC_INTR_STRUCT_INTR_SET_t*) 0x40221124UL)
#define CYREG_IPC_INTR_STRUCT9_INTR_MASK ((volatile un_IPC_INTR_STRUCT_INTR_MASK_t*) 0x40221128UL)
#define CYREG_IPC_INTR_STRUCT9_INTR_MASKED ((volatile un_IPC_INTR_STRUCT_INTR_MASKED_t*) 0x4022112CUL)

/**
  * \brief IPC interrupt structure (IPC_INTR_STRUCT10)
  */
#define CYREG_IPC_INTR_STRUCT10_INTR    ((volatile un_IPC_INTR_STRUCT_INTR_t*) 0x40221140UL)
#define CYREG_IPC_INTR_STRUCT10_INTR_SET ((volatile un_IPC_INTR_STRUCT_INTR_SET_t*) 0x40221144UL)
#define CYREG_IPC_INTR_STRUCT10_INTR_MASK ((volatile un_IPC_INTR_STRUCT_INTR_MASK_t*) 0x40221148UL)
#define CYREG_IPC_INTR_STRUCT10_INTR_MASKED ((volatile un_IPC_INTR_STRUCT_INTR_MASKED_t*) 0x4022114CUL)

/**
  * \brief IPC interrupt structure (IPC_INTR_STRUCT11)
  */
#define CYREG_IPC_INTR_STRUCT11_INTR    ((volatile un_IPC_INTR_STRUCT_INTR_t*) 0x40221160UL)
#define CYREG_IPC_INTR_STRUCT11_INTR_SET ((volatile un_IPC_INTR_STRUCT_INTR_SET_t*) 0x40221164UL)
#define CYREG_IPC_INTR_STRUCT11_INTR_MASK ((volatile un_IPC_INTR_STRUCT_INTR_MASK_t*) 0x40221168UL)
#define CYREG_IPC_INTR_STRUCT11_INTR_MASKED ((volatile un_IPC_INTR_STRUCT_INTR_MASKED_t*) 0x4022116CUL)

/**
  * \brief IPC interrupt structure (IPC_INTR_STRUCT12)
  */
#define CYREG_IPC_INTR_STRUCT12_INTR    ((volatile un_IPC_INTR_STRUCT_INTR_t*) 0x40221180UL)
#define CYREG_IPC_INTR_STRUCT12_INTR_SET ((volatile un_IPC_INTR_STRUCT_INTR_SET_t*) 0x40221184UL)
#define CYREG_IPC_INTR_STRUCT12_INTR_MASK ((volatile un_IPC_INTR_STRUCT_INTR_MASK_t*) 0x40221188UL)
#define CYREG_IPC_INTR_STRUCT12_INTR_MASKED ((volatile un_IPC_INTR_STRUCT_INTR_MASKED_t*) 0x4022118CUL)

/**
  * \brief IPC interrupt structure (IPC_INTR_STRUCT13)
  */
#define CYREG_IPC_INTR_STRUCT13_INTR    ((volatile un_IPC_INTR_STRUCT_INTR_t*) 0x402211A0UL)
#define CYREG_IPC_INTR_STRUCT13_INTR_SET ((volatile un_IPC_INTR_STRUCT_INTR_SET_t*) 0x402211A4UL)
#define CYREG_IPC_INTR_STRUCT13_INTR_MASK ((volatile un_IPC_INTR_STRUCT_INTR_MASK_t*) 0x402211A8UL)
#define CYREG_IPC_INTR_STRUCT13_INTR_MASKED ((volatile un_IPC_INTR_STRUCT_INTR_MASKED_t*) 0x402211ACUL)

/**
  * \brief IPC interrupt structure (IPC_INTR_STRUCT14)
  */
#define CYREG_IPC_INTR_STRUCT14_INTR    ((volatile un_IPC_INTR_STRUCT_INTR_t*) 0x402211C0UL)
#define CYREG_IPC_INTR_STRUCT14_INTR_SET ((volatile un_IPC_INTR_STRUCT_INTR_SET_t*) 0x402211C4UL)
#define CYREG_IPC_INTR_STRUCT14_INTR_MASK ((volatile un_IPC_INTR_STRUCT_INTR_MASK_t*) 0x402211C8UL)
#define CYREG_IPC_INTR_STRUCT14_INTR_MASKED ((volatile un_IPC_INTR_STRUCT_INTR_MASKED_t*) 0x402211CCUL)

/**
  * \brief IPC interrupt structure (IPC_INTR_STRUCT15)
  */
#define CYREG_IPC_INTR_STRUCT15_INTR    ((volatile un_IPC_INTR_STRUCT_INTR_t*) 0x402211E0UL)
#define CYREG_IPC_INTR_STRUCT15_INTR_SET ((volatile un_IPC_INTR_STRUCT_INTR_SET_t*) 0x402211E4UL)
#define CYREG_IPC_INTR_STRUCT15_INTR_MASK ((volatile un_IPC_INTR_STRUCT_INTR_MASK_t*) 0x402211E8UL)
#define CYREG_IPC_INTR_STRUCT15_INTR_MASKED ((volatile un_IPC_INTR_STRUCT_INTR_MASKED_t*) 0x402211ECUL)

#endif /* _CYREG_IPC_H_ */


/* [] END OF FILE */
