/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   ADC_CONFIG_H_  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Aliaa Eslam Zayed
 * Created : 22 /8/2023
 *  Layer  : MCAL
 *  SWC    : ADC
 *
 */
#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_
/*----------------------------------------------ADC_REFS--------------------------------------------------------*/
#define ADC_REFS   ADC_REFS_AVCC                        /***WE can choose *ADC_REFS_AREF
									                                      *ADC_REFS_AVCC
									                                      *ADC_REFS_INTERNAL_2.56  ***/
									                   
									                   
/*---------------------------------------------ADCLRA------------------------------------------------------------*/									                   
#define ADCLRA  ADC_RIGHT_ADJUSTMENT                     /*** We can choose* ADC_LEFT_ADJUSTMENT
									                   				       * ADC_RIGHT_ADJUSTMENT  ***/
											           
/*--------------------------------------------ADC_PRESCULAR_MODE--------------------------------------------------*/											           
#define ADC_PRESCULAR_MODE  ADC_PRESCULAR_0            /*** We can choose *ADC_PRESCULAR_0
											           					  *ADC_PRESCULAR_1
																          *ADC_PRESCULAR_2
																          *ADC_PRESCULAR_3
																          *ADC_PRESCULAR_4
																          *ADC_PRESCULAR_5
																          *ADC_PRESCULAR_6
																          *ADC_PRESCULAR_7        ***/

/*-------------------------------------------ADIF_MODE----------------------------------------------------------*/																
#define ADIF_MODE     ADIF_ENABLE                      /*** We can choose   *ADIF_ENABLE 
																            *ADIF_DISABLE           ***/

/*--------------------------------------------AUTO_TRIGGER_MODE-------------------------------------------------*/											           
#define AUTO_TRIGGER_MODE   AUTO_TRIGGER_DISABLE         /***We can choose* AUTO_TRIGGER_DISABLE  
												         				  * AUTO_TRIGGER_ENABLE   ***/

/*-------------------------------------------ADC_CHANNEL_MODE----------------------------------------------------*/											           
#define ADC_CHANNEL_MODE   ADC_CHANNEL0                  /***We can choose *ADC_CHANNEL0
															               *ADC_CHANNEL1
															               *ADC_CHANNEL2
															               *ADC_CHANNEL3
															               *ADC_CHANNEL4
															               *ADC_CHANNEL5
															               *ADC_CHANNEL6
															               *ADC_CHANNEL7         ****/
																		  

/*-----------------------------------------ADEN_MODE-------------------------------------------------------------*/
#define ADEN_MODE  ADEN_ENABLE                       /*** We can choose *ADEN_ENABLE 
																        *ADEN_DISABLE         ***/

/*----------------------------------------AUTO_TRIGGER_SOURCE---------------------------------------------------*/
#define AUTO_TRIGGER_SOURCE   AUTO_TRIGGER_FREE_RUNNING /*** We can choose*ADC_AUTO_TRIGGER_FREE_RUNNING          
																		  *ADC_AUTO_TRIGGER_ANALOG_COMPARATOR     
																		  *ADC_AUTO_TRIGGER_EXTI_REQUEST          
																		  *ADC_AUTO_TRIGGER_TIMER0_COMPER_MATCH   
																		  *ADC_AUTO_TRIGGER_TIMER0_OVERFLOW       
																		  *ADC_AUTO_TRIGGER_TIMER_COMPARE_MATCH_B 
																		  *ADC_AUTO_TRIGGER_TIMER1_OVERFLOW       
																		  *ADC_AUTO_TRIGGER_TIMER1_CAPTURE_EVENT  *****/

#endif
