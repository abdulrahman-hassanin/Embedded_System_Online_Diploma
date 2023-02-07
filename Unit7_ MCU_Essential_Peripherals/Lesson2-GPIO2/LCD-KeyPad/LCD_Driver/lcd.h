/*
 * lcd.h
 *
 * Created: 27/01/2023 06:53:48
 * Author : Abdulrahman
 */ 


#ifndef LCD_H_
#define LCD_H_

/*	MCU Configuration	*/
#define F_CPU 8000000UL
#include "commonMacros.h"
#include "avr/io.h"
#include "util/delay.h"
#include "stdio.h"

/************************************************************************/
/*					LCD Hardware Configuration                          */
/************************************************************************/
/*	LCD HW configurations	*/
#define DATA_Shift			0		// (0: 8-bit Mode) | (4: 4-bit mode)
#define EN_Switch			3		// Enable pin
#define RW_Switch			2		// read(1) / write(0) pin
#define RS_Switch			1		// Register Select: character(1) | control(0)
#define LCD_PORT			PORTA
#define LCD_DataDir_PORT	DDRA
#define LCD_CTRL			PORTB
#define LCD_DataDir_CTRL	DDRB

#define EIGHT_BIT_MODE
// #define FOUR_BIT_MODE

/************************************************************************/
/*				LCD Commands											*/
/************************************************************************/
/*	LCD Commands	 */

#define FOUR_BITS_DATA_MODE							(0x02)
#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)

/************************************************************************/
/*                     Function Prototype                               */
/************************************************************************/
void LCD_isBusy(void);
void LCD_kick(void);
void LCD_Send_Command(unsigned char command);
void LCD_Send_Char(unsigned char character);
void LCD_Send_String(char* str);
void LCD_Init(void);
void LCD_Clear_Screen();
void LCD_GotoXY(unsigned char line, unsigned char position);
void LCD_Display_Number(int Number);
void LCD_Display_Real_Number(double Number);


#endif /* LCD_H_ */