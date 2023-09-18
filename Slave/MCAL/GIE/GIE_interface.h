/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   GIE_INTERFACE_H_  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Aliaa Eslam Zayed
 * Created : 23/8/2023
 *  Layer  : MCAL
 *  SWC    : GIE
 *
 */
#ifndef GIE_INTERFACE_H_
#define GIE_INTERFACE_H_

/*--------------------------------------------Functions------------------------------------------------------------*/
/**
	Function Name        : MGIE_voidEnableGlobalInterrupt
	Function Returns     : void
	Function Arguments   : void 
	Function Description : Enable the global interrupt  by setting the pin of the SREG gesiter
*/
void MGIE_voidEnableGlobalInterrupt(void);

/**
	Function Name        : MGIE_voidDisableGlobalInterrupt
	Function Returns     : void
	Function Arguments   : void 
	Function Description : Enable the global interrupt  by clearing the pin of the SREG gesiter
*/
void MGIE_voidDisableGlobalInterrupt(void);


#endif