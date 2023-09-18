/*
*
*<<<<<<<<<<<<<<<<<<<<<DIO_PROGRAM.c>>>>>>>>>>>>>>>>>>>>>
* Author : ALIAA ESLAM ZAYED
* Created: 13 /8/2023
* Layer  : MCAL
* SWC    : DIO /GPIO
*
*/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"

void MDIO_voidSetPinDirection (u8 A_u8PortNo , u8 A_u8PinNo , u8 A_u8PinDirection)
{

	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((A_u8PortNo <= DIO_PORTD) && (A_u8PinNo <= DIO_PIN7))
	{
		if ( A_u8PinDirection == DIO_PIN_OUTPUT )
		{
			/* Check on the Required PORT Number */
			switch (A_u8PortNo)
			{
			case DIO_PORTA: SET_BIT(DDRA_Register,A_u8PinNo); break;
			case DIO_PORTB: SET_BIT(DDRB_Register,A_u8PinNo); break;
			case DIO_PORTC: SET_BIT(DDRC_Register,A_u8PinNo); break;
			case DIO_PORTD: SET_BIT(DDRD_Register,A_u8PinNo); break;
			}
		}

		else if ( A_u8PinDirection == DIO_PIN_INPUT )
		{
			/* Check on the Required PORT Number */
			switch (A_u8PortNo)
			{
			case DIO_PORTA: CLR_BIT(DDRA_Register,A_u8PinNo); break;
			case DIO_PORTB: CLR_BIT(DDRB_Register,A_u8PinNo); break;
			case DIO_PORTC: CLR_BIT(DDRC_Register,A_u8PinNo); break;
			case DIO_PORTD: CLR_BIT(DDRD_Register,A_u8PinNo); break;
			}
		}
	}
}

void MDIO_voidSetPinValue (u8 A_u8PortNo , u8 A_u8PinNo  , u8 A_u8Value )
{	
		if(A_u8Value==DIO_PIN_HIGH)
		{
			switch (A_u8PortNo)
			{
			case DIO_PORTA: SET_BIT(PORTA,A_u8PinNo); break;
			case DIO_PORTB: SET_BIT(PORTB,A_u8PinNo); break;
			case DIO_PORTC: SET_BIT(PORTC,A_u8PinNo); break;
			case DIO_PORTD: SET_BIT(PORTD,A_u8PinNo); break;
			}
		}
		else if(A_u8Value==DIO_PIN_LOW)
		{
			switch (A_u8PortNo)
			{
			case DIO_PORTA: CLR_BIT(PORTA,A_u8PinNo); break;
			case DIO_PORTB: CLR_BIT(PORTB,A_u8PinNo); break;
			case DIO_PORTC: CLR_BIT(PORTC,A_u8PinNo); break;
			case DIO_PORTD: CLR_BIT(PORTD,A_u8PinNo); break;
			}
		}
}

void MDIO_voidClrPinValue (u8 A_u8PortNo , u8 A_u8PinNo )
{
	switch (A_u8PortNo)
			{
			case DIO_PORTA: CLR_BIT(PORTA,A_u8PinNo); break;
			case DIO_PORTB: CLR_BIT(PORTB,A_u8PinNo); break;
			case DIO_PORTC: CLR_BIT(PORTC,A_u8PinNo); break;
			case DIO_PORTD: CLR_BIT(PORTD,A_u8PinNo); break;
			}
}

void MDIO_voidGetPinValue (u8 A_u8PortNo , u8 A_u8PinNo  , u8 * A_PtrData )
{
	switch (A_u8PortNo)
			{
			case DIO_PORTA: *A_PtrData=GET_BIT(PINA,A_u8PinNo); break;
			case DIO_PORTB: *A_PtrData=GET_BIT(PINB,A_u8PinNo); break;
			case DIO_PORTC: *A_PtrData=GET_BIT(PINC,A_u8PinNo); break;
			case DIO_PORTD: *A_PtrData=GET_BIT(PIND,A_u8PinNo); break;
			}
}

void MDIO_voidTogglePinValue (u8 A_u8PortNo , u8 A_u8PinNo)
{
	switch (A_u8PortNo)
			{
			case DIO_PORTA: TOG_BIT(PORTA,A_u8PinNo); break;
			case DIO_PORTB: TOG_BIT(PORTB,A_u8PinNo); break;
			case DIO_PORTC: TOG_BIT(PORTC,A_u8PinNo); break;
			case DIO_PORTD: TOG_BIT(PORTD,A_u8PinNo); break;
			}
}


void MDIO_voidSetPortDirection (u8 A_u8PortNo , u8 A_u8PinDirection)
{
	switch (A_u8PortNo)
			{
			case DIO_PORTA: DDRA_Register= A_u8PinDirection; break;
			case DIO_PORTB: DDRB_Register= A_u8PinDirection; break;
			case DIO_PORTC: DDRC_Register= A_u8PinDirection; break;
			case DIO_PORTD: DDRD_Register= A_u8PinDirection; break;
			}
}

void MDIO_voidSetPortValue   (u8 A_u8PortNo  , u8 A_u8Value)
{
	switch (A_u8PortNo)
			{
			case DIO_PORTA: PORTA= A_u8Value; break;
			case DIO_PORTB: PORTB= A_u8Value; break;
			case DIO_PORTC: PORTC= A_u8Value; break;
			case DIO_PORTD: PORTD= A_u8Value; break;
			}
}

void MDIO_voidClrPortValue (u8 A_u8PortNo)
{
	switch (A_u8PortNo)
			{
			case DIO_PORTA: PORTA= DIO_PORT_LOW; break;
			case DIO_PORTB: PORTB= DIO_PORT_LOW; break;
			case DIO_PORTC: PORTC= DIO_PORT_LOW; break;
			case DIO_PORTD: PORTD= DIO_PORT_LOW; break;
			}
}

void MDIO_voidGetPortValue (u8 A_u8PortNo  , u8 * A_PtrData )
{
	switch (A_u8PortNo)
			{
			case DIO_PORTA: *A_PtrData= DIO_PINA; break;
			case DIO_PORTB: *A_PtrData= DIO_PINB; break;
			case DIO_PORTC: *A_PtrData= DIO_PINC; break;
			case DIO_PORTD: *A_PtrData= DIO_PIND; break;
			}
}

void MDIO_voidTogglePortValue (u8 A_u8PortNo)
{
		switch (A_u8PortNo)
			{
			case DIO_PORTA: PORTA =~ PORTA; break;
			case DIO_PORTB: PORTB =~ PORTB; break;
			case DIO_PORTC: PORTC =~ PORTC; break;
			case DIO_PORTD: PORTD =~ PORTD; break;
			}
}
void MDIO_voidWriteHighNibbles ( u8 A_u8PORT , u8 A_u8value  )
{
	switch(A_u8PORT)
		{
		case DIO_PORTA :
			PORTA&=0x0f;                   // make sure the high bits = 0000
			PORTA|=A_u8value;			//Set only the high nibble of the port A by the given value
			break ;
		case DIO_PORTB:
			PORTB&=0x0f;                 //Set only the high nibble of the port B by the given value
			PORTB|=A_u8value;
			break ;
		case DIO_PORTC :
			PORTC&=0x0f;                 //Set only the high nibble of the port C by the given value
			PORTC|=A_u8value;
			break ;
		case DIO_PORTD:
			PORTD&=0x0f;                 //Set only the high nibble of the port D by the given value
			PORTD|=A_u8value;
			break ;
		}
}
void MDIO_voidWriteLowNibbles  ( u8 A_u8PORT , u8 A_u8value )
{
	switch(A_u8PORT)
		{
		case DIO_PORTA :
			PORTA&=0xf0;                   // make sure the low bits = 0000
			PORTA|=A_u8value;			//Set only the low nibble of the port A by the given value
			break ;
		case DIO_PORTB:
			PORTB&=0xf0;                 //Set only the low nibble of the port B by the given value
			PORTB|=A_u8value;
			break ;
		case DIO_PORTC :
			PORTC&=0xf0;                 //Set only the low nibble of the port C by the given value
			PORTC|=A_u8value;
			break ;
		case DIO_PORTD:
			PORTD&=0xf0;                 //Set only the low nibble of the port D by the given value
			PORTD|=A_u8value;
			break ;
		}
}
