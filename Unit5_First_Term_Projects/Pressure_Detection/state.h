/*
 * state.h
 *
 * Author: Abdulrahman Hassanin 
 */

#ifndef STATE_H_
#define STATE_H_

// Automatic state function generator
#define STATE_define(_stateFUN_) void ST_##_stateFUN_()
#define STATE(_stateFUN_) ST_##_stateFUN_


// States Connections
void setPressureVal(int pVal);
void HighPressureDetected();
void startAlarm();
void stopAlarm();

#endif   /* STATE_H_ */