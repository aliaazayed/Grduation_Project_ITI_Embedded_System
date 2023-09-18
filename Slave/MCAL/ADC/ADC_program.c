/*
 *
 *<<<<<<<<<<<<<<<<<<<<< ADC_PROGRAM.c>>>>>>>>>>>>>>>>>>>>>
 * Author : ALIAA ESLAM ZAYED
 * Created: 22 /8/2023
 * Layer  : MCAL
 * SWC    : ADC
 *
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO/DIO_interface.h"
#include "../DIO/DIO_private.h"

#include "../GIE/GIE_private.h"

#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_private.h"



 void (*ADC_CallBack) (void) =NULL;

void MADC_voidInitialization(void)
{
	#if ADC_REFS ==  ADC_REFS_AREF
	CLR_BIT(ADMUX, ADMUX_REFS0);
	CLR_BIT(ADMUX, ADMUX_REFS1);

	#elif ADC_REFS ==  ADC_REFS_AVCC
	SET_BIT(ADMUX, ADMUX_REFS0);
	CLR_BIT(ADMUX, ADMUX_REFS1);
	
	#elif ADC_REFS ==  ADC_REFS_INTERNAL
	SET_BIT(ADMUX, ADMUX_REFS0);
	SET_BIT(ADMUX, ADMUX_REFS1);
	#endif
	
	#if ADCLRA == ADC_LEFT_ADJUSTMENT
	SET_BIT(ADMUX, ADMUX_ADLAR);
	#elif ADCLRA == ADC_RIGHT_ADJUSTMENT
	CLR_BIT(ADMUX, ADMUX_ADLAR);
	#endif
	
	
	#if ADC_PRESCULAR_MODE== ADC_PRESCULAR_0
	CLR_BIT(ADCSAR, ADCSRA_ADPS0);
	CLR_BIT(ADCSAR, ADCSRA_ADPS1);
	CLR_BIT(ADCSAR, ADCSRA_ADPS2);
	#elif ADC_PRESCULAR_MODE== ADC_PRESCULAR_1
	SET_BIT(ADCSRA, ADCSRA_ADPS0);
	CLR_BIT(ADCSRA, ADCSRA_ADPS1);
	CLR_BIT(ADCSRA, ADCSRA_ADPS2);
	#elif ADC_PRESCULAR_MODE== ADC_PRESCULAR_2
	CLR_BIT(ADCSRA, ADCSRA_ADPS0);
	SET_BIT(ADCSRA, ADCSRA_ADPS1);
	CLR_BIT(ADCSRA, ADCSRA_ADPS2);
	#elif ADC_PRESCULAR_MODE== ADC_PRESCULAR_3
	SET_BIT(ADCSRA, ADCSRA_ADPS0);
	SET_BIT(ADCSRA, ADCSRA_ADPS1);
	CLR_BIT(ADCSRA, ADCSRA_ADPS2);
	#elif ADC_PRESCULAR_MODE== ADC_PRESCULAR_4
	CLR_BIT(ADCSRA, ADCSRA_ADPS0);
	CLR_BIT(ADCSRA, ADCSRA_ADPS1);
	SET_BIT(ADCSRA, ADCSRA_ADPS2);
	#elif ADC_PRESCULAR_MODE== ADC_PRESCULAR_5
	SET_BIT(ADCSRA, ADCSRA_ADPS0);
	CLR_BIT(ADCSRA, ADCSRA_ADPS1);
	SET_BIT(ADCSRA, ADCSRA_ADPS2);
	#elif ADC_PRESCULAR_MODE== ADC_PRESCULAR_6
	CLR_BIT(ADCSRA, ADCSRA_ADPS0);
	SET_BIT(ADCSRA, ADCSRA_ADPS1);
	SET_BIT(ADCSRA, ADCSRA_ADPS2);
	#elif ADC_PRESCULAR_MODE== ADC_PRESCULAR_7
	SET_BIT(ADCSRA, ADCSRA_ADPS0);
	SET_BIT(ADCSRA, ADCSRA_ADPS1);
	SET_BIT(ADCSRA, ADCSRA_ADPS2);
	#endif
	
	#if ADIF_MODE== ADIF_ENABLE
	CLR_BIT(SREG, ADCSRA_ADIF);
	#elif ADIF_MODE== ADIF_DISABLE
	SET_BIT(SREG, ADCSRA_ADIF);
	#endif
	
	#if AUTO_TRIGGER_MODE== AUTO_TRIGGER_DISABLE
	CLR_BIT(SFIOR, ADCSRA_ADATE);
	#elif AUTO_TRIGGER_MODE== AUTO_TRIGGER_ENABLE
	SET_BIT(SFIOR, ADCSRA_ADATE);
	#endif
	
	#if ADEN_MODE== ADEN_DISABLE
	CLR_BIT(ADSCRA, ADCSRA_ADEN);
	#elif ADEN_MODE== ADEN_ENABLE
	SET_BIT(ADCSAR, ADCSRA_ADEN);
	#endif
}

void MADC_voidStartConversion(u8 A_u8ChannelNo)
{
	switch (A_u8ChannelNo)
	{
		case ADC_CHANNEL0 :CLR_BIT(ADMUX, ADMUX_MUX0);
	                      CLR_BIT(ADMUX, ADMUX_MUX1);
	                      CLR_BIT(ADMUX, ADMUX_MUX2);
	                      CLR_BIT(ADMUX, ADMUX_MUX3);
	                      CLR_BIT(ADMUX, ADMUX_MUX4);
						  break ;
						  
		case ADC_CHANNEL1 :  	SET_BIT(ADMUX, ADMUX_MUX0);
	                        CLR_BIT(ADMUX, ADMUX_MUX1);
	                        CLR_BIT(ADMUX, ADMUX_MUX2);
	                        CLR_BIT(ADMUX, ADMUX_MUX3);
	                        CLR_BIT(ADMUX, ADMUX_MUX4);
						  break ;
						  
		case ADC_CHANNEL2 :  CLR_BIT(ADMUX, ADMUX_MUX0);
						  SET_BIT(ADMUX, ADMUX_MUX1);
						  CLR_BIT(ADMUX, ADMUX_MUX2);
						  CLR_BIT(ADMUX, ADMUX_MUX3);
						  CLR_BIT(ADMUX, ADMUX_MUX4);
						  break ;
						  
		case ADC_CHANNEL3 :  SET_BIT(ADMUX, ADMUX_MUX0);
						  SET_BIT(ADMUX, ADMUX_MUX1);
						  CLR_BIT(ADMUX, ADMUX_MUX2);
						  CLR_BIT(ADMUX, ADMUX_MUX3);
						  CLR_BIT(ADMUX, ADMUX_MUX4);
						  break ;
						  
		case ADC_CHANNEL4 :  CLR_BIT(ADMUX, ADMUX_MUX0);
						  CLR_BIT(ADMUX, ADMUX_MUX1);
						  SET_BIT(ADMUX, ADMUX_MUX2);
						  CLR_BIT(ADMUX, ADMUX_MUX3);
						  CLR_BIT(ADMUX, ADMUX_MUX4);
						  break ;
						  
		case ADC_CHANNEL5 :  SET_BIT(ADMUX, ADMUX_MUX0);
						  CLR_BIT(ADMUX, ADMUX_MUX1);
						  SET_BIT(ADMUX, ADMUX_MUX2);
						  CLR_BIT(ADMUX, ADMUX_MUX3);
						  CLR_BIT(ADMUX, ADMUX_MUX4);
						  break ;
						  
		case ADC_CHANNEL6 :  CLR_BIT(ADMUX, ADMUX_MUX0);
						  SET_BIT(ADMUX, ADMUX_MUX1);
						  SET_BIT(ADMUX, ADMUX_MUX2);
						  CLR_BIT(ADMUX, ADMUX_MUX3);
						  CLR_BIT(ADMUX, ADMUX_MUX4);
						  break ;
						  
		case ADC_CHANNEL7 :  SET_BIT(ADMUX, ADMUX_MUX0);
						  SET_BIT(ADMUX, ADMUX_MUX1);
						  SET_BIT(ADMUX, ADMUX_MUX2);
						  CLR_BIT(ADMUX, ADMUX_MUX3);
						  CLR_BIT(ADMUX, ADMUX_MUX4);
						  break ;
		default         : /**ERROR*/
		                  break ;				  
	}
	
	/**Start Conversion */
	SET_BIT(ADCSAR, ADCSRA_ADSC);
}

	

void MADC_voidEnableADC (void)
{
	SET_BIT(ADCSAR , ADCSRA_ADEN) ;
}

void MADC_voidDisableADC (void)
{
	CLR_BIT(ADCSAR , ADCSRA_ADEN) ;
}

void MADC_voidEnableInterrupt (void)
{
	SET_BIT(ADCSAR , ADCSRA_ADIE) ;
}

void MADC_voidDisableInterrupt (void)
{
	CLR_BIT(ADCSAR , ADCSRA_ADIE) ;
}

f32 MADC_u16GetResult(u8 channel)
{
	u16 LOC_u16Result;
	MADC_voidStartConversion(channel);
	SET_BIT(ADCSAR, ADCSRA_ADSC);
	while(GET_BIT(ADCSAR, ADCSRA_ADIF)==0);
	LOC_u16Result=ADCL|(ADCH<<8);
	SET_BIT(ADCSAR, ADCSRA_ADIF);
     return LOC_u16Result;
}

f32 MADC_f32GetVoltValue(u8 A_u8ChannelNo)
{
	f32 LOC_f32Num;
	f32 LOC_f32Volt;
	LOC_f32Num= MADC_u16GetResult(A_u8ChannelNo);
    LOC_f32Volt= (LOC_f32Num * 5)/1024;
	
	return LOC_f32Volt;
}

f32 MADC_f32LDRSensor(u8 A_u8ChannelNo)
{
	f32 LOC_f32Temp;
	f32 LOC_f32Volt= MADC_f32GetVoltValue( A_u8ChannelNo);
	
	LOC_f32Temp= (LOC_f32Volt* 100);
	
	return LOC_f32Temp;
}

void MADC_voidSetCallback( void (*A_fptr)(void)  )
{
	ADC_CallBack = A_fptr;
}

/**ISR of ADC*/
void __vector_16(void)__attribute__((signal))__attribute__((interrupt));
void __vector_16(void)
{
	if( ADC_CallBack != NULL ){
		ADC_CallBack () ;
	}
}
