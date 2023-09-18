/*
 *
 *<<<<<<<<<<<<<<<<<<<<<KPD_CONFIG_H_>>>>>>>>>>>>>>>>>>>>>>>>
 * Author : ALIAA ESLAM ZAYED
 * Created: 18 /8/2023
 * Layer  : HAL
 * SWC    : KPD
 *
 */
 
 
#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

 /*************This KPD can its pins change if we Choose another virson***********/
u8  KPD_u8Button[4][4]= {{'7', '8', '9', '/' },
	                     {'4', '5', '6', '*' },
						 {'1', '2', '3', '-' },
                         {'c', '0', '=', '+'}};
						 
/********************************** KPD Pins Defines *****************************/						 
#define KPD_ROW_PIN0   DIO_PIN0						 
#define KPD_ROW_PIN1   DIO_PIN1
#define KPD_ROW_PIN2   DIO_PIN2
#define KPD_ROW_PIN3   DIO_PIN3

#define KPD_COL_PIN4   DIO_PIN4
#define KPD_COL_PIN5   DIO_PIN5
#define KPD_COL_PIN6   DIO_PIN6
#define KPD_COL_PIN7   DIO_PIN7

#define KPD_PORT     DIO_PORTA    /**** We Can choose *DIO_PORTA
												      *DIO_PORTB
												      *DIO_PORTC
												      *DIO_PORTD *****/					
#endif
