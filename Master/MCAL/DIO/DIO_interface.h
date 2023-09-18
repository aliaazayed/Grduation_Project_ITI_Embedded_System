/*
*
*<<<<<<<<<<<<<<<<<<<<<DIO_INTERFACE_H>>>>>>>>>>>>>>>>>>>>>>>>
* Author : ALIAA ESLAM ZAYED
* Created: 12 /8/2023
* Layer  : MCAL
* SWC    : DIO/GPIO
*
*/

#ifndef  DIO_INTERFACE_H_
#define  DIO_INTERFACE_H_

typedef enum                 //it should be before functions prototypes
 {
	DIO_NOK,
	DIO_OK

 }MDIO_ErrorStatus;


/** PORT Defines****/
#define DIO_PORTA  0
#define DIO_PORTB  1
#define DIO_PORTC  2
#define DIO_PORTD  3


/** PIN Defines****/
#define DIO_PIN0  0
#define DIO_PIN1  1
#define DIO_PIN2  2
#define DIO_PIN3  3
#define DIO_PIN4  4
#define DIO_PIN5  5
#define DIO_PIN6  6
#define DIO_PIN7  7

#define DIO_PINA  PINA
#define DIO_PINB  PINB 
#define DIO_PINC  PINC 
#define DIO_PIND  PIND

/* PIN Directions  */
#define DIO_PIN_OUTPUT		1
#define DIO_PIN_INPUT	    0

/* PIN Value Options */
#define DIO_PIN_HIGH		1
#define DIO_PIN_LOW			0

/* PORT Directions    */
#define DIO_PORT_OUTPUT		0xFF
#define DIO_PORT_INPUT		0

/* PORT Value Options */
#define DIO_PORT_HIGH 		0xFF
#define DIO_PORT_LOW  		0

/* Pull UP */
#define PUD   2

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Functions>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
                                  /******* I/O PINS*******/

/**
	Function Name        : MDIO_voidSetPinDirection
	Function Returns     : void
	Function Arguments   : u8 A_u8PortNo , u8 A_u8PinNo , u8 A_u8PinDirection
	Function Description : Set the direction of the given pin in the given port (direction 0 = input : 1 = output)
*/

void MDIO_voidSetPinDirection (u8 A_u8PortNo , u8 A_u8PinNo , u8 A_u8PinDirection); 

/**
	Function Name        : MDIO_voidSetPinValue
	Function Returns     : void
	Function Arguments   : u8 A_u8PortNo , u8 A_u8PinNo , u8 A_u8Value
	Function Description : Set the value of the given pin in the given port with high
*/

void MDIO_voidSetPinValue (u8 A_u8PortNo , u8 A_u8PinNo  , u8 A_u8Value );

/**
	Function Name        : MDIO_voidClrPinValue
	Function Returns     : void
	Function Arguments   : u8 A_u8PortNo , u8 A_u8PinNo
	Function Description : Set the value of the given pin in the given port with low
*/
void MDIO_voidClrPinValue (u8 A_u8PortNo , u8 A_u8PinNo                            );


/**
	Function Name        : MDIO_voidGetPinValue
	Function Returns     : void
	Function Arguments   : u8 A_u8PortNo , u8 A_u8PinNo , u8 * A_PtrData
	Function Description : Get the value of the given pin in the given port with high
*/

void MDIO_voidGetPinValue (u8 A_u8PortNo , u8 A_u8PinNo  , u8 * A_PtrData );

/**
	Function Name        : MDIO_voidGetPinValue
	Function Returns     : void
	Function Arguments   : u8 A_u8PortNo , u8 A_u8PinNo 
	Function Description : Toggle the value of the given pin in the given port 
*/

void MDIO_voidTogglePinValue (u8 A_u8PortNo , u8 A_u8PinNo              );

                           
						  /********I/O PORT********/


/**
	Function Name        : MDIO_voidSetPortDirection
	Function Returns     : void
	Function Arguments   : u8 A_u8PortNo  , u8 A_u8PinDirection
	Function Description : Set the direction of the given port  
*/

void MDIO_voidSetPortDirection (u8 A_u8PortNo , u8 A_u8PinDirection); 

/**
	Function Name        : MDIO_voidSetPortValue
	Function Returns     : void
	Function Arguments   : u8 A_u8PortNo  , u8 A_u8Value
	Function Description : Set the value of the given port with high
*/

void MDIO_voidSetPortValue   (u8 A_u8PortNo  , u8 A_u8Value       );

/**
	Function Name        : MDIO_voidClrPortValue
	Function Returns     : void
	Function Arguments   : u8 A_u8PortNo 
	Function Description : Set the value of the given  port with low
*/
void MDIO_voidClrPortValue (u8 A_u8PortNo                          );

/**
	Function Name        : MDIO_voidGetPortValue
	Function Returns     : void
	Function Arguments   : u8 A_u8PortNo  , u8 * A_PtrData
	Function Description : Get the value of the given port with high
*/

void MDIO_voidGetPortValue (u8 A_u8PortNo  , u8 * A_PtrData      );

/**
	Function Name        : MDIO_voidGetPinValue
	Function Returns     : void
	Function Arguments   : u8 A_u8PortNo 
	Function Description : Toggle the value of the given  port 
*/

void MDIO_voidTogglePortValue (u8 A_u8PortNo                      );


                                /********Internal Pull Up***************/

/**
	Function Name        : MDIO_voidConnectPullup 
	Function Returns     : void
	Function Arguments   : u8 A_u8PORT ,u8 A_u8PIN, u8 A_u8ConnectPullup
	Function Description : To activate the pull up of the given pin in the given port 
*/								
void MDIO_voidConnectPullup    (u8 A_u8PORT ,u8 A_u8PIN, u8 A_u8ConnectPullup );

/**
	Function Name        : MDIO_voidDisConnectPullup
	Function Returns     : void
	Function Arguments   : void
	Function Description : To disable the pull up of the given pin in the given port 
*/
void MDIO_voidDisConnectPullup            (void                                 );


                               /************* IO Nibbles*************/
/**
	Function Name        : MDIO_voidWriteHighNibbles
	Function Returns     : void
	Function Arguments   : u8 A_u8PORT , u8 value
	Function Description : write a value to the high nibble of the port
*/
void MDIO_voidWriteHighNibbles ( u8 A_u8PORT , u8 A_u8value                      );

/**
	Function Name        : MDIO_voidWriteLowNibbles
	Function Returns     : void
	Function Arguments   : u8 A_u8PORT , u8 value
	Function Description : write a value to the high nibble of the port
*/
void MDIO_voidWriteLowNibbles  ( u8 A_u8PORT , u8 A_u8value                     );


#endif