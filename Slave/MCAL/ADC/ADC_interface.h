/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   ADC_INTERFACE_H_  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Aliaa Eslam Zayed
 * Created : 22 /8/2023
 *  Layer  : MCAL
 *  SWC    : ADC
 *
 */
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/*----------------------------------------------ADC_REFS--------------------------------------------------------*/
#define ADC_REFS_AREF              0
#define ADC_REFS_AVCC              1
#define ADC_REFS_INTERNAL          3

/*------------------------------------------ADMUX Register Pins------------------------------------------------*/
#define  ADMUX_MUX0    DIO_PIN0
#define  ADMUX_MUX1    DIO_PIN1
#define  ADMUX_MUX2    DIO_PIN2
#define  ADMUX_MUX3    DIO_PIN3
#define  ADMUX_MUX4    DIO_PIN4
#define  ADMUX_ADLAR   DIO_PIN5
#define  ADMUX_REFS0   DIO_PIN6
#define  ADMUX_REFS1   DIO_PIN7

/*------------------------------------------ADCSRA Register Pins------------------------------------------------*/
#define  ADCSRA_ADPS0   DIO_PIN0
#define  ADCSRA_ADPS1  DIO_PIN1
#define  ADCSRA_ADPS2  DIO_PIN2
#define  ADCSRA_ADIE   DIO_PIN3
#define  ADCSRA_ADIF   DIO_PIN4
#define  ADCSRA_ADATE  DIO_PIN5
#define  ADCSRA_ADSC   DIO_PIN6
#define  ADCSRA_ADEN   DIO_PIN7

/*------------------------------------------ADC Prescular Modes------------------------------------------------*/
#define  ADC_PRESCULAR_0  2
#define  ADC_PRESCULAR_1  2
#define  ADC_PRESCULAR_2  4
#define  ADC_PRESCULAR_3  8
#define  ADC_PRESCULAR_4  16
#define  ADC_PRESCULAR_5  32
#define  ADC_PRESCULAR_6  64
#define  ADC_PRESCULAR_7  128

/*------------------------------------------ADIF pin Modes ----------------------------------------------------*/
#define ADIF_ENABLE    0
#define ADIF_DISABLE   1

/*------------------------------------------Auto Trigger pin Modes---------------------------------------------*/
#define AUTO_TRIGGER_DISABLE  1
#define AUTO_TRIGGER_ENABLE   0

/*------------------------------------------ADLRA pin Modes --------------------------------------------------*/
#define  ADC_LEFT_ADJUSTMENT        0
#define  ADC_RIGHT_ADJUSTMENT       1

/*------------------------------------------ADEN pin  Modes--------------------------------------------------*/
#define  ADEN_ENABLE   0
#define  ADEN_DISABLE  1

/*------------------------------------------ADC Channel Modes-----------------------------------------------*/
#define ADC_CHANNEL0   0
#define ADC_CHANNEL1   1
#define ADC_CHANNEL2   2
#define ADC_CHANNEL3   3
#define ADC_CHANNEL4   4
#define ADC_CHANNEL5   5
#define ADC_CHANNEL6   6
#define ADC_CHANNEL7   7

/*------------------------------------------Auto trigger Pins Modes----------------------------------------*/
#define  ADC_AUTO_TRIGGER_FREE_RUNNING           0
#define  ADC_AUTO_TRIGGER_ANALOG_COMPARATOR      1
#define  ADC_AUTO_TRIGGER_EXTI_REQUEST           2
#define  ADC_AUTO_TRIGGER_TIMER0_COMPER_MATCH    3
#define  ADC_AUTO_TRIGGER_TIMER0_OVERFLOW        4
#define  ADC_AUTO_TRIGGER_TIMER_COMPARE_MATCH_B  5
#define  ADC_AUTO_TRIGGER_TIMER1_OVERFLOW        6
#define  ADC_AUTO_TRIGGER_TIMER1_CAPTURE_EVENT   7

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Functions >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/**
	Function Name        : MADC_voidInitialization
	Function Returns     : void
	Function Arguments   : void
	Function Description : Intialize the ADC
*/
void MADC_voidInitialization(void);

/**
	Function Name        : MADC_voidStartConversion
	Function Returns     : void
	Function Arguments   : A_u8ChannelNo
	Function Description : initialize the conversion of the pin
*/
void MADC_voidStartConversion(u8 A_u8ChannelNo);

/**
	Function Name        : MADC_voidEnableADC 
	Function Returns     : void
	Function Arguments   : void
	Function Description : Enable the ADC converion
*/
void MADC_voidEnableADC (void);

/**
	Function Name        : MADC_voidDisableADC 
	Function Returns     : void
	Function Arguments   : void
	Function Description : Disable the ADC converion
*/
void MADC_voidDisableADC (void);

/**
	Function Name        : MADC_voidEnableInterrupt 
	Function Returns     : void
	Function Arguments   : void
	Function Description : Enable PIE
*/
void MADC_voidEnableInterrupt (void); 

/**
	Function Name        : MADC_voidDisableInterrupt 
	Function Returns     : void
	Function Arguments   : void
	Function Description : Disable PIE
*/
void MADC_voidDisableInterrupt (void);

/**
	Function Name        : MADC_u16GetResult
	Function Returns     : u16
	Function Arguments   : void
	Function Description : Get the value of the ADC using POLLING  mode
*/
f32 MADC_u16GetResult(u8 A_u8ChannelNo);


f32 MADC_f32GetVoltValue(u8 A_u8ChannelNo);

f32 MADC_f32LDRSensor(u8 A_u8ChannelNo);


/**
	Function Name        : MADC_voidSetCallback
	Function Returns     : void
	Function Arguments   : void (*A_fptr)(void)
	Function Description : Get the value of the ADC using INT  mode
*/
void MADC_voidSetCallback( void (*A_fptr)(void)  );
#endif
