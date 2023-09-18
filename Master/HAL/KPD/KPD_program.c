/*
 *
 *<<<<<<<<<<<<<<<<<<<<<KPD_PROGRAM.c>>>>>>>>>>>>>>>>>>>>>
 * Author : ALIAA ESLAM ZAYED
 * Created: 18 /8/2023
 * Layer  : HAL
 * SWC    : KPD
 *
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/DIO/DIO_private.h"

#include "KPD_interface.h"
#include "KPD_config.h"

#include <avr/delay.h>

void HKPD_voidInitialization(void)
{
	/*******************1- Connect pullup of the first four pins "ROW"*************************************/
	MDIO_voidSetPinDirection( KPD_PORT, KPD_ROW_PIN0, DIO_PIN_INPUT);
	MDIO_voidSetPinDirection( KPD_PORT, KPD_ROW_PIN1, DIO_PIN_INPUT);
	MDIO_voidSetPinDirection( KPD_PORT, KPD_ROW_PIN2, DIO_PIN_INPUT);
	MDIO_voidSetPinDirection( KPD_PORT, KPD_ROW_PIN3, DIO_PIN_INPUT);

	MDIO_voidSetPinValue( KPD_PORT, KPD_ROW_PIN0, DIO_PIN_HIGH);
	MDIO_voidSetPinValue( KPD_PORT, KPD_ROW_PIN1, DIO_PIN_HIGH);
	MDIO_voidSetPinValue( KPD_PORT, KPD_ROW_PIN2, DIO_PIN_HIGH);
	MDIO_voidSetPinValue( KPD_PORT, KPD_ROW_PIN3, DIO_PIN_HIGH);

	/*********************2- Make the columns pins as an output pin****************************************/ 
	MDIO_voidSetPinDirection( KPD_PORT, KPD_COL_PIN4, DIO_PIN_OUTPUT);
	MDIO_voidSetPinDirection( KPD_PORT, KPD_COL_PIN5, DIO_PIN_OUTPUT);
	MDIO_voidSetPinDirection( KPD_PORT, KPD_COL_PIN6, DIO_PIN_OUTPUT);
	MDIO_voidSetPinDirection( KPD_PORT, KPD_COL_PIN7, DIO_PIN_OUTPUT);

	MDIO_voidSetPinValue( KPD_PORT, KPD_COL_PIN4, DIO_PIN_HIGH);
	MDIO_voidSetPinValue( KPD_PORT, KPD_COL_PIN5, DIO_PIN_HIGH);
	MDIO_voidSetPinValue( KPD_PORT, KPD_COL_PIN6, DIO_PIN_HIGH);
	MDIO_voidSetPinValue( KPD_PORT, KPD_COL_PIN7, DIO_PIN_HIGH);

}

u8 HKPD_u8GetPressedKey(void)
{
	u8 LOC_u8ReturnDatat= NOT_PRESSED;
	u8 LOC_u8GetPressed;
	u8 LOC_u8Col;
	u8 LOC_u8Row;

	for(LOC_u8Col=0+ KPD_COL_PIN4; LOC_u8Col<1+ KPD_COL_PIN7; LOC_u8Col++)
	{
		MDIO_voidSetPinValue(KPD_PORT, LOC_u8Col, DIO_PIN_LOW);
		for(LOC_u8Row=0+ KPD_ROW_PIN0; LOC_u8Row<1+KPD_ROW_PIN3; LOC_u8Row++)
		{
			MDIO_voidGetPinValue(KPD_PORT, LOC_u8Row, &LOC_u8GetPressed);
			if(LOC_u8GetPressed==0)
			{
				_delay_ms(100);
				MDIO_voidGetPinValue(KPD_PORT, LOC_u8Row, &LOC_u8GetPressed);
				if( LOC_u8GetPressed==DIO_PIN_LOW)
				{
					LOC_u8ReturnDatat= KPD_u8Button[LOC_u8Row - KPD_ROW_PIN0][LOC_u8Col - KPD_COL_PIN4];
				}
				MDIO_voidGetPinValue(KPD_PORT, LOC_u8Row, &LOC_u8GetPressed);
				while( DIO_PIN_LOW == LOC_u8GetPressed )
				{

					MDIO_voidGetPinValue( KPD_PORT , LOC_u8Row , &LOC_u8GetPressed );

				}

				break ;
			}
		}
		MDIO_voidSetPinValue(KPD_PORT, LOC_u8Col, DIO_PIN_HIGH);
	}
	return LOC_u8ReturnDatat;

}
