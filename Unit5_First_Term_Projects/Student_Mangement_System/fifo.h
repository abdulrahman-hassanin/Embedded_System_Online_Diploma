/*
 * fifo.h
 *
 * Author: Abdulrahman Hassanin 
 */


#ifndef FIFO_H_
#define FIFO_H_

#include <stdio.h>
#include <stdint.h>
#include "student.h"

// User Configuration
// select the element type (uint8_t, uint16_t, uint32_t, ...)
#define element_type Student_Data_t

// FIFO Data type
typedef struct {
    element_type* base;
    element_type* head;
    element_type* tail;
    uint8_t length;
    uint8_t count;
}FIFO_Buf_t;

typedef enum{
    FIFO_no_error,
    FIFO_full,
    FIFO_empty,
    FIFO_null
}FIFO_Buf_status;

// FIFO API
FIFO_Buf_status FIFO_init(FIFO_Buf_t* fifo, element_type* buf, uint8_t length);
FIFO_Buf_status FIFO_enqeue(FIFO_Buf_t* fifo, element_type item);
FIFO_Buf_status FIFO_deqeue(FIFO_Buf_t* fifo, element_type* item);
uint8_t FIFO_IS_Student_Exist(FIFO_Buf_t* fifo, element_type* item, uint8_t ID);
FIFO_Buf_status FIFO_Is_FULL(FIFO_Buf_t* fifo);

#endif /* FIFO_H_ */