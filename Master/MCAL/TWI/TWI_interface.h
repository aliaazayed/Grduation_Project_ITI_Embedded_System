/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    TWI_INTERFACE.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Aliaa Eslam Zayed
 *  Created: 3/ 9/ 2023
 *  Layer  : MCAL
 *  SWC    : TWI
 *
 */

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

#define  TWCR_TWIE      DIO_PIN0
#define  TWCR_TWEN      DIO_PIN2
#define  TWCR_TWWC      DIO_PIN3
#define  TWCR_TWSTO     DIO_PIN4
#define  TWCR_TWSTA     DIO_PIN5
#define  TWCR_TWEA      DIO_PIN6
#define  TWCR_TWINT     DIO_PIN7


#define  TWSR_TWPS0     DIO_PIN0
#define  TWSR_TWPS1     DIO_PIN1
#define  TWSR_TWS3      DIO_PIN3
#define  TWSR_TWS4      DIO_PIN4
#define  TWSR_TWS5      DIO_PIN5
#define  TWSR_TWS6      DIO_PIN6
#define  TWSR_TWS7      DIO_PIN7


#define  TWAR_TWGCE     DIO_PIN0
#define  TWAR_TWA0      DIO_PIN1
#define  TWAR_TWA1      DIO_PIN2
#define  TWAR_TWA2      DIO_PIN3
#define  TWAR_TWA3      DIO_PIN4
#define  TWAR_TWA4      DIO_PIN5
#define  TWAR_TWA5      DIO_PIN6
#define  TWAR_TWA6      DIO_PIN7



#define  PRESCULAR_1     0
#define  PRESCULAR_4     1
#define  PRESCULAR_16    2
#define  PRESCULAR_64    3


#define  TWINT_ENABLE    0
#define  TWINT_DISABLE   1

#define  TWI_ACK_ENABLE   0
#define  TWI_ACK_DISABLE  1


#define  TWI_ENABLE    0
#define  TWI_DISABLE   1


#define  TWIE_ENABLE    0
#define  TWIE_DISABLE   1

#define  READ           0
#define  WRITE          1
				       
#define  ACK            0
#define  NOT_ACK        1
				     
void MTWI_voidInitialization(void);

u8 MTWI_u8SendStartCondition(void);

u8 MTWI_u8SendSlaveAddress(u8 A_u8SlaveAddress, u8 A_u8ReadWrite);

u8 MTWI_u8SendData(u8 A_u8Data);

u8 MTWI_u8StopCondition(void);

u8 MTWI_u8GetStatus(void);

u8 MTWI_u8RecieveData(u8 * A_PtrData, u8 A_u8Acknoledge);

#endif																			 