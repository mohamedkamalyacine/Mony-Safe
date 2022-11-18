#include "Types.h"
#include "BIT_MATH.h"

#include "KPD_interface.h"
#include "KPD_config.h"
#include "KPD_private.h"

void KPD_vidInit(EN_GPIO_t portNum, EN_nibble_t outNibble, EN_nibble_t inNibble)
{
    if(outNibble == LOW_NIBBLE)
    {
        DIO_vidSetLowNibble(portNum, OUTPUT);
        DIO_vidSetHighNibble(portNum, INPUT);
        DIO_vidWriteHighNibble(portNum, 0xF0);
    }
    else if(outNibble == HIGH_NIBBLE)
    {
        DIO_vidSetLowNibble(portNum, INPUT);
        DIO_vidSetHighNibble(portNum, OUTPUT);
        DIO_vidWriteHighNibble(portNum, 0x0F);
    }
    else
    {
        //Error_Handling
    }
}

u8 KPD_u8GetPressedKey(EN_GPIO_t portNum, EN_nibble_t outNibble, EN_nibble_t inNibble)
{
    u8 arr[4][4]={{'7','8','9','/'},
                  {'4','5','6','*'},
                  {'1','2','3','-'},
                  {'A','0','=','+'}};
    
    u8 row , coloumn;
    EN_pinStatus_t readValue;
    u8 returnValue;
    returnValue = NOT_PRESSRD;

    if(outNibble == LOW_NIBBLE)
    {
        for(row = 0; row<4; row++)
        {
            DIO_vidWriteLowNibble(portNum, 0x0F);
            DIO_vidWritePin(row, portNum, LOW);
            for(coloumn=0; coloumn<4; coloumn++)
            {
                readValue = DIO_enuReadPin((coloumn+4), portNum);
                if(readValue == LOW)
                {
                    returnValue = arr[row][coloumn];
                    break;
                }
            }
            if(readValue == LOW)
            {
                break;
            }
        }
    }
    else
    {
        for(row=0; row<4; row++)
        {
            DIO_vidWriteHighNibble(portNum, 0xF0);
            DIO_vidWritePin((row+4), portNum, LOW);
            for(coloumn=0; coloumn<4; coloumn++)
            {
                readValue = DIO_enuReadPin(coloumn, portNum);
                if(readValue == LOW)
                {
                    returnValue = arr[row][coloumn];
                    break;
                }
            }
            if(readValue == LOW)
            {
                break;
            }
        }
    }
    return returnValue;
}