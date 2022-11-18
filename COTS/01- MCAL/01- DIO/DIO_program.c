#include "Types.h"
#include "Bit_Math.h"

#include "DIO_private.h"
#include "DIO_config.h"
#include "DIO_interface.h"

void DIO_vidSetPin(EN_pin_t pinNum, EN_GPIO_t portNum, EN_mode_t mode)
{
    switch(portNum)
    {
        case GPIOA:
            if(mode == OUTPUT)
            {
                SET_BIT(DDRA, pinNum);
            }
            else if(mode == INPUT)
            {
                CLR_BIT(DDRA, pinNum);
            }
            else
            {
                //Error_handling
            }
            break;

        case GPIOB:
            if(mode == OUTPUT)
            {
                SET_BIT(DDRB, pinNum);
            }
            else if(mode == INPUT)
            {
                CLR_BIT(DDRB, pinNum);
            }
            else
            {
                //Error_handling
            }
            break;

        case GPIOC:
            if(mode == OUTPUT)
            {
                SET_BIT(DDRC, pinNum);
            }
            else if(mode == INPUT)
            {
                CLR_BIT(DDRC, pinNum);
            }
            else
            {
                //Error_handling
            }
            break;

        case GPIOD:
            if(mode == OUTPUT)
            {
                SET_BIT(DDRD, pinNum);
            }
            else if(mode == INPUT)
            {
                CLR_BIT(DDRD, pinNum);
            }
            else
            {
                //Error_handling
            }
            break;

        default:
            break;
    }
}

void DIO_vidWritePin(EN_pin_t pinNum, EN_GPIO_t portNum, EN_pinStatus_t value)
{
    switch(portNum)
    {
        case GPIOA:
            if(value == HIGH)
            {
                SET_BIT(PORTA, pinNum);
            }
            else if(value == LOW)
            {
                CLR_BIT(PORTA, pinNum);
            }
            else
            {
                //Error_handling
            }
            break;

        case GPIOB:
            if(value == HIGH)
            {
                SET_BIT(PORTB, pinNum);
            }
            else if(value == LOW)
            {
                CLR_BIT(PORTB, pinNum);
            }
            else
            {
                //Error_handling
            }
            break;

        case GPIOC:
            if(value == HIGH)
            {
                SET_BIT(PORTC, pinNum);
            }
            else if(value == LOW)
            {
                CLR_BIT(PORTC, pinNum);
            }
            else
            {
                //Error_handling
            }
            break;

        case GPIOD:
            if(value == HIGH)
            {
                SET_BIT(PORTD, pinNum);
            }
            else if(value == LOW)
            {
                CLR_BIT(PORTD, pinNum);
            }
            else
            {
                //Error_handling
            }
            break;

        default:
            break;
    }
}

EN_pinStatus_t DIO_enuReadPin(EN_pin_t pinNum, EN_GPIO_t portNum)
{
    EN_pinStatus_t out;
    switch(portNum)
    {
        case GPIOA:
            out = GET_BIT(PINA, pinNum);
            break;

        case GPIOB:
            out = GET_BIT(PINB, pinNum);
            break;

        case GPIOC:
            out = GET_BIT(PINC, pinNum);
            break;

        case GPIOD:
            out = GET_BIT(PIND, pinNum);
            break;

        default:
            break;
    }
    return out; 
}

void DIO_vidSetPort(EN_GPIO_t portNum, EN_mode_t mode)
{
    switch(portNum)
    {
        case GPIOA:
            if(mode == OUTPUT)
            {
                DDRA = 0xFF;
            }
            else if(mode == INPUT)
            {
                DDRA = 0x00;
            }
            else
            {
                //Error_handling
            }
            break;

        case GPIOB:
            if(mode == OUTPUT)
            {
                DDRB = 0xFF;
            }
            else if(mode == INPUT)
            {
                DDRB = 0x00;
            }
            else
            {
                //Error_handling
            }
            break;

        case GPIOC:
            if(mode == OUTPUT)
            {
                DDRC = 0xFF;
            }
            else if(mode == INPUT)
            {
                DDRB = 0x00;
            }
            else
            {
                //Error_handling
            }
            break;

        case GPIOD:
            if(mode == OUTPUT)
            {
                DDRD = 0xFF;
            }
            else if(mode == INPUT)
            {
                DDRD = 0x00;
            }
            else
            {
                //Error_handling
            }
            break;

        default:
            break;
    }
}

void DIO_vidWritePort(EN_GPIO_t portNum, EN_pinStatus_t value)
{
    switch(portNum)
    {
        case GPIOA:
            PORTA = value;
            break;

        case GPIOB:
            PORTB = value;
            break;

        case GPIOC:
            PORTC = value;
            break;

        case GPIOD:
            PORTD = value;
            break;

        default:
            break;
    }    
}

void DIO_vidSetLowNibble(EN_GPIO_t portNum, EN_mode_t mode)
{
    if(mode == OUTPUT)
    {
        DIO_vidSetPin(PIN0, portNum, OUTPUT);
        DIO_vidSetPin(PIN1, portNum, OUTPUT);
        DIO_vidSetPin(PIN2, portNum, OUTPUT);
        DIO_vidSetPin(PIN3, portNum, OUTPUT);
    }
    else if(mode == INPUT)
    {
        DIO_vidSetPin(PIN0, portNum, INPUT);
        DIO_vidSetPin(PIN1, portNum, INPUT);
        DIO_vidSetPin(PIN2, portNum, INPUT);
        DIO_vidSetPin(PIN3, portNum, INPUT);
    }
    else
    {
        //Error_Handling
    }
}

void DIO_vidSetHighNibble(EN_GPIO_t portNum, EN_mode_t mode)
{
    if(mode == OUTPUT)
    {
        DIO_vidSetPin(PIN4, portNum, OUTPUT);
        DIO_vidSetPin(PIN5, portNum, OUTPUT);
        DIO_vidSetPin(PIN6, portNum, OUTPUT);
        DIO_vidSetPin(PIN7, portNum, OUTPUT);
    }
    else if(mode == INPUT)
    {
        DIO_vidSetPin(PIN4, portNum, INPUT);
        DIO_vidSetPin(PIN5, portNum, INPUT);
        DIO_vidSetPin(PIN6, portNum, INPUT);
        DIO_vidSetPin(PIN7, portNum, INPUT);
    }
    else
    {
        //Error_Handling
    }
}

void DIO_vidWriteLowNibble(EN_GPIO_t portNum, u8 value)
{
    value &= 0x0F; 
    switch(portNum)
    {
        case GPIOA:
            PORTA &= 0xF0;
            PORTA |= value;
            break;

        case GPIOB:
            PORTB &= 0xF0;
            PORTB |= value;
            break;

        case GPIOC:
            PORTC &= 0xF0;
            PORTC |= value;
            break;

        case GPIOD:
            PORTD &= 0xF0;
            PORTD |= value;
            break;

        default:
            break;
    }
}

void DIO_vidWriteHighNibble(EN_GPIO_t portNum, u8 value)
{
    value &= 0xF0; 
    switch(portNum)
    {
        case GPIOA:
            PORTA &= 0x0F;
            PORTA |= value;
            break;

        case GPIOB:
            PORTB &= 0x0F;
            PORTB |= value;
            break;

        case GPIOC:
            PORTC &= 0x0F;
            PORTC |= value;
            break;

        case GPIOD:
            PORTD &= 0x0F;
            PORTD |= value;
            break;

        default:
            break;
    }
}