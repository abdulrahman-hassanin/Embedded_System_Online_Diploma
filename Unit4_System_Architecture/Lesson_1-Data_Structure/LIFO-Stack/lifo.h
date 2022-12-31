/*
 * lifo.h
 *
 * Author: Abdulrahman Hassanin 
 */

#ifndef LIFO_H_
#define LIFO_H_

// type definitions
typedef struct LIFO_Buf_S {
    unsigned int length;
    unsigned int count;
    unsigned int* base;
    unsigned int* head;    
}LIFO_Buf_t;

typedef enum {
    LIFO_no_error,
    LIFO_full,
    LIFO_empty,
    LIFO_null
}LIFO_Status;

// APIs
LIFO_Status LIFO_Add_item(LIFO_Buf_t* lifo_buf, unsigned int item);
LIFO_Status LIFO_Get_item(LIFO_Buf_t* lifo_buf, unsigned int* item);
LIFO_Status LIFO_init(LIFO_Buf_t* lifo_buf, unsigned int* buf, unsigned int length);


#endif /* LIFO_H_ */