/*
 * LCD-KeyPad.c
 *
 * Created: 28/01/2023 12:23:50 
 * Author : Abdulrahman
 */ 

#include "LCD_Driver/lcd.h"
#include "KeyPad_Driver/keypad.h"

int main(void)
{
	LCD_Init();
    KEYPAD_Init();
    char pressed_key;
    while (1) 
    {
        pressed_key = KEYPAD_GetChar();
        switch(pressed_key) 
        {
            case '?':
                LCD_Clear_Screen();
                break;
            case 'A':
                break;  // do nothing if no key is pressed
            default:
                LCD_Send_Char(pressed_key);
                break; 
        }
    }
}

