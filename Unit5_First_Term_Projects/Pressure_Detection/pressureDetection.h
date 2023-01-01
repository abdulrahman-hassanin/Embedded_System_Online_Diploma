/*
 * pressureDetection.h
 *
 * Author: Abdulrahman Hassanin 
 */

#ifndef PRESSUREDETECTION_H_
#define PRESSUREDETECTION_H_

#include "state.h"

// state pointer to function
void (*pressureDetection_state)();

// declare state functions
STATE_define(highPressureDetection);

#endif   /* PRESSUREDETECTION_H_ */