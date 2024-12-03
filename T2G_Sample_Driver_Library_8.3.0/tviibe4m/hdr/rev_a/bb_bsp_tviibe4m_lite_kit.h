/***************************************************************************//**
* \file bb_bsp_tviibe4m_lite_kit.h
*
* \brief
* Project specific header
*
* \note
* It contains references to all generated header files and should 
* not be modified.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef BB_BSP_TVIIBE4M_LITE_KIT_H
#define BB_BSP_TVIIBE4M_LITE_KIT_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/
/******************************************************************************/
 
// tviibe4m - Lite Kit - 100pin
#if (CY_USE_PSVP == 0) && ( defined(CYT2BL5BAS) || defined(CYT2BL5BAE) || \
                            defined(CYT2BL5CAS) || defined(CYT2BL5CAE) )

// Lite Kit Entities

/******************************************************************************/
/*                      User LEDs Mux                                         */
/******************************************************************************/
#define CY_CB_LED_PORT                  GPIO_PRT5
#define CY_CB_LED_PIN                   0
#define CY_CB_LED_PIN_MUX               P5_0_GPIO

#define CY_CB_LED2_PORT                 GPIO_PRT5
#define CY_CB_LED2_PIN                  1
#define CY_CB_LED2_PIN_MUX              P5_1_GPIO

#define CY_CB_LED3_PORT                 GPIO_PRT5
#define CY_CB_LED3_PIN                  2
#define CY_CB_LED3_PIN_MUX              P5_2_GPIO


/******************************************************************************/
/*                      User Buttons Mux                                      */
/******************************************************************************/
#define CY_CB_BUTTON_PORT               GPIO_PRT5
#define CY_CB_BUTTON_PIN                3
#define CY_CB_BUTTON_PIN_MUX            P5_3_GPIO
#define CY_CB_BUTTON_IRQN               ioss_interrupts_gpio_5_IRQn

#define CY_CB_BUTTON2_PORT              GPIO_PRT17
#define CY_CB_BUTTON2_PIN               0
#define CY_CB_BUTTON2_PIN_MUX           P17_0_GPIO
#define CY_CB_BUTTON2_IRQN              ioss_interrupts_gpio_17_IRQn


/******************************************************************************/
/*                      ADC POT                                               */
/******************************************************************************/
#define CY_ADC_POT_MACRO                PASS0_SAR0
#define CY_ADC_POT_IN_NO                0
#define CY_ADC_POT_PORT                 GPIO_PRT6
#define CY_ADC_POT_PIN                  0
#define CY_ADC_POT_PIN_MUX              P6_0_GPIO
#define CY_ADC_POT_PCLK                 PCLK_PASS0_CLOCK_SAR0
#define CY_ADC_POT_IRQN                 pass_0_interrupts_sar_0_IRQn


/******************************************************************************/
/*                      SCB-SPI/I2C  Port Mux                                 */
/******************************************************************************/
/* SCB - SPI Mux (BB_CAN_SPI) */
#define CY_SCB_TYPE                     SCB3
#define CY_SCB_MOSI_PORT                GPIO_PRT13
#define CY_SCB_MOSI_PIN                 1
#define CY_SCB_MOSI_PIN_MUX             P13_1_SCB3_SPI_MOSI
#define CY_SCB_MISO_PORT                GPIO_PRT13
#define CY_SCB_MISO_PIN                 0
#define CY_SCB_MISO_PIN_MUX             P13_0_SCB3_SPI_MISO
#define CY_SCB_SCK_PORT                 GPIO_PRT13
#define CY_SCB_SCK_PIN                  2
#define CY_SCB_SCK_PIN_MUX              P13_2_SCB3_SPI_CLK
#define CY_SCB_SS0_PORT                 GPIO_PRT13
#define CY_SCB_SS0_PIN                  3
#define CY_SCB_SS0_PIN_MUX              P13_3_SCB3_SPI_SELECT0
#define CY_SCB_SS1_PORT                 GPIO_PRT13
#define CY_SCB_SS1_PIN                  4
#define CY_SCB_SS1_PIN_MUX              P13_4_SCB3_SPI_SELECT1
#define CY_SCB_SS2_PORT                 GPIO_PRT13
#define CY_SCB_SS2_PIN                  5
#define CY_SCB_SS2_PIN_MUX              P13_5_SCB3_SPI_SELECT2
#define CY_SCB_SS3_PORT                 GPIO_PRT13
#define CY_SCB_SS3_PIN                  6
#define CY_SCB_SS3_PIN_MUX              P13_6_SCB3_SPI_SELECT3
#define CY_SCB_PCLK                     PCLK_SCB3_CLOCK
#define CY_SCB_IRQN                     scb_3_interrupt_IRQn

/* SCB -I2C */
#define CY_SCB_I2C_TYPE                 SCB4
#define CY_SCB_I2C_SDA_PORT             GPIO_PRT6
#define CY_SCB_I2C_SDA_PIN              1
#define CY_SCB_I2C_SDA_PIN_MUX          P6_1_SCB4_I2C_SDA
#define CY_SCB_I2C_SCL_PORT             GPIO_PRT6
#define CY_SCB_I2C_SCL_PIN              2
#define CY_SCB_I2C_SCL_PIN_MUX          P6_2_SCB4_I2C_SCL
#define CY_SCB_I2C_PCLK                 PCLK_SCB4_CLOCK
#define CY_SCB_I2C_IRQN                 scb_4_interrupt_IRQn


/******************************************************************************/
/*                      CANFD Port Mux                                 */
/******************************************************************************/
#define CY_CANFD0_TYPE                  CY_CANFD0_2_TYPE
#define CY_CANFD0_RX_PORT               GPIO_PRT12
#define CY_CANFD0_RX_PIN                1u
#define CY_CANFD0_RX_MUX                P12_1_CANFD0_TTCAN_RX2
#define CY_CANFD0_TX_PORT               GPIO_PRT12
#define CY_CANFD0_TX_PIN                0
#define CY_CANFD0_TX_MUX                P12_0_CANFD0_TTCAN_TX2
#define CY_CANFD0_PCLK                  PCLK_CANFD0_CLOCK_CAN2
#define CY_CANFD0_IRQN                  canfd_0_interrupts0_2_IRQn


/******************************************************************************/
/*                      SCB-UART USB Port Mux                                 */
/******************************************************************************/
#define CY_USB_SCB_UART_TYPE            SCB0
#define CY_USB_SCB_UART_RX_PORT         GPIO_PRT0
#define CY_USB_SCB_UART_RX_PIN          0
#define CY_USB_SCB_UART_RX_PIN_MUX      P0_0_SCB0_UART_RX
#define CY_USB_SCB_UART_TX_PORT         GPIO_PRT0
#define CY_USB_SCB_UART_TX_PIN          1
#define CY_USB_SCB_UART_TX_PIN_MUX      P0_1_SCB0_UART_TX
#define CY_USB_SCB_UART_PCLK            PCLK_SCB0_CLOCK
#define CY_USB_SCB_UART_IRQN            scb_0_interrupt_IRQn  


/******************************************************************************/
/*                      DMA PDMA CRC Mux                                      */
/******************************************************************************/
#define CY_LED0_PORT                    GPIO_PRT5
#define CY_LED0_PIN                     0
#define CY_LED0_PIN_MUX                 P5_0_GPIO


/******************************************************************************/
/*                      SMARTIO Mux                                           */
/******************************************************************************/
#define CY_SMARTIO_MACRO                SMARTIO
#define CY_SMARTIO_PORT                 SMARTIO_PRT17
#define CY_SMARTIO_CLK                  PCLK_SMARTIO17_CLOCK

#define CY_SMARTIO_OUT_PORT             GPIO_PRT17
#define CY_SMARTIO_OUT_PIN              1
#define CY_SMARTIO_OUT_PORT_MUX         P17_1_GPIO

#define CY_SMARTIO_IN_PORT              GPIO_PRT17
#define CY_SMARTIO_IN_PIN               0
#define CY_SMARTIO_IN_PORT_MUX          P17_0_GPIO

#define CY_SMARTIO_IN2_PORT             GPIO_PRT17
#define CY_SMARTIO_IN2_PIN              2
#define CY_SMARTIO_IN2_PORT_MUX_PWM     P17_2_GPIO
#define CY_SMARTIO_TCPWM_GRP0_CNT       TCPWM0_GRP0_CNT56
#define CY_SMARTIO_TCPWM_PCLK           PCLK_TCPWM0_CLOCKS56


/******************************************************************************/
/*                      PWM Mux                                               */
/******************************************************************************/
#define Cy_TCPWM_LINE0_PORT             GPIO_PRT5
#define Cy_TCPWM_LINE0_PIN              0
#define Cy_TCPWM_LINE0_MUX              P5_0_TCPWM0_LINE9

#define Cy_TCPWM_LINE0_CMPL_PORT        GPIO_PRT5
#define Cy_TCPWM_LINE0_CMPL_PIN         1
#define Cy_TCPWM_LINE0_CMPL_MUX         P5_1_TCPWM0_LINE_COMPL9


/******************************************************************************/
/*                      SRAM ECC Mux                                          */
/******************************************************************************/
#define CY_SYSFLT_RAMC0_NC_ECC          CY_SYSFLT_CPUSS_RAMC0_NC_ECC
#define CY_SYSFLT_RAMC0_C_ECC           CY_SYSFLT_CPUSS_RAMC0_C_ECC


/******************************************************************************/
/*                      IPC UsingLowLevelApi Mux                              */
/******************************************************************************/
#define CY_LED0_PORT                    GPIO_PRT5
#define CY_LED0_PIN                     0
#define CY_LED0_PIN_MUX                 P5_0_GPIO

#define CY_LED1_PORT                    GPIO_PRT5
#define CY_LED1_PIN                     1
#define CY_LED1_PIN_MUX                 P5_1_GPIO

#define CY_LED2_PORT                    GPIO_PRT5
#define CY_LED2_PIN                     2
#define CY_LED2_PIN_MUX                 P5_2_GPIO


/******************************************************************************/
/******************************************************************************/
      
#else // No Device or PSVP Selected
    
    #error "Choose proper device and respective package"
    
#endif // #if (CY_USE_PSVP == 1)
  
  
#ifdef __cplusplus
}
#endif

#endif /* BB_BSP_TVIIBE4M_LITE_KIT_H */

/* [] END OF FILE */
