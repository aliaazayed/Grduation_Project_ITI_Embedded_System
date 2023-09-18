/*
*
*<<<<<<<<<<<<<<<<<<<<<DIO_PRIVATE_H>>>>>>>>>>>>>>>>>>>>>>>>
* Author : ALIAA ESLAM ZAYED
* Created: 12 /8/2023
* Layer  : MCAL
* SWC    : DIO/GPIO
*
*/

#ifndef  DIO_PRIVATE_H_
#define  DIO_PRIVATE_H_

/********************
Group PORTA Register
********************/
#define PORTA           *((volatile u8*) 0x3B)   
#define DDRA_Register   *((volatile u8*) 0x3A)
#define PINA            *((volatile u8*) 0x39)

/********************
Group PORTB Register
********************/
#define PORTB           *((volatile u8*) 0x38)   
#define DDRB_Register   *((volatile u8*) 0x37)
#define PINB            *((volatile u8*) 0x36)

/********************
Group PORTC Register
********************/
#define PORTC           *((volatile u8*) 0x35)   
#define DDRC_Register   *((volatile u8*) 0x34)
#define PINC            *((volatile u8*) 0x33)


/********************
Group PORTD Register
********************/
#define PORTD           *((volatile u8*) 0x32)   
#define DDRD_Register   *((volatile u8*) 0x31)
#define PIND            *((volatile u8*) 0x30)

/*PULL UP */
#define  SFIOR   *((volatile u8*)0x50)

#define ENABLE_PULLUP  1
#define DISABLE_PULLUP 2

#endif