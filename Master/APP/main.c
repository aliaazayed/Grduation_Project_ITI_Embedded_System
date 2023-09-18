/*
 * Module name: 	 Master
 * File name :       main.c
 * File description: this file contains master main function
 * Version: 		 v01
 * Date:    		 9/9/2023
 * Author:  		 Salma Motaz
 */

#if 1

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/DIO/DIO_interface.h"

#include "../MCAL/UART/UART_interface.h"
#include "../MCAL/UART/UART_config.h"

#include "../HAL/CLCD/CLCD_interface.h"
#include "../HAL/CLCD/CLCD_config.h"

#include "../HAL/KPD/KPD_interface.h"

#include "../HAL/EEPROM/EEPROM_interface.h"

#include <avr/delay.h>

#define EEPROM_PosistionCount_LOCATION			1
#define EEPROM_AdminPasswordStatus_LOCATION 	2
#define EEPROM_AdminPassword_LOCATION			3
#define EEPROM_AlarmPassword_LOCATION			7
#define EEPROM_GuestPassword_LOCATION			11
#define EEPROM_ID1_LOCATION						15

typedef struct Data
{
	u8 st_arr_u8Password [5];
}ST_Data_t;


u8 gol_u8Mode, gol_u8FlagMode, gol_u8PosistionCount,gol_u8FlagMode_A,gol_u8Mode_A;

void APP_voidInitFuncation(void);
void APP_vidAdminFunction (void);
void APP_voidAdminMenu(void);
void APP_vidAddUserFuncation(void);
void APP_vidDeleteUserFuncation(void);
void APP_vidChangeGuestPasswordFuncation(void);
void APP_vidUserFunction (void);
void APP_vidGuestFunction (void);
void APP_vidAlarmFunction(void);

int main()
{
	MDIO_voidSetPinDirection(DIO_PORTC, DIO_PIN2, DIO_PIN_OUTPUT);

	MUART_voidInitialization();
	HEEPROM_voidInitialization();
	CLCD_voidInitialization();
	HKPD_voidInitialization();

#if 1

	u8 loc_u8PressedKey;

	gol_u8PosistionCount = HEEPROM_u8ReadData(EEPROM_PosistionCount_LOCATION);

	CLCD_voidSetPosition(0,4);
	CLCD_voidSendString("Welcome");
	MUART_voidSendData('w');
	_delay_ms(200);
	CLCD_voidClearScreen();

	if (HEEPROM_u8ReadData(EEPROM_AdminPasswordStatus_LOCATION) == '0')
	{
		APP_voidInitFuncation();
	}

	gol_u8Mode = 0;
	gol_u8FlagMode = 0;

	while(1)
	{
		loc_u8PressedKey = HKPD_u8GetPressedKey();

		CLCD_voidSetPosition(0,0);
		CLCD_voidSendString("1 Admin 2 User");
		CLCD_voidSetPosition(1,0);
		CLCD_voidSendString("3 Guest 4 StopAl");

		MUART_voidSendData('w');

		if(loc_u8PressedKey != NOT_PRESSED)
		{
			if (gol_u8FlagMode == 0 && loc_u8PressedKey < '5' && loc_u8PressedKey > '0')
			{
				gol_u8Mode = loc_u8PressedKey;
				loc_u8PressedKey = NOT_PRESSED;
				gol_u8FlagMode = 1;
			}

			if(gol_u8Mode == '1')
			{
				APP_vidAdminFunction ();
			}

			if(gol_u8Mode == '2')
			{
				APP_vidUserFunction ();
			}

			if(gol_u8Mode == '3')
			{
				APP_vidGuestFunction ();
			}

			if(gol_u8Mode == '4')
			{
				APP_vidAlarmFunction();
			}
		}
	}

#endif

#if 0

	u8 volatile i = 0;
	u8 loc_u8Value[256],j=0;

	//CLCD_voidSendData('10');
	//CLCD_voidSendData('11');
	for (i = 1; i < 255 ; i++)
	{
		_delay_ms(20);
		//HEEPROM_voidWriteData(i,0xff);
		//HEEPROM_voidWriteData(i,'1');
		HEEPROM_voidWriteData(i,'0');
	}

	for (i = 1; i<255; i++)
	{
		_delay_ms(20);
		loc_u8Value[j] = HEEPROM_u8ReadData(i);
		j++;
		//CLCD_voidSendNumber(loc_u8Value);
		//CLCD_voidSendData(loc_u8Value);
		//CLCD_voidSendData('255');
		//CLCD_voidSendString(loc_u8Value);
	}
	CLCD_voidSendString(loc_u8Value);
#endif

}

void APP_voidInitFuncation(void)
{
	u8 loc_u8PressedKey; volatile loc_u8CountPassword;
	u8 loc_AAGOutValue = 0;
	CLCD_voidClearScreen();
	CLCD_voidSendString("c in password");
	CLCD_voidSetPosition(1,0);
	CLCD_voidSendString("mode to clear");
	_delay_ms(250);
	CLCD_voidClearScreen();
	CLCD_voidSendString(" = To next step");
	_delay_ms(250);
	CLCD_voidClearScreen();

	CLCD_voidSendString("Enter Admin PW");
	CLCD_voidSetPosition(1,0);

	while(1)
	{
		MUART_voidSendData('w');
		for(loc_u8CountPassword  = 1; loc_u8CountPassword < 6; loc_u8CountPassword++)
		{
			MUART_voidSendData('w');
			do
			{
				loc_u8PressedKey = HKPD_u8GetPressedKey();
			}while(	loc_u8PressedKey == NOT_PRESSED);


			if(loc_u8PressedKey == 'c' && loc_AAGOutValue == 0 )
			{
				loc_u8CountPassword = 0;
				CLCD_voidSetPosition(1, loc_u8CountPassword);
				CLCD_voidSendData(' ');
				_delay_ms(100);
			}

			if (loc_u8PressedKey == 'c')
			{
				if (loc_AAGOutValue == 1)
				{
					CLCD_voidSetPosition(1, loc_u8CountPassword-2);
					CLCD_voidSendData(' ');
					_delay_ms(200);
					CLCD_voidSetPosition(1, loc_u8CountPassword-2);
					loc_u8CountPassword-=2;
				}
				if (loc_u8CountPassword == 1 || loc_u8CountPassword == 0)
				{
					loc_AAGOutValue = 0;
					loc_u8CountPassword = 0;
					CLCD_voidSetPosition(1, loc_u8CountPassword);
				}
			}
			else if (loc_u8CountPassword < 5)
			{
				loc_AAGOutValue = 1;
				CLCD_voidSendData(loc_u8PressedKey);
				_delay_ms(200);
				CLCD_voidSetPosition(1, loc_u8CountPassword-1);
				CLCD_voidSendData('*');
				_delay_ms(200);
				HEEPROM_voidWriteData(EEPROM_AdminPassword_LOCATION + loc_u8CountPassword-1,loc_u8PressedKey);
			}
			else if (loc_u8PressedKey == '=' && loc_u8CountPassword >= 5)
			{
				loc_u8PressedKey = '=';
				break;
			}
			else
			{
				loc_u8CountPassword-=1;
			}
		}

		if(loc_u8PressedKey == '=')
		{
			CLCD_voidClearScreen();
			CLCD_voidSendString("Data added");
			CLCD_voidSetPosition(1,0);
			CLCD_voidSendString("successfully");
			loc_AAGOutValue = 0;
			_delay_ms(250);
			break;
		}
	}

	CLCD_voidClearScreen();
	CLCD_voidSendString("Enter Alarm PW");
	CLCD_voidSetPosition(1,0);

	while(1)
	{
		MUART_voidSendData('w');
		for(loc_u8CountPassword  = 1; loc_u8CountPassword < 6; loc_u8CountPassword++)
		{
			do
			{
				loc_u8PressedKey = HKPD_u8GetPressedKey();
			}while(	loc_u8PressedKey == NOT_PRESSED);

			if(loc_u8PressedKey == 'c' && loc_AAGOutValue == 0 )
			{
				loc_u8CountPassword = 0;
				CLCD_voidSetPosition(1, loc_u8CountPassword);
				CLCD_voidSendData(' ');
				_delay_ms(200);
			}

			if (loc_u8PressedKey == 'c')
			{
				if (loc_AAGOutValue == 1)
				{
					CLCD_voidSetPosition(1, loc_u8CountPassword-2);
					CLCD_voidSendData(' ');
					_delay_ms(200);
					CLCD_voidSetPosition(1, loc_u8CountPassword-2);
					loc_u8CountPassword-=2;
				}
				if (loc_u8CountPassword == 1 || loc_u8CountPassword == 0)
				{
					loc_AAGOutValue = 0;
					loc_u8CountPassword = 0;
					CLCD_voidSetPosition(1, loc_u8CountPassword);
				}
			}
			else if (loc_u8CountPassword < 5)
			{
				loc_AAGOutValue = 1;
				CLCD_voidSendData(loc_u8PressedKey);
				_delay_ms(200);
				CLCD_voidSetPosition(1, loc_u8CountPassword-1);
				CLCD_voidSendData('*');
				_delay_ms(200);
				HEEPROM_voidWriteData(EEPROM_AlarmPassword_LOCATION + loc_u8CountPassword-1,loc_u8PressedKey);
			}
			else if (loc_u8PressedKey == '=' && loc_u8CountPassword >= 5)
			{
				loc_u8PressedKey = '=';
				break;
			}
			else
			{
				loc_u8CountPassword-=1;
			}
		}

		if(loc_u8PressedKey == '=')
		{
			CLCD_voidClearScreen();
			CLCD_voidSendString("Data added");
			CLCD_voidSetPosition(1,0);
			CLCD_voidSendString("successfully");
			loc_AAGOutValue = 0;
			_delay_ms(250);
			break;
		}
	}

	CLCD_voidClearScreen();
	CLCD_voidSendString("Enter Guest PW");
	CLCD_voidSetPosition(1,0);

	while(1)
	{
		MUART_voidSendData('w');
		for(loc_u8CountPassword  = 1; loc_u8CountPassword < 6; loc_u8CountPassword++)
		{
			do
			{
				loc_u8PressedKey = HKPD_u8GetPressedKey();
			}while(	loc_u8PressedKey == NOT_PRESSED);

			if(loc_u8PressedKey == 'c' && loc_AAGOutValue == 0 )
			{
				loc_u8CountPassword = 0;
				CLCD_voidSetPosition(1, loc_u8CountPassword);
				CLCD_voidSendData(' ');
				_delay_ms(200);
			}

			if (loc_u8PressedKey == 'c')
			{
				if (loc_AAGOutValue == 1)
				{
					CLCD_voidSetPosition(1, loc_u8CountPassword-2);
					CLCD_voidSendData(' ');
					_delay_ms(200);
					CLCD_voidSetPosition(1, loc_u8CountPassword-2);
					loc_u8CountPassword-=2;
				}
				if (loc_u8CountPassword == 1 || loc_u8CountPassword == 0)
				{
					loc_AAGOutValue = 0;
					loc_u8CountPassword = 0;
					CLCD_voidSetPosition(1, loc_u8CountPassword);
				}
			}
			else if (loc_u8CountPassword < 5)
			{
				loc_AAGOutValue = 1;
				CLCD_voidSendData(loc_u8PressedKey);
				_delay_ms(200);
				CLCD_voidSetPosition(1, loc_u8CountPassword-1);
				CLCD_voidSendData('*');
				_delay_ms(200);
				HEEPROM_voidWriteData(EEPROM_GuestPassword_LOCATION + loc_u8CountPassword-1,loc_u8PressedKey);
			}
			else if (loc_u8PressedKey == '=' && loc_u8CountPassword >= 5)
			{
				loc_u8PressedKey = '=';
				break;
			}
			else
			{
				loc_u8CountPassword-=1;
			}
		}

		if(loc_u8PressedKey == '=')
		{
			CLCD_voidClearScreen();
			CLCD_voidSendString("Data added");
			CLCD_voidSetPosition(1,0);
			CLCD_voidSendString("successfully");
			HEEPROM_voidWriteData(EEPROM_AdminPasswordStatus_LOCATION,'1');
			_delay_ms(250);
			break;
		}
	}
}

void APP_vidUserFunction (void)
{
#if 1
	ST_Data_t User;
	u8 loc_u8PressedKey = NOT_PRESSED;

	u8 volatile loc_UserFlag = 0, loc_UserTrail = 1, loc_UserOutValue = 0;
	u8 loc_u8PosistionCount = 0, loc_u8CountPassword = 0,loc_u8IDLocation,loc_u8IDValue = ' ',loc_u8IDCheckFlag = 0;

	u8 loc_u8AlarmBuffer;
	MDIO_voidGetPinValue(DIO_PORTC, DIO_PIN2, &loc_u8AlarmBuffer);

	if(loc_u8AlarmBuffer == DIO_PIN_LOW)
	{
		CLCD_voidClearScreen();
		CLCD_voidSendString("Welcome to User");
		CLCD_voidSetPosition(1,0);
		CLCD_voidSendString("Mode");
		_delay_ms(250);
		CLCD_voidClearScreen();
		CLCD_voidSendString(" c for Exit");
		_delay_ms(250);
		CLCD_voidClearScreen();
		CLCD_voidSendString(" = To next step");
		_delay_ms(250);
		CLCD_voidClearScreen();

		while(loc_UserFlag == 0)
		{
#if 1
			while(1)
			{
				MUART_voidSendData('w');

				if(loc_u8PressedKey != 'c')
				{
					loc_u8PressedKey = HKPD_u8GetPressedKey();

					CLCD_voidClearScreen();
					CLCD_voidSendString("+ in ID mode to ");
					CLCD_voidSetPosition(1,0);
					CLCD_voidSendString("clear");
					_delay_ms(250);

					CLCD_voidClearScreen();
					CLCD_voidSendString("Enter user ID");
					CLCD_voidSetPosition(1,0);
				}

				if(loc_u8PressedKey == 'c')
				{
					loc_u8PressedKey = 'c';
					loc_UserFlag = 0;
					CLCD_voidClearScreen();
					break;
				}


				loc_u8IDValue = ' ';
				while(1)
				{
					MUART_voidSendData('w');
					loc_u8PressedKey = HKPD_u8GetPressedKey();

					if (loc_u8PressedKey != NOT_PRESSED && loc_u8PressedKey != '+' && loc_u8PressedKey != '=' && loc_u8PressedKey != 'c' && loc_u8IDValue == ' ')
					{
						loc_u8IDValue = loc_u8PressedKey;
						CLCD_voidSendData(loc_u8IDValue);
					}

					if(loc_u8PressedKey == 'c')
					{
						loc_u8PressedKey = 'c';
						break;
					}

					if(loc_u8PressedKey == '+')
					{
						CLCD_voidSetPosition(1,0);
						CLCD_voidSendData(' ');
						loc_u8IDValue = ' ';
						CLCD_voidSetPosition(1,0);
					}

					if(loc_u8PressedKey == '=')
					{
						if(loc_u8IDValue >= '0' && loc_u8IDValue < '10')
						{
							CLCD_voidClearScreen();
							break;
						}
						else if (loc_u8IDValue == ' ')
						{
							CLCD_voidClearScreen();
							CLCD_voidSendString("Enter ID");
							_delay_ms(250);
							CLCD_voidClearScreen();
							CLCD_voidSendString("Enter user ID");
							CLCD_voidSetPosition(1,0);
						}
						else
						{
							CLCD_voidClearScreen();
							CLCD_voidSendString("Invalid operator");
							loc_u8IDValue = ' ';
							_delay_ms(250);
							CLCD_voidClearScreen();
							CLCD_voidSendString("Enter user ID");
							CLCD_voidSetPosition(1,0);
						}
					}
				}

				if(loc_u8PressedKey == 'c')
				{
					continue;
				}

				if(loc_u8IDValue > '0' && loc_u8IDValue < '6')
				{
					loc_u8IDLocation = EEPROM_ID1_LOCATION;
					u8 loc_u8IDCountPosistion = '1';

					while(1)
					{
						if(loc_u8IDValue != HEEPROM_u8ReadData(loc_u8IDLocation) && loc_u8IDValue == loc_u8IDCountPosistion)
						{
							break;
						}
						else if (loc_u8IDValue == HEEPROM_u8ReadData(loc_u8IDLocation))
						{
							loc_u8IDCheckFlag = 1;
							break;
						}
						else
						{
							loc_u8IDLocation += 5;
							loc_u8IDCountPosistion++;
						}

						if(loc_u8IDLocation == 36)
						{
							break;
						}
						_delay_ms(20);
					}

					if(loc_u8IDCheckFlag == 1)
					{
						CLCD_voidClearScreen();
						CLCD_voidSendString("c in password");
						CLCD_voidSetPosition(1,0);
						CLCD_voidSendString("mode to clear");
						_delay_ms(250);

						CLCD_voidClearScreen();
						CLCD_voidSendString("Enter password");
						CLCD_voidSetPosition(1,0);
						u8 loc_u8Key = 0;

						for(loc_u8CountPassword  = 1; loc_u8CountPassword < 6; loc_u8CountPassword++)
						{
							MUART_voidSendData('w');
							do
							{
								loc_u8PressedKey = HKPD_u8GetPressedKey();
							}while(	loc_u8PressedKey == NOT_PRESSED);

							if(loc_u8PressedKey == 'c' && loc_UserOutValue == 0 )
							{
								loc_u8CountPassword = 0;
								CLCD_voidSetPosition(1, loc_u8CountPassword);
								CLCD_voidSendData(' ');
								loc_u8CountPassword = 0;
								_delay_ms(200);
							}

							if (loc_u8PressedKey == 'c')
							{
								if (loc_UserOutValue == 1)
								{
									CLCD_voidSetPosition(1, loc_u8CountPassword-2);
									CLCD_voidSendData(' ');
									_delay_ms(200);
									CLCD_voidSetPosition(1, loc_u8CountPassword-2);
									loc_u8CountPassword-=2;
								}
								if (loc_u8CountPassword == 1 || loc_u8CountPassword == 0)
								{
									loc_UserOutValue = 0;
									loc_u8CountPassword = 0;
									CLCD_voidSetPosition(1, loc_u8CountPassword);
								}
							}
							else if (loc_u8CountPassword < 5)
							{
								loc_UserOutValue = 1;
								CLCD_voidSendData(loc_u8PressedKey);
								_delay_ms(200);
								CLCD_voidSetPosition(1, loc_u8CountPassword-1);
								CLCD_voidSendData('*');
								_delay_ms(200);
								User.st_arr_u8Password[loc_u8CountPassword-1] = loc_u8PressedKey;
							}
							else if (loc_u8PressedKey == '=' && loc_u8CountPassword >= 5)
							{
								loc_u8PressedKey = '=';
								break;
							}
							else
							{
								loc_u8CountPassword-=1;
							}
						}

						if(User.st_arr_u8Password[0] != HEEPROM_u8ReadData(loc_u8IDLocation + 1) || User.st_arr_u8Password[1] != HEEPROM_u8ReadData(loc_u8IDLocation + 2) || User.st_arr_u8Password[2] != HEEPROM_u8ReadData(loc_u8IDLocation + 3) || User.st_arr_u8Password[3] != HEEPROM_u8ReadData(loc_u8IDLocation + 4))
						{
							loc_UserFlag = 1;
							CLCD_voidClearScreen();
							CLCD_voidSendString("Wrong password");
							loc_u8PressedKey = 0;
							break;
						}

						if(loc_UserFlag == 0 || loc_UserFlag == 1 )
						{
							break;
						}

					}
					else
					{
						CLCD_voidClearScreen();
						CLCD_voidSendString("ID doesn't exist");
						loc_UserFlag = 1;
						break;
					}
				}
				else
				{
					CLCD_voidClearScreen();
					CLCD_voidSendString("Invalid ID");
					loc_UserFlag = 1;
					break;
				}

			}
#endif
			if(loc_u8PressedKey == 'c' && loc_UserFlag == 0)
			{
				break;
			}

			if(loc_UserFlag == 1 && loc_UserTrail < 3)
			{
				CLCD_voidSetPosition(1,0);
				CLCD_voidSendString("Tries left: ");
				CLCD_voidSendNumber(3-loc_UserTrail);
				loc_UserTrail++;
				loc_UserFlag = 0;
				_delay_ms(250);
				CLCD_voidClearScreen();
			}
			else
			{
				if(loc_UserFlag == 0)
				{
					break;
				}
				else if(loc_UserTrail == 3)
				{
					_delay_ms(250);
					CLCD_voidClearScreen();
					CLCD_voidSendString("Can not sign in");
					MDIO_voidSetPinValue(DIO_PORTC, DIO_PIN2, DIO_PIN_OUTPUT);
					_delay_ms(250);
					loc_UserFlag = 1;
					CLCD_voidClearScreen();
				}

			}
		}

		if (loc_UserFlag == 0 && loc_u8PressedKey != 'c')
		{
			loc_UserTrail = 1;
			CLCD_voidClearScreen();
			CLCD_voidSendString("Sign in");
			CLCD_voidSetPosition(1,0);
			CLCD_voidSendString("successfully");
			MUART_voidSendData('s');
			_delay_ms(1000);
			gol_u8FlagMode = 0;
			gol_u8Mode = 0;

		}
		else
		{
			gol_u8FlagMode = 0;
			gol_u8Mode = 0;
			CLCD_voidClearScreen();
		}

	}
	else
	{
		CLCD_voidClearScreen();
		CLCD_voidSendString("Close Alarm");
		CLCD_voidSetPosition(1,0);
		CLCD_voidSendString("first");
		_delay_ms(250);
		gol_u8FlagMode = 0;
		gol_u8Mode = 0;
		CLCD_voidClearScreen();
	}
#endif
}

void APP_vidGuestFunction (void)
{

#if 1
	ST_Data_t Guest;
	u8 loc_u8PressedKey,loc_u8CountPassword;
	u8 loc_GuestFlag = 0, loc_GuestTrail = 1, loc_GuestOutValue = 0;

	u8 loc_u8AlarmBuffer;
	MDIO_voidGetPinValue(DIO_PORTC, DIO_PIN2, &loc_u8AlarmBuffer);

	if(loc_u8AlarmBuffer == DIO_PIN_LOW)
	{
		CLCD_voidClearScreen();
		CLCD_voidSendString("Welcome to guest");
		CLCD_voidSetPosition(1,0);
		CLCD_voidSendString("Mode");
		_delay_ms(250);
		CLCD_voidClearScreen();
		CLCD_voidSendString(" c for Exit");
		_delay_ms(250);
		CLCD_voidClearScreen();
		CLCD_voidSendString(" = To next step");
		_delay_ms(250);
		CLCD_voidClearScreen();

		while(loc_GuestFlag == 0)
		{
			MUART_voidSendData('w');

			CLCD_voidSendString("Enter guest PW");
			CLCD_voidSetPosition(1,0);
			while(1)
			{
				MUART_voidSendData('w');

				loc_u8PressedKey = HKPD_u8GetPressedKey();

				for(loc_u8CountPassword  = 1; loc_u8CountPassword < 6; loc_u8CountPassword++)
				{
					MUART_voidSendData('w');
					do
					{
						loc_u8PressedKey = HKPD_u8GetPressedKey();
					}while(	loc_u8PressedKey == NOT_PRESSED);

					if(loc_u8PressedKey == 'c' && loc_GuestOutValue == 0)
					{
						loc_u8PressedKey = 'c';
						break;
					}

					if (loc_u8PressedKey == 'c')
					{
						CLCD_voidSetPosition(1, loc_u8CountPassword-2);
						CLCD_voidSendData(' ');
						_delay_ms(200);
						CLCD_voidSetPosition(1, loc_u8CountPassword-2);
						loc_u8CountPassword-=2;
						if(loc_u8CountPassword == 1 || loc_u8CountPassword == 0)
						{
							loc_GuestOutValue = 0;
						}
					}
					else if (loc_u8CountPassword < 5)
					{
						loc_GuestOutValue = 1;
						CLCD_voidSendData(loc_u8PressedKey);
						_delay_ms(200);
						CLCD_voidSetPosition(1, loc_u8CountPassword-1);
						CLCD_voidSendData('*');
						_delay_ms(200);
						Guest.st_arr_u8Password[loc_u8CountPassword-1] = loc_u8PressedKey;
					}
					else if (loc_u8PressedKey == '=' && loc_u8CountPassword > 4)
					{
						loc_u8PressedKey = '=';
						break;
					}
					else
					{
						loc_u8CountPassword-=1;
					}
				}


				if (loc_u8PressedKey == 'c')
				{
					loc_GuestFlag = 0;
					break;
				}

				if(Guest.st_arr_u8Password[0] != HEEPROM_u8ReadData(EEPROM_GuestPassword_LOCATION) || Guest.st_arr_u8Password[1] != HEEPROM_u8ReadData(EEPROM_GuestPassword_LOCATION + 1) || Guest.st_arr_u8Password[2] != HEEPROM_u8ReadData(EEPROM_GuestPassword_LOCATION + 2) || Guest.st_arr_u8Password[3] != HEEPROM_u8ReadData(EEPROM_GuestPassword_LOCATION + 3))
				{
					loc_GuestFlag = 1;
				}

				if(loc_GuestFlag == 1 || loc_GuestFlag == 0)
				{
					break;
				}
			}

			if(loc_u8PressedKey == 'c' && loc_GuestFlag == 0)
			{
				break;
			}

			if(loc_GuestFlag == 1 && loc_GuestTrail < 3)
			{
				CLCD_voidClearScreen();
				CLCD_voidSendString("Wrong password");
				CLCD_voidSetPosition(1,0);
				CLCD_voidSendString("Tries left: ");
				CLCD_voidSendNumber(3-loc_GuestTrail);
				loc_GuestTrail++;
				loc_GuestFlag = 0;
				_delay_ms(250);
				CLCD_voidClearScreen();
			}
			else
			{
				if(loc_GuestFlag == 0)
				{
					break;
				}
				else if(loc_GuestTrail == 3)
				{
					CLCD_voidClearScreen();
					CLCD_voidSendString("Wrong password");
					_delay_ms(250);
					CLCD_voidClearScreen();
					CLCD_voidSendString("Can not sign in");
					MDIO_voidSetPinValue(DIO_PORTC, DIO_PIN2, DIO_PIN_OUTPUT);
					_delay_ms(250);
					loc_GuestFlag = 1;
					CLCD_voidClearScreen();
				}

			}
		}

		if(loc_u8PressedKey == 'c' && loc_GuestFlag == 0)
		{
			gol_u8Mode = 0;
			gol_u8FlagMode = 0;
			CLCD_voidClearScreen();
		}
		else if (loc_GuestFlag == 0)
		{
			loc_GuestTrail = 1;
			CLCD_voidClearScreen();
			CLCD_voidSendString("Sign in");
			CLCD_voidSetPosition(1,0);
			CLCD_voidSendString("successfully");
			MUART_voidSendData('s');
			_delay_ms(1000);
			gol_u8FlagMode = 0;
			gol_u8Mode = 0;
		}
		else
		{
			gol_u8FlagMode = 0;
			gol_u8Mode = 0;
			CLCD_voidClearScreen();
		}

	}
	else
	{
		CLCD_voidClearScreen();
		CLCD_voidSendString("Close Alarm");
		CLCD_voidSetPosition(1,0);
		CLCD_voidSendString("first");
		_delay_ms(250);
		gol_u8FlagMode = 0;
		gol_u8Mode = 0;
		CLCD_voidClearScreen();
	}
#endif
}

void APP_vidAlarmFunction(void)
{
#if 1
	ST_Data_t Alarm;
	u8 loc_AlarmFlag = 0, loc_AlarmTrail = 1, loc_AlarmOutValue = 0;

	u8 loc_u8PressedKey, loc_u8CountPassword;
	u8 loc_u8AlarmBuffer;

	MDIO_voidGetPinValue(DIO_PORTC, DIO_PIN2, &loc_u8AlarmBuffer);

	if(loc_u8AlarmBuffer == DIO_PIN_HIGH)
	{
		CLCD_voidClearScreen();
		CLCD_voidSendString("c in password");
		CLCD_voidSetPosition(1,0);
		CLCD_voidSendString("mode to clear");
		_delay_ms(250);
		CLCD_voidClearScreen();
		CLCD_voidSendString(" c for Exit");
		_delay_ms(250);
		CLCD_voidClearScreen();
		CLCD_voidSendString(" = To next step");
		_delay_ms(250);
		CLCD_voidClearScreen();

		while(loc_AlarmFlag == 0)
		{
			MUART_voidSendData('w');

			CLCD_voidSendString("Enter Alarm PW");
			CLCD_voidSetPosition(1,0);
			while(1)
			{
				MUART_voidSendData('w');

				loc_u8PressedKey = HKPD_u8GetPressedKey();

				for(loc_u8CountPassword  = 1; loc_u8CountPassword < 6; loc_u8CountPassword++)
				{
					MUART_voidSendData('w');

					do
					{
						loc_u8PressedKey = HKPD_u8GetPressedKey();
					}while(	loc_u8PressedKey == NOT_PRESSED);

					if(loc_u8PressedKey == 'c' && loc_AlarmOutValue == 0)
					{
						loc_u8PressedKey = 'c';
						break;
					}

					if (loc_u8PressedKey == 'c')
					{
						CLCD_voidSetPosition(1, loc_u8CountPassword-2);
						CLCD_voidSendData(' ');
						_delay_ms(200);
						CLCD_voidSetPosition(1, loc_u8CountPassword-2);
						loc_u8CountPassword-=2;
						if(loc_u8CountPassword == 1 || loc_u8CountPassword == 0)
						{
							loc_AlarmOutValue = 0;
						}
					}
					else if (loc_u8CountPassword < 5)
					{
						loc_AlarmOutValue = 1;
						CLCD_voidSendData(loc_u8PressedKey);
						_delay_ms(200);
						CLCD_voidSetPosition(1, loc_u8CountPassword-1);
						CLCD_voidSendData('*');
						_delay_ms(200);
						Alarm.st_arr_u8Password[loc_u8CountPassword-1] = loc_u8PressedKey;
					}
					else if (loc_u8PressedKey == '=' && loc_u8CountPassword > 4)
					{
						break;
					}
					else if (loc_u8PressedKey == '=' && loc_u8CountPassword > 4)
					{
						loc_u8PressedKey = '=';
						break;
					}
					else
					{
						loc_u8CountPassword-=1;
					}
				}

				if (loc_u8PressedKey == 'c')
				{
					loc_AlarmFlag = 0;
					break;
				}

				if(Alarm.st_arr_u8Password[0] != HEEPROM_u8ReadData(EEPROM_AlarmPassword_LOCATION) || Alarm.st_arr_u8Password[1] != HEEPROM_u8ReadData(EEPROM_AlarmPassword_LOCATION + 1) || Alarm.st_arr_u8Password[2] != HEEPROM_u8ReadData(EEPROM_AlarmPassword_LOCATION + 2) || Alarm.st_arr_u8Password[3] != HEEPROM_u8ReadData(EEPROM_AlarmPassword_LOCATION + 3))
				{
					loc_AlarmFlag = 1;
				}

				if(loc_AlarmFlag == 1 || loc_AlarmFlag == 0)
				{
					break;
				}
			}

			if(loc_u8PressedKey == 'c' && loc_AlarmFlag == 0)
			{
				break;
			}

			if(loc_AlarmFlag == 1 && loc_AlarmTrail < 3)
			{
				CLCD_voidClearScreen();
				CLCD_voidSendString("Wrong password");
				CLCD_voidSetPosition(1,0);
				CLCD_voidSendString("Tries left: ");
				CLCD_voidSendNumber(3-loc_AlarmTrail);
				loc_AlarmTrail++;
				loc_AlarmFlag = 0;
				_delay_ms(250);
				CLCD_voidClearScreen();
			}
			else
			{
				if(loc_AlarmFlag == 0)
				{
					break;
				}
				else if(loc_AlarmTrail == 3)
				{
					CLCD_voidClearScreen();
					CLCD_voidSendString("Wrong password");
					_delay_ms(250);
					CLCD_voidClearScreen();
					CLCD_voidSendString("Can not close ");
					CLCD_voidSetPosition(1,0);
					CLCD_voidSendString("alarm");
					MDIO_voidSetPinValue(DIO_PORTC, DIO_PIN2, DIO_PIN_OUTPUT);
					_delay_ms(250);
					loc_AlarmFlag = 1;
					CLCD_voidClearScreen();
				}

			}
		}

		if(loc_u8PressedKey == 'c' && loc_AlarmFlag == 0)
		{
			gol_u8Mode = 0;
			gol_u8FlagMode = 0;
			CLCD_voidClearScreen();
		}
		else if (loc_AlarmFlag == 0)
		{
			loc_AlarmTrail = 1;
			MDIO_voidSetPinValue(DIO_PORTC, DIO_PIN2, DIO_PIN_INPUT);
			gol_u8FlagMode = 0;
			gol_u8Mode = 0;
			CLCD_voidClearScreen();
		}
		else
		{
			gol_u8FlagMode = 0;
			gol_u8Mode = 0;
			CLCD_voidClearScreen();
		}
	}

	else
	{
		CLCD_voidClearScreen();
		CLCD_voidSendString("No Alarm set");
		_delay_ms(250);
		gol_u8FlagMode = 0;
		loc_AlarmFlag = 0;
		gol_u8Mode = 0;
		CLCD_voidClearScreen();
	}
#endif
}

void APP_vidAdminFunction (void)
{

	ST_Data_t Admin;

	u8 loc_AdminFlag = 0, loc_AdminTrail = 1, loc_AdminOutValue = 0;

	u8 loc_u8PressedKey, loc_u8CountPassword;

	u8 loc_u8AlarmBuffer;
	MDIO_voidGetPinValue(DIO_PORTC, DIO_PIN2, &loc_u8AlarmBuffer);

	if(loc_u8AlarmBuffer == DIO_PIN_LOW)
	{
		CLCD_voidClearScreen();
		CLCD_voidSendString("c in password");
		CLCD_voidSetPosition(1,0);
		CLCD_voidSendString("mode to clear");
		_delay_ms(250);
		CLCD_voidClearScreen();
		CLCD_voidSendString("c to exit");
		_delay_ms(250);
		CLCD_voidClearScreen();
		CLCD_voidSendString(" = To next step");
		_delay_ms(250);
		CLCD_voidClearScreen();

		while(loc_AdminFlag == 0)
		{
			MUART_voidSendData('w');

			CLCD_voidSendString("Enter Admin PW");
			CLCD_voidSetPosition(1,0);
			while(1)
			{
				MUART_voidSendData('w');

				loc_u8PressedKey = HKPD_u8GetPressedKey();

				for(loc_u8CountPassword  = 1; loc_u8CountPassword < 6; loc_u8CountPassword++)
				{
					MUART_voidSendData('w');

					do
					{
						loc_u8PressedKey = HKPD_u8GetPressedKey();
					}while(	loc_u8PressedKey == NOT_PRESSED);

					if(loc_u8PressedKey == 'c' && loc_AdminOutValue == 0)
					{
						loc_u8PressedKey = 'c';
						break;
					}

					if (loc_u8PressedKey == 'c')
					{
						CLCD_voidSetPosition(1, loc_u8CountPassword-2);
						CLCD_voidSendData(' ');
						_delay_ms(200);
						CLCD_voidSetPosition(1, loc_u8CountPassword-2);
						loc_u8CountPassword-=2;
						if(loc_u8CountPassword == 1 || loc_u8CountPassword == 0)
						{
							loc_AdminOutValue = 0;
						}
					}
					else if (loc_u8CountPassword < 5)
					{
						loc_AdminOutValue = 1;
						CLCD_voidSendData(loc_u8PressedKey);
						_delay_ms(200);
						CLCD_voidSetPosition(1, loc_u8CountPassword-1);
						CLCD_voidSendData('*');
						_delay_ms(200);
						Admin.st_arr_u8Password[loc_u8CountPassword-1] = loc_u8PressedKey;
					}
					else if (loc_u8PressedKey == '=' && loc_u8CountPassword > 4)
					{
						loc_u8PressedKey = '=';
						break;
					}
					else
					{
						loc_u8CountPassword-=1;
					}
				}

				if (loc_u8PressedKey == 'c')
				{
					loc_AdminFlag = 0;
					break;
				}

				if(Admin.st_arr_u8Password[0] != HEEPROM_u8ReadData(EEPROM_AdminPassword_LOCATION) || Admin.st_arr_u8Password[1] != HEEPROM_u8ReadData(EEPROM_AdminPassword_LOCATION + 1) || Admin.st_arr_u8Password[2] != HEEPROM_u8ReadData(EEPROM_AdminPassword_LOCATION + 2) || Admin.st_arr_u8Password[3] != HEEPROM_u8ReadData(EEPROM_AdminPassword_LOCATION + 3))
				{
					loc_AdminFlag = 1;
				}

				if(loc_AdminFlag == 1 || loc_AdminFlag == 0)
				{
					break;
				}

			}

			if(loc_u8PressedKey == 'c' && loc_AdminFlag == 0)
			{
				break;
			}

			if(loc_AdminFlag == 1 && loc_AdminTrail < 3)
			{
				CLCD_voidClearScreen();
				CLCD_voidSendString("Wrong password");
				CLCD_voidSetPosition(1,0);
				CLCD_voidSendString("Tries left: ");
				CLCD_voidSendNumber(3-loc_AdminTrail);
				loc_AdminTrail++;
				loc_AdminFlag = 0;
				_delay_ms(250);
				CLCD_voidClearScreen();
			}
			else
			{
				if(loc_AdminFlag == 0)
				{
					break;
				}
				else if(loc_AdminTrail == 3)
				{
					CLCD_voidClearScreen();
					CLCD_voidSendString("Wrong password");
					_delay_ms(250);
					CLCD_voidClearScreen();
					CLCD_voidSendString("Can not enter");
					CLCD_voidSetPosition(1,0);
					CLCD_voidSendString("admin mode");
					MDIO_voidSetPinValue(DIO_PORTC, DIO_PIN2, DIO_PIN_OUTPUT);
					_delay_ms(250);
					loc_AdminFlag = 1;
					CLCD_voidClearScreen();
				}

			}
		}

		if(loc_u8PressedKey == 'c' && loc_AdminFlag == 0)
		{
			gol_u8Mode = 0;
			gol_u8FlagMode = 0;
			CLCD_voidClearScreen();
		}
		else if (loc_AdminFlag == 0)
		{
			loc_AdminTrail = 1;
			APP_voidAdminMenu();
		}
		else
		{
			gol_u8FlagMode = 0;
			gol_u8Mode = 0;
			CLCD_voidClearScreen();
		}
	}
	else
	{
		CLCD_voidClearScreen();
		CLCD_voidSendString("Close Alarm");
		CLCD_voidSetPosition(1,0);
		CLCD_voidSendString("first");
		_delay_ms(250);
		gol_u8FlagMode = 0;
		gol_u8Mode = 0;
		CLCD_voidClearScreen();
	}
}

void APP_voidAdminMenu(void)
{
	u8 loc_u8PressedKey;
	gol_u8Mode_A = 0;
	gol_u8FlagMode_A = 0;

	CLCD_voidClearScreen();
	CLCD_voidSendString("Welcome to Admin");
	CLCD_voidSetPosition(1,0);
	CLCD_voidSendString("Mode");
	_delay_ms(250);
	CLCD_voidClearScreen();
	CLCD_voidSendString(" * for Exit");
	_delay_ms(250);
	CLCD_voidClearScreen();

	while(1)
	{
		MUART_voidSendData('w');

		CLCD_voidSetPosition(0,0);
		CLCD_voidSendString("1 AddUr 2 DelUr");
		CLCD_voidSetPosition(1,0);
		CLCD_voidSendString("3Change guest PW");

		loc_u8PressedKey = HKPD_u8GetPressedKey();

		if (gol_u8FlagMode_A == 0 && loc_u8PressedKey < '4' && loc_u8PressedKey > '0')
		{
			gol_u8Mode_A = loc_u8PressedKey;
			loc_u8PressedKey = NOT_PRESSED;
			gol_u8FlagMode_A = 1;
		}

		if(gol_u8Mode_A == '1')
		{
			APP_vidAddUserFuncation();
		}

		if(gol_u8Mode_A == '2')
		{
			APP_vidDeleteUserFuncation();
		}

		if(gol_u8Mode_A == '3')
		{
			APP_vidChangeGuestPasswordFuncation();
		}

		if(loc_u8PressedKey == '*')
		{
			gol_u8FlagMode = 0;
			gol_u8Mode = '0';
			CLCD_voidClearScreen();
			break;
		}
	}
}

void APP_vidAddUserFuncation(void)
{
#if 1
	u8 loc_u8PressedKey = NOT_PRESSED;
	u8 loc_u8PosistionCount = 0, loc_u8CountPassword = 0,loc_u8display,loc_u8IDLocation,loc_u8IDValue = ' ',loc_u8IDCheckFlag = 0;

	loc_u8PosistionCount = HEEPROM_u8ReadData(EEPROM_PosistionCount_LOCATION);

	CLCD_voidClearScreen();
	CLCD_voidSendString("Add user mode");
	_delay_ms(250);
	CLCD_voidClearScreen();
	CLCD_voidSendString(" c for Exit");
	_delay_ms(250);
	CLCD_voidClearScreen();
	CLCD_voidSendString(" = To next step");
	_delay_ms(250);
	CLCD_voidClearScreen();

	while(1)
	{
		MUART_voidSendData('w');

		if(loc_u8PressedKey != 'c')
		{
			loc_u8PressedKey = HKPD_u8GetPressedKey();

			CLCD_voidClearScreen();
			CLCD_voidSendString("+ in ID mode to ");
			CLCD_voidSetPosition(1,0);
			CLCD_voidSendString("clear");
			_delay_ms(250);

			CLCD_voidClearScreen();
			CLCD_voidSendString("Enter user ID");
			CLCD_voidSetPosition(1,0);
		}

		if(loc_u8PressedKey == 'c')
		{
			gol_u8Mode_A = 0;
			gol_u8FlagMode_A = 0;
			CLCD_voidClearScreen();
			break;
		}

		loc_u8IDValue = ' ';

		while(1)
		{
			MUART_voidSendData('w');

			loc_u8PressedKey = HKPD_u8GetPressedKey();

			if (loc_u8PressedKey != NOT_PRESSED && loc_u8PressedKey != '+' && loc_u8PressedKey != '=' && loc_u8PressedKey != 'c' && loc_u8IDValue == ' ')
			{
				loc_u8IDValue = loc_u8PressedKey;
				CLCD_voidSendData(loc_u8IDValue);
			}

			if(loc_u8PressedKey == 'c')
			{
				loc_u8PressedKey = 'c';
				break;
			}

			if(loc_u8PressedKey == '+')
			{
				CLCD_voidSetPosition(1,0);
				CLCD_voidSendData(' ');
				loc_u8IDValue = ' ';
				CLCD_voidSetPosition(1,0);
			}

			if(loc_u8PressedKey == '=')
			{
				if(loc_u8IDValue >= '0' && loc_u8IDValue < '10')
				{
					CLCD_voidClearScreen();
					break;
				}
				else if (loc_u8IDValue == ' ')
				{
					CLCD_voidClearScreen();
					CLCD_voidSendString("Enter ID");
					_delay_ms(250);
					CLCD_voidClearScreen();
					CLCD_voidSendString("Enter user ID");
					CLCD_voidSetPosition(1,0);
				}
				else
				{
					CLCD_voidClearScreen();
					CLCD_voidSendString("Invalid operator");
					loc_u8IDValue = ' ';
					_delay_ms(250);
					CLCD_voidClearScreen();
					CLCD_voidSendString("Enter user ID");
					CLCD_voidSetPosition(1,0);
				}
			}


		}

		if(loc_u8PressedKey == 'c')
		{
			continue;
		}

		if(loc_u8IDValue > '0' && loc_u8IDValue < '6')
		{
			loc_u8IDLocation = EEPROM_ID1_LOCATION;
			u8 loc_u8IDCountPosistion = '1';

			while(1)
			{
				MUART_voidSendData('w');

				if(loc_u8IDValue != HEEPROM_u8ReadData(loc_u8IDLocation) && loc_u8IDValue == loc_u8IDCountPosistion)
				{
					break;
				}
				else if (loc_u8IDValue == HEEPROM_u8ReadData(loc_u8IDLocation))
				{
					loc_u8IDCheckFlag = 1;
					break;
				}
				else
				{
					loc_u8IDLocation += 5;
					loc_u8IDCountPosistion++;
				}

				if(loc_u8IDLocation == 36)
				{
					break;
				}
				_delay_ms(20);
			}

			if(loc_u8IDCheckFlag == 1)
			{
				CLCD_voidClearScreen();
				CLCD_voidSendString("ID already exist");
				CLCD_voidSetPosition(1,0);
				CLCD_voidSendString("Try again");
				_delay_ms(250);
				CLCD_voidClearScreen();
				continue;
			}
			else
			{
				HEEPROM_voidWriteData(loc_u8IDLocation,loc_u8IDValue);
				HEEPROM_voidWriteData(EEPROM_PosistionCount_LOCATION,loc_u8PosistionCount+1);
				loc_u8PosistionCount = HEEPROM_u8ReadData(EEPROM_PosistionCount_LOCATION);

				CLCD_voidClearScreen();
				CLCD_voidSendString("c in password");
				CLCD_voidSetPosition(1,0);
				CLCD_voidSendString("mode to clear");
				_delay_ms(250);

				CLCD_voidClearScreen();
				CLCD_voidSendString("Enter password");
				CLCD_voidSetPosition(1,0);
				u8 loc_u8Key = 0,loc_UserOutValue = 0;

				while(1)
				{
					MUART_voidSendData('w');

					loc_u8PressedKey = HKPD_u8GetPressedKey();

					if(loc_u8Key == 0)
					{
						for(loc_u8CountPassword  = 1; loc_u8CountPassword < 6; loc_u8CountPassword++)
						{
							do
							{
								loc_u8PressedKey = HKPD_u8GetPressedKey();
							}while(	loc_u8PressedKey == NOT_PRESSED);

							if(loc_u8PressedKey == 'c' && loc_UserOutValue == 0 )
							{
								loc_u8CountPassword = 0;
								CLCD_voidSetPosition(1, loc_u8CountPassword);
								CLCD_voidSendData(' ');
								loc_u8CountPassword = 0;
								_delay_ms(200);
							}

							if (loc_u8PressedKey == 'c')
							{
								if (loc_UserOutValue == 1)
								{
									CLCD_voidSetPosition(1, loc_u8CountPassword-2);
									CLCD_voidSendData(' ');
									_delay_ms(200);
									CLCD_voidSetPosition(1, loc_u8CountPassword-2);
									loc_u8CountPassword-=2;
								}
								if (loc_u8CountPassword == 1 || loc_u8CountPassword == 0)
								{
									loc_UserOutValue = 0;
									loc_u8CountPassword = 0;
									CLCD_voidSetPosition(1, loc_u8CountPassword);
								}
							}
							else if (loc_u8CountPassword < 5)
							{
								CLCD_voidSendData(loc_u8PressedKey);
								_delay_ms(200);
								CLCD_voidSetPosition(1, loc_u8CountPassword-1);
								CLCD_voidSendData('*');
								_delay_ms(200);

								HEEPROM_voidWriteData(loc_u8IDLocation + loc_u8CountPassword,loc_u8PressedKey);
							}
							else if (loc_u8PressedKey == '=' && loc_u8CountPassword >= 5)
							{
								loc_u8PressedKey = '=';
								break;
							}
							else
							{
								loc_u8CountPassword-=1;
							}
						}
						loc_u8Key = 1;
					}

					if(loc_u8PressedKey == '=')
					{
						CLCD_voidClearScreen();
						CLCD_voidSendString("Data Added");
						CLCD_voidSetPosition(1,0);
						CLCD_voidSendString("successfully");
						_delay_ms(250);
						loc_u8PressedKey = 'c';
						break;
					}
				}
			}
		}
		else
		{
			CLCD_voidClearScreen();
			CLCD_voidSendString("Invalid ID");
			CLCD_voidSetPosition(1,0);
			CLCD_voidSendString("Try again");
			_delay_ms(250);
			CLCD_voidClearScreen();
			continue;
		}
	}
#endif
}
void APP_vidDeleteUserFuncation(void)
{
#if 1
	u8 loc_u8PressedKey = NOT_PRESSED;
	u8 loc_u8PosistionCount = 0, loc_u8CountPassword = 0,loc_u8IDLocation,loc_u8IDValue = ' ',loc_u8IDCheckFlag = 0;

	loc_u8PosistionCount = HEEPROM_u8ReadData(EEPROM_PosistionCount_LOCATION);

	CLCD_voidClearScreen();
	CLCD_voidSendString("Delete user mode");
	_delay_ms(250);
	CLCD_voidClearScreen();
	CLCD_voidSendString(" c for Exit");
	_delay_ms(250);
	CLCD_voidClearScreen();
	CLCD_voidSendString(" = To next step");
	_delay_ms(250);
	CLCD_voidClearScreen();

	while(1)
	{
		MUART_voidSendData('w');

		if(loc_u8PressedKey != 'c')
		{
			loc_u8PressedKey = HKPD_u8GetPressedKey();

			CLCD_voidClearScreen();
			CLCD_voidSendString("+ in ID mode to ");
			CLCD_voidSetPosition(1,0);
			CLCD_voidSendString("clear");
			_delay_ms(250);

			CLCD_voidClearScreen();
			CLCD_voidSendString("Enter user ID");
			CLCD_voidSetPosition(1,0);
		}

		if(loc_u8PressedKey == 'c')
		{
			gol_u8Mode_A = 0;
			gol_u8FlagMode_A = 0;
			CLCD_voidClearScreen();
			break;
		}

		loc_u8IDValue = ' ';

		while(1)
		{
			MUART_voidSendData('w');

			loc_u8PressedKey = HKPD_u8GetPressedKey();

			if (loc_u8PressedKey != NOT_PRESSED && loc_u8PressedKey != '+' && loc_u8PressedKey != '=' && loc_u8PressedKey != 'c' && loc_u8IDValue == ' ' )
			{
				loc_u8IDValue = loc_u8PressedKey;
				CLCD_voidSendData(loc_u8IDValue);
			}

			if(loc_u8PressedKey == 'c')
			{
				loc_u8PressedKey = 'c';
				break;
			}

			if(loc_u8PressedKey == '+')
			{
				CLCD_voidSetPosition(1,0);
				CLCD_voidSendData(' ');
				loc_u8IDValue = ' ';
				CLCD_voidSetPosition(1,0);
			}

			if(loc_u8PressedKey == '=')
			{
				if(loc_u8IDValue >= '0' && loc_u8IDValue < '10')
				{
					CLCD_voidClearScreen();
					break;
				}
				else if (loc_u8IDValue == ' ')
				{
					CLCD_voidClearScreen();
					CLCD_voidSendString("Enter ID");
					_delay_ms(250);
					CLCD_voidClearScreen();
					CLCD_voidSendString("Enter user ID");
					CLCD_voidSetPosition(1,0);
				}
				else
				{
					CLCD_voidClearScreen();
					CLCD_voidSendString("Invalid operator");
					loc_u8IDValue = ' ';
					_delay_ms(250);
					CLCD_voidClearScreen();
					CLCD_voidSendString("Enter user ID");
					CLCD_voidSetPosition(1,0);
				}
			}
		}

		if(loc_u8PressedKey == 'c')
		{
			continue;
		}

		if(loc_u8IDValue > '0' && loc_u8IDValue < '6')
		{
			loc_u8IDLocation = EEPROM_ID1_LOCATION;

			u8 loc_u8IDCountPosistion = '1';

			while(1)
			{
				MUART_voidSendData('w');

				if(loc_u8IDValue != HEEPROM_u8ReadData(loc_u8IDLocation) && loc_u8IDValue == loc_u8IDCountPosistion)
				{
					break;
				}
				else if (loc_u8IDValue == HEEPROM_u8ReadData(loc_u8IDLocation))
				{
					loc_u8IDCheckFlag = 1;
					break;
				}
				else
				{
					loc_u8IDLocation += 5;
					loc_u8IDCountPosistion++;
				}

				if(loc_u8IDLocation == 36)
				{
					break;
				}
				_delay_ms(20);
			}

			if(loc_u8IDCheckFlag == 1)
			{
				HEEPROM_voidWriteData(loc_u8IDLocation,'0');
				HEEPROM_voidWriteData(EEPROM_PosistionCount_LOCATION,loc_u8PosistionCount-1);
				loc_u8PosistionCount = HEEPROM_u8ReadData(EEPROM_PosistionCount_LOCATION);

				for(loc_u8CountPassword  = 1; loc_u8CountPassword < 5; loc_u8CountPassword++)
				{
					HEEPROM_voidWriteData(loc_u8IDLocation + loc_u8CountPassword,'0');
				}
				CLCD_voidClearScreen();
				CLCD_voidSendString("Data deleted");
				CLCD_voidSetPosition(1,0);
				CLCD_voidSendString("successfully");
				_delay_ms(250);
				loc_u8PressedKey = 'c';
				continue;
			}
			else
			{
				CLCD_voidClearScreen();
				CLCD_voidSendString("ID doesn't exist");
				CLCD_voidSetPosition(1,0);
				CLCD_voidSendString("Try again");
				_delay_ms(250);
				CLCD_voidClearScreen();
				continue;
			}
		}
		else
		{
			CLCD_voidClearScreen();
			CLCD_voidSendString("Invalid ID");
			CLCD_voidSetPosition(1,0);
			CLCD_voidSendString("Try again");
			_delay_ms(250);
			CLCD_voidClearScreen();
			continue;
		}
	}

#endif
}
void APP_vidChangeGuestPasswordFuncation(void)
{
#if 1
	u8 loc_u8PressedKey,loc_u8CountPassword,loc_u8Key = 0;
	u8 loc_GuestOutValue = 0;

	CLCD_voidClearScreen();
	CLCD_voidSendString("Change guest");
	CLCD_voidSetPosition(1,0);
	CLCD_voidSendString("password");
	_delay_ms(250);
	CLCD_voidClearScreen();
	CLCD_voidSendString(" c for Exit");
	_delay_ms(250);
	CLCD_voidClearScreen();
	CLCD_voidSendString(" = To next step");
	_delay_ms(250);
	CLCD_voidClearScreen();

	while(1)
	{
		MUART_voidSendData('w');

		loc_u8PressedKey = HKPD_u8GetPressedKey();

		CLCD_voidSendString("Enter password");
		CLCD_voidSetPosition(1,0);

		while(1)
		{
			MUART_voidSendData('w');

			loc_u8PressedKey = HKPD_u8GetPressedKey();

			if(loc_u8Key == 0)
			{
				for(loc_u8CountPassword  = 1; loc_u8CountPassword < 6; loc_u8CountPassword++)
				{
					MUART_voidSendData('w');

					do
					{
						loc_u8PressedKey = HKPD_u8GetPressedKey();
					}while(	loc_u8PressedKey == NOT_PRESSED);

					if (loc_u8PressedKey == 'c' && loc_GuestOutValue == 0 )
					{
						loc_u8PressedKey = 'c';
						break;
					}
					if (loc_u8PressedKey == 'c')
					{
						CLCD_voidSetPosition(1, loc_u8CountPassword-2);
						CLCD_voidSendData(' ');
						_delay_ms(200);
						CLCD_voidSetPosition(1, loc_u8CountPassword-2);
						loc_u8CountPassword-=2;
						if(loc_u8CountPassword == 1 || loc_u8CountPassword == 0)
						{
							loc_GuestOutValue = 0;
						}
					}
					else if (loc_u8CountPassword < 5)
					{
						loc_GuestOutValue = 1;
						CLCD_voidSendData(loc_u8PressedKey);
						_delay_ms(200);
						CLCD_voidSetPosition(1, loc_u8CountPassword-1);
						CLCD_voidSendData('*');
						_delay_ms(200);
						HEEPROM_voidWriteData(EEPROM_GuestPassword_LOCATION + loc_u8CountPassword-1,loc_u8PressedKey);
					}
					else if (loc_u8PressedKey == '=' && loc_u8CountPassword >= 5)
					{
						loc_u8PressedKey = '=';
						break;
					}
					else
					{
						loc_u8CountPassword-=1;
					}
				}

				loc_u8Key = 1;
			}

			if (loc_u8PressedKey == 'c')
			{
				break;
			}
			if(loc_u8PressedKey == '=')
			{
				CLCD_voidClearScreen();
				CLCD_voidSendString("New PW added");
				CLCD_voidSetPosition(1,0);
				CLCD_voidSendString("successfully");
				loc_u8Key = 0;
				_delay_ms(250);
				loc_u8PressedKey = 'c';
				break;
			}
		}

		if(loc_u8PressedKey == 'c')
		{
			gol_u8FlagMode_A = 0;
			gol_u8Mode_A = '0';
			CLCD_voidClearScreen();
			break;
		}
	}

#endif
}

#endif



