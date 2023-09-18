/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    UART_PRIVATE.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Aliaa Eslam Zayed
 *  Created: 30/ 8/ 2023
 *  Layer  : MCAL
 *  SWC    : UART
 *
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define  UDR      (*(volatile  u8*)0x2C)
#define  UCSRA    (*(volatile  u8*)0x2B)
#define  UCSRB    (*(volatile  u8*)0x2A)
#define  UBRRL    (*(volatile  u8*)0x29)
#define  UCSRC    (*(volatile  u8*)0x40)
#define  UBRRH    (*(volatile  u8*)0x40)

#endif																			 