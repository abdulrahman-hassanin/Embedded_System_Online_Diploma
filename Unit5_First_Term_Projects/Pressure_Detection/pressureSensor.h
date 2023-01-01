/*
 * pressureSensor.h
 *
 * Author: Abdulrahman Hassanin 
 */

#ifndef PRESSURESENSOR_H_
#define PRESSURESENSOR_H_

#include "state.h"

// state pointer to function
extern void (*pSensor_state)();

STATE_define(init);
STATE_define(reading);
STATE_define(Pwaiting);

#endif   /* PRESSURESENSOR_H_ */