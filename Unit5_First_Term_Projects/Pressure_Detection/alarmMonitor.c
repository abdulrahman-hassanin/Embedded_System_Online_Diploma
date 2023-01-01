/*
 * alarmMonitor.h
 *
 * Author: Abdulrahman Hassanin 
 */

#include "alarmMonitor.h"

// Define State
enum {
    alarmOff,
    alarmOn,
    waiting
} alarm_State_id;

// Define Variables
int alarmPeriod = 6000;

// state pointer to function
void (*alarm_state)();

STATE_define(alarmOff)
{
    // state name
    alarm_State_id = alarmOff;

    // state action
    stopAlarm();
}

STATE_define(alarmOn)
{
    // state name
    alarm_State_id = alarmOn;

    // state action
    startAlarm();

    // state check
    alarm_state = STATE(waiting);
    alarm_state();
}

STATE_define(waiting)
{
    // state name
    alarm_State_id = waiting;

    Delay(alarmPeriod);

    // alarm waiting expired    
    alarm_state = STATE(alarmOff);
    alarm_state();
}

void HighPressureDetected()
{
    alarm_state = STATE(alarmOn);
}

void startAlarm()
{
    
    Set_Alarm_actuator(0);
}

void stopAlarm()
{
    Set_Alarm_actuator(1);
}