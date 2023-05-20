/*
 * state.h
 *
 *  Created on: May 20, 2023
 *      Author: Shokry
 */

#ifndef STATE_H_
#define STATE_H_

#include "stdio.h"
#include "stdlib.h"
#include "driver.h"

#define STATE_define(_stateFUN_) void st_##_stateFUN_()
#define STATE(_stateFUN_) st_##_stateFUN_

// declare signal connection functions
void Set_Pressure_Val (int Pressure_Val);
void High_Pressure_Detected () ;
void Start_Alarm();
void Stop_Alarm();
#endif /* STATE_H_ */




