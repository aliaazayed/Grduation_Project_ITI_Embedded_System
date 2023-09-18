
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/DIO/DIO_config.h"
#include "../MCAL/DIO/DIO_private.h"

#include "../MCAL/UART/UART_interface.h"
#include "../MCAL/UART/UART_config.h"

#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/ADC/ADC_config.h"

#include "../HAL/CLCD/CLCD_interface.h"
#include "../HAL/CLCD/CLCD_config.h"
#include "../HAL/CLCD/CLCD_private.h"

#include "../HAL/LED/LED_interface.h"

#include "../HAL/STEPPER_MOTOR/STEPPER_config.h"
#include "../HAL/STEPPER_MOTOR/STEPPER_interface.h"

#include "avr/delay.h"

int main()
{
	/***************************** COMMUNICATION PROTOCOL  *******************************/
	MUART_voidInitialization();
	/*******************  ENTRY GATE & EXIT GATE ****************************************/
	u8 Car_Arr[]={0b00110,0b00110,0b01111,0b01110,0b01110,0b01111,0b01110,0b00000};
	u8 LOC_u8Col=0,LOC_u8In, LOC_u8Out, LOC_u8Iterator=0;;
	CLCD_voidInitialization();
	MDIO_voidSetPinDirection(DIO_PORTC, DIO_PIN0, DIO_PIN_OUTPUT);
	MDIO_voidSetPinDirection(DIO_PORTC, DIO_PIN1, DIO_PIN_OUTPUT);
	MDIO_voidSetPinDirection(DIO_PORTC, DIO_PIN2, DIO_PIN_OUTPUT);
	MDIO_voidSetPinDirection(DIO_PORTC, DIO_PIN3, DIO_PIN_OUTPUT);

	/*----------------------------------------------------------------------------------*/

	/*************** Push Bottom For lightening the leds ********************************/
	u8 LOC_u8Buffer=1;
	MDIO_voidSetPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);
	MDIO_voidSetPinDirection(DIO_PORTD,DIO_PIN4,DIO_PIN_INPUT);
	/*----------------------------------------------------------------------------------*/

	/*********************** Temperature MOde *******************************************/
	f32 LOC_f32ReadLM;
	MADC_voidInitialization();
	MDIO_voidSetPinDirection(DIO_PORTA, DIO_PIN4, DIO_PIN_OUTPUT);
	/*---------------------------------------------------------------------------------*/

	while(1)
	{
		CLCD_voidSendNumber(8-LOC_u8Col) ;
		CLCD_voidSendString(" Free Spaces");

		u8 LOC_u8Receive = MUART_voidRecieveData();

		_delay_ms(250);
		while (LOC_u8Receive == 's')
		{
			/*************************** Entry Geta *****************************************/
			for(LOC_u8Iterator=0; LOC_u8Iterator<=LOC_u8Col; LOC_u8Iterator++)
			{
				HLCD_voidDispSpecialChar(Car_Arr, 1, CLCD_ROW_2, LOC_u8Iterator);
			}

			MDIO_voidGetPinValue(DIO_PORTD, DIO_PIN2,&LOC_u8In);

			LOC_u8Receive = MUART_voidRecieveData();
		}
		if (LOC_u8In==1)
		{
			CLCD_voidClearScreen();
			CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COLUMN_1);
			LOC_u8Col++;
			if(LOC_u8Col== 9)
			{
				CLCD_voidSendString("Garage is full");
				LOC_u8Col=8;
			}
			else{
				CLCD_voidSendNumber(8-LOC_u8Col) ;
				CLCD_voidSendString(" Free Spaces");
				for(LOC_u8Iterator=0; LOC_u8Iterator<=LOC_u8Col; LOC_u8Iterator++)
				{
					HLCD_voidDispSpecialChar(Car_Arr, 1, CLCD_ROW_2, LOC_u8Iterator);
				}
				MDIO_voidSetPinValue(DIO_PORTC, DIO_PIN1, DIO_PIN_HIGH);
				_delay_ms(100);
				MDIO_voidSetPinValue(DIO_PORTC, DIO_PIN1, DIO_PIN_LOW);
				while(LOC_u8In==1)
				{
					MDIO_voidGetPinValue(DIO_PORTD, DIO_PIN2,&LOC_u8In);
				}
				MDIO_voidSetPinValue(DIO_PORTC, DIO_PIN0, DIO_PIN_HIGH);
				_delay_ms(100);
				MDIO_voidSetPinValue(DIO_PORTC, DIO_PIN0, DIO_PIN_LOW);

			}
		}


		/*************************** Exit Geta *****************************************/
		MDIO_voidGetPinValue(DIO_PORTD, DIO_PIN3,&LOC_u8Out);
		if (LOC_u8Out==1)
		{
			LOC_u8Col--;
			CLCD_voidClearScreen();
			CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COLUMN_1);

			CLCD_voidSendNumber(8-LOC_u8Col) ;
			CLCD_voidSendString(" Free Spaces");
			for(LOC_u8Iterator=0; LOC_u8Iterator<=LOC_u8Col; LOC_u8Iterator++)
			{
				HLCD_voidDispSpecialChar(Car_Arr, 1, CLCD_ROW_2, LOC_u8Iterator);
			}
			MDIO_voidSetPinValue(DIO_PORTC, DIO_PIN3, DIO_PIN_HIGH);
			_delay_ms(100);
			MDIO_voidSetPinValue(DIO_PORTC, DIO_PIN3, DIO_PIN_LOW);
			while(LOC_u8Out==1)
			{
				MDIO_voidGetPinValue(DIO_PORTD, DIO_PIN3,&LOC_u8Out);
			}
			MDIO_voidSetPinValue(DIO_PORTC, DIO_PIN2, DIO_PIN_HIGH);
			_delay_ms(100);
			MDIO_voidSetPinValue(DIO_PORTC, DIO_PIN2, DIO_PIN_LOW);
		}

		/*************************** 1- Lightening Mode **********************************/
		MDIO_voidGetPinValue(DIO_PORTD, DIO_PIN4,&LOC_u8Buffer);
		if (LOC_u8Buffer==0)
		{
			_delay_ms(20);
			if(LOC_u8Buffer==0){
				MDIO_voidSetPinValue(DIO_PORTA, DIO_PIN5,DIO_PIN_HIGH);
				MDIO_voidGetPinValue(DIO_PORTD, DIO_PIN4,&LOC_u8Buffer);
				_delay_ms(100);
			}

		}
		else if(LOC_u8Buffer==1)
		{
			_delay_ms(20);
			if(LOC_u8Buffer==1){
				MDIO_voidSetPinValue(DIO_PORTA, DIO_PIN5,DIO_PIN_LOW);
				MDIO_voidGetPinValue(DIO_PORTD, DIO_PIN4,&LOC_u8Buffer);
				_delay_ms(100);
			}
		}
		
		/********************************3- Temperature Mode ***********************************/
		LOC_f32ReadLM=MADC_f32LDRSensor(ADC_CHANNEL0);
		if(LOC_f32ReadLM>=30)
		{
			MDIO_voidSetPinValue(DIO_PORTA, DIO_PIN4, DIO_PIN_HIGH);
			CLCD_voidClearScreen();
			CLCD_voidSendString("The temp: ");
			CLCD_voidSetPosition(CLCD_ROW_1,11);
			CLCD_voidSendNumber(LOC_f32ReadLM);
			_delay_ms(100);
			CLCD_voidSetPosition(CLCD_ROW_1, CLCD_COLUMN_1);
		}
		else
		{
			CLCD_voidClearScreen();
			MDIO_voidSetPinValue(DIO_PORTA, DIO_PIN4, DIO_PIN_LOW);
			CLCD_voidSendString("The temp: ");
			CLCD_voidSetPosition(CLCD_ROW_1,11);
			CLCD_voidSendNumber(LOC_f32ReadLM);
			_delay_ms(100);
			CLCD_voidSetPosition(CLCD_ROW_1, CLCD_COLUMN_1);
		}

	}

	return 0;
}
