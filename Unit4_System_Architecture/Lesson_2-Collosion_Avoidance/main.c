/*
 * main.c
 *
 * Author: Abdulrahman Hassanin 
 */

#include "CA.h"

void setup()
{
    // init all the drivers
    // init IRQ ...
    // init HAL US_Driver DC_Driver
    // init Block (CA_module)
    // set states pointers for each block
    CA_state = STATE(CA_waiting);
}

void main()
{
    volatile int d;

    setup();

    while(1)
    {
        // call state for each block
        CA_state();

        // delay
        for(d=0; d<1000; d++);
    }
}