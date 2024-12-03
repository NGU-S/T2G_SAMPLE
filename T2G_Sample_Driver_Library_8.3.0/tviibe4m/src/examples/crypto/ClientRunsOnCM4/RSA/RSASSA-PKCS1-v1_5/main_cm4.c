/***************************************************************************//**
* \file main_cm4.c
*
* \version 1.0
*
* \brief Main example file for CM4
*
********************************************************************************
* \copyright
* Copyright 2016-2020, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "cy_project.h"
#include "cy_device_headers.h"

/* Include default crypto configuration.
 * You can use other configuration instead follows.
 */
#include "crypto/cy_crypto_config.h"

#define RSA_KEY_LENGTH_1024BIT (1024ul)
#define RSA_KEY_LENGTH_2048BIT (2048ul)
#define RSA_KEY_LENGTH_3072BIT (3072ul)
#define RSA_KEY_LENGTH_IN_BIT  RSA_KEY_LENGTH_1024BIT

/* For CRYPTO client that can run on the both CPUs */
cy_stc_crypto_context_t        cryptoCtx;

/* Test vector */
uint8_t modulus[] = 
{
/* This is a modulus. (a part of public key)
 * Refer public_key.txt
 */
/* Big endian format */
#if RSA_KEY_LENGTH_IN_BIT == RSA_KEY_LENGTH_1024BIT
    0xc5,0x98,0xb6,0xe7,0xb8,0x02,0x87,0x90,0xfa,0x77,0x75,0x1e,0xcf,0x55,0x30,0x8a,
    0xd0,0x73,0x46,0x3e,0x97,0x23,0x89,0xf1,0xc2,0x22,0xdb,0xa9,0xf5,0x99,0xeb,0xd5,
    0x88,0xbf,0x2a,0x87,0x74,0x89,0xc9,0x79,0x52,0x37,0xd1,0x33,0x86,0xce,0x82,0x3f,
    0xc4,0x06,0x91,0x42,0x0f,0x91,0x09,0x17,0xb8,0x41,0xd0,0x47,0x5f,0xfe,0xaf,0x34,
    0x51,0x68,0xd4,0xbe,0x4a,0xc7,0x6c,0xd7,0x43,0xe5,0xa6,0x21,0x4e,0xab,0x4f,0x9e,
    0x05,0x72,0x9a,0x9a,0x02,0xc1,0x0e,0x78,0x72,0x53,0x90,0x65,0x93,0x90,0x49,0x67,
    0x3f,0x21,0xc4,0x0e,0x4b,0xf2,0xdc,0xf0,0x8f,0xd3,0x09,0x6f,0x0c,0xc9,0x91,0x6e,
    0xbf,0xfb,0xac,0x76,0x45,0xf4,0xf3,0x48,0xb1,0xf4,0x33,0x0b,0xde,0x75,0x90,0xf9,
#elif RSA_KEY_LENGTH_IN_BIT == RSA_KEY_LENGTH_2048BIT
    0x9f,0x00,0x32,0x24,0x41,0x9d,0x4d,0x77,0x7e,0x8b,0x55,0xb9,0x54,0x8e,0xa8,0x9e,
    0xdd,0x98,0x22,0xdc,0xe6,0xcd,0x34,0xb1,0x47,0xba,0xa7,0xeb,0xd8,0xfd,0x3b,0x6b,
    0x4e,0x34,0x7e,0xe3,0x4f,0x82,0x84,0x2c,0x3d,0x9c,0x00,0x67,0x52,0x60,0xc6,0x63,
    0xb8,0xc9,0x2a,0xf7,0x8b,0x09,0xfd,0x81,0x78,0x3a,0xb5,0x5e,0x46,0xe4,0x74,0xa5,
    0x24,0x57,0x7f,0x04,0x52,0xda,0xb5,0xa8,0x46,0x45,0x29,0xf7,0x47,0x3a,0xd5,0x4c,
    0xeb,0xae,0x7e,0x14,0x90,0x23,0xf3,0xa8,0x5d,0x91,0xca,0xce,0xa4,0x20,0xb3,0x78,
    0xfd,0x0c,0x3a,0x1f,0x97,0x46,0x09,0x92,0x19,0x02,0x6d,0xfb,0xf5,0x65,0x28,0xeb,
    0x8d,0x80,0x2d,0x98,0x6a,0xcb,0x51,0xf0,0xfc,0x25,0x74,0x66,0x79,0x19,0xea,0xdb,
    0xee,0xa4,0xfe,0xb5,0xe6,0x25,0x6f,0xff,0x56,0x07,0x77,0xdb,0xb8,0xfb,0x71,0xd8,
    0xa9,0xe7,0x19,0x70,0xc0,0x81,0x4b,0xf1,0x4f,0xa3,0xf7,0x3e,0x75,0x15,0x63,0x72,
    0x95,0x5b,0x11,0xe3,0x2d,0xcd,0x47,0x99,0xea,0x23,0x63,0x54,0xcf,0x52,0x0e,0x2a,
    0xc0,0xc2,0xfd,0x55,0x2b,0xbc,0xed,0xc8,0xee,0x33,0xc9,0xe5,0x46,0xef,0xf0,0x0a,
    0x7d,0xf9,0x66,0x43,0x41,0x00,0x19,0xbd,0xc6,0x87,0x2e,0x95,0x88,0x2d,0x38,0x23,
    0xa2,0x37,0xbe,0x84,0xb4,0x6a,0xda,0x9b,0xac,0x7c,0x58,0xf5,0xf9,0xe6,0xc8,0x05,
    0xb0,0x20,0x1c,0xfb,0xee,0x26,0xf6,0xf3,0x09,0xa2,0x67,0xe9,0xff,0x02,0x93,0x60,
    0x3e,0x31,0x73,0xb6,0x9a,0x0b,0x34,0xd6,0x76,0x48,0xeb,0xa5,0x94,0x7d,0xc2,0x89,
#else // RSA_KEY_LENGTH_IN_BIT == RSA_KEY_LENGTH_3072BIT
    0xc0,0x37,0x04,0x94,0xa6,0x65,0xb9,0x61,0x7d,0xeb,0xf7,0x36,0xeb,0x9a,0x4f,0x82,
    0x4a,0xce,0xc5,0xc6,0x1e,0xbe,0x1e,0x19,0x1a,0x71,0xac,0xaf,0x7f,0x05,0x75,0xf5,
    0x31,0xb9,0x25,0x04,0xb6,0x7e,0xfd,0x1f,0x84,0x72,0xbf,0x46,0x2e,0x53,0x3a,0x98,
    0x71,0xb0,0xf2,0xb7,0x95,0xe7,0x15,0x0b,0x60,0x7c,0x94,0xb7,0xd5,0xd1,0x7d,0x74,
    0x96,0x77,0xe2,0x5f,0xf2,0xaa,0xc3,0xfd,0xcc,0x30,0x55,0x24,0x84,0xc2,0x3d,0xba,
    0x07,0x2a,0x05,0xc3,0xdf,0x26,0xf5,0xb5,0x40,0xdf,0x99,0x99,0xe2,0x2e,0x17,0x13,
    0x19,0x4b,0xcc,0x8f,0x2a,0x02,0x1e,0x4f,0x90,0x9b,0x3d,0x85,0x66,0xc5,0xa3,0x1d,
    0x37,0x85,0xc7,0x8a,0xc3,0x30,0xf4,0x04,0x81,0x87,0xcf,0xbe,0x5b,0x54,0x1f,0xf7,
    0x62,0x72,0xcc,0x1a,0xa2,0xf9,0x92,0x1a,0x99,0xae,0x3e,0x61,0xb5,0x93,0xa4,0x71,
    0x79,0xb7,0xbc,0x2a,0x28,0x3a,0x34,0x17,0x46,0x24,0xb1,0x8a,0x21,0x55,0x7f,0x61,
    0xe8,0xca,0x93,0xbf,0x30,0x28,0x0d,0x48,0xa4,0x16,0xb1,0x71,0x87,0x2d,0xb9,0xe0,
    0x0a,0x5f,0xa8,0xf1,0x34,0xb8,0x8e,0x98,0x50,0x7c,0x20,0x6c,0x38,0x05,0x25,0xc8,
    0xca,0x0a,0x5d,0xc8,0x6d,0x74,0x4c,0xd9,0x1e,0x05,0x82,0xb1,0xad,0xe0,0x9c,0xf4,
    0x2b,0xb2,0xf4,0x34,0x3a,0x5e,0xd4,0xbc,0x36,0x8a,0xda,0xa4,0x11,0x1d,0x9c,0xc6,
    0xee,0xf7,0x52,0x56,0x23,0x93,0xd9,0x95,0x3d,0x61,0xa8,0x59,0xba,0x8e,0x46,0xa0,
    0x3f,0x1f,0x44,0xa9,0x06,0xb2,0x74,0xb4,0x46,0x44,0xb4,0x94,0xb0,0xa1,0xa8,0x9f,
    0x7e,0xe1,0x08,0x99,0x85,0x57,0x86,0x18,0x62,0xc2,0xcf,0x23,0x1d,0xd1,0x60,0x0a,
    0xbb,0x8f,0x4a,0x48,0xc6,0x83,0x8f,0xbd,0x94,0x6e,0xc2,0x70,0x86,0xb7,0xb8,0xb8,
    0x4a,0x3c,0xc1,0xd1,0x40,0xc6,0x81,0x98,0x9c,0x63,0xa9,0x82,0x0e,0x6e,0xe8,0xb4,
    0x5f,0x48,0xf9,0x34,0x7e,0x06,0x88,0x8e,0x2c,0x9d,0xcc,0x72,0x27,0x4f,0xe8,0xa7,
    0xe3,0x1d,0xdf,0x5c,0x60,0xda,0x75,0x4a,0xa1,0x04,0xcb,0xee,0x00,0x87,0x6e,0x4b,
    0x3b,0xd4,0x90,0x12,0x53,0xad,0xc0,0x80,0x43,0xaf,0x61,0x16,0xe8,0x6e,0xd2,0x9e,
    0xcc,0xd5,0xe3,0xb2,0x01,0xe9,0xdc,0x02,0x51,0x8c,0x24,0x03,0xe5,0xb8,0x81,0xc1,
    0xf2,0x13,0xea,0xea,0x8c,0x27,0xd0,0x98,0x5f,0x9a,0x83,0x11,0x2a,0x84,0x4c,0x19,
#endif
};

uint8_t publicExponent[] = 
{
/* This is a part of public key. (So called e)
 * Refer public_key.txt
 */
/* Big endien format */
    0x01, 0x00, 0x01
};

uint8_t encryptedSignature[] = 
{
/* PKCS#1 v1.5 signature with SHA256.
 * This value is calculated from private_key.pem and plain_text.txt.
 * You can calculate the value if using OpenSSL:
 *  openssl dgst -sha256 -sign private_key.pem plain_text.txt > signature.sig
*/
/* Big endian format */
#if RSA_KEY_LENGTH_IN_BIT == RSA_KEY_LENGTH_1024BIT
    0x19,0xE8,0x9F,0xE9,0xD9,0xCC,0x33,0x5E,0xCE,0x15,0xC9,0x31,0x8F,0x62,0x28,0x63,
    0xC4,0xB6,0xF8,0x1D,0xE5,0x00,0xDD,0x9B,0xB5,0x08,0x53,0x30,0x75,0xF0,0x98,0xB5,
    0xFB,0xAE,0xA2,0x55,0xF0,0xBA,0xD5,0x06,0x40,0x2D,0x61,0x7E,0xE1,0x7E,0xCF,0x05,
    0x0C,0xEF,0x54,0xD5,0xDA,0xEF,0xC4,0xBE,0xCC,0xB6,0x5C,0xDB,0xF2,0xDC,0xD2,0xAC,
    0x13,0x0F,0x61,0x72,0x8A,0xA9,0x2E,0xD5,0xC8,0x78,0xF8,0x6F,0xB7,0xF1,0x36,0xA3,
    0x7C,0x1A,0x04,0xBF,0xB3,0x64,0xFB,0xD3,0x1A,0x63,0x5A,0xBC,0x65,0x8B,0x4F,0x24,
    0x50,0xA3,0x91,0xA1,0x27,0x41,0x86,0x2C,0x82,0x47,0xB9,0xEC,0x30,0xC3,0xA6,0xF9,
    0xD1,0xE5,0xA3,0x7F,0x44,0xB6,0x57,0x8F,0x55,0x2A,0x17,0xFE,0xDD,0x1C,0xD0,0x41,
#elif RSA_KEY_LENGTH_IN_BIT == RSA_KEY_LENGTH_2048BIT
    0x18,0xC2,0x11,0x87,0xF8,0xAC,0x4E,0x63,0xD8,0xA5,0x2C,0xC4,0x01,0xEF,0x2C,0x40,
    0xB5,0x66,0xC8,0xBD,0xF2,0x8E,0x4A,0xF2,0xD0,0x46,0x26,0x27,0x2C,0x54,0x3F,0x03,
    0x9C,0x09,0x15,0x4B,0x33,0x7A,0xD7,0x72,0xC0,0x60,0x04,0x46,0x7C,0x89,0xC4,0xE5,
    0x8F,0xF1,0x7C,0xC2,0xE2,0xB4,0xB1,0x79,0x69,0xDF,0x4D,0xFB,0x0C,0xB7,0x75,0xE9,
    0xB0,0xB9,0x18,0x97,0x94,0x7F,0xCE,0x23,0x13,0xAB,0x9E,0x89,0xEC,0xA9,0x0A,0xB4,
    0x4F,0xA3,0x57,0xDE,0xFB,0x1A,0xB4,0x8A,0xD5,0xD8,0xBF,0x55,0x8E,0xFE,0xE4,0x08,
    0x32,0xCB,0x90,0xD0,0x1B,0xB2,0x19,0x14,0xA2,0x0C,0x77,0x29,0xE2,0x7C,0xEC,0x91,
    0xFB,0x30,0x00,0x97,0x37,0x37,0x05,0xE9,0xDD,0x51,0x9C,0x0D,0x0A,0x7B,0x85,0x94,
    0x7C,0x6B,0x64,0xC9,0x7A,0x17,0xA8,0x45,0x29,0x62,0xD9,0x3A,0x32,0xCB,0xED,0x86,
    0x48,0x3C,0x97,0x63,0x11,0xFD,0x74,0xA9,0x9C,0x2E,0x1E,0xDF,0x1F,0x33,0x89,0xBE,
    0x0C,0xFF,0x89,0xFC,0xBF,0x38,0x14,0xC9,0x17,0x29,0xA6,0xFD,0xC2,0x39,0xF1,0x32,
    0x23,0xC4,0xB7,0xB1,0x98,0xA8,0x37,0x1D,0x9F,0x02,0xFF,0xC5,0x43,0x0A,0xEC,0xE9,
    0x54,0x0B,0xCA,0x6B,0x8A,0xF9,0xC8,0x31,0xC1,0x80,0x92,0x74,0x78,0x12,0x12,0xCD,
    0x08,0x4A,0xBE,0x3F,0xAB,0x0E,0xEF,0x14,0x95,0x02,0x27,0x77,0x4D,0x8D,0x04,0x6B,
    0x02,0x93,0x40,0xEF,0x78,0x98,0x63,0xF8,0x05,0x68,0x5D,0x7B,0xB1,0x63,0xF4,0x49,
    0x48,0x70,0x16,0x2C,0x78,0x31,0x5D,0x51,0xDD,0xCD,0x84,0x18,0xDA,0x3C,0xF1,0xD9,
#else // RSA_KEY_LENGTH_IN_BIT == RSA_KEY_LENGTH_3072BIT
    0x93,0x5C,0x86,0xF1,0xDB,0x03,0x86,0xD9,0x66,0x9D,0x24,0x39,0x2F,0xA1,0xFD,0xA2,
    0x05,0x64,0x23,0x59,0x07,0x9F,0xEC,0xE6,0xEA,0x63,0x8B,0x83,0x3C,0xB4,0x2A,0x64,
    0x90,0x76,0x00,0xF8,0x91,0xDA,0x29,0x46,0x3F,0x6D,0x3F,0x39,0x33,0x90,0x80,0x04,
    0x41,0x8E,0x9E,0x4B,0x4A,0x25,0x63,0x60,0xA3,0x01,0x86,0xCE,0x9C,0x33,0x8A,0x6B,
    0x76,0x0E,0x97,0x4C,0xD2,0x72,0x1F,0x60,0x7F,0x95,0xEB,0x48,0x44,0xEA,0x07,0x4D,
    0xF4,0x27,0x53,0xDC,0xBE,0x73,0xCF,0xE6,0xFC,0x99,0x0A,0x4A,0x56,0x28,0x9F,0xD4,
    0x50,0x61,0x96,0x27,0x61,0x57,0x70,0x2F,0x35,0x2C,0x00,0x0D,0xF7,0x81,0x54,0x9A,
    0x67,0x34,0x8A,0x92,0x90,0x61,0x5F,0x9F,0xB5,0xD6,0x39,0x9B,0x83,0xF6,0xEB,0xDB,
    0x17,0x7D,0x08,0x49,0xB2,0x72,0xDE,0x93,0x6C,0x4E,0x86,0x1A,0x6C,0x97,0x59,0x2C,
    0x55,0x42,0xA2,0xA6,0xF5,0xD3,0x60,0x01,0xF9,0x1F,0xAA,0x89,0xAB,0x6A,0x89,0x6D,
    0x43,0x7D,0x23,0x24,0xBB,0x61,0xA1,0x04,0x4F,0x75,0x86,0x36,0xF5,0x1B,0xE2,0xA5,
    0xC0,0x66,0xCF,0xDE,0x59,0xDF,0x4F,0x00,0x89,0x29,0xA2,0x40,0x30,0x4C,0xA5,0x57,
    0x8B,0x72,0xFC,0x4B,0x1F,0xF5,0x62,0xCC,0x4A,0xD6,0x2B,0x76,0xA4,0x31,0xEC,0x33,
    0xB7,0x61,0x7D,0xBB,0xF9,0xFA,0xA7,0x19,0x48,0xB7,0x3C,0xF3,0xE8,0x9C,0xBE,0x96,
    0x4E,0xE4,0x6B,0x93,0x11,0x59,0x2D,0x18,0x61,0x43,0x4A,0xEE,0xAC,0xDA,0xF8,0xAC,
    0x1A,0x9B,0x49,0xC5,0x58,0x12,0xC5,0xAC,0x42,0x2E,0xB3,0x2F,0xFE,0x9B,0xA7,0xA1,
    0x85,0x14,0x71,0x96,0xDF,0x5F,0x12,0x0B,0x2D,0x8E,0x66,0x58,0x0C,0xC5,0xF9,0xCB,
    0x79,0x2D,0x44,0xA7,0xFD,0xA8,0x95,0x69,0x70,0x7C,0x0D,0xC4,0x57,0x75,0x95,0x8C,
    0x5B,0xBE,0x24,0x53,0x59,0x55,0x08,0xAB,0xB6,0x41,0x3D,0x55,0x83,0x7C,0x82,0xB1,
    0xF0,0xE5,0xE4,0xD2,0xBF,0x2E,0xB4,0xFD,0x72,0xA7,0x6A,0xAE,0xCF,0x3B,0xC4,0xC2,
    0xA0,0x1D,0x67,0x65,0x62,0x36,0xC8,0xB4,0xE1,0xBB,0x16,0xE5,0x4A,0x13,0xE2,0x3B,
    0xF4,0xC3,0x95,0xDC,0x06,0x81,0x67,0xE5,0x01,0x07,0x09,0x64,0x94,0x2F,0x7F,0x05,
    0xEE,0xEE,0x11,0x87,0x6F,0xDA,0x21,0xB5,0x0D,0xD0,0x14,0x0B,0x09,0x20,0x31,0xE5,
    0xE6,0xCE,0x8E,0x36,0x8D,0x9A,0x36,0x36,0x05,0x65,0x73,0x8D,0x59,0x85,0x43,0x14,
#endif
};

/* The plain text that is used to calculate the HASH in the signature. */
#if RSA_KEY_LENGTH_IN_BIT == RSA_KEY_LENGTH_1024BIT
uint8_t plainTxt[] = "hogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehoge";
#elif RSA_KEY_LENGTH_IN_BIT == RSA_KEY_LENGTH_2048BIT
uint8_t plainTxt[] = "hogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehoge"
                     "hogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehoge";
#else // RSA_KEY_LENGTH_IN_BIT == RSA_KEY_LENGTH_3072BIT
uint8_t plainTxt[] = "hogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehoge"
                     "hogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehoge"
                     "hogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehoge";
#endif
uint8_t decryptedSignature[RSA_KEY_LENGTH_IN_BIT/8];
uint8_t calculatedHash[CY_CRYPTO_SHA256_DIGEST_SIZE];

cy_en_crypto_rsa_ver_result_t verifyResult;

/***********************************************************************************************************************
 * RSA decryption
 ***********************************************************************************************************************/
void Run_RSA(void)
{
    cy_stc_crypto_context_rsa_t cryptoRsaContext;
    cy_stc_crypto_context_sha_t cryptoShaContext;

    /* At first convert endianness big to little.
     * Input keys and message are treated as little endian integer by Cy_Crypto_Rsa_Proc/Cy_Crypto_Rsa_CalcCoefs.
     */
    Cy_Crypto_Rsa_InvertEndianness(modulus, sizeof(modulus));
    Cy_Crypto_Rsa_InvertEndianness(publicExponent, sizeof(publicExponent));
    Cy_Crypto_Rsa_InvertEndianness(encryptedSignature, sizeof(encryptedSignature));

    /* Decrypt with the public key */
    {
        cy_stc_crypto_rsa_pub_key_t pubKeyPtr = 
        {
            .moduloPtr          = &modulus,
            .moduloLength       = RSA_KEY_LENGTH_IN_BIT,     /* The modulus length in bits,  */
            .pubExpPtr          = &publicExponent,
            .pubExpLength       = 17,       /* 17 bits */
            .barretCoefPtr      = NULL,     /* Can be NULL. All coefficients will be calculated in  Cy_Crypto_Rsa_Proc */
            .inverseModuloPtr   = NULL,     /* Same as above */
            .rBarPtr            = NULL,     /* Same as above */
        };

        /* At first decrytp the received signature. */
        Cy_Crypto_Rsa_Proc
        (
            &cryptoCtx,
            &cryptoRsaContext,
            &pubKeyPtr,
            &encryptedSignature,
            RSA_KEY_LENGTH_IN_BIT / 8u,         /* Size in byte */
            &decryptedSignature
        );
        /* Wait for completion */
        Cy_Crypto_Sync(true, &cryptoCtx);

        /* Calculated result is little endian */
        /* Then to compare with reference value, convert endianness to big endian. */
        Cy_Crypto_Rsa_InvertEndianness(decryptedSignature, sizeof(decryptedSignature));

        /* Calculate the hash from the plain text */
        Cy_Crypto_Sha_Run
        (
            &cryptoCtx,
            &cryptoShaContext,
            &plainTxt,
            sizeof(plainTxt) - 1u,  /* Except \0 */
            &calculatedHash,
            CY_CRYPTO_MODE_SHA256
        );
        /* Wait for completion */
        Cy_Crypto_Sync(true, &cryptoCtx);

        /* Finally verify decrypted signature with calculated digest */
        cy_stc_crypto_context_rsa_ver_t cryptoRsaVerContext;
        Cy_Crypto_Rsa_Verify
        (
            &cryptoCtx,
            &cryptoRsaVerContext,
            &verifyResult,
            CY_CRYPTO_MODE_SHA256,
            &calculatedHash,
            &decryptedSignature,
            sizeof(decryptedSignature)
        );
        /* Wait for completion */
        Cy_Crypto_Sync(true, &cryptoCtx);

        /* Check the result. */
        /* You can remove following ASSERT */
        CY_ASSERT(verifyResult == CY_CRYPTO_RSA_VERIFY_SUCCESS);
        /* Then you can get the result from cryptoRsaVerContext */
    }
}

/***********************************************************************************************************************
 * main function
 ***********************************************************************************************************************/
int main(void)
{
    SystemInit();

    __enable_irq(); /* Enable global interrupts. */


    /* Initialize and enable CRYPTO */
    {
        cy_en_crypto_status_t status;
        do
        {
            status = Cy_Crypto_Init(&cryptoConfig, &cryptoCtx);
        } while(status != CY_CRYPTO_SUCCESS);
        Cy_Crypto_Enable(&cryptoCtx);
    }

    /* Run RSA */
    Run_RSA();

    for(;;)
    {
    }
}



/* [] END OF FILE */
