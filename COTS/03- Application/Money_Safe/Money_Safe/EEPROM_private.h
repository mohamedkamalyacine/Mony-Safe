#ifndef _MCAL_EEPROM_PRIVATE_H_
#define _MCAL_EEPROM_PRIVATE_H_

#define EEARH (*(volatile u8*)0x3F)
#define EEARL (*(volatile u8*)0x3E)
#define EEDR  (*(volatile u8*)0x3D)

#define EECR *(volatile u8*)0x3C
    #define EERIE 3
    #define EEMWE 2
    #define EEWE 1
    #define EERE 0

#endif