/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    STEPPER_INTERFACE.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Aliaa Eslam Zayed
 *  Created: 27/ 8/ 2023
 *  Layer  : HAL
 *  SWC    : STEPPER_MOTOR
 *
 */

#ifndef STEPPER_MOTOR_INTERFACE_H_
#define STEPPER_MOTOR_INTERFACE_H_


typedef struct
{
	u8 port;
	u8 pin0 ;
	u8 pin1 ;
	u8 pin2 ;
	u8 pin3 ;
}STEPPER_CONFIG;
#define STEPPER_FULL_STEP    1
#define STEPPER_HALF_STEP    0

#define STEPPER_CLOCK_WISE       1
#define STEPPER_ANTI_CLOCK_WISE  0

/*----------------------------------------------- Functions ----------------------------------------------------------*/

/*
	Function Name        : HSTEPPER_voidInitialization
	Function Returns     : void
	Function Arguments   : void
	Function Description : Initialize Stepper motor
*/
void HSTEPPER_voidInitialization( void );

/*
	Function Name        : HSTEPPER_voidOff
	Function Returns     : void
	Function Arguments   : void
	Function Description : Stop Stepper motor
*/
void HSTEPPER_voidOff ( void );

/*
	Function Name        : HSTEPPER_voidOn
	Function Returns     : void
	Function Arguments   : Copy_u8StepType, Copy_u8Direction, Copy_u8Speed, Copy_u16Degree
	Function Description : Rotata Stepper motor
*/
void HSTEPPER_voidOn  ( u8 Copy_u8StepType , u8 Copy_u8Direction , u8 Copy_u8Speed , u16 Copy_u16Degree );

void HSTEPER_voidOnCCW(void);
void HSTEPER_voidOnCW(void);


void HSTEPER_voidOnCCWS(STEPPER_CONFIG S);
void HSTEPER_voidOnCWS(STEPPER_CONFIG S);



#endif
