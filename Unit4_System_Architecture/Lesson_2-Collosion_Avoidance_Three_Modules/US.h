/*
 * US.h
 *
 * Author: Abdulrahman Hassanin 
 */

#ifndef US_H_
#define US_H_

#include "state.h"

// declare state functions US
STATE_define(US_busy);

void US_init();

// state pointer to function
extern void (*US_state)();


#endif   /*US_H_ */