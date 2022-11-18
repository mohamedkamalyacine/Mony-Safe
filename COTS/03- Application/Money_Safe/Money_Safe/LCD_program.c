#include "Types.h"
#include "Bit_Math.h"

#include "DIO_interface.h"

#include "LCD_config.h"
#include "LCD_private.h"
#include "LCD_interface.h"

#define F_CPU 8000000UL
#include "util/delay.h"
#include <stdio.h>

static void LCD_vidSendEnablePulse(EN_pin_t pinNum, EN_GPIO_t portNum)
{
    DIO_vidWritePin(pinNum, portNum, HIGH);
    _delay_ms(2);
    DIO_vidWritePin(pinNum, portNum, LOW);
}

void LCD_vidSendCmd(EN_GPIO_t dataPortNum, EN_pin_t pinRSnum, EN_GPIO_t portRSnum, EN_pin_t pinENnum, EN_GPIO_t portENnum, u8 cmd)
{
    DIO_vidWritePort(dataPortNum, cmd);
    DIO_vidWritePin(pinRSnum, portRSnum, LOW);
    LCD_vidSendEnablePulse(pinENnum, portENnum);
}

void LCD_vidInit(EN_GPIO_t dataPortNum, EN_pin_t pinRSnum, EN_GPIO_t portRSnum, EN_pin_t pinENnum, EN_GPIO_t portENnum)
{
    DIO_vidSetPort(dataPortNum, OUTPUT);
    DIO_vidSetPin(pinRSnum, portRSnum, OUTPUT);
    DIO_vidSetPin(pinENnum, portENnum, OUTPUT);
    _delay_ms(200);
    LCD_vidSendCmd(dataPortNum, pinRSnum, portRSnum, pinENnum, portENnum, LCD_FUNCTION_8BIT_2LINES);
    _delay_ms(1);
    LCD_vidSendCmd(dataPortNum, pinRSnum, portRSnum, pinENnum, portENnum, LCD_DISP_ON_CURSOR_ON);
    _delay_ms(1);
    LCD_vidSendCmd(dataPortNum, pinRSnum, portRSnum, pinENnum, portENnum, LCD_CLEAR_SCREEN);
    _delay_ms(2);
    LCD_vidSendCmd(dataPortNum, pinRSnum, portRSnum, pinENnum, portENnum, LCD_ENTRY_MODE);
    _delay_ms(10);
}

void LCD_vidDisplayChar(EN_GPIO_t dataPortNum, EN_pin_t pinRSnum, EN_GPIO_t portRSnum, EN_pin_t pinENnum, EN_GPIO_t portENnum, u8 ch)
{
    DIO_vidWritePort(dataPortNum, ch);
    DIO_vidWritePin(pinRSnum, portRSnum, HIGH);
    LCD_vidSendEnablePulse(pinENnum, portENnum);
}

void LCD_vidDisplayString(EN_GPIO_t dataPortNum, EN_pin_t pinRSnum, EN_GPIO_t portRSnum, EN_pin_t pinENnum, EN_GPIO_t portENnum, u8* ptrString)
{

    while(*ptrString != '\0')
    {
        LCD_vidDisplayChar(dataPortNum, pinRSnum, portRSnum, pinENnum, portENnum, *ptrString);
        ptrString++;
    }
}

void LCD_vidDisplayNumber(EN_GPIO_t dataPortNum, EN_pin_t pinRSnum, EN_GPIO_t portRSnum, EN_pin_t pinENnum, EN_GPIO_t portENnum, u8 number)
{
    u8 str[7];
    sprintf(str, "%d", number);
    LCD_vidDisplayString(dataPortNum, pinRSnum, portRSnum, pinENnum, portENnum, str);
}