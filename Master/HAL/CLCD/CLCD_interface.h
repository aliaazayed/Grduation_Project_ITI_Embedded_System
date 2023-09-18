/*
 *
 *<<<<<<<<<<<<<<<<<<<<<CLCD_INTERFACE_H_>>>>>>>>>>>>>>>>>>>>>>>>
 * Author : ALIAA ESLAM ZAYED
 * Created: 18 /8/2023
 * Layer  : HAL
 * SWC    : CLCD
 *
 */
 
 #ifndef CLCD_INTERFACE_H_
 #define CLCD_INTERFACE_H_

 /*** CLCD_PINs Defines*****/
 #define CLCD_PIN0  DIO_PIN0
 #define CLCD_PIN1  DIO_PIN1
 #define CLCD_PIN2  DIO_PIN2
 #define CLCD_PIN3  DIO_PIN3
 #define CLCD_PIN4  DIO_PIN4
 #define CLCD_PIN5  DIO_PIN5
 #define CLCD_PIN6  DIO_PIN6
 #define CLCD_PIN7  DIO_PIN7
 
 /****** CLCD_ROWs ********/
 #define CLCD_ROW_1        1
 #define CLCD_ROW_2        2
 
 /*******CLCD_COLUMNs******/
#define  CLCD_COLUMN_1     1
#define  CLCD_COLUMN_2     2
#define  CLCD_COLUMN_3     3
#define  CLCD_COLUMN_4     4
#define  CLCD_COLUMN_5     5
#define  CLCD_COLUMN_6     6
#define  CLCD_COLUMN_7     7
#define  CLCD_COLUMN_8     8
#define  CLCD_COLUMN_9     9
#define  CLCD_COLUMN_10    10
#define  CLCD_COLUMN_11    11
#define  CLCD_COLUMN_12    12
#define  CLCD_COLUMN_13    13
#define  CLCD_COLUMN_14    14
#define  CLCD_COLUMN_15    15
#define  CLCD_COLUMN_16    16

/********CLCD_MODES*********/
#define EIGHT_BIT_MODE     8
#define FOUR_BIT_MODE      4
 /*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Functions>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
 
/**
	Function Name        : CLCD_voidInitialization
	Function Returns     : void
	Function Arguments   : void
	Function Description : Intialize the LCD and the port as an output
*/
 void CLCD_voidInitialization(void);
 
 /**
	Function Name        : CLCD_voidSendData
	Function Returns     : void
	Function Arguments   : copy_u8Data
	Function Description : Send a data to LCD 
*/
 void CLCD_voidSendData( u8 copy_u8Data);
 
  /**
	Function Name        : CLCD_voidSendCommand
	Function Returns     : void
	Function Arguments   : copy_u8Command
	Function Description : Send a Command to LCD 
*/
 void CLCD_voidSendCommand( u8 copy_u8Command);
 
  /**
	Function Name        : CLCD_voidClearScreen
	Function Returns     : void
	Function Arguments   : void
	Function Description : Clear the  LCD 
*/
 void CLCD_voidClearScreen(void);
 
/**
	Function Name        : CLCD_voidSendString
	Function Returns     : void
	Function Arguments   : copy_u8PtrString
	Function Description : Display an array of string on the LCD
*/
 void CLCD_voidSendString(u8* copy_u8ptrString);
 
 /**
	Function Name        : CLCD_voidSetPosition
	Function Returns     : void
	Function Arguments   : copy_u8Row,  copy_u8Column
	Function Description : Set The cursor on the specific position on the LCD
*/ 
 void CLCD_voidSetPosition (u8 copy_u8Row, u8 copy_u8Column);
 
/**
	Function Name        : CLCD_voidSetExtraChar
	Function Returns     : void
	Function Arguments   : copy_u8Row,  copy_u8Column
	Function Description : send a data on any char don't hava an ASCII code
*/ 
 void CLCD_voidSetExtraChar( u8 copy_u8Row, u8 copy_u8Column);

 void CLCD_voidSendNumber(s32 cpy_u32Number);
 
 void CLCD_voidSendFloat(f64 cpy_f64Float);
 
 //void CLCD_voidDispSpecialChar(u8 * A_u8Array, u8 A_u8Block, u8 A_u8RowId, u8 A_u8ColId);     //car function

 void CLCD_vidSendSpecialChar(const u8* arr_u8Char, u8 cpy_u8BlockNumber);

 #endif
