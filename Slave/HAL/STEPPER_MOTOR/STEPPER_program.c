/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    STEPPER_PROGRAM.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Aliaa Eslam Zayed
 *  Created: 27/ 8/ 2023
 *  Layer  : HAL
 *  SWC    : STEPPER_MOTOR
 *
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/DIO/DIO_config.h"
#include "STEPPER_interface.h"
#include "STEPPER_config.h"

#include"avr/delay.h"



void HSTEPER_voidOnCWS(STEPPER_CONFIG S)
{
	/**** Init*****/
	MDIO_voidSetPinDirection( S.port, S.pin0  , DIO_PIN_OUTPUT);
	MDIO_voidSetPinDirection( S.port, S.pin1  , DIO_PIN_OUTPUT);
	MDIO_voidSetPinDirection( S.port, S.pin2  , DIO_PIN_OUTPUT);
	MDIO_voidSetPinDirection( S.port, S.pin3  , DIO_PIN_OUTPUT);

	MDIO_voidSetPinValue( S.port, S.pin0  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( S.port, S.pin1  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( S.port, S.pin2  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( S.port, S.pin3  , DIO_PIN_LOW);

	/**** CW***/
	MDIO_voidSetPinValue( S.port, S.pin0  , DIO_PIN_HIGH);
	MDIO_voidSetPinValue( S.port, S.pin1  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( S.port, S.pin2  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( S.port, S.pin3  , DIO_PIN_LOW);
	_delay_ms(50 );

	MDIO_voidSetPinValue( S.port, S.pin0  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( S.port, S.pin1  , DIO_PIN_HIGH);
	MDIO_voidSetPinValue( S.port, S.pin2  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( S.port, S.pin3  , DIO_PIN_LOW);
	_delay_ms( 50 );

	MDIO_voidSetPinValue( S.port, S.pin0  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( S.port, S.pin1  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( S.port, S.pin2  , DIO_PIN_HIGH);
	MDIO_voidSetPinValue( S.port, S.pin3  , DIO_PIN_LOW);
	_delay_ms(50 );
	MDIO_voidSetPinValue( S.port, S.pin0  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( S.port, S.pin1  , DIO_PIN_HIGH);
	MDIO_voidSetPinValue( S.port, S.pin2  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( S.port, S.pin3  , DIO_PIN_LOW);
	_delay_ms( 50 );
	MDIO_voidSetPinValue( S.port, S.pin0  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( S.port, S.pin1  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( S.port, S.pin2  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( S.port, S.pin3  , DIO_PIN_HIGH);
	_delay_ms( 50 );
	MDIO_voidSetPinValue( S.port, S.pin0  , DIO_PIN_HIGH);
	MDIO_voidSetPinValue( S.port, S.pin1  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( S.port, S.pin2  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( S.port, S.pin3  , DIO_PIN_LOW);
	_delay_ms(50 );

}


void HSTEPER_voidOnCCWS(STEPPER_CONFIG S)
{
	/**** Init*****/
	MDIO_voidSetPinDirection( S.port, S.pin0  , DIO_PIN_OUTPUT);
	MDIO_voidSetPinDirection( S.port, S.pin1  , DIO_PIN_OUTPUT);
	MDIO_voidSetPinDirection( S.port, S.pin2  , DIO_PIN_OUTPUT);
	MDIO_voidSetPinDirection( S.port, S.pin3  , DIO_PIN_OUTPUT);

	MDIO_voidSetPinValue( S.port, S.pin0  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( S.port, S.pin1  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( S.port, S.pin2  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( S.port, S.pin3  , DIO_PIN_LOW);

	/**** CCW***/
	MDIO_voidSetPinValue( S.port, S.pin0  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( S.port, S.pin1  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( S.port, S.pin2  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( S.port, S.pin3  , DIO_PIN_HIGH);
	_delay_ms( 50 );


	MDIO_voidSetPinValue( S.port, S.pin0  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( S.port, S.pin1  , DIO_PIN_HIGH);
	MDIO_voidSetPinValue( S.port, S.pin2  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( S.port, S.pin3  , DIO_PIN_LOW);
	_delay_ms( 50 );

	MDIO_voidSetPinValue( S.port, S.pin0  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( S.port, S.pin1  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( S.port, S.pin2  , DIO_PIN_HIGH);
	MDIO_voidSetPinValue( S.port, S.pin3  , DIO_PIN_LOW);
	_delay_ms(50 );
	MDIO_voidSetPinValue( S.port, S.pin0  , DIO_PIN_HIGH);
	MDIO_voidSetPinValue( S.port, S.pin1  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( S.port, S.pin2  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( S.port, S.pin3  , DIO_PIN_LOW);
	_delay_ms(50 );

}


void HSTEPPER_voidInitialization( void )
{
	MDIO_voidSetPinDirection( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_OUTPUT);
	MDIO_voidSetPinDirection( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_OUTPUT);
	MDIO_voidSetPinDirection( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_OUTPUT);
	MDIO_voidSetPinDirection( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_OUTPUT);

	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_LOW);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_LOW);

}
void HSTEPER_voidOnCW(void)
{
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_HIGH);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_LOW);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_LOW);
	_delay_ms(50 );

	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_HIGH);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_LOW);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_LOW);
	_delay_ms( 50 );

	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_HIGH);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_LOW);
	_delay_ms(50 );
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_HIGH);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_LOW);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_LOW);
	_delay_ms( 50 );
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_LOW);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_HIGH);
	_delay_ms( 50 );
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_HIGH);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_LOW);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_LOW);
	_delay_ms(50 );
}


void HSTEPER_voidOnCCW(void)
{
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_LOW);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_HIGH);
	_delay_ms( 100 );
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_HIGH);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_LOW);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_LOW);
	_delay_ms( 100 );
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_HIGH);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_LOW);
	_delay_ms(100 );

	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_HIGH);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_LOW);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_LOW);
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_LOW);
	_delay_ms(100 );

}




void HSTEPPER_voidOn  ( u8 Copy_u8StepType , u8 Copy_u8Direction , u8 Copy_u8Speed , u16 Copy_u16Degree ){

	u32 LOC_u16Iterator = 0 ;

	if( Copy_u8StepType == STEPPER_FULL_STEP ){

		if( Copy_u8Direction == STEPPER_CLOCK_WISE ){

			for( LOC_u16Iterator = 0 ; LOC_u16Iterator < ( ( (u32)Copy_u16Degree * 256 ) / 45 ) / 4 ; LOC_u16Iterator++  ){

				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_HIGH);
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_LOW);
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_LOW);
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_LOW);
				_delay_ms( Copy_u8Speed );

				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_LOW);
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_HIGH);
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_LOW);
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_LOW);
				_delay_ms( Copy_u8Speed );

				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_LOW);
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_LOW);
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_HIGH);
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_LOW);
				_delay_ms( Copy_u8Speed );

				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_LOW);
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_LOW);
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_LOW);
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_HIGH);
				_delay_ms( Copy_u8Speed );


			}

		}else if( Copy_u8Direction == STEPPER_ANTI_CLOCK_WISE ){

			for( LOC_u16Iterator = 0 ; LOC_u16Iterator < ( ( (u32)Copy_u16Degree * 256 ) / 45 ) / 4 ; LOC_u16Iterator++  ){

				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_LOW);
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_LOW);
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_LOW);
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_HIGH);
				_delay_ms( Copy_u8Speed );

				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_LOW);
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_LOW);
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_HIGH);
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_LOW);
				_delay_ms( Copy_u8Speed );

				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_LOW);
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_HIGH);
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_LOW);
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_LOW);
				_delay_ms( Copy_u8Speed );

				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_HIGH);
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_LOW);
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_LOW);
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_LOW);
				_delay_ms( Copy_u8Speed );


			}

		}

	}else if( Copy_u8StepType == STEPPER_HALF_STEP ){

		if( Copy_u8Direction == STEPPER_CLOCK_WISE ){

			for( LOC_u16Iterator = 0 ; LOC_u16Iterator < ( ( (u32)Copy_u16Degree * 512 ) / 45 ) / 8 ; LOC_u16Iterator++  ){

				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_HIGH );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_LOW  );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_LOW  );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_LOW  );
				_delay_ms( Copy_u8Speed );                                                 

				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_HIGH );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_HIGH );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_LOW  );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_LOW  );
				_delay_ms( Copy_u8Speed );

				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_LOW  );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_HIGH );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_LOW  );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_LOW  );
				_delay_ms( Copy_u8Speed );

				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_LOW  );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_HIGH );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_HIGH );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_LOW  );
				_delay_ms( Copy_u8Speed );

				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_LOW  );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_LOW  );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_HIGH );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_LOW  );
				_delay_ms( Copy_u8Speed );

				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_LOW  );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_LOW  );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_HIGH );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_HIGH );
				_delay_ms( Copy_u8Speed );

				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_LOW  );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_LOW  );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_LOW  );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_HIGH );
				_delay_ms( Copy_u8Speed );

				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_HIGH );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_LOW  );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_LOW  );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_HIGH );
				_delay_ms( Copy_u8Speed );



			}

		}else if( Copy_u8Direction == STEPPER_ANTI_CLOCK_WISE ){


			for( LOC_u16Iterator = 0 ; LOC_u16Iterator < ( ( (u32)Copy_u16Degree * 512 ) / 45 ) / 8 ; LOC_u16Iterator++  ){
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_HIGH );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_LOW  );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_LOW  );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_HIGH );
				_delay_ms( Copy_u8Speed );

				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_LOW  );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_LOW  );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_LOW  );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_HIGH );
				_delay_ms( Copy_u8Speed );

				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_LOW  );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_LOW  );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_HIGH );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_HIGH );
				_delay_ms( Copy_u8Speed );

				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_LOW  );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_LOW  );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_HIGH );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_LOW  );
				_delay_ms( Copy_u8Speed );

				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_LOW  );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_HIGH );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_HIGH );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_LOW  );
				_delay_ms( Copy_u8Speed );

				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_LOW  );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_HIGH );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_LOW  );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_LOW  );
				_delay_ms( Copy_u8Speed );

				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_HIGH );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_HIGH );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_LOW  );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_LOW  );
				_delay_ms( Copy_u8Speed );

				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_BLUE_PIN  , DIO_PIN_HIGH );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_PINK_PIN  , DIO_PIN_LOW  );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_YELLOW_PIN, DIO_PIN_LOW  );
				MDIO_voidSetPinValue( STEPPER_MOTOR_PORT, STEPPER_MOTOR_ORANGE_PIN, DIO_PIN_LOW  );
				_delay_ms( Copy_u8Speed );

			}

		}

	}

}


void HSTEPPER_voidOff ( void ){

	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT , STEPPER_MOTOR_BLUE_PIN   , DIO_PIN_LOW );
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT , STEPPER_MOTOR_PINK_PIN   , DIO_PIN_LOW );
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT , STEPPER_MOTOR_YELLOW_PIN , DIO_PIN_LOW );
	MDIO_voidSetPinValue( STEPPER_MOTOR_PORT , STEPPER_MOTOR_ORANGE_PIN , DIO_PIN_LOW );

}
