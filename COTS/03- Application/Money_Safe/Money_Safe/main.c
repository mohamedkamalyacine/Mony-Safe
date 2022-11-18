/*
 * Money_Safe.c
 *
 * Created: 26-Sep-22 12:25:37 PM
 * Author : hp
 */ 

#include "Types.h"
#include "Bit_Math.h"

#include "DIO_interface.h"

#include "EEPROM_interface.h"

#include "LCD_private.h"
#include "LCD_interface.h"

#include "KPD_interface.h"

#define F_CPU 8000000UL
#include "util/delay.h"
#include <stdio.h>

int main(void)
{	
	LCD_vidInit(GPIOB, PIN7, GPIOA, PIN6, GPIOA);
	KPD_vidInit(GPIOC, LOW_NIBBLE, HIGH_NIBBLE);
	
	u8 key = NOT_PRESSRD;
	u8 pass[4] = "1234", check[4];
	u8 count = 0;
	static u8 trial = 3;
	
	u8 i;
	for(i=0; pass[i]!='\0'; i++)
	{
		EEPROM_vidWrite((pass+i), pass[i]);
	}
	
	LCD_vidDisplayString(GPIOB, PIN7, GPIOA, PIN6, GPIOA, "Enter Password: ");
	_delay_ms(200);
	LCD_vidSendCmd(GPIOB, PIN7, GPIOA, PIN6, GPIOA, LCD_BEGIN_AT_SECOND_RAW);

	//LCD_vidDisplayChar(GPIOB, PIN7, GPIOA, PIN6, GPIOA,EEPROM_u8Read(pass+4));
	
	while (1) 
    {
		do
		{
			key = KPD_u8GetPressedKey(GPIOC, LOW_NIBBLE, HIGH_NIBBLE);
			
			if(key != NOT_PRESSRD && trial != 0)
			{
				check[count] = key;
				
				LCD_vidDisplayChar(GPIOB, PIN7, GPIOA, PIN6, GPIOA, key);
				_delay_ms(200);
				LCD_vidSendCmd(GPIOB, PIN7, GPIOA, PIN6, GPIOA, LCD_MOVE_CURSOR_LEFT);
				LCD_vidDisplayChar(GPIOB, PIN7, GPIOA, PIN6, GPIOA, '*');
				_delay_ms(200);
				count++;
				//key = NOT_PRESSRD;
			}
			
		}while(count != 4);
		
		if(count == 4 && trial != 0)
		{
			for(i=0; i<=3; i++)
			{
				if(check[i] == EEPROM_u8Read(pass+i))
				{
					if(i == 3)
					{
						LCD_vidSendCmd(GPIOB, PIN7, GPIOA, PIN6, GPIOA, LCD_CLEAR_SCREEN);
						_delay_ms(200);
						LCD_vidDisplayString(GPIOB, PIN7, GPIOA, PIN6, GPIOA, "Correct Password");
						_delay_ms(200);						
					}
					else
					{
						continue;
					}
				}
				else if(check[i] != EEPROM_u8Read((pass+i)))
				{
					trial--;
					LCD_vidSendCmd(GPIOB, PIN7, GPIOA, PIN6, GPIOA, LCD_CLEAR_SCREEN);
					_delay_ms(200);
					LCD_vidDisplayString(GPIOB, PIN7, GPIOA, PIN6, GPIOA, "Still ");
					_delay_ms(200);
					LCD_vidDisplayNumber(GPIOB, PIN7, GPIOA, PIN6, GPIOA, trial);
					_delay_ms(200);
					LCD_vidDisplayString(GPIOB, PIN7, GPIOA, PIN6, GPIOA, " Trials");
					_delay_ms(200);
					LCD_vidSendCmd(GPIOB, PIN7, GPIOA, PIN6, GPIOA, LCD_BEGIN_AT_SECOND_RAW);
					break;
				}
				else
				{
					//Do_Nothing
				}
			}
			
			count = 0;
			key = NOT_PRESSRD;
		}
				
		else if(trial == 0)
		{
			LCD_vidDisplayString(GPIOB, PIN7, GPIOA, PIN6, GPIOA, "Error Password");
			_delay_ms(200);
		}
		else
			{/*Do_Nothing*/}
	}
}

