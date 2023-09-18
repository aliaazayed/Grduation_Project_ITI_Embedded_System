/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    EEPROM_PORGRAM.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Aliaa Eslam Zayed
 *  Created: 5/ 9/ 2023
 *  Layer  : HAL
 *  SWC    : EEPROM
 *
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/TWI/TWI_interface.h"
#include "../../MCAL/TWI/TWI_private.h"

#include"EEPROM_interface.h"

void HEEPROM_voidInitialization(void)
{
	MTWI_voidInitialization();
}

void HEEPROM_voidWriteData(u16 A_u16Address, u8 A_u8Data)
{
	/*** 1- start condition ****/
	MTWI_u8SendStartCondition();
	/*** 2- Send address  slave ****/
	MTWI_u8SendSlaveAddress((0b1010000) , WRITE);
	MTWI_u8SendData((u8)A_u16Address);
	/*** 3- Send Data ****/
	MTWI_u8SendData(A_u8Data);
	/*** 4- Stop condition ***/
	MTWI_u8StopCondition();
}
	

u8 HEEPROM_u8ReadData(u16 A_u16Address)
{
	u8 LOC_u8Data=0;
	
	/*** 1- start condition ****/
	MTWI_u8SendStartCondition();
	/*** 2- Send address  slave ****/
	MTWI_u8SendSlaveAddress((0b1010000), WRITE);
	MTWI_u8SendData((u8) A_u16Address);

	/*** 3- Restart *******/
	MTWI_u8SendStartCondition();
	/*** 4- Send address  slave ****/
	MTWI_u8SendSlaveAddress((0b1010000), READ);
	/*** 5- Recieve Data ****/
	MTWI_u8RecieveData( &LOC_u8Data,NOT_ACK);
	/*** 6- Stop condition ***/
	MTWI_u8StopCondition();

	return LOC_u8Data;
}
