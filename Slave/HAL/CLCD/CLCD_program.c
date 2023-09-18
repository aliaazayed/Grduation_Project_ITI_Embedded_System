/*
 *
 *<<<<<<<<<<<<<<<<<<<<<CLCD_PROGRAM.c>>>>>>>>>>>>>>>>>>>>>
 * Author : ALIAA ESLAM ZAYED
 * Created: 18 /8/2023
 * Layer  : HAL
 * SWC    : CLCD
 *
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/DIO/DIO_private.h"


#include "CLCD_interface.h"
#include "CLCD_private.h"
#include "CLCD_config.h"


#include <avr/delay.h>

void CLCD_voidInitialization(void)
{
	#if CLCD_MODE ==EIGHT_BIT_MODE
	MDIO_voidSetPortDirection( CLCD_DATA_PORT, DIO_PORT_OUTPUT);
	MDIO_voidSetPinDirection( CLCD_CONTROL_PORT, CLCD_RS_PIN,DIO_PIN_OUTPUT);
	MDIO_voidSetPinDirection( CLCD_CONTROL_PORT, CLCD_RW_PIN,DIO_PIN_OUTPUT);
	MDIO_voidSetPinDirection( CLCD_CONTROL_PORT, CLCD_EN_PIN,DIO_PIN_OUTPUT);

	
	CLCD_voidClearScreen();
	_delay_ms(50);
	CLCD_voidSendCommand(CLCD_RETURN_HOME);
	_delay_ms(50);
	CLCD_voidSendCommand(FUNCTION_SET_TWO_LINE );
	_delay_ms(1);
	CLCD_voidSendCommand(LCD_DISPLAY_ON_CURSOR_OFF_BLINK_OFF  );
	_delay_ms(1);
	CLCD_voidClearScreen();
	CLCD_voidSendCommand(LCD_ENTRY_MODE_SHIFT_LEFT );
	
	#elif CLCD_MODE == FOUR_BIT_MODE
	MDIO_voidSetPinDirection( CLCD_DATA_PORT, CLCD_PIN4, DIO_PIN_OUTPUT);
	MDIO_voidSetPinDirection( CLCD_DATA_PORT, CLCD_PIN5, DIO_PIN_OUTPUT);
	MDIO_voidSetPinDirection( CLCD_DATA_PORT, CLCD_PIN6, DIO_PIN_OUTPUT);
	MDIO_voidSetPinDirection( CLCD_DATA_PORT, CLCD_PIN7, DIO_PIN_OUTPUT);
	MDIO_voidSetPinDirection( CLCD_CONTROL_PORT, CLCD_RS_PIN, DIO_PIN_OUTPUT);
	MDIO_voidSetPinDirection( CLCD_CONTROL_PORT, CLCD_RW_PIN, DIO_PIN_OUTPUT);
	MDIO_voidSetPinDirection( CLCD_CONTROL_PORT, CLCD_EN_PIN, DIO_PIN_OUTPUT);
	
	CLCD_voidSendCommand(CLCD_RETURN_HOME);
	_delay_ms(50);

	CLCD_voidSendCommand(FUNCTION_SET_FOUR_BIT );
	_delay_ms(1);
	CLCD_voidSendCommand(LCD_DISPLAY_ON_CURSOR_OFF_BLINK_OFF  );
	_delay_ms(1);
	CLCD_voidClearScreen();
	CLCD_voidSendCommand(LCD_ENTRY_MODE_SHIFT_LEFT );
	#endif
	
}
	
 void CLCD_voidSendData( u8 copy_u8Data)
 {
	 #if CLCD_MODE == EIGHT_BIT_MODE
	 MDIO_voidSetPortValue(CLCD_DATA_PORT, copy_u8Data);
	 MDIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_PIN_HIGH);
	 MDIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_RW_PIN,DIO_PIN_LOW);
	 CLCD_voidSendFallingEdge ();
	 #elif CLCD_MODE == FOUR_BIT_MODE
	MDIO_voidSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RS_PIN , DIO_PIN_HIGH );
	MDIO_voidSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RW_PIN , DIO_PIN_LOW  );
	MDIO_voidWriteHighNibbles (CLCD_DATA_PORT ,(copy_u8Data>>FOUR_BIT_MODE));            // send the most 4 bits of data to high nibbles
	CLCD_voidSendFallingEdge();
	MDIO_voidWriteHighNibbles (CLCD_DATA_PORT ,copy_u8Data);               // send the least 4 bits of data to high nibbles
	CLCD_voidSendFallingEdge();

	#endif

	_delay_ms(1);
	  
	  
 }
	 
void CLCD_voidSendCommand( u8 copy_u8Command)
{
	 #if CLCD_MODE == EIGHT_BIT_MODE
	 MDIO_voidSetPortValue(CLCD_DATA_PORT,copy_u8Command);
	 MDIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_PIN_LOW);
	 MDIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_RW_PIN,DIO_PIN_LOW);
	 CLCD_voidSendFallingEdge ();
	  #elif CLCD_MODE == FOUR_BIT_MODE
	MDIO_voidSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RS_PIN , DIO_PIN_LOW );
	MDIO_voidSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RW_PIN , DIO_PIN_LOW  );
	MDIO_voidWriteHighNibbles (CLCD_DATA_PORT ,(copy_u8Command>>FOUR_BIT_MODE));            // send the most 4 bits of data to high nibbles
	CLCD_voidSendFallingEdge();
	MDIO_voidWriteHighNibbles (CLCD_DATA_PORT ,copy_u8Command);               // send the least 4 bits of data to high nibbles
	CLCD_voidSendFallingEdge();

	#endif

	_delay_ms(1);
	 
}
void CLCD_voidClearScreen(void)
{
	CLCD_voidSendCommand( LCD_DISPLAY_CLEAR);
	_delay_ms(10);
}
 void CLCD_voidSendString( u8* copy_u8ptrString)
 {
	 u8 LOC_u8Itrator=0;
	 while(copy_u8ptrString[ LOC_u8Itrator])
	 {
		CLCD_voidSendData(copy_u8ptrString[ LOC_u8Itrator]);
		 LOC_u8Itrator++;
	 }
 }	 

 void CLCD_voidSetPosition ( u8 copy_u8Row, u8 copy_u8Column)
 {
	 u8 LOC_u8Data;/*
	 if( (copy_u8Row>2)||(copy_u8Row<1) ||(copy_u8Column>16)||(copy_u8Column<1))
	 {
		 LOC_u8Data=LCD_SET_CURSOR_FIRST_LINE;
	 }
	 else*/ if(copy_u8Row==CLCD_ROW_1)
	 {
		 LOC_u8Data=LCD_SET_CURSOR_FIRST_LINE+(copy_u8Column-1);
	 }
     else if(copy_u8Row==CLCD_ROW_2)
	 {
		 LOC_u8Data=LCD_SET_CURSOR_SECOND_LINE +(copy_u8Column-1);
	 }	
    CLCD_voidSendCommand(LOC_u8Data);
	_delay_ms(1);
 }	




 void CLCD_voidSendFallingEdge (void)
 {
	MDIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_EN_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	MDIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_EN_PIN, DIO_PIN_LOW);
    _delay_ms(1);
 }



void CLCD_voidSendNumber(s32 cpy_u32Number) //123
{      u32 cpy_u32power=1;
       s32 cpy_u32num=cpy_u32Number;
      if(cpy_u32Number==0)
      {
    	  CLCD_voidSendData('0');
    	  return;
      }
      if(cpy_u32Number<0)
      {

    	  cpy_u32Number=cpy_u32Number*(-1);
    	  CLCD_voidSendData('-');
      }
      while(cpy_u32num)
      {//01234

    	  cpy_u32num=cpy_u32num/10;          //01234  0123  012   01   0 0
    	  cpy_u32power=cpy_u32power*10;      //10000
      }
      cpy_u32power=cpy_u32power/10;
      while(cpy_u32power>0)
      {
    	  cpy_u32num=cpy_u32Number/cpy_u32power;  //01234/1000=0
    	  cpy_u32Number%=cpy_u32power;
    	  cpy_u32power/=10;

    	  CLCD_voidSendData(cpy_u32num+'0');
      }




}

void CLCD_voidSendFloat(f64 cpy_f64Float) 
{
	  u32 cpy_u32power=1;
	       s32 cpy_u32num=cpy_f64Float;
	       s32 i=0;

	      if(cpy_f64Float==0)
	      {
	    	  CLCD_voidSendData('0');
	    	  return;
	      }
	      if(cpy_f64Float<0)
	      {

	    	  cpy_f64Float=cpy_f64Float*(-1);
	    	  CLCD_voidSendData('-');
	      }
	      while(cpy_u32num)//1234
	      {

	    	  cpy_u32num=cpy_u32num/10;
	    	   i++;//4
	    	  cpy_u32power=cpy_u32power*10;      //10000
	      }
	      s32 int_num=cpy_f64Float*10000;  //1234.1234-->12341234
	      cpy_u32power=cpy_u32power*1000;
	      while(cpy_u32power>0)
	      {
	    	  cpy_u32num=int_num/cpy_u32power;  //01234/1000=0
	    	  int_num%=cpy_u32power;
	    	  cpy_u32power/=10;
               if(i==0)
               {
            	   CLCD_voidSendData('.');

               }
               i--;
	    	  CLCD_voidSendData(cpy_u32num+'0');
	      }





	/*
	HCLCD_vidSendNumber((s32)cpy_f64Float); //3
	HCLCD_vidSendData('.');//3.
	cpy_f64Float-=(s32)cpy_f64Float;//.14
	while(cpy_f64Float)//0.14*100
	{
		cpy_f64Float*=10;//1.4   4
		HCLCD_vidSendData((s32)cpy_f64Float+'0');//'1'   4
		cpy_f64Float-=(s32)cpy_f64Float;//0.4    0

	}
*/

}

void HLCD_voidDispSpecialChar(u8 * A_u8Array, u8 A_u8Block, u8 A_u8RowId, u8 A_u8ColId)
{
	/**iterator for for loop*/
	u8 L_u8Iterator ;

	/**set CGRAM address (001x xxxx) */
	CLCD_voidSendCommand ((A_u8Block *8) | 0x40) ;

	/** Send the array to be stored */
	for (L_u8Iterator = 0 ;
	     L_u8Iterator <= 7   ;
		 L_u8Iterator ++ )
		 {
			 CLCD_voidSendData (A_u8Array [L_u8Iterator]) ;
		 }

	/* Move the cursor to required position */
	CLCD_voidSetPosition (A_u8RowId , A_u8ColId) ;

	/* Set the block to be displayed */
	CLCD_voidSendData (A_u8Block) ;
}
