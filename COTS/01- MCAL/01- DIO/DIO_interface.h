#ifndef _MCAL_DIO_INTERFACE_H_
#define _MCAL_DIO_INTERFACE_H_

#include "Types.h"

typedef enum EN_mode_t
{
    INPUT = 0,
    OUTPUT
}EN_mode_t;

typedef enum EN_pinStatus_t
{
    LOW = 0,
    HIGH
}EN_pinStatus_t;

typedef enum EN_pin_t
{
    PIN0 = 0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}EN_pin_t;

typedef enum EN_port_t
{
    GPIOA = 0,
    GPIOB,
    GPIOC,
    GPIOD
}EN_GPIO_t;

typedef enum EN_nibble_t
{
    LOW_NIBBLE = 0,
    HIGH_NIBBLE
}EN_nibble_t;

//Set PINx in PORTx INPUT or OUTPUT
void DIO_vidSetPin(EN_pin_t pinNum, EN_GPIO_t portNum, EN_mode_t mode);

//Write on PINx in PORTx LOW or HIGH
void DIO_vidWritePin(EN_pin_t pinNum, EN_GPIO_t portNum, EN_pinStatus_t value);

//Read PINx status in PORTx
EN_pinStatus_t DIO_enuReadPin(EN_pin_t pinNum, EN_GPIO_t portNum);

//Set All PORTx Pins as an INPUT or OUTPUT
void DIO_vidSetPort(EN_GPIO_t portNum, EN_mode_t mode);

//Write on PORTx HIGH or LOW
void DIO_vidWritePort(EN_GPIO_t portNum, EN_pinStatus_t value);

//Set Low Niibble for PORTx
void DIO_vidSetLowNibble(EN_GPIO_t portNum, EN_mode_t mode);

//Set High Niibble for PORTx
void DIO_vidSetHighNibble(EN_GPIO_t portNum, EN_mode_t mode);

//Write on Low Niibble for PORTx
void DIO_vidWriteLowNibble(EN_GPIO_t portNum, u8 value);

//Write on High Niibble for PORTx
void DIO_vidWriteHighNibble(EN_GPIO_t portNum, u8 value);

#endif