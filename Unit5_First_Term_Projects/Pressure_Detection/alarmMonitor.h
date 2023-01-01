/*
 * alarmMonitor.h
 *
 * Author: Abdulrahman Hassanin 
 */

#ifndef ALARMMONITOR_H_
#define ALARMMONITOR_H_

#include "state.h"
#include "driver.h"

// state pointer to function
void (*alarm_state)();

// declare state functions
STATE_define(alarmOff);
STATE_define(alarmOn);
STATE_define(waiting);

#endif   /* ALARMMONITOR_H_ */