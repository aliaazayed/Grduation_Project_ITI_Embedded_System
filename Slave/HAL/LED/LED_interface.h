/*
*
*<<<<<<<<<<<<<<<<<<<<<LED_INTERFACE_H_>>>>>>>>>>>>>>>>>>>>>>>>
* Author : ALIAA ESLAM ZAYED
* Created: 14 /8/2023
* Layer  : HAL
* SWC    : LED
*
*/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_



/** PORT Defines****/
#define LED_PORTA  DIO_PORTA
#define LED_PORTB  DIO_PORTB
#define LED_PORTC  DIO_PORTC
#define LED_PORTD  DIO_PORTD


/** PIN Defines****/
#define LED_PIN0  DIO_PIN0
#define LED_PIN1  DIO_PIN1
#define LED_PIN2  DIO_PIN2
#define LED_PIN3  DIO_PIN3
#define LED_PIN4  DIO_PIN4
#define LED_PIN5  DIO_PIN5
#define LED_PIN6  DIO_PIN6
#define LED_PIN7  DIO_PIN7


/** LED MODE*****/
#define LED_ACTIVE_HIGH   DIO_PIN_HIGH
#define LED_ACTIVE_LOW    DIO_PIN_LOW	


typedef struct
{
	u8 port;
	u8 pin ;
    u8 activeMode;
}LED_CONFIG;

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Functions >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/


/**
	Function Name        : HLED_voidLEDIntialization
	Function Returns     : void
	Function Arguments   : LED
	Function Description : Intialize the given pin in the given port as an output pin
*/
void HLED_voidLEDIntialization(LED_CONFIG LED);	

/*
	Function Name        : HLED_voidLEDOn
	Function Returns     : void
	Function Arguments   : LED
	Function Description :  Set the pin to be high to make led on
*/
void HLED_voidLEDOn(LED_CONFIG LED);

/**
	Function Name        : HLED_voidLEDIntialization
	Function Returns     : void
	Function Arguments   : LED
	Function Description : Clear the pin with low to make led off
*/
void HLED_voidLEDIOff(LED_CONFIG LED);	

/**
	Function Name        : HLED_voidLEDIntialization
	Function Returns     : void
	Function Arguments   : LED
	Function Description : Toggle the pin value
*/
void HLED_voidLEDToggle(LED_CONFIG LED);	

	


#endif
