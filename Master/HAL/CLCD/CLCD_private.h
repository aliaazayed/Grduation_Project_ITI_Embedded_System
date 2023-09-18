/*
 *
 *<<<<<<<<<<<<<<<<<<<<<CLCD_PRIVATE_H_>>>>>>>>>>>>>>>>>>>>>>>>
 * Author : ALIAA ESLAM ZAYED
 * Created: 18 /8/2023
 * Layer  : HAL
 * SWC    : CLCD
 *
 */
 
 #ifndef CLCD_PRIVATE_H_
 #define CLCD_PRIVATE_H_
 
 static void CLCD_voidSendFallingEdge (void); /*Function to falling the clock edge ,"We define it here to force the customer not use it*/ 

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Initialization>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#define CLCD_RETURN_HOME        0x02         /*instruction to make AC point to 00 Address */
/********************************************1-Function Set*******************************************************************/ 
#define FUNCTION_SET_FOUR_BIT  0x28         /* instruction function set on the four bit mode*/
#define FUNCTION_SET_ONE_LINE  0x30         /*instrucion function set on the eight bit mode with 1_line display & 5*7 dot prouct */ 
#define FUNCTION_SET_TWO_LINE  0x38         /*instrucion function set on the eight bit mode with 2_line display & 5*7 dot prouct */  
 
/**************************************2-_DISPLAY on/off& CURSOR on/off& BLINK on/off*****************************************
****************************************instruction= 0b0000 1 D C B **********************************************************
**************************************                D=0 "Display off, we use it if we don't want to show what is char, app:password
                                                      D=1  "display on"
													  C = "0-->Cursor off/ 1-->Cursor on"
													  B = "0-->Blink off/  1-->Blink on "
************************************************************************************************************************************/
#define LCD_DISPLAY_OFF_CURSOR_OFF_BLINK_OFF    0x08         
#define LCD_DISPLAY_ON_CURSOR_OFF_BLINK_OFF     0x0c         
#define LCD_DISPLAY_OFF_CURSOR_OFF_BLINK_ON     0x09         
													         
/***************************************3- Clear the Screen *******************************************************************/   													        													         
#define LCD_DISPLAY_CLEAR                       0x01         /*instruction to clear the LCD*/

/**************************************4- Entry Mode ***************************************************************************/
#define LCD_ENTRY_MODE_SHIFT_LEFT               0x06         /* instruction  left to Right */ 
#define LCD_ENTRY_MODE_SHIFT_RIGHT              0x07         /* instruction  Right to left */

/*****************************************End of initialization******************************************************************/



/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Cursor Position >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

#define LCD_SET_CURSOR_FIRST_LINE              0x80         /* To  set the cursor on the first line of the first position*/
#define LCD_SET_CURSOR_SECOND_LINE             0xc0         /* To  set the cursor on the second line of the first position*/

/**<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< AC position(CGRAM/DDRAM)>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#define CLCD_CGRAM_COMMAND                       0x04
#define CLCD_DDRAM_COMMAND                       0x08
 
 #endif
