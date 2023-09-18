/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    TWI_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Aliaa Eslam Zayed
 *  Created: 3/ 9/ 2023
 *  Layer  : MCAL
 *  SWC    : TWI
 *
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/DIO/DIO_private.h"

#include "TWI_private.h"
#include "TWI_interface.h"
#include "TWI_config.h"

void MTWI_voidInitialization(void)
{
	/****** Boudrate ********/
	TWBR= (((CPU_CLK_FREQ)/(SCL_FREQ))-16)/(2*(4^PRESCULAR_MODE));
	//TWBR=72;
	#if TWIE_MODE == TWIE_ENABLE
	SET_BIT(TWCR, TWCR_TWIE);
	#elif TWIE_MODE == TWIE_DISABLE
	CLR_BIT(TWCR, TWCR_TWIE);
	#endif
	
	
	#if TWI_MODE == TWI_ENABLE
	SET_BIT(TWCR, TWCR_TWIE);
	#elif TWI_MODE == TWI_DISABLE
	CLR_BIT(TWCR, TWCR_TWIE);
	#endif
	
}

u8 MTWI_u8SendStartCondition(void)
{
	TWCR = (1<<TWCR_TWINT)|(1<<TWCR_TWSTA)|(1<<TWCR_TWEN);
	/****Wait for TWINT Flag set. This indicates that the START condition has been transmitted  ****/
	while (!(TWCR & (1<<TWCR_TWINT)));
	
	return (TWSR & 0xF8);
}

u8 MTWI_u8SendSlaveAddress(u8 A_u8SlaveAddress, u8 A_u8ReadWrite)
{
	TWDR = A_u8SlaveAddress<<1;
	
	if(A_u8ReadWrite== READ)
	{
		SET_BIT(TWDR, DIO_PIN0);
	}
	else if(A_u8ReadWrite== WRITE)
	{
		CLR_BIT(TWDR, DIO_PIN0);
	}
	/*** Clear TWINT bit in TWCR to start transmission of address  ***/
    TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);
	
	/*** ensure that start condition is closed**/
	CLR_BIT(TWCR, TWCR_TWSTA);
	while (!(TWCR & (1<<TWCR_TWINT)));
	
	return (TWSR & 0xF8);
	
}
u8 MTWI_u8SendData(u8 A_u8Data)
{
	TWDR = A_u8Data;
    TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);
    while (!(TWCR & (1<<TWCR_TWINT)));
	return (TWSR & 0xF8);
}

u8 MTWI_u8StopCondition(void)
{
	TWCR = (1<<TWCR_TWINT)|(1<<TWCR_TWEN)|(1<<TWCR_TWSTO);
	return (TWSR & 0xF8);
}

u8 MTWI_u8GetStatus(void)
{
	return (TWSR & 0xF8);
}

u8 MTWI_u8RecieveData(u8 * A_PtrData, u8 A_u8Acknoledge)
{
	if(ACK== A_u8Acknoledge)
	{
		TWCR =(1<<TWCR_TWINT)|(1<<TWCR_TWEN)|(1<<TWCR_TWEA);
	}
	if(NOT_ACK== A_u8Acknoledge)
	{
		TWCR =(1<<TWCR_TWINT)|(1<<TWCR_TWEN);
		CLR_BIT(TWCR, TWCR_TWEA);
	}
	
	 while (!(TWCR & (1<<TWCR_TWINT)));
	 
	 *A_PtrData=TWDR;
	 
	return (TWSR & 0xF8);
}
	
