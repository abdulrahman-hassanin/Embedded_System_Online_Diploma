/*
 * DC.h
 *
 * Author: Abdulrahman Hassanin 
 */

#ifndef DC_H_
#define DC_H_

#include "state.h"

// declare state functions DC
STATE_define(DC_idle);
STATE_define(DC_busy);

void DC_init();

// state pointer to function
extern void (*DC_state)();


#endif   /* DC_H_ */