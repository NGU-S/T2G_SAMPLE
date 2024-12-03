/***************************************************************************//**
* \file SMIF_TestData.h
*
* \version 1.0
*
* \brief Supporting example file
*
********************************************************************************
* \copyright
* Copyright 2016-2020, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(SMIF_TESTDATA_H)
#define SMIF_TESTDATA_H

#define TEST_PROGRAM_SIZE   (0x00000200ul) // 512B

#pragma alignvar(2) /* Align when cast to CY_SMIF_FLASHDATA */
const uint8_t  programData[TEST_PROGRAM_SIZE] = {

0x01, 0x02, 0x04, 0x08, 0x01, 0x02, 0x04, 0x08, 0x01, 0x02, 0x04, 0x08, 0x01, 0x02, 0x04, 0x08,
0x11, 0x12, 0x14, 0x18, 0x11, 0x12, 0x14, 0x18, 0x11, 0x12, 0x14, 0x18, 0x11, 0x12, 0x14, 0x18, 
0x21, 0x22, 0x24, 0x28, 0x21, 0x22, 0x24, 0x28, 0x21, 0x22, 0x24, 0x28, 0x21, 0x22, 0x24, 0x28, 
0x31, 0x32, 0x34, 0x38, 0x31, 0x32, 0x34, 0x38, 0x31, 0x32, 0x34, 0x38, 0x31, 0x32, 0x34, 0x38, 
0x41, 0x42, 0x44, 0x48, 0x41, 0x42, 0x44, 0x48, 0x41, 0x42, 0x44, 0x48, 0x41, 0x42, 0x44, 0x48, 
0x51, 0x52, 0x54, 0x58, 0x51, 0x52, 0x54, 0x58, 0x51, 0x52, 0x54, 0x58, 0x51, 0x52, 0x54, 0x58, 
0x61, 0x62, 0x64, 0x68, 0x61, 0x62, 0x64, 0x68, 0x61, 0x62, 0x64, 0x68, 0x61, 0x62, 0x64, 0x68, 
0x71, 0x72, 0x74, 0x78, 0x71, 0x72, 0x74, 0x78, 0x71, 0x72, 0x74, 0x78, 0x71, 0x72, 0x74, 0x78, 
0x81, 0x82, 0x84, 0x88, 0x81, 0x82, 0x84, 0x88, 0x81, 0x82, 0x84, 0x88, 0x81, 0x82, 0x84, 0x88, 
0x91, 0x92, 0x94, 0x98, 0x91, 0x92, 0x94, 0x98, 0x91, 0x92, 0x94, 0x98, 0x91, 0x92, 0x94, 0x98, 
0xA1, 0xA2, 0xA4, 0xA8, 0xA1, 0xA2, 0xA4, 0xA8, 0xA1, 0xA2, 0xA4, 0xA8, 0xA1, 0xA2, 0xA4, 0xA8, 
0xB1, 0xB2, 0xB4, 0xB8, 0xB1, 0xB2, 0xB4, 0xB8, 0xB1, 0xB2, 0xB4, 0xB8, 0xB1, 0xB2, 0xB4, 0xB8, 
0xC1, 0xC2, 0xC4, 0xC8, 0xC1, 0xC2, 0xC4, 0xC8, 0xC1, 0xC2, 0xC4, 0xC8, 0xC1, 0xC2, 0xC4, 0xC8, 
0xD1, 0xD2, 0xD4, 0xD8, 0xD1, 0xD2, 0xD4, 0xD8, 0xD1, 0xD2, 0xD4, 0xD8, 0xD1, 0xD2, 0xD4, 0xD8, 
0xE1, 0xE2, 0xE4, 0xE8, 0xE1, 0xE2, 0xE4, 0xE8, 0xE1, 0xE2, 0xE4, 0xE8, 0xE1, 0xE2, 0xE4, 0xE8, 
0xF1, 0xF2, 0xF4, 0xF8, 0xF1, 0xF2, 0xF4, 0xF8, 0xF1, 0xF2, 0xF4, 0xF8, 0xF1, 0xF2, 0x54, 0x65, 

0x01, 0x02, 0x04, 0x08, 0x01, 0x02, 0x04, 0x08, 0x01, 0x02, 0x04, 0x08, 0x01, 0x02, 0x04, 0x08,
0x11, 0x12, 0x14, 0x18, 0x11, 0x12, 0x14, 0x18, 0x11, 0x12, 0x14, 0x18, 0x11, 0x12, 0x14, 0x18, 
0x21, 0x22, 0x24, 0x28, 0x21, 0x22, 0x24, 0x28, 0x21, 0x22, 0x24, 0x28, 0x21, 0x22, 0x24, 0x28, 
0x31, 0x32, 0x34, 0x38, 0x31, 0x32, 0x34, 0x38, 0x31, 0x32, 0x34, 0x38, 0x31, 0x32, 0x34, 0x38, 
0x41, 0x42, 0x44, 0x48, 0x41, 0x42, 0x44, 0x48, 0x41, 0x42, 0x44, 0x48, 0x41, 0x42, 0x44, 0x48, 
0x51, 0x52, 0x54, 0x58, 0x51, 0x52, 0x54, 0x58, 0x51, 0x52, 0x54, 0x58, 0x51, 0x52, 0x54, 0x58, 
0x61, 0x62, 0x64, 0x68, 0x61, 0x62, 0x64, 0x68, 0x61, 0x62, 0x64, 0x68, 0x61, 0x62, 0x64, 0x68, 
0x71, 0x72, 0x74, 0x78, 0x71, 0x72, 0x74, 0x78, 0x71, 0x72, 0x74, 0x78, 0x71, 0x72, 0x74, 0x78, 
0x81, 0x82, 0x84, 0x88, 0x81, 0x82, 0x84, 0x88, 0x81, 0x82, 0x84, 0x88, 0x81, 0x82, 0x84, 0x88, 
0x91, 0x92, 0x94, 0x98, 0x91, 0x92, 0x94, 0x98, 0x91, 0x92, 0x94, 0x98, 0x91, 0x92, 0x94, 0x98, 
0xA1, 0xA2, 0xA4, 0xA8, 0xA1, 0xA2, 0xA4, 0xA8, 0xA1, 0xA2, 0xA4, 0xA8, 0xA1, 0xA2, 0xA4, 0xA8, 
0xB1, 0xB2, 0xB4, 0xB8, 0xB1, 0xB2, 0xB4, 0xB8, 0xB1, 0xB2, 0xB4, 0xB8, 0xB1, 0xB2, 0xB4, 0xB8, 
0xC1, 0xC2, 0xC4, 0xC8, 0xC1, 0xC2, 0xC4, 0xC8, 0xC1, 0xC2, 0xC4, 0xC8, 0xC1, 0xC2, 0xC4, 0xC8, 
0xD1, 0xD2, 0xD4, 0xD8, 0xD1, 0xD2, 0xD4, 0xD8, 0xD1, 0xD2, 0xD4, 0xD8, 0xD1, 0xD2, 0xD4, 0xD8, 
0xE1, 0xE2, 0xE4, 0xE8, 0xE1, 0xE2, 0xE4, 0xE8, 0xE1, 0xE2, 0xE4, 0xE8, 0xE1, 0xE2, 0xE4, 0xE8, 
0xF1, 0xF2, 0xF4, 0xF8, 0xF1, 0xF2, 0xF4, 0xF8, 0xF1, 0xF2, 0xF4, 0xF8, 0xF1, 0xF2, 0x54, 0x65, 

};
#endif
