/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    TWI_CONFIG.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Aliaa Eslam Zayed
 *  Created: 3/ 9/ 2023
 *  Layer  : MCAL
 *  SWC    : TWI
 *
 */

#ifndef TWI_CONFIG_H_
#define TWI_CONFIG_H_

#define SCL_FREQ       400000
#define CPU_CLK_FREQ   8000000

/*------------------------------------------------ PRESCULAR_MODE -------------------------------------------------------------*/
#define PRESCULAR_MODE    PRESCULAR_1              /**** We have Options : *PRESCULAR_1   
																		   *PRESCULAR_4 
																		   *PRESCULAR_16
																		   *PRESCULAR_64   ****/

/*------------------------------------- TWINT_MODE -----------------------------------------------------------*/
#define TWINT_MODE    TWINT_DISABLE                              /*** We have Options   *TWINT_ENABLE 
																				        *TWINT_DISABLE  ***/

/*------------------------------------- TWI_ACK_MODE -----------------------------------------------------------*/
#define  TWI_ACK_MODE    TWI_ACK_ENABLE                              /*** We have Options *TWI_ACK_ENABLE 
																				          *TWI_ACK_DISABLE ***/

/*------------------------------------- TWI_MODE -----------------------------------------------------------*/
#define  TWI_MODE    TWI_ENABLE                              /*** We have Options *TWI_ENABLE 
																				  *TWI_DISABLE ***/

/*------------------------------------- TWIE_MODE -----------------------------------------------------------*/
#define  TWIE_MODE    TWIE_DISABLE                              /*** We have Options *TWIE_ENABLE 
																				     *TWIE_DISABLE ***/

	




#endif																			 