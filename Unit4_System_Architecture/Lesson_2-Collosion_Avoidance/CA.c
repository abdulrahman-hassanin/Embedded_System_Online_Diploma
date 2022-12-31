/*
 * CA.c
 *
 * Author: Abdulrahman Hassanin 
 */

#include "CA.h"

// variables
int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;


// Define state
enum {
    CA_waiting,
    CA_driving
}CA_state_id;


// state pointer to function
void (*CA_state)();

int US_Get_distance_random(int l, int r, int count);


STATE_define(CA_waiting)
{
    // state_Name
    CA_state_id = CA_waiting;

    // state_Action
    // DC_Motor(CA_speed)
    CA_speed = 0;

    // Event_Check
    CA_distance = US_Get_distance_random(45, 55, 1);
    (CA_distance <= CA_threshold) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));

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
    CA_distance = US_Get_distance_random(45, 55, 10);
    (CA_distance <= CA_threshold) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));

    printf("CA_driving State: distance = %d speed = %d\n", CA_distance, CA_speed);
}

int US_Get_distance_random(int l, int r, int count)
{
    // Generate radom number in range l and r
    int i,rand_num;
    for(i=0; i<count; i++){
        rand_num = (rand() % (r-l)) + l;
    }
    return rand_num;
}