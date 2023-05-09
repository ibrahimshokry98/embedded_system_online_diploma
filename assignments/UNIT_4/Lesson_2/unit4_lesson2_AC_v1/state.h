/*
 * state.h
 *
 *  Created on: May 1, 2023
 *      Author: Shokry
 */

#ifndef STATE_H_
#define STATE_H_
#include "stdio.h"
#include "stdlib.h"

//Automatic state fn generated

#define STATE_define(_stateFUN_) void st_##_stateFUN_ ()
#define STATE(_stateFUN_) st_##_stateFUN_

#endif /* STATE_H_ */
