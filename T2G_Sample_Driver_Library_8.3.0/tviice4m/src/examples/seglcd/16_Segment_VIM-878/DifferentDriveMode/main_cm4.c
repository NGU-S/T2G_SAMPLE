/*******************************************************************************
* \file main_cm4.c
*
* \brief
* Main file for CM4
* 
********************************************************************************
* \copyright
* Copyright 2022, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*
* VERSION   DATE        WHO         DETAIL
* v0.0      WW2246      MKAR        Initial version
*******************************************************************************/
#include "cy_project.h"
#include "cy_device_headers.h"
#include "cycfg_seglcd.h"

/*****************************************************************************/
/* Local pre-processor symbols/macros ('#define')                            */
/*****************************************************************************/
/* Timer */
#define TCPWM0_GRPx_CNTx_COUNTER              TCPWM0_GRP0_CNT0
#define PCLK_TCPWM0_CLOCKSx_COUNTER           PCLK_TCPWM0_CLOCKS0
#define TCPWM_PERI_CLK_DIVIDER_NO_COUNTER     0ul

/* LED port */
#define USER_LED_PORT                         CY_BSP_USER_LED1_PORT
#define USER_LED_PIN                          CY_BSP_USER_LED1_PIN
#define USER_LED_PIN_MUX                      CY_BSP_USER_LED1_PIN_MUX

/* Button port */
#define USER_BUTTON_PORT                      CY_BSP_USER_BUTTON1_PORT
#define USER_BUTTON_PIN                       CY_BSP_USER_BUTTON1_PIN
#define USER_BUTTON_PIN_MUX                   CY_BSP_USER_BUTTON1_PIN_MUX
#define USER_BUTTON_IRQ                       CY_BSP_USER_BUTTON1_IRQN

#define SIZE_OF_PORT                          (sizeof(appPortCfg)/sizeof(cy_stc_app_port_t))

/******************************************************************************/
/* Local Variable Declarations                                                */
/******************************************************************************/
/* Display number count */
uint8_t display_count=0ul;

/* Drive mode count */
uint8_t dm_counter=0ul;

/* Timer configuration */
cy_stc_tcpwm_counter_config_t const DisplayTimer_config =
{
    .period             = 15625ul - 1ul,
    .clockPrescaler     = CY_TCPWM_PRESCALER_DIVBY_128,
    .runMode            = CY_TCPWM_COUNTER_CONTINUOUS,
    .countDirection     = CY_TCPWM_COUNTER_COUNT_UP,
    .debug_pause        = 0ul,
    .compareOrCapture   = CY_TCPWM_COUNTER_MODE_COMPARE,
    .compare0           = 0ul,
    .compare0_buff      = 0ul,
    .compare1           = 0ul,
    .compare1_buff      = 0ul,
    .enableCompare0Swap = false,
    .enableCompare1Swap = false,
    .interruptSources   = CY_TCPWM_INT_NONE,
    .capture0InputMode  = CY_TCPWM_INPUT_LEVEL,
    .capture0Input      = 0ul,
    .reloadInputMode    = CY_TCPWM_INPUT_LEVEL,
    .reloadInput        = 0ul,
    .startInputMode     = CY_TCPWM_INPUT_LEVEL,
    .startInput         = 0ul,
    .stopInputMode      = CY_TCPWM_INPUT_LEVEL,
    .stopInput          = 0ul,
    .capture1InputMode  = CY_TCPWM_INPUT_LEVEL,
    .capture1Input      = 0ul,
    .countInputMode     = CY_TCPWM_INPUT_LEVEL,
    .countInput         = 1ul,
    .trigger0EventCfg   = CY_TCPWM_COUNTER_OVERFLOW,
    .trigger1EventCfg   = CY_TCPWM_COUNTER_OVERFLOW
};

/* Timer interrupt */
cy_stc_sysint_irq_t irq_cfg1 = 
{
    .sysIntSrc  = tcpwm_0_interrupts_0_IRQn,
    .intIdx     = CPUIntIdx3_IRQn,
    .isEnabled  = true
};

/* Button interrupt */
const cy_stc_sysint_irq_t irq_cfg2 =
{
    .sysIntSrc  = USER_BUTTON_IRQ,
    .intIdx     = CPUIntIdx2_IRQn,
    .isEnabled  = true
};

/* Common signal definition */
const uint32_t commons[SegLCD_COM_NUM] =
{
    LCD_Seg_COM0_ROW,
    LCD_Seg_COM1_ROW,
    LCD_Seg_COM2_ROW,
    LCD_Seg_COM3_ROW
};

/* Button port configuration */
const cy_stc_gpio_pin_config_t user_button_port_pin_cfg = 
{
    .outVal    = 0ul,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom     = USER_BUTTON_PIN_MUX,
    .intEdge   = CY_GPIO_INTR_FALLING,
    .intMask   = 1ul,
    .vtrip     = 0ul,
    .slewRate  = 0ul,
    .driveSel  = 0ul,
};

/* Drive mode 1 configuration */
cy_stc_seglcd_config_t config1 =
{
    .speed      = CY_SEGLCD_SPEED_HIGH,
    .wave       = CY_SEGLCD_TYPE_A,
    .drive      = CY_SEGLCD_PWM,
    .bias       = CY_SEGLCD_BIAS_HALF,
    .lsClk      = CY_SEGLCD_LSCLK_LF,
    .comNum     = SegLCD_COM_NUM,
    .frRate     = 250ul,
    .contrast   = 20ul,
    .clkFreq    = 2000000ul,
};

/* Drive mode 2 configuration */
cy_stc_seglcd_config_t config2 =
{
    .speed      = CY_SEGLCD_SPEED_HIGH,
    .wave       = CY_SEGLCD_TYPE_B,
    .drive      = CY_SEGLCD_PWM,
    .bias       = CY_SEGLCD_BIAS_THIRD,
    .lsClk      = CY_SEGLCD_LSCLK_LF,
    .comNum     = SegLCD_COM_NUM,
    .frRate     = 250ul,
    .contrast   = 20ul,
    .clkFreq    = 2000000ul,
};

/* Drive mode 3 configuration */
cy_stc_seglcd_config_t config3 =
{
    .speed      = CY_SEGLCD_SPEED_HIGH,
    .wave       = CY_SEGLCD_TYPE_A,
    .drive      = CY_SEGLCD_CORRELATION,
    .bias       = CY_SEGLCD_BIAS_THIRD,
    .lsClk      = CY_SEGLCD_LSCLK_LF,
    .comNum     = SegLCD_COM_NUM,
    .frRate     = 250ul,
    .contrast   = 20ul,
    .clkFreq    = 2000000ul,
};

/* LCD segment and common pins structure */
typedef struct
{
    volatile stc_GPIO_PRT_t*  port;
    uint8_t                   pin;
    en_hsiom_sel_t            hsiom;
    uint32_t                  driveMode;
} cy_stc_app_port_t;

/* LCD segment and common pins definition */
cy_stc_app_port_t appPortCfg[] =
{
    /* User LED pin details */
    { USER_LED_PORT,            USER_LED_PIN,           USER_LED_PIN_MUX,               CY_GPIO_DM_STRONG_IN_OFF },
    /* LCD segment pin details */
    { CY_BSP_LCD_SEG_0_PORT,    CY_BSP_LCD_SEG_0_PIN,   CY_BSP_LCD_SEG_0_PIN_MUX,       CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_SEG_1_PORT,    CY_BSP_LCD_SEG_1_PIN,   CY_BSP_LCD_SEG_1_PIN_MUX,       CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_SEG_2_PORT,    CY_BSP_LCD_SEG_2_PIN,   CY_BSP_LCD_SEG_2_PIN_MUX,       CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_SEG_3_PORT,    CY_BSP_LCD_SEG_3_PIN,   CY_BSP_LCD_SEG_3_PIN_MUX,       CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_SEG_4_PORT,    CY_BSP_LCD_SEG_4_PIN,   CY_BSP_LCD_SEG_4_PIN_MUX,       CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_SEG_5_PORT,    CY_BSP_LCD_SEG_5_PIN,   CY_BSP_LCD_SEG_5_PIN_MUX,       CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_SEG_6_PORT,    CY_BSP_LCD_SEG_6_PIN,   CY_BSP_LCD_SEG_6_PIN_MUX,       CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_SEG_7_PORT,    CY_BSP_LCD_SEG_7_PIN,   CY_BSP_LCD_SEG_7_PIN_MUX,       CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_SEG_8_PORT,    CY_BSP_LCD_SEG_8_PIN,   CY_BSP_LCD_SEG_8_PIN_MUX,       CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_SEG_9_PORT,    CY_BSP_LCD_SEG_9_PIN,   CY_BSP_LCD_SEG_9_PIN_MUX,       CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_SEG_10_PORT,   CY_BSP_LCD_SEG_10_PIN,  CY_BSP_LCD_SEG_10_PIN_MUX,      CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_SEG_11_PORT,   CY_BSP_LCD_SEG_11_PIN,  CY_BSP_LCD_SEG_11_PIN_MUX,      CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_SEG_12_PORT,   CY_BSP_LCD_SEG_12_PIN,  CY_BSP_LCD_SEG_12_PIN_MUX,      CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_SEG_13_PORT,   CY_BSP_LCD_SEG_13_PIN,  CY_BSP_LCD_SEG_13_PIN_MUX,      CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_SEG_14_PORT,   CY_BSP_LCD_SEG_14_PIN,  CY_BSP_LCD_SEG_14_PIN_MUX,      CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_SEG_15_PORT,   CY_BSP_LCD_SEG_15_PIN,  CY_BSP_LCD_SEG_15_PIN_MUX,      CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_SEG_16_PORT,   CY_BSP_LCD_SEG_16_PIN,  CY_BSP_LCD_SEG_16_PIN_MUX,      CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_SEG_17_PORT,   CY_BSP_LCD_SEG_17_PIN,  CY_BSP_LCD_SEG_17_PIN_MUX,      CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_SEG_18_PORT,   CY_BSP_LCD_SEG_18_PIN,  CY_BSP_LCD_SEG_18_PIN_MUX,      CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_SEG_19_PORT,   CY_BSP_LCD_SEG_19_PIN,  CY_BSP_LCD_SEG_19_PIN_MUX,      CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_SEG_20_PORT,   CY_BSP_LCD_SEG_20_PIN,  CY_BSP_LCD_SEG_20_PIN_MUX,      CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_SEG_21_PORT,   CY_BSP_LCD_SEG_21_PIN,  CY_BSP_LCD_SEG_21_PIN_MUX,      CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_SEG_22_PORT,   CY_BSP_LCD_SEG_22_PIN,  CY_BSP_LCD_SEG_22_PIN_MUX,      CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_SEG_23_PORT,   CY_BSP_LCD_SEG_23_PIN,  CY_BSP_LCD_SEG_23_PIN_MUX,      CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_SEG_24_PORT,   CY_BSP_LCD_SEG_24_PIN,  CY_BSP_LCD_SEG_24_PIN_MUX,      CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_SEG_25_PORT,   CY_BSP_LCD_SEG_25_PIN,  CY_BSP_LCD_SEG_25_PIN_MUX,      CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_SEG_26_PORT,   CY_BSP_LCD_SEG_26_PIN,  CY_BSP_LCD_SEG_26_PIN_MUX,      CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_SEG_27_PORT,   CY_BSP_LCD_SEG_27_PIN,  CY_BSP_LCD_SEG_27_PIN_MUX,      CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_SEG_28_PORT,   CY_BSP_LCD_SEG_28_PIN,  CY_BSP_LCD_SEG_28_PIN_MUX,      CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_SEG_29_PORT,   CY_BSP_LCD_SEG_29_PIN,  CY_BSP_LCD_SEG_29_PIN_MUX,      CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_SEG_30_PORT,   CY_BSP_LCD_SEG_30_PIN,  CY_BSP_LCD_SEG_30_PIN_MUX,      CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_SEG_31_PORT,   CY_BSP_LCD_SEG_31_PIN,  CY_BSP_LCD_SEG_31_PIN_MUX,      CY_GPIO_DM_STRONG_IN_OFF },
    /* LCD com pin details */
    { CY_BSP_LCD_COM_0_PORT,    CY_BSP_LCD_COM_0_PIN,   CY_BSP_LCD_COM_0_PIN_MUX,       CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_COM_1_PORT,    CY_BSP_LCD_COM_1_PIN,   CY_BSP_LCD_COM_1_PIN_MUX,       CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_COM_2_PORT,    CY_BSP_LCD_COM_2_PIN,   CY_BSP_LCD_COM_2_PIN_MUX,       CY_GPIO_DM_STRONG_IN_OFF },
    { CY_BSP_LCD_COM_3_PORT,    CY_BSP_LCD_COM_3_PIN,   CY_BSP_LCD_COM_3_PIN_MUX,       CY_GPIO_DM_STRONG_IN_OFF },
};

/*******************************************************************************
* Function Name: ButtonIntHandler
********************************************************************************
*
* \brief Handler for button pushing interrupt in drive mode change.
*
* \param None.
*
* \return
* void
*
* \note 
* None
*******************************************************************************/
void ButtonIntHandler(void)
{
    uint32_t intStatus;

    dm_counter++;

    display_count=0ul;

    /* If falling edge detected */
    intStatus = Cy_GPIO_GetInterruptStatusMasked(USER_BUTTON_PORT, USER_BUTTON_PIN);
    if (intStatus != 0ul)
    {
        Cy_GPIO_ClearInterrupt(USER_BUTTON_PORT, USER_BUTTON_PIN);
        
        /* Drive mode change */
        if(dm_counter==1ul)
        {
            /* Drive mode 2 settings initialization */
            CY_SEGLCD_SUCCESS == Cy_SegLCD_Init((stc_LCD_t *)SegLCD_HW, &config2);

            /* Clear frame */
            Cy_SegLCD_ClrFrame((stc_LCD_t *)SegLCD_HW, commons);

            /* LCD controller enable */
            Cy_SegLCD_Enable((stc_LCD_t *)SegLCD_HW);

            /* Display to the "2" for drive mode 2 */
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[0ul][0ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[0ul][1ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[0ul][3ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[0ul][4ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[0ul][6ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[0ul][10ul]);

            /* Display to the "0" for second digit */
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][0ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][1ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][2ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][3ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][4ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][5ul]);

            /* Display to the "0" for third digit */
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][0ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][1ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][2ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][3ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][4ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][5ul]);\
        }
        else if(dm_counter==2ul)
        {
            /* Drive mode 3 settings initialization */
            CY_SEGLCD_SUCCESS == Cy_SegLCD_Init((stc_LCD_t *)SegLCD_HW, &config3);

            /* Clear frame */
            Cy_SegLCD_ClrFrame((stc_LCD_t *)SegLCD_HW, commons);

            /* LCD controller enable */
            Cy_SegLCD_Enable((stc_LCD_t *)SegLCD_HW);

            /* Display to the "3" for drive mode 3 */
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[0ul][0ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[0ul][1ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[0ul][2ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[0ul][3ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[0ul][6ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[0ul][10ul]);

            /* Display to the "0" for second digit */
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][0ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][1ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][2ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][3ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][4ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][5ul]);

            /* Display to the "0" for third digit */
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][0ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][1ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][2ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][3ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][4ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][5ul]);
        }
        else
        {
            /* Drive mode 1 settings initialization */ 
            CY_SEGLCD_SUCCESS == Cy_SegLCD_Init((stc_LCD_t *)SegLCD_HW, &config1);

            /* Clear frame */
            Cy_SegLCD_ClrFrame((stc_LCD_t *)SegLCD_HW, commons);

            /* LCD controller enable */
            Cy_SegLCD_Enable((stc_LCD_t *)SegLCD_HW);

            /* Display to the "1" for drive mode 1 */
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[0ul][1ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[0ul][2ul]);

            /* Display to the "0" for second digit */
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][0ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][1ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][2ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][3ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][4ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][5ul]);

            /* Display to the "0" for third digit */
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][0ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][1ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][2ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][3ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][4ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][5ul]);

            /* Clear counter */
            dm_counter=0ul;
        }
    }
}

/*******************************************************************************
* Function Name: Timer_Handler
********************************************************************************
*
* \brief Handler for timer interrupt in number increment.
*
* \param None.
*
* \return
* void
*
* \note 
* None
*******************************************************************************/
void Timer_Handler(void)
{
    if(Cy_Tcpwm_Counter_GetTC_IntrMasked(TCPWM0_GRPx_CNTx_COUNTER))
    {
        /* Clear frame */
        Cy_SegLCD_ClrFrame((stc_LCD_t *)SegLCD_HW, commons);

        /* Check for drive modes */
        if(dm_counter==0ul)
        {
            /* Display to the "1" for drive mode 1 */
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[0ul][1ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[0ul][2ul]);
        }
        else if(dm_counter==1ul)
        {
            /* Display to the "2" for drive mode 2 */
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[0ul][0ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[0ul][1ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[0ul][3ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[0ul][4ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[0ul][6ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[0ul][10ul]);
        }
        else if(dm_counter==2ul)
        {
            /* Display to the "3" for drive mode 3 */
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[0ul][0ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[0ul][1ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[0ul][2ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[0ul][3ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[0ul][6ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[0ul][10ul]);
        }
        else
        {
        }

        /* Check display number*/
        switch(display_count)
        {
            case 0ul:/* Display to "0" */
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][0ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][1ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][2ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][3ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][4ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][5ul]);

                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][0ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][1ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][2ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][3ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][4ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][5ul]);
                break;
          
            case 1ul:/* Display to "1" */
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][1ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][2ul]);

                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][1ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][2ul]);
                break;

            case 2ul:/* Display to "2" */
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][0ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][1ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][3ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][4ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][6ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][10ul]);

                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][0ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][1ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][3ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][4ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][6ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][10ul]);
                break;
          
            case 3ul:/* Display to "3" */
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][0ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][1ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][2ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][3ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][6ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][10ul]);

                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][0ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][1ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][2ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][3ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][6ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][10ul]);
                break;

            case 4ul:/* Display to "4" */
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][1ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][2ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][5ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][6ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][10ul]);

                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][1ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][2ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][5ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][6ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][10ul]);
                break;

            case 5ul:/* Display to "5" */
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][0ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][2ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][3ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][5ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][6ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][10ul]);

                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][0ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][2ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][3ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][5ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][6ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][10ul]);
                break;
          
            case 6ul:/* Display to "6" */
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][0ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][2ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][3ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][4ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][5ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][6ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][10ul]);

                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][0ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][2ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][3ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][4ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][5ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][6ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][10ul]);
                break;

            case 7ul:/* Display to "7" */
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][0ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][1ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][2ul]);

                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][0ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][1ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][2ul]);
                break;

            case 8ul:/* Display to "8" */
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][0ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][1ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][2ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][3ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][4ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][5ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][6ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][10ul]);
                
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][0ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][1ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][2ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][3ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][4ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][5ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][6ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][10ul]);
                break;

            case 9ul:/* Display to "9" */
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][0ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][1ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][2ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][3ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][5ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][6ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][10ul]);
                
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][0ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][1ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][2ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][3ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][5ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][6ul]);
                Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][10ul]);
                break;

            default:
                break;
        }
       
        /* Clear count */
        display_count++;
        if(display_count==10ul)
        {
            display_count=0ul;
        }

        /* Clear timer interrupt */
        Cy_Tcpwm_Counter_ClearTC_Intr(TCPWM0_GRPx_CNTx_COUNTER);
    }
}


/* LCD segment and common pins initialization function */
static void Cy_AppPortInit(cy_stc_app_port_t cfg[], uint8_t size)
{
    cy_stc_gpio_pin_config_t pinCfg = {0ul};
    for(uint32_t i = 0ul; i < size; i++)
    {
        pinCfg.driveMode = cfg[i].driveMode;
        pinCfg.hsiom     = cfg[i].hsiom;
        Cy_GPIO_Pin_Init(cfg[i].port, cfg[i].pin, &pinCfg);
    }
}

/*******************************************************************************
* Function Name: main
********************************************************************************
*
* \brief This is an example to display for 3 digits number by using 
*        LCD controller drive mode.
*
* \param None.
*
* \return
* int
*
* \note 
* This program display 3 digits number. This program can change to three
* drive modes in the LCD controller by pushing a button. 
* For details,refer to code example document.
*******************************************************************************/
int main(void)
{   
    __enable_irq();
    
    SystemInit();

    /* GPIO(button) initialization */
    Cy_GPIO_Pin_Init(USER_BUTTON_PORT, USER_BUTTON_PIN, &user_button_port_pin_cfg);
    
    /* Interrupt for Timer initialization */
    Cy_SysInt_InitIRQ(&irq_cfg1);
    Cy_SysInt_SetSystemIrqVector(irq_cfg1.sysIntSrc, Timer_Handler);

    /* Set the interrupt priority and enable the interrupt */
    NVIC_SetPriority(CPUIntIdx3_IRQn, 2ul);
    NVIC_ClearPendingIRQ(CPUIntIdx3_IRQn);
    NVIC_EnableIRQ(CPUIntIdx3_IRQn);

    /* Interrupt for GPIO(button) initialization */
    Cy_SysInt_InitIRQ(&irq_cfg2);
    Cy_SysInt_SetSystemIrqVector(irq_cfg2.sysIntSrc, ButtonIntHandler);
    
    /* Set the interrupt priority and enable the interrupt */
    NVIC_SetPriority(CPUIntIdx2_IRQn, 3ul);
    NVIC_ClearPendingIRQ(CPUIntIdx2_IRQn);
    NVIC_EnableIRQ(CPUIntIdx2_IRQn);

    /* LCD segment and common pins initialization */
    Cy_AppPortInit(appPortCfg, SIZE_OF_PORT);

    /* Enable peripheral clock divider for LCD operation with the 2MHz clock frequency */
    Cy_SysClk_PeriphAssignDivider(PCLK_LCD0_CLOCK, CY_SYSCLK_DIV_8_BIT, 0ul);
    Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_8_BIT, 0ul, 39ul);
    Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_8_BIT, 0ul);
    
    /* Assign a programmable divider for TCPWM0_GRP0_CNT0 */
    Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCKSx_COUNTER, (cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_COUNTER);
    Cy_SysClk_PeriphSetDivider((cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_COUNTER, 39ul);
    Cy_SysClk_PeriphEnableDivider((cy_en_divider_types_t)CY_SYSCLK_DIV_16_BIT, TCPWM_PERI_CLK_DIVIDER_NO_COUNTER);

    /* Initialize TCPWM0_GPR0_CNT0 as Timer and enable */
    Cy_Tcpwm_Counter_Init(TCPWM0_GRPx_CNTx_COUNTER, &DisplayTimer_config);
    Cy_Tcpwm_Counter_Enable(TCPWM0_GRPx_CNTx_COUNTER);
    Cy_Tcpwm_TriggerStart(TCPWM0_GRPx_CNTx_COUNTER);  
    
    /* Enable interrupt */
    Cy_Tcpwm_Counter_SetTC_IntrMask(TCPWM0_GRPx_CNTx_COUNTER);

    /* LCD controller initialization */
    if (CY_SEGLCD_SUCCESS == Cy_SegLCD_Init((stc_LCD_t *)SegLCD_HW, &config1))
    {
        /* Clear frame */
        if (CY_SEGLCD_SUCCESS == Cy_SegLCD_ClrFrame((stc_LCD_t *)SegLCD_HW, commons))
        {
            /* LCD controller enable */ 
            Cy_SegLCD_Enable((stc_LCD_t *)SegLCD_HW);
            
            /* Display to the "1" for first digit in drive mode */
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[0ul][1ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[0ul][2ul]);
            
            /* Display to the "0" for second digit */
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][0ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][1ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][2ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][3ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][4ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[1ul][5ul]);
            
            /* Display to the "0" for third digit */
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][0ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][1ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][2ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][3ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][4ul]);
            Cy_SegLCD_SetPixel((stc_LCD_t *)SegLCD_HW, SegLCD_Display0_pixMap[2ul][5ul]);

            for(;;);
        }
        else
        {
            /* Error handling */
            while(1);
        }
    }
    else
    {
        /* Error handling */
        while(1);
    }
}
/* [] END OF FILE */
