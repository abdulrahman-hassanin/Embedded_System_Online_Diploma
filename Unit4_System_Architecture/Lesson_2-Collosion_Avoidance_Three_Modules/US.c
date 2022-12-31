/*
 * US.c
 *
 * Author: Abdulrahman Hassanin 
 */

#include "US.h"

// Define state
enum {
    US_busy
}US_state_id;

// variables
int US_distance = 0;
// Define state

// state pointer to function
void (*US_state)();
int US_Get_distance_random(int l, int r, int count);

void US_init()
{
    // init US Driver
    printf("US_init \n");
}

STATE_define(US_busy)
{
    // state_Name
    US_state_id = US_busy;

    // state_Action 
    US_distance = US_Get_distance_random(45, 55, 1);

    // Event_Check

    printf("US_waiting State: distance = %d\n", US_distance);
    US_Set_distance(US_distance);
    US_state = STATE(US_busy);
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