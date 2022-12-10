#include "uart.h"

unsigned char string_buffer[100] = "Lean-in-Depth: <Abdulrahman Hassanin>";

void main(void)
{
    // VersatilePB 
    Uart_Send_string(string_buffer);
}