/*
 * lifo.c
 *
 * Author: Abdulrahman Hassanin 
 */

#include "lifo.h"
#include "stdio.h"

// APIs
LIFO_Status LIFO_Add_item(LIFO_Buf_t* lifo_buf, unsigned int item)
{
    // chcek lifo is valid
    if(!lifo_buf->base || !lifo_buf->head)
        return LIFO_null;

    // check lifo is fill
    if(lifo_buf->count == lifo_buf->length)
        return LIFO_full;

    // add value
    *(lifo_buf->head) = item;
    lifo_buf->head++;
    lifo_buf->count++;

    return LIFO_no_error;
}

LIFO_Status LIFO_Get_item(LIFO_Buf_t* lifo_buf, unsigned int* item)
{
    // chcek lifo is valid
    if(!lifo_buf->base || !lifo_buf->head)
        return LIFO_null;

    // check lifo is empty
    if(lifo_buf->count == 0)
        return LIFO_empty;

    // get value
    lifo_buf->head--;
    *item = *(lifo_buf->head);
    lifo_buf->count--;
    return LIFO_no_error;
}

LIFO_Status LIFO_init(LIFO_Buf_t* lifo_buf, unsigned int* buf, unsigned int length)
{
    if(buf == NULL)         // in case fail of dynamic alloc
        return LIFO_null;

    lifo_buf->base = buf;
    lifo_buf->head = buf;
    lifo_buf->length = length;
    lifo_buf->count = 0;

    return LIFO_no_error;
}