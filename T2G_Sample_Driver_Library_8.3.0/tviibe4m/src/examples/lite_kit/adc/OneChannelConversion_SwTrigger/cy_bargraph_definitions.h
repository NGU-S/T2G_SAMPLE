#ifndef CY_BARGRAPH_DEFINITIONS_H
#define CY_BARGRAPH_DEFINITIONS_H

#include "cy_device_headers.h"

#define NUMBER_OF_BARGRAPH_LEDS    3

#define GET_NR_OF_ACTIVE_LEDS_FROM_PERCENT(percent)      ((percent) / (100UL / NUMBER_OF_BARGRAPH_LEDS))

#define SET_BARGRAPH_PERCENT(percent)   do {                                                                                            \
                                            uint8_t u8NrOfActiveLeds = GET_NR_OF_ACTIVE_LEDS_FROM_PERCENT(percent);                     \
                                            Cy_GPIO_Write(BARGRAPH_LED_A_PORT, BARGRAPH_LED_A_PIN, (u8NrOfActiveLeds >=  1) ? 0 : 1);   \
                                            Cy_GPIO_Write(BARGRAPH_LED_B_PORT, BARGRAPH_LED_B_PIN, (u8NrOfActiveLeds >=  2) ? 0 : 1);   \
                                            Cy_GPIO_Write(BARGRAPH_LED_C_PORT, BARGRAPH_LED_C_PIN, (u8NrOfActiveLeds >=  3) ? 0 : 1);   \
                                        } while(0)


// The LEDs on the T2G lite kit board shall serve as a bargraph consisting of 3 LEDs
#define BARGRAPH_LED_A_PORT           CY_CB_LED_PORT
#define BARGRAPH_LED_A_PIN            CY_CB_LED_PIN
#define BARGRAPH_LED_A_PIN_MUX        CY_CB_LED_PIN_MUX

#define BARGRAPH_LED_B_PORT           CY_CB_LED2_PORT
#define BARGRAPH_LED_B_PIN            CY_CB_LED2_PIN
#define BARGRAPH_LED_B_PIN_MUX        CY_CB_LED2_PIN_MUX

#define BARGRAPH_LED_C_PORT           CY_CB_LED3_PORT
#define BARGRAPH_LED_C_PIN            CY_CB_LED3_PIN
#define BARGRAPH_LED_C_PIN_MUX        CY_CB_LED3_PIN_MUX




#endif // CY_BARGRAPH_DEFINITIONS_H


#ifdef ENABLE_VARIABLE_DEFINITION

cy_stc_gpio_pin_config_t bargraph_led_a_port_pin_cfg =             
{                                                  
    .outVal = 0x00,                                
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,    
    .hsiom = BARGRAPH_LED_A_PIN_MUX,                           
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


cy_stc_gpio_pin_config_t bargraph_led_b_port_pin_cfg =             
{                                                  
    .outVal = 0x00,                                
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,    
    .hsiom = BARGRAPH_LED_B_PIN_MUX,                           
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


cy_stc_gpio_pin_config_t bargraph_led_c_port_pin_cfg =             
{                                                  
    .outVal = 0x00,                                
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,    
    .hsiom = BARGRAPH_LED_C_PIN_MUX,                           
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




#endif // ENABLE_VARIABLE_DEFINITION


