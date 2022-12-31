/*
 * CA.h
 *
 * Author: Abdulrahman Hassanin 
 */

#ifndef CA_H_
#define CA_H_

#include "state.h"

// declare state functions CA
STATE_define(CA_waiting);
STATE_define(CA_driving);

// state pointer to function
extern void (*CA_state)();


#endif   /* CA_H_ */