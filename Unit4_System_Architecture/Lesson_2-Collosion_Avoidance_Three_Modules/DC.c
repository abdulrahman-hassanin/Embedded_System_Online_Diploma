/*
 * DC.c
 *
 * Author: Abdulrahman Hassanin 
 */

#include "DC.h"

// Define state
enum {
    DC_idle,
    DC_busy
}DC_state_id;

// variables
int DC_speed = 0;

// state pointer to function
void (*DC_state)();

void DC_init()
{
    // init PWM
    printf("DC_init \n");
}

void DC_Motor(int s)
{
    DC_speed = s;
    DC_state = STATE(DC_busy);    
    printf("CA -------speed=%d-------> DC\n", DC_speed);

}

STATE_define(DC_idle)
{
    // state_Name
    DC_state_id = DC_idle;

    // state_Action
    // call PWM to make speed = DC_speed

    printf("DC_idle State: distance = %d\n", DC_speed);
}


STATE_define(DC_busy)
{
    // state_Name
    DC_state_id = DC_busy;

    // state_Action
    // call PWM to make speed = DC_speed

    printf("DC_busy State: speed = %d\n", DC_speed);
}