/*
 *
 *<<<<<<<<<<<<<<<<<<<<<KPD_INTERFACE_H_>>>>>>>>>>>>>>>>>>>>>>>>
 * Author : ALIAA ESLAM ZAYED
 * Created: 18 /8/2023
 * Layer  : HAL
 * SWC    : KPD
 *
 */
 
 
#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

#define NOT_PRESSED  0xff

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Functions>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/*
	Function Name        : HKPD_voidInitialization
	Function Returns     : void
	Function Arguments   : void
	Function Description : Initialize the Rows as an input and active the pull up & columns  as an output and give it the value high
*/
void HKPD_voidInitialization(void);


/*
	Function Name        : HKPD_u8GetPressedKey
	Function Returns     : u8
	Function Arguments   : void
	Function Description : Get the value of the pressed key and return 0xff if we don't pressed
*/
u8 HKPD_u8GetPressedKey(void);						
						
#endif