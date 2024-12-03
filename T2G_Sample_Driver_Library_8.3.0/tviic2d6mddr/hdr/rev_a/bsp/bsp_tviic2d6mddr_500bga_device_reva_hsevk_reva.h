
/***************************************************************************//**
* \file :
* bsp_tviic2d6mddr_500bga_device_reva0_hsevk_reva.h
* 
* \brief
* Project specific header
* 
* \note
* !!! Auto generated file and should not be modified !!!
* Generator revision: 1.9.4
* 
********************************************************************************
* \copyright
* Copyright 2016-2021, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef BSP_TVIIC2D6MDDR_500BGA_DEVICE_REVA_HSEVK_REVA_H
#define BSP_TVIIC2D6MDDR_500BGA_DEVICE_REVA_HSEVK_REVA_H

#ifdef __cplusplus
extern C {
#endif

/******************************************************************************/
/******************************************************************************/


#if (defined(CYT4ENDBAS) || defined(CYT4ENDBCS) || defined(CYT4ENDBES) || defined(CYT4ENDBGS) || \
     defined(CYT4ENDBJS) || defined(CYT4ENDBLS) || defined(CYT4ENDBNS) || defined(CYT4ENDBQS) || \
	 defined(CYT4ENDBSS) || defined(CYT4ENDBTS) || defined(CYT4ENDBUS) || defined(CYT4ENDBVS) || \
	 defined(CYT4ENDBWS) || defined(CYT4ENDBXS) || defined(CYT4ENDBYS) || defined(CYT4ENDBZS) && (CY_USE_PSVP == 0))

#define CY_LIN0_CH1_AVAILABLE
#define CY_CANFD0_CH1_AVAILABLE
#define CY_CANFD1_CH0_AVAILABLE
#define CY_SMIF0_AVAILABLE
#define CY_ETH0_AVAILABLE

/******************************************************************************/
/* GPIO                                                                       */
/******************************************************************************/


/**** LED ****/
#define CY_USER_LED1_PORT   			GPIO_PRT7
#define CY_USER_LED1_PIN    			0
#define CY_USER_LED1_PIN_MUX			P7_0_GPIO
#define CY_USER_LED1_IRQN   			ioss_interrupts_gpio_dpslp_7_IRQn

#define CY_USER_LED2_PORT   			GPIO_PRT7
#define CY_USER_LED2_PIN    			1
#define CY_USER_LED2_PIN_MUX			P7_1_GPIO
#define CY_USER_LED2_IRQN   			ioss_interrupts_gpio_dpslp_7_IRQn

#define CY_USER_LED3_PORT   			GPIO_PRT7
#define CY_USER_LED3_PIN    			2
#define CY_USER_LED3_PIN_MUX			P7_2_GPIO
#define CY_USER_LED3_IRQN   			ioss_interrupts_gpio_dpslp_7_IRQn


/**** BUTTON ****/
#define CY_USER_BUTTON_WAKE_PORT   		GPIO_PRT6                   // SW5
#define CY_USER_BUTTON_WAKE_PIN    		2
#define CY_USER_BUTTON_WAKE_PIN_MUX		P6_2_GPIO
#define CY_USER_BUTTON_WAKE_IRQN   		ioss_interrupts_gpio_dpslp_6_IRQn

#define CY_USER_BUTTON_LEFT_PORT   		GPIO_PRT8                   // SW3
#define CY_USER_BUTTON_LEFT_PIN    		0
#define CY_USER_BUTTON_LEFT_PIN_MUX		P8_0_GPIO
#define CY_USER_BUTTON_LEFT_IRQN   		ioss_interrupts_gpio_dpslp_8_IRQn

#define CY_USER_BUTTON_RIGHT_PORT   		GPIO_PRT8                   //SW6
#define CY_USER_BUTTON_RIGHT_PIN    		1
#define CY_USER_BUTTON_RIGHT_PIN_MUX		P8_1_GPIO
#define CY_USER_BUTTON_RIGHT_IRQN   		ioss_interrupts_gpio_dpslp_8_IRQn

#define CY_USER_BUTTON_UP_PORT   		GPIO_PRT8                   //SW7
#define CY_USER_BUTTON_UP_PIN    		2
#define CY_USER_BUTTON_UP_PIN_MUX		P8_2_GPIO
#define CY_USER_BUTTON_UP_IRQN   		ioss_interrupts_gpio_dpslp_8_IRQn


/**** MISC_GPIO ****/
#define CY_CAN0_SLP_PORT   			GPIO_PRT4
#define CY_CAN0_SLP_PIN    			3
#define CY_CAN0_SLP_PIN_MUX			P4_3_GPIO

#define CY_LIN0_WAKE_PORT   			GPIO_PRT2
#define CY_LIN0_WAKE_PIN    			1
#define CY_LIN0_WAKE_PIN_MUX			P2_1_GPIO
#define CY_LIN0_WAKE_IRQN   			ioss_interrupts_gpio_dpslp_2_IRQn

#define CY_MIPI_IO_PDWN_PORT   			GPIO_PRT8
#define CY_MIPI_IO_PDWN_PIN    			6
#define CY_MIPI_IO_PDWN_PIN_MUX			P8_6_GPIO

#define CY_MIPI_IO_CLK_PORT   			GPIO_PRT8
#define CY_MIPI_IO_CLK_PIN    			7
#define CY_MIPI_IO_CLK_PIN_MUX			P8_7_GPIO

#define CY_LPDDR_PWR_EN_PORT   			GPIO_PRT1
#define CY_LPDDR_PWR_EN_PIN    			2
#define CY_LPDDR_PWR_EN_PIN_MUX			P1_2_GPIO

#define CY_LPDDR_VDD1_EN_PORT   	        GPIO_PRT5
#define CY_LPDDR_VDD1_EN_PIN    	        0
#define CY_LPDDR_VDD1_EN_PIN_MUX	        P5_0_GPIO

#define CY_LPDDR_VDD2_EN_PORT   	        GPIO_PRT5
#define CY_LPDDR_VDD2_EN_PIN    	        1
#define CY_LPDDR_VDD2_EN_PIN_MUX	        P5_1_GPIO

#define CY_LPDDR_VDDQ_EN_PORT   	        GPIO_PRT5
#define CY_LPDDR_VDDQ_EN_PIN    	        2
#define CY_LPDDR_VDDQ_EN_PIN_MUX	        P5_2_GPIO

#define CY_PG_VDD1_PORT   			GPIO_PRT6
#define CY_PG_VDD1_PIN    			0
#define CY_PG_VDD1_PIN_MUX			P6_0_GPIO
#define CY_PG_VDD1_IRQN   			ioss_interrupts_gpio_dpslp_6_IRQn

#define CY_PG_VDD2_PORT   			GPIO_PRT6
#define CY_PG_VDD2_PIN    			1
#define CY_PG_VDD2_PIN_MUX			P6_1_GPIO
#define CY_PG_VDD2_IRQN   			ioss_interrupts_gpio_dpslp_6_IRQn

#define CY_PG_VDDQ_PORT   			GPIO_PRT6
#define CY_PG_VDDQ_PIN    			2
#define CY_PG_VDDQ_PIN_MUX			P6_2_GPIO
#define CY_PG_VDDQ_IRQN   			ioss_interrupts_gpio_dpslp_6_IRQn

#define CY_SMIF_PWR_EN_PORT   		        GPIO_PRT1
#define CY_SMIF_PWR_EN_PIN    		        3
#define CY_SMIF_PWR_EN_PIN_MUX		        P1_3_GPIO

#define CY_SDHC_0_RST_PORT   		        GPIO_PRT7
#define CY_SDHC_0_RST_PIN    		        6
#define CY_SDHC_0_RST_PIN_MUX		        P7_6_GPIO

#define CY_SMIF_0_RST_PORT   		        GPIO_PRT7
#define CY_SMIF_0_RST_PIN    		        7
#define CY_SMIF_0_RST_PIN_MUX		        P7_7_GPIO


/******************************************************************************/
/* SCB                                                                        */
/******************************************************************************/

#define CY_MIPI_CSI_I2C_TYPE   			SCB9
#define CY_MIPI_CSI_I2C_SDA_PORT   		GPIO_PRT7
#define CY_MIPI_CSI_I2C_SDA_PIN    		4
#define CY_MIPI_CSI_I2C_SDA_PIN_MUX		P7_4_SCB9_I2C_SDA

#define CY_MIPI_CSI_I2C_SCL_PORT   		GPIO_PRT7
#define CY_MIPI_CSI_I2C_SCL_PIN    		5
#define CY_MIPI_CSI_I2C_SCL_PIN_MUX		P7_5_SCB9_I2C_SCL
#define CY_MIPI_CSI_I2C_PCLK   			PCLK_SCB9_CLOCK
#define CY_MIPI_CSI_I2C_IRQN   			scb_9_interrupt_IRQn

#define CY_USB_SCB_UART_TYPE   			SCB11
#define CY_USB_SCB_UART_RX_PORT   		GPIO_PRT8
#define CY_USB_SCB_UART_RX_PIN    		4
#define CY_USB_SCB_UART_RX_PIN_MUX		P8_4_SCB11_UART_RX

#define CY_USB_SCB_UART_TX_PORT   		GPIO_PRT8
#define CY_USB_SCB_UART_TX_PIN    		5
#define CY_USB_SCB_UART_TX_PIN_MUX		P8_5_SCB11_UART_TX
#define CY_USB_SCB_UART_PCLK   			PCLK_SCB11_CLOCK
#define CY_USB_SCB_UART_IRQN   			scb_11_interrupt_IRQn

#define CY_AUDIOSS_I2C_TYPE                     SCB6
#define CY_AUDIOSS_I2C_SDA_PORT                 GPIO_PRT1
#define CY_AUDIOSS_I2C_SDA_PIN                  0
#define CY_AUDIOSS_I2C_SDA_PIN_MUX              P1_0_SCB6_I2C_SDA

#define CY_AUDIOSS_I2C_SCL_PORT                 GPIO_PRT1
#define CY_AUDIOSS_I2C_SCL_PIN                  1
#define CY_AUDIOSS_I2C_SCL_PIN_MUX              P1_1_SCB6_I2C_SCL
#define CY_AUDIOSS_I2C_PCLK                     PCLK_SCB6_CLOCK
#define CY_AUDIOSS_I2C_IRQN                     scb_6_interrupt_IRQn

#define CY_MKR_BUS_I2C_TYPE                     SCB6
#define CY_MKR_BUS_I2C_SDA_PORT                 GPIO_PRT1
#define CY_MKR_BUS_I2C_SDA_PIN                  0
#define CY_MKR_BUS_I2C_SDA_PIN_MUX              P1_0_SCB6_I2C_SDA

#define CY_MKR_BUS_I2C_SCL_PORT                 GPIO_PRT1
#define CY_MKR_BUS_I2C_SCL_PIN                  1
#define CY_MKR_BUS_I2C_SCL_PIN_MUX              P1_1_SCB6_I2C_SCL
#define CY_MKR_BUS_I2C_PCLK                     PCLK_SCB6_CLOCK
#define CY_MKR_BUS_I2C_IRQN                     scb_6_interrupt_IRQn

/******************************************************************************/
/* CAN                                                                        */
/******************************************************************************/

#define CY_CANFD0_TYPE   			CANFD0_CH1
#define CY_CANFD0_TX_PORT   			GPIO_PRT4
#define CY_CANFD0_TX_PIN    			4
#define CY_CANFD0_TX_PIN_MUX			P4_4_CANFD0_TTCAN_TX1

#define CY_CANFD0_RX_PORT   			GPIO_PRT4
#define CY_CANFD0_RX_PIN    			5
#define CY_CANFD0_RX_PIN_MUX			P4_5_CANFD0_TTCAN_RX1
#define CY_CANFD0_PCLK   			PCLK_CANFD0_CLOCK_CAN1
#define CY_CANFD0_IRQN   			canfd_0_interrupts0_1_IRQn

/******************************************************************************/
/* LIN                                                                        */
/******************************************************************************/

#define CY_LINCH1_TYPE                          LIN0_CH0
#define CY_LINCH1_TX_PORT   			GPIO_PRT1
#define CY_LINCH1_TX_PIN    			6
#define CY_LINCH1_TX_PIN_MUX			P1_6_LIN0_LIN_TX0

#define CY_LINCH1_RX_PORT   			GPIO_PRT1
#define CY_LINCH1_RX_PIN    			7
#define CY_LINCH1_RX_PIN_MUX			P1_7_LIN0_LIN_RX0

#define CY_LINCH1_EN_PORT   			GPIO_PRT2
#define CY_LINCH1_EN_PIN    			0
#define CY_LINCH1_EN_PIN_MUX			P2_0_LIN0_LIN_EN0
#define CY_LINCH1_PCLK   			PCLK_LIN0_CLOCK_CH_EN0
#define CY_LINCH1_IRQN   			lin_0_interrupts_0_IRQn

/******************************************************************************/
/* SAR                                                                        */
/******************************************************************************/

#define CY_ADC_THERMISTOR_TYPE   	        PASS0_SAR0
#define CY_ADC_THERMISTOR_CHN    	        2
#define CY_ADC_THERMISTOR_PORT   		GPIO_PRT1
#define CY_ADC_THERMISTOR_PIN    		5
#define CY_ADC_THERMISTOR_PIN_MUX		P1_5_GPIO
#define CY_ADC_THERMISTOR_PCLK   		PCLK_PASS0_CLOCK_SAR0
#define CY_ADC_THERMISTOR_IRQN   		pass_0_interrupts_sar_2_IRQn

#define CY_ADC_POT_MACRO                        PASS0_SAR0
#define CY_ADC_POT_IN_NO    	                1
#define CY_ADC_POT_PORT                         GPIO_PRT1
#define CY_ADC_POT_PIN    			4
#define CY_ADC_POT_PIN_MUX			P1_4_GPIO
#define CY_ADC_POT_PCLK   			PCLK_PASS0_CLOCK_SAR0
#define CY_ADC_POT_IRQN   			pass_0_interrupts_sar_1_IRQn


/******************************************************************************/
/* ETH                                                                        */
/******************************************************************************/

#define CY_GIG_ETH_TYPE   			ETH0
#define CY_GIG_ETH_INSTANCE_NUM                 (0)

#define CY_GIG_ETH_TD0_PORT   	                GPIO_PRT17
#define CY_GIG_ETH_TD0_PIN    	                0
#define CY_GIG_ETH_TD0_PIN_MUX	                P17_0_ETH0_TXD0

#define CY_GIG_ETH_TD1_PORT   	                GPIO_PRT17
#define CY_GIG_ETH_TD1_PIN    	                1
#define CY_GIG_ETH_TD1_PIN_MUX	                P17_1_ETH0_TXD1

#define CY_GIG_ETH_TD2_PORT   	                GPIO_PRT17
#define CY_GIG_ETH_TD2_PIN    	                3
#define CY_GIG_ETH_TD2_PIN_MUX	                P17_3_ETH0_TXD2

#define CY_GIG_ETH_TD3_PORT   	                GPIO_PRT17
#define CY_GIG_ETH_TD3_PIN    	                4
#define CY_GIG_ETH_TD3_PIN_MUX	                P17_4_ETH0_TXD3

#define CY_GIG_ETH_TX_CLK_PORT   	        GPIO_PRT17
#define CY_GIG_ETH_TX_CLK_PIN    	        2
#define CY_GIG_ETH_TX_CLK_PIN_MUX	        P17_2_ETH0_TX_CLK

#define CY_GIG_ETH_TX_CTL_PORT   	        GPIO_PRT19
#define CY_GIG_ETH_TX_CTL_PIN    	        0
#define CY_GIG_ETH_TX_CTL_PIN_MUX	        P19_0_ETH0_TX_CTL

#define CY_GIG_ETH_REF_CLK_PORT   	        GPIO_PRT19
#define CY_GIG_ETH_REF_CLK_PIN    	        1
#define CY_GIG_ETH_REF_CLK_PIN_MUX	        P19_1_ETH0_REF_CLK

#define CY_GIG_ETH_RD0_PORT   	                GPIO_PRT19
#define CY_GIG_ETH_RD0_PIN    	                2
#define CY_GIG_ETH_RD0_PIN_MUX	                P19_2_ETH0_RXD0

#define CY_GIG_ETH_RD1_PORT   	                GPIO_PRT19
#define CY_GIG_ETH_RD1_PIN    	                3
#define CY_GIG_ETH_RD1_PIN_MUX	                P19_3_ETH0_RXD1

#define CY_GIG_ETH_RD2_PORT   	                GPIO_PRT19
#define CY_GIG_ETH_RD2_PIN    	                5
#define CY_GIG_ETH_RD2_PIN_MUX	                P19_5_ETH0_RXD2

#define CY_GIG_ETH_RD3_PORT   	                GPIO_PRT18
#define CY_GIG_ETH_RD3_PIN    	                0
#define CY_GIG_ETH_RD3_PIN_MUX	                P18_0_ETH0_RXD3

#define CY_GIG_ETH_RX_CLK_PORT   	        GPIO_PRT19
#define CY_GIG_ETH_RX_CLK_PIN    	        4
#define CY_GIG_ETH_RX_CLK_PIN_MUX	        P19_4_ETH0_RX_CLK

#define CY_GIG_ETH_RX_CTL_PORT   	        GPIO_PRT18
#define CY_GIG_ETH_RX_CTL_PIN    	        1
#define CY_GIG_ETH_RX_CTL_PIN_MUX	        P18_1_ETH0_RX_CTL

#define CY_GIG_ETH_TXER_PORT   	                GPIO_PRT9
#define CY_GIG_ETH_TXER_PIN    	                0
#define CY_GIG_ETH_TXER_PIN_MUX	                P9_0_ETH0_TX_ER

#define CY_GIG_ETH_RX_ER_PORT   	        GPIO_PRT9
#define CY_GIG_ETH_RX_ER_PIN    	        1
#define CY_GIG_ETH_RX_ER_PIN_MUX	        P9_1_ETH0_RX_ER

#define CY_GIG_ETH_TMR_TSU_PORT   	        GPIO_PRT9
#define CY_GIG_ETH_TMR_TSU_PIN    	        2
#define CY_GIG_ETH_TMR_TSU_PIN_MUX	        P9_2_ETH0_ETH_TSU_TIMER_CMP_VAL

#define CY_GIG_ETH_MDC_PORT   		        GPIO_PRT9
#define CY_GIG_ETH_MDC_PIN    		        3
#define CY_GIG_ETH_MDC_PIN_MUX		        P9_3_ETH0_MDC

#define CY_GIG_ETH_MDIO_PORT   		        GPIO_PRT9
#define CY_GIG_ETH_MDIO_PIN    		        4
#define CY_GIG_ETH_MDIO_PIN_MUX		        P9_4_ETH0_MDIO

#define CY_GIG_ETH_IRQN0   			eth_0_interrupt_eth_0_IRQn
#define CY_GIG_ETH_IRQN1   			eth_0_interrupt_eth_1_IRQn
#define CY_GIG_ETH_IRQN2   			eth_0_interrupt_eth_2_IRQn


/******************************************************************************/
/* SMIF                                                                       */
/******************************************************************************/

#define CY_SMIF0_TYPE   			SMIF0

#define CY_SMIF0_CLK_PORT   		        GPIO_PRT15
#define CY_SMIF0_CLK_PIN    		        0
#define CY_SMIF0_CLK_PIN_MUX		        P15_0_SMIF0_SMIF0_SPIHB_CLK

#define CY_SMIF0_CLK_INV_PORT   	        GPIO_PRT15
#define CY_SMIF0_CLK_INV_PIN    	        1
#define CY_SMIF0_CLK_INV_PIN_MUX	        P15_1_SMIF0_SMIF0_SPIHB_CLK

#define CY_SMIF0_RWDS_PORT   		        GPIO_PRT14
#define CY_SMIF0_RWDS_PIN    		        4
#define CY_SMIF0_RWDS_PIN_MUX		        P14_4_SMIF0_SMIF0_SPIHB_RWDS

#define CY_SMIF0_SELECT0_PORT   		GPIO_PRT16
#define CY_SMIF0_SELECT0_PIN    		2
#define CY_SMIF0_SELECT0_PIN_MUX		P16_2_SMIF0_SMIF0_SPIHB_SELECT0

#define CY_SMIF0_SELECT1_PORT   		GPIO_PRT16
#define CY_SMIF0_SELECT1_PIN    		5
#define CY_SMIF0_SELECT1_PIN_MUX		P16_5_SMIF0_SMIF0_SPIHB_SELECT1

#define CY_SMIF0_DATA0_PORT   		        GPIO_PRT16
#define CY_SMIF0_DATA0_PIN    		        0
#define CY_SMIF0_DATA0_PIN_MUX		        P16_0_SMIF0_SMIF0_SPIHB_DATA0

#define CY_SMIF0_DATA1_PORT   		        GPIO_PRT16
#define CY_SMIF0_DATA1_PIN    		        3
#define CY_SMIF0_DATA1_PIN_MUX		        P16_3_SMIF0_SMIF0_SPIHB_DATA1

#define CY_SMIF0_DATA2_PORT   		        GPIO_PRT14
#define CY_SMIF0_DATA2_PIN    		        1
#define CY_SMIF0_DATA2_PIN_MUX		        P14_1_SMIF0_SMIF0_SPIHB_DATA2

#define CY_SMIF0_DATA3_PORT   		        GPIO_PRT14
#define CY_SMIF0_DATA3_PIN    		        2
#define CY_SMIF0_DATA3_PIN_MUX		        P14_2_SMIF0_SMIF0_SPIHB_DATA3

#define CY_SMIF0_DATA4_PORT   		        GPIO_PRT14
#define CY_SMIF0_DATA4_PIN    		        0
#define CY_SMIF0_DATA4_PIN_MUX		        P14_0_SMIF0_SMIF0_SPIHB_DATA4

#define CY_SMIF0_DATA5_PORT   		        GPIO_PRT14
#define CY_SMIF0_DATA5_PIN    		        3
#define CY_SMIF0_DATA5_PIN_MUX		        P14_3_SMIF0_SMIF0_SPIHB_DATA5

#define CY_SMIF0_DATA6_PORT   		        GPIO_PRT16
#define CY_SMIF0_DATA6_PIN    		        1
#define CY_SMIF0_DATA6_PIN_MUX		        P16_1_SMIF0_SMIF0_SPIHB_DATA6

#define CY_SMIF0_DATA7_PORT   		        GPIO_PRT16
#define CY_SMIF0_DATA7_PIN    		        4
#define CY_SMIF0_DATA7_PIN_MUX		        P16_4_SMIF0_SMIF0_SPIHB_DATA7

#define CY_SMIF_S25FXXXS                        (0u)
#define CY_SMIF_S25FXXXL                        (1u)
#define CY_SMIF0_QUAD_MEMORY                    CY_SMIF_S25FXXXL

#define CY_SMIF0_IRQN                           smif_0_interrupt_IRQn

/* SMIF 1*/
#define CY_SMIF1_TYPE                           SMIF1

#define CY_SMIF1_CLK_PORT   		        GPIO_PRT18
#define CY_SMIF1_CLK_PIN    		        0
#define CY_SMIF1_CLK_PIN_MUX		        P18_0_SMIF0_SMIF1_SPIHB_CLK

#define CY_SMIF1_CLK_INV_PORT   	        GPIO_PRT18
#define CY_SMIF1_CLK_INV_PIN    	        1
#define CY_SMIF1_CLK_INV_PIN_MUX	        P18_1_SMIF0_SMIF1_SPIHB_CLK

#define CY_SMIF1_RWDS_PORT   		        GPIO_PRT17
#define CY_SMIF1_RWDS_PIN    		        4
#define CY_SMIF1_RWDS_PIN_MUX		        P17_4_SMIF0_SMIF1_SPIHB_RWDS

#define CY_SMIF1_SELECT0_PORT   	        GPIO_PRT19
#define CY_SMIF1_SELECT0_PIN    	        2
#define CY_SMIF1_SELECT0_PIN_MUX	        P19_2_SMIF0_SMIF1_SPIHB_SELECT0

#define CY_SMIF1_SELECT1_PORT   	        GPIO_PRT19
#define CY_SMIF1_SELECT1_PIN    	        5
#define CY_SMIF1_SELECT1_PIN_MUX	        P19_5_SMIF0_SMIF1_SPIHB_SELECT1

#define CY_SMIF1_DATA0_PORT   		        GPIO_PRT19
#define CY_SMIF1_DATA0_PIN    		        0
#define CY_SMIF1_DATA0_PIN_MUX		        P19_0_SMIF0_SMIF1_SPIHB_DATA0

#define CY_SMIF1_DATA1_PORT   		        GPIO_PRT19
#define CY_SMIF1_DATA1_PIN    		        3
#define CY_SMIF1_DATA1_PIN_MUX		        P19_3_SMIF0_SMIF1_SPIHB_DATA1

#define CY_SMIF1_DATA2_PORT   		        GPIO_PRT17
#define CY_SMIF1_DATA2_PIN    		        1
#define CY_SMIF1_DATA2_PIN_MUX		        P17_1_SMIF0_SMIF1_SPIHB_DATA2

#define CY_SMIF1_DATA3_PORT   		        GPIO_PRT17
#define CY_SMIF1_DATA3_PIN    		        2
#define CY_SMIF1_DATA3_PIN_MUX		        P17_2_SMIF0_SMIF1_SPIHB_DATA3

#define CY_SMIF1_DATA4_PORT   		        GPIO_PRT17
#define CY_SMIF1_DATA4_PIN    		        0
#define CY_SMIF1_DATA4_PIN_MUX		        P17_0_SMIF0_SMIF1_SPIHB_DATA4

#define CY_SMIF1_DATA5_PORT   		        GPIO_PRT17
#define CY_SMIF1_DATA5_PIN    		        3
#define CY_SMIF1_DATA5_PIN_MUX		        P17_3_SMIF0_SMIF1_SPIHB_DATA5

#define CY_SMIF1_DATA6_PORT   		        GPIO_PRT19
#define CY_SMIF1_DATA6_PIN    		        1
#define CY_SMIF1_DATA6_PIN_MUX		        P19_1_SMIF0_SMIF1_SPIHB_DATA6

#define CY_SMIF1_DATA7_PORT   		        GPIO_PRT19
#define CY_SMIF1_DATA7_PIN    		        4
#define CY_SMIF1_DATA7_PIN_MUX		        P19_4_SMIF0_SMIF1_SPIHB_DATA7

#define CY_SMIF_S25FXXXS                        (0u)
#define CY_SMIF_S25FXXXL                        (1u)
#define CY_SMIF1_QUAD_MEMORY                    CY_SMIF_S25FXXXL

#define CY_SMIF1_IRQN   			smif_1_interrupt_IRQn

/******************************************************************************/
/*                      SDHC-eMMC Mux                                         */
/******************************************************************************/

#define CY_SDHC_TYPE                            SDHC0

#define CY_SDHC_CLK_CARD_PORT                   GPIO_PRT16
#define CY_SDHC_CLK_CARD_PIN                    4
#define CY_SDHC_CLK_CARD_PIN_MUX                P16_4_SDHC0_CLK_CARD

#define CY_SDHC_CARD_CMD_PORT                   GPIO_PRT16
#define CY_SDHC_CARD_CMD_PIN                    2
#define CY_SDHC_CARD_CMD_PIN_MUX                P16_2_SDHC0_CARD_CMD

#define CY_SDHC_CARD_DAT_3TO00_PORT             GPIO_PRT16
#define CY_SDHC_CARD_DAT_3TO00_PIN              5
#define CY_SDHC_CARD_DAT_3TO00_PIN_MUX          P16_5_SDHC0_CARD_DAT_3TO00  

#define CY_SDHC_CARD_DAT_3TO01_PORT             GPIO_PRT14
#define CY_SDHC_CARD_DAT_3TO01_PIN              0
#define CY_SDHC_CARD_DAT_3TO01_PIN_MUX          P14_0_SDHC0_CARD_DAT_3TO01

#define CY_SDHC_CARD_DAT_3TO02_PORT             GPIO_PRT14
#define CY_SDHC_CARD_DAT_3TO02_PIN              1
#define CY_SDHC_CARD_DAT_3TO02_PIN_MUX          P14_1_SDHC0_CARD_DAT_3TO02

#define CY_SDHC_CARD_DAT_3TO03_PORT             GPIO_PRT14
#define CY_SDHC_CARD_DAT_3TO03_PIN              2
#define CY_SDHC_CARD_DAT_3TO03_PIN_MUX          P14_2_SDHC0_CARD_DAT_3TO03

#define CY_SDHC_CARD_DAT_7TO40_PORT             GPIO_PRT14
#define CY_SDHC_CARD_DAT_7TO40_PIN              3
#define CY_SDHC_CARD_DAT_7TO40_PIN_MUX          P14_3_SDHC0_CARD_DAT_7TO40  

#define CY_SDHC_CARD_DAT_7TO41_PORT             GPIO_PRT14
#define CY_SDHC_CARD_DAT_7TO41_PIN              4
#define CY_SDHC_CARD_DAT_7TO41_PIN_MUX          P14_4_SDHC0_CARD_DAT_7TO41

#define CY_SDHC_CARD_DAT_7TO42_PORT             GPIO_PRT16
#define CY_SDHC_CARD_DAT_7TO42_PIN              0
#define CY_SDHC_CARD_DAT_7TO42_PIN_MUX          P16_0_SDHC0_CARD_DAT_7TO42

#define CY_SDHC_CARD_DAT_7TO43_PORT             GPIO_PRT16
#define CY_SDHC_CARD_DAT_7TO43_PIN              1
#define CY_SDHC_CARD_DAT_7TO43_PIN_MUX          P16_1_SDHC0_CARD_DAT_7TO43

#define CY_SDHC_GENERAL_IRQN                    sdhc_0_interrupt_general_IRQn
#define CY_SDHC_WAKEUP_IRQN                     sdhc_0_interrupt_wakeup_IRQn 
  

/******************************************************************************/
/******************************************************************************/

#else 	/* No Device or PSVP Selected */

    #error Choose correct device from the device specific Datasheet. 

#endif 	/* #if(defined(CYT4ENDBAS)) */


#ifdef __cplusplus
}
#endif


#endif 	/* BSP_TVIIC2D6MDDR_500BGA_DEVICE_REVA_HSEVK_REVA_H */


/* [] END OF FILE */
