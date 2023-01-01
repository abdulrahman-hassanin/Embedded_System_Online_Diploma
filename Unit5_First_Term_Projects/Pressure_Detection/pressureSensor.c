/*
 * pressureSensor.c
 *
 * Author: Abdulrahman Hassanin 
 */

#include "pressureDetection.h"
#include "pressureSensor.h"
#include "driver.h"
#include "alarmMonitor.h"

// Define State

enum {
    init,
    reading,
    Pwaiting,
} pSensor_State_id;

// Define Variables
int val;

// state pointer to function
void (*pSensor_state)();

STATE_define(init)
{
    // state name
    pSensor_State_id = init;
    
    // state action
    alarm_state();

    // state check
    pSensor_state = STATE(Pwaiting); 
    pSensor_state();
}

STATE_define(reading)
{
    // state name
    pSensor_State_id = reading;

    // state Action
    val = getPressureVal();
    setPressureVal(val);
    pressureDetection_state();

    
    pSensor_state = STATE(Pwaiting);
}

STATE_define(Pwaiting)
{
    // state name
    pSensor_State_id = Pwaiting ;

    // waiting timer
    Delay(100);

    pSensor_state = STATE(reading);
}