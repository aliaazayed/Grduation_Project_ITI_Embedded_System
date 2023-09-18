/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   GIE_PROGRAM.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Aliaa Eslam Zayed
 * Created : 23/8/2023
 *  Layer  : MCAL
 *  SWC    : GIE
 *
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_private.h"

void MGIE_voidEnableGlobalInterrupt(void)
{
	SET_BIT(SREG, GIE_PIN7);
}

void MGIE_voidDisableGlobalInterrupt(void)
{
	CLR_BIT(SREG, GIE_PIN7);
}
