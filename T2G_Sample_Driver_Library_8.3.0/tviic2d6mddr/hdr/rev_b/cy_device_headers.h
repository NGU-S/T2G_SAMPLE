/***************************************************************************//**
* \file cy_device_headers.h
*
* \brief
* Common header file to be included by the drivers.
*
* \note
* Generator version: 1.6.0.2045
* Database revision: TVIIC2D6MDDR_393233
*
********************************************************************************
* \copyright
* Copyright 2016-2024, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef _CY_DEVICE_HEADERS_H_
#define _CY_DEVICE_HEADERS_H_

#if defined (CYT4ENDBAS)
    #include "cyt4endbas.h"
#elif defined (CYT4ENDBCS)
    #include "cyt4endbcs.h"
#elif defined (CYT4ENDBES)
    #include "cyt4endbes.h"
#elif defined (CYT4ENDBGS)
    #include "cyt4endbgs.h"
#elif defined (CYT4ENDBJS)
    #include "cyt4endbjs.h"
#elif defined (CYT4ENDBLS)
    #include "cyt4endbls.h"
#elif defined (CYT4ENDBNS)
    #include "cyt4endbns.h"
#elif defined (CYT4ENDBQS)
    #include "cyt4endbqs.h"
#elif defined (CYT4ENDBSS)
    #include "cyt4endbss.h"
#elif defined (CYT4ENDBZS)
    #include "cyt4endbzs.h"
#else
    #error Undefined part number
#endif

#endif /* _CY_DEVICE_HEADERS_H_ */


/* [] END OF FILE */
