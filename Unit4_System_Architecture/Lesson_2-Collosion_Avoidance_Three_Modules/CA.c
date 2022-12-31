/*
 * CA.c
 *
 * Author: Abdulrahman Hassanin 
 */

#include "CA.h"

// Define state
enum {
    CA_waiting,
    CA_driving
}CA_state_id;

// variables
int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;

// state pointer to function
void (*CA_state)();


void US_Set_distance(int d)
{
    CA_distance = d;
    (CA_distance <= CA_threshold) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
    printf("US -------distance=%d-------> CA\n", CA_distance);
}

STATE_define(CA_waiting)
{
    // state_Name
    CA_state_id = CA_waiting;

    // state_Action
    // DC_Motor(CA_speed)
    CA_speed = 0;
    DC_Motor(CA_speed);

    // Event_Check
    printf("CA_waiting State: distance = %d speed = %d\n", CA_distance, CA_speed);
}


STATE_define(CA_driving)
{
    // state_Name
    CA_state_id = CA_driving;

    // state_Action
    // DC_Motor(CA_speed)
    CA_speed = 30;

    // Event_Check

    printf("CA_driving State: distance = %d speed = %d\n", CA_distance, CA_speed);
}