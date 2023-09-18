/*
*
*<<<<<<<<<<<<<<<<<<<<<LED_PROGRAM.c>>>>>>>>>>>>>>>>>>>>>
* Author : ALIAA ESLAM ZAYED
* Created: 14 /8/2023
* Layer  : HAL
* SWC    : LED
*
*/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/DIO/DIO_private.h"


#include "LED_interface.h"


void HLED_voidLEDIntialization(LED_CONFIG LED)
{
	MDIO_voidSetPinDirection (LED.port , LED.pin , LED.activeMode);

}

void HLED_voidLEDOn(LED_CONFIG LED)
{
	 MDIO_voidSetPinValue (LED.port , LED.pin , LED_ACTIVE_HIGH);
}

void HLED_voidLEDIOff(LED_CONFIG LED)
{
	 MDIO_voidSetPinValue (LED.port , LED.pin , LED_ACTIVE_LOW);
}

void HLED_voidLEDToggle(LED_CONFIG LED)
{
	MDIO_voidTogglePinValue (LED.port , LED.pin);
}
	
