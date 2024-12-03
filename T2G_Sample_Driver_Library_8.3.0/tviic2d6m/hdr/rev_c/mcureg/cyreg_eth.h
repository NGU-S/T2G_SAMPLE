/***************************************************************************//**
* \file cyreg_eth.h
*
* \brief
* ETH register definition header
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

#ifndef _CYREG_ETH_H_
#define _CYREG_ETH_H_

#include "cyip_eth_v2.h"

/**
  * \brief Ethernet Interface (ETH)
  */
#define CYREG_ETH0_CTL                  ((volatile un_ETH_CTL_t*) 0x40480000UL)
#define CYREG_ETH0_STATUS               ((volatile un_ETH_STATUS_t*) 0x40480004UL)
#define CYREG_ETH0_NETWORK_CONTROL      ((volatile un_ETH_NETWORK_CONTROL_t*) 0x40481000UL)
#define CYREG_ETH0_NETWORK_CONFIG       ((volatile un_ETH_NETWORK_CONFIG_t*) 0x40481004UL)
#define CYREG_ETH0_NETWORK_STATUS       ((volatile un_ETH_NETWORK_STATUS_t*) 0x40481008UL)
#define CYREG_ETH0_USER_IO_REGISTER     ((volatile un_ETH_USER_IO_REGISTER_t*) 0x4048100CUL)
#define CYREG_ETH0_DMA_CONFIG           ((volatile un_ETH_DMA_CONFIG_t*) 0x40481010UL)
#define CYREG_ETH0_TRANSMIT_STATUS      ((volatile un_ETH_TRANSMIT_STATUS_t*) 0x40481014UL)
#define CYREG_ETH0_RECEIVE_Q_PTR        ((volatile un_ETH_RECEIVE_Q_PTR_t*) 0x40481018UL)
#define CYREG_ETH0_TRANSMIT_Q_PTR       ((volatile un_ETH_TRANSMIT_Q_PTR_t*) 0x4048101CUL)
#define CYREG_ETH0_RECEIVE_STATUS       ((volatile un_ETH_RECEIVE_STATUS_t*) 0x40481020UL)
#define CYREG_ETH0_INT_STATUS           ((volatile un_ETH_INT_STATUS_t*) 0x40481024UL)
#define CYREG_ETH0_INT_ENABLE           ((volatile un_ETH_INT_ENABLE_t*) 0x40481028UL)
#define CYREG_ETH0_INT_DISABLE          ((volatile un_ETH_INT_DISABLE_t*) 0x4048102CUL)
#define CYREG_ETH0_INT_MASK             ((volatile un_ETH_INT_MASK_t*) 0x40481030UL)
#define CYREG_ETH0_PHY_MANAGEMENT       ((volatile un_ETH_PHY_MANAGEMENT_t*) 0x40481034UL)
#define CYREG_ETH0_PAUSE_TIME           ((volatile un_ETH_PAUSE_TIME_t*) 0x40481038UL)
#define CYREG_ETH0_TX_PAUSE_QUANTUM     ((volatile un_ETH_TX_PAUSE_QUANTUM_t*) 0x4048103CUL)
#define CYREG_ETH0_PBUF_TXCUTTHRU       ((volatile un_ETH_PBUF_TXCUTTHRU_t*) 0x40481040UL)
#define CYREG_ETH0_PBUF_RXCUTTHRU       ((volatile un_ETH_PBUF_RXCUTTHRU_t*) 0x40481044UL)
#define CYREG_ETH0_JUMBO_MAX_LENGTH     ((volatile un_ETH_JUMBO_MAX_LENGTH_t*) 0x40481048UL)
#define CYREG_ETH0_EXTERNAL_FIFO_INTERFACE ((volatile un_ETH_EXTERNAL_FIFO_INTERFACE_t*) 0x4048104CUL)
#define CYREG_ETH0_AXI_MAX_PIPELINE     ((volatile un_ETH_AXI_MAX_PIPELINE_t*) 0x40481054UL)
#define CYREG_ETH0_RSC_CONTROL          ((volatile un_ETH_RSC_CONTROL_t*) 0x40481058UL)
#define CYREG_ETH0_INT_MODERATION       ((volatile un_ETH_INT_MODERATION_t*) 0x4048105CUL)
#define CYREG_ETH0_SYS_WAKE_TIME        ((volatile un_ETH_SYS_WAKE_TIME_t*) 0x40481060UL)
#define CYREG_ETH0_HASH_BOTTOM          ((volatile un_ETH_HASH_BOTTOM_t*) 0x40481080UL)
#define CYREG_ETH0_HASH_TOP             ((volatile un_ETH_HASH_TOP_t*) 0x40481084UL)
#define CYREG_ETH0_SPEC_ADD1_BOTTOM     ((volatile un_ETH_SPEC_ADD1_BOTTOM_t*) 0x40481088UL)
#define CYREG_ETH0_SPEC_ADD1_TOP        ((volatile un_ETH_SPEC_ADD1_TOP_t*) 0x4048108CUL)
#define CYREG_ETH0_SPEC_ADD2_BOTTOM     ((volatile un_ETH_SPEC_ADD2_BOTTOM_t*) 0x40481090UL)
#define CYREG_ETH0_SPEC_ADD2_TOP        ((volatile un_ETH_SPEC_ADD2_TOP_t*) 0x40481094UL)
#define CYREG_ETH0_SPEC_ADD3_BOTTOM     ((volatile un_ETH_SPEC_ADD3_BOTTOM_t*) 0x40481098UL)
#define CYREG_ETH0_SPEC_ADD3_TOP        ((volatile un_ETH_SPEC_ADD3_TOP_t*) 0x4048109CUL)
#define CYREG_ETH0_SPEC_ADD4_BOTTOM     ((volatile un_ETH_SPEC_ADD4_BOTTOM_t*) 0x404810A0UL)
#define CYREG_ETH0_SPEC_ADD4_TOP        ((volatile un_ETH_SPEC_ADD4_TOP_t*) 0x404810A4UL)
#define CYREG_ETH0_SPEC_TYPE1           ((volatile un_ETH_SPEC_TYPE1_t*) 0x404810A8UL)
#define CYREG_ETH0_SPEC_TYPE2           ((volatile un_ETH_SPEC_TYPE2_t*) 0x404810ACUL)
#define CYREG_ETH0_SPEC_TYPE3           ((volatile un_ETH_SPEC_TYPE3_t*) 0x404810B0UL)
#define CYREG_ETH0_SPEC_TYPE4           ((volatile un_ETH_SPEC_TYPE4_t*) 0x404810B4UL)
#define CYREG_ETH0_WOL_REGISTER         ((volatile un_ETH_WOL_REGISTER_t*) 0x404810B8UL)
#define CYREG_ETH0_STRETCH_RATIO        ((volatile un_ETH_STRETCH_RATIO_t*) 0x404810BCUL)
#define CYREG_ETH0_STACKED_VLAN         ((volatile un_ETH_STACKED_VLAN_t*) 0x404810C0UL)
#define CYREG_ETH0_TX_PFC_PAUSE         ((volatile un_ETH_TX_PFC_PAUSE_t*) 0x404810C4UL)
#define CYREG_ETH0_MASK_ADD1_BOTTOM     ((volatile un_ETH_MASK_ADD1_BOTTOM_t*) 0x404810C8UL)
#define CYREG_ETH0_MASK_ADD1_TOP        ((volatile un_ETH_MASK_ADD1_TOP_t*) 0x404810CCUL)
#define CYREG_ETH0_DMA_ADDR_OR_MASK     ((volatile un_ETH_DMA_ADDR_OR_MASK_t*) 0x404810D0UL)
#define CYREG_ETH0_RX_PTP_UNICAST       ((volatile un_ETH_RX_PTP_UNICAST_t*) 0x404810D4UL)
#define CYREG_ETH0_TX_PTP_UNICAST       ((volatile un_ETH_TX_PTP_UNICAST_t*) 0x404810D8UL)
#define CYREG_ETH0_TSU_NSEC_CMP         ((volatile un_ETH_TSU_NSEC_CMP_t*) 0x404810DCUL)
#define CYREG_ETH0_TSU_SEC_CMP          ((volatile un_ETH_TSU_SEC_CMP_t*) 0x404810E0UL)
#define CYREG_ETH0_TSU_MSB_SEC_CMP      ((volatile un_ETH_TSU_MSB_SEC_CMP_t*) 0x404810E4UL)
#define CYREG_ETH0_TSU_PTP_TX_MSB_SEC   ((volatile un_ETH_TSU_PTP_TX_MSB_SEC_t*) 0x404810E8UL)
#define CYREG_ETH0_TSU_PTP_RX_MSB_SEC   ((volatile un_ETH_TSU_PTP_RX_MSB_SEC_t*) 0x404810ECUL)
#define CYREG_ETH0_TSU_PEER_TX_MSB_SEC  ((volatile un_ETH_TSU_PEER_TX_MSB_SEC_t*) 0x404810F0UL)
#define CYREG_ETH0_TSU_PEER_RX_MSB_SEC  ((volatile un_ETH_TSU_PEER_RX_MSB_SEC_t*) 0x404810F4UL)
#define CYREG_ETH0_DPRAM_FILL_DBG       ((volatile un_ETH_DPRAM_FILL_DBG_t*) 0x404810F8UL)
#define CYREG_ETH0_REVISION_REG         ((volatile un_ETH_REVISION_REG_t*) 0x404810FCUL)
#define CYREG_ETH0_OCTETS_TXED_BOTTOM   ((volatile un_ETH_OCTETS_TXED_BOTTOM_t*) 0x40481100UL)
#define CYREG_ETH0_OCTETS_TXED_TOP      ((volatile un_ETH_OCTETS_TXED_TOP_t*) 0x40481104UL)
#define CYREG_ETH0_FRAMES_TXED_OK       ((volatile un_ETH_FRAMES_TXED_OK_t*) 0x40481108UL)
#define CYREG_ETH0_BROADCAST_TXED       ((volatile un_ETH_BROADCAST_TXED_t*) 0x4048110CUL)
#define CYREG_ETH0_MULTICAST_TXED       ((volatile un_ETH_MULTICAST_TXED_t*) 0x40481110UL)
#define CYREG_ETH0_PAUSE_FRAMES_TXED    ((volatile un_ETH_PAUSE_FRAMES_TXED_t*) 0x40481114UL)
#define CYREG_ETH0_FRAMES_TXED_64       ((volatile un_ETH_FRAMES_TXED_64_t*) 0x40481118UL)
#define CYREG_ETH0_FRAMES_TXED_65       ((volatile un_ETH_FRAMES_TXED_65_t*) 0x4048111CUL)
#define CYREG_ETH0_FRAMES_TXED_128      ((volatile un_ETH_FRAMES_TXED_128_t*) 0x40481120UL)
#define CYREG_ETH0_FRAMES_TXED_256      ((volatile un_ETH_FRAMES_TXED_256_t*) 0x40481124UL)
#define CYREG_ETH0_FRAMES_TXED_512      ((volatile un_ETH_FRAMES_TXED_512_t*) 0x40481128UL)
#define CYREG_ETH0_FRAMES_TXED_1024     ((volatile un_ETH_FRAMES_TXED_1024_t*) 0x4048112CUL)
#define CYREG_ETH0_FRAMES_TXED_1519     ((volatile un_ETH_FRAMES_TXED_1519_t*) 0x40481130UL)
#define CYREG_ETH0_TX_UNDERRUNS         ((volatile un_ETH_TX_UNDERRUNS_t*) 0x40481134UL)
#define CYREG_ETH0_SINGLE_COLLISIONS    ((volatile un_ETH_SINGLE_COLLISIONS_t*) 0x40481138UL)
#define CYREG_ETH0_MULTIPLE_COLLISIONS  ((volatile un_ETH_MULTIPLE_COLLISIONS_t*) 0x4048113CUL)
#define CYREG_ETH0_EXCESSIVE_COLLISIONS ((volatile un_ETH_EXCESSIVE_COLLISIONS_t*) 0x40481140UL)
#define CYREG_ETH0_LATE_COLLISIONS      ((volatile un_ETH_LATE_COLLISIONS_t*) 0x40481144UL)
#define CYREG_ETH0_DEFERRED_FRAMES      ((volatile un_ETH_DEFERRED_FRAMES_t*) 0x40481148UL)
#define CYREG_ETH0_CRS_ERRORS           ((volatile un_ETH_CRS_ERRORS_t*) 0x4048114CUL)
#define CYREG_ETH0_OCTETS_RXED_BOTTOM   ((volatile un_ETH_OCTETS_RXED_BOTTOM_t*) 0x40481150UL)
#define CYREG_ETH0_OCTETS_RXED_TOP      ((volatile un_ETH_OCTETS_RXED_TOP_t*) 0x40481154UL)
#define CYREG_ETH0_FRAMES_RXED_OK       ((volatile un_ETH_FRAMES_RXED_OK_t*) 0x40481158UL)
#define CYREG_ETH0_BROADCAST_RXED       ((volatile un_ETH_BROADCAST_RXED_t*) 0x4048115CUL)
#define CYREG_ETH0_MULTICAST_RXED       ((volatile un_ETH_MULTICAST_RXED_t*) 0x40481160UL)
#define CYREG_ETH0_PAUSE_FRAMES_RXED    ((volatile un_ETH_PAUSE_FRAMES_RXED_t*) 0x40481164UL)
#define CYREG_ETH0_FRAMES_RXED_64       ((volatile un_ETH_FRAMES_RXED_64_t*) 0x40481168UL)
#define CYREG_ETH0_FRAMES_RXED_65       ((volatile un_ETH_FRAMES_RXED_65_t*) 0x4048116CUL)
#define CYREG_ETH0_FRAMES_RXED_128      ((volatile un_ETH_FRAMES_RXED_128_t*) 0x40481170UL)
#define CYREG_ETH0_FRAMES_RXED_256      ((volatile un_ETH_FRAMES_RXED_256_t*) 0x40481174UL)
#define CYREG_ETH0_FRAMES_RXED_512      ((volatile un_ETH_FRAMES_RXED_512_t*) 0x40481178UL)
#define CYREG_ETH0_FRAMES_RXED_1024     ((volatile un_ETH_FRAMES_RXED_1024_t*) 0x4048117CUL)
#define CYREG_ETH0_FRAMES_RXED_1519     ((volatile un_ETH_FRAMES_RXED_1519_t*) 0x40481180UL)
#define CYREG_ETH0_UNDERSIZE_FRAMES     ((volatile un_ETH_UNDERSIZE_FRAMES_t*) 0x40481184UL)
#define CYREG_ETH0_EXCESSIVE_RX_LENGTH  ((volatile un_ETH_EXCESSIVE_RX_LENGTH_t*) 0x40481188UL)
#define CYREG_ETH0_RX_JABBERS           ((volatile un_ETH_RX_JABBERS_t*) 0x4048118CUL)
#define CYREG_ETH0_FCS_ERRORS           ((volatile un_ETH_FCS_ERRORS_t*) 0x40481190UL)
#define CYREG_ETH0_RX_LENGTH_ERRORS     ((volatile un_ETH_RX_LENGTH_ERRORS_t*) 0x40481194UL)
#define CYREG_ETH0_RX_SYMBOL_ERRORS     ((volatile un_ETH_RX_SYMBOL_ERRORS_t*) 0x40481198UL)
#define CYREG_ETH0_ALIGNMENT_ERRORS     ((volatile un_ETH_ALIGNMENT_ERRORS_t*) 0x4048119CUL)
#define CYREG_ETH0_RX_RESOURCE_ERRORS   ((volatile un_ETH_RX_RESOURCE_ERRORS_t*) 0x404811A0UL)
#define CYREG_ETH0_RX_OVERRUNS          ((volatile un_ETH_RX_OVERRUNS_t*) 0x404811A4UL)
#define CYREG_ETH0_RX_IP_CK_ERRORS      ((volatile un_ETH_RX_IP_CK_ERRORS_t*) 0x404811A8UL)
#define CYREG_ETH0_RX_TCP_CK_ERRORS     ((volatile un_ETH_RX_TCP_CK_ERRORS_t*) 0x404811ACUL)
#define CYREG_ETH0_RX_UDP_CK_ERRORS     ((volatile un_ETH_RX_UDP_CK_ERRORS_t*) 0x404811B0UL)
#define CYREG_ETH0_AUTO_FLUSHED_PKTS    ((volatile un_ETH_AUTO_FLUSHED_PKTS_t*) 0x404811B4UL)
#define CYREG_ETH0_TSU_TIMER_INCR_SUB_NSEC ((volatile un_ETH_TSU_TIMER_INCR_SUB_NSEC_t*) 0x404811BCUL)
#define CYREG_ETH0_TSU_TIMER_MSB_SEC    ((volatile un_ETH_TSU_TIMER_MSB_SEC_t*) 0x404811C0UL)
#define CYREG_ETH0_TSU_STROBE_MSB_SEC   ((volatile un_ETH_TSU_STROBE_MSB_SEC_t*) 0x404811C4UL)
#define CYREG_ETH0_TSU_STROBE_SEC       ((volatile un_ETH_TSU_STROBE_SEC_t*) 0x404811C8UL)
#define CYREG_ETH0_TSU_STROBE_NSEC      ((volatile un_ETH_TSU_STROBE_NSEC_t*) 0x404811CCUL)
#define CYREG_ETH0_TSU_TIMER_SEC        ((volatile un_ETH_TSU_TIMER_SEC_t*) 0x404811D0UL)
#define CYREG_ETH0_TSU_TIMER_NSEC       ((volatile un_ETH_TSU_TIMER_NSEC_t*) 0x404811D4UL)
#define CYREG_ETH0_TSU_TIMER_ADJUST     ((volatile un_ETH_TSU_TIMER_ADJUST_t*) 0x404811D8UL)
#define CYREG_ETH0_TSU_TIMER_INCR       ((volatile un_ETH_TSU_TIMER_INCR_t*) 0x404811DCUL)
#define CYREG_ETH0_TSU_PTP_TX_SEC       ((volatile un_ETH_TSU_PTP_TX_SEC_t*) 0x404811E0UL)
#define CYREG_ETH0_TSU_PTP_TX_NSEC      ((volatile un_ETH_TSU_PTP_TX_NSEC_t*) 0x404811E4UL)
#define CYREG_ETH0_TSU_PTP_RX_SEC       ((volatile un_ETH_TSU_PTP_RX_SEC_t*) 0x404811E8UL)
#define CYREG_ETH0_TSU_PTP_RX_NSEC      ((volatile un_ETH_TSU_PTP_RX_NSEC_t*) 0x404811ECUL)
#define CYREG_ETH0_TSU_PEER_TX_SEC      ((volatile un_ETH_TSU_PEER_TX_SEC_t*) 0x404811F0UL)
#define CYREG_ETH0_TSU_PEER_TX_NSEC     ((volatile un_ETH_TSU_PEER_TX_NSEC_t*) 0x404811F4UL)
#define CYREG_ETH0_TSU_PEER_RX_SEC      ((volatile un_ETH_TSU_PEER_RX_SEC_t*) 0x404811F8UL)
#define CYREG_ETH0_TSU_PEER_RX_NSEC     ((volatile un_ETH_TSU_PEER_RX_NSEC_t*) 0x404811FCUL)
#define CYREG_ETH0_PCS_CONTROL          ((volatile un_ETH_PCS_CONTROL_t*) 0x40481200UL)
#define CYREG_ETH0_PCS_STATUS           ((volatile un_ETH_PCS_STATUS_t*) 0x40481204UL)
#define CYREG_ETH0_PCS_AN_ADV           ((volatile un_ETH_PCS_AN_ADV_t*) 0x40481210UL)
#define CYREG_ETH0_PCS_AN_LP_BASE       ((volatile un_ETH_PCS_AN_LP_BASE_t*) 0x40481214UL)
#define CYREG_ETH0_PCS_AN_EXP           ((volatile un_ETH_PCS_AN_EXP_t*) 0x40481218UL)
#define CYREG_ETH0_PCS_AN_NP_TX         ((volatile un_ETH_PCS_AN_NP_TX_t*) 0x4048121CUL)
#define CYREG_ETH0_PCS_AN_LP_NP         ((volatile un_ETH_PCS_AN_LP_NP_t*) 0x40481220UL)
#define CYREG_ETH0_PCS_AN_EXT_STATUS    ((volatile un_ETH_PCS_AN_EXT_STATUS_t*) 0x4048123CUL)
#define CYREG_ETH0_TX_PAUSE_QUANTUM1    ((volatile un_ETH_TX_PAUSE_QUANTUM1_t*) 0x40481260UL)
#define CYREG_ETH0_TX_PAUSE_QUANTUM2    ((volatile un_ETH_TX_PAUSE_QUANTUM2_t*) 0x40481264UL)
#define CYREG_ETH0_TX_PAUSE_QUANTUM3    ((volatile un_ETH_TX_PAUSE_QUANTUM3_t*) 0x40481268UL)
#define CYREG_ETH0_RX_LPI               ((volatile un_ETH_RX_LPI_t*) 0x40481270UL)
#define CYREG_ETH0_RX_LPI_TIME          ((volatile un_ETH_RX_LPI_TIME_t*) 0x40481274UL)
#define CYREG_ETH0_TX_LPI               ((volatile un_ETH_TX_LPI_t*) 0x40481278UL)
#define CYREG_ETH0_TX_LPI_TIME          ((volatile un_ETH_TX_LPI_TIME_t*) 0x4048127CUL)
#define CYREG_ETH0_DESIGNCFG_DEBUG1     ((volatile un_ETH_DESIGNCFG_DEBUG1_t*) 0x40481280UL)
#define CYREG_ETH0_DESIGNCFG_DEBUG2     ((volatile un_ETH_DESIGNCFG_DEBUG2_t*) 0x40481284UL)
#define CYREG_ETH0_DESIGNCFG_DEBUG3     ((volatile un_ETH_DESIGNCFG_DEBUG3_t*) 0x40481288UL)
#define CYREG_ETH0_DESIGNCFG_DEBUG4     ((volatile un_ETH_DESIGNCFG_DEBUG4_t*) 0x4048128CUL)
#define CYREG_ETH0_DESIGNCFG_DEBUG5     ((volatile un_ETH_DESIGNCFG_DEBUG5_t*) 0x40481290UL)
#define CYREG_ETH0_DESIGNCFG_DEBUG6     ((volatile un_ETH_DESIGNCFG_DEBUG6_t*) 0x40481294UL)
#define CYREG_ETH0_DESIGNCFG_DEBUG7     ((volatile un_ETH_DESIGNCFG_DEBUG7_t*) 0x40481298UL)
#define CYREG_ETH0_DESIGNCFG_DEBUG8     ((volatile un_ETH_DESIGNCFG_DEBUG8_t*) 0x4048129CUL)
#define CYREG_ETH0_DESIGNCFG_DEBUG9     ((volatile un_ETH_DESIGNCFG_DEBUG9_t*) 0x404812A0UL)
#define CYREG_ETH0_DESIGNCFG_DEBUG10    ((volatile un_ETH_DESIGNCFG_DEBUG10_t*) 0x404812A4UL)
#define CYREG_ETH0_SPEC_ADD5_BOTTOM     ((volatile un_ETH_SPEC_ADD5_BOTTOM_t*) 0x40481300UL)
#define CYREG_ETH0_SPEC_ADD5_TOP        ((volatile un_ETH_SPEC_ADD5_TOP_t*) 0x40481304UL)
#define CYREG_ETH0_SPEC_ADD36_BOTTOM    ((volatile un_ETH_SPEC_ADD36_BOTTOM_t*) 0x404813F8UL)
#define CYREG_ETH0_SPEC_ADD36_TOP       ((volatile un_ETH_SPEC_ADD36_TOP_t*) 0x404813FCUL)
#define CYREG_ETH0_INT_Q1_STATUS        ((volatile un_ETH_INT_Q1_STATUS_t*) 0x40481400UL)
#define CYREG_ETH0_INT_Q2_STATUS        ((volatile un_ETH_INT_Q2_STATUS_t*) 0x40481404UL)
#define CYREG_ETH0_INT_Q3_STATUS        ((volatile un_ETH_INT_Q3_STATUS_t*) 0x40481408UL)
#define CYREG_ETH0_INT_Q15_STATUS       ((volatile un_ETH_INT_Q15_STATUS_t*) 0x40481438UL)
#define CYREG_ETH0_TRANSMIT_Q1_PTR      ((volatile un_ETH_TRANSMIT_Q1_PTR_t*) 0x40481440UL)
#define CYREG_ETH0_TRANSMIT_Q2_PTR      ((volatile un_ETH_TRANSMIT_Q2_PTR_t*) 0x40481444UL)
#define CYREG_ETH0_TRANSMIT_Q3_PTR      ((volatile un_ETH_TRANSMIT_Q3_PTR_t*) 0x40481448UL)
#define CYREG_ETH0_TRANSMIT_Q15_PTR     ((volatile un_ETH_TRANSMIT_Q15_PTR_t*) 0x40481478UL)
#define CYREG_ETH0_RECEIVE_Q1_PTR       ((volatile un_ETH_RECEIVE_Q1_PTR_t*) 0x40481480UL)
#define CYREG_ETH0_RECEIVE_Q2_PTR       ((volatile un_ETH_RECEIVE_Q2_PTR_t*) 0x40481484UL)
#define CYREG_ETH0_RECEIVE_Q3_PTR       ((volatile un_ETH_RECEIVE_Q3_PTR_t*) 0x40481488UL)
#define CYREG_ETH0_RECEIVE_Q7_PTR       ((volatile un_ETH_RECEIVE_Q7_PTR_t*) 0x40481498UL)
#define CYREG_ETH0_DMA_RXBUF_SIZE_Q1    ((volatile un_ETH_DMA_RXBUF_SIZE_Q1_t*) 0x404814A0UL)
#define CYREG_ETH0_DMA_RXBUF_SIZE_Q2    ((volatile un_ETH_DMA_RXBUF_SIZE_Q2_t*) 0x404814A4UL)
#define CYREG_ETH0_DMA_RXBUF_SIZE_Q3    ((volatile un_ETH_DMA_RXBUF_SIZE_Q3_t*) 0x404814A8UL)
#define CYREG_ETH0_DMA_RXBUF_SIZE_Q7    ((volatile un_ETH_DMA_RXBUF_SIZE_Q7_t*) 0x404814B8UL)
#define CYREG_ETH0_CBS_CONTROL          ((volatile un_ETH_CBS_CONTROL_t*) 0x404814BCUL)
#define CYREG_ETH0_CBS_IDLESLOPE_Q_A    ((volatile un_ETH_CBS_IDLESLOPE_Q_A_t*) 0x404814C0UL)
#define CYREG_ETH0_CBS_IDLESLOPE_Q_B    ((volatile un_ETH_CBS_IDLESLOPE_Q_B_t*) 0x404814C4UL)
#define CYREG_ETH0_UPPER_TX_Q_BASE_ADDR ((volatile un_ETH_UPPER_TX_Q_BASE_ADDR_t*) 0x404814C8UL)
#define CYREG_ETH0_TX_BD_CONTROL        ((volatile un_ETH_TX_BD_CONTROL_t*) 0x404814CCUL)
#define CYREG_ETH0_RX_BD_CONTROL        ((volatile un_ETH_RX_BD_CONTROL_t*) 0x404814D0UL)
#define CYREG_ETH0_UPPER_RX_Q_BASE_ADDR ((volatile un_ETH_UPPER_RX_Q_BASE_ADDR_t*) 0x404814D4UL)
#define CYREG_ETH0_HIDDEN_REG0          ((volatile un_ETH_HIDDEN_REG0_t*) 0x404814E0UL)
#define CYREG_ETH0_HIDDEN_REG1          ((volatile un_ETH_HIDDEN_REG1_t*) 0x404814E4UL)
#define CYREG_ETH0_HIDDEN_REG2          ((volatile un_ETH_HIDDEN_REG2_t*) 0x404814E8UL)
#define CYREG_ETH0_HIDDEN_REG3          ((volatile un_ETH_HIDDEN_REG3_t*) 0x404814ECUL)
#define CYREG_ETH0_HIDDEN_REG4          ((volatile un_ETH_HIDDEN_REG4_t*) 0x404814F8UL)
#define CYREG_ETH0_HIDDEN_REG5          ((volatile un_ETH_HIDDEN_REG5_t*) 0x404814FCUL)
#define CYREG_ETH0_SCREENING_TYPE_1_REGISTER_0 ((volatile un_ETH_SCREENING_TYPE_1_REGISTER_0_t*) 0x40481500UL)
#define CYREG_ETH0_SCREENING_TYPE_1_REGISTER_1 ((volatile un_ETH_SCREENING_TYPE_1_REGISTER_1_t*) 0x40481504UL)
#define CYREG_ETH0_SCREENING_TYPE_1_REGISTER_2 ((volatile un_ETH_SCREENING_TYPE_1_REGISTER_2_t*) 0x40481508UL)
#define CYREG_ETH0_SCREENING_TYPE_1_REGISTER_3 ((volatile un_ETH_SCREENING_TYPE_1_REGISTER_3_t*) 0x4048150CUL)
#define CYREG_ETH0_SCREENING_TYPE_1_REGISTER_4 ((volatile un_ETH_SCREENING_TYPE_1_REGISTER_4_t*) 0x40481510UL)
#define CYREG_ETH0_SCREENING_TYPE_1_REGISTER_5 ((volatile un_ETH_SCREENING_TYPE_1_REGISTER_5_t*) 0x40481514UL)
#define CYREG_ETH0_SCREENING_TYPE_1_REGISTER_6 ((volatile un_ETH_SCREENING_TYPE_1_REGISTER_6_t*) 0x40481518UL)
#define CYREG_ETH0_SCREENING_TYPE_1_REGISTER_7 ((volatile un_ETH_SCREENING_TYPE_1_REGISTER_7_t*) 0x4048151CUL)
#define CYREG_ETH0_SCREENING_TYPE_1_REGISTER_8 ((volatile un_ETH_SCREENING_TYPE_1_REGISTER_8_t*) 0x40481520UL)
#define CYREG_ETH0_SCREENING_TYPE_1_REGISTER_9 ((volatile un_ETH_SCREENING_TYPE_1_REGISTER_9_t*) 0x40481524UL)
#define CYREG_ETH0_SCREENING_TYPE_1_REGISTER_10 ((volatile un_ETH_SCREENING_TYPE_1_REGISTER_10_t*) 0x40481528UL)
#define CYREG_ETH0_SCREENING_TYPE_1_REGISTER_11 ((volatile un_ETH_SCREENING_TYPE_1_REGISTER_11_t*) 0x4048152CUL)
#define CYREG_ETH0_SCREENING_TYPE_1_REGISTER_12 ((volatile un_ETH_SCREENING_TYPE_1_REGISTER_12_t*) 0x40481530UL)
#define CYREG_ETH0_SCREENING_TYPE_1_REGISTER_13 ((volatile un_ETH_SCREENING_TYPE_1_REGISTER_13_t*) 0x40481534UL)
#define CYREG_ETH0_SCREENING_TYPE_1_REGISTER_14 ((volatile un_ETH_SCREENING_TYPE_1_REGISTER_14_t*) 0x40481538UL)
#define CYREG_ETH0_SCREENING_TYPE_1_REGISTER_15 ((volatile un_ETH_SCREENING_TYPE_1_REGISTER_15_t*) 0x4048153CUL)
#define CYREG_ETH0_SCREENING_TYPE_2_REGISTER_0 ((volatile un_ETH_SCREENING_TYPE_2_REGISTER_0_t*) 0x40481540UL)
#define CYREG_ETH0_SCREENING_TYPE_2_REGISTER_1 ((volatile un_ETH_SCREENING_TYPE_2_REGISTER_1_t*) 0x40481544UL)
#define CYREG_ETH0_SCREENING_TYPE_2_REGISTER_2 ((volatile un_ETH_SCREENING_TYPE_2_REGISTER_2_t*) 0x40481548UL)
#define CYREG_ETH0_SCREENING_TYPE_2_REGISTER_3 ((volatile un_ETH_SCREENING_TYPE_2_REGISTER_3_t*) 0x4048154CUL)
#define CYREG_ETH0_SCREENING_TYPE_2_REGISTER_4 ((volatile un_ETH_SCREENING_TYPE_2_REGISTER_4_t*) 0x40481550UL)
#define CYREG_ETH0_SCREENING_TYPE_2_REGISTER_5 ((volatile un_ETH_SCREENING_TYPE_2_REGISTER_5_t*) 0x40481554UL)
#define CYREG_ETH0_SCREENING_TYPE_2_REGISTER_6 ((volatile un_ETH_SCREENING_TYPE_2_REGISTER_6_t*) 0x40481558UL)
#define CYREG_ETH0_SCREENING_TYPE_2_REGISTER_7 ((volatile un_ETH_SCREENING_TYPE_2_REGISTER_7_t*) 0x4048155CUL)
#define CYREG_ETH0_SCREENING_TYPE_2_REGISTER_8 ((volatile un_ETH_SCREENING_TYPE_2_REGISTER_8_t*) 0x40481560UL)
#define CYREG_ETH0_SCREENING_TYPE_2_REGISTER_9 ((volatile un_ETH_SCREENING_TYPE_2_REGISTER_9_t*) 0x40481564UL)
#define CYREG_ETH0_SCREENING_TYPE_2_REGISTER_10 ((volatile un_ETH_SCREENING_TYPE_2_REGISTER_10_t*) 0x40481568UL)
#define CYREG_ETH0_SCREENING_TYPE_2_REGISTER_11 ((volatile un_ETH_SCREENING_TYPE_2_REGISTER_11_t*) 0x4048156CUL)
#define CYREG_ETH0_SCREENING_TYPE_2_REGISTER_12 ((volatile un_ETH_SCREENING_TYPE_2_REGISTER_12_t*) 0x40481570UL)
#define CYREG_ETH0_SCREENING_TYPE_2_REGISTER_13 ((volatile un_ETH_SCREENING_TYPE_2_REGISTER_13_t*) 0x40481574UL)
#define CYREG_ETH0_SCREENING_TYPE_2_REGISTER_14 ((volatile un_ETH_SCREENING_TYPE_2_REGISTER_14_t*) 0x40481578UL)
#define CYREG_ETH0_SCREENING_TYPE_2_REGISTER_15 ((volatile un_ETH_SCREENING_TYPE_2_REGISTER_15_t*) 0x4048157CUL)
#define CYREG_ETH0_TX_SCHED_CTRL        ((volatile un_ETH_TX_SCHED_CTRL_t*) 0x40481580UL)
#define CYREG_ETH0_BW_RATE_LIMIT_Q0TO3  ((volatile un_ETH_BW_RATE_LIMIT_Q0TO3_t*) 0x40481590UL)
#define CYREG_ETH0_BW_RATE_LIMIT_Q4TO7  ((volatile un_ETH_BW_RATE_LIMIT_Q4TO7_t*) 0x40481594UL)
#define CYREG_ETH0_BW_RATE_LIMIT_Q8TO11 ((volatile un_ETH_BW_RATE_LIMIT_Q8TO11_t*) 0x40481598UL)
#define CYREG_ETH0_BW_RATE_LIMIT_Q12TO15 ((volatile un_ETH_BW_RATE_LIMIT_Q12TO15_t*) 0x4048159CUL)
#define CYREG_ETH0_TX_Q_SEG_ALLOC_Q0TO7 ((volatile un_ETH_TX_Q_SEG_ALLOC_Q0TO7_t*) 0x404815A0UL)
#define CYREG_ETH0_TX_Q_SEG_ALLOC_Q8TO15 ((volatile un_ETH_TX_Q_SEG_ALLOC_Q8TO15_t*) 0x404815A4UL)
#define CYREG_ETH0_RECEIVE_Q8_PTR       ((volatile un_ETH_RECEIVE_Q8_PTR_t*) 0x404815C0UL)
#define CYREG_ETH0_RECEIVE_Q15_PTR      ((volatile un_ETH_RECEIVE_Q15_PTR_t*) 0x404815DCUL)
#define CYREG_ETH0_DMA_RXBUF_SIZE_Q8    ((volatile un_ETH_DMA_RXBUF_SIZE_Q8_t*) 0x404815E0UL)
#define CYREG_ETH0_DMA_RXBUF_SIZE_Q15   ((volatile un_ETH_DMA_RXBUF_SIZE_Q15_t*) 0x404815FCUL)
#define CYREG_ETH0_INT_Q1_ENABLE        ((volatile un_ETH_INT_Q1_ENABLE_t*) 0x40481600UL)
#define CYREG_ETH0_INT_Q2_ENABLE        ((volatile un_ETH_INT_Q2_ENABLE_t*) 0x40481604UL)
#define CYREG_ETH0_INT_Q3_ENABLE        ((volatile un_ETH_INT_Q3_ENABLE_t*) 0x40481608UL)
#define CYREG_ETH0_INT_Q7_ENABLE        ((volatile un_ETH_INT_Q7_ENABLE_t*) 0x40481618UL)
#define CYREG_ETH0_INT_Q1_DISABLE       ((volatile un_ETH_INT_Q1_DISABLE_t*) 0x40481620UL)
#define CYREG_ETH0_INT_Q2_DISABLE       ((volatile un_ETH_INT_Q2_DISABLE_t*) 0x40481624UL)
#define CYREG_ETH0_INT_Q3_DISABLE       ((volatile un_ETH_INT_Q3_DISABLE_t*) 0x40481628UL)
#define CYREG_ETH0_INT_Q7_DISABLE       ((volatile un_ETH_INT_Q7_DISABLE_t*) 0x40481638UL)
#define CYREG_ETH0_INT_Q1_MASK          ((volatile un_ETH_INT_Q1_MASK_t*) 0x40481640UL)
#define CYREG_ETH0_INT_Q2_MASK          ((volatile un_ETH_INT_Q2_MASK_t*) 0x40481644UL)
#define CYREG_ETH0_INT_Q3_MASK          ((volatile un_ETH_INT_Q3_MASK_t*) 0x40481648UL)
#define CYREG_ETH0_INT_Q7_MASK          ((volatile un_ETH_INT_Q7_MASK_t*) 0x40481658UL)
#define CYREG_ETH0_INT_Q8_ENABLE        ((volatile un_ETH_INT_Q8_ENABLE_t*) 0x40481660UL)
#define CYREG_ETH0_INT_Q15_ENABLE       ((volatile un_ETH_INT_Q15_ENABLE_t*) 0x4048167CUL)
#define CYREG_ETH0_INT_Q8_DISABLE       ((volatile un_ETH_INT_Q8_DISABLE_t*) 0x40481680UL)
#define CYREG_ETH0_INT_Q15_DISABLE      ((volatile un_ETH_INT_Q15_DISABLE_t*) 0x4048169CUL)
#define CYREG_ETH0_INT_Q8_MASK          ((volatile un_ETH_INT_Q8_MASK_t*) 0x404816A0UL)
#define CYREG_ETH0_INT_Q15_MASK         ((volatile un_ETH_INT_Q15_MASK_t*) 0x404816BCUL)
#define CYREG_ETH0_SCREENING_TYPE_2_ETHERTYPE_REG_0 ((volatile un_ETH_SCREENING_TYPE_2_ETHERTYPE_REG_0_t*) 0x404816E0UL)
#define CYREG_ETH0_SCREENING_TYPE_2_ETHERTYPE_REG_1 ((volatile un_ETH_SCREENING_TYPE_2_ETHERTYPE_REG_1_t*) 0x404816E4UL)
#define CYREG_ETH0_SCREENING_TYPE_2_ETHERTYPE_REG_2 ((volatile un_ETH_SCREENING_TYPE_2_ETHERTYPE_REG_2_t*) 0x404816E8UL)
#define CYREG_ETH0_SCREENING_TYPE_2_ETHERTYPE_REG_3 ((volatile un_ETH_SCREENING_TYPE_2_ETHERTYPE_REG_3_t*) 0x404816ECUL)
#define CYREG_ETH0_SCREENING_TYPE_2_ETHERTYPE_REG_4 ((volatile un_ETH_SCREENING_TYPE_2_ETHERTYPE_REG_4_t*) 0x404816F0UL)
#define CYREG_ETH0_SCREENING_TYPE_2_ETHERTYPE_REG_5 ((volatile un_ETH_SCREENING_TYPE_2_ETHERTYPE_REG_5_t*) 0x404816F4UL)
#define CYREG_ETH0_SCREENING_TYPE_2_ETHERTYPE_REG_6 ((volatile un_ETH_SCREENING_TYPE_2_ETHERTYPE_REG_6_t*) 0x404816F8UL)
#define CYREG_ETH0_SCREENING_TYPE_2_ETHERTYPE_REG_7 ((volatile un_ETH_SCREENING_TYPE_2_ETHERTYPE_REG_7_t*) 0x404816FCUL)
#define CYREG_ETH0_TYPE2_COMPARE_0_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_0_WORD_0_t*) 0x40481700UL)
#define CYREG_ETH0_TYPE2_COMPARE_0_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_0_WORD_1_t*) 0x40481704UL)
#define CYREG_ETH0_TYPE2_COMPARE_1_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_1_WORD_0_t*) 0x40481708UL)
#define CYREG_ETH0_TYPE2_COMPARE_1_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_1_WORD_1_t*) 0x4048170CUL)
#define CYREG_ETH0_TYPE2_COMPARE_2_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_2_WORD_0_t*) 0x40481710UL)
#define CYREG_ETH0_TYPE2_COMPARE_2_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_2_WORD_1_t*) 0x40481714UL)
#define CYREG_ETH0_TYPE2_COMPARE_3_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_3_WORD_0_t*) 0x40481718UL)
#define CYREG_ETH0_TYPE2_COMPARE_3_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_3_WORD_1_t*) 0x4048171CUL)
#define CYREG_ETH0_TYPE2_COMPARE_4_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_4_WORD_0_t*) 0x40481720UL)
#define CYREG_ETH0_TYPE2_COMPARE_4_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_4_WORD_1_t*) 0x40481724UL)
#define CYREG_ETH0_TYPE2_COMPARE_5_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_5_WORD_0_t*) 0x40481728UL)
#define CYREG_ETH0_TYPE2_COMPARE_5_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_5_WORD_1_t*) 0x4048172CUL)
#define CYREG_ETH0_TYPE2_COMPARE_6_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_6_WORD_0_t*) 0x40481730UL)
#define CYREG_ETH0_TYPE2_COMPARE_6_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_6_WORD_1_t*) 0x40481734UL)
#define CYREG_ETH0_TYPE2_COMPARE_7_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_7_WORD_0_t*) 0x40481738UL)
#define CYREG_ETH0_TYPE2_COMPARE_7_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_7_WORD_1_t*) 0x4048173CUL)
#define CYREG_ETH0_TYPE2_COMPARE_8_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_8_WORD_0_t*) 0x40481740UL)
#define CYREG_ETH0_TYPE2_COMPARE_8_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_8_WORD_1_t*) 0x40481744UL)
#define CYREG_ETH0_TYPE2_COMPARE_9_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_9_WORD_0_t*) 0x40481748UL)
#define CYREG_ETH0_TYPE2_COMPARE_9_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_9_WORD_1_t*) 0x4048174CUL)
#define CYREG_ETH0_TYPE2_COMPARE_10_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_10_WORD_0_t*) 0x40481750UL)
#define CYREG_ETH0_TYPE2_COMPARE_10_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_10_WORD_1_t*) 0x40481754UL)
#define CYREG_ETH0_TYPE2_COMPARE_11_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_11_WORD_0_t*) 0x40481758UL)
#define CYREG_ETH0_TYPE2_COMPARE_11_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_11_WORD_1_t*) 0x4048175CUL)
#define CYREG_ETH0_TYPE2_COMPARE_12_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_12_WORD_0_t*) 0x40481760UL)
#define CYREG_ETH0_TYPE2_COMPARE_12_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_12_WORD_1_t*) 0x40481764UL)
#define CYREG_ETH0_TYPE2_COMPARE_13_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_13_WORD_0_t*) 0x40481768UL)
#define CYREG_ETH0_TYPE2_COMPARE_13_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_13_WORD_1_t*) 0x4048176CUL)
#define CYREG_ETH0_TYPE2_COMPARE_14_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_14_WORD_0_t*) 0x40481770UL)
#define CYREG_ETH0_TYPE2_COMPARE_14_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_14_WORD_1_t*) 0x40481774UL)
#define CYREG_ETH0_TYPE2_COMPARE_15_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_15_WORD_0_t*) 0x40481778UL)
#define CYREG_ETH0_TYPE2_COMPARE_15_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_15_WORD_1_t*) 0x4048177CUL)
#define CYREG_ETH0_TYPE2_COMPARE_16_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_16_WORD_0_t*) 0x40481780UL)
#define CYREG_ETH0_TYPE2_COMPARE_16_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_16_WORD_1_t*) 0x40481784UL)
#define CYREG_ETH0_TYPE2_COMPARE_17_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_17_WORD_0_t*) 0x40481788UL)
#define CYREG_ETH0_TYPE2_COMPARE_17_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_17_WORD_1_t*) 0x4048178CUL)
#define CYREG_ETH0_TYPE2_COMPARE_18_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_18_WORD_0_t*) 0x40481790UL)
#define CYREG_ETH0_TYPE2_COMPARE_18_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_18_WORD_1_t*) 0x40481794UL)
#define CYREG_ETH0_TYPE2_COMPARE_19_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_19_WORD_0_t*) 0x40481798UL)
#define CYREG_ETH0_TYPE2_COMPARE_19_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_19_WORD_1_t*) 0x4048179CUL)
#define CYREG_ETH0_TYPE2_COMPARE_20_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_20_WORD_0_t*) 0x404817A0UL)
#define CYREG_ETH0_TYPE2_COMPARE_20_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_20_WORD_1_t*) 0x404817A4UL)
#define CYREG_ETH0_TYPE2_COMPARE_21_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_21_WORD_0_t*) 0x404817A8UL)
#define CYREG_ETH0_TYPE2_COMPARE_21_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_21_WORD_1_t*) 0x404817ACUL)
#define CYREG_ETH0_TYPE2_COMPARE_22_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_22_WORD_0_t*) 0x404817B0UL)
#define CYREG_ETH0_TYPE2_COMPARE_22_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_22_WORD_1_t*) 0x404817B4UL)
#define CYREG_ETH0_TYPE2_COMPARE_23_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_23_WORD_0_t*) 0x404817B8UL)
#define CYREG_ETH0_TYPE2_COMPARE_23_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_23_WORD_1_t*) 0x404817BCUL)
#define CYREG_ETH0_TYPE2_COMPARE_24_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_24_WORD_0_t*) 0x404817C0UL)
#define CYREG_ETH0_TYPE2_COMPARE_24_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_24_WORD_1_t*) 0x404817C4UL)
#define CYREG_ETH0_TYPE2_COMPARE_25_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_25_WORD_0_t*) 0x404817C8UL)
#define CYREG_ETH0_TYPE2_COMPARE_25_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_25_WORD_1_t*) 0x404817CCUL)
#define CYREG_ETH0_TYPE2_COMPARE_26_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_26_WORD_0_t*) 0x404817D0UL)
#define CYREG_ETH0_TYPE2_COMPARE_26_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_26_WORD_1_t*) 0x404817D4UL)
#define CYREG_ETH0_TYPE2_COMPARE_27_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_27_WORD_0_t*) 0x404817D8UL)
#define CYREG_ETH0_TYPE2_COMPARE_27_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_27_WORD_1_t*) 0x404817DCUL)
#define CYREG_ETH0_TYPE2_COMPARE_28_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_28_WORD_0_t*) 0x404817E0UL)
#define CYREG_ETH0_TYPE2_COMPARE_28_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_28_WORD_1_t*) 0x404817E4UL)
#define CYREG_ETH0_TYPE2_COMPARE_29_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_29_WORD_0_t*) 0x404817E8UL)
#define CYREG_ETH0_TYPE2_COMPARE_29_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_29_WORD_1_t*) 0x404817ECUL)
#define CYREG_ETH0_TYPE2_COMPARE_30_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_30_WORD_0_t*) 0x404817F0UL)
#define CYREG_ETH0_TYPE2_COMPARE_30_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_30_WORD_1_t*) 0x404817F4UL)
#define CYREG_ETH0_TYPE2_COMPARE_31_WORD_0 ((volatile un_ETH_TYPE2_COMPARE_31_WORD_0_t*) 0x404817F8UL)
#define CYREG_ETH0_TYPE2_COMPARE_31_WORD_1 ((volatile un_ETH_TYPE2_COMPARE_31_WORD_1_t*) 0x404817FCUL)

#endif /* _CYREG_ETH_H_ */


/* [] END OF FILE */
