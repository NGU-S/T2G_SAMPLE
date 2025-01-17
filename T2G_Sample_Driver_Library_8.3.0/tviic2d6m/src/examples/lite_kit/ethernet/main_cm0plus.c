/***************************************************************************//**
* \file main_cm7_0.c
*
* \version 1.0
*
* \brief Main example file for CM7_0
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
#include "drivers\ethernet\cy_ethif.h"

/********************************************************/

#define EMAC_MII                        0
#define EMAC_RMII                       1
#define EMAC_GMII                       2
#define EMAC_RGMII                      3

#define ETH_LINKSPEED_10                10
#define ETH_LINKSPEED_100               100
#define ETH_LINKSPEED_1000              1000

/** PHY Mode Selection      */
#define EMAC_INTERFACE                  EMAC_RGMII
#define EMAC_LINKSPEED                  ETH_LINKSPEED_10

/********************************************************/

#define USER_LED_PORT                   CY_USER_LED2_PORT
#define USER_LED_PIN                    CY_USER_LED2_PIN
#define USER_LED_PIN_MUX                CY_USER_LED2_PIN_MUX

/********************************************************/
#define ETH_REG_BASE                    CY_GIG_ETH_TYPE

#define ETH_INTR_SRC                    (CY_GIG_ETH_IRQN0)
#define ETH_INTR_SRC_Q1                 (CY_GIG_ETH_IRQN1)
#define ETH_INTR_SRC_Q2                 (CY_GIG_ETH_IRQN2)

#define ETHx_TD0_PORT                   CY_GIG_ETH_TD0_PORT
#define ETHx_TD0_PIN                    CY_GIG_ETH_TD0_PIN
#define ETHx_TD0_PIN_MUX                CY_GIG_ETH_TD0_PIN_MUX

#define ETHx_TD1_PORT                   CY_GIG_ETH_TD1_PORT
#define ETHx_TD1_PIN                    CY_GIG_ETH_TD1_PIN
#define ETHx_TD1_PIN_MUX                CY_GIG_ETH_TD1_PIN_MUX

#define ETHx_TD2_PORT                   CY_GIG_ETH_TD2_PORT
#define ETHx_TD2_PIN                    CY_GIG_ETH_TD2_PIN
#define ETHx_TD2_PIN_MUX                CY_GIG_ETH_TD2_PIN_MUX

#define ETHx_TD3_PORT                   CY_GIG_ETH_TD3_PORT
#define ETHx_TD3_PIN                    CY_GIG_ETH_TD3_PIN
#define ETHx_TD3_PIN_MUX                CY_GIG_ETH_TD3_PIN_MUX

#define ETHx_TD4_PORT                   CY_GIG_ETH_TD4_PORT
#define ETHx_TD4_PIN                    CY_GIG_ETH_TD4_PIN
#define ETHx_TD4_PIN_MUX                CY_GIG_ETH_TD4_PIN_MUX

#define ETHx_TD5_PORT                   CY_GIG_ETH_TD5_PORT
#define ETHx_TD5_PIN                    CY_GIG_ETH_TD5_PIN
#define ETHx_TD5_PIN_MUX                CY_GIG_ETH_TD5_PIN_MUX

#define ETHx_TD6_PORT                   CY_GIG_ETH_TD6_PORT
#define ETHx_TD6_PIN                    CY_GIG_ETH_TD6_PIN
#define ETHx_TD6_PIN_MUX                CY_GIG_ETH_TD6_PIN_MUX

#define ETHx_TD7_PORT                   CY_GIG_ETH_TD7_PORT
#define ETHx_TD7_PIN                    CY_GIG_ETH_TD7_PIN
#define ETHx_TD7_PIN_MUX                CY_GIG_ETH_TD7_PIN_MUX

#define ETHx_TXER_PORT                  CY_GIG_ETH_TXER_PORT
#define ETHx_TXER_PIN                   CY_GIG_ETH_TXER_PIN
#define ETHx_TXER_PIN_MUX               CY_GIG_ETH_TXER_PIN_MUX

#define ETHx_TX_CTL_PORT                CY_GIG_ETH_TX_CTL_PORT
#define ETHx_TX_CTL_PIN                 CY_GIG_ETH_TX_CTL_PIN
#define ETHx_TX_CTL_PIN_MUX             CY_GIG_ETH_TX_CTL_PIN_MUX

#define ETHx_RD0_PORT                   CY_GIG_ETH_RD0_PORT
#define ETHx_RD0_PIN                    CY_GIG_ETH_RD0_PIN
#define ETHx_RD0_PIN_MUX                CY_GIG_ETH_RD0_PIN_MUX

#define ETHx_RD1_PORT                   CY_GIG_ETH_RD1_PORT
#define ETHx_RD1_PIN                    CY_GIG_ETH_RD1_PIN
#define ETHx_RD1_PIN_MUX                CY_GIG_ETH_RD1_PIN_MUX

#define ETHx_RD2_PORT                   CY_GIG_ETH_RD2_PORT
#define ETHx_RD2_PIN                    CY_GIG_ETH_RD2_PIN
#define ETHx_RD2_PIN_MUX                CY_GIG_ETH_RD2_PIN_MUX

#define ETHx_RD3_PORT                   CY_GIG_ETH_RD3_PORT
#define ETHx_RD3_PIN                    CY_GIG_ETH_RD3_PIN
#define ETHx_RD3_PIN_MUX                CY_GIG_ETH_RD3_PIN_MUX

#define ETHx_RD4_PORT                   CY_GIG_ETH_RD4_PORT
#define ETHx_RD4_PIN                    CY_GIG_ETH_RD4_PIN
#define ETHx_RD4_PIN_MUX                CY_GIG_ETH_RD4_PIN_MUX

#define ETHx_RD5_PORT                   CY_GIG_ETH_RD5_PORT
#define ETHx_RD5_PIN                    CY_GIG_ETH_RD5_PIN
#define ETHx_RD5_PIN_MUX                CY_GIG_ETH_RD5_PIN_MUX

#define ETHx_RD6_PORT                   CY_GIG_ETH_RD6_PORT
#define ETHx_RD6_PIN                    CY_GIG_ETH_RD6_PIN
#define ETHx_RD6_PIN_MUX                CY_GIG_ETH_RD6_PIN_MUX

#define ETHx_RD7_PORT                   CY_GIG_ETH_RD7_PORT
#define ETHx_RD7_PIN                    CY_GIG_ETH_RD7_PIN
#define ETHx_RD7_PIN_MUX                CY_GIG_ETH_RD7_PIN_MUX

#define ETHx_RX_CTL_PORT                CY_GIG_ETH_RX_CTL_PORT
#define ETHx_RX_CTL_PIN                 CY_GIG_ETH_RX_CTL_PIN
#define ETHx_RX_CTL_PIN_MUX             CY_GIG_ETH_RX_CTL_PIN_MUX

#define ETHx_RX_ER_PORT                 CY_GIG_ETH_RX_ER_PORT
#define ETHx_RX_ER_PIN                  CY_GIG_ETH_RX_ER_PIN
#define ETHx_RX_ER_PIN_MUX              CY_GIG_ETH_RX_ER_PIN_MUX

#define ETHx_TX_CLK_PORT                CY_GIG_ETH_TX_CLK_PORT
#define ETHx_TX_CLK_PIN                 CY_GIG_ETH_TX_CLK_PIN
#define ETHx_TX_CLK_PIN_MUX             CY_GIG_ETH_TX_CLK_PIN_MUX

#define ETHx_RX_CLK_PORT                CY_GIG_ETH_RX_CLK_PORT
#define ETHx_RX_CLK_PIN                 CY_GIG_ETH_RX_CLK_PIN
#define ETHx_RX_CLK_PIN_MUX             CY_GIG_ETH_RX_CLK_PIN_MUX

#define ETHx_REF_CLK_PORT               CY_GIG_ETH_REF_CLK_PORT
#define ETHx_REF_CLK_PIN                CY_GIG_ETH_REF_CLK_PIN
#define ETHx_REF_CLK_PIN_MUX            CY_GIG_ETH_REF_CLK_PIN_MUX

#define ETHx_MDC_PORT                   CY_GIG_ETH_MDC_PORT
#define ETHx_MDC_PIN                    CY_GIG_ETH_MDC_PIN
#define ETHx_MDC_PIN_MUX                CY_GIG_ETH_MDC_PIN_MUX

#define ETHx_MDIO_PORT                  CY_GIG_ETH_MDIO_PORT
#define ETHx_MDIO_PIN                   CY_GIG_ETH_MDIO_PIN
#define ETHx_MDIO_PIN_MUX               CY_GIG_ETH_MDIO_PIN_MUX


/********************************************************/
/** PHY related constants   */  
#define PHY_ADDR                    (0)  // Value depends on PHY and its hardware configurations
#define ETH_FRAME_SIZE              1500


/********************************************************/

cy_stc_gpio_pin_config_t user_led_port_pin_cfg =             
{                                                  
    .outVal = 0x00,                                
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,    
    .hsiom = USER_LED_PIN_MUX,                           
    .intEdge = 0,                                  
    .intMask = 0,                                  
    .vtrip = 0,                                    
    .slewRate = 0,                                 
    .driveSel = 0,                                 
    .vregEn = 0,                                   
    .ibufMode = 0,                                 
    .vtripSel = 0,                                 
    .vrefSel = 0,                                  
    .vohSel = 0,                                   
};

/********************************************************/
// EMAC *********
/**                      PortPinName.outVal||  driveMode               hsiom             ||intEdge||intMask||vtrip||slewRate||driveSel||vregEn||ibufMode||vtripSel||vrefSel||vohSel*/
cy_stc_gpio_pin_config_t ethx_tx0   = {0x00, CY_GPIO_DM_STRONG_IN_OFF, ETHx_TD0_PIN_MUX,     0,       0,       0,     0,        0,        0,      0,        0,        0,       0};
cy_stc_gpio_pin_config_t ethx_tx1   = {0x00, CY_GPIO_DM_STRONG_IN_OFF, ETHx_TD1_PIN_MUX,     0,       0,       0,     0,        0,        0,      0,        0,        0,       0};
cy_stc_gpio_pin_config_t ethx_tx2   = {0x00, CY_GPIO_DM_STRONG_IN_OFF, ETHx_TD2_PIN_MUX,     0,       0,       0,     0,        0,        0,      0,        0,        0,       0};
cy_stc_gpio_pin_config_t ethx_tx3   = {0x00, CY_GPIO_DM_STRONG_IN_OFF, ETHx_TD3_PIN_MUX,     0,       0,       0,     0,        0,        0,      0,        0,        0,       0};
cy_stc_gpio_pin_config_t ethx_txer  = {0x00, CY_GPIO_DM_STRONG_IN_OFF, ETHx_TXER_PIN_MUX,    0,       0,       0,     0,        0,        0,      0,        0,        0,       0};
cy_stc_gpio_pin_config_t ethx_txctl = {0x00, CY_GPIO_DM_STRONG_IN_OFF, ETHx_TX_CTL_PIN_MUX,  0,       0,       0,     0,        0,        0,      0,        0,        0,       0};
cy_stc_gpio_pin_config_t ethx_rx0   = {0x00, CY_GPIO_DM_HIGHZ,         ETHx_RD0_PIN_MUX,     0,       0,       0,     0,        0,        0,      0,        0,        0,       0};
cy_stc_gpio_pin_config_t ethx_rx1   = {0x00, CY_GPIO_DM_HIGHZ,         ETHx_RD1_PIN_MUX,     0,       0,       0,     0,        0,        0,      0,        0,        0,       0};
cy_stc_gpio_pin_config_t ethx_rx2   = {0x00, CY_GPIO_DM_HIGHZ,         ETHx_RD2_PIN_MUX,     0,       0,       0,     0,        0,        0,      0,        0,        0,       0};
cy_stc_gpio_pin_config_t ethx_rx3   = {0x00, CY_GPIO_DM_HIGHZ,         ETHx_RD3_PIN_MUX,     0,       0,       0,     0,        0,        0,      0,        0,        0,       0};
cy_stc_gpio_pin_config_t ethx_rxctl = {0x00, CY_GPIO_DM_HIGHZ,         ETHx_RX_CTL_PIN_MUX,  0,       0,       0,     0,        0,        0,      0,        0,        0,       0};
cy_stc_gpio_pin_config_t ethx_rxer  = {0x00, CY_GPIO_DM_HIGHZ,         ETHx_RX_ER_PIN_MUX,   0,       0,       0,     0,        0,        0,      0,        0,        0,       0};
                                                                       
cy_stc_gpio_pin_config_t ethx_txclk = {0x00, CY_GPIO_DM_STRONG_IN_OFF, ETHx_TX_CLK_PIN_MUX,  0,       0,       0,     0,        0,        0,      0,        0,        0,       0};
cy_stc_gpio_pin_config_t ethx_rxclk  = {0x00, CY_GPIO_DM_HIGHZ,        ETHx_RX_CLK_PIN_MUX,  0,       0,       0,     0,        0,        0,      0,        0,        0,       0};
cy_stc_gpio_pin_config_t ethx_refclk = {0x00, CY_GPIO_DM_HIGHZ,        ETHx_REF_CLK_PIN_MUX, 0,       0,       0,     0,        0,        0,      0,        0,        0,       0};

cy_stc_gpio_pin_config_t ethx_mdc   = {0x00, CY_GPIO_DM_STRONG_IN_OFF, ETHx_MDC_PIN_MUX,     0,       0,       0,     0,        3,        0,      0,        0,        0,       0};
cy_stc_gpio_pin_config_t ethx_mdio  = {0x00, CY_GPIO_DM_STRONG,        ETHx_MDIO_PIN_MUX,    0,       0,       0,     0,        3,        0,      0,        0,        0,       0};


/* PHY Configuration */
cy_stc_rtl8211f_phy_cfg_t rtlPhyConfig =
{
    .ifMode             = ETH_PHY_CONFIG_INTERFACE_RGMII_TXID,                  /**  Interface mode between MAC and PHY */
    .advMode            = ETH_PHY_CONFIG_ADVERTISING_SUPPORTED_10BASET_HALF,    /**  Advertise the speed Supported */
#if (EMAC_LINKSPEED == ETH_LINKSPEED_1000)
    .clkout             = ETH_PHY_CONFIG_ENABLE_CLKOUT_125MHZ,                         /**  Clock Out Selection */
    .speedMode          = ETH_PHY_CONFIG_LINK_MODE_1000BASET_FULL,              /**  Speed mode that shall be advertised (#enableAutoNeg == true) or configured */    
#elif (EMAC_LINKSPEED == ETH_LINKSPEED_100)
    .clkout             = ETH_PHY_CONFIG_ENABLE_CLKOUT_25MHZ,                   /**  Clock Out Selection */
    .speedMode          = ETH_PHY_CONFIG_LINK_MODE_100BASET_FULL,               /**  Speed mode that shall be advertised (#enableAutoNeg == true) or configured */
#else
    .clkout             = ETH_PHY_CONFIG_ENABLE_CLKOUT_25MHZ,                   /**  Clock Out Selection */
    .speedMode          = ETH_PHY_CONFIG_LINK_MODE_10BASET_FULL,                /**  Speed mode that shall be advertised (#enableAutoNeg == true) or configured */    
#endif    
    .enableAutoNeg      = true,                                                 /**  Selects between auto-negotation and fixed configuration */
    .enableLoopback     = false,                                                /**  Selects if LoopBack is enabled or not */
    .masterMode         = false,                                                /** Selects if master Mode is enabled */
};

/* PHY Context */
cy_stc_rtl8211f_t rtlPhyHandle = 
{
    .pEth       = ETH_REG_BASE, /**  Pointer to ETH IP base */
    .phyAddr    = 0u,           /**  PHY address (0-31) */
};

/********************************************************/
/* Transmit source buffer  */
#if   defined ( __ghs__ )
  #pragma alignvar (8) 
#elif defined ( __ICCARM__ )
  __attribute((aligned(8))) 
#else
  #warning "This driver is supported only by GHS and IAR compiler"
#endif

bool bFrameReceived = false;
bool bFrameTransmit = false;
uint16_t u16TransmitLength = 0;
uint8_t u8DummyTxBuf[ETH_FRAME_SIZE] = {0};

/********************************************************/
void Cy_Ethx_InterruptHandler (void);
static void Cy_App_Init_EthernetPortpins(void);
static void Ethx_RxFrameCB ( cy_pstc_eth_type_t pstcEth, uint8_t * u8RxBuffer, uint32_t u32Length );
static void Ethx_TSUIncrement ( cy_pstc_eth_type_t pstcEth );
static void Ethx_TxFrameSuccessful ( cy_pstc_eth_type_t pstcEth, uint8_t u8QueueIndex, uint32_t bufIdx);
static void Phy_RTL8211F_Configure(void);

/********************************************************/
/* Interrupt Handlers for Ethernet 0 */
void Cy_Ethx_InterruptHandler (void)
{
    Cy_EthIf00_DecodeEvent();
}


static uint32_t checkError     = 0UL;

int main(void)
{
    uint32_t cy_Hfclk4FreqHz   = 0UL;
    uint32_t cy_Hfclk5FreqHz   = 0UL;
    uint32_t cy_PeriFreqHz     = 0UL;
    
    SystemInit();
    
    __enable_irq();

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_GPIO_Pin_Init(USER_LED_PORT, USER_LED_PIN, &user_led_port_pin_cfg);    
    
    /* EMAC Configuration */
    bool bClearAll = true;
    bool bTransmitBuf = true;
    bool bLastBuffer = true;
    
    /* Clocks check for Debug only */
    Cy_SysClk_GetHfClkFrequency(CY_SYSCLK_HFCLK_5, &cy_Hfclk5FreqHz);       /* Clock for TSU */    
    Cy_SysClk_GetHfClkFrequency(CY_SYSCLK_HFCLK_4, &cy_Hfclk4FreqHz);       /* Internal reference Clock for RGMII/RMII mode */      
    Cy_SysClk_GetClkPeriFrequency(&cy_PeriFreqHz);                          /* Clock for MDC: Peri -> GR4Divider -> Ethernet */
    
    /* Configure Ethernet Port pins */
    Cy_App_Init_EthernetPortpins();      
    
    /* Wrapper configuration */
    cy_str_ethif_wrapper_config stcWrapperConfig = 
    {
        #if ((EMAC_INTERFACE == EMAC_RGMII) && (EMAC_LINKSPEED == ETH_LINKSPEED_10))
        .stcInterfaceSel = CY_ETHIF_CTL_RGMII_10,       /* 10 Mbps RGMII */ 
        #elif ((EMAC_INTERFACE == EMAC_RGMII) && (EMAC_LINKSPEED == ETH_LINKSPEED_100))
        .stcInterfaceSel = CY_ETHIF_CTL_RGMII_100,      /* 100 Mbps RGMII */ 
        #elif ((EMAC_INTERFACE == EMAC_RGMII) && (EMAC_LINKSPEED == ETH_LINKSPEED_1000))
        .stcInterfaceSel = CY_ETHIF_CTL_RGMII_1000,     /* 1000 Mbps RGMII */ 
        #else
        .stcInterfaceSel = 8,                           /* Error in configuration */     
        #endif
        
        .bRefClockSource = CY_ETHIF_EXTERNAL_HSIO,      /* assigning Ref_Clk to HSIO Clock, it is recommended to use external clock coming from HSIO  */
        
        #if EMAC_LINKSPEED == ETH_LINKSPEED_10
        .u8RefClkDiv = 10,                              /* RefClk: 25MHz, Divide Refclock by 10 to have 2.5 MHz tx clock  */
        #elif EMAC_LINKSPEED == ETH_LINKSPEED_100
        .u8RefClkDiv = 1,                               /* RefClk: 25MHz, Divide Refclock by 1 to have 25 MHz Tx clock  */
        #elif EMAC_LINKSPEED == ETH_LINKSPEED_1000
        .u8RefClkDiv = 1,                               /* RefClk: 125MHz, Divide Refclock by 1 to have 125 MHz Tx clock || Although only relevant in RGMII/GMII modes */        
        #endif
    };
    
    /* Default Timer register values */
    CEDI_1588TimerVal stc1588TimerValue = 
    {
        .secsUpper = 0,
        .secsLower = 0,
        .nanosecs = 0,
    };
    
    /* Increment values for each clock cycles */
    CEDI_TimerIncrement stc1588TimerIncValue = 
    {                                           /* This Increment values are calculated for source clock of 196.607999 MHz */
        .nanoSecsInc = 5,                       /* Having source clock of 196.607999 MHz, with each clock cycle Nanosecond counter shall be incremented by 5  */
        .subNsInc = 0x1615,                     /* incrementing just Nanosecond counter will not give accuracy, so sub-nanosecond counter also must be incremented  */  
        .lsbSubNsInc = 0x55,                    /* 0x55 is the lower 8 bits increment value for subNanosecond and 0x1615 is the higher 16 bits of the counter */
        .altIncCount = 0,                       /* This example is not using alternate increment mode, also it is not recommended by IP provider          */
        .altNanoSInc = 0,                       /* When Alt increment mode is disabled, then this counter does not play any role                          */
    };
    
    /* To calculate the value to write to the sub-ns register you take the decimal value of 
        the sub-nanosecond value, then multiply it by 2 to the power of 24 (16777216) and 
        convert the result to hexadecimal. For example for a sub-nanosecond value of 0.33333333 
        you would write 0x55005555.  */ 
    
    /* TSU configuration   */
    cy_str_ethif_TSU_Config stcTSUConfig = 
    {
        .pstcTimerValue    = &stc1588TimerValue,            /* start value for the counter */
        .pstcTimerIncValue = &stc1588TimerIncValue,         /* Increment value for each clock cycle */
        .bOneStepTxSyncEnable = false,                      /* useful when PTP protocol is in place */
        .enTxDescStoreTimeStamp = CEDI_TX_TS_DISABLED,      
        .enRxDescStoreTimeStamp = CEDI_RX_TS_DISABLED,
        .bStoreNSinRxDesc = false,
    };
     
    /* General Ethernet configuration  */
    cy_stc_ethif_configuration_t stcENETConfig = 
    {                    
        .bintrEnable         = 1,                           /* Interrupt enable */
        .dmaDataBurstLen     = CEDI_DMA_DBUR_LEN_4, 
        .u8dmaCfgFlags       = CEDI_CFG_DMA_FRCE_TX_BRST,
        .mdcPclkDiv          = CEDI_MDC_DIV_BY_48,          /* source clock is 80 MHz and MDC must be less than 2.5MHz   */
        .u8rxLenErrDisc      = 0,                           /* Length error frame not discarded  */
        .u8disCopyPause      = 0,                           
        .u8chkSumOffEn       = 0,                           /* Checksum for both Tx and Rx disabled    */
        .u8rx1536ByteEn      = 1,                           /* Enable receive frame up to 1536    */
        .u8rxJumboFrEn       = 0,
        .u8enRxBadPreamble   = 1,
        .u8ignoreIpgRxEr     = 0,
        .u8storeUdpTcpOffset = 0,
        .u8aw2wMaxPipeline   = 2,                           /* Value must be > 0   */
        .u8ar2rMaxPipeline   = 2,                           /* Value must be > 0   */
        .u8pfcMultiQuantum   = 0,
        .pstcWrapperConfig   = &stcWrapperConfig,
        .pstcTSUConfig       = &stcTSUConfig,               /* TSU settings    */
        .btxq0enable         = 1,                           /* Tx Q0 Enabled   */
        .btxq1enable         = 0,                           /* Tx Q1 Disabled  */            
        .btxq2enable         = 0,                           /* Tx Q2 Disabled  */
        .brxq0enable         = 1,                           /* Rx Q0 Enabled   */
        .brxq1enable         = 0,                           /* Rx Q1 Disabled  */
        .brxq2enable         = 0,                           /* Rx Q2 Disabled  */
    };
    
    /* Interrupt configurations */
    cy_stc_ethif_interruptconfig_t stcInterruptConfig = 
    {
        .btsu_time_match        = 0,          /* Time stamp unit time match event */
        .bwol_rx                = 0,          /* Wake on LAN event received */
        .blpi_ch_rx             = 0,          /* LPI indication status bit change received */
        .btsu_sec_inc           = 0,          /* TSU seconds register increment */
        .bptp_tx_pdly_rsp       = 0,          /* PTP pdelay_resp frame transmitted */
        .bptp_tx_pdly_req       = 0,          /* PTP pdelay_req frame transmitted */
        .bptp_rx_pdly_rsp       = 0,          /* PTP pdelay_resp frame received */
        .bptp_rx_pdly_req       = 0,          /* PTP pdelay_req frame received */
        .bptp_tx_sync           = 0,          /* PTP sync frame transmitted */
        .bptp_tx_dly_req        = 0,          /* PTP delay_req frame transmitted */
        .bptp_rx_sync           = 0,          /* PTP sync frame received */
        .bptp_rx_dly_req        = 0,          /* PTP delay_req frame received */
        .bext_intr              = 0,          /* External input interrupt detected */
        .bpause_frame_tx        = 0,          /* Pause frame transmitted */
        .bpause_time_zero       = 0,          /* Pause time reaches zero or zeroq pause frame received */
        .bpause_nz_qu_rx        = 0,          /* Pause frame with non-zero quantum received */
        .bhresp_not_ok          = 0,          /* DMA hresp not OK */
        .brx_overrun            = 1,          /* Rx overrun error */
        .bpcs_link_change_det   = 0,          /* Link status change detected by PCS */
        .btx_complete           = 1,          /* Frame has been transmitted successfully */
        .btx_fr_corrupt         = 1,          /* Tx frame corruption */
        .btx_retry_ex_late_coll = 1,          /* Retry limit exceeded or late collision */
        .btx_underrun           = 1,          /* Tx underrun */
        .btx_used_read          = 1,          /* Used bit set has been read in Tx descriptor list */
        .brx_used_read          = 1,          /* Used bit set has been read in Rx descriptor list */
        .brx_complete           = 1,          /* Frame received successfully and stored */
        .bman_frame             = 0,          /* Management Frame Sent */   
        
        /* call back functions */
        .rxframecb  = Ethx_RxFrameCB,
        .txerrorcb  = NULL,
        .txcompletecb = Ethx_TxFrameSuccessful,     /* Set it to NULL, if do not wish to have callback */
        .tsuSecondInccb = Ethx_TSUIncrement,
    };

    /* Enable Ethernet Interrupts */
    const cy_stc_sysint_irq_t irq_cfg_ethx_q0 = {.sysIntSrc  = ETH_INTR_SRC,    .intIdx  = CPUIntIdx3_IRQn, .isEnabled  = true};
    const cy_stc_sysint_irq_t irq_cfg_ethx_q1 = {.sysIntSrc  = ETH_INTR_SRC_Q1, .intIdx  = CPUIntIdx3_IRQn, .isEnabled  = true};
    const cy_stc_sysint_irq_t irq_cfg_ethx_q2 = {.sysIntSrc  = ETH_INTR_SRC_Q2, .intIdx  = CPUIntIdx3_IRQn, .isEnabled  = true};
    
    Cy_SysInt_InitIRQ(&irq_cfg_ethx_q0);
    Cy_SysInt_SetSystemIrqVector(irq_cfg_ethx_q0.sysIntSrc, Cy_Ethx_InterruptHandler);

    Cy_SysInt_InitIRQ(&irq_cfg_ethx_q1);
    Cy_SysInt_SetSystemIrqVector(irq_cfg_ethx_q1.sysIntSrc, Cy_Ethx_InterruptHandler);

    Cy_SysInt_InitIRQ(&irq_cfg_ethx_q2);
    Cy_SysInt_SetSystemIrqVector(irq_cfg_ethx_q2.sysIntSrc, Cy_Ethx_InterruptHandler);
    
    NVIC_SetPriority(CPUIntIdx3_IRQn, 3);
    NVIC_ClearPendingIRQ(CPUIntIdx3_IRQn);
    NVIC_EnableIRQ(CPUIntIdx3_IRQn);
    
    /* Initialize ENET MAC */
    if (CY_ETHIF_SUCCESS != Cy_EthIf_Init(ETH_REG_BASE, &stcENETConfig, &stcInterruptConfig))
    {
        /* Error */
    }    
    
    /* PHY initialization */
    Cy_Rtl8211f_Init(&rtlPhyHandle, &rtlPhyConfig);
    
    /* Configure the PHY */
    Phy_RTL8211F_Configure();
    
    /* Check for the link status */
    while (true != Cy_Rtl8211f_GetLinkStatus(&rtlPhyHandle));

    /* Load Destination MAC address */
    u8DummyTxBuf[0] =  0xFF;
    u8DummyTxBuf[1] =  0xFF;
    u8DummyTxBuf[2] =  0xFF;
    u8DummyTxBuf[3] =  0xFF;
    u8DummyTxBuf[4] =  0xFF;
    u8DummyTxBuf[5] =  0xFF;
    
    /* Load source MAC address */
    u8DummyTxBuf[6] =  0x02;
    u8DummyTxBuf[7] =  0x00;
    u8DummyTxBuf[8] =  0x00;
    u8DummyTxBuf[9] =  0x00;
    u8DummyTxBuf[10] = 0x00;
    u8DummyTxBuf[11] = 0x02;
    
    /* Load Ethertype */
    u8DummyTxBuf[12] = 0x00;
    u8DummyTxBuf[13] = 0x00;
     
    /* Load Dummy payload */
    for (uint16_t i = 0; i < 1500; i++ )
    {
        u8DummyTxBuf[i + 14] = (uint8_t)i;
    }

    for (uint16_t i = 0; i < 10; i++ )
    {
        checkError = Cy_EthIf_TransmitFrame(ETH_REG_BASE, u8DummyTxBuf, ETH_FRAME_SIZE, CY_ETH_QS0_0, bLastBuffer);
        if (CY_ETHIF_SUCCESS != checkError)
        {
            // Error while transmitting 
            while(1);
        }
        else
        {
            // Frame started transmitting        
        }
        
        /* Free Release Buffer, this routine shall be called at regular interval of time to free "Released" buffers */
        /* Release all Transmit buffer */
        Cy_EthIF_ClearReleasedBuf(bClearAll, bTransmitBuf);
    }
    

    for(;;)
    {
        if (bFrameReceived)
        {
            bFrameReceived = false;
            bFrameTransmit = false;

            /* Transmit Received Frame */
            if (CY_ETHIF_SUCCESS != Cy_EthIf_TransmitFrame(ETH_REG_BASE, u8DummyTxBuf, u16TransmitLength, CY_ETH_QS0_0, bLastBuffer))
            {
                /* Error while transmitting */
            }
            /* Clear all released buffer for both Transmit and Receive */
            Cy_EthIF_ClearReleasedBuf(bClearAll, bTransmitBuf);  
            bTransmitBuf = false;
            Cy_EthIF_ClearReleasedBuf(bClearAll, bTransmitBuf);  
            bTransmitBuf = true;  
        }             
    }
}

/* Callback on frame reception successful */
static void Ethx_RxFrameCB ( cy_pstc_eth_type_t pstcEth, uint8_t * u8RxBuffer, uint32_t u32Length )
{
    bFrameReceived = true;
    
    /* Copy frame to transmit buffer */
    /* Starting from 14, as actual data starts from there. */
    /* Copy function also includes last 4 bytes of CDC     */
    for (uint32_t cntr = 14; cntr < (u32Length - 4); cntr++)
    {
        u8DummyTxBuf[cntr] = u8RxBuffer[cntr];
    }
    
    /* Echo frame will have last 4 bytes of CRC from EMAC CRC generator */
    u16TransmitLength = (uint16_t) (u32Length - 4);
    u16TransmitLength = u16TransmitLength + 64;
    if (u16TransmitLength > 1500)
    {
        u16TransmitLength = 64;
    }
    
    /* Receive buffer should be release to be reused again; done in main while loop along with transmit buffer */
    
    /* Toggle LED */
    Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);        
}

/* Callback on frame transmission successful */
static void Ethx_TxFrameSuccessful ( cy_pstc_eth_type_t pstcEth, uint8_t u8QueueIndex, uint32_t bufIdx)
{
    bFrameTransmit = true;
    u16TransmitLength = u16TransmitLength + 64;
    if (u16TransmitLength > 1500)
    {
        u16TransmitLength = 64;
    }
}

/* TSU One Second Increment Interrupt call back function */
static void Ethx_TSUIncrement ( cy_pstc_eth_type_t pstcEth )
{
    //Cy_GPIO_Inv(USER_LED_PORT, USER_LED_PIN);
}

/*******************************************************************************
* Function Name: Cy_App_Init_EthernetPortpins
****************************************************************************//**
*
* \brief Initializes Ethernet Port Pins. 
* 
* \Note:
*******************************************************************************/
static void Cy_App_Init_EthernetPortpins (void)
{    
    Cy_GPIO_Pin_Init(ETHx_TD0_PORT, ETHx_TD0_PIN, &ethx_tx0);                       /** TX0 */
    Cy_GPIO_Pin_Init(ETHx_TD1_PORT, ETHx_TD1_PIN, &ethx_tx1);                       /** TX1 */
    Cy_GPIO_Pin_Init(ETHx_TD2_PORT, ETHx_TD2_PIN, &ethx_tx2);                       /** TX2 */
    Cy_GPIO_Pin_Init(ETHx_TD3_PORT, ETHx_TD3_PIN, &ethx_tx3);                       /** TX3 */
    Cy_GPIO_Pin_Init(ETHx_TXER_PORT, ETHx_TXER_PIN, &ethx_txer);                    /** TX_ER */
    Cy_GPIO_Pin_Init(ETHx_TX_CTL_PORT, ETHx_TX_CTL_PIN, &ethx_txctl);               /** TX_CTL */
    
    Cy_GPIO_Pin_Init(ETHx_RD0_PORT, ETHx_RD0_PIN, &ethx_rx0);                       /** RX0 */
    Cy_GPIO_Pin_Init(ETHx_RD1_PORT, ETHx_RD1_PIN, &ethx_rx1);                       /** RX1 */
    Cy_GPIO_Pin_Init(ETHx_RD2_PORT, ETHx_RD2_PIN, &ethx_rx2);                       /** RX2 */
    Cy_GPIO_Pin_Init(ETHx_RD3_PORT, ETHx_RD3_PIN, &ethx_rx3);                       /** RX3 */
    Cy_GPIO_Pin_Init(ETHx_RX_CTL_PORT, ETHx_RX_CTL_PIN, &ethx_rxctl);               /** RX_CTL */
    //Cy_GPIO_Pin_Init(ETHx_RX_ER_PORT, ETHx_RX_ER_PIN, &ethx_rxer);                  /** RX_ER */
    
    Cy_GPIO_Pin_Init(ETHx_TX_CLK_PORT, ETHx_TX_CLK_PIN, &ethx_txclk);               /** TX_CLK */
    Cy_GPIO_Pin_Init(ETHx_RX_CLK_PORT, ETHx_RX_CLK_PIN, &ethx_rxclk);               /** RX_CLK */
    Cy_GPIO_Pin_Init(ETHx_REF_CLK_PORT, ETHx_REF_CLK_PIN, &ethx_refclk);            /** REFCLK */
    
    Cy_GPIO_Pin_Init(ETHx_MDC_PORT,  ETHx_MDC_PIN, &ethx_mdc);                      /** MDC */
    Cy_GPIO_Pin_Init(ETHx_MDIO_PORT, ETHx_MDIO_PIN, &ethx_mdio);                    /** MDIO */
}

/*******************************************************************************
* Function Name: Phy_RTL8211F_Configure
****************************************************************************//**
*
* \brief Dedicated to configure the RTL8211F PHY.
* Function configures the PHY with 10 Mbps link speed, full duplex communication and Auto Negotiation off
*
* \Note:
* If hardware consist of any other PHY than DP83867IR, dedicated function shall be written to configure relevant 
* registers in side PHY
*******************************************************************************/
static void Phy_RTL8211F_Configure(void)
{
    uint16_t linkSpeed = 0, linkMode = 0;
    
    /* Check for the auto negotiation complete  */
    if (Cy_Rtl8211f_IsAutonegotiationEnabled(&rtlPhyHandle))
    {
        while(Cy_Rtl8211f_IsAutonegotiationDone(&rtlPhyHandle) == false);
    }
    
    /* Check the link speed and mode */
    linkSpeed = Cy_Rtl8211f_GetLinkSpeed(&rtlPhyHandle);
    linkMode = Cy_Rtl8211f_GetLinkMode(&rtlPhyHandle);
    
    /* Check the receiver is ok if 1000mbps link */
    if (linkSpeed == ETH_PHY_LINK_SPEED_1000M)
    {
        while (Cy_Rtl8211f_IsRemoteReceiverOk(&rtlPhyHandle) == false);
    }
    
    /* Configure the link LEDs */
    Cy_Rtl8211f_ConfigureLeds(&rtlPhyHandle);
}


/* [] END OF FILE */
