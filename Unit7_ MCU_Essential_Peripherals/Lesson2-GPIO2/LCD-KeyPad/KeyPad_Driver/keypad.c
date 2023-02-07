/*
 * keypad.c
 *
 * Created: 28/01/2023 01:58:28
 * Author : Abdulrahman
 */ 
#include "keypad.h"

int KeyPad_R[] = {R0, R1, R2, R3};		// rows of keypad
int KeyPad_C[] = {C0, C1, C2, C3};		// columns

void KEYPAD_Init()
{
	KEYPAD_DDR &= ~( (1<<R0) | (1<<R1) | (1<<R2) | (1<<R3));  // set upper port of keypad as input
	// this will be required for scanning the rows
	KEYPAD_DDR |=  ( (1<<C0) | (1<<C1) | (1<<C2) | (1<<C3));  // set lower port of keypad as output
	// this is the port of the keypad port where the rows are connected.
	KEYPAD_PORT = 0xFF;
	
}

char KEYPAD_GetChar()
{
	int i, j;
	for(i=0; i<4; i++)
	{
		// All columns C output 1
		KEYPAD_PORT |= ((1<<KeyPad_C[0]) | (1<<KeyPad_C[1]) | (1<<KeyPad_C[2]) | (1<<KeyPad_C[3]));
		// Pin i of columns output 0
		KEYPAD_PORT &= ~(1<<KeyPad_C[i]);
		for(j=0; j<4; j++) {
			if(!(KEYPAD_PIN & (1<<KeyPad_R[j]))) {
				while(!(KEYPAD_PIN & (1<<KeyPad_R[j]))); // wait for key to be released
				switch(i) {
					case (0):{
						if(j==0)	return '7';
						else if (j==1)	return '4';
						else if (j==2)	return '1';
						else if (j==3)	return '?';
						break;
					}
					case (1):{
						if(j==0)	return '8';
						else if (j==1)	return '5';
						else if (j==2)	return '2';
						else if (j==3)	return '0';
						break;
					}
					case (2):{
						if(j==0)	return '9';
						else if (j==1)	return '6';
						else if (j==2)	return '3';
						else if (j==3)	return '=';
						break;
					}
					case (3):{
						if(j==0)	return '/';
						else if (j==1)	return '*';
						else if (j==2)	return '-';
						else if (j==3)	return '+';
						break;
					}
				}
			}
		}
	}

	return 'A';		// return 'A' if no key is pressed.
}