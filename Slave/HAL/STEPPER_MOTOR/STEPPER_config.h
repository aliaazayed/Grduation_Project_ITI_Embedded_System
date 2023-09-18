/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    STEPPER_CONFIGH.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Aliaa Eslam Zayed
 *  Created: 27/ 8/ 2023
 *  Layer  : HAL
 *  SWC    : STEPPER_MOTOR
 *
 */

#ifndef STEPPER_MOTOR_CONFIG_H_
#define STEPPER_MOTOR_CONFIG_H_

/*-------------------------------------------------------------------------------------------------------------*/
#define STEPPER_MOTOR_PORT         DIO_PORTC                  /*** We have choices *DIO_PORTA
																			       *DIO_PORTB
																			       *DIO_PORTC
																			       *DIO_PORTD   ***/
/*-------------------------------------------------------------------------------------------------------------*/
/** We can choose *DIO_PIN0
				  *DIO_PIN1
				  *DIO_PIN2
				  *DIO_PIN3
				  *DIO_PIN4
				  *DIO_PIN5
				  *DIO_PIN6
				  *DIO_PIN7  ***/
				  
#define STEPPER_MOTOR_BLUE_PIN     DIO_PIN0
#define STEPPER_MOTOR_PINK_PIN     DIO_PIN1
#define STEPPER_MOTOR_YELLOW_PIN   DIO_PIN2
#define STEPPER_MOTOR_ORANGE_PIN   DIO_PIN3


																			  
#endif																			 
