/*
 * ps.h
 *
 *  Created on: May 20, 2023
 *      Author: Shokry
 */

#ifndef PS_H_
#define PS_H_

#include "state.h"

//define state
enum {
	PS_busy
}PS_State_id;

//Declare state functions;
STATE_define(PS_busy);

// STATE PINTER TO FUNCTION
extern void (*PS_state) ();
void PS_init();


#endif /* PS_H_ */



