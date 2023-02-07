/*
 * keypad.h
 *
 * Created: 28/01/2023 01:58:45
 * Author : Abdulrahman
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <avr/io.h>
#include <util/delay.h>

#define KEYPAD_PORT			PORTD
#define KEYPAD_DDR          DDRD
#define KEYPAD_PIN			PIND

#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

/************************************************************************/
/* Function Prototype                                                                     */
/************************************************************************/

void KEYPAD_Init();
char KEYPAD_GetChar();


#endif /* KEYPAD_H_ */