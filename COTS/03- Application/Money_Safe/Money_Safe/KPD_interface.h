#ifndef _HAL_KPD_INTERFACE_H_
#define _HAL_KPD_INTERFACE_H_

#include "DIO_interface.h"

#define NOT_PRESSRD 0xFF

void KPD_vidInit(EN_GPIO_t portNum, EN_nibble_t outNibble, EN_nibble_t inNibble);
u8 KPD_u8GetPressedKey(EN_GPIO_t portNum, EN_nibble_t outNibble, EN_nibble_t inNibble);

#endif