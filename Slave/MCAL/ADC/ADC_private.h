/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   ADC_PRIVATE_H_  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Aliaa Eslam Zayed
 *  Created: 22 /8/2023
 *  Layer  : MCAL
 *  SWC    : ADC
 *
 */
#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_



#define ACSR                *((volatile u8*)0x28 )
#define ADMUX               *((volatile u8*)0x27 )
#define ADCSAR              *((volatile u8*)0x26 )
#define ADCH                *((volatile u8*)0x25 )
#define ADCL                *((volatile u8*)0x24 )
#define ADC_DATA_RE 		*((volatile u16*)0x24)		//ADC Low + High


#endif
