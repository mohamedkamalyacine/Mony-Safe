#ifndef _MCAL_DIO_PRIVATE_H_
#define _MCAL_DIO_PRIVATE_H_

#include "Types.h"

//Definition of DDRx
#define DDRA    *((volatile u8*)0x3A)
#define DDRB    *((volatile u8*)0x37)
#define DDRC    *((volatile u8*)0x34)
#define DDRD    *((volatile u8*)0x31)

//Definition of PORTx
#define PORTA   *((volatile u8*)0x3B)
#define PORTB   *((volatile u8*)0x38)
#define PORTC   *((volatile u8*)0x35)
#define PORTD   *((volatile u8*)0x32)

//Definition of PINx
#define PINA    *((volatile u8*)0x39)
#define PINB    *((volatile u8*)0x36)
#define PINC    *((volatile u8*)0x33)
#define PIND    *((volatile u8*)0x30)

#endif