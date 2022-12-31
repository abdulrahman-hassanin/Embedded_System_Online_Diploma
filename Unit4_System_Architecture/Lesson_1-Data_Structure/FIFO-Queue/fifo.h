/*
 * fifo.h
 *
 * Author: Abdulrahman Hassanin 
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "stdint.h"

// USER Configuration
// select the element type (uint8_t, uint16_t, uint32_t, ...)
#define element_type uint8_t

// FIFO data types
typedef struct {
    unsigned int length;
    unsigned int count;
    element_type* base;
    element_type* head;
    element_type* tail;
}FIFO_Buf_t;

typedef enum{
    FIFO_no_error,
    FIFO_full,
    FIFO_empty,
    FIFO_null
}FIFO_Buf_Status;


// FIFO APIs
FIFO_Buf_Status FIFO_init(FIFO_Buf_t* fifo, element_type* buf,  uint8_t length);
FIFO_Buf_Status FIFO_enqueue(FIFO_Buf_t* fifo, element_type item);
FIFO_Buf_Status FIFO_dequeue(FIFO_Buf_t* fifo, element_type* item);
FIFO_Buf_Status FIFO_IS_FULL(FIFO_Buf_t* fifo);
void FIFO_print(FIFO_Buf_t* fifo);

#endif /* FIFO_H_ */