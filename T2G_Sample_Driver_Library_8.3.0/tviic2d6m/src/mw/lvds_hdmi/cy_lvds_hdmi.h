/***************************************************************************//**
* \file cy_lvds_hdmi.h
* \version 1.0
*
* \brief
* Provides an API declaration of the LVDS to HDMI transmission driver.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

/**
* Refer to the technical reference manual (TRM) and the device datasheet.
*
* \defgroup group_mw_lvds_hdmi_macros Macro
* \defgroup group_mw_lvds_hdmi_functions Functions
* \defgroup group_mw_lvds_hdmi_datastructure Data structure
* \defgroup group_mw_lvds_hdmi_enums Enumerated types
*/

#ifndef CY_LVDS_HDMI_H_
#define CY_LVDS_HDMI_H_

/* Only applicable for the lite kit */
#ifdef CY_327BGA_EVKLITE_rev_a

#include <stddef.h>
#include <stdbool.h>
#include "cy_device_headers.h"
#include "cy_i2c_hdmi.h"
#include "cy_base_hdmi.h"


#if defined(__cplusplus)
extern "C" {
#endif

/**
* \addtogroup group_mw_lvds_hdmi_macros
* \{
*/

#define DEBUG_IT6263

/* Macros for DDC Address */
#define DDC_HDCP_ADDRESS                        0x74
#define DDC_EDID_ADDRESS                        0xA0
#define DDC_FIFO_MAXREQ                         0x20

#define HDMI_INPUT_SIGNAL_TYPE                  0 // 24 bit sync seperate    
  
/** \} group_mw_lvds_hdmi_macros */

/**
* \addtogroup group_mw_lvds_hdmi_enums
* \{
*/

/* Function return value types */
typedef enum
{
    CY_HDMI_TRX_SUCCESS   = 0x00u,      /**< Returned successful */
    CY_HDMI_TRX_ERROR     = 0x01u,      /**< General error */
    CY_HDMI_TRX_BAD_PARAM = 0x02u,      /**< Bad parameter was passed */
} cy_en_hdmi_trx_status_t;

/* LVDS source encoding format */
typedef enum
{
    CY_LVDS_FORMAT_JEIDA  	= 0x00u,
    CY_LVDS_FORMAT_VESA  	= 0x01u
} cy_en_lvds_format_type_t ;

/* LVDS source input link type */
typedef enum
{
    CY_LVDS_LINK_SINGLE  	= 0x00u,
    CY_LVDS_LINK_DUAL  		= 0x01u
} cy_en_lvds_input_type_t ;

/* LVDS source bit format type */
typedef enum
{
    CY_LVDS_LINK_6BIT  		= 0x00u,
    CY_LVDS_LINK_8BIT  		= 0x01u,
    CY_LVDS_LINK_10BIT  	= 0x02u
} cy_en_lvds_bit_type_t ;

/* LVDS to HDMI transceiver aspect ratio */
typedef enum 
{
    CY_HDMI_ASPECT_RATIO_4x3    = 0x00u,
    CY_HDMI_ASPECT_RATIO_16x9   = 0x01u
} cy_en_hdmi_aspec_type_t;

/* LVDS to HDMI transceiver color and sequence format */
typedef enum 
{
    CY_HDMI_COLOR_RGB444    = 0x00u,
    CY_HDMI_COLOR_YUV444    = 0x01u,
    CY_HDMI_COLOR_YUV422    = 0x02u
} cy_en_hdmi_color_format_type_t ;

/* LVDS to HDMI transceiver colorimetry */
typedef enum
{
    CY_HDMI_COLORIMETRY_ITU601  = 0x00u,
    CY_HDMI_COLORIMETRY_ITU709  = 0x01u
} cy_en_hdmi_colorimetry_type_t ;

/* Values for the hdmi video type */
typedef enum 
{
    CY_HDMI_800x480p60     = 0u,
    CY_HDMI_640x480p60     = 1u,
    CY_HDMI_480p60         = 2u,
    CY_HDMI_480p60_16x9    = 3u,
    CY_HDMI_720p60         = 4u,
    CY_HDMI_1080i60        = 5u,
    CY_HDMI_480i60         = 6u,    
    CY_HDMI_480i60_16x9    = 7u,
    CY_HDMI_600p60         = 8u,
    CY_HDMI_1080p60        = 16u,
    CY_HDMI_576p50         = 17u,
    CY_HDMI_576p50_16x9    = 18u,
    CY_HDMI_720p50         = 19u,
    CY_HDMI_1080i50        = 20u,
    CY_HDMI_576i50         = 21u,
    CY_HDMI_576i50_16x9    = 22u,
    CY_HDMI_1080p50        = 31u,
    CY_HDMI_1080p24        = 32u,
    CY_HDMI_1080p48        = 33u,
    CY_HDMI_1080p25        = 34u,
    CY_HDMI_1080p30        = 35u,
    CY_HDMI_720p60_FP3D    = 0x84u,
    CY_HDMI_720p50_FP3D    = 0x93u,
    CY_HDMI_1080p24_FP3D   = 0xA0u,
} cy_en_hdmi_video_type_t ;

/* Supported HDMI input vendor list */
typedef enum 
{
    DELL_2408WPF        = 0u,
    HP_E27_G4           = 1u,
    HP_E27M_G4          = 2u,
    LONTIUM_Semi        = 3u,
    WAVESHARE_7inch     = 4u,
    WAVESHARE_5inch     = 5u,
    Unknown_Display     = 6u,
} cy_en_hdmi_vendor_name_t;


/** \} group_mw_lvds_hdmi_enums */


/**
* \addtogroup group_mw_lvds_hdmi_datastructure
* \{
*/

/* Structure to store the vendor specific information */
typedef struct 
{
    cy_en_hdmi_vendor_name_t    hdmiVendorName;
    uint8_t                     hdmiVIDC[8];
} cy_stc_hdmi_vendor_edid_t;

/* LVDS and HDMI control and status flags */
typedef struct
{
    uint8_t 	                    hdmiHpdStatus;
    uint8_t 	                    hdmiHpdChangeStatus;
    bool                            hdmiReGenTimingEnable;
    uint8_t                         hdmiIsChangeMode;
    uint8_t                         hdmiVideoModeSelect;
    uint8_t                         hdmiOutputColorDepth;
    uint8_t                         hdmiInputColorFormat;
    uint8_t                         hdmi3DFormat;
    uint8_t                         hdmiPixelRep;
    uint32_t                        hdmiVideoPixelClock;
    cy_en_hdmi_video_type_t         hdmiVIC;
    cy_en_hdmi_aspec_type_t         hdmiAspectRatio;
    cy_en_hdmi_colorimetry_type_t   hdmiColorimetry;
} cy_stc_hdmi_trx_status_t;

/* Structure configure the LVDS to HDMI transceiver */
typedef struct
{
    cy_en_lvds_bit_type_t           colorBits;
    cy_en_lvds_input_type_t 		singleOrDual;
    cy_en_lvds_format_type_t 		encodeFormat;
    cy_en_hdmi_color_format_type_t 	colorFormat;
    cy_en_hdmi_video_type_t         videoType;
} cy_stc_hdmi_trx_config_t;

/** \} group_mw_lvds_hdmi_datastructure */

/**
* \addtogroup group_mw_lvds_hdmi_functions
* \{
*/

/* LVDS to HDMI transceiver global function definition */
cy_en_hdmi_trx_status_t Cy_HDMI_Transceiver_DeInit(void);
cy_en_hdmi_trx_status_t Cy_HDMI_Transceiver_Init(cy_stc_hdmi_trx_config_t videoFormat);
cy_en_hdmi_trx_status_t Cy_HDMI_Transceiver_Sleep(void);
cy_en_hdmi_trx_status_t Cy_HDMI_Transceiver_Wakeup(void);
cy_en_hdmi_trx_status_t Cy_HDMI_Transceiver_DeviceLoop(void);
cy_en_hdmi_trx_status_t CY_HDMI_Transceiver_SetDisplayOption(cy_en_hdmi_video_type_t videoMode, cy_en_hdmi_color_format_type_t colorMode);

/** \} group_mw_lvds_hdmi_functions */


#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* CY_327BGA_EVKLITE_rev_a */

#endif  /* CY_LVDS_HDMI_H_ */

/* [] END OF FILE */
