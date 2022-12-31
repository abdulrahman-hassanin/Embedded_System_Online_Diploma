/*
 * state.h
 *
 * Author: Abdulrahman Hassanin 
 */

#ifndef STATE_H_
#define STATE_H_

#include "stdio.h"
#include "stdlib.h"
// Automatic state function generator
#define STATE_define(_stateFUN_) void ST_##_stateFUN_()
#define STATE(_stateFUN_) ST_##_stateFUN_


// States Connections
void US_Set_distance(int d);
void DC_Motor(int s);

#endif   /* STATE_H_ */