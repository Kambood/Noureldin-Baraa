#include "Arduino.h"
#include "Keypad.h"


u8 keyCharMap[4][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}};

u8 colPins[3] = {9,10,11};
u8 rowPins[4] = {0,1,2,4};


void keyPadSetup(void)
{
    for(u8 i =0; i<4;i++)
    {
        pinMode(rowPins[i],OUTPUT);
    }
    for(u8 i =0; i<3;i++)
    {
        pinMode(colPins[i],INPUT_PULLUP);
    }


}


u8 getKeyPressed()
{
    for(u8 row = 0; row < 4; row++)
    {
        //turn all rows high
        digitalWrite(rowPins[0],HIGH);
        digitalWrite(rowPins[1],HIGH);
        digitalWrite(rowPins[2],HIGH);
        digitalWrite(rowPins[3],HIGH);

        digitalWrite(rowPins[row], LOW);
        //digitalWrite(rowPins[],)
        for(u8 col=0; col<3; col++)
        {
            if(!digitalRead(colPins[col]))
            {
                return keyCharMap[row][col];
            }
        }
        //digitalWrite(rowPins[row],HIGH);
    }
    return NULL;
}