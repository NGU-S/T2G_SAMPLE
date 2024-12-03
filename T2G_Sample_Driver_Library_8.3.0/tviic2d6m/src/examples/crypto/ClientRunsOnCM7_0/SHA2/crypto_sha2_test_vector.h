/***************************************************************************//**
* \file crypto_sha2_test_vector.h
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

#ifndef __CRYPTO_SHA2_TEST_VECTOR__
#define __CRYPTO_SHA2_TEST_VECTOR__

#ifdef __CRYPTO_ENABLE_TEST_VECTOR__

/* Refer https://www.di-mgt.com.au/sha_testvectors.html */
/* https://www.browserling.com/tools/sha2-hash */
/* https://emn178.github.io/online-tools/md4.html */
/*******************************************************************************
* SHA224
********************************************************************************/
#define SHA224_NUMBER_OF_TEST (10)
const uint8_t SHA224_Vector0_Msg0[] = "abc";
const uint8_t SHA224_Vector0_Msg1[] = "";
const uint8_t SHA224_Vector0_Msg2[] = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";
const uint8_t SHA224_Vector0_Msg3[] = "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu";
const uint8_t SHA224_Vector0_Msg4[] = "000000000000000000000000000000000000000000000000000000000000000";        // block length - 1
const uint8_t SHA224_Vector0_Msg5[] = "0000000000000000000000000000000000000000000000000000000000000000";       // block length
const uint8_t SHA224_Vector0_Msg6[] = "00000000000000000000000000000000000000000000000000000000000000000";      // block length + 1
const uint8_t SHA224_Vector0_Msg7[] = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";    // 2 x block length - 1
const uint8_t SHA224_Vector0_Msg8[] = "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";   // 2 x block length
const uint8_t SHA224_Vector0_Msg9[] = "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";  // 2 x block length + 1
const uint8_t * const SHA224_MsgPtr[SHA224_NUMBER_OF_TEST] = 
{
    SHA224_Vector0_Msg0,
    SHA224_Vector0_Msg1,
    SHA224_Vector0_Msg2,
    SHA224_Vector0_Msg3,
    SHA224_Vector0_Msg4,
    SHA224_Vector0_Msg5,
    SHA224_Vector0_Msg6,
    SHA224_Vector0_Msg7,
    SHA224_Vector0_Msg8,
    SHA224_Vector0_Msg9,
};
const uint32_t SHA224_MsgLen[SHA224_NUMBER_OF_TEST] = 
{
    sizeof(SHA224_Vector0_Msg0) / sizeof(SHA224_Vector0_Msg0[0]) - 1,
    sizeof(SHA224_Vector0_Msg1) / sizeof(SHA224_Vector0_Msg1[0]) - 1,
    sizeof(SHA224_Vector0_Msg2) / sizeof(SHA224_Vector0_Msg2[0]) - 1,
    sizeof(SHA224_Vector0_Msg3) / sizeof(SHA224_Vector0_Msg3[0]) - 1,
    sizeof(SHA224_Vector0_Msg4) / sizeof(SHA224_Vector0_Msg4[0]) - 1,
    sizeof(SHA224_Vector0_Msg5) / sizeof(SHA224_Vector0_Msg5[0]) - 1,
    sizeof(SHA224_Vector0_Msg6) / sizeof(SHA224_Vector0_Msg6[0]) - 1,
    sizeof(SHA224_Vector0_Msg7) / sizeof(SHA224_Vector0_Msg7[0]) - 1,
    sizeof(SHA224_Vector0_Msg8) / sizeof(SHA224_Vector0_Msg8[0]) - 1,
    sizeof(SHA224_Vector0_Msg9) / sizeof(SHA224_Vector0_Msg9[0]) - 1,
};
const uint8_t SHA224_hash_ref[SHA224_NUMBER_OF_TEST][224 / 8] = 
{
    {0x23,0x09,0x7d,0x22,0x34,0x05,0xd8,0x22,0x86,0x42,0xa4,0x77,0xbd,0xa2,0x55,0xb3,0x2a,0xad,0xbc,0xe4,0xbd,0xa0,0xb3,0xf7,0xe3,0x6c,0x9d,0xa7},
    {0xd1,0x4a,0x02,0x8c,0x2a,0x3a,0x2b,0xc9,0x47,0x61,0x02,0xbb,0x28,0x82,0x34,0xc4,0x15,0xa2,0xb0,0x1f,0x82,0x8e,0xa6,0x2a,0xc5,0xb3,0xe4,0x2f},
    {0x75,0x38,0x8b,0x16,0x51,0x27,0x76,0xcc,0x5d,0xba,0x5d,0xa1,0xfd,0x89,0x01,0x50,0xb0,0xc6,0x45,0x5c,0xb4,0xf5,0x8b,0x19,0x52,0x52,0x25,0x25},
    {0xc9,0x7c,0xa9,0xa5,0x59,0x85,0x0c,0xe9,0x7a,0x04,0xa9,0x6d,0xef,0x6d,0x99,0xa9,0xe0,0xe0,0xe2,0xab,0x14,0xe6,0xb8,0xdf,0x26,0x5f,0xc0,0xb3},
    {0x73,0x95,0x33,0x88,0x66,0x4f,0xd5,0xaa,0x65,0x0d,0xe8,0x6b,0xc6,0x69,0x69,0x01,0xe2,0xa3,0x6e,0x51,0xd0,0xf7,0xc2,0xb3,0xd6,0xc1,0xca,0x9a},
    {0xfc,0x5d,0x6a,0xed,0x71,0x46,0xd6,0x74,0x7d,0xd6,0xfc,0xa0,0x75,0xf9,0xfe,0x5a,0x30,0xa4,0xc0,0xc9,0xff,0x67,0xef,0xfc,0x48,0x4f,0x10,0xb5},
    {0x63,0xdf,0xe5,0x94,0x1a,0xc4,0xcd,0x8f,0x4d,0xd7,0x7b,0x0c,0x95,0xed,0xf3,0xb1,0x73,0xe9,0xb4,0x42,0xf8,0xe7,0x94,0x3e,0xf7,0xc6,0x0e,0x21},
    {0x8f,0x0c,0xf8,0x95,0x2d,0x26,0x8a,0xa0,0xe8,0x40,0xa2,0xb3,0xf6,0xbc,0x2b,0xf0,0x5c,0xaa,0x6c,0x67,0xac,0xae,0x0b,0xfd,0x7b,0xc8,0x4d,0x79},
    {0xfb,0x7e,0xcb,0x83,0xc5,0xda,0x42,0xcc,0x89,0x13,0x00,0x00,0x73,0x29,0x6c,0x8e,0x85,0x2e,0x35,0x36,0x91,0x97,0x06,0xd2,0xd3,0x88,0x70,0x04},
    {0xa2,0x1b,0xa8,0x38,0x90,0xb1,0x54,0xab,0x64,0x0a,0x42,0x57,0xcd,0x5a,0x84,0x4a,0xd5,0x0f,0xe8,0x05,0xc0,0x14,0x5d,0x7b,0x97,0x61,0x01,0xc1},
};
uint8_t SHA224_hash[SHA224_NUMBER_OF_TEST][224 / 8];

/*******************************************************************************
* SHA256
********************************************************************************/
#define SHA256_NUMBER_OF_TEST (10)
const uint8_t SHA256_Vector0_Msg0[] = "abc";
const uint8_t SHA256_Vector0_Msg1[] = "";
const uint8_t SHA256_Vector0_Msg2[] = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";
const uint8_t SHA256_Vector0_Msg3[] = "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu";
const uint8_t SHA256_Vector0_Msg4[] = "000000000000000000000000000000000000000000000000000000000000000";        // block length - 1
const uint8_t SHA256_Vector0_Msg5[] = "0000000000000000000000000000000000000000000000000000000000000000";       // block length
const uint8_t SHA256_Vector0_Msg6[] = "00000000000000000000000000000000000000000000000000000000000000000";      // block length + 1
const uint8_t SHA256_Vector0_Msg7[] = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";    // 2 x block length - 1
const uint8_t SHA256_Vector0_Msg8[] = "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";   // 2 x block length
const uint8_t SHA256_Vector0_Msg9[] = "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";  // 2 x block length + 1
const uint8_t * const SHA256_MsgPtr[SHA256_NUMBER_OF_TEST] = 
{
    SHA256_Vector0_Msg0,
    SHA256_Vector0_Msg1,
    SHA256_Vector0_Msg2,
    SHA256_Vector0_Msg3,
    SHA256_Vector0_Msg4,
    SHA256_Vector0_Msg5,
    SHA256_Vector0_Msg6,
    SHA256_Vector0_Msg7,
    SHA256_Vector0_Msg8,
    SHA256_Vector0_Msg9,
};
const uint32_t SHA256_MsgLen[SHA256_NUMBER_OF_TEST] = 
{
    sizeof(SHA256_Vector0_Msg0) / sizeof(SHA256_Vector0_Msg0[0]) - 1,
    sizeof(SHA256_Vector0_Msg1) / sizeof(SHA256_Vector0_Msg1[0]) - 1,
    sizeof(SHA256_Vector0_Msg2) / sizeof(SHA256_Vector0_Msg2[0]) - 1,
    sizeof(SHA256_Vector0_Msg3) / sizeof(SHA256_Vector0_Msg3[0]) - 1,
    sizeof(SHA256_Vector0_Msg4) / sizeof(SHA256_Vector0_Msg4[0]) - 1,
    sizeof(SHA256_Vector0_Msg5) / sizeof(SHA256_Vector0_Msg5[0]) - 1,
    sizeof(SHA256_Vector0_Msg6) / sizeof(SHA256_Vector0_Msg6[0]) - 1,
    sizeof(SHA256_Vector0_Msg7) / sizeof(SHA256_Vector0_Msg7[0]) - 1,
    sizeof(SHA256_Vector0_Msg8) / sizeof(SHA256_Vector0_Msg8[0]) - 1,
    sizeof(SHA256_Vector0_Msg9) / sizeof(SHA256_Vector0_Msg9[0]) - 1,
};
const uint8_t SHA256_hash_ref[SHA256_NUMBER_OF_TEST][256 / 8] = 
{
    {0xba,0x78,0x16,0xbf,0x8f,0x01,0xcf,0xea,0x41,0x41,0x40,0xde,0x5d,0xae,0x22,0x23,0xb0,0x03,0x61,0xa3,0x96,0x17,0x7a,0x9c,0xb4,0x10,0xff,0x61,0xf2,0x00,0x15,0xad},
    {0xe3,0xb0,0xc4,0x42,0x98,0xfc,0x1c,0x14,0x9a,0xfb,0xf4,0xc8,0x99,0x6f,0xb9,0x24,0x27,0xae,0x41,0xe4,0x64,0x9b,0x93,0x4c,0xa4,0x95,0x99,0x1b,0x78,0x52,0xb8,0x55},
    {0x24,0x8d,0x6a,0x61,0xd2,0x06,0x38,0xb8,0xe5,0xc0,0x26,0x93,0x0c,0x3e,0x60,0x39,0xa3,0x3c,0xe4,0x59,0x64,0xff,0x21,0x67,0xf6,0xec,0xed,0xd4,0x19,0xdb,0x06,0xc1},
    {0xcf,0x5b,0x16,0xa7,0x78,0xaf,0x83,0x80,0x03,0x6c,0xe5,0x9e,0x7b,0x04,0x92,0x37,0x0b,0x24,0x9b,0x11,0xe8,0xf0,0x7a,0x51,0xaf,0xac,0x45,0x03,0x7a,0xfe,0xe9,0xd1},
    {0xc7,0xdc,0x2d,0x25,0xe3,0x06,0x35,0x5c,0x97,0xaf,0x91,0x6e,0x8d,0x50,0xb2,0x7a,0x94,0x85,0x06,0xa7,0x4c,0x6b,0x2d,0xd1,0xb2,0x9e,0x2b,0x63,0xd0,0xa3,0xaa,0x8c},
    {0x60,0xe0,0x5b,0xd1,0xb1,0x95,0xaf,0x2f,0x94,0x11,0x2f,0xa7,0x19,0x7a,0x5c,0x88,0x28,0x90,0x58,0x84,0x0c,0xe7,0xc6,0xdf,0x96,0x93,0x75,0x6b,0xc6,0x25,0x0f,0x55},
    {0xe5,0x31,0xef,0x0f,0x96,0x24,0x09,0x17,0x09,0x17,0xab,0xf9,0xde,0x32,0x87,0xaf,0xec,0x23,0xdd,0x1c,0x42,0xc9,0xe1,0xfe,0xa6,0x6c,0x5f,0xea,0xb9,0x9e,0x8f,0x7c},
    {0x91,0x8c,0xeb,0x84,0xa4,0x71,0x7a,0xe1,0x16,0x78,0x2c,0x9a,0xed,0x17,0x25,0x69,0xde,0x14,0xba,0x57,0x90,0x5e,0x62,0x5e,0x14,0x75,0x4c,0x88,0x62,0xfd,0xbf,0xae},
    {0x45,0x72,0x57,0x91,0xc4,0x7b,0x32,0x61,0x8c,0xc5,0x7b,0x88,0x34,0x3e,0x2b,0xce,0xec,0x3b,0x0a,0x01,0xb8,0x3b,0xc9,0x7d,0x14,0x4a,0x2c,0xbc,0x11,0xa2,0x0c,0x3d},
    {0xbe,0xab,0x39,0x66,0x38,0x9f,0x2a,0xd4,0x95,0xc7,0xdb,0x4f,0x9d,0xc0,0x29,0xf1,0x6a,0xae,0x31,0xc7,0x6a,0xf3,0xeb,0xef,0xd9,0x75,0x4f,0xaf,0x0e,0x6d,0xdc,0xb4},
};
uint8_t SHA256_hash[SHA256_NUMBER_OF_TEST][256 / 8];

/*******************************************************************************
* SHA384
********************************************************************************/
#define SHA384_NUMBER_OF_TEST (10)
const uint8_t SHA384_Vector0_Msg0[] = "abc";
const uint8_t SHA384_Vector0_Msg1[] = "";
const uint8_t SHA384_Vector0_Msg2[] = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";
const uint8_t SHA384_Vector0_Msg3[] = "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu";
const uint8_t SHA384_Vector0_Msg4[] = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";        // block length - 1
const uint8_t SHA384_Vector0_Msg5[] = "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";       // block length
const uint8_t SHA384_Vector0_Msg6[] = "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";      // block length + 1
const uint8_t SHA384_Vector0_Msg7[] = "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";    // 2 x block length - 1
const uint8_t SHA384_Vector0_Msg8[] = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";   // 2 x block length
const uint8_t SHA384_Vector0_Msg9[] = "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";  // 2 x block length + 1
const uint8_t * const SHA384_MsgPtr[SHA384_NUMBER_OF_TEST] = 
{
    SHA384_Vector0_Msg0,
    SHA384_Vector0_Msg1,
    SHA384_Vector0_Msg2,
    SHA384_Vector0_Msg3,
    SHA384_Vector0_Msg4,
    SHA384_Vector0_Msg5,
    SHA384_Vector0_Msg6,
    SHA384_Vector0_Msg7,
    SHA384_Vector0_Msg8,
    SHA384_Vector0_Msg9,
};
const uint32_t SHA384_MsgLen[SHA384_NUMBER_OF_TEST] = 
{
    sizeof(SHA384_Vector0_Msg0) / sizeof(SHA384_Vector0_Msg0[0]) - 1,
    sizeof(SHA384_Vector0_Msg1) / sizeof(SHA384_Vector0_Msg1[0]) - 1,
    sizeof(SHA384_Vector0_Msg2) / sizeof(SHA384_Vector0_Msg2[0]) - 1,
    sizeof(SHA384_Vector0_Msg3) / sizeof(SHA384_Vector0_Msg3[0]) - 1,
    sizeof(SHA384_Vector0_Msg4) / sizeof(SHA384_Vector0_Msg4[0]) - 1,
    sizeof(SHA384_Vector0_Msg5) / sizeof(SHA384_Vector0_Msg5[0]) - 1,
    sizeof(SHA384_Vector0_Msg6) / sizeof(SHA384_Vector0_Msg6[0]) - 1,
    sizeof(SHA384_Vector0_Msg7) / sizeof(SHA384_Vector0_Msg7[0]) - 1,
    sizeof(SHA384_Vector0_Msg8) / sizeof(SHA384_Vector0_Msg8[0]) - 1,
    sizeof(SHA384_Vector0_Msg9) / sizeof(SHA384_Vector0_Msg9[0]) - 1,
};
const uint8_t SHA384_hash_ref[SHA384_NUMBER_OF_TEST][384 / 8] = 
{
    {0xcb,0x00,0x75,0x3f,0x45,0xa3,0x5e,0x8b,0xb5,0xa0,0x3d,0x69,0x9a,0xc6,0x50,0x07,0x27,0x2c,0x32,0xab,0x0e,0xde,0xd1,0x63,0x1a,0x8b,0x60,0x5a,0x43,0xff,0x5b,0xed,0x80,0x86,0x07,0x2b,0xa1,0xe7,0xcc,0x23,0x58,0xba,0xec,0xa1,0x34,0xc8,0x25,0xa7},
    {0x38,0xb0,0x60,0xa7,0x51,0xac,0x96,0x38,0x4c,0xd9,0x32,0x7e,0xb1,0xb1,0xe3,0x6a,0x21,0xfd,0xb7,0x11,0x14,0xbe,0x07,0x43,0x4c,0x0c,0xc7,0xbf,0x63,0xf6,0xe1,0xda,0x27,0x4e,0xde,0xbf,0xe7,0x6f,0x65,0xfb,0xd5,0x1a,0xd2,0xf1,0x48,0x98,0xb9,0x5b},
    {0x33,0x91,0xfd,0xdd,0xfc,0x8d,0xc7,0x39,0x37,0x07,0xa6,0x5b,0x1b,0x47,0x09,0x39,0x7c,0xf8,0xb1,0xd1,0x62,0xaf,0x05,0xab,0xfe,0x8f,0x45,0x0d,0xe5,0xf3,0x6b,0xc6,0xb0,0x45,0x5a,0x85,0x20,0xbc,0x4e,0x6f,0x5f,0xe9,0x5b,0x1f,0xe3,0xc8,0x45,0x2b},
    {0x09,0x33,0x0c,0x33,0xf7,0x11,0x47,0xe8,0x3d,0x19,0x2f,0xc7,0x82,0xcd,0x1b,0x47,0x53,0x11,0x1b,0x17,0x3b,0x3b,0x05,0xd2,0x2f,0xa0,0x80,0x86,0xe3,0xb0,0xf7,0x12,0xfc,0xc7,0xc7,0x1a,0x55,0x7e,0x2d,0xb9,0x66,0xc3,0xe9,0xfa,0x91,0x74,0x60,0x39},
    {0x3e,0xc1,0x20,0x73,0xd8,0x17,0xf3,0xdb,0xaf,0xed,0x35,0xc9,0x5a,0x2d,0x9a,0xaa,0x47,0x11,0xfa,0x31,0x06,0xa3,0x4a,0x5b,0x9c,0x6f,0x1b,0x99,0xee,0x3f,0xfb,0x46,0x66,0x44,0x79,0x44,0x8b,0xd3,0x90,0x20,0x3f,0xa5,0x82,0xd6,0x7c,0x32,0x17,0xfa},
    {0x5c,0x07,0x28,0xb0,0xb1,0x5b,0xeb,0x1d,0x5e,0xfe,0x1d,0x23,0xa7,0x59,0x94,0x96,0xa3,0x4b,0x16,0x38,0xa3,0xb4,0xa9,0x0b,0x9f,0x27,0x1f,0xc4,0xa8,0xae,0x0e,0xfb,0xf4,0x69,0xe6,0x88,0xc5,0xcb,0xc1,0xb9,0xe6,0xe2,0x21,0xc4,0xf8,0x41,0x0a,0x3c},
    {0x80,0x7f,0xc7,0xa4,0xea,0x2b,0xb9,0x79,0xc2,0x86,0x6b,0xa1,0x8e,0x8a,0x5e,0x4f,0xb6,0x49,0xb7,0x13,0x70,0x72,0x68,0x40,0xe4,0x2a,0x5c,0xcd,0xf5,0xfc,0x45,0x61,0xa5,0x81,0xd8,0x27,0x06,0x88,0x52,0xa7,0x45,0x64,0x87,0x4f,0x4e,0x59,0x4b,0x06},
    {0x6a,0x05,0x41,0xcf,0xf6,0x5b,0xd2,0xcd,0x2f,0xf3,0xd9,0x34,0x25,0x49,0xa2,0x8a,0xa1,0x16,0xd3,0x3d,0xcf,0x16,0xfd,0xbf,0x08,0x01,0x02,0x5b,0xfa,0xc8,0xa3,0x7c,0x25,0x45,0x2e,0x3d,0xf1,0x4d,0x17,0x65,0xc3,0xb9,0x87,0x40,0x86,0x80,0xb3,0xff},
    {0xed,0x6a,0xaa,0x4c,0xb7,0xac,0x25,0x7e,0xb2,0xc8,0x2c,0x71,0xd2,0x6a,0xc5,0x93,0xee,0xea,0x99,0x70,0x60,0xe4,0xe4,0x89,0x6d,0x05,0x5c,0xef,0xb2,0xe7,0x23,0x36,0xdb,0x2a,0x94,0xf4,0x95,0xdb,0xce,0x29,0x33,0xd5,0x8a,0x31,0x4a,0x9f,0x61,0xe0},
    {0x5a,0x27,0x9e,0xee,0xcb,0x4a,0xaa,0xd7,0x66,0x1e,0xf9,0xf1,0xea,0x90,0xea,0x61,0xa5,0x0a,0xce,0xc3,0x81,0x7f,0xe4,0x79,0xaf,0x7c,0x6d,0x69,0x84,0xd3,0xd7,0x3a,0x15,0x50,0x04,0xdc,0x94,0xd4,0x64,0x75,0x3a,0x9d,0x2a,0xa0,0xdc,0xfb,0x80,0xcd},
};
uint8_t SHA384_hash[SHA384_NUMBER_OF_TEST][384 / 8];

/*******************************************************************************
* SHA512
********************************************************************************/
#define SHA512_NUMBER_OF_TEST (10)
const uint8_t SHA512_Vector0_Msg0[] = "abc";
const uint8_t SHA512_Vector0_Msg1[] = "";
const uint8_t SHA512_Vector0_Msg2[] = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";
const uint8_t SHA512_Vector0_Msg3[] = "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu";
const uint8_t SHA512_Vector0_Msg4[] = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";        // block length - 1
const uint8_t SHA512_Vector0_Msg5[] = "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";       // block length
const uint8_t SHA512_Vector0_Msg6[] = "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";      // block length + 1
const uint8_t SHA512_Vector0_Msg7[] = "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";    // 2 x block length - 1
const uint8_t SHA512_Vector0_Msg8[] = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";   // 2 x block length
const uint8_t SHA512_Vector0_Msg9[] = "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";  // 2 x block length + 1
const uint8_t * const SHA512_MsgPtr[SHA512_NUMBER_OF_TEST] = 
{
    SHA512_Vector0_Msg0,
    SHA512_Vector0_Msg1,
    SHA512_Vector0_Msg2,
    SHA512_Vector0_Msg3,
    SHA512_Vector0_Msg4,
    SHA512_Vector0_Msg5,
    SHA512_Vector0_Msg6,
    SHA512_Vector0_Msg7,
    SHA512_Vector0_Msg8,
    SHA512_Vector0_Msg9,
};
const uint32_t SHA512_MsgLen[SHA512_NUMBER_OF_TEST] = 
{
    sizeof(SHA512_Vector0_Msg0) / sizeof(SHA512_Vector0_Msg0[0]) - 1,
    sizeof(SHA512_Vector0_Msg1) / sizeof(SHA512_Vector0_Msg1[0]) - 1,
    sizeof(SHA512_Vector0_Msg2) / sizeof(SHA512_Vector0_Msg2[0]) - 1,
    sizeof(SHA512_Vector0_Msg3) / sizeof(SHA512_Vector0_Msg3[0]) - 1,
    sizeof(SHA512_Vector0_Msg4) / sizeof(SHA512_Vector0_Msg4[0]) - 1,
    sizeof(SHA512_Vector0_Msg5) / sizeof(SHA512_Vector0_Msg5[0]) - 1,
    sizeof(SHA512_Vector0_Msg6) / sizeof(SHA512_Vector0_Msg6[0]) - 1,
    sizeof(SHA512_Vector0_Msg7) / sizeof(SHA512_Vector0_Msg7[0]) - 1,
    sizeof(SHA512_Vector0_Msg8) / sizeof(SHA512_Vector0_Msg8[0]) - 1,
    sizeof(SHA512_Vector0_Msg9) / sizeof(SHA512_Vector0_Msg9[0]) - 1,
};
const uint8_t SHA512_hash_ref[SHA512_NUMBER_OF_TEST][512 / 8] = 
{
    {0xdd,0xaf,0x35,0xa1,0x93,0x61,0x7a,0xba,0xcc,0x41,0x73,0x49,0xae,0x20,0x41,0x31,0x12,0xe6,0xfa,0x4e,0x89,0xa9,0x7e,0xa2,0x0a,0x9e,0xee,0xe6,0x4b,0x55,0xd3,0x9a,0x21,0x92,0x99,0x2a,0x27,0x4f,0xc1,0xa8,0x36,0xba,0x3c,0x23,0xa3,0xfe,0xeb,0xbd,0x45,0x4d,0x44,0x23,0x64,0x3c,0xe8,0x0e,0x2a,0x9a,0xc9,0x4f,0xa5,0x4c,0xa4,0x9f},
    {0xcf,0x83,0xe1,0x35,0x7e,0xef,0xb8,0xbd,0xf1,0x54,0x28,0x50,0xd6,0x6d,0x80,0x07,0xd6,0x20,0xe4,0x05,0x0b,0x57,0x15,0xdc,0x83,0xf4,0xa9,0x21,0xd3,0x6c,0xe9,0xce,0x47,0xd0,0xd1,0x3c,0x5d,0x85,0xf2,0xb0,0xff,0x83,0x18,0xd2,0x87,0x7e,0xec,0x2f,0x63,0xb9,0x31,0xbd,0x47,0x41,0x7a,0x81,0xa5,0x38,0x32,0x7a,0xf9,0x27,0xda,0x3e},
    {0x20,0x4a,0x8f,0xc6,0xdd,0xa8,0x2f,0x0a,0x0c,0xed,0x7b,0xeb,0x8e,0x08,0xa4,0x16,0x57,0xc1,0x6e,0xf4,0x68,0xb2,0x28,0xa8,0x27,0x9b,0xe3,0x31,0xa7,0x03,0xc3,0x35,0x96,0xfd,0x15,0xc1,0x3b,0x1b,0x07,0xf9,0xaa,0x1d,0x3b,0xea,0x57,0x78,0x9c,0xa0,0x31,0xad,0x85,0xc7,0xa7,0x1d,0xd7,0x03,0x54,0xec,0x63,0x12,0x38,0xca,0x34,0x45},
    {0x8e,0x95,0x9b,0x75,0xda,0xe3,0x13,0xda,0x8c,0xf4,0xf7,0x28,0x14,0xfc,0x14,0x3f,0x8f,0x77,0x79,0xc6,0xeb,0x9f,0x7f,0xa1,0x72,0x99,0xae,0xad,0xb6,0x88,0x90,0x18,0x50,0x1d,0x28,0x9e,0x49,0x00,0xf7,0xe4,0x33,0x1b,0x99,0xde,0xc4,0xb5,0x43,0x3a,0xc7,0xd3,0x29,0xee,0xb6,0xdd,0x26,0x54,0x5e,0x96,0xe5,0x5b,0x87,0x4b,0xe9,0x09},
    {0xbc,0xf1,0xcd,0xbb,0x53,0x66,0xd1,0x50,0xa1,0x2c,0x0f,0xcb,0x53,0x3b,0x41,0x22,0x94,0x82,0x98,0xe0,0x43,0x2a,0xba,0x65,0xdf,0x96,0x50,0xd5,0xea,0x7d,0x02,0x0d,0x8f,0x3e,0x9e,0xdb,0xc9,0x60,0x9b,0xc6,0x39,0xb2,0xb2,0x2c,0x93,0x0f,0x95,0xa0,0x09,0x36,0x57,0x4e,0xb2,0x51,0xd3,0x04,0x20,0xb6,0xaf,0x6e,0x71,0x9f,0xe7,0x67},
    {0x7a,0x4d,0x49,0x46,0xa5,0x0e,0xe1,0x0e,0x8c,0xdc,0xe5,0x56,0xa0,0x0f,0x21,0x75,0x7a,0x20,0x23,0xd3,0x9a,0x89,0x5c,0x78,0x09,0x96,0xe7,0x7d,0x6c,0x27,0xf8,0xc3,0x1e,0xbe,0x1b,0xb3,0x07,0x51,0x6b,0xe8,0x95,0xb5,0xd0,0x06,0x95,0x7e,0x0a,0x1e,0xd4,0x95,0xca,0x6c,0x37,0xd8,0xa7,0x49,0x13,0x69,0x44,0x06,0xd5,0xf2,0xc2,0x6e},
    {0xfa,0xde,0xc0,0xe7,0xa8,0x1f,0xdc,0x41,0x9e,0x45,0xb7,0x6a,0x9d,0x57,0x9d,0x08,0xd6,0x06,0xa4,0x0d,0xf3,0xfa,0x61,0x21,0x57,0xff,0x39,0xa9,0xcf,0xf5,0x77,0x0b,0xf7,0x0a,0x33,0xfa,0x4f,0x6b,0x6c,0x96,0x05,0xba,0x6f,0xdd,0x02,0x5d,0xff,0xb3,0x99,0x79,0x0a,0x74,0x2d,0x0e,0x7a,0x9c,0x13,0x39,0x0f,0x69,0xbd,0x96,0x43,0x30},
    {0xbe,0x91,0x73,0x1c,0xfc,0x6e,0xb7,0x9f,0x04,0x5a,0xba,0xb7,0x9f,0xcf,0x5e,0x18,0xa9,0x4f,0x39,0x9d,0x48,0xe2,0xbe,0x04,0xfd,0x18,0x72,0x45,0x7d,0x7e,0xa2,0x3e,0x44,0xeb,0xc7,0x9b,0x30,0xf8,0x13,0x26,0xc1,0x9e,0x84,0x6b,0xd4,0x08,0xf1,0x3c,0x6a,0x84,0xdc,0x62,0x6b,0x11,0x3f,0x33,0xf1,0x0b,0x40,0x2e,0x31,0x5e,0x72,0x58},
    {0x35,0x0c,0xf3,0xe6,0xd7,0x1a,0x8d,0x70,0x69,0xd4,0xdc,0x94,0x98,0x33,0x30,0xad,0xb6,0xaa,0x13,0x4e,0x01,0xa0,0x05,0xa7,0x70,0x9a,0x51,0xf5,0x1f,0x16,0x01,0xdc,0x5d,0x37,0xb9,0x9e,0x88,0xb6,0x14,0xc5,0x1f,0xba,0x29,0xb3,0xe9,0x40,0xc1,0x58,0x70,0xf4,0xb3,0x4a,0x06,0x73,0x13,0x14,0x7a,0xc6,0xa8,0x8c,0x78,0x0b,0xce,0x8d},
    {0x02,0xcd,0x70,0xc5,0x24,0xbc,0x6a,0x5a,0xf6,0x44,0xc7,0x80,0xeb,0x07,0x72,0xc3,0x35,0x8c,0xbe,0x8e,0x72,0x70,0x51,0xa9,0xbb,0xda,0x02,0x07,0x2d,0xa7,0x42,0x8f,0x71,0xa4,0x68,0x48,0xc5,0x45,0xae,0x73,0xc7,0x41,0x1b,0x99,0xa1,0x4f,0x99,0x69,0xf0,0xd8,0xb1,0x58,0x2a,0x5a,0xd7,0xa9,0x5e,0x34,0xe8,0xa7,0x2c,0x53,0xdc,0x1c},
};
uint8_t SHA512_hash[SHA512_NUMBER_OF_TEST][512 / 8];


/*******************************************************************************
* SHA512_224
********************************************************************************/
#define SHA512_224_NUMBER_OF_TEST (10)
const uint8_t SHA512_224_Vector0_Msg0[] = "abc";
const uint8_t SHA512_224_Vector0_Msg1[] = "";
const uint8_t SHA512_224_Vector0_Msg2[] = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";
const uint8_t SHA512_224_Vector0_Msg3[] = "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu";
const uint8_t SHA512_224_Vector0_Msg4[] = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";        // block length - 1
const uint8_t SHA512_224_Vector0_Msg5[] = "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";       // block length
const uint8_t SHA512_224_Vector0_Msg6[] = "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";      // block length + 1
const uint8_t SHA512_224_Vector0_Msg7[] = "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";    // 2 x block length - 1
const uint8_t SHA512_224_Vector0_Msg8[] = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";   // 2 x block length
const uint8_t SHA512_224_Vector0_Msg9[] = "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";  // 2 x block length + 1
const uint8_t * const SHA512_224_MsgPtr[SHA512_224_NUMBER_OF_TEST] = 
{
    SHA512_224_Vector0_Msg0,
    SHA512_224_Vector0_Msg1,
    SHA512_224_Vector0_Msg2,
    SHA512_224_Vector0_Msg3,
    SHA512_224_Vector0_Msg4,
    SHA512_224_Vector0_Msg5,
    SHA512_224_Vector0_Msg6,
    SHA512_224_Vector0_Msg7,
    SHA512_224_Vector0_Msg8,
    SHA512_224_Vector0_Msg9,
};
const uint32_t SHA512_224_MsgLen[SHA512_224_NUMBER_OF_TEST] = 
{
    sizeof(SHA512_224_Vector0_Msg0) / sizeof(SHA512_224_Vector0_Msg0[0]) - 1,
    sizeof(SHA512_224_Vector0_Msg1) / sizeof(SHA512_224_Vector0_Msg1[0]) - 1,
    sizeof(SHA512_224_Vector0_Msg2) / sizeof(SHA512_224_Vector0_Msg2[0]) - 1,
    sizeof(SHA512_224_Vector0_Msg3) / sizeof(SHA512_224_Vector0_Msg3[0]) - 1,
    sizeof(SHA512_224_Vector0_Msg4) / sizeof(SHA512_224_Vector0_Msg4[0]) - 1,
    sizeof(SHA512_224_Vector0_Msg5) / sizeof(SHA512_224_Vector0_Msg5[0]) - 1,
    sizeof(SHA512_224_Vector0_Msg6) / sizeof(SHA512_224_Vector0_Msg6[0]) - 1,
    sizeof(SHA512_224_Vector0_Msg7) / sizeof(SHA512_224_Vector0_Msg7[0]) - 1,
    sizeof(SHA512_224_Vector0_Msg8) / sizeof(SHA512_224_Vector0_Msg8[0]) - 1,
    sizeof(SHA512_224_Vector0_Msg9) / sizeof(SHA512_224_Vector0_Msg9[0]) - 1,
};
const uint8_t SHA512_224_hash_ref[SHA512_224_NUMBER_OF_TEST][224 / 8] = 
{
    {0x46,0x34,0x27,0x0f,0x70,0x7b,0x6a,0x54,0xda,0xae,0x75,0x30,0x46,0x08,0x42,0xe2,0x0e,0x37,0xed,0x26,0x5c,0xee,0xe9,0xa4,0x3e,0x89,0x24,0xaa},
    {0x6e,0xd0,0xdd,0x02,0x80,0x6f,0xa8,0x9e,0x25,0xde,0x06,0x0c,0x19,0xd3,0xac,0x86,0xca,0xbb,0x87,0xd6,0xa0,0xdd,0xd0,0x5c,0x33,0x3b,0x84,0xf4},
    {0xe5,0x30,0x2d,0x6d,0x54,0xbb,0x24,0x22,0x75,0xd1,0xe7,0x62,0x2d,0x68,0xdf,0x6e,0xb0,0x2d,0xed,0xd1,0x3f,0x56,0x4c,0x13,0xdb,0xda,0x21,0x74},
    {0x23,0xfe,0xc5,0xbb,0x94,0xd6,0x0b,0x23,0x30,0x81,0x92,0x64,0x0b,0x0c,0x45,0x33,0x35,0xd6,0x64,0x73,0x4f,0xe4,0x0e,0x72,0x68,0x67,0x4a,0xf9},
    {0x2f,0x0b,0xeb,0xde,0xb7,0xb6,0x10,0x00,0xb7,0x3d,0x98,0xf6,0xd9,0x9f,0x5c,0x0e,0x58,0xc3,0x80,0xc8,0xc4,0xfb,0x08,0x1d,0xcb,0x27,0x07,0x9d},
    {0xe8,0x30,0x99,0x6f,0xbf,0xcb,0x01,0x49,0x8d,0xd2,0x9e,0x0a,0x83,0x60,0x35,0x2e,0x2f,0x6b,0x31,0xff,0xb8,0xc7,0x56,0x5e,0x29,0x77,0xc1,0x7f},
    {0xe0,0x04,0xbb,0x2a,0x4b,0xa0,0xb9,0xed,0x15,0x32,0xc5,0xc2,0xc5,0x62,0x45,0x5a,0x67,0x5b,0xca,0x25,0xc2,0xae,0xec,0x60,0xf0,0x2e,0x03,0x10},
    {0x53,0xc8,0xca,0xcb,0xb8,0x92,0xec,0x88,0xa9,0x0a,0x0c,0x2a,0x88,0x2e,0xcd,0x16,0x05,0x9b,0x05,0x70,0x83,0xb2,0xc6,0xd5,0xb0,0xd6,0x15,0x83},
    {0xc3,0x65,0xf2,0x04,0xb7,0x0f,0x7b,0xa6,0x85,0x08,0x99,0x07,0x5c,0xcc,0xe7,0x4c,0x5e,0x3d,0x75,0xd6,0x85,0x3b,0xc0,0x0e,0xf8,0xb0,0xd1,0x04},
    {0xb8,0x80,0x21,0xa7,0x01,0x9a,0xdd,0x12,0xd4,0x87,0xc3,0x10,0xf7,0x2d,0xd1,0xe4,0x8f,0xb6,0xd8,0xa3,0xfb,0xa2,0xc8,0x7f,0x5a,0xf1,0xb6,0x18},
};
uint8_t SHA512_224_hash[SHA512_224_NUMBER_OF_TEST][224 / 8];

/*******************************************************************************
* SHA512_256
********************************************************************************/
#define SHA512_256_NUMBER_OF_TEST (10)
const uint8_t SHA512_256_Vector0_Msg0[] = "abc";
const uint8_t SHA512_256_Vector0_Msg1[] = "";
const uint8_t SHA512_256_Vector0_Msg2[] = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";
const uint8_t SHA512_256_Vector0_Msg3[] = "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu";
const uint8_t SHA512_256_Vector0_Msg4[] = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";        // block length - 1
const uint8_t SHA512_256_Vector0_Msg5[] = "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";       // block length
const uint8_t SHA512_256_Vector0_Msg6[] = "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";      // block length + 1
const uint8_t SHA512_256_Vector0_Msg7[] = "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";    // 2 x block length - 1
const uint8_t SHA512_256_Vector0_Msg8[] = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";   // 2 x block length
const uint8_t SHA512_256_Vector0_Msg9[] = "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";  // 2 x block length + 1
const uint8_t * const SHA512_256_MsgPtr[SHA512_256_NUMBER_OF_TEST] = 
{
    SHA512_256_Vector0_Msg0,
    SHA512_256_Vector0_Msg1,
    SHA512_256_Vector0_Msg2,
    SHA512_256_Vector0_Msg3,
    SHA512_256_Vector0_Msg4,
    SHA512_256_Vector0_Msg5,
    SHA512_256_Vector0_Msg6,
    SHA512_256_Vector0_Msg7,
    SHA512_256_Vector0_Msg8,
    SHA512_256_Vector0_Msg9,
};
const uint32_t SHA512_256_MsgLen[SHA512_256_NUMBER_OF_TEST] = 
{
    sizeof(SHA512_256_Vector0_Msg0) / sizeof(SHA512_256_Vector0_Msg0[0]) - 1,
    sizeof(SHA512_256_Vector0_Msg1) / sizeof(SHA512_256_Vector0_Msg1[0]) - 1,
    sizeof(SHA512_256_Vector0_Msg2) / sizeof(SHA512_256_Vector0_Msg2[0]) - 1,
    sizeof(SHA512_256_Vector0_Msg3) / sizeof(SHA512_256_Vector0_Msg3[0]) - 1,
    sizeof(SHA512_256_Vector0_Msg4) / sizeof(SHA512_256_Vector0_Msg4[0]) - 1,
    sizeof(SHA512_256_Vector0_Msg5) / sizeof(SHA512_256_Vector0_Msg5[0]) - 1,
    sizeof(SHA512_256_Vector0_Msg6) / sizeof(SHA512_256_Vector0_Msg6[0]) - 1,
    sizeof(SHA512_256_Vector0_Msg7) / sizeof(SHA512_256_Vector0_Msg7[0]) - 1,
    sizeof(SHA512_256_Vector0_Msg8) / sizeof(SHA512_256_Vector0_Msg8[0]) - 1,
    sizeof(SHA512_256_Vector0_Msg9) / sizeof(SHA512_256_Vector0_Msg9[0]) - 1,
};
const uint8_t SHA512_256_hash_ref[SHA512_256_NUMBER_OF_TEST][256 / 8] = 
{
    {0x53,0x04,0x8e,0x26,0x81,0x94,0x1e,0xf9,0x9b,0x2e,0x29,0xb7,0x6b,0x4c,0x7d,0xab,0xe4,0xc2,0xd0,0xc6,0x34,0xfc,0x6d,0x46,0xe0,0xe2,0xf1,0x31,0x07,0xe7,0xaf,0x23},
    {0xc6,0x72,0xb8,0xd1,0xef,0x56,0xed,0x28,0xab,0x87,0xc3,0x62,0x2c,0x51,0x14,0x06,0x9b,0xdd,0x3a,0xd7,0xb8,0xf9,0x73,0x74,0x98,0xd0,0xc0,0x1e,0xce,0xf0,0x96,0x7a},
    {0xbd,0xe8,0xe1,0xf9,0xf1,0x9b,0xb9,0xfd,0x34,0x06,0xc9,0x0e,0xc6,0xbc,0x47,0xbd,0x36,0xd8,0xad,0xa9,0xf1,0x18,0x80,0xdb,0xc8,0xa2,0x2a,0x70,0x78,0xb6,0xa4,0x61},
    {0x39,0x28,0xe1,0x84,0xfb,0x86,0x90,0xf8,0x40,0xda,0x39,0x88,0x12,0x1d,0x31,0xbe,0x65,0xcb,0x9d,0x3e,0xf8,0x3e,0xe6,0x14,0x6f,0xea,0xc8,0x61,0xe1,0x9b,0x56,0x3a},
    {0xfb,0xbf,0x2b,0xa5,0xc3,0x92,0xf4,0x09,0x87,0x99,0xfd,0x9e,0x18,0xb8,0xa9,0x97,0xb3,0xd1,0xe7,0xf7,0xf0,0x30,0xb3,0x08,0x20,0x82,0x12,0x31,0x76,0xcf,0xc5,0x85},
    {0xa5,0x39,0xc5,0x57,0x5d,0x7e,0xb4,0x2f,0xc1,0x5a,0xdc,0x1c,0x18,0xbb,0x84,0xcd,0x95,0xf3,0x08,0xbb,0x1a,0x46,0xf6,0xce,0x92,0xb2,0x6e,0x56,0x8b,0xd6,0x92,0x72},
    {0xcd,0x13,0xbd,0x63,0xfa,0x2c,0x11,0xa9,0xee,0x2b,0xd1,0x46,0xb8,0x62,0x4e,0x57,0x68,0x5e,0x71,0xbf,0x93,0x4d,0x12,0xf5,0x97,0x69,0x89,0xa0,0xf4,0x47,0x2e,0x16},
    {0xec,0x4d,0x40,0x24,0xfa,0xd5,0x77,0x91,0xde,0x3a,0x44,0x62,0x8b,0xb4,0x91,0x58,0xa4,0x65,0xec,0x88,0xe0,0x21,0xef,0x28,0x58,0x34,0xb2,0x7c,0x44,0x4a,0x0a,0x94},
    {0xef,0xb6,0xbc,0x0b,0x29,0x30,0xa6,0xbb,0xd2,0xe7,0x82,0x38,0xd7,0xe5,0xd2,0x10,0x53,0x53,0x11,0x30,0x32,0xf7,0x63,0x44,0x4c,0xb9,0x05,0x14,0xec,0x50,0x7e,0x79},
    {0x20,0x4f,0x99,0x1a,0xaf,0xde,0x9b,0x9e,0xac,0x14,0xf8,0xe8,0x88,0x7d,0xb5,0x86,0xe7,0x93,0x3d,0x6e,0x2b,0x9c,0x6d,0x2d,0x8a,0xa8,0x7c,0x32,0xdf,0xaa,0x3a,0xe6},
};
uint8_t SHA512_256_hash[SHA512_256_NUMBER_OF_TEST][256 / 8];

#endif

#endif

