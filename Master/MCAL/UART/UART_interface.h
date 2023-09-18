/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    UART_INTERFACE.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Aliaa Eslam Zayed
 *  Created: 30/ 8/ 2023
 *  Layer  : MCAL
 *  SWC    : UART
 *
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#define  UCSRA_MPCM           DIO_PIN0
#define  UCSRA_U2X            DIO_PIN1
#define  UCSRA_PE             DIO_PIN2
#define  UCSRA_DOR            DIO_PIN3
#define  UCSRA_FE             DIO_PIN4
#define  UCSRA_UDRE           DIO_PIN5
#define  UCSRA_TXC            DIO_PIN6
#define  UCSRA_RXC            DIO_PIN7


#define  UCSRB_TXB8           DIO_PIN0
#define  UCSRB_RXB8           DIO_PIN1
#define  UCSRB_UCSZ2          DIO_PIN2
#define  UCSRB_TXEN           DIO_PIN3
#define  UCSRB_RXEN           DIO_PIN4
#define  UCSRB_UDRIE          DIO_PIN5
#define  UCSRB_TXCIE          DIO_PIN6
#define  UCSRB_RXCIE          DIO_PIN7


#define  UCSRC_UCPOL          DIO_PIN0
#define  UCSRC_UCSZ0          DIO_PIN1
#define  UCSRC_UCSZ1          DIO_PIN2
#define  UCSRC_USBS           DIO_PIN3
#define  UCSRC_UPM0           DIO_PIN4
#define  UCSRC_UPM1           DIO_PIN5
#define  UCSRC_UMSEL          DIO_PIN6
#define  UCSRC_URSEL          DIO_PIN7

#define  UCSZ_5_BIT        0
#define  UCSZ_6_BIT        1
#define  UCSZ_7_BIT        2
#define  UCSZ_8_BIT        3
#define  UCSZ_9_BIT        4


void MUART_voidInitialization(void);

void MUART_voidSendData(u8 A_u8Data);

void MUART_voidSendString(u8 * A_ptrString);

u8 MUART_voidRecieveData(void);

void MUART_voidRecieveString(u8 * A_ptrString);















#endif																			 
