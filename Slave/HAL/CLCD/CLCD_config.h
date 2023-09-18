/*
 *
 *<<<<<<<<<<<<<<<<<<<<<CLCD_CONFIG_H_>>>>>>>>>>>>>>>>>>>>>>>>
 * Author : ALIAA ESLAM ZAYED
 * Created: 18 /8/2023
 * Layer  : HAL
 * SWC    : CLCD
 *
 */
 
 #ifndef CLCD_CONFIG_H_
 #define CLCD_CONFIG_H_
 
#define CLCD_DATA_PORT     DIO_PORTB    /**** We Can choose *DIO_PORTA
														    *DIO_PORTB
														    *DIO_PORTC
														    *DIO_PORTD *****/

#define CLCD_CONTROL_PORT  DIO_PORTA    /**** We Can choose *DIO_PORTA
														    *DIO_PORTB
														    *DIO_PORTC
														    *DIO_PORTD *****/
														    

#define CLCD_MODE   EIGHT_BIT_MODE      /**** We Can choose *EIGHT_BIT_MODE       
														    *FOUR_BIT_MODE *****/


/**** We Can choose *CLCD_PIN0      
				    *CLCD_PIN1
				    *CLCD_PIN2
				    *CLCD_PIN3
					*CLCD_PIN4
					*CLCD_PIN5
					*CLCD_PIN6
					*CLCD_PIN7 *****/
#define CLCD_RS_PIN  CLCD_PIN1
#define CLCD_RW_PIN  CLCD_PIN2
#define CLCD_EN_PIN  CLCD_PIN3
 
 #endif
