/*
 * fifo.c
 *
 * Author: Abdulrahman Hassanin 
 */

#include "fifo.h"

// FIFO APIs
FIFO_Buf_status FIFO_init(FIFO_Buf_t* fifo, element_type* buf, uint8_t length)
{
    if(buf==NULL)
        return FIFO_null;

    fifo->base = buf;
    fifo->head = buf;
    fifo->tail = buf;
    fifo->length = length;
    fifo->count = 0;

    return FIFO_no_error;
}

FIFO_Buf_status FIFO_enqeue(FIFO_Buf_t* fifo, element_type item)
{
    if(!fifo->base || !fifo->head || !fifo->tail)
        return FIFO_null;
    if(fifo->count == fifo->length)
        return FIFO_full;
    
    // Add new item
    *(fifo->head) = item;
    fifo->count++;

    // circular fifo
    if(fifo->head == (fifo->base + (fifo->length * sizeof(element_type))))
        fifo->head = fifo->base;
    else
        fifo->head++;

    return FIFO_no_error;

}

FIFO_Buf_status FIFO_deqeue(FIFO_Buf_t* fifo, element_type* item)
{
    if(!fifo->base || !fifo->head || !fifo->tail)
        return FIFO_null;
    if(fifo->count == 0)
        return FIFO_empty;

    *item = *(fifo->tail);
    fifo->count--;

    // circular fifo
    if(fifo->tail == (fifo->base + (fifo->length * sizeof(element_type))))
        fifo->tail = fifo->base;
    else
        fifo->tail++;

    return FIFO_no_error;
}

uint8_t FIFO_IS_Student_Exist(FIFO_Buf_t* fifo, element_type* buf, uint8_t ID)
{
    if(!fifo->base || !fifo->head || !fifo->tail)
        return FIFO_null;
    if(fifo->count == 0)
        return 0;

    uint8_t found = 0;
    element_type* temp = fifo->tail;
    for(uint8_t i=0; i<fifo->count; i++) {   
        if(temp->roll == ID){
            *buf = *temp;
            found = 1;
            break;
        }

        // circular fifo
        if(temp == (fifo->base + (fifo->length * sizeof(element_type))))
            temp = fifo->base;
        else
            temp++;
    }

    return found;
}

FIFO_Buf_status FIFO_Is_FULL(FIFO_Buf_t* fifo)
{
    if(!fifo->base || !fifo->head ||  !fifo->tail)
        return FIFO_null;
    if(fifo->count == fifo->length)
        return FIFO_full;
    return FIFO_no_error;
}