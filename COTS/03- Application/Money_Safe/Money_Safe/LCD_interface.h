#ifndef _HAL_LCD_INTERFACE_H_
#define _HAL_LCD_INTERFACE_H_

#include "DIO_interface.h"

void LCD_vidInit(EN_GPIO_t dataPortNum, EN_pin_t pinRSnum, EN_GPIO_t portRSnum, EN_pin_t pinENnum, EN_GPIO_t portENnum);
void LCD_vidSendCmd(EN_GPIO_t dataPortNum, EN_pin_t pinRSnum, EN_GPIO_t portRSnum, EN_pin_t pinENnum, EN_GPIO_t portENnum, u8 cmd);
void LCD_vidDisplayChar(EN_GPIO_t dataPortNum, EN_pin_t pinRSnum, EN_GPIO_t portRSnum, EN_pin_t pinENnum, EN_GPIO_t portENnum, u8 ch);
void LCD_vidDisplayString(EN_GPIO_t dataPortNum, EN_pin_t pinRSnum, EN_GPIO_t portRSnum, EN_pin_t pinENnum, EN_GPIO_t portENnum, u8* ptrString);
void LCD_vidDisplayNumber(EN_GPIO_t dataPortNum, EN_pin_t pinRSnum, EN_GPIO_t portRSnum, EN_pin_t pinENnum, EN_GPIO_t portENnum, u8 number);

#endif