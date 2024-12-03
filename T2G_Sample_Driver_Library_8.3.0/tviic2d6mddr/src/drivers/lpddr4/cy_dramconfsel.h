/***************************************************************************//**
* \file cy_dramconfsel.h
*   $Date: 2023-10-31 01:11:48 -0700 (Tue, 31 Oct 2023) $
*   $Revision: 325606 $
*
* \brief
*  Let's the user select which type of configuration shall be used to
*  init the LPDDR4 Controller
*
********************************************************************************
* \copyright
* Copyright 2020-2021, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(__DRAMCONFSEL_H__)
#define __DRAMCONFSEL_H__


#define SVN_REV_CY_DRAMCONFSEL_H         "$Revision: 325606 $"
#define SVN_DATE_CY_DRAMCONFSEL_H        "$Date: 2023-10-31 01:11:48 -0700 (Tue, 31 Oct 2023) $"

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */


/*please specify if you are using a Solution Designer Config or Macro Type Config*/
#define MANUAL_CONFIG                1 /* to use either Config_02_RD_LLLH_WR_LLLM_1_AC2.h,Config_02_RD_LLHH_WR_LLLM_1_AC2.h or ...*/
#define SOL_DESIGNER_CONFIG          2 /* to use a configuration prepared with Solution Designer */
#define RELEASE_BUILD_DUMMY_CONFIG   3 /* to avoid build errors in none LPDDR4 projects where no LPDDR4 config is available */

#define CONFIG_TYPE RELEASE_BUILD_DUMMY_CONFIG          //<------ set config type here

#if(CONFIG_TYPE==MANUAL_CONFIG)
    #include"cy_dram_config.h"            // driver must include this file as some timing parameters are needed for timing derating function
#elif(CONFIG_TYPE==SOL_DESIGNER_CONFIG)         // file which contains DRAM timing param. when manually configured.
    #include"lpddr4_cfg.h"                // driver must include this file as some timing parameters are needed for timing derating function
#elif(CONFIG_TYPE==RELEASE_BUILD_DUMMY_CONFIG)
    #include"cy_dram_config_dummy.h"
#else                                           // file from Solution Designer containing the timing param. 
    warning"Check the CONFIG_TYPE in cy_dramconfsel.h switch between config from Solution Designer to Manual Config Files with macros "
#endif


#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* __DRAMCONFSEL_H__ */

/* [] END OF FILE */
