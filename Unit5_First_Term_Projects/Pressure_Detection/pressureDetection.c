/*
 * algo.c
 *
 * Author: Abdulrahman Hassanin 
 */

#include "pressureDetection.h"
#include "driver/driver.h"

// Define State

enum {
    highPressureDetection
} pressureDetection_State_id;

// Define Variables
int Pval;
int threshold = 20;

// state pointer to function
void (*algo_state)();

STATE_define(highPressureDetection)
{
    // state name
    pressureDetection_State_id = highPressureDetection;
    
    // state action
    if(Pval > threshold)
        HighPressureDetected();

    // state check
}

void setPressureVal(int val)
{
    Pval = val;
}