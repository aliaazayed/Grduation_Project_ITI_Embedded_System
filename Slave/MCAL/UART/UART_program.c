/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    UART_PROGRAM.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Aliaa Eslam Zayed
 *  Created: 30/ 8/ 2023
 *  Layer  : MCAL
 *  SWC    : UART
 *
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../HAL/CLCD/CLCD_interface.h"
#include "../../HAL/CLCD/CLCD_config.h"
#include "../DIO/DIO_interface.h"
#include "UART_private.h"
#include "UART_interface.h"
#include "UART_config.h"

#include <avr/delay.h>
void MUART_voidInitialization(void)
{
	SET_BIT(UCSRB ,UCSRB_TXEN) ;
	SET_BIT(UCSRB ,UCSRB_RXEN) ;
	
	/*Choose number of data bits to be sent*/
	#if   NUMBER_OF_DATA_BITS == UCSZ_5_BIT
	        UCSRC = (1<<UCSRC_URSEL) ;
	#elif NUMBER_OF_DATA_BITS == UCSZ_6_BIT
	        UCSRC = (1<<UCSRC_URSEL) | (1<<UCSRC_UCSZ0) ;
	#elif NUMBER_OF_DATA_BITS == UCSZ_7_BIT
	        UCSRC = (1<<UCSRC_URSEL) | (1<<UCSRC_UCSZ1) ;
	#elif NUMBER_OF_DATA_BITS == UCSZ_8_BIT
	        UCSRC = (1<<UCSRC_URSEL) | (1<<UCSRC_UCSZ0) | (1<<UCSRC_UCSZ1) ; 
	#elif NUMBER_OF_DATA_BITS == UCSZ_9_BIT
	        SET_BIT (UCSRB , UCSRB_TXB8) ;
			SET_BIT (UCSRB , UCSRB_RXB8) ;
			SET_BIT (UCSRB , UCSRB_UCSZ2) ;
	        UCSRC = (1<<UCSRC_URSEL) | (1<<UCSRC_UCSZ1) | (1<<UCSRC_UCSZ0) ; 
	#endif
	
	UBRRL=51;
}
	
void MUART_voidSendData(u8 A_u8Data)
{
	while(GET_BIT(UCSRA, UCSRA_UDRE)==0);
	

	UDR=A_u8Data ;
}

void MUART_voidSendString(u8 * A_ptrString)
{
	u8 LOC_u8Iterator=0;
	while( A_ptrString[LOC_u8Iterator])
	{
		_delay_ms(30);
		MUART_voidSendData( A_ptrString[LOC_u8Iterator]);
		LOC_u8Iterator++;

	}

}

u8 MUART_voidRecieveData(void)
{
	while(GET_BIT(UCSRA, UCSRA_RXC)==0);
	
	return UDR;
}

void MUART_voidRecieveString(u8 * A_ptrString)
{
	u8 LOC_u8Iterator=0;
	//A_ptrString[LOC_u8Iterator]=MUART_voidRecieveData();
	while( LOC_u8Iterator<10)
	{


		A_ptrString[LOC_u8Iterator]=MUART_voidRecieveData();
		CLCD_voidInitialization();
		CLCD_voidSendData(A_ptrString[LOC_u8Iterator]);
		LOC_u8Iterator++;

		A_ptrString[LOC_u8Iterator]='\0';

	}
}




