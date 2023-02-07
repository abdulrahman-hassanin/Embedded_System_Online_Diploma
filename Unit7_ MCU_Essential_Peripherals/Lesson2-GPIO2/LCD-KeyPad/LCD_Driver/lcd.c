/*
 * lcd.c
 *
 * Created: 27/01/2023 06:53:35
 * Author : Abdulrahman
 */ 


#include "lcd.h"

void LCD_kick()
{
	CLEAR_BIT(LCD_CTRL, EN_Switch);
	_delay_ms(50);
	SET_BIT(LCD_CTRL, EN_Switch);
}

void LCD_isBusy()
{
	LCD_DataDir_PORT &= ~(0xFF<<DATA_Shift); // set port as input
	// Read mode(RW=1) & Command mode(RS=0)
	SET_BIT(LCD_CTRL, RW_Switch);			
	CLEAR_BIT(LCD_CTRL, RS_Switch);
	
	LCD_kick();								// wait for enable cycle
	
	LCD_DataDir_PORT = 0xFF;				// set port as output
	CLEAR_BIT(LCD_CTRL, RW_Switch);			// write mode
}

void LCD_Init()
{
	// Hardware Initialization waiting
	_delay_ms(20);
	
	// set 3 controls as outputs
	// write 0 (turn off enable, Write mode on, command mode on
	LCD_DataDir_CTRL |= (1<<EN_Switch | 1<<RW_Switch | 1<<RS_Switch);
	LCD_CTRL &= ~(1<<EN_Switch | 1<<RW_Switch | 1<<RS_Switch);
	
	// set LCD port as output to write command
	LCD_DataDir_PORT = 0xFF;
	_delay_ms(15);
	
	LCD_Clear_Screen();
	
#ifdef	EIGHT_BIT_MODE
	LCD_Send_Command(LCD_FUNCTION_8BIT_2LINES);
#endif

#ifdef	FOUR_BIT_MODE
	LCD_Send_Command(FOUR_BITS_DATA_MODE);
	LCD_Send_Command(LCD_FUNCTION_4BIT_2LINES);
#endif

	LCD_Send_Command(LCD_ENTRY_MODE);
	LCD_Send_Command(LCD_BEGIN_AT_FIRST_ROW);
	LCD_Send_Command(LCD_DISP_ON_CURSOR_BLINK);

}

void LCD_Send_Command(unsigned char command)
{
#ifdef	EIGHT_BIT_MODE
	LCD_isBusy();
	
	// Reset to write mode & character-mode(turn off command mode)
	CLEAR_BIT(LCD_CTRL, RW_Switch);
	CLEAR_BIT(LCD_CTRL, RS_Switch);
	
	// write command
	LCD_PORT = command;
	
	LCD_kick();
#endif
	
#ifdef	FOUR_BIT_MODE
	LCD_isBusy();
	
	// Reset to Read mode & character  mode(turn of command mode)
	CLEAR_BIT(LCD_CTRL, RW_Switch);
	CLEAR_BIT(LCD_CTRL, RS_Switch);
	// write command
	LCD_PORT = (LCD_PORT & 0x0F) | (command & 0xF0);
	LCD_kick();
	
	// Reset to Read mode & character  mode(turn of command mode)
	CLEAR_BIT(LCD_CTRL, RW_Switch);
	CLEAR_BIT(LCD_CTRL, RS_Switch);
	// write command
	LCD_PORT = (LCD_PORT & 0x0F) | (command<<4);
	LCD_kick();
#endif
}

void LCD_Send_Char(unsigned char character)
{
#ifdef	EIGHT_BIT_MODE
	LCD_isBusy();
	
	// set RS for data mode
	SET_BIT(LCD_CTRL, RS_Switch);
	// turn RW off so you can write
	CLEAR_BIT(LCD_CTRL, RW_Switch);
	
	// write data
	LCD_PORT = ((character)<<DATA_Shift);
	
	LCD_kick();
#endif
#ifdef	FOUR_BIT_MODE
	LCD_PORT = (LCD_PORT & 0x0F) | (character & 0xF0);
	LCD_CTRL |= 1<<RS_Switch;
	LCD_CTRL &= ~(1<<RW_Switch);
	LCD_kick();
	LCD_PORT = (LCD_PORT & 0x0F) | (character << 4);
	LCD_CTRL |= 1<<RS_Switch;
	LCD_CTRL &= ~(1<<RW_Switch);
	LCD_kick();
#endif
}

void LCD_GotoXY(unsigned char line, unsigned char position)
{
	if(line==0)
	{
		if (position<16 && position>=0)
			LCD_Send_Command(0x80 + position);
	}
	else if(line==1)
	{
		if (position<16 && position>=0)
			LCD_Send_Command(0xC0 + position);
	}
}

void LCD_Clear_Screen()
{
	LCD_Send_Command(LCD_CLEAR_SCREEN);
}

void LCD_Send_String(char* str)
{
	int count = 0;
	while(*str>0)
	{
		count++;
		LCD_Send_Char(*str++);
		if (count==16)
			LCD_GotoXY(1, 0); // LINE 1 position 0
		else if(count==32 || count==33)
		{
			LCD_Clear_Screen();
			LCD_GotoXY(0, 0);
			count = 0;
		}
	}
}

void LCD_Display_Number(int number)
{
	char str[7];
	sprintf(str, "%d", number);	// Adjust formatting
	LCD_Send_String(str);
}

void LCD_Display_Real_Number(double Number)
{
	char str[16];
	
	char *tempSign = (Number<0) ? "-": "";
	float tempVal  = (Number<0) ? -Number: Number;
	
	int tempInt1 = tempVal;				 // Get the integer (678)
	float tempFrac = tempVal - tempInt1; // Get fraction (0.0123)
	int tempInt2 = tempFrac * 10000;	 // Turn into integer (123)
	
	// print as parts, note that you need 0-padding for fractional bit
	sprintf(str, "%s%d.%04d", tempSign, tempInt1, tempInt2);
	
	LCD_Send_String(str);
}