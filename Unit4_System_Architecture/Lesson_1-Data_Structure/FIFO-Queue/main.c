/*
 * main.c
 *
 * Author: Abdulrahman Hassanin 
 */

#include "fifo.h"
#include "stdio.h"

// create buffer
#define width1 5
element_type uart_buffer[width1];

void main()
{
    FIFO_Buf_t FIFO_UART;
    element_type i, temp;
    if( FIFO_init(&FIFO_UART, uart_buffer, 5) == FIFO_no_error)
        printf("FIFO init -------- Done\n");

    for (int i = 0; i < 7; ++i)
    {
        printf("FIFO Enqueue (%x) \n", i);
        if(FIFO_enqueue(&FIFO_UART, i) == FIFO_no_error)
            printf("FIFO enqueue -------- Done\n");
        else
            printf("FIFO enqueue --------  failed\n");
    }

    FIFO_print(&FIFO_UART);
    if(FIFO_dequeue(&FIFO_UART, &temp) == FIFO_no_error)
            printf("FIFO denque %x -------- Done\n", temp);
    if(FIFO_dequeue(&FIFO_UART, &temp) == FIFO_no_error)
            printf("FIFO denque %x -------- Done\n", temp);
    FIFO_print(&FIFO_UART);
}