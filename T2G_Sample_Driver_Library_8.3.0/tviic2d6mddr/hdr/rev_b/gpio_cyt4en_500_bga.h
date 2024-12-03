/***************************************************************************//**
* \file gpio_cyt4en_500_bga.h
*
* \brief
* CYT4EN device GPIO header for 500-BGA package
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

#ifndef _GPIO_CYT4EN_500_BGA_H_
#define _GPIO_CYT4EN_500_BGA_H_

/* Package type */
enum
{
    CY_GPIO_PACKAGE_QFN,
    CY_GPIO_PACKAGE_BGA,
    CY_GPIO_PACKAGE_CSP,
    CY_GPIO_PACKAGE_WLCSP,
    CY_GPIO_PACKAGE_LQFP,
    CY_GPIO_PACKAGE_TEQFP,
    CY_GPIO_PACKAGE_TEQFP_OPB,
};

#define CY_GPIO_PACKAGE_TYPE            CY_GPIO_PACKAGE_BGA
#define CY_GPIO_PIN_COUNT               500u

/* AMUXBUS Segments */
enum
{
    AMUXBUS_ECT,
    AMUXBUS_FPDLINK0,
    AMUXBUS_FPDLINK1,
    AMUXBUS_LPDDR4,
    AMUXBUS_MAIN,
    AMUXBUS_MIPI,
    AMUXBUS_TEST,
    AMUXBUS_TESTSRSS,
    AMUXBUS_LPDDR4_ADFT_BUS_A,
    AMUXBUS_LPDDR4_ADFT_BUS_B,
};

/* AMUX Splitter Controls */
typedef enum
{
    AMUX_SPLIT_CTL_0                = 0x0000u,  /* Left = AMUXBUS_TEST; Right = AMUXBUS_TESTSRSS */
    AMUX_SPLIT_CTL_1                = 0x0001u,  /* Left = AMUXBUS_ECT; Right = AMUXBUS_TEST */
    AMUX_SPLIT_CTL_2                = 0x0002u,  /* Left = AMUXBUS_MIPI; Right = AMUXBUS_TEST */
    AMUX_SPLIT_CTL_3                = 0x0003u,  /* Left = AMUXBUS_FPDLINK0; Right = AMUXBUS_TEST */
    AMUX_SPLIT_CTL_4                = 0x0004u,  /* Left = AMUXBUS_FPDLINK1; Right = AMUXBUS_TEST */
    AMUX_SPLIT_CTL_5                = 0x0005u,  /* Left = AMUXBUS_LPDDR4; Right = AMUXBUS_TEST */
    AMUX_SPLIT_CTL_6                = 0x0006u   /* Left = AMUXBUS_MAIN; Right = AMUXBUS_TEST */
} cy_en_amux_split_t;

/* Port List */
/* PORT 0 (GPIO) */
#define P0_0_GPIO_STD_PORT              GPIO_PRT0
#define P0_0_GPIO_STD_PIN               0u
#define P0_0_GPIO_STD_NUM               0u
#define P0_0_AMUXSEGMENT                AMUXBUS_MAIN
#define P0_1_GPIO_STD_PORT              GPIO_PRT0
#define P0_1_GPIO_STD_PIN               1u
#define P0_1_GPIO_STD_NUM               1u
#define P0_1_AMUXSEGMENT                AMUXBUS_MAIN
#define P0_2_GPIO_STD_PORT              GPIO_PRT0
#define P0_2_GPIO_STD_PIN               2u
#define P0_2_GPIO_STD_NUM               2u
#define P0_2_AMUXSEGMENT                AMUXBUS_MAIN
#define P0_3_GPIO_STD_PORT              GPIO_PRT0
#define P0_3_GPIO_STD_PIN               3u
#define P0_3_GPIO_STD_NUM               3u
#define P0_3_AMUXSEGMENT                AMUXBUS_MAIN

/* PORT 1 (GPIO) */
#define P1_0_GPIO_STD_STG_PORT          GPIO_PRT1
#define P1_0_GPIO_STD_STG_PIN           0u
#define P1_0_GPIO_STD_STG_NUM           0u
#define P1_0_AMUXSEGMENT                AMUXBUS_MAIN
#define P1_1_GPIO_STD_STG_PORT          GPIO_PRT1
#define P1_1_GPIO_STD_STG_PIN           1u
#define P1_1_GPIO_STD_STG_NUM           1u
#define P1_1_AMUXSEGMENT                AMUXBUS_MAIN
#define P1_2_GPIO_STD_STG_PORT          GPIO_PRT1
#define P1_2_GPIO_STD_STG_PIN           2u
#define P1_2_GPIO_STD_STG_NUM           2u
#define P1_2_AMUXSEGMENT                AMUXBUS_MAIN
#define P1_3_GPIO_STD_STG_PORT          GPIO_PRT1
#define P1_3_GPIO_STD_STG_PIN           3u
#define P1_3_GPIO_STD_STG_NUM           3u
#define P1_3_AMUXSEGMENT                AMUXBUS_MAIN
#define P1_4_GPIO_STD_STG_PORT          GPIO_PRT1
#define P1_4_GPIO_STD_STG_PIN           4u
#define P1_4_GPIO_STD_STG_NUM           4u
#define P1_4_AMUXSEGMENT                AMUXBUS_MAIN
#define P1_5_GPIO_STD_STG_PORT          GPIO_PRT1
#define P1_5_GPIO_STD_STG_PIN           5u
#define P1_5_GPIO_STD_STG_NUM           5u
#define P1_5_AMUXSEGMENT                AMUXBUS_MAIN
#define P1_6_GPIO_STD_STG_PORT          GPIO_PRT1
#define P1_6_GPIO_STD_STG_PIN           6u
#define P1_6_GPIO_STD_STG_NUM           6u
#define P1_6_AMUXSEGMENT                AMUXBUS_MAIN
#define P1_7_GPIO_STD_STG_PORT          GPIO_PRT1
#define P1_7_GPIO_STD_STG_PIN           7u
#define P1_7_GPIO_STD_STG_NUM           7u
#define P1_7_AMUXSEGMENT                AMUXBUS_MAIN

/* PORT 2 (GPIO) */
#define P2_0_GPIO_STD_STG_PORT          GPIO_PRT2
#define P2_0_GPIO_STD_STG_PIN           0u
#define P2_0_GPIO_STD_STG_NUM           0u
#define P2_0_AMUXSEGMENT                AMUXBUS_MAIN
#define P2_1_GPIO_STD_STG_PORT          GPIO_PRT2
#define P2_1_GPIO_STD_STG_PIN           1u
#define P2_1_GPIO_STD_STG_NUM           1u
#define P2_1_AMUXSEGMENT                AMUXBUS_TEST
#define P2_2_GPIO_STD_STG_PORT          GPIO_PRT2
#define P2_2_GPIO_STD_STG_PIN           2u
#define P2_2_GPIO_STD_STG_NUM           2u
#define P2_2_AMUXSEGMENT                AMUXBUS_TEST
#define P2_4_GPIO_STD_STG_PORT          GPIO_PRT2
#define P2_4_GPIO_STD_STG_PIN           4u
#define P2_4_GPIO_STD_STG_NUM           4u
#define P2_4_AMUXSEGMENT                AMUXBUS_MAIN
#define P2_5_GPIO_STD_STG_PORT          GPIO_PRT2
#define P2_5_GPIO_STD_STG_PIN           5u
#define P2_5_GPIO_STD_STG_NUM           5u
#define P2_5_AMUXSEGMENT                AMUXBUS_MAIN

/* PORT 3 (GPIO) */
#define P3_0_GPIO_ENH_STG_PORT          GPIO_PRT3
#define P3_0_GPIO_ENH_STG_PIN           0u
#define P3_0_GPIO_ENH_STG_NUM           0u
#define P3_0_AMUXSEGMENT                AMUXBUS_MAIN
#define P3_1_GPIO_ENH_STG_PORT          GPIO_PRT3
#define P3_1_GPIO_ENH_STG_PIN           1u
#define P3_1_GPIO_ENH_STG_NUM           1u
#define P3_1_AMUXSEGMENT                AMUXBUS_MAIN

/* PORT 4 (GPIO) */
#define P4_0_GPIO_STD_STG_PORT          GPIO_PRT4
#define P4_0_GPIO_STD_STG_PIN           0u
#define P4_0_GPIO_STD_STG_NUM           0u
#define P4_0_AMUXSEGMENT                AMUXBUS_MAIN
#define P4_1_GPIO_STD_STG_PORT          GPIO_PRT4
#define P4_1_GPIO_STD_STG_PIN           1u
#define P4_1_GPIO_STD_STG_NUM           1u
#define P4_1_AMUXSEGMENT                AMUXBUS_MAIN
#define P4_2_GPIO_STD_STG_PORT          GPIO_PRT4
#define P4_2_GPIO_STD_STG_PIN           2u
#define P4_2_GPIO_STD_STG_NUM           2u
#define P4_2_AMUXSEGMENT                AMUXBUS_MAIN
#define P4_3_GPIO_STD_STG_PORT          GPIO_PRT4
#define P4_3_GPIO_STD_STG_PIN           3u
#define P4_3_GPIO_STD_STG_NUM           3u
#define P4_3_AMUXSEGMENT                AMUXBUS_MAIN
#define P4_4_GPIO_STD_STG_PORT          GPIO_PRT4
#define P4_4_GPIO_STD_STG_PIN           4u
#define P4_4_GPIO_STD_STG_NUM           4u
#define P4_4_AMUXSEGMENT                AMUXBUS_MAIN
#define P4_5_GPIO_STD_STG_PORT          GPIO_PRT4
#define P4_5_GPIO_STD_STG_PIN           5u
#define P4_5_GPIO_STD_STG_NUM           5u
#define P4_5_AMUXSEGMENT                AMUXBUS_MAIN
#define P4_6_GPIO_STD_STG_PORT          GPIO_PRT4
#define P4_6_GPIO_STD_STG_PIN           6u
#define P4_6_GPIO_STD_STG_NUM           6u
#define P4_6_AMUXSEGMENT                AMUXBUS_MAIN
#define P4_7_GPIO_STD_STG_PORT          GPIO_PRT4
#define P4_7_GPIO_STD_STG_PIN           7u
#define P4_7_GPIO_STD_STG_NUM           7u
#define P4_7_AMUXSEGMENT                AMUXBUS_MAIN

/* PORT 5 (GPIO) */
#define P5_0_GPIO_ENH_STG_PORT          GPIO_PRT5
#define P5_0_GPIO_ENH_STG_PIN           0u
#define P5_0_GPIO_ENH_STG_NUM           0u
#define P5_0_AMUXSEGMENT                AMUXBUS_MAIN
#define P5_1_GPIO_ENH_STG_PORT          GPIO_PRT5
#define P5_1_GPIO_ENH_STG_PIN           1u
#define P5_1_GPIO_ENH_STG_NUM           1u
#define P5_1_AMUXSEGMENT                AMUXBUS_MAIN
#define P5_2_GPIO_ENH_STG_PORT          GPIO_PRT5
#define P5_2_GPIO_ENH_STG_PIN           2u
#define P5_2_GPIO_ENH_STG_NUM           2u
#define P5_2_AMUXSEGMENT                AMUXBUS_MAIN
#define P5_3_GPIO_ENH_STG_PORT          GPIO_PRT5
#define P5_3_GPIO_ENH_STG_PIN           3u
#define P5_3_GPIO_ENH_STG_NUM           3u
#define P5_3_AMUXSEGMENT                AMUXBUS_MAIN
#define P5_4_GPIO_ENH_STG_PORT          GPIO_PRT5
#define P5_4_GPIO_ENH_STG_PIN           4u
#define P5_4_GPIO_ENH_STG_NUM           4u
#define P5_4_AMUXSEGMENT                AMUXBUS_MAIN
#define P5_5_GPIO_ENH_STG_PORT          GPIO_PRT5
#define P5_5_GPIO_ENH_STG_PIN           5u
#define P5_5_GPIO_ENH_STG_NUM           5u
#define P5_5_AMUXSEGMENT                AMUXBUS_MAIN

/* PORT 6 (GPIO) */
#define P6_0_GPIO_STD_STG_PORT          GPIO_PRT6
#define P6_0_GPIO_STD_STG_PIN           0u
#define P6_0_GPIO_STD_STG_NUM           0u
#define P6_0_AMUXSEGMENT                AMUXBUS_MAIN
#define P6_1_GPIO_STD_STG_PORT          GPIO_PRT6
#define P6_1_GPIO_STD_STG_PIN           1u
#define P6_1_GPIO_STD_STG_NUM           1u
#define P6_1_AMUXSEGMENT                AMUXBUS_MAIN
#define P6_2_GPIO_STD_STG_PORT          GPIO_PRT6
#define P6_2_GPIO_STD_STG_PIN           2u
#define P6_2_GPIO_STD_STG_NUM           2u
#define P6_2_AMUXSEGMENT                AMUXBUS_MAIN
#define P6_3_GPIO_STD_STG_PORT          GPIO_PRT6
#define P6_3_GPIO_STD_STG_PIN           3u
#define P6_3_GPIO_STD_STG_NUM           3u
#define P6_3_AMUXSEGMENT                AMUXBUS_MAIN

/* PORT 7 (GPIO) */
#define P7_0_SMC_STG_PORT               GPIO_PRT7
#define P7_0_SMC_STG_PIN                0u
#define P7_0_SMC_STG_NUM                0u
#define P7_0_AMUXSEGMENT                AMUXBUS_MAIN
#define P7_1_SMC_STG_PORT               GPIO_PRT7
#define P7_1_SMC_STG_PIN                1u
#define P7_1_SMC_STG_NUM                1u
#define P7_1_AMUXSEGMENT                AMUXBUS_MAIN
#define P7_2_SMC_STG_PORT               GPIO_PRT7
#define P7_2_SMC_STG_PIN                2u
#define P7_2_SMC_STG_NUM                2u
#define P7_2_AMUXSEGMENT                AMUXBUS_MAIN
#define P7_3_SMC_STG_PORT               GPIO_PRT7
#define P7_3_SMC_STG_PIN                3u
#define P7_3_SMC_STG_NUM                3u
#define P7_3_AMUXSEGMENT                AMUXBUS_MAIN
#define P7_4_SMC_STG_PORT               GPIO_PRT7
#define P7_4_SMC_STG_PIN                4u
#define P7_4_SMC_STG_NUM                4u
#define P7_4_AMUXSEGMENT                AMUXBUS_MAIN
#define P7_5_SMC_STG_PORT               GPIO_PRT7
#define P7_5_SMC_STG_PIN                5u
#define P7_5_SMC_STG_NUM                5u
#define P7_5_AMUXSEGMENT                AMUXBUS_MAIN
#define P7_6_SMC_STG_PORT               GPIO_PRT7
#define P7_6_SMC_STG_PIN                6u
#define P7_6_SMC_STG_NUM                6u
#define P7_6_AMUXSEGMENT                AMUXBUS_MAIN
#define P7_7_SMC_STG_PORT               GPIO_PRT7
#define P7_7_SMC_STG_PIN                7u
#define P7_7_SMC_STG_NUM                7u
#define P7_7_AMUXSEGMENT                AMUXBUS_MAIN

/* PORT 8 (GPIO) */
#define P8_0_SMC_STG_PORT               GPIO_PRT8
#define P8_0_SMC_STG_PIN                0u
#define P8_0_SMC_STG_NUM                0u
#define P8_0_AMUXSEGMENT                AMUXBUS_MAIN
#define P8_1_SMC_STG_PORT               GPIO_PRT8
#define P8_1_SMC_STG_PIN                1u
#define P8_1_SMC_STG_NUM                1u
#define P8_1_AMUXSEGMENT                AMUXBUS_MAIN
#define P8_2_SMC_STG_PORT               GPIO_PRT8
#define P8_2_SMC_STG_PIN                2u
#define P8_2_SMC_STG_NUM                2u
#define P8_2_AMUXSEGMENT                AMUXBUS_MAIN
#define P8_3_SMC_STG_PORT               GPIO_PRT8
#define P8_3_SMC_STG_PIN                3u
#define P8_3_SMC_STG_NUM                3u
#define P8_3_AMUXSEGMENT                AMUXBUS_MAIN
#define P8_4_SMC_STG_PORT               GPIO_PRT8
#define P8_4_SMC_STG_PIN                4u
#define P8_4_SMC_STG_NUM                4u
#define P8_4_AMUXSEGMENT                AMUXBUS_MAIN
#define P8_5_SMC_STG_PORT               GPIO_PRT8
#define P8_5_SMC_STG_PIN                5u
#define P8_5_SMC_STG_NUM                5u
#define P8_5_AMUXSEGMENT                AMUXBUS_MAIN
#define P8_6_SMC_STG_PORT               GPIO_PRT8
#define P8_6_SMC_STG_PIN                6u
#define P8_6_SMC_STG_NUM                6u
#define P8_6_AMUXSEGMENT                AMUXBUS_MAIN
#define P8_7_SMC_STG_PORT               GPIO_PRT8
#define P8_7_SMC_STG_PIN                7u
#define P8_7_SMC_STG_NUM                7u
#define P8_7_AMUXSEGMENT                AMUXBUS_MAIN

/* PORT 9 (GPIO) */
#define P9_0_HSIO_STD_STG_PORT          GPIO_PRT9
#define P9_0_HSIO_STD_STG_PIN           0u
#define P9_0_HSIO_STD_STG_NUM           0u
#define P9_0_AMUXSEGMENT                AMUXBUS_MAIN
#define P9_1_HSIO_STD_STG_PORT          GPIO_PRT9
#define P9_1_HSIO_STD_STG_PIN           1u
#define P9_1_HSIO_STD_STG_NUM           1u
#define P9_1_AMUXSEGMENT                AMUXBUS_MAIN
#define P9_2_HSIO_STD_STG_PORT          GPIO_PRT9
#define P9_2_HSIO_STD_STG_PIN           2u
#define P9_2_HSIO_STD_STG_NUM           2u
#define P9_2_AMUXSEGMENT                AMUXBUS_MAIN
#define P9_3_HSIO_STD_STG_PORT          GPIO_PRT9
#define P9_3_HSIO_STD_STG_PIN           3u
#define P9_3_HSIO_STD_STG_NUM           3u
#define P9_3_AMUXSEGMENT                AMUXBUS_MAIN
#define P9_4_HSIO_STD_STG_PORT          GPIO_PRT9
#define P9_4_HSIO_STD_STG_PIN           4u
#define P9_4_HSIO_STD_STG_NUM           4u
#define P9_4_AMUXSEGMENT                AMUXBUS_MAIN
#define P9_5_HSIO_STD_STG_PORT          GPIO_PRT9
#define P9_5_HSIO_STD_STG_PIN           5u
#define P9_5_HSIO_STD_STG_NUM           5u
#define P9_5_AMUXSEGMENT                AMUXBUS_MAIN
#define P9_6_HSIO_STD_STG_PORT          GPIO_PRT9
#define P9_6_HSIO_STD_STG_PIN           6u
#define P9_6_HSIO_STD_STG_NUM           6u
#define P9_6_AMUXSEGMENT                AMUXBUS_MAIN
#define P9_7_HSIO_STD_STG_PORT          GPIO_PRT9
#define P9_7_HSIO_STD_STG_PIN           7u
#define P9_7_HSIO_STD_STG_NUM           7u
#define P9_7_AMUXSEGMENT                AMUXBUS_MAIN

/* PORT 10 (GPIO) */
#define P10_0_HSIO_STD_STG_PORT         GPIO_PRT10
#define P10_0_HSIO_STD_STG_PIN          0u
#define P10_0_HSIO_STD_STG_NUM          0u
#define P10_0_AMUXSEGMENT               AMUXBUS_MAIN
#define P10_1_HSIO_STD_STG_PORT         GPIO_PRT10
#define P10_1_HSIO_STD_STG_PIN          1u
#define P10_1_HSIO_STD_STG_NUM          1u
#define P10_1_AMUXSEGMENT               AMUXBUS_MAIN
#define P10_2_HSIO_STD_STG_PORT         GPIO_PRT10
#define P10_2_HSIO_STD_STG_PIN          2u
#define P10_2_HSIO_STD_STG_NUM          2u
#define P10_2_AMUXSEGMENT               AMUXBUS_MAIN
#define P10_3_HSIO_STD_STG_PORT         GPIO_PRT10
#define P10_3_HSIO_STD_STG_PIN          3u
#define P10_3_HSIO_STD_STG_NUM          3u
#define P10_3_AMUXSEGMENT               AMUXBUS_MAIN
#define P10_4_HSIO_STD_STG_PORT         GPIO_PRT10
#define P10_4_HSIO_STD_STG_PIN          4u
#define P10_4_HSIO_STD_STG_NUM          4u
#define P10_4_AMUXSEGMENT               AMUXBUS_MAIN
#define P10_5_HSIO_STD_STG_PORT         GPIO_PRT10
#define P10_5_HSIO_STD_STG_PIN          5u
#define P10_5_HSIO_STD_STG_NUM          5u
#define P10_5_AMUXSEGMENT               AMUXBUS_MAIN
#define P10_6_HSIO_STD_STG_PORT         GPIO_PRT10
#define P10_6_HSIO_STD_STG_PIN          6u
#define P10_6_HSIO_STD_STG_NUM          6u
#define P10_6_AMUXSEGMENT               AMUXBUS_MAIN
#define P10_7_HSIO_STD_STG_PORT         GPIO_PRT10
#define P10_7_HSIO_STD_STG_PIN          7u
#define P10_7_HSIO_STD_STG_NUM          7u
#define P10_7_AMUXSEGMENT               AMUXBUS_MAIN

/* PORT 11 (GPIO) */
#define P11_0_HSIO_STD_STG_PORT         GPIO_PRT11
#define P11_0_HSIO_STD_STG_PIN          0u
#define P11_0_HSIO_STD_STG_NUM          0u
#define P11_0_AMUXSEGMENT               AMUXBUS_MAIN
#define P11_1_HSIO_STD_STG_PORT         GPIO_PRT11
#define P11_1_HSIO_STD_STG_PIN          1u
#define P11_1_HSIO_STD_STG_NUM          1u
#define P11_1_AMUXSEGMENT               AMUXBUS_MAIN
#define P11_2_HSIO_STD_STG_PORT         GPIO_PRT11
#define P11_2_HSIO_STD_STG_PIN          2u
#define P11_2_HSIO_STD_STG_NUM          2u
#define P11_2_AMUXSEGMENT               AMUXBUS_MAIN
#define P11_3_HSIO_STD_STG_PORT         GPIO_PRT11
#define P11_3_HSIO_STD_STG_PIN          3u
#define P11_3_HSIO_STD_STG_NUM          3u
#define P11_3_AMUXSEGMENT               AMUXBUS_MAIN
#define P11_4_HSIO_STD_STG_PORT         GPIO_PRT11
#define P11_4_HSIO_STD_STG_PIN          4u
#define P11_4_HSIO_STD_STG_NUM          4u
#define P11_4_AMUXSEGMENT               AMUXBUS_MAIN
#define P11_5_HSIO_STD_STG_PORT         GPIO_PRT11
#define P11_5_HSIO_STD_STG_PIN          5u
#define P11_5_HSIO_STD_STG_NUM          5u
#define P11_5_AMUXSEGMENT               AMUXBUS_MAIN
#define P11_6_HSIO_STD_STG_PORT         GPIO_PRT11
#define P11_6_HSIO_STD_STG_PIN          6u
#define P11_6_HSIO_STD_STG_NUM          6u
#define P11_6_AMUXSEGMENT               AMUXBUS_MAIN
#define P11_7_HSIO_STD_STG_PORT         GPIO_PRT11
#define P11_7_HSIO_STD_STG_PIN          7u
#define P11_7_HSIO_STD_STG_NUM          7u
#define P11_7_AMUXSEGMENT               AMUXBUS_MAIN

/* PORT 12 (GPIO) */
#define P12_0_HSIO_STD_STG_PORT         GPIO_PRT12
#define P12_0_HSIO_STD_STG_PIN          0u
#define P12_0_HSIO_STD_STG_NUM          0u
#define P12_0_AMUXSEGMENT               AMUXBUS_MAIN
#define P12_1_HSIO_STD_STG_PORT         GPIO_PRT12
#define P12_1_HSIO_STD_STG_PIN          1u
#define P12_1_HSIO_STD_STG_NUM          1u
#define P12_1_AMUXSEGMENT               AMUXBUS_MAIN
#define P12_2_HSIO_STD_STG_PORT         GPIO_PRT12
#define P12_2_HSIO_STD_STG_PIN          2u
#define P12_2_HSIO_STD_STG_NUM          2u
#define P12_2_AMUXSEGMENT               AMUXBUS_MAIN
#define P12_3_HSIO_STD_STG_PORT         GPIO_PRT12
#define P12_3_HSIO_STD_STG_PIN          3u
#define P12_3_HSIO_STD_STG_NUM          3u
#define P12_3_AMUXSEGMENT               AMUXBUS_MAIN
#define P12_4_HSIO_STD_STG_PORT         GPIO_PRT12
#define P12_4_HSIO_STD_STG_PIN          4u
#define P12_4_HSIO_STD_STG_NUM          4u
#define P12_4_AMUXSEGMENT               AMUXBUS_MAIN
#define P12_5_HSIO_STD_STG_PORT         GPIO_PRT12
#define P12_5_HSIO_STD_STG_PIN          5u
#define P12_5_HSIO_STD_STG_NUM          5u
#define P12_5_AMUXSEGMENT               AMUXBUS_MAIN
#define P12_6_HSIO_STD_STG_PORT         GPIO_PRT12
#define P12_6_HSIO_STD_STG_PIN          6u
#define P12_6_HSIO_STD_STG_NUM          6u
#define P12_6_AMUXSEGMENT               AMUXBUS_MAIN
#define P12_7_HSIO_STD_STG_PORT         GPIO_PRT12
#define P12_7_HSIO_STD_STG_PIN          7u
#define P12_7_HSIO_STD_STG_NUM          7u
#define P12_7_AMUXSEGMENT               AMUXBUS_MAIN

/* PORT 13 (GPIO) */
#define P13_0_HSIO_STD_STG_PORT         GPIO_PRT13
#define P13_0_HSIO_STD_STG_PIN          0u
#define P13_0_HSIO_STD_STG_NUM          0u
#define P13_0_AMUXSEGMENT               AMUXBUS_MAIN
#define P13_1_HSIO_STD_STG_PORT         GPIO_PRT13
#define P13_1_HSIO_STD_STG_PIN          1u
#define P13_1_HSIO_STD_STG_NUM          1u
#define P13_1_AMUXSEGMENT               AMUXBUS_MAIN

/* PORT 14 (GPIO) */
#define P14_0_HSIO_ENH_STG_PORT         GPIO_PRT14
#define P14_0_HSIO_ENH_STG_PIN          0u
#define P14_0_HSIO_ENH_STG_NUM          0u
#define P14_0_AMUXSEGMENT               AMUXBUS_MAIN
#define P14_1_HSIO_ENH_STG_PORT         GPIO_PRT14
#define P14_1_HSIO_ENH_STG_PIN          1u
#define P14_1_HSIO_ENH_STG_NUM          1u
#define P14_1_AMUXSEGMENT               AMUXBUS_MAIN
#define P14_2_HSIO_ENH_STG_PORT         GPIO_PRT14
#define P14_2_HSIO_ENH_STG_PIN          2u
#define P14_2_HSIO_ENH_STG_NUM          2u
#define P14_2_AMUXSEGMENT               AMUXBUS_MAIN
#define P14_3_HSIO_ENH_STG_PORT         GPIO_PRT14
#define P14_3_HSIO_ENH_STG_PIN          3u
#define P14_3_HSIO_ENH_STG_NUM          3u
#define P14_3_AMUXSEGMENT               AMUXBUS_MAIN
#define P14_4_HSIO_ENH_STG_PORT         GPIO_PRT14
#define P14_4_HSIO_ENH_STG_PIN          4u
#define P14_4_HSIO_ENH_STG_NUM          4u
#define P14_4_AMUXSEGMENT               AMUXBUS_MAIN

/* PORT 15 (GPIO) */
#define P15_0_HSIO_ENH_PDIFF_STG_PORT   GPIO_PRT15
#define P15_0_HSIO_ENH_PDIFF_STG_PIN    0u
#define P15_0_HSIO_ENH_PDIFF_STG_NUM    0u
#define P15_0_AMUXSEGMENT               AMUXBUS_MAIN
#define P15_1_HSIO_ENH_PDIFF_STG_PORT   GPIO_PRT15
#define P15_1_HSIO_ENH_PDIFF_STG_PIN    1u
#define P15_1_HSIO_ENH_PDIFF_STG_NUM    1u
#define P15_1_AMUXSEGMENT               AMUXBUS_MAIN

/* PORT 16 (GPIO) */
#define P16_0_HSIO_ENH_STG_PORT         GPIO_PRT16
#define P16_0_HSIO_ENH_STG_PIN          0u
#define P16_0_HSIO_ENH_STG_NUM          0u
#define P16_0_AMUXSEGMENT               AMUXBUS_MAIN
#define P16_1_HSIO_ENH_STG_PORT         GPIO_PRT16
#define P16_1_HSIO_ENH_STG_PIN          1u
#define P16_1_HSIO_ENH_STG_NUM          1u
#define P16_1_AMUXSEGMENT               AMUXBUS_MAIN
#define P16_2_HSIO_ENH_STG_PORT         GPIO_PRT16
#define P16_2_HSIO_ENH_STG_PIN          2u
#define P16_2_HSIO_ENH_STG_NUM          2u
#define P16_2_AMUXSEGMENT               AMUXBUS_MAIN
#define P16_3_HSIO_ENH_STG_PORT         GPIO_PRT16
#define P16_3_HSIO_ENH_STG_PIN          3u
#define P16_3_HSIO_ENH_STG_NUM          3u
#define P16_3_AMUXSEGMENT               AMUXBUS_MAIN
#define P16_4_HSIO_ENH_STG_PORT         GPIO_PRT16
#define P16_4_HSIO_ENH_STG_PIN          4u
#define P16_4_HSIO_ENH_STG_NUM          4u
#define P16_4_AMUXSEGMENT               AMUXBUS_MAIN
#define P16_5_HSIO_ENH_STG_PORT         GPIO_PRT16
#define P16_5_HSIO_ENH_STG_PIN          5u
#define P16_5_HSIO_ENH_STG_NUM          5u
#define P16_5_AMUXSEGMENT               AMUXBUS_MAIN

/* PORT 17 (GPIO) */
#define P17_0_HSIO_ENH_STG_PORT         GPIO_PRT17
#define P17_0_HSIO_ENH_STG_PIN          0u
#define P17_0_HSIO_ENH_STG_NUM          0u
#define P17_0_AMUXSEGMENT               AMUXBUS_MAIN
#define P17_1_HSIO_ENH_STG_PORT         GPIO_PRT17
#define P17_1_HSIO_ENH_STG_PIN          1u
#define P17_1_HSIO_ENH_STG_NUM          1u
#define P17_1_AMUXSEGMENT               AMUXBUS_MAIN
#define P17_2_HSIO_ENH_STG_PORT         GPIO_PRT17
#define P17_2_HSIO_ENH_STG_PIN          2u
#define P17_2_HSIO_ENH_STG_NUM          2u
#define P17_2_AMUXSEGMENT               AMUXBUS_MAIN
#define P17_3_HSIO_ENH_STG_PORT         GPIO_PRT17
#define P17_3_HSIO_ENH_STG_PIN          3u
#define P17_3_HSIO_ENH_STG_NUM          3u
#define P17_3_AMUXSEGMENT               AMUXBUS_MAIN
#define P17_4_HSIO_ENH_STG_PORT         GPIO_PRT17
#define P17_4_HSIO_ENH_STG_PIN          4u
#define P17_4_HSIO_ENH_STG_NUM          4u
#define P17_4_AMUXSEGMENT               AMUXBUS_MAIN

/* PORT 18 (GPIO) */
#define P18_0_HSIO_ENH_PDIFF_STG_PORT   GPIO_PRT18
#define P18_0_HSIO_ENH_PDIFF_STG_PIN    0u
#define P18_0_HSIO_ENH_PDIFF_STG_NUM    0u
#define P18_0_AMUXSEGMENT               AMUXBUS_MAIN
#define P18_1_HSIO_ENH_PDIFF_STG_PORT   GPIO_PRT18
#define P18_1_HSIO_ENH_PDIFF_STG_PIN    1u
#define P18_1_HSIO_ENH_PDIFF_STG_NUM    1u
#define P18_1_AMUXSEGMENT               AMUXBUS_MAIN

/* PORT 19 (GPIO) */
#define P19_0_HSIO_ENH_STG_PORT         GPIO_PRT19
#define P19_0_HSIO_ENH_STG_PIN          0u
#define P19_0_HSIO_ENH_STG_NUM          0u
#define P19_0_AMUXSEGMENT               AMUXBUS_MAIN
#define P19_1_HSIO_ENH_STG_PORT         GPIO_PRT19
#define P19_1_HSIO_ENH_STG_PIN          1u
#define P19_1_HSIO_ENH_STG_NUM          1u
#define P19_1_AMUXSEGMENT               AMUXBUS_MAIN
#define P19_2_HSIO_ENH_STG_PORT         GPIO_PRT19
#define P19_2_HSIO_ENH_STG_PIN          2u
#define P19_2_HSIO_ENH_STG_NUM          2u
#define P19_2_AMUXSEGMENT               AMUXBUS_MAIN
#define P19_3_HSIO_ENH_STG_PORT         GPIO_PRT19
#define P19_3_HSIO_ENH_STG_PIN          3u
#define P19_3_HSIO_ENH_STG_NUM          3u
#define P19_3_AMUXSEGMENT               AMUXBUS_MAIN
#define P19_4_HSIO_ENH_STG_PORT         GPIO_PRT19
#define P19_4_HSIO_ENH_STG_PIN          4u
#define P19_4_HSIO_ENH_STG_NUM          4u
#define P19_4_AMUXSEGMENT               AMUXBUS_MAIN
#define P19_5_HSIO_ENH_STG_PORT         GPIO_PRT19
#define P19_5_HSIO_ENH_STG_PIN          5u
#define P19_5_HSIO_ENH_STG_NUM          5u
#define P19_5_AMUXSEGMENT               AMUXBUS_MAIN

/* Analog Connections */
#define PASS0_I_TEMP_KELVIN_PORT        0u
#define PASS0_I_TEMP_KELVIN_PIN         2u
#define PASS0_SARMUX_PADS0_PORT         1u
#define PASS0_SARMUX_PADS0_PIN          3u
#define PASS0_SARMUX_PADS1_PORT         1u
#define PASS0_SARMUX_PADS1_PIN          4u
#define PASS0_SARMUX_PADS10_PORT        5u
#define PASS0_SARMUX_PADS10_PIN         0u
#define PASS0_SARMUX_PADS11_PORT        5u
#define PASS0_SARMUX_PADS11_PIN         1u
#define PASS0_SARMUX_PADS12_PORT        5u
#define PASS0_SARMUX_PADS12_PIN         2u
#define PASS0_SARMUX_PADS13_PORT        5u
#define PASS0_SARMUX_PADS13_PIN         3u
#define PASS0_SARMUX_PADS14_PORT        5u
#define PASS0_SARMUX_PADS14_PIN         4u
#define PASS0_SARMUX_PADS15_PORT        5u
#define PASS0_SARMUX_PADS15_PIN         5u
#define PASS0_SARMUX_PADS16_PORT        4u
#define PASS0_SARMUX_PADS16_PIN         4u
#define PASS0_SARMUX_PADS17_PORT        4u
#define PASS0_SARMUX_PADS17_PIN         5u
#define PASS0_SARMUX_PADS18_PORT        4u
#define PASS0_SARMUX_PADS18_PIN         6u
#define PASS0_SARMUX_PADS19_PORT        4u
#define PASS0_SARMUX_PADS19_PIN         7u
#define PASS0_SARMUX_PADS2_PORT         1u
#define PASS0_SARMUX_PADS2_PIN          5u
#define PASS0_SARMUX_PADS20_PORT        6u
#define PASS0_SARMUX_PADS20_PIN         0u
#define PASS0_SARMUX_PADS21_PORT        6u
#define PASS0_SARMUX_PADS21_PIN         1u
#define PASS0_SARMUX_PADS22_PORT        6u
#define PASS0_SARMUX_PADS22_PIN         2u
#define PASS0_SARMUX_PADS23_PORT        6u
#define PASS0_SARMUX_PADS23_PIN         3u
#define PASS0_SARMUX_PADS3_PORT         1u
#define PASS0_SARMUX_PADS3_PIN          6u
#define PASS0_SARMUX_PADS32_PORT        7u
#define PASS0_SARMUX_PADS32_PIN         0u
#define PASS0_SARMUX_PADS33_PORT        7u
#define PASS0_SARMUX_PADS33_PIN         1u
#define PASS0_SARMUX_PADS34_PORT        7u
#define PASS0_SARMUX_PADS34_PIN         2u
#define PASS0_SARMUX_PADS35_PORT        7u
#define PASS0_SARMUX_PADS35_PIN         3u
#define PASS0_SARMUX_PADS36_PORT        7u
#define PASS0_SARMUX_PADS36_PIN         4u
#define PASS0_SARMUX_PADS37_PORT        7u
#define PASS0_SARMUX_PADS37_PIN         5u
#define PASS0_SARMUX_PADS38_PORT        7u
#define PASS0_SARMUX_PADS38_PIN         6u
#define PASS0_SARMUX_PADS39_PORT        7u
#define PASS0_SARMUX_PADS39_PIN         7u
#define PASS0_SARMUX_PADS4_PORT         1u
#define PASS0_SARMUX_PADS4_PIN          7u
#define PASS0_SARMUX_PADS40_PORT        8u
#define PASS0_SARMUX_PADS40_PIN         0u
#define PASS0_SARMUX_PADS41_PORT        8u
#define PASS0_SARMUX_PADS41_PIN         1u
#define PASS0_SARMUX_PADS42_PORT        8u
#define PASS0_SARMUX_PADS42_PIN         2u
#define PASS0_SARMUX_PADS43_PORT        8u
#define PASS0_SARMUX_PADS43_PIN         3u
#define PASS0_SARMUX_PADS44_PORT        8u
#define PASS0_SARMUX_PADS44_PIN         4u
#define PASS0_SARMUX_PADS45_PORT        8u
#define PASS0_SARMUX_PADS45_PIN         5u
#define PASS0_SARMUX_PADS46_PORT        8u
#define PASS0_SARMUX_PADS46_PIN         6u
#define PASS0_SARMUX_PADS47_PORT        8u
#define PASS0_SARMUX_PADS47_PIN         7u
#define PASS0_SARMUX_PADS5_PORT         2u
#define PASS0_SARMUX_PADS5_PIN          0u
#define PASS0_SARMUX_PADS6_PORT         3u
#define PASS0_SARMUX_PADS6_PIN          0u
#define PASS0_SARMUX_PADS7_PORT         4u
#define PASS0_SARMUX_PADS7_PIN          1u
#define PASS0_SARMUX_PADS8_PORT         4u
#define PASS0_SARMUX_PADS8_PIN          2u
#define PASS0_SARMUX_PADS9_PORT         4u
#define PASS0_SARMUX_PADS9_PIN          3u
#define PASS0_VB_TEMP_KELVIN_PORT       2u
#define PASS0_VB_TEMP_KELVIN_PIN        2u
#define PASS0_VE_TEMP_KELVIN_PORT       4u
#define PASS0_VE_TEMP_KELVIN_PIN        1u
#define SRSS_ADFT_PIN0_PORT             2u
#define SRSS_ADFT_PIN0_PIN              1u
#define SRSS_ADFT_PIN1_PORT             2u
#define SRSS_ADFT_PIN1_PIN              2u
#define SRSS_ADFT_POR_PAD_HV_PORT       2u
#define SRSS_ADFT_POR_PAD_HV_PIN        1u
#define SRSS_ECO_IN_PORT                0u
#define SRSS_ECO_IN_PIN                 2u
#define SRSS_ECO_OUT_PORT               0u
#define SRSS_ECO_OUT_PIN                3u
#define SRSS_LPECO_IN_PORT              0u
#define SRSS_LPECO_IN_PIN               0u
#define SRSS_LPECO_OUT_PORT             0u
#define SRSS_LPECO_OUT_PIN              1u
#define SRSS_VEXT_REF_REG_PORT          0u
#define SRSS_VEXT_REF_REG_PIN           3u
#define SRSS_WCO_IN_PORT                0u
#define SRSS_WCO_IN_PIN                 0u
#define SRSS_WCO_OUT_PORT               0u
#define SRSS_WCO_OUT_PIN                1u

/* HSIOM Connections */
typedef enum
{
    /* Generic HSIOM connections */
    HSIOM_SEL_GPIO                  =  0,       /* GPIO controls 'out' */
    HSIOM_SEL_GPIO_DSI              =  1,       /* GPIO controls 'out', DSI controls 'output enable' */
    HSIOM_SEL_DSI_DSI               =  2,       /* DSI controls 'out' and 'output enable' */
    HSIOM_SEL_DSI_GPIO              =  3,       /* DSI controls 'out', GPIO controls 'output enable' */
    HSIOM_SEL_AMUXA                 =  4,       /* AMUXBUS A */
    HSIOM_SEL_AMUXB                 =  5,       /* AMUXBUS B */
    HSIOM_SEL_AMUXA_DSI             =  6,       /* Analog mux bus A, DSI control */
    HSIOM_SEL_AMUXB_DSI             =  7,       /* Analog mux bus B, DSI control */
    HSIOM_SEL_ACT_0                 =  8,       /* Active peripheral 0 */
    HSIOM_SEL_ACT_1                 =  9,       /* Active peripheral 1 */
    HSIOM_SEL_ACT_2                 = 10,       /* Active peripheral 2 */
    HSIOM_SEL_ACT_3                 = 11,       /* Active peripheral 3 */
    HSIOM_SEL_DS_0                  = 12,       /* Deep Sleep peripheral 0 */
    HSIOM_SEL_DS_1                  = 13,       /* Deep Sleep peripheral 1 */
    HSIOM_SEL_DS_2                  = 14,       /* Deep Sleep peripheral 2 */
    HSIOM_SEL_DS_3                  = 15,       /* Deep Sleep peripheral 3 */
    HSIOM_SEL_ACT_4                 = 16,       /* Active peripheral 4 */
    HSIOM_SEL_ACT_5                 = 17,       /* Active peripheral 5 */
    HSIOM_SEL_ACT_6                 = 18,       /* Active peripheral 6 */
    HSIOM_SEL_ACT_7                 = 19,       /* Active peripheral 7 */
    HSIOM_SEL_ACT_8                 = 20,       /* Active peripheral 8 */
    HSIOM_SEL_ACT_9                 = 21,       /* Active peripheral 9 */
    HSIOM_SEL_ACT_10                = 22,       /* Active peripheral 10 */
    HSIOM_SEL_ACT_11                = 23,       /* Active peripheral 11 */
    HSIOM_SEL_ACT_12                = 24,       /* Active peripheral 12 */
    HSIOM_SEL_ACT_13                = 25,       /* Active peripheral 13 */
    HSIOM_SEL_ACT_14                = 26,       /* Active peripheral 14 */
    HSIOM_SEL_ACT_15                = 27,       /* Active peripheral 15 */
    HSIOM_SEL_DS_4                  = 28,       /* Deep Sleep peripheral 4 */
    HSIOM_SEL_DS_5                  = 29,       /* Deep Sleep peripheral 5 */
    HSIOM_SEL_DS_6                  = 30,       /* Deep Sleep peripheral 6 */
    HSIOM_SEL_DS_7                  = 31,       /* Deep Sleep peripheral 7 */

    /* P0.0 */
    P0_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P0_0_AMUXA                      =  4,       /* AMUXBUS A */
    P0_0_AMUXB                      =  5,       /* AMUXBUS B */

    /* P0.1 */
    P0_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P0_1_AMUXA                      =  4,       /* AMUXBUS A */
    P0_1_AMUXB                      =  5,       /* AMUXBUS B */

    /* P0.2 */
    P0_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P0_2_AMUXA                      =  4,       /* AMUXBUS A */
    P0_2_AMUXB                      =  5,       /* AMUXBUS B */
    P0_2_SRSS_EXT_CLK               = 19,       /* Digital Active - srss.ext_clk:0 */
    P0_2_SRSS_DDFT_PIN_IN1          = 31,       /* Digital Deep Sleep - srss.ddft_pin_in[1]:1 */

    /* P0.3 */
    P0_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P0_3_AMUXA                      =  4,       /* AMUXBUS A */
    P0_3_AMUXB                      =  5,       /* AMUXBUS B */

    /* P1.0 */
    P1_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_0_AMUXA                      =  4,       /* AMUXBUS A */
    P1_0_AMUXB                      =  5,       /* AMUXBUS B */
    P1_0_TCPWM0_LINE516             =  8,       /* Digital Active - tcpwm[0].line[516]:0 */
    P1_0_TCPWM0_LINE_COMPL515       =  9,       /* Digital Active - tcpwm[0].line_compl[515]:0 */
    P1_0_TCPWM0_TR_ONE_CNT_IN514    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[514]:0 */
    P1_0_VIDEOSS0_TTL_CAP0_DATA1    = 23,       /* Digital Active - videoss[0].ttl_cap0_data[1]:1 */
    P1_0_SCB6_SPI_CLK               = 25,       /* Digital Active - scb[6].spi_clk:0 */
    P1_0_SCB6_UART_RX               = 26,       /* Digital Active - scb[6].uart_rx:0 */
    P1_0_SCB6_I2C_SDA               = 27,       /* Digital Active - scb[6].i2c_sda:0 */

    /* P1.1 */
    P1_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_1_AMUXA                      =  4,       /* AMUXBUS A */
    P1_1_AMUXB                      =  5,       /* AMUXBUS B */
    P1_1_TCPWM0_LINE517             =  8,       /* Digital Active - tcpwm[0].line[517]:0 */
    P1_1_TCPWM0_LINE_COMPL516       =  9,       /* Digital Active - tcpwm[0].line_compl[516]:0 */
    P1_1_TCPWM0_TR_ONE_CNT_IN515    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[515]:0 */
    P1_1_VIDEOSS0_TTL_CAP0_DATA0    = 23,       /* Digital Active - videoss[0].ttl_cap0_data[0]:1 */
    P1_1_SCB6_SPI_MOSI              = 25,       /* Digital Active - scb[6].spi_mosi:0 */
    P1_1_SCB6_UART_TX               = 26,       /* Digital Active - scb[6].uart_tx:0 */
    P1_1_SCB6_I2C_SCL               = 27,       /* Digital Active - scb[6].i2c_scl:0 */

    /* P1.2 */
    P1_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_2_AMUXA                      =  4,       /* AMUXBUS A */
    P1_2_AMUXB                      =  5,       /* AMUXBUS B */
    P1_2_TCPWM0_LINE518             =  8,       /* Digital Active - tcpwm[0].line[518]:0 */
    P1_2_TCPWM0_LINE_COMPL517       =  9,       /* Digital Active - tcpwm[0].line_compl[517]:0 */
    P1_2_TCPWM0_TR_ONE_CNT_IN516    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[516]:0 */
    P1_2_PERI_TR_IO_INPUT0          = 20,       /* Digital Active - peri.tr_io_input[0]:0 */
    P1_2_VIDEOSS0_TTL_CAP0_DATA24   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[24]:1 */
    P1_2_SCB6_SPI_MISO              = 25,       /* Digital Active - scb[6].spi_miso:0 */
    P1_2_SCB6_UART_RTS              = 26,       /* Digital Active - scb[6].uart_rts:0 */

    /* P1.3 */
    P1_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_3_AMUXA                      =  4,       /* AMUXBUS A */
    P1_3_AMUXB                      =  5,       /* AMUXBUS B */
    P1_3_TCPWM0_LINE519             =  8,       /* Digital Active - tcpwm[0].line[519]:0 */
    P1_3_TCPWM0_LINE_COMPL518       =  9,       /* Digital Active - tcpwm[0].line_compl[518]:0 */
    P1_3_TCPWM0_TR_ONE_CNT_IN517    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[517]:0 */
    P1_3_PERI_TR_IO_OUTPUT1         = 21,       /* Digital Active - peri.tr_io_output[1]:0 */
    P1_3_VIDEOSS0_TTL_CAP0_DATA25   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[25]:1 */
    P1_3_SCB6_SPI_SELECT0           = 25,       /* Digital Active - scb[6].spi_select0:0 */
    P1_3_SCB6_UART_CTS              = 26,       /* Digital Active - scb[6].uart_cts:0 */

    /* P1.4 */
    P1_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_4_AMUXA                      =  4,       /* AMUXBUS A */
    P1_4_AMUXB                      =  5,       /* AMUXBUS B */
    P1_4_TCPWM0_LINE520             =  8,       /* Digital Active - tcpwm[0].line[520]:0 */
    P1_4_TCPWM0_LINE_COMPL519       =  9,       /* Digital Active - tcpwm[0].line_compl[519]:0 */
    P1_4_TCPWM0_TR_ONE_CNT_IN518    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[518]:0 */
    P1_4_PERI_TR_IO_INPUT1          = 21,       /* Digital Active - peri.tr_io_input[1]:0 */
    P1_4_VIDEOSS0_TTL_CAP0_DATA26   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[26]:1 */
    P1_4_SCB6_SPI_SELECT1           = 25,       /* Digital Active - scb[6].spi_select1:0 */

    /* P1.5 */
    P1_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_5_AMUXA                      =  4,       /* AMUXBUS A */
    P1_5_AMUXB                      =  5,       /* AMUXBUS B */
    P1_5_TCPWM0_LINE521             =  8,       /* Digital Active - tcpwm[0].line[521]:0 */
    P1_5_TCPWM0_LINE_COMPL520       =  9,       /* Digital Active - tcpwm[0].line_compl[520]:0 */
    P1_5_TCPWM0_TR_ONE_CNT_IN519    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[519]:0 */
    P1_5_VIDEOSS0_TTL_DSP1_DATA_A111 = 18,      /* Digital Active - videoss[0].ttl_dsp1_data_a1[11]:1 */
    P1_5_PERI_TR_IO_INPUT2          = 21,       /* Digital Active - peri.tr_io_input[2]:0 */
    P1_5_SCB7_SPI_SELECT1           = 25,       /* Digital Active - scb[7].spi_select1:0 */

    /* P1.6 */
    P1_6_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_6_AMUXA                      =  4,       /* AMUXBUS A */
    P1_6_AMUXB                      =  5,       /* AMUXBUS B */
    P1_6_TCPWM0_LINE522             =  8,       /* Digital Active - tcpwm[0].line[522]:0 */
    P1_6_TCPWM0_LINE_COMPL522       =  9,       /* Digital Active - tcpwm[0].line_compl[522]:0 */
    P1_6_TCPWM0_TR_ONE_CNT_IN522    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[522]:0 */
    P1_6_VIDEOSS0_TTL_DSP1_DATA_A011 = 18,      /* Digital Active - videoss[0].ttl_dsp1_data_a0[11]:1 */
    P1_6_PERI_TR_IO_INPUT3          = 21,       /* Digital Active - peri.tr_io_input[3]:0 */
    P1_6_DAC0_DAC_MCK               = 23,       /* Digital Active - dac[0].dac_mck:0 */
    P1_6_LIN0_LIN_TX0               = 24,       /* Digital Active - lin[0].lin_tx[0]:0 */
    P1_6_CANFD0_TTCAN_TX0           = 25,       /* Digital Active - canfd[0].ttcan_tx[0]:0 */
    P1_6_CXPI0_CXPI_TX0             = 26,       /* Digital Active - cxpi[0].cxpi_tx[0]:0 */

    /* P1.7 */
    P1_7_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_7_AMUXA                      =  4,       /* AMUXBUS A */
    P1_7_AMUXB                      =  5,       /* AMUXBUS B */
    P1_7_TCPWM0_LINE523             =  8,       /* Digital Active - tcpwm[0].line[523]:0 */
    P1_7_TCPWM0_LINE_COMPL523       =  9,       /* Digital Active - tcpwm[0].line_compl[523]:0 */
    P1_7_TCPWM0_TR_ONE_CNT_IN523    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[523]:0 */
    P1_7_TDM0_TDM_TX_FSYNC0         = 16,       /* Digital Active - tdm[0].tdm_tx_fsync[0]:1 */
    P1_7_TDM0_TDM_RX_FSYNC1         = 17,       /* Digital Active - tdm[0].tdm_rx_fsync[1]:3 */
    P1_7_VIDEOSS0_TTL_DSP1_DATA_A110 = 18,      /* Digital Active - videoss[0].ttl_dsp1_data_a1[10]:1 */
    P1_7_PWM0_PWM_LINE1_P0          = 21,       /* Digital Active - pwm[0].pwm_line1_p[0]:3 */
    P1_7_PERI_TR_IO_INPUT4          = 22,       /* Digital Active - peri.tr_io_input[4]:0 */
    P1_7_LIN0_LIN_RX0               = 24,       /* Digital Active - lin[0].lin_rx[0]:0 */
    P1_7_CANFD0_TTCAN_RX0           = 25,       /* Digital Active - canfd[0].ttcan_rx[0]:0 */
    P1_7_CXPI0_CXPI_RX0             = 26,       /* Digital Active - cxpi[0].cxpi_rx[0]:0 */
    P1_7_SRSS_DDFT_PIN_IN0          = 31,       /* Digital Deep Sleep - srss.ddft_pin_in[0]:1 */

    /* P2.0 */
    P2_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P2_0_AMUXA                      =  4,       /* AMUXBUS A */
    P2_0_AMUXB                      =  5,       /* AMUXBUS B */
    P2_0_TCPWM0_LINE524             =  8,       /* Digital Active - tcpwm[0].line[524]:0 */
    P2_0_TCPWM0_LINE_COMPL524       =  9,       /* Digital Active - tcpwm[0].line_compl[524]:0 */
    P2_0_TCPWM0_TR_ONE_CNT_IN524    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[524]:0 */
    P2_0_TDM0_TDM_TX_MCK0           = 16,       /* Digital Active - tdm[0].tdm_tx_mck[0]:1 */
    P2_0_TDM0_TDM_RX_MCK1           = 17,       /* Digital Active - tdm[0].tdm_rx_mck[1]:3 */
    P2_0_VIDEOSS0_TTL_DSP1_DATA_A010 = 18,      /* Digital Active - videoss[0].ttl_dsp1_data_a0[10]:1 */
    P2_0_PWM0_PWM_LINE1_N0          = 21,       /* Digital Active - pwm[0].pwm_line1_n[0]:3 */
    P2_0_PERI_TR_IO_INPUT5          = 22,       /* Digital Active - peri.tr_io_input[5]:0 */
    P2_0_LIN0_LIN_EN0               = 24,       /* Digital Active - lin[0].lin_en[0]:0 */
    P2_0_CANFD0_TTCAN_TX1           = 25,       /* Digital Active - canfd[0].ttcan_tx[1]:0 */
    P2_0_CXPI0_CXPI_EN0             = 26,       /* Digital Active - cxpi[0].cxpi_en[0]:0 */

    /* P2.1 */
    P2_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P2_1_AMUXA                      =  4,       /* AMUXBUS A */
    P2_1_AMUXB                      =  5,       /* AMUXBUS B */
    P2_1_TCPWM0_LINE525             =  8,       /* Digital Active - tcpwm[0].line[525]:0 */
    P2_1_TCPWM0_LINE_COMPL527       =  9,       /* Digital Active - tcpwm[0].line_compl[527]:0 */
    P2_1_TCPWM0_TR_ONE_CNT_IN526    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[526]:0 */
    P2_1_VIDEOSS0_TTL_CAP0_DATA23   = 11,       /* Digital Active - videoss[0].ttl_cap0_data[23]:1 */
    P2_1_TDM0_TDM_TX_SCK0           = 16,       /* Digital Active - tdm[0].tdm_tx_sck[0]:1 */
    P2_1_TDM0_TDM_RX_SCK1           = 17,       /* Digital Active - tdm[0].tdm_rx_sck[1]:3 */
    P2_1_PERI_TR_IO_INPUT0          = 20,       /* Digital Active - peri.tr_io_input[0]:1 */
    P2_1_PWM0_PWM_LINE2_P0          = 21,       /* Digital Active - pwm[0].pwm_line2_p[0]:3 */
    P2_1_PERI_TR_IO_OUTPUT0         = 22,       /* Digital Active - peri.tr_io_output[0]:0 */
    P2_1_CPUSS_CAL_SUP_NZ           = 23,       /* Digital Active - cpuss.cal_sup_nz:0 */
    P2_1_LIN0_LIN_EN0               = 24,       /* Digital Active - lin[0].lin_en[0]:1 */
    P2_1_CANFD0_TTCAN_RX1           = 25,       /* Digital Active - canfd[0].ttcan_rx[1]:0 */
    P2_1_CXPI0_CXPI_EN0             = 26,       /* Digital Active - cxpi[0].cxpi_en[0]:1 */
    P2_1_CPUSS_FAULT_OUT0           = 27,       /* Digital Active - cpuss.fault_out[0]:0 */
    P2_1_SRSS_CAL_WAVE              = 29,       /* Digital Deep Sleep - srss.cal_wave:0 */
    P2_1_SRSS_DDFT_PIN_IN0          = 31,       /* Digital Deep Sleep - srss.ddft_pin_in[0]:0 */

    /* P2.2 */
    P2_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P2_2_AMUXA                      =  4,       /* AMUXBUS A */
    P2_2_AMUXB                      =  5,       /* AMUXBUS B */
    P2_2_TCPWM0_LINE526             =  8,       /* Digital Active - tcpwm[0].line[526]:0 */
    P2_2_TCPWM0_LINE_COMPL525       =  9,       /* Digital Active - tcpwm[0].line_compl[525]:0 */
    P2_2_TCPWM0_TR_ONE_CNT_IN527    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[527]:0 */
    P2_2_TDM0_TDM_TX_SD0            = 16,       /* Digital Active - tdm[0].tdm_tx_sd[0]:1 */
    P2_2_TDM0_TDM_RX_SD1            = 17,       /* Digital Active - tdm[0].tdm_rx_sd[1]:3 */
    P2_2_PWM0_PWM_LINE2_N0          = 21,       /* Digital Active - pwm[0].pwm_line2_n[0]:3 */
    P2_2_PERI_TR_IO_OUTPUT0         = 22,       /* Digital Active - peri.tr_io_output[0]:1 */
    P2_2_LIN0_LIN_RX1               = 24,       /* Digital Active - lin[0].lin_rx[1]:0 */
    P2_2_CXPI0_CXPI_RX1             = 25,       /* Digital Active - cxpi[0].cxpi_rx[1]:0 */
    P2_2_CPUSS_SWJ_SWO_TDO          = 29,       /* Digital Deep Sleep - cpuss.swj_swo_tdo:0 */
    P2_2_SRSS_DDFT_PIN_IN1          = 31,       /* Digital Deep Sleep - srss.ddft_pin_in[1]:0 */

    /* P2.4 */
    P2_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P2_4_AMUXA                      =  4,       /* AMUXBUS A */
    P2_4_AMUXB                      =  5,       /* AMUXBUS B */
    P2_4_TCPWM0_LINE527             =  8,       /* Digital Active - tcpwm[0].line[527]:0 */
    P2_4_TCPWM0_LINE_COMPL526       =  9,       /* Digital Active - tcpwm[0].line_compl[526]:0 */
    P2_4_TCPWM0_TR_ONE_CNT_IN525    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[525]:0 */
    P2_4_TDM0_TDM_TX_FSYNC1         = 16,       /* Digital Active - tdm[0].tdm_tx_fsync[1]:1 */
    P2_4_TDM0_TDM_RX_FSYNC0         = 17,       /* Digital Active - tdm[0].tdm_rx_fsync[0]:2 */
    P2_4_PWM0_PWM_LINE1_P1          = 21,       /* Digital Active - pwm[0].pwm_line1_p[1]:3 */
    P2_4_PERI_TR_IO_INPUT6          = 22,       /* Digital Active - peri.tr_io_input[6]:0 */
    P2_4_LIN0_LIN_TX1               = 24,       /* Digital Active - lin[0].lin_tx[1]:0 */
    P2_4_CXPI0_CXPI_TX1             = 25,       /* Digital Active - cxpi[0].cxpi_tx[1]:0 */
    P2_4_CPUSS_SWJ_SWCLK_TCLK       = 29,       /* Digital Deep Sleep - cpuss.swj_swclk_tclk:0 */

    /* P2.5 */
    P2_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P2_5_AMUXA                      =  4,       /* AMUXBUS A */
    P2_5_AMUXB                      =  5,       /* AMUXBUS B */
    P2_5_TCPWM0_LINE0               =  8,       /* Digital Active - tcpwm[0].line[0]:0 */
    P2_5_TCPWM0_LINE_COMPL2         =  9,       /* Digital Active - tcpwm[0].line_compl[2]:0 */
    P2_5_TDM0_TDM_TX_MCK1           = 16,       /* Digital Active - tdm[0].tdm_tx_mck[1]:1 */
    P2_5_TDM0_TDM_RX_MCK0           = 17,       /* Digital Active - tdm[0].tdm_rx_mck[0]:2 */
    P2_5_PWM0_PWM_LINE1_N1          = 21,       /* Digital Active - pwm[0].pwm_line1_n[1]:3 */
    P2_5_PERI_TR_IO_INPUT7          = 22,       /* Digital Active - peri.tr_io_input[7]:0 */
    P2_5_LIN0_LIN_EN1               = 24,       /* Digital Active - lin[0].lin_en[1]:0 */
    P2_5_CXPI0_CXPI_EN1             = 25,       /* Digital Active - cxpi[0].cxpi_en[1]:0 */
    P2_5_CPUSS_SWJ_SWDIO_TMS        = 29,       /* Digital Deep Sleep - cpuss.swj_swdio_tms:0 */

    /* P3.0 */
    P3_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P3_0_AMUXA                      =  4,       /* AMUXBUS A */
    P3_0_AMUXB                      =  5,       /* AMUXBUS B */
    P3_0_TCPWM0_LINE1               =  8,       /* Digital Active - tcpwm[0].line[1]:0 */
    P3_0_TCPWM0_LINE_COMPL0         =  9,       /* Digital Active - tcpwm[0].line_compl[0]:0 */
    P3_0_TDM0_TDM_TX_SCK1           = 16,       /* Digital Active - tdm[0].tdm_tx_sck[1]:1 */
    P3_0_TDM0_TDM_RX_SCK0           = 17,       /* Digital Active - tdm[0].tdm_rx_sck[0]:2 */
    P3_0_PWM0_PWM_LINE2_P1          = 21,       /* Digital Active - pwm[0].pwm_line2_p[1]:3 */
    P3_0_PERI_TR_IO_INPUT8          = 22,       /* Digital Active - peri.tr_io_input[8]:0 */
    P3_0_CPUSS_SWJ_SWDOE_TDI        = 29,       /* Digital Deep Sleep - cpuss.swj_swdoe_tdi:0 */
    P3_0_SCB0_I2C_SDA               = 30,       /* Digital Deep Sleep - scb[0].i2c_sda:0 */

    /* P3.1 */
    P3_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P3_1_AMUXA                      =  4,       /* AMUXBUS A */
    P3_1_AMUXB                      =  5,       /* AMUXBUS B */
    P3_1_TCPWM0_LINE2               =  8,       /* Digital Active - tcpwm[0].line[2]:0 */
    P3_1_TCPWM0_LINE_COMPL1         =  9,       /* Digital Active - tcpwm[0].line_compl[1]:0 */
    P3_1_TDM0_TDM_TX_SD1            = 16,       /* Digital Active - tdm[0].tdm_tx_sd[1]:1 */
    P3_1_TDM0_TDM_RX_SD0            = 17,       /* Digital Active - tdm[0].tdm_rx_sd[0]:2 */
    P3_1_PWM0_PWM_LINE2_N1          = 21,       /* Digital Active - pwm[0].pwm_line2_n[1]:3 */
    P3_1_PERI_TR_IO_INPUT9          = 22,       /* Digital Active - peri.tr_io_input[9]:0 */
    P3_1_CPUSS_SWJ_TRSTN            = 29,       /* Digital Deep Sleep - cpuss.swj_trstn:0 */
    P3_1_SCB0_I2C_SCL               = 30,       /* Digital Deep Sleep - scb[0].i2c_scl:0 */

    /* P4.0 */
    P4_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_0_AMUXA                      =  4,       /* AMUXBUS A */
    P4_0_AMUXB                      =  5,       /* AMUXBUS B */
    P4_0_TCPWM0_LINE514             =  8,       /* Digital Active - tcpwm[0].line[514]:0 */
    P4_0_TCPWM0_LINE_COMPL513       =  9,       /* Digital Active - tcpwm[0].line_compl[513]:0 */
    P4_0_TCPWM0_TR_ONE_CNT_IN512    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[512]:0 */
    P4_0_VIDEOSS0_TTL_CAP0_DATA22   = 11,       /* Digital Active - videoss[0].ttl_cap0_data[22]:1 */
    P4_0_SCB7_SPI_CLK               = 25,       /* Digital Active - scb[7].spi_clk:0 */
    P4_0_SCB7_UART_RX               = 26,       /* Digital Active - scb[7].uart_rx:0 */
    P4_0_SCB7_I2C_SDA               = 27,       /* Digital Active - scb[7].i2c_sda:0 */

    /* P4.1 */
    P4_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_1_AMUXA                      =  4,       /* AMUXBUS A */
    P4_1_AMUXB                      =  5,       /* AMUXBUS B */
    P4_1_TCPWM0_LINE515             =  8,       /* Digital Active - tcpwm[0].line[515]:0 */
    P4_1_TCPWM0_LINE_COMPL514       =  9,       /* Digital Active - tcpwm[0].line_compl[514]:0 */
    P4_1_TCPWM0_TR_ONE_CNT_IN513    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[513]:0 */
    P4_1_VIDEOSS0_TTL_CAP0_DATA21   = 11,       /* Digital Active - videoss[0].ttl_cap0_data[21]:1 */
    P4_1_SCB7_SPI_MOSI              = 25,       /* Digital Active - scb[7].spi_mosi:0 */
    P4_1_SCB7_UART_TX               = 26,       /* Digital Active - scb[7].uart_tx:0 */
    P4_1_SCB7_I2C_SCL               = 27,       /* Digital Active - scb[7].i2c_scl:0 */

    /* P4.2 */
    P4_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_2_AMUXA                      =  4,       /* AMUXBUS A */
    P4_2_AMUXB                      =  5,       /* AMUXBUS B */
    P4_2_TCPWM0_LINE512             =  8,       /* Digital Active - tcpwm[0].line[512]:0 */
    P4_2_TCPWM0_LINE_COMPL521       =  9,       /* Digital Active - tcpwm[0].line_compl[521]:0 */
    P4_2_TCPWM0_TR_ONE_CNT_IN520    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[520]:0 */
    P4_2_VIDEOSS0_TTL_CAP0_DATA20   = 11,       /* Digital Active - videoss[0].ttl_cap0_data[20]:1 */
    P4_2_SCB7_SPI_MISO              = 25,       /* Digital Active - scb[7].spi_miso:0 */
    P4_2_SCB7_UART_RTS              = 26,       /* Digital Active - scb[7].uart_rts:0 */

    /* P4.3 */
    P4_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_3_AMUXA                      =  4,       /* AMUXBUS A */
    P4_3_AMUXB                      =  5,       /* AMUXBUS B */
    P4_3_TCPWM0_LINE513             =  8,       /* Digital Active - tcpwm[0].line[513]:0 */
    P4_3_TCPWM0_LINE_COMPL512       =  9,       /* Digital Active - tcpwm[0].line_compl[512]:0 */
    P4_3_TCPWM0_TR_ONE_CNT_IN521    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[521]:0 */
    P4_3_VIDEOSS0_TTL_CAP0_DATA19   = 11,       /* Digital Active - videoss[0].ttl_cap0_data[19]:1 */
    P4_3_SCB7_SPI_SELECT0           = 25,       /* Digital Active - scb[7].spi_select0:0 */
    P4_3_SCB7_UART_CTS              = 26,       /* Digital Active - scb[7].uart_cts:0 */

    /* P4.4 */
    P4_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_4_AMUXA                      =  4,       /* AMUXBUS A */
    P4_4_AMUXB                      =  5,       /* AMUXBUS B */
    P4_4_TCPWM0_LINE9               =  8,       /* Digital Active - tcpwm[0].line[9]:0 */
    P4_4_TCPWM0_LINE_COMPL8         =  9,       /* Digital Active - tcpwm[0].line_compl[8]:0 */
    P4_4_PASS0_SAR_EXT_MUX_SEL2     = 16,       /* Digital Active - pass[0].sar_ext_mux_sel[2] */
    P4_4_PERI_TR_IO_INPUT16         = 21,       /* Digital Active - peri.tr_io_input[16]:0 */
    P4_4_SG0_SG_AMPL1               = 22,       /* Digital Active - sg[0].sg_ampl[1]:2 */
    P4_4_CANFD0_TTCAN_TX1           = 25,       /* Digital Active - canfd[0].ttcan_tx[1]:1 */
    P4_4_CPUSS_FAULT_OUT1           = 27,       /* Digital Active - cpuss.fault_out[1]:0 */
    P4_4_SCB0_SPI_SELECT3           = 30,       /* Digital Deep Sleep - scb[0].spi_select3:0 */

    /* P4.5 */
    P4_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_5_AMUXA                      =  4,       /* AMUXBUS A */
    P4_5_AMUXB                      =  5,       /* AMUXBUS B */
    P4_5_TCPWM0_LINE10              =  8,       /* Digital Active - tcpwm[0].line[10]:0 */
    P4_5_TCPWM0_LINE_COMPL9         =  9,       /* Digital Active - tcpwm[0].line_compl[9]:0 */
    P4_5_PASS0_SAR_EXT_MUX_SEL3     = 16,       /* Digital Active - pass[0].sar_ext_mux_sel[3] */
    P4_5_PERI_TR_IO_INPUT17         = 21,       /* Digital Active - peri.tr_io_input[17]:0 */
    P4_5_SG0_SG_TONE1               = 22,       /* Digital Active - sg[0].sg_tone[1]:2 */
    P4_5_CANFD0_TTCAN_RX1           = 25,       /* Digital Active - canfd[0].ttcan_rx[1]:1 */
    P4_5_CPUSS_FAULT_OUT2           = 27,       /* Digital Active - cpuss.fault_out[2]:0 */
    P4_5_SCB0_I2C_SDA               = 30,       /* Digital Deep Sleep - scb[0].i2c_sda:1 */

    /* P4.6 */
    P4_6_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_6_AMUXA                      =  4,       /* AMUXBUS A */
    P4_6_AMUXB                      =  5,       /* AMUXBUS B */
    P4_6_TCPWM0_LINE11              =  8,       /* Digital Active - tcpwm[0].line[11]:0 */
    P4_6_TCPWM0_LINE_COMPL10        =  9,       /* Digital Active - tcpwm[0].line_compl[10]:0 */
    P4_6_PASS0_SAR_EXT_MUX_SEL4     = 16,       /* Digital Active - pass[0].sar_ext_mux_sel[4] */
    P4_6_PERI_TR_IO_INPUT18         = 21,       /* Digital Active - peri.tr_io_input[18]:0 */
    P4_6_SG0_SG_AMPL2               = 22,       /* Digital Active - sg[0].sg_ampl[2]:2 */
    P4_6_CANFD1_TTCAN_TX0           = 25,       /* Digital Active - canfd[1].ttcan_tx[0]:0 */
    P4_6_CPUSS_FAULT_OUT3           = 27,       /* Digital Active - cpuss.fault_out[3]:0 */
    P4_6_SCB0_I2C_SCL               = 30,       /* Digital Deep Sleep - scb[0].i2c_scl:1 */

    /* P4.7 */
    P4_7_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_7_AMUXA                      =  4,       /* AMUXBUS A */
    P4_7_AMUXB                      =  5,       /* AMUXBUS B */
    P4_7_TCPWM0_LINE12              =  8,       /* Digital Active - tcpwm[0].line[12]:0 */
    P4_7_TCPWM0_LINE_COMPL11        =  9,       /* Digital Active - tcpwm[0].line_compl[11]:0 */
    P4_7_PASS0_SAR_EXT_MUX_SEL5     = 16,       /* Digital Active - pass[0].sar_ext_mux_sel[5] */
    P4_7_PERI_TR_IO_INPUT19         = 21,       /* Digital Active - peri.tr_io_input[19]:0 */
    P4_7_SG0_SG_TONE2               = 22,       /* Digital Active - sg[0].sg_tone[2]:2 */
    P4_7_CANFD1_TTCAN_RX0           = 25,       /* Digital Active - canfd[1].ttcan_rx[0]:0 */

    /* P5.0 */
    P5_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P5_0_AMUXA                      =  4,       /* AMUXBUS A */
    P5_0_AMUXB                      =  5,       /* AMUXBUS B */
    P5_0_TCPWM0_LINE3               =  8,       /* Digital Active - tcpwm[0].line[3]:0 */
    P5_0_TCPWM0_LINE_COMPL16        =  9,       /* Digital Active - tcpwm[0].line_compl[16]:0 */
    P5_0_VIDEOSS0_TTL_CAP0_DATA18   = 11,       /* Digital Active - videoss[0].ttl_cap0_data[18]:1 */
    P5_0_SCB3_I2C_SDA               = 20,       /* Digital Active - scb[3].i2c_sda:1 */
    P5_0_PERI_TR_IO_INPUT10         = 21,       /* Digital Active - peri.tr_io_input[10]:0 */
    P5_0_CPUSS_CLK_FM_PUMP          = 22,       /* Digital Active - cpuss.clk_fm_pump */
    P5_0_SCB0_UART_RX               = 23,       /* Digital Active - scb[0].uart_rx:0 */
    P5_0_SCB0_SPI_CLK               = 30,       /* Digital Deep Sleep - scb[0].spi_clk:0 */

    /* P5.1 */
    P5_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P5_1_AMUXA                      =  4,       /* AMUXBUS A */
    P5_1_AMUXB                      =  5,       /* AMUXBUS B */
    P5_1_TCPWM0_LINE4               =  8,       /* Digital Active - tcpwm[0].line[4]:0 */
    P5_1_TCPWM0_LINE_COMPL3         =  9,       /* Digital Active - tcpwm[0].line_compl[3]:0 */
    P5_1_VIDEOSS0_TTL_CAP0_DATA17   = 11,       /* Digital Active - videoss[0].ttl_cap0_data[17]:1 */
    P5_1_SCB3_I2C_SCL               = 20,       /* Digital Active - scb[3].i2c_scl:1 */
    P5_1_PERI_TR_IO_INPUT11         = 21,       /* Digital Active - peri.tr_io_input[11]:0 */
    P5_1_SCB0_UART_TX               = 23,       /* Digital Active - scb[0].uart_tx:0 */
    P5_1_LIN0_LIN_TX1               = 24,       /* Digital Active - lin[0].lin_tx[1]:1 */
    P5_1_CXPI0_CXPI_EN1             = 25,       /* Digital Active - cxpi[0].cxpi_en[1]:1 */
    P5_1_SCB0_SPI_MOSI              = 30,       /* Digital Deep Sleep - scb[0].spi_mosi:0 */

    /* P5.2 */
    P5_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P5_2_AMUXA                      =  4,       /* AMUXBUS A */
    P5_2_AMUXB                      =  5,       /* AMUXBUS B */
    P5_2_TCPWM0_LINE5               =  8,       /* Digital Active - tcpwm[0].line[5]:0 */
    P5_2_TCPWM0_LINE_COMPL4         =  9,       /* Digital Active - tcpwm[0].line_compl[4]:0 */
    P5_2_PERI_TR_IO_INPUT12         = 21,       /* Digital Active - peri.tr_io_input[12]:0 */
    P5_2_SCB1_I2C_SDA               = 22,       /* Digital Active - scb[1].i2c_sda:1 */
    P5_2_SCB0_UART_RTS              = 23,       /* Digital Active - scb[0].uart_rts:0 */
    P5_2_LIN0_LIN_RX1               = 24,       /* Digital Active - lin[0].lin_rx[1]:1 */
    P5_2_CXPI0_CXPI_RX1             = 25,       /* Digital Active - cxpi[0].cxpi_rx[1]:1 */
    P5_2_SCB0_SPI_MISO              = 30,       /* Digital Deep Sleep - scb[0].spi_miso:0 */

    /* P5.3 */
    P5_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P5_3_AMUXA                      =  4,       /* AMUXBUS A */
    P5_3_AMUXB                      =  5,       /* AMUXBUS B */
    P5_3_TCPWM0_LINE6               =  8,       /* Digital Active - tcpwm[0].line[6]:0 */
    P5_3_TCPWM0_LINE_COMPL5         =  9,       /* Digital Active - tcpwm[0].line_compl[5]:0 */
    P5_3_PERI_TR_IO_INPUT13         = 21,       /* Digital Active - peri.tr_io_input[13]:0 */
    P5_3_SCB1_I2C_SCL               = 22,       /* Digital Active - scb[1].i2c_scl:1 */
    P5_3_SCB0_UART_CTS              = 23,       /* Digital Active - scb[0].uart_cts:0 */
    P5_3_LIN0_LIN_EN1               = 24,       /* Digital Active - lin[0].lin_en[1]:1 */
    P5_3_CXPI0_CXPI_TX1             = 25,       /* Digital Active - cxpi[0].cxpi_tx[1]:1 */
    P5_3_SCB0_SPI_SELECT0           = 30,       /* Digital Deep Sleep - scb[0].spi_select0:0 */

    /* P5.4 */
    P5_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P5_4_AMUXA                      =  4,       /* AMUXBUS A */
    P5_4_AMUXB                      =  5,       /* AMUXBUS B */
    P5_4_TCPWM0_LINE7               =  8,       /* Digital Active - tcpwm[0].line[7]:0 */
    P5_4_TCPWM0_LINE_COMPL6         =  9,       /* Digital Active - tcpwm[0].line_compl[6]:0 */
    P5_4_PASS0_SAR_EXT_MUX_SEL0     = 16,       /* Digital Active - pass[0].sar_ext_mux_sel[0] */
    P5_4_SCB2_I2C_SDA               = 17,       /* Digital Active - scb[2].i2c_sda:1 */
    P5_4_PERI_TR_IO_INPUT14         = 21,       /* Digital Active - peri.tr_io_input[14]:0 */
    P5_4_SG0_SG_AMPL0               = 22,       /* Digital Active - sg[0].sg_ampl[0]:2 */
    P5_4_CANFD0_TTCAN_TX0           = 25,       /* Digital Active - canfd[0].ttcan_tx[0]:1 */
    P5_4_SCB0_SPI_SELECT1           = 30,       /* Digital Deep Sleep - scb[0].spi_select1:0 */

    /* P5.5 */
    P5_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P5_5_AMUXA                      =  4,       /* AMUXBUS A */
    P5_5_AMUXB                      =  5,       /* AMUXBUS B */
    P5_5_TCPWM0_LINE8               =  8,       /* Digital Active - tcpwm[0].line[8]:0 */
    P5_5_TCPWM0_LINE_COMPL7         =  9,       /* Digital Active - tcpwm[0].line_compl[7]:0 */
    P5_5_PASS0_SAR_EXT_MUX_SEL1     = 16,       /* Digital Active - pass[0].sar_ext_mux_sel[1] */
    P5_5_SCB2_I2C_SCL               = 17,       /* Digital Active - scb[2].i2c_scl:1 */
    P5_5_PERI_TR_IO_INPUT15         = 21,       /* Digital Active - peri.tr_io_input[15]:0 */
    P5_5_SG0_SG_TONE0               = 22,       /* Digital Active - sg[0].sg_tone[0]:2 */
    P5_5_CANFD0_TTCAN_RX0           = 25,       /* Digital Active - canfd[0].ttcan_rx[0]:1 */
    P5_5_SCB0_SPI_SELECT2           = 30,       /* Digital Deep Sleep - scb[0].spi_select2:0 */

    /* P6.0 */
    P6_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_0_AMUXA                      =  4,       /* AMUXBUS A */
    P6_0_AMUXB                      =  5,       /* AMUXBUS B */
    P6_0_TCPWM0_LINE13              =  8,       /* Digital Active - tcpwm[0].line[13]:0 */
    P6_0_TCPWM0_LINE_COMPL12        =  9,       /* Digital Active - tcpwm[0].line_compl[12]:0 */
    P6_0_PASS0_SAR_EXT_MUX_EN0      = 16,       /* Digital Active - pass[0].sar_ext_mux_en[0] */
    P6_0_PERI_TR_IO_INPUT20         = 21,       /* Digital Active - peri.tr_io_input[20]:0 */
    P6_0_SG0_SG_AMPL3               = 22,       /* Digital Active - sg[0].sg_ampl[3]:2 */
    P6_0_CANFD1_TTCAN_TX1           = 25,       /* Digital Active - canfd[1].ttcan_tx[1]:0 */

    /* P6.1 */
    P6_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_1_AMUXA                      =  4,       /* AMUXBUS A */
    P6_1_AMUXB                      =  5,       /* AMUXBUS B */
    P6_1_TCPWM0_LINE14              =  8,       /* Digital Active - tcpwm[0].line[14]:0 */
    P6_1_TCPWM0_LINE_COMPL13        =  9,       /* Digital Active - tcpwm[0].line_compl[13]:0 */
    P6_1_PASS0_SAR_EXT_MUX_EN1      = 16,       /* Digital Active - pass[0].sar_ext_mux_en[1] */
    P6_1_PERI_TR_IO_INPUT21         = 21,       /* Digital Active - peri.tr_io_input[21]:0 */
    P6_1_SG0_SG_TONE3               = 22,       /* Digital Active - sg[0].sg_tone[3]:2 */
    P6_1_CANFD1_TTCAN_RX1           = 25,       /* Digital Active - canfd[1].ttcan_rx[1]:0 */

    /* P6.2 */
    P6_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_2_AMUXA                      =  4,       /* AMUXBUS A */
    P6_2_AMUXB                      =  5,       /* AMUXBUS B */
    P6_2_TCPWM0_LINE15              =  8,       /* Digital Active - tcpwm[0].line[15]:0 */
    P6_2_TCPWM0_LINE_COMPL14        =  9,       /* Digital Active - tcpwm[0].line_compl[14]:0 */
    P6_2_PERI_TR_IO_INPUT22         = 21,       /* Digital Active - peri.tr_io_input[22]:0 */
    P6_2_SG0_SG_AMPL4               = 22,       /* Digital Active - sg[0].sg_ampl[4]:0 */

    /* P6.3 */
    P6_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_3_AMUXA                      =  4,       /* AMUXBUS A */
    P6_3_AMUXB                      =  5,       /* AMUXBUS B */
    P6_3_TCPWM0_LINE16              =  8,       /* Digital Active - tcpwm[0].line[16]:0 */
    P6_3_TCPWM0_LINE_COMPL15        =  9,       /* Digital Active - tcpwm[0].line_compl[15]:0 */
    P6_3_PERI_TR_IO_INPUT23         = 21,       /* Digital Active - peri.tr_io_input[23]:0 */
    P6_3_SG0_SG_TONE4               = 22,       /* Digital Active - sg[0].sg_tone[4]:0 */

    /* P7.0 */
    P7_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_0_AMUXA                      =  4,       /* AMUXBUS A */
    P7_0_AMUXB                      =  5,       /* AMUXBUS B */
    P7_0_TCPWM0_LINE256             =  8,       /* Digital Active - tcpwm[0].line[256]:0 */
    P7_0_TCPWM0_LINE_COMPL533       =  9,       /* Digital Active - tcpwm[0].line_compl[533]:0 */
    P7_0_VIDEOSS0_TTL_CAP0_DATA16   = 11,       /* Digital Active - videoss[0].ttl_cap0_data[16]:1 */
    P7_0_SG0_SG_MCK1                = 18,       /* Digital Active - sg[0].sg_mck[1]:0 */
    P7_0_PERI_TR_IO_INPUT24         = 21,       /* Digital Active - peri.tr_io_input[24]:0 */
    P7_0_SCB5_SPI_CLK               = 25,       /* Digital Active - scb[5].spi_clk:0 */
    P7_0_SCB5_UART_RX               = 26,       /* Digital Active - scb[5].uart_rx:0 */
    P7_0_SCB5_I2C_SDA               = 27,       /* Digital Active - scb[5].i2c_sda:0 */

    /* P7.1 */
    P7_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_1_AMUXA                      =  4,       /* AMUXBUS A */
    P7_1_AMUXB                      =  5,       /* AMUXBUS B */
    P7_1_TCPWM0_LINE528             =  8,       /* Digital Active - tcpwm[0].line[528]:0 */
    P7_1_TCPWM0_LINE_COMPL256       =  9,       /* Digital Active - tcpwm[0].line_compl[256]:0 */
    P7_1_TCPWM0_TR_ONE_CNT_IN533    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[533]:0 */
    P7_1_VIDEOSS0_TTL_CAP0_DATA15   = 11,       /* Digital Active - videoss[0].ttl_cap0_data[15]:1 */
    P7_1_SG0_SG_MCK2                = 18,       /* Digital Active - sg[0].sg_mck[2]:0 */
    P7_1_PERI_TR_IO_INPUT25         = 21,       /* Digital Active - peri.tr_io_input[25]:0 */
    P7_1_SCB5_SPI_MOSI              = 25,       /* Digital Active - scb[5].spi_mosi:0 */
    P7_1_SCB5_UART_TX               = 26,       /* Digital Active - scb[5].uart_tx:0 */
    P7_1_SCB5_I2C_SCL               = 27,       /* Digital Active - scb[5].i2c_scl:0 */

    /* P7.2 */
    P7_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_2_AMUXA                      =  4,       /* AMUXBUS A */
    P7_2_AMUXB                      =  5,       /* AMUXBUS B */
    P7_2_TCPWM0_LINE257             =  8,       /* Digital Active - tcpwm[0].line[257]:0 */
    P7_2_TCPWM0_LINE_COMPL528       =  9,       /* Digital Active - tcpwm[0].line_compl[528]:0 */
    P7_2_VIDEOSS0_TTL_CAP0_DATA14   = 11,       /* Digital Active - videoss[0].ttl_cap0_data[14]:1 */
    P7_2_SG0_SG_MCK3                = 18,       /* Digital Active - sg[0].sg_mck[3]:0 */
    P7_2_PERI_TR_IO_INPUT26         = 21,       /* Digital Active - peri.tr_io_input[26]:0 */
    P7_2_SCB10_SPI_SELECT1          = 24,       /* Digital Active - scb[10].spi_select1:0 */
    P7_2_SCB5_SPI_MISO              = 25,       /* Digital Active - scb[5].spi_miso:0 */
    P7_2_SCB5_UART_RTS              = 26,       /* Digital Active - scb[5].uart_rts:0 */

    /* P7.3 */
    P7_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_3_AMUXA                      =  4,       /* AMUXBUS A */
    P7_3_AMUXB                      =  5,       /* AMUXBUS B */
    P7_3_TCPWM0_LINE529             =  8,       /* Digital Active - tcpwm[0].line[529]:0 */
    P7_3_TCPWM0_LINE_COMPL257       =  9,       /* Digital Active - tcpwm[0].line_compl[257]:0 */
    P7_3_TCPWM0_TR_ONE_CNT_IN528    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[528]:0 */
    P7_3_VIDEOSS0_TTL_CAP0_DATA13   = 11,       /* Digital Active - videoss[0].ttl_cap0_data[13]:1 */
    P7_3_SG0_SG_MCK4                = 18,       /* Digital Active - sg[0].sg_mck[4]:0 */
    P7_3_PERI_TR_IO_INPUT27         = 21,       /* Digital Active - peri.tr_io_input[27]:0 */
    P7_3_SCB11_SPI_SELECT1          = 24,       /* Digital Active - scb[11].spi_select1:0 */
    P7_3_SCB5_SPI_SELECT0           = 25,       /* Digital Active - scb[5].spi_select0:0 */
    P7_3_SCB5_UART_CTS              = 26,       /* Digital Active - scb[5].uart_cts:0 */

    /* P7.4 */
    P7_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_4_AMUXA                      =  4,       /* AMUXBUS A */
    P7_4_AMUXB                      =  5,       /* AMUXBUS B */
    P7_4_TCPWM0_LINE258             =  8,       /* Digital Active - tcpwm[0].line[258]:0 */
    P7_4_TCPWM0_LINE_COMPL529       =  9,       /* Digital Active - tcpwm[0].line_compl[529]:0 */
    P7_4_VIDEOSS0_TTL_CAP0_DATA12   = 11,       /* Digital Active - videoss[0].ttl_cap0_data[12]:1 */
    P7_4_PERI_TR_IO_INPUT28         = 21,       /* Digital Active - peri.tr_io_input[28]:0 */
    P7_4_SCB9_SPI_CLK               = 25,       /* Digital Active - scb[9].spi_clk:0 */
    P7_4_SCB9_UART_RX               = 26,       /* Digital Active - scb[9].uart_rx:0 */
    P7_4_SCB9_I2C_SDA               = 27,       /* Digital Active - scb[9].i2c_sda:0 */

    /* P7.5 */
    P7_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_5_AMUXA                      =  4,       /* AMUXBUS A */
    P7_5_AMUXB                      =  5,       /* AMUXBUS B */
    P7_5_TCPWM0_LINE530             =  8,       /* Digital Active - tcpwm[0].line[530]:0 */
    P7_5_TCPWM0_LINE_COMPL258       =  9,       /* Digital Active - tcpwm[0].line_compl[258]:0 */
    P7_5_TCPWM0_TR_ONE_CNT_IN529    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[529]:0 */
    P7_5_PERI_TR_IO_INPUT29         = 21,       /* Digital Active - peri.tr_io_input[29]:0 */
    P7_5_VIDEOSS0_TTL_CAP0_DATA11   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[11]:1 */
    P7_5_SCB9_SPI_MOSI              = 25,       /* Digital Active - scb[9].spi_mosi:0 */
    P7_5_SCB9_UART_TX               = 26,       /* Digital Active - scb[9].uart_tx:0 */
    P7_5_SCB9_I2C_SCL               = 27,       /* Digital Active - scb[9].i2c_scl:0 */

    /* P7.6 */
    P7_6_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_6_AMUXA                      =  4,       /* AMUXBUS A */
    P7_6_AMUXB                      =  5,       /* AMUXBUS B */
    P7_6_TCPWM0_LINE259             =  8,       /* Digital Active - tcpwm[0].line[259]:0 */
    P7_6_TCPWM0_LINE_COMPL530       =  9,       /* Digital Active - tcpwm[0].line_compl[530]:0 */
    P7_6_PERI_TR_IO_INPUT30         = 21,       /* Digital Active - peri.tr_io_input[30]:0 */
    P7_6_VIDEOSS0_TTL_CAP0_DATA10   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[10]:1 */
    P7_6_SCB9_SPI_MISO              = 25,       /* Digital Active - scb[9].spi_miso:0 */
    P7_6_SCB9_UART_RTS              = 26,       /* Digital Active - scb[9].uart_rts:0 */
    P7_6_CPUSS_FAULT_OUT0           = 27,       /* Digital Active - cpuss.fault_out[0]:1 */

    /* P7.7 */
    P7_7_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_7_AMUXA                      =  4,       /* AMUXBUS A */
    P7_7_AMUXB                      =  5,       /* AMUXBUS B */
    P7_7_TCPWM0_LINE531             =  8,       /* Digital Active - tcpwm[0].line[531]:0 */
    P7_7_TCPWM0_LINE_COMPL259       =  9,       /* Digital Active - tcpwm[0].line_compl[259]:0 */
    P7_7_TCPWM0_TR_ONE_CNT_IN530    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[530]:0 */
    P7_7_PERI_TR_IO_INPUT31         = 21,       /* Digital Active - peri.tr_io_input[31]:0 */
    P7_7_VIDEOSS0_TTL_CAP0_CLK      = 23,       /* Digital Active - videoss[0].ttl_cap0_clk:3 */
    P7_7_SCB9_SPI_SELECT0           = 25,       /* Digital Active - scb[9].spi_select0:0 */
    P7_7_SCB9_UART_CTS              = 26,       /* Digital Active - scb[9].uart_cts:0 */
    P7_7_CPUSS_FAULT_OUT1           = 27,       /* Digital Active - cpuss.fault_out[1]:1 */

    /* P8.0 */
    P8_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_0_AMUXA                      =  4,       /* AMUXBUS A */
    P8_0_AMUXB                      =  5,       /* AMUXBUS B */
    P8_0_TCPWM0_LINE260             =  8,       /* Digital Active - tcpwm[0].line[260]:0 */
    P8_0_TCPWM0_LINE_COMPL531       =  9,       /* Digital Active - tcpwm[0].line_compl[531]:0 */
    P8_0_PERI_TR_IO_INPUT32         = 21,       /* Digital Active - peri.tr_io_input[32]:0 */
    P8_0_VIDEOSS0_TTL_CAP0_DATA9    = 23,       /* Digital Active - videoss[0].ttl_cap0_data[9]:3 */
    P8_0_SCB10_SPI_CLK              = 25,       /* Digital Active - scb[10].spi_clk:0 */
    P8_0_SCB10_UART_RX              = 26,       /* Digital Active - scb[10].uart_rx:0 */
    P8_0_SCB10_I2C_SDA              = 27,       /* Digital Active - scb[10].i2c_sda:0 */

    /* P8.1 */
    P8_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_1_AMUXA                      =  4,       /* AMUXBUS A */
    P8_1_AMUXB                      =  5,       /* AMUXBUS B */
    P8_1_TCPWM0_LINE532             =  8,       /* Digital Active - tcpwm[0].line[532]:0 */
    P8_1_TCPWM0_LINE_COMPL260       =  9,       /* Digital Active - tcpwm[0].line_compl[260]:0 */
    P8_1_TCPWM0_TR_ONE_CNT_IN531    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[531]:0 */
    P8_1_PERI_TR_IO_INPUT33         = 21,       /* Digital Active - peri.tr_io_input[33]:0 */
    P8_1_SG0_SG_MCK0                = 22,       /* Digital Active - sg[0].sg_mck[0]:0 */
    P8_1_VIDEOSS0_TTL_CAP0_DATA8    = 23,       /* Digital Active - videoss[0].ttl_cap0_data[8]:3 */
    P8_1_SCB10_SPI_MOSI             = 25,       /* Digital Active - scb[10].spi_mosi:0 */
    P8_1_SCB10_UART_TX              = 26,       /* Digital Active - scb[10].uart_tx:0 */
    P8_1_SCB10_I2C_SCL              = 27,       /* Digital Active - scb[10].i2c_scl:0 */

    /* P8.2 */
    P8_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_2_AMUXA                      =  4,       /* AMUXBUS A */
    P8_2_AMUXB                      =  5,       /* AMUXBUS B */
    P8_2_TCPWM0_LINE261             =  8,       /* Digital Active - tcpwm[0].line[261]:0 */
    P8_2_TCPWM0_LINE_COMPL532       =  9,       /* Digital Active - tcpwm[0].line_compl[532]:0 */
    P8_2_PERI_TR_IO_INPUT34         = 21,       /* Digital Active - peri.tr_io_input[34]:0 */
    P8_2_SG0_SG_AMPL0               = 22,       /* Digital Active - sg[0].sg_ampl[0]:3 */
    P8_2_VIDEOSS0_TTL_CAP0_DATA7    = 23,       /* Digital Active - videoss[0].ttl_cap0_data[7]:3 */
    P8_2_SCB10_SPI_MISO             = 25,       /* Digital Active - scb[10].spi_miso:0 */
    P8_2_SCB10_UART_RTS             = 26,       /* Digital Active - scb[10].uart_rts:0 */

    /* P8.3 */
    P8_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_3_AMUXA                      =  4,       /* AMUXBUS A */
    P8_3_AMUXB                      =  5,       /* AMUXBUS B */
    P8_3_TCPWM0_LINE533             =  8,       /* Digital Active - tcpwm[0].line[533]:0 */
    P8_3_TCPWM0_LINE_COMPL261       =  9,       /* Digital Active - tcpwm[0].line_compl[261]:0 */
    P8_3_TCPWM0_TR_ONE_CNT_IN532    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[532]:0 */
    P8_3_PERI_TR_IO_INPUT35         = 21,       /* Digital Active - peri.tr_io_input[35]:0 */
    P8_3_SG0_SG_TONE0               = 22,       /* Digital Active - sg[0].sg_tone[0]:3 */
    P8_3_VIDEOSS0_TTL_CAP0_DATA6    = 23,       /* Digital Active - videoss[0].ttl_cap0_data[6]:3 */
    P8_3_SCB10_SPI_SELECT0          = 25,       /* Digital Active - scb[10].spi_select0:0 */
    P8_3_SCB10_UART_CTS             = 26,       /* Digital Active - scb[10].uart_cts:0 */

    /* P8.4 */
    P8_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_4_AMUXA                      =  4,       /* AMUXBUS A */
    P8_4_AMUXB                      =  5,       /* AMUXBUS B */
    P8_4_TCPWM0_LINE262             =  8,       /* Digital Active - tcpwm[0].line[262]:0 */
    P8_4_TCPWM0_LINE_COMPL17        =  9,       /* Digital Active - tcpwm[0].line_compl[17]:0 */
    P8_4_PERI_TR_IO_INPUT36         = 21,       /* Digital Active - peri.tr_io_input[36]:0 */
    P8_4_SG0_SG_AMPL1               = 22,       /* Digital Active - sg[0].sg_ampl[1]:3 */
    P8_4_VIDEOSS0_TTL_CAP0_DATA5    = 23,       /* Digital Active - videoss[0].ttl_cap0_data[5]:3 */
    P8_4_SCB11_SPI_CLK              = 25,       /* Digital Active - scb[11].spi_clk:0 */
    P8_4_SCB11_UART_RX              = 26,       /* Digital Active - scb[11].uart_rx:0 */
    P8_4_SCB11_I2C_SDA              = 27,       /* Digital Active - scb[11].i2c_sda:0 */

    /* P8.5 */
    P8_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_5_AMUXA                      =  4,       /* AMUXBUS A */
    P8_5_AMUXB                      =  5,       /* AMUXBUS B */
    P8_5_TCPWM0_LINE17              =  8,       /* Digital Active - tcpwm[0].line[17]:0 */
    P8_5_TCPWM0_LINE_COMPL262       =  9,       /* Digital Active - tcpwm[0].line_compl[262]:0 */
    P8_5_TCPWM0_TR_ONE_CNT_IN22     = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[22]:0 */
    P8_5_PERI_TR_IO_INPUT37         = 21,       /* Digital Active - peri.tr_io_input[37]:0 */
    P8_5_SG0_SG_TONE1               = 22,       /* Digital Active - sg[0].sg_tone[1]:3 */
    P8_5_VIDEOSS0_TTL_CAP0_DATA4    = 23,       /* Digital Active - videoss[0].ttl_cap0_data[4]:3 */
    P8_5_SCB11_SPI_MOSI             = 25,       /* Digital Active - scb[11].spi_mosi:0 */
    P8_5_SCB11_UART_TX              = 26,       /* Digital Active - scb[11].uart_tx:0 */
    P8_5_SCB11_I2C_SCL              = 27,       /* Digital Active - scb[11].i2c_scl:0 */

    /* P8.6 */
    P8_6_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_6_AMUXA                      =  4,       /* AMUXBUS A */
    P8_6_AMUXB                      =  5,       /* AMUXBUS B */
    P8_6_TCPWM0_LINE263             =  8,       /* Digital Active - tcpwm[0].line[263]:0 */
    P8_6_TCPWM0_LINE_COMPL18        =  9,       /* Digital Active - tcpwm[0].line_compl[18]:0 */
    P8_6_PERI_TR_IO_INPUT38         = 21,       /* Digital Active - peri.tr_io_input[38]:0 */
    P8_6_SG0_SG_AMPL2               = 22,       /* Digital Active - sg[0].sg_ampl[2]:3 */
    P8_6_VIDEOSS0_TTL_CAP0_DATA3    = 23,       /* Digital Active - videoss[0].ttl_cap0_data[3]:3 */
    P8_6_SCB5_SPI_SELECT1           = 24,       /* Digital Active - scb[5].spi_select1:0 */
    P8_6_SCB11_SPI_MISO             = 25,       /* Digital Active - scb[11].spi_miso:0 */
    P8_6_SCB11_UART_RTS             = 26,       /* Digital Active - scb[11].uart_rts:0 */

    /* P8.7 */
    P8_7_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_7_AMUXA                      =  4,       /* AMUXBUS A */
    P8_7_AMUXB                      =  5,       /* AMUXBUS B */
    P8_7_TCPWM0_LINE18              =  8,       /* Digital Active - tcpwm[0].line[18]:0 */
    P8_7_TCPWM0_LINE_COMPL263       =  9,       /* Digital Active - tcpwm[0].line_compl[263]:0 */
    P8_7_PERI_TR_IO_INPUT39         = 21,       /* Digital Active - peri.tr_io_input[39]:0 */
    P8_7_SG0_SG_TONE2               = 22,       /* Digital Active - sg[0].sg_tone[2]:3 */
    P8_7_VIDEOSS0_TTL_CAP0_DATA2    = 23,       /* Digital Active - videoss[0].ttl_cap0_data[2]:3 */
    P8_7_SCB9_SPI_SELECT1           = 24,       /* Digital Active - scb[9].spi_select1:0 */
    P8_7_SCB11_SPI_SELECT0          = 25,       /* Digital Active - scb[11].spi_select0:0 */
    P8_7_SCB11_UART_CTS             = 26,       /* Digital Active - scb[11].uart_cts:0 */

    /* P9.0 */
    P9_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_0_AMUXA                      =  4,       /* AMUXBUS A */
    P9_0_AMUXB                      =  5,       /* AMUXBUS B */
    P9_0_TCPWM0_LINE512             =  8,       /* Digital Active - tcpwm[0].line[512]:1 */
    P9_0_TCPWM0_LINE_COMPL523       =  9,       /* Digital Active - tcpwm[0].line_compl[523]:1 */
    P9_0_TCPWM0_TR_ONE_CNT_IN522    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[522]:1 */
    P9_0_SCB1_UART_RX               = 11,       /* Digital Active - scb[1].uart_rx:0 */
    P9_0_TDM0_TDM_RX_MCK2           = 17,       /* Digital Active - tdm[0].tdm_rx_mck[2]:0 */
    P9_0_SCB1_SPI_CLK               = 19,       /* Digital Active - scb[1].spi_clk:0 */
    P9_0_CPUSS_TRACE_CLOCK          = 20,       /* Digital Active - cpuss.trace_clock:0 */
    P9_0_VIDEOSS0_TTL_DSP1_CONTROL11 = 21,      /* Digital Active - videoss[0].ttl_dsp1_control[11]:0 */
    P9_0_SCB1_I2C_SDA               = 22,       /* Digital Active - scb[1].i2c_sda:0 */
    P9_0_VIDEOSS0_TTL_CAP0_DATA9    = 23,       /* Digital Active - videoss[0].ttl_cap0_data[9]:2 */
    P9_0_ETH0_TX_ER                 = 27,       /* Digital Active - eth[0].tx_er */

    /* P9.1 */
    P9_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_1_AMUXA                      =  4,       /* AMUXBUS A */
    P9_1_AMUXB                      =  5,       /* AMUXBUS B */
    P9_1_TCPWM0_LINE513             =  8,       /* Digital Active - tcpwm[0].line[513]:1 */
    P9_1_TCPWM0_LINE_COMPL512       =  9,       /* Digital Active - tcpwm[0].line_compl[512]:1 */
    P9_1_TCPWM0_TR_ONE_CNT_IN523    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[523]:1 */
    P9_1_SCB1_UART_TX               = 11,       /* Digital Active - scb[1].uart_tx:0 */
    P9_1_TDM0_TDM_RX_SCK2           = 17,       /* Digital Active - tdm[0].tdm_rx_sck[2]:0 */
    P9_1_SCB1_SPI_MOSI              = 19,       /* Digital Active - scb[1].spi_mosi:0 */
    P9_1_CPUSS_TRACE_DATA0          = 20,       /* Digital Active - cpuss.trace_data[0]:0 */
    P9_1_VIDEOSS0_TTL_DSP1_CONTROL10 = 21,      /* Digital Active - videoss[0].ttl_dsp1_control[10]:0 */
    P9_1_SCB1_I2C_SCL               = 22,       /* Digital Active - scb[1].i2c_scl:0 */
    P9_1_VIDEOSS0_TTL_CAP0_DATA8    = 23,       /* Digital Active - videoss[0].ttl_cap0_data[8]:2 */
    P9_1_ETH0_RX_ER                 = 27,       /* Digital Active - eth[0].rx_er */

    /* P9.2 */
    P9_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_2_AMUXA                      =  4,       /* AMUXBUS A */
    P9_2_AMUXB                      =  5,       /* AMUXBUS B */
    P9_2_TCPWM0_LINE514             =  8,       /* Digital Active - tcpwm[0].line[514]:1 */
    P9_2_TCPWM0_LINE_COMPL513       =  9,       /* Digital Active - tcpwm[0].line_compl[513]:1 */
    P9_2_TCPWM0_TR_ONE_CNT_IN512    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[512]:1 */
    P9_2_SCB1_UART_RTS              = 11,       /* Digital Active - scb[1].uart_rts:0 */
    P9_2_TDM0_TDM_RX_FSYNC2         = 17,       /* Digital Active - tdm[0].tdm_rx_fsync[2]:0 */
    P9_2_SCB1_SPI_MISO              = 19,       /* Digital Active - scb[1].spi_miso:0 */
    P9_2_CPUSS_TRACE_DATA1          = 20,       /* Digital Active - cpuss.trace_data[1]:0 */
    P9_2_VIDEOSS0_TTL_DSP1_CONTROL9 = 21,       /* Digital Active - videoss[0].ttl_dsp1_control[9]:0 */
    P9_2_VIDEOSS0_TTL_CAP0_DATA7    = 23,       /* Digital Active - videoss[0].ttl_cap0_data[7]:2 */
    P9_2_ETH0_ETH_TSU_TIMER_CMP_VAL = 27,       /* Digital Active - eth[0].eth_tsu_timer_cmp_val */

    /* P9.3 */
    P9_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_3_AMUXA                      =  4,       /* AMUXBUS A */
    P9_3_AMUXB                      =  5,       /* AMUXBUS B */
    P9_3_TCPWM0_LINE515             =  8,       /* Digital Active - tcpwm[0].line[515]:1 */
    P9_3_TCPWM0_LINE_COMPL514       =  9,       /* Digital Active - tcpwm[0].line_compl[514]:1 */
    P9_3_TCPWM0_TR_ONE_CNT_IN513    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[513]:1 */
    P9_3_SCB1_UART_CTS              = 11,       /* Digital Active - scb[1].uart_cts:0 */
    P9_3_TDM0_TDM_RX_SD2            = 17,       /* Digital Active - tdm[0].tdm_rx_sd[2]:0 */
    P9_3_VIDEOSS0_TTL_DSP1_CONTROL8 = 18,       /* Digital Active - videoss[0].ttl_dsp1_control[8]:0 */
    P9_3_SCB1_SPI_SELECT0           = 19,       /* Digital Active - scb[1].spi_select0:0 */
    P9_3_CPUSS_TRACE_DATA2          = 20,       /* Digital Active - cpuss.trace_data[2]:0 */
    P9_3_VIDEOSS0_TTL_CAP0_DATA6    = 23,       /* Digital Active - videoss[0].ttl_cap0_data[6]:2 */
    P9_3_ETH0_MDC                   = 27,       /* Digital Active - eth[0].mdc:0 */

    /* P9.4 */
    P9_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_4_AMUXA                      =  4,       /* AMUXBUS A */
    P9_4_AMUXB                      =  5,       /* AMUXBUS B */
    P9_4_TCPWM0_LINE23              =  8,       /* Digital Active - tcpwm[0].line[23]:0 */
    P9_4_TCPWM0_LINE_COMPL29        =  9,       /* Digital Active - tcpwm[0].line_compl[29]:0 */
    P9_4_TCPWM0_TR_ONE_CNT_IN28     = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[28]:0 */
    P9_4_VIDEOSS0_TTL_DSP1_CONTROL7 = 18,       /* Digital Active - videoss[0].ttl_dsp1_control[7]:0 */
    P9_4_SCB1_SPI_SELECT1           = 19,       /* Digital Active - scb[1].spi_select1:0 */
    P9_4_CPUSS_TRACE_DATA3          = 20,       /* Digital Active - cpuss.trace_data[3]:0 */
    P9_4_VIDEOSS0_TTL_CAP0_DATA5    = 23,       /* Digital Active - videoss[0].ttl_cap0_data[5]:2 */
    P9_4_ETH0_MDIO                  = 27,       /* Digital Active - eth[0].mdio:0 */

    /* P9.5 */
    P9_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_5_AMUXA                      =  4,       /* AMUXBUS A */
    P9_5_AMUXB                      =  5,       /* AMUXBUS B */
    P9_5_TCPWM0_LINE24              =  8,       /* Digital Active - tcpwm[0].line[24]:0 */
    P9_5_TCPWM0_LINE_COMPL30        =  9,       /* Digital Active - tcpwm[0].line_compl[30]:0 */
    P9_5_TCPWM0_TR_ONE_CNT_IN29     = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[29]:0 */
    P9_5_TDM0_TDM_TX_MCK0           = 16,       /* Digital Active - tdm[0].tdm_tx_mck[0]:0 */
    P9_5_TDM0_TDM_RX_MCK1           = 17,       /* Digital Active - tdm[0].tdm_rx_mck[1]:1 */
    P9_5_VIDEOSS0_TTL_DSP1_CONTROL6 = 18,       /* Digital Active - videoss[0].ttl_dsp1_control[6]:0 */
    P9_5_SRSS_EXT_CLK               = 19,       /* Digital Active - srss.ext_clk:2 */
    P9_5_PWM0_PWM_LINE1_P0          = 21,       /* Digital Active - pwm[0].pwm_line1_p[0]:0 */
    P9_5_SG0_SG_TONE0               = 22,       /* Digital Active - sg[0].sg_tone[0]:0 */
    P9_5_VIDEOSS0_TTL_CAP0_DATA4    = 23,       /* Digital Active - videoss[0].ttl_cap0_data[4]:2 */
    P9_5_CPUSS_TRACE_DATA4          = 25,       /* Digital Active - cpuss.trace_data[4]:0 */

    /* P9.6 */
    P9_6_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_6_AMUXA                      =  4,       /* AMUXBUS A */
    P9_6_AMUXB                      =  5,       /* AMUXBUS B */
    P9_6_TCPWM0_LINE25              =  8,       /* Digital Active - tcpwm[0].line[25]:0 */
    P9_6_TCPWM0_LINE_COMPL23        =  9,       /* Digital Active - tcpwm[0].line_compl[23]:0 */
    P9_6_TCPWM0_TR_ONE_CNT_IN30     = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[30]:0 */
    P9_6_VIDEOSS0_TTL_CAP0_DATA23   = 11,       /* Digital Active - videoss[0].ttl_cap0_data[23]:0 */
    P9_6_TDM0_TDM_TX_SCK0           = 16,       /* Digital Active - tdm[0].tdm_tx_sck[0]:0 */
    P9_6_TDM0_TDM_RX_SCK1           = 17,       /* Digital Active - tdm[0].tdm_rx_sck[1]:1 */
    P9_6_VIDEOSS0_TTL_DSP1_DATA_A111 = 18,      /* Digital Active - videoss[0].ttl_dsp1_data_a1[11]:0 */
    P9_6_PWM0_PWM_LINE1_N0          = 21,       /* Digital Active - pwm[0].pwm_line1_n[0]:0 */
    P9_6_SG0_SG_AMPL0               = 22,       /* Digital Active - sg[0].sg_ampl[0]:0 */
    P9_6_VIDEOSS0_TTL_CAP0_DATA3    = 23,       /* Digital Active - videoss[0].ttl_cap0_data[3]:2 */
    P9_6_CPUSS_TRACE_DATA5          = 25,       /* Digital Active - cpuss.trace_data[5]:0 */
    P9_6_VIDEOSS0_TTL_DSP1_CONTROL5 = 27,       /* Digital Active - videoss[0].ttl_dsp1_control[5]:0 */

    /* P9.7 */
    P9_7_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_7_AMUXA                      =  4,       /* AMUXBUS A */
    P9_7_AMUXB                      =  5,       /* AMUXBUS B */
    P9_7_TCPWM0_LINE516             =  8,       /* Digital Active - tcpwm[0].line[516]:1 */
    P9_7_TCPWM0_LINE_COMPL515       =  9,       /* Digital Active - tcpwm[0].line_compl[515]:1 */
    P9_7_TCPWM0_TR_ONE_CNT_IN514    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[514]:1 */
    P9_7_VIDEOSS0_TTL_CAP0_DATA22   = 11,       /* Digital Active - videoss[0].ttl_cap0_data[22]:0 */
    P9_7_TDM0_TDM_TX_FSYNC0         = 16,       /* Digital Active - tdm[0].tdm_tx_fsync[0]:0 */
    P9_7_TDM0_TDM_RX_FSYNC1         = 17,       /* Digital Active - tdm[0].tdm_rx_fsync[1]:1 */
    P9_7_VIDEOSS0_TTL_DSP1_DATA_A011 = 18,      /* Digital Active - videoss[0].ttl_dsp1_data_a0[11]:0 */
    P9_7_PWM0_PWM_LINE2_P0          = 21,       /* Digital Active - pwm[0].pwm_line2_p[0]:0 */
    P9_7_SG0_SG_TONE1               = 22,       /* Digital Active - sg[0].sg_tone[1]:0 */
    P9_7_VIDEOSS0_TTL_CAP0_DATA2    = 23,       /* Digital Active - videoss[0].ttl_cap0_data[2]:2 */
    P9_7_CPUSS_TRACE_DATA6          = 25,       /* Digital Active - cpuss.trace_data[6]:0 */
    P9_7_VIDEOSS0_TTL_DSP1_CONTROL4 = 27,       /* Digital Active - videoss[0].ttl_dsp1_control[4]:0 */

    /* P10.0 */
    P10_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P10_0_AMUXA                     =  4,       /* AMUXBUS A */
    P10_0_AMUXB                     =  5,       /* AMUXBUS B */
    P10_0_TCPWM0_LINE517            =  8,       /* Digital Active - tcpwm[0].line[517]:1 */
    P10_0_TCPWM0_LINE_COMPL516      =  9,       /* Digital Active - tcpwm[0].line_compl[516]:1 */
    P10_0_TCPWM0_TR_ONE_CNT_IN515   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[515]:1 */
    P10_0_VIDEOSS0_TTL_CAP0_DATA21  = 11,       /* Digital Active - videoss[0].ttl_cap0_data[21]:0 */
    P10_0_TDM0_TDM_TX_SD0           = 16,       /* Digital Active - tdm[0].tdm_tx_sd[0]:0 */
    P10_0_TDM0_TDM_RX_SD1           = 17,       /* Digital Active - tdm[0].tdm_rx_sd[1]:1 */
    P10_0_VIDEOSS0_TTL_DSP1_DATA_A110 = 18,     /* Digital Active - videoss[0].ttl_dsp1_data_a1[10]:0 */
    P10_0_PWM0_PWM_LINE2_N0         = 21,       /* Digital Active - pwm[0].pwm_line2_n[0]:0 */
    P10_0_SG0_SG_AMPL1              = 22,       /* Digital Active - sg[0].sg_ampl[1]:0 */
    P10_0_VIDEOSS0_TTL_CAP0_CLK     = 23,       /* Digital Active - videoss[0].ttl_cap0_clk:2 */
    P10_0_CPUSS_TRACE_DATA7         = 25,       /* Digital Active - cpuss.trace_data[7]:0 */
    P10_0_VIDEOSS0_TTL_DSP1_CONTROL3 = 27,      /* Digital Active - videoss[0].ttl_dsp1_control[3]:0 */

    /* P10.1 */
    P10_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P10_1_AMUXA                     =  4,       /* AMUXBUS A */
    P10_1_AMUXB                     =  5,       /* AMUXBUS B */
    P10_1_TCPWM0_LINE518            =  8,       /* Digital Active - tcpwm[0].line[518]:1 */
    P10_1_TCPWM0_LINE_COMPL517      =  9,       /* Digital Active - tcpwm[0].line_compl[517]:1 */
    P10_1_TCPWM0_TR_ONE_CNT_IN516   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[516]:1 */
    P10_1_VIDEOSS0_TTL_CAP0_DATA20  = 11,       /* Digital Active - videoss[0].ttl_cap0_data[20]:0 */
    P10_1_SCB2_I2C_SDA              = 17,       /* Digital Active - scb[2].i2c_sda:0 */
    P10_1_VIDEOSS0_TTL_DSP1_DATA_A010 = 18,     /* Digital Active - videoss[0].ttl_dsp1_data_a0[10]:0 */
    P10_1_SCB2_SPI_CLK              = 19,       /* Digital Active - scb[2].spi_clk:0 */
    P10_1_SCB2_UART_RX              = 22,       /* Digital Active - scb[2].uart_rx:0 */
    P10_1_VIDEOSS0_TTL_CAP0_DATA9   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[9]:1 */
    P10_1_CPUSS_TRACE_DATA4         = 25,       /* Digital Active - cpuss.trace_data[4]:1 */

    /* P10.2 */
    P10_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P10_2_AMUXA                     =  4,       /* AMUXBUS A */
    P10_2_AMUXB                     =  5,       /* AMUXBUS B */
    P10_2_TCPWM0_LINE519            =  8,       /* Digital Active - tcpwm[0].line[519]:1 */
    P10_2_TCPWM0_LINE_COMPL518      =  9,       /* Digital Active - tcpwm[0].line_compl[518]:1 */
    P10_2_TCPWM0_TR_ONE_CNT_IN517   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[517]:1 */
    P10_2_VIDEOSS0_TTL_CAP0_DATA19  = 11,       /* Digital Active - videoss[0].ttl_cap0_data[19]:0 */
    P10_2_SCB2_I2C_SCL              = 17,       /* Digital Active - scb[2].i2c_scl:0 */
    P10_2_VIDEOSS0_TTL_DSP1_DATA_A19 = 18,      /* Digital Active - videoss[0].ttl_dsp1_data_a1[9]:0 */
    P10_2_SCB2_SPI_MOSI             = 19,       /* Digital Active - scb[2].spi_mosi:0 */
    P10_2_PWM0_PWM_MCK0             = 21,       /* Digital Active - pwm[0].pwm_mck[0]:0 */
    P10_2_SCB2_UART_TX              = 22,       /* Digital Active - scb[2].uart_tx:0 */
    P10_2_VIDEOSS0_TTL_CAP0_DATA8   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[8]:1 */
    P10_2_CPUSS_TRACE_DATA5         = 25,       /* Digital Active - cpuss.trace_data[5]:1 */

    /* P10.3 */
    P10_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P10_3_AMUXA                     =  4,       /* AMUXBUS A */
    P10_3_AMUXB                     =  5,       /* AMUXBUS B */
    P10_3_TCPWM0_LINE520            =  8,       /* Digital Active - tcpwm[0].line[520]:1 */
    P10_3_TCPWM0_LINE_COMPL519      =  9,       /* Digital Active - tcpwm[0].line_compl[519]:1 */
    P10_3_TCPWM0_TR_ONE_CNT_IN518   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[518]:1 */
    P10_3_VIDEOSS0_TTL_CAP0_DATA18  = 11,       /* Digital Active - videoss[0].ttl_cap0_data[18]:0 */
    P10_3_VIDEOSS0_TTL_DSP1_DATA_A09 = 18,      /* Digital Active - videoss[0].ttl_dsp1_data_a0[9]:0 */
    P10_3_SCB2_SPI_SELECT1          = 19,       /* Digital Active - scb[2].spi_select1:0 */
    P10_3_PWM0_PWM_MCK1             = 21,       /* Digital Active - pwm[0].pwm_mck[1]:0 */
    P10_3_VIDEOSS0_TTL_CAP0_DATA7   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[7]:1 */
    P10_3_CPUSS_TRACE_DATA6         = 25,       /* Digital Active - cpuss.trace_data[6]:1 */

    /* P10.4 */
    P10_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P10_4_AMUXA                     =  4,       /* AMUXBUS A */
    P10_4_AMUXB                     =  5,       /* AMUXBUS B */
    P10_4_TCPWM0_LINE26             =  8,       /* Digital Active - tcpwm[0].line[26]:0 */
    P10_4_TCPWM0_LINE_COMPL24       =  9,       /* Digital Active - tcpwm[0].line_compl[24]:0 */
    P10_4_TCPWM0_TR_ONE_CNT_IN23    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[23]:0 */
    P10_4_VIDEOSS0_TTL_CAP0_DATA17  = 11,       /* Digital Active - videoss[0].ttl_cap0_data[17]:0 */
    P10_4_VIDEOSS0_TTL_DSP1_DATA_A18 = 18,      /* Digital Active - videoss[0].ttl_dsp1_data_a1[8]:0 */
    P10_4_SCB2_SPI_MISO             = 19,       /* Digital Active - scb[2].spi_miso:0 */
    P10_4_SCB2_UART_RTS             = 22,       /* Digital Active - scb[2].uart_rts:0 */
    P10_4_VIDEOSS0_TTL_CAP0_DATA6   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[6]:1 */
    P10_4_CPUSS_TRACE_DATA7         = 25,       /* Digital Active - cpuss.trace_data[7]:1 */

    /* P10.5 */
    P10_5_GPIO                      =  0,       /* GPIO controls 'out' */
    P10_5_AMUXA                     =  4,       /* AMUXBUS A */
    P10_5_AMUXB                     =  5,       /* AMUXBUS B */
    P10_5_TCPWM0_LINE521            =  8,       /* Digital Active - tcpwm[0].line[521]:1 */
    P10_5_TCPWM0_LINE_COMPL520      =  9,       /* Digital Active - tcpwm[0].line_compl[520]:1 */
    P10_5_TCPWM0_TR_ONE_CNT_IN519   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[519]:1 */
    P10_5_VIDEOSS0_TTL_CAP0_DATA16  = 11,       /* Digital Active - videoss[0].ttl_cap0_data[16]:0 */
    P10_5_VIDEOSS0_TTL_DSP1_DATA_A08 = 18,      /* Digital Active - videoss[0].ttl_dsp1_data_a0[8]:0 */
    P10_5_SCB2_SPI_SELECT0          = 19,       /* Digital Active - scb[2].spi_select0:0 */
    P10_5_CPUSS_TRACE_CLOCK         = 20,       /* Digital Active - cpuss.trace_clock:1 */
    P10_5_SCB2_UART_CTS             = 22,       /* Digital Active - scb[2].uart_cts:0 */
    P10_5_VIDEOSS0_TTL_CAP0_DATA5   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[5]:1 */

    /* P10.6 */
    P10_6_GPIO                      =  0,       /* GPIO controls 'out' */
    P10_6_AMUXA                     =  4,       /* AMUXBUS A */
    P10_6_AMUXB                     =  5,       /* AMUXBUS B */
    P10_6_TCPWM0_LINE522            =  8,       /* Digital Active - tcpwm[0].line[522]:1 */
    P10_6_TCPWM0_LINE_COMPL521      =  9,       /* Digital Active - tcpwm[0].line_compl[521]:1 */
    P10_6_TCPWM0_TR_ONE_CNT_IN520   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[520]:1 */
    P10_6_VIDEOSS0_TTL_CAP0_DATA15  = 11,       /* Digital Active - videoss[0].ttl_cap0_data[15]:0 */
    P10_6_TDM0_TDM_TX_MCK1          = 16,       /* Digital Active - tdm[0].tdm_tx_mck[1]:0 */
    P10_6_TDM0_TDM_RX_MCK0          = 17,       /* Digital Active - tdm[0].tdm_rx_mck[0]:1 */
    P10_6_VIDEOSS0_TTL_DSP1_DATA_A17 = 18,      /* Digital Active - videoss[0].ttl_dsp1_data_a1[7]:0 */
    P10_6_CPUSS_TRACE_DATA0         = 20,       /* Digital Active - cpuss.trace_data[0]:1 */
    P10_6_PWM0_PWM_LINE1_P1         = 21,       /* Digital Active - pwm[0].pwm_line1_p[1]:0 */
    P10_6_SG0_SG_TONE2              = 22,       /* Digital Active - sg[0].sg_tone[2]:0 */
    P10_6_VIDEOSS0_TTL_CAP0_DATA4   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[4]:1 */

    /* P10.7 */
    P10_7_GPIO                      =  0,       /* GPIO controls 'out' */
    P10_7_AMUXA                     =  4,       /* AMUXBUS A */
    P10_7_AMUXB                     =  5,       /* AMUXBUS B */
    P10_7_TCPWM0_LINE523            =  8,       /* Digital Active - tcpwm[0].line[523]:1 */
    P10_7_TCPWM0_LINE_COMPL522      =  9,       /* Digital Active - tcpwm[0].line_compl[522]:1 */
    P10_7_TCPWM0_TR_ONE_CNT_IN521   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[521]:1 */
    P10_7_VIDEOSS0_TTL_CAP0_DATA14  = 11,       /* Digital Active - videoss[0].ttl_cap0_data[14]:0 */
    P10_7_TDM0_TDM_TX_SCK1          = 16,       /* Digital Active - tdm[0].tdm_tx_sck[1]:0 */
    P10_7_TDM0_TDM_RX_SCK0          = 17,       /* Digital Active - tdm[0].tdm_rx_sck[0]:1 */
    P10_7_VIDEOSS0_TTL_DSP1_DATA_A07 = 18,      /* Digital Active - videoss[0].ttl_dsp1_data_a0[7]:0 */
    P10_7_CPUSS_TRACE_DATA1         = 20,       /* Digital Active - cpuss.trace_data[1]:1 */
    P10_7_PWM0_PWM_LINE1_N1         = 21,       /* Digital Active - pwm[0].pwm_line1_n[1]:0 */
    P10_7_SG0_SG_AMPL2              = 22,       /* Digital Active - sg[0].sg_ampl[2]:0 */
    P10_7_VIDEOSS0_TTL_CAP0_DATA3   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[3]:1 */

    /* P11.0 */
    P11_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_0_AMUXA                     =  4,       /* AMUXBUS A */
    P11_0_AMUXB                     =  5,       /* AMUXBUS B */
    P11_0_TCPWM0_LINE27             =  8,       /* Digital Active - tcpwm[0].line[27]:0 */
    P11_0_TCPWM0_LINE_COMPL25       =  9,       /* Digital Active - tcpwm[0].line_compl[25]:0 */
    P11_0_TCPWM0_TR_ONE_CNT_IN24    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[24]:0 */
    P11_0_VIDEOSS0_TTL_CAP0_DATA13  = 11,       /* Digital Active - videoss[0].ttl_cap0_data[13]:0 */
    P11_0_TDM0_TDM_TX_FSYNC1        = 16,       /* Digital Active - tdm[0].tdm_tx_fsync[1]:0 */
    P11_0_TDM0_TDM_RX_FSYNC0        = 17,       /* Digital Active - tdm[0].tdm_rx_fsync[0]:1 */
    P11_0_VIDEOSS0_TTL_DSP1_DATA_A16 = 18,      /* Digital Active - videoss[0].ttl_dsp1_data_a1[6]:0 */
    P11_0_CPUSS_TRACE_DATA2         = 20,       /* Digital Active - cpuss.trace_data[2]:1 */
    P11_0_PWM0_PWM_LINE2_P1         = 21,       /* Digital Active - pwm[0].pwm_line2_p[1]:0 */
    P11_0_SG0_SG_TONE3              = 22,       /* Digital Active - sg[0].sg_tone[3]:0 */
    P11_0_VIDEOSS0_TTL_CAP0_DATA2   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[2]:1 */

    /* P11.1 */
    P11_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_1_AMUXA                     =  4,       /* AMUXBUS A */
    P11_1_AMUXB                     =  5,       /* AMUXBUS B */
    P11_1_TCPWM0_LINE28             =  8,       /* Digital Active - tcpwm[0].line[28]:0 */
    P11_1_TCPWM0_LINE_COMPL26       =  9,       /* Digital Active - tcpwm[0].line_compl[26]:0 */
    P11_1_TCPWM0_TR_ONE_CNT_IN25    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[25]:0 */
    P11_1_VIDEOSS0_TTL_CAP0_DATA12  = 11,       /* Digital Active - videoss[0].ttl_cap0_data[12]:0 */
    P11_1_TDM0_TDM_TX_SD1           = 16,       /* Digital Active - tdm[0].tdm_tx_sd[1]:0 */
    P11_1_TDM0_TDM_RX_SD0           = 17,       /* Digital Active - tdm[0].tdm_rx_sd[0]:1 */
    P11_1_VIDEOSS0_TTL_DSP1_DATA_A06 = 18,      /* Digital Active - videoss[0].ttl_dsp1_data_a0[6]:0 */
    P11_1_CPUSS_TRACE_DATA3         = 20,       /* Digital Active - cpuss.trace_data[3]:1 */
    P11_1_PWM0_PWM_LINE2_N1         = 21,       /* Digital Active - pwm[0].pwm_line2_n[1]:0 */
    P11_1_SG0_SG_AMPL3              = 22,       /* Digital Active - sg[0].sg_ampl[3]:0 */
    P11_1_VIDEOSS0_TTL_CAP0_CLK     = 23,       /* Digital Active - videoss[0].ttl_cap0_clk:1 */

    /* P11.2 */
    P11_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_2_AMUXA                     =  4,       /* AMUXBUS A */
    P11_2_AMUXB                     =  5,       /* AMUXBUS B */
    P11_2_TCPWM0_LINE29             =  8,       /* Digital Active - tcpwm[0].line[29]:0 */
    P11_2_TCPWM0_LINE_COMPL27       =  9,       /* Digital Active - tcpwm[0].line_compl[27]:0 */
    P11_2_TCPWM0_TR_ONE_CNT_IN26    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[26]:0 */
    P11_2_VIDEOSS0_TTL_DSP0_CONTROL0 = 16,      /* Digital Active - videoss[0].ttl_dsp0_control[0]:0 */
    P11_2_TDM0_TDM_RX_MCK3          = 17,       /* Digital Active - tdm[0].tdm_rx_mck[3]:0 */
    P11_2_SCB3_SPI_CLK              = 18,       /* Digital Active - scb[3].spi_clk:0 */
    P11_2_SCB3_UART_RX              = 19,       /* Digital Active - scb[3].uart_rx:0 */
    P11_2_SCB3_I2C_SDA              = 20,       /* Digital Active - scb[3].i2c_sda:0 */
    P11_2_PWM0_PWM_LINE1_P0         = 21,       /* Digital Active - pwm[0].pwm_line1_p[0]:2 */
    P11_2_PERI_TR_IO_INPUT40        = 22,       /* Digital Active - peri.tr_io_input[40]:0 */
    P11_2_VIDEOSS0_TTL_CAP0_DATA11  = 23,       /* Digital Active - videoss[0].ttl_cap0_data[11]:0 */
    P11_2_VIDEOSS0_TTL_DSP1_DATA_A15 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a1[5]:0 */

    /* P11.3 */
    P11_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_3_AMUXA                     =  4,       /* AMUXBUS A */
    P11_3_AMUXB                     =  5,       /* AMUXBUS B */
    P11_3_TCPWM0_LINE30             =  8,       /* Digital Active - tcpwm[0].line[30]:0 */
    P11_3_TCPWM0_LINE_COMPL28       =  9,       /* Digital Active - tcpwm[0].line_compl[28]:0 */
    P11_3_TCPWM0_TR_ONE_CNT_IN27    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[27]:0 */
    P11_3_VIDEOSS0_TTL_DSP0_CONTROL1 = 16,      /* Digital Active - videoss[0].ttl_dsp0_control[1]:0 */
    P11_3_TDM0_TDM_RX_SCK3          = 17,       /* Digital Active - tdm[0].tdm_rx_sck[3]:0 */
    P11_3_SCB3_SPI_MOSI             = 18,       /* Digital Active - scb[3].spi_mosi:0 */
    P11_3_SCB3_UART_TX              = 19,       /* Digital Active - scb[3].uart_tx:0 */
    P11_3_SCB3_I2C_SCL              = 20,       /* Digital Active - scb[3].i2c_scl:0 */
    P11_3_PWM0_PWM_LINE1_N0         = 21,       /* Digital Active - pwm[0].pwm_line1_n[0]:2 */
    P11_3_PERI_TR_IO_INPUT41        = 22,       /* Digital Active - peri.tr_io_input[41]:0 */
    P11_3_VIDEOSS0_TTL_CAP0_DATA10  = 23,       /* Digital Active - videoss[0].ttl_cap0_data[10]:0 */
    P11_3_VIDEOSS0_TTL_DSP1_DATA_A05 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a0[5]:0 */

    /* P11.4 */
    P11_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_4_AMUXA                     =  4,       /* AMUXBUS A */
    P11_4_AMUXB                     =  5,       /* AMUXBUS B */
    P11_4_TCPWM0_LINE31             =  8,       /* Digital Active - tcpwm[0].line[31]:0 */
    P11_4_TCPWM0_LINE_COMPL37       =  9,       /* Digital Active - tcpwm[0].line_compl[37]:0 */
    P11_4_TCPWM0_TR_ONE_CNT_IN36    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[36]:0 */
    P11_4_TDM0_TDM_RX_FSYNC3        = 17,       /* Digital Active - tdm[0].tdm_rx_fsync[3]:0 */
    P11_4_SCB3_SPI_MISO             = 18,       /* Digital Active - scb[3].spi_miso:0 */
    P11_4_SCB3_UART_RTS             = 19,       /* Digital Active - scb[3].uart_rts:0 */
    P11_4_VIDEOSS0_TTL_DSP0_CONTROL2 = 20,      /* Digital Active - videoss[0].ttl_dsp0_control[2]:0 */
    P11_4_PWM0_PWM_LINE2_P0         = 21,       /* Digital Active - pwm[0].pwm_line2_p[0]:2 */
    P11_4_PERI_TR_IO_INPUT42        = 22,       /* Digital Active - peri.tr_io_input[42]:0 */
    P11_4_VIDEOSS0_TTL_CAP0_CLK     = 23,       /* Digital Active - videoss[0].ttl_cap0_clk:0 */
    P11_4_VIDEOSS0_TTL_DSP1_DATA_A14 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a1[4]:0 */

    /* P11.5 */
    P11_5_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_5_AMUXA                     =  4,       /* AMUXBUS A */
    P11_5_AMUXB                     =  5,       /* AMUXBUS B */
    P11_5_TCPWM0_LINE32             =  8,       /* Digital Active - tcpwm[0].line[32]:0 */
    P11_5_TCPWM0_LINE_COMPL31       =  9,       /* Digital Active - tcpwm[0].line_compl[31]:0 */
    P11_5_TCPWM0_TR_ONE_CNT_IN37    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[37]:0 */
    P11_5_TDM0_TDM_RX_SD3           = 17,       /* Digital Active - tdm[0].tdm_rx_sd[3]:0 */
    P11_5_SCB3_SPI_SELECT0          = 18,       /* Digital Active - scb[3].spi_select0:0 */
    P11_5_SCB3_UART_CTS             = 19,       /* Digital Active - scb[3].uart_cts:0 */
    P11_5_VIDEOSS0_TTL_DSP0_CONTROL3 = 20,      /* Digital Active - videoss[0].ttl_dsp0_control[3]:0 */
    P11_5_PWM0_PWM_LINE2_N0         = 21,       /* Digital Active - pwm[0].pwm_line2_n[0]:2 */
    P11_5_PERI_TR_IO_INPUT43        = 22,       /* Digital Active - peri.tr_io_input[43]:0 */
    P11_5_VIDEOSS0_TTL_CAP0_DATA9   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[9]:0 */
    P11_5_VIDEOSS0_TTL_DSP1_DATA_A04 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a0[4]:0 */

    /* P11.6 */
    P11_6_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_6_AMUXA                     =  4,       /* AMUXBUS A */
    P11_6_AMUXB                     =  5,       /* AMUXBUS B */
    P11_6_TCPWM0_LINE33             =  8,       /* Digital Active - tcpwm[0].line[33]:0 */
    P11_6_TCPWM0_LINE_COMPL32       =  9,       /* Digital Active - tcpwm[0].line_compl[32]:0 */
    P11_6_TCPWM0_TR_ONE_CNT_IN31    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[31]:0 */
    P11_6_TDM0_TDM_RX_MCK1          = 17,       /* Digital Active - tdm[0].tdm_rx_mck[1]:2 */
    P11_6_VIDEOSS0_TTL_DSP0_CONTROL4 = 20,      /* Digital Active - videoss[0].ttl_dsp0_control[4]:0 */
    P11_6_PWM0_PWM_LINE1_P1         = 21,       /* Digital Active - pwm[0].pwm_line1_p[1]:2 */
    P11_6_PERI_TR_IO_INPUT44        = 22,       /* Digital Active - peri.tr_io_input[44]:0 */
    P11_6_VIDEOSS0_TTL_CAP0_DATA8   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[8]:0 */
    P11_6_VIDEOSS0_TTL_DSP1_DATA_A13 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a1[3]:0 */
    P11_6_SCB8_SPI_CLK              = 25,       /* Digital Active - scb[8].spi_clk:0 */
    P11_6_SCB8_UART_RX              = 26,       /* Digital Active - scb[8].uart_rx:0 */
    P11_6_SCB8_I2C_SDA              = 27,       /* Digital Active - scb[8].i2c_sda:0 */

    /* P11.7 */
    P11_7_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_7_AMUXA                     =  4,       /* AMUXBUS A */
    P11_7_AMUXB                     =  5,       /* AMUXBUS B */
    P11_7_TCPWM0_LINE34             =  8,       /* Digital Active - tcpwm[0].line[34]:0 */
    P11_7_TCPWM0_LINE_COMPL33       =  9,       /* Digital Active - tcpwm[0].line_compl[33]:0 */
    P11_7_TCPWM0_TR_ONE_CNT_IN32    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[32]:0 */
    P11_7_TDM0_TDM_RX_SCK1          = 17,       /* Digital Active - tdm[0].tdm_rx_sck[1]:2 */
    P11_7_VIDEOSS0_TTL_DSP0_CONTROL5 = 20,      /* Digital Active - videoss[0].ttl_dsp0_control[5]:0 */
    P11_7_PWM0_PWM_LINE1_N1         = 21,       /* Digital Active - pwm[0].pwm_line1_n[1]:2 */
    P11_7_PERI_TR_IO_INPUT45        = 22,       /* Digital Active - peri.tr_io_input[45]:0 */
    P11_7_VIDEOSS0_TTL_CAP0_DATA7   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[7]:0 */
    P11_7_VIDEOSS0_TTL_DSP1_DATA_A03 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a0[3]:0 */
    P11_7_SCB8_SPI_MOSI             = 25,       /* Digital Active - scb[8].spi_mosi:0 */
    P11_7_SCB8_UART_TX              = 26,       /* Digital Active - scb[8].uart_tx:0 */
    P11_7_SCB8_I2C_SCL              = 27,       /* Digital Active - scb[8].i2c_scl:0 */

    /* P12.0 */
    P12_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P12_0_AMUXA                     =  4,       /* AMUXBUS A */
    P12_0_AMUXB                     =  5,       /* AMUXBUS B */
    P12_0_TCPWM0_LINE534            =  8,       /* Digital Active - tcpwm[0].line[534]:0 */
    P12_0_TCPWM0_LINE_COMPL543      =  9,       /* Digital Active - tcpwm[0].line_compl[543]:0 */
    P12_0_TCPWM0_TR_ONE_CNT_IN542   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[542]:0 */
    P12_0_TDM0_TDM_RX_FSYNC1        = 17,       /* Digital Active - tdm[0].tdm_rx_fsync[1]:2 */
    P12_0_VIDEOSS0_TTL_DSP0_CONTROL6 = 20,      /* Digital Active - videoss[0].ttl_dsp0_control[6]:0 */
    P12_0_PWM0_PWM_LINE2_P1         = 21,       /* Digital Active - pwm[0].pwm_line2_p[1]:2 */
    P12_0_PERI_TR_IO_INPUT46        = 22,       /* Digital Active - peri.tr_io_input[46]:0 */
    P12_0_VIDEOSS0_TTL_CAP0_DATA6   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[6]:0 */
    P12_0_VIDEOSS0_TTL_DSP1_DATA_A12 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a1[2]:0 */
    P12_0_SCB8_SPI_MISO             = 25,       /* Digital Active - scb[8].spi_miso:0 */
    P12_0_SCB8_UART_RTS             = 26,       /* Digital Active - scb[8].uart_rts:0 */

    /* P12.1 */
    P12_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P12_1_AMUXA                     =  4,       /* AMUXBUS A */
    P12_1_AMUXB                     =  5,       /* AMUXBUS B */
    P12_1_TCPWM0_LINE535            =  8,       /* Digital Active - tcpwm[0].line[535]:0 */
    P12_1_TCPWM0_LINE_COMPL534      =  9,       /* Digital Active - tcpwm[0].line_compl[534]:0 */
    P12_1_TCPWM0_TR_ONE_CNT_IN543   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[543]:0 */
    P12_1_TDM0_TDM_RX_SD1           = 17,       /* Digital Active - tdm[0].tdm_rx_sd[1]:2 */
    P12_1_VIDEOSS0_TTL_DSP0_CONTROL7 = 20,      /* Digital Active - videoss[0].ttl_dsp0_control[7]:0 */
    P12_1_PWM0_PWM_LINE2_N1         = 21,       /* Digital Active - pwm[0].pwm_line2_n[1]:2 */
    P12_1_PERI_TR_IO_INPUT47        = 22,       /* Digital Active - peri.tr_io_input[47]:0 */
    P12_1_VIDEOSS0_TTL_CAP0_DATA5   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[5]:0 */
    P12_1_VIDEOSS0_TTL_DSP1_DATA_A02 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a0[2]:0 */
    P12_1_SCB8_SPI_SELECT0          = 25,       /* Digital Active - scb[8].spi_select0:0 */
    P12_1_SCB8_UART_CTS             = 26,       /* Digital Active - scb[8].uart_cts:0 */

    /* P12.2 */
    P12_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P12_2_AMUXA                     =  4,       /* AMUXBUS A */
    P12_2_AMUXB                     =  5,       /* AMUXBUS B */
    P12_2_TCPWM0_LINE536            =  8,       /* Digital Active - tcpwm[0].line[536]:0 */
    P12_2_TCPWM0_LINE_COMPL535      =  9,       /* Digital Active - tcpwm[0].line_compl[535]:0 */
    P12_2_TCPWM0_TR_ONE_CNT_IN534   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[534]:0 */
    P12_2_TDM0_TDM_TX_MCK2          = 16,       /* Digital Active - tdm[0].tdm_tx_mck[2]:0 */
    P12_2_TDM0_TDM_RX_MCK0          = 17,       /* Digital Active - tdm[0].tdm_rx_mck[0]:0 */
    P12_2_SCB3_SPI_SELECT1          = 18,       /* Digital Active - scb[3].spi_select1:0 */
    P12_2_VIDEOSS0_TTL_DSP0_CONTROL8 = 20,      /* Digital Active - videoss[0].ttl_dsp0_control[8]:0 */
    P12_2_PWM0_PWM_LINE1_P0         = 21,       /* Digital Active - pwm[0].pwm_line1_p[0]:1 */
    P12_2_SG0_SG_TONE0              = 22,       /* Digital Active - sg[0].sg_tone[0]:1 */
    P12_2_VIDEOSS0_TTL_CAP0_DATA4   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[4]:0 */
    P12_2_VIDEOSS0_TTL_DSP1_DATA_A11 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a1[1]:0 */

    /* P12.3 */
    P12_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P12_3_AMUXA                     =  4,       /* AMUXBUS A */
    P12_3_AMUXB                     =  5,       /* AMUXBUS B */
    P12_3_TCPWM0_LINE537            =  8,       /* Digital Active - tcpwm[0].line[537]:0 */
    P12_3_TCPWM0_LINE_COMPL536      =  9,       /* Digital Active - tcpwm[0].line_compl[536]:0 */
    P12_3_TCPWM0_TR_ONE_CNT_IN535   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[535]:0 */
    P12_3_TDM0_TDM_TX_SCK2          = 16,       /* Digital Active - tdm[0].tdm_tx_sck[2]:0 */
    P12_3_TDM0_TDM_RX_SCK0          = 17,       /* Digital Active - tdm[0].tdm_rx_sck[0]:0 */
    P12_3_VIDEOSS0_TTL_DSP0_CONTROL9 = 20,      /* Digital Active - videoss[0].ttl_dsp0_control[9]:0 */
    P12_3_PWM0_PWM_LINE1_N0         = 21,       /* Digital Active - pwm[0].pwm_line1_n[0]:1 */
    P12_3_SG0_SG_AMPL0              = 22,       /* Digital Active - sg[0].sg_ampl[0]:1 */
    P12_3_VIDEOSS0_TTL_CAP0_DATA3   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[3]:0 */
    P12_3_VIDEOSS0_TTL_DSP1_DATA_A01 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a0[1]:0 */
    P12_3_SCB8_SPI_SELECT1          = 25,       /* Digital Active - scb[8].spi_select1:0 */

    /* P12.4 */
    P12_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P12_4_AMUXA                     =  4,       /* AMUXBUS A */
    P12_4_AMUXB                     =  5,       /* AMUXBUS B */
    P12_4_TCPWM0_LINE538            =  8,       /* Digital Active - tcpwm[0].line[538]:0 */
    P12_4_TCPWM0_LINE_COMPL537      =  9,       /* Digital Active - tcpwm[0].line_compl[537]:0 */
    P12_4_TCPWM0_TR_ONE_CNT_IN536   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[536]:0 */
    P12_4_TDM0_TDM_TX_FSYNC2        = 16,       /* Digital Active - tdm[0].tdm_tx_fsync[2]:0 */
    P12_4_TDM0_TDM_RX_FSYNC0        = 17,       /* Digital Active - tdm[0].tdm_rx_fsync[0]:0 */
    P12_4_VIDEOSS0_TTL_DSP0_CONTROL10 = 20,     /* Digital Active - videoss[0].ttl_dsp0_control[10]:0 */
    P12_4_PWM0_PWM_LINE2_P0         = 21,       /* Digital Active - pwm[0].pwm_line2_p[0]:1 */
    P12_4_SG0_SG_TONE1              = 22,       /* Digital Active - sg[0].sg_tone[1]:1 */
    P12_4_VIDEOSS0_TTL_CAP0_DATA2   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[2]:0 */
    P12_4_VIDEOSS0_TTL_DSP1_DATA_A10 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a1[0]:0 */

    /* P12.5 */
    P12_5_GPIO                      =  0,       /* GPIO controls 'out' */
    P12_5_AMUXA                     =  4,       /* AMUXBUS A */
    P12_5_AMUXB                     =  5,       /* AMUXBUS B */
    P12_5_TCPWM0_LINE539            =  8,       /* Digital Active - tcpwm[0].line[539]:0 */
    P12_5_TCPWM0_LINE_COMPL538      =  9,       /* Digital Active - tcpwm[0].line_compl[538]:0 */
    P12_5_TCPWM0_TR_ONE_CNT_IN537   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[537]:0 */
    P12_5_TDM0_TDM_TX_SD2           = 16,       /* Digital Active - tdm[0].tdm_tx_sd[2]:0 */
    P12_5_TDM0_TDM_RX_SD0           = 17,       /* Digital Active - tdm[0].tdm_rx_sd[0]:0 */
    P12_5_SCB4_SPI_SELECT1          = 18,       /* Digital Active - scb[4].spi_select1:0 */
    P12_5_SRSS_EXT_CLK              = 19,       /* Digital Active - srss.ext_clk:1 */
    P12_5_VIDEOSS0_TTL_DSP0_CONTROL11 = 20,     /* Digital Active - videoss[0].ttl_dsp0_control[11]:0 */
    P12_5_PWM0_PWM_LINE2_N0         = 21,       /* Digital Active - pwm[0].pwm_line2_n[0]:1 */
    P12_5_SG0_SG_AMPL1              = 22,       /* Digital Active - sg[0].sg_ampl[1]:1 */
    P12_5_VIDEOSS0_TTL_CAP0_DATA1   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[1]:0 */
    P12_5_VIDEOSS0_TTL_DSP1_DATA_A00 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a0[0]:0 */

    /* P12.6 */
    P12_6_GPIO                      =  0,       /* GPIO controls 'out' */
    P12_6_AMUXA                     =  4,       /* AMUXBUS A */
    P12_6_AMUXB                     =  5,       /* AMUXBUS B */
    P12_6_TCPWM0_LINE540            =  8,       /* Digital Active - tcpwm[0].line[540]:0 */
    P12_6_TCPWM0_LINE_COMPL539      =  9,       /* Digital Active - tcpwm[0].line_compl[539]:0 */
    P12_6_TCPWM0_TR_ONE_CNT_IN538   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[538]:0 */
    P12_6_TDM0_TDM_TX_MCK3          = 16,       /* Digital Active - tdm[0].tdm_tx_mck[3]:0 */
    P12_6_TDM0_TDM_RX_MCK1          = 17,       /* Digital Active - tdm[0].tdm_rx_mck[1]:0 */
    P12_6_SCB4_SPI_CLK              = 18,       /* Digital Active - scb[4].spi_clk:0 */
    P12_6_SCB4_UART_RX              = 19,       /* Digital Active - scb[4].uart_rx:0 */
    P12_6_SCB4_I2C_SDA              = 20,       /* Digital Active - scb[4].i2c_sda:0 */
    P12_6_PWM0_PWM_LINE1_P1         = 21,       /* Digital Active - pwm[0].pwm_line1_p[1]:1 */
    P12_6_SG0_SG_TONE2              = 22,       /* Digital Active - sg[0].sg_tone[2]:1 */
    P12_6_VIDEOSS0_TTL_CAP0_DATA0   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[0]:0 */
    P12_6_VIDEOSS0_TTL_DSP1_CLOCK   = 24,       /* Digital Active - videoss[0].ttl_dsp1_clock:0 */

    /* P12.7 */
    P12_7_GPIO                      =  0,       /* GPIO controls 'out' */
    P12_7_AMUXA                     =  4,       /* AMUXBUS A */
    P12_7_AMUXB                     =  5,       /* AMUXBUS B */
    P12_7_TCPWM0_LINE541            =  8,       /* Digital Active - tcpwm[0].line[541]:0 */
    P12_7_TCPWM0_LINE_COMPL540      =  9,       /* Digital Active - tcpwm[0].line_compl[540]:0 */
    P12_7_TCPWM0_TR_ONE_CNT_IN539   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[539]:0 */
    P12_7_TDM0_TDM_TX_SCK3          = 16,       /* Digital Active - tdm[0].tdm_tx_sck[3]:0 */
    P12_7_TDM0_TDM_RX_SCK1          = 17,       /* Digital Active - tdm[0].tdm_rx_sck[1]:0 */
    P12_7_SCB4_SPI_MOSI             = 18,       /* Digital Active - scb[4].spi_mosi:0 */
    P12_7_SCB4_UART_TX              = 19,       /* Digital Active - scb[4].uart_tx:0 */
    P12_7_SCB4_I2C_SCL              = 20,       /* Digital Active - scb[4].i2c_scl:0 */
    P12_7_PWM0_PWM_LINE1_N1         = 21,       /* Digital Active - pwm[0].pwm_line1_n[1]:1 */
    P12_7_SG0_SG_AMPL2              = 22,       /* Digital Active - sg[0].sg_ampl[2]:1 */
    P12_7_VIDEOSS0_TTL_CAP0_DATA24  = 23,       /* Digital Active - videoss[0].ttl_cap0_data[24]:0 */
    P12_7_VIDEOSS0_TTL_DSP1_CONTROL0 = 24,      /* Digital Active - videoss[0].ttl_dsp1_control[0]:0 */

    /* P13.0 */
    P13_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P13_0_AMUXA                     =  4,       /* AMUXBUS A */
    P13_0_AMUXB                     =  5,       /* AMUXBUS B */
    P13_0_TCPWM0_LINE542            =  8,       /* Digital Active - tcpwm[0].line[542]:0 */
    P13_0_TCPWM0_LINE_COMPL541      =  9,       /* Digital Active - tcpwm[0].line_compl[541]:0 */
    P13_0_TCPWM0_TR_ONE_CNT_IN540   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[540]:0 */
    P13_0_TDM0_TDM_TX_FSYNC3        = 16,       /* Digital Active - tdm[0].tdm_tx_fsync[3]:0 */
    P13_0_TDM0_TDM_RX_FSYNC1        = 17,       /* Digital Active - tdm[0].tdm_rx_fsync[1]:0 */
    P13_0_SCB4_SPI_MISO             = 18,       /* Digital Active - scb[4].spi_miso:0 */
    P13_0_SCB4_UART_RTS             = 19,       /* Digital Active - scb[4].uart_rts:0 */
    P13_0_SRSS_DDFT_CLK_DIRECT      = 20,       /* Digital Active - srss.ddft_clk_direct */
    P13_0_PWM0_PWM_LINE2_P1         = 21,       /* Digital Active - pwm[0].pwm_line2_p[1]:1 */
    P13_0_SG0_SG_TONE3              = 22,       /* Digital Active - sg[0].sg_tone[3]:1 */
    P13_0_VIDEOSS0_TTL_CAP0_DATA25  = 23,       /* Digital Active - videoss[0].ttl_cap0_data[25]:0 */
    P13_0_VIDEOSS0_TTL_DSP1_CONTROL1 = 24,      /* Digital Active - videoss[0].ttl_dsp1_control[1]:0 */

    /* P13.1 */
    P13_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P13_1_AMUXA                     =  4,       /* AMUXBUS A */
    P13_1_AMUXB                     =  5,       /* AMUXBUS B */
    P13_1_TCPWM0_LINE543            =  8,       /* Digital Active - tcpwm[0].line[543]:0 */
    P13_1_TCPWM0_LINE_COMPL542      =  9,       /* Digital Active - tcpwm[0].line_compl[542]:0 */
    P13_1_TCPWM0_TR_ONE_CNT_IN541   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[541]:0 */
    P13_1_TDM0_TDM_TX_SD3           = 16,       /* Digital Active - tdm[0].tdm_tx_sd[3]:0 */
    P13_1_TDM0_TDM_RX_SD1           = 17,       /* Digital Active - tdm[0].tdm_rx_sd[1]:0 */
    P13_1_SCB4_SPI_SELECT0          = 18,       /* Digital Active - scb[4].spi_select0:0 */
    P13_1_SCB4_UART_CTS             = 19,       /* Digital Active - scb[4].uart_cts:0 */
    P13_1_SRSS_IO_CLK_HF5           = 20,       /* Digital Active - srss.io_clk_hf[5]:0 */
    P13_1_PWM0_PWM_LINE2_N1         = 21,       /* Digital Active - pwm[0].pwm_line2_n[1]:1 */
    P13_1_SG0_SG_AMPL3              = 22,       /* Digital Active - sg[0].sg_ampl[3]:1 */
    P13_1_VIDEOSS0_TTL_CAP0_DATA26  = 23,       /* Digital Active - videoss[0].ttl_cap0_data[26]:0 */
    P13_1_VIDEOSS0_TTL_DSP1_CONTROL2 = 24,      /* Digital Active - videoss[0].ttl_dsp1_control[2]:0 */
    P13_1_VIDEOSS0_TTL_DSP0_CLOCK   = 25,       /* Digital Active - videoss[0].ttl_dsp0_clock:0 */
    P13_1_VIDEOSS0_FPDLINK_CLKREF_GPIO = 26,    /* Digital Active - videoss[0].fpdlink_clkref_gpio */

    /* P14.0 */
    P14_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P14_0_AMUXA                     =  4,       /* AMUXBUS A */
    P14_0_AMUXB                     =  5,       /* AMUXBUS B */
    P14_0_SDHC0_CARD_DAT_3TO01      = 11,       /* Digital Active - sdhc[0].card_dat_3to0[1]:0 */
    P14_0_SMIF0_SMIF0_SPIHB_DATA4   = 27,       /* Digital Active - smif[0].smif0_spihb_data4 */

    /* P14.1 */
    P14_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P14_1_AMUXA                     =  4,       /* AMUXBUS A */
    P14_1_AMUXB                     =  5,       /* AMUXBUS B */
    P14_1_SDHC0_CARD_DAT_3TO02      = 11,       /* Digital Active - sdhc[0].card_dat_3to0[2]:0 */
    P14_1_SMIF0_SMIF0_SPIHB_DATA2   = 27,       /* Digital Active - smif[0].smif0_spihb_data2 */

    /* P14.2 */
    P14_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P14_2_AMUXA                     =  4,       /* AMUXBUS A */
    P14_2_AMUXB                     =  5,       /* AMUXBUS B */
    P14_2_SDHC0_CARD_DAT_3TO03      = 11,       /* Digital Active - sdhc[0].card_dat_3to0[3]:0 */
    P14_2_SMIF0_SMIF0_SPIHB_DATA3   = 27,       /* Digital Active - smif[0].smif0_spihb_data3 */

    /* P14.3 */
    P14_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P14_3_AMUXA                     =  4,       /* AMUXBUS A */
    P14_3_AMUXB                     =  5,       /* AMUXBUS B */
    P14_3_SDHC0_CARD_DAT_7TO40      = 11,       /* Digital Active - sdhc[0].card_dat_7to4[0]:0 */
    P14_3_SMIF0_SMIF0_SPIHB_DATA5   = 27,       /* Digital Active - smif[0].smif0_spihb_data5 */

    /* P14.4 */
    P14_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P14_4_AMUXA                     =  4,       /* AMUXBUS A */
    P14_4_AMUXB                     =  5,       /* AMUXBUS B */
    P14_4_SDHC0_CARD_DAT_7TO41      = 11,       /* Digital Active - sdhc[0].card_dat_7to4[1]:0 */
    P14_4_SMIF0_SMIF0_SPIHB_RWDS    = 27,       /* Digital Active - smif[0].smif0_spihb_rwds */

    /* P15.0 */
    P15_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P15_0_AMUXA                     =  4,       /* AMUXBUS A */
    P15_0_AMUXB                     =  5,       /* AMUXBUS B */
    P15_0_SDHC0_CARD_DETECT_N       = 11,       /* Digital Active - sdhc[0].card_detect_n:0 */
    P15_0_SMIF0_SMIF0_SPIHB_CLK     = 27,       /* Digital Active - smif[0].smif0_spihb_clk:0 */

    /* P15.1 */
    P15_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P15_1_AMUXA                     =  4,       /* AMUXBUS A */
    P15_1_AMUXB                     =  5,       /* AMUXBUS B */
    P15_1_SDHC0_CARD_MECH_WRITE_PROT = 11,      /* Digital Active - sdhc[0].card_mech_write_prot:0 */
    P15_1_SMIF0_SMIF0_SPIHB_CLK     = 27,       /* Digital Active - smif[0].smif0_spihb_clk:1 */

    /* P16.0 */
    P16_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P16_0_AMUXA                     =  4,       /* AMUXBUS A */
    P16_0_AMUXB                     =  5,       /* AMUXBUS B */
    P16_0_SDHC0_CARD_DAT_7TO42      = 11,       /* Digital Active - sdhc[0].card_dat_7to4[2]:0 */
    P16_0_SMIF0_SMIF0_SPIHB_DATA0   = 27,       /* Digital Active - smif[0].smif0_spihb_data0 */

    /* P16.1 */
    P16_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P16_1_AMUXA                     =  4,       /* AMUXBUS A */
    P16_1_AMUXB                     =  5,       /* AMUXBUS B */
    P16_1_SDHC0_CARD_DAT_7TO43      = 11,       /* Digital Active - sdhc[0].card_dat_7to4[3]:0 */
    P16_1_SMIF0_SMIF0_SPIHB_DATA6   = 27,       /* Digital Active - smif[0].smif0_spihb_data6 */

    /* P16.2 */
    P16_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P16_2_AMUXA                     =  4,       /* AMUXBUS A */
    P16_2_AMUXB                     =  5,       /* AMUXBUS B */
    P16_2_SDHC0_CARD_CMD            = 11,       /* Digital Active - sdhc[0].card_cmd:0 */
    P16_2_SMIF0_SMIF0_SPIHB_SELECT0 = 27,       /* Digital Active - smif[0].smif0_spihb_select0 */

    /* P16.3 */
    P16_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P16_3_AMUXA                     =  4,       /* AMUXBUS A */
    P16_3_AMUXB                     =  5,       /* AMUXBUS B */
    P16_3_SDHC0_CARD_IF_PWR_EN      = 11,       /* Digital Active - sdhc[0].card_if_pwr_en:0 */
    P16_3_SMIF0_SMIF0_SPIHB_DATA1   = 27,       /* Digital Active - smif[0].smif0_spihb_data1 */

    /* P16.4 */
    P16_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P16_4_AMUXA                     =  4,       /* AMUXBUS A */
    P16_4_AMUXB                     =  5,       /* AMUXBUS B */
    P16_4_SDHC0_CLK_CARD            = 11,       /* Digital Active - sdhc[0].clk_card:0 */
    P16_4_SMIF0_SMIF0_SPIHB_DATA7   = 27,       /* Digital Active - smif[0].smif0_spihb_data7 */

    /* P16.5 */
    P16_5_GPIO                      =  0,       /* GPIO controls 'out' */
    P16_5_AMUXA                     =  4,       /* AMUXBUS A */
    P16_5_AMUXB                     =  5,       /* AMUXBUS B */
    P16_5_SDHC0_CARD_DAT_3TO00      = 11,       /* Digital Active - sdhc[0].card_dat_3to0[0]:0 */
    P16_5_SMIF0_SMIF0_SPIHB_SELECT1 = 27,       /* Digital Active - smif[0].smif0_spihb_select1 */

    /* P17.0 */
    P17_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P17_0_AMUXA                     =  4,       /* AMUXBUS A */
    P17_0_AMUXB                     =  5,       /* AMUXBUS B */
    P17_0_ETH0_TXD0                 = 24,       /* Digital Active - eth[0].txd[0] */
    P17_0_SMIF0_SMIF1_SPIHB_DATA4   = 27,       /* Digital Active - smif[0].smif1_spihb_data4 */

    /* P17.1 */
    P17_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P17_1_AMUXA                     =  4,       /* AMUXBUS A */
    P17_1_AMUXB                     =  5,       /* AMUXBUS B */
    P17_1_ETH0_TXD1                 = 24,       /* Digital Active - eth[0].txd[1] */
    P17_1_SMIF0_SMIF1_SPIHB_DATA2   = 27,       /* Digital Active - smif[0].smif1_spihb_data2 */

    /* P17.2 */
    P17_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P17_2_AMUXA                     =  4,       /* AMUXBUS A */
    P17_2_AMUXB                     =  5,       /* AMUXBUS B */
    P17_2_ETH0_TX_CLK               = 24,       /* Digital Active - eth[0].tx_clk */
    P17_2_SMIF0_SMIF1_SPIHB_DATA3   = 27,       /* Digital Active - smif[0].smif1_spihb_data3 */

    /* P17.3 */
    P17_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P17_3_AMUXA                     =  4,       /* AMUXBUS A */
    P17_3_AMUXB                     =  5,       /* AMUXBUS B */
    P17_3_ETH0_TXD2                 = 24,       /* Digital Active - eth[0].txd[2] */
    P17_3_SMIF0_SMIF1_SPIHB_DATA5   = 27,       /* Digital Active - smif[0].smif1_spihb_data5 */

    /* P17.4 */
    P17_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P17_4_AMUXA                     =  4,       /* AMUXBUS A */
    P17_4_AMUXB                     =  5,       /* AMUXBUS B */
    P17_4_ETH0_TXD3                 = 24,       /* Digital Active - eth[0].txd[3] */
    P17_4_SMIF0_SMIF1_SPIHB_RWDS    = 27,       /* Digital Active - smif[0].smif1_spihb_rwds */

    /* P18.0 */
    P18_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P18_0_AMUXA                     =  4,       /* AMUXBUS A */
    P18_0_AMUXB                     =  5,       /* AMUXBUS B */
    P18_0_ETH0_RXD3                 = 24,       /* Digital Active - eth[0].rxd[3] */
    P18_0_SMIF0_SMIF1_SPIHB_CLK     = 27,       /* Digital Active - smif[0].smif1_spihb_clk:0 */

    /* P18.1 */
    P18_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P18_1_AMUXA                     =  4,       /* AMUXBUS A */
    P18_1_AMUXB                     =  5,       /* AMUXBUS B */
    P18_1_ETH0_RX_CTL               = 24,       /* Digital Active - eth[0].rx_ctl */
    P18_1_SMIF0_SMIF1_SPIHB_CLK     = 27,       /* Digital Active - smif[0].smif1_spihb_clk:1 */

    /* P19.0 */
    P19_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P19_0_AMUXA                     =  4,       /* AMUXBUS A */
    P19_0_AMUXB                     =  5,       /* AMUXBUS B */
    P19_0_ETH0_TX_CTL               = 24,       /* Digital Active - eth[0].tx_ctl */
    P19_0_SMIF0_SMIF1_SPIHB_DATA0   = 27,       /* Digital Active - smif[0].smif1_spihb_data0 */

    /* P19.1 */
    P19_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P19_1_AMUXA                     =  4,       /* AMUXBUS A */
    P19_1_AMUXB                     =  5,       /* AMUXBUS B */
    P19_1_ETH0_REF_CLK              = 24,       /* Digital Active - eth[0].ref_clk */
    P19_1_SMIF0_SMIF1_SPIHB_DATA6   = 27,       /* Digital Active - smif[0].smif1_spihb_data6 */

    /* P19.2 */
    P19_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P19_2_AMUXA                     =  4,       /* AMUXBUS A */
    P19_2_AMUXB                     =  5,       /* AMUXBUS B */
    P19_2_ETH0_RXD0                 = 24,       /* Digital Active - eth[0].rxd[0] */
    P19_2_SMIF0_SMIF1_SPIHB_SELECT0 = 27,       /* Digital Active - smif[0].smif1_spihb_select0 */

    /* P19.3 */
    P19_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P19_3_AMUXA                     =  4,       /* AMUXBUS A */
    P19_3_AMUXB                     =  5,       /* AMUXBUS B */
    P19_3_ETH0_RXD1                 = 24,       /* Digital Active - eth[0].rxd[1] */
    P19_3_SMIF0_SMIF1_SPIHB_DATA1   = 27,       /* Digital Active - smif[0].smif1_spihb_data1 */

    /* P19.4 */
    P19_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P19_4_AMUXA                     =  4,       /* AMUXBUS A */
    P19_4_AMUXB                     =  5,       /* AMUXBUS B */
    P19_4_ETH0_RX_CLK               = 24,       /* Digital Active - eth[0].rx_clk */
    P19_4_SMIF0_SMIF1_SPIHB_DATA7   = 27,       /* Digital Active - smif[0].smif1_spihb_data7 */

    /* P19.5 */
    P19_5_GPIO                      =  0,       /* GPIO controls 'out' */
    P19_5_AMUXA                     =  4,       /* AMUXBUS A */
    P19_5_AMUXB                     =  5,       /* AMUXBUS B */
    P19_5_ETH0_RXD2                 = 24,       /* Digital Active - eth[0].rxd[2] */
    P19_5_SMIF0_SMIF1_SPIHB_SELECT1 = 27        /* Digital Active - smif[0].smif1_spihb_select1 */
} en_hsiom_sel_t;

#endif /* _GPIO_CYT4EN_500_BGA_H_ */


/* [] END OF FILE */
