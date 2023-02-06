/*
 * ToggleLED.c
 *
 * Created: 26/01/2023 08:19:08
 * Author : Abdulrahman Hassanin
 */ 

#include "MemMap.h"
#include "utils.h"
#define F_CPU 8000000UL
#include "util/delay.h"

unsigned char led = 5;
unsigned char turnOnFlag = 1;

void checkLedState(void)
{
	if(led==7){
		led = 5;
		turnOnFlag ^= 1;
	}else{
		led++;
	}
}

int main(void)
{
	ClearBit(DDRD, 0);			// set p0 as input	push1
	ClearBit(DDRD, 1);			// set p1 as input  push2
	SetBit(DDRD, 4);			// set p4 as output Buzzer
	SetBit(DDRD, 5);			// set p5 as output LED1
	SetBit(DDRD, 6);			// set p6 as output	LED2
	SetBit(DDRD, 7);			// set p7 as output	LED3
	
    while (1) 
    {
		if (ReadBit(PIND, 0) == 1)     // read push1 pull up 
		{
			if(turnOnFlag){
				SetBit(PORTD, led);
				checkLedState();
			}else{
				ClearBit(PORTD, led);
				checkLedState();
			}
			_delay_ms(500);
		}
		
		if (ReadBit(PIND, 1) == 1 )	// read push2 pull up 
		{
			Toggle(PORTD, 4);
			_delay_ms(500);
		}
    }
}

