/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    EEPROM_INTERFACE.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Aliaa Eslam Zayed
 *  Created: 5/ 9/ 2023
 *  Layer  : HAL
 *  SWC    : EEPROM
 *
 */

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void HEEPROM_voidInitialization(void);

void HEEPROM_voidWriteData(u16 A_u16Adress, u8 A_u8Data);

u8 HEEPROM_u8ReadData(u16 A_u16Address);



#endif																			 
