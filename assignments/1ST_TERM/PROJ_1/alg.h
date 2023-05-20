/*
 * alg.h
 *
 *  Created on: May 20, 2023
 *      Author: Shokry
 */

#ifndef ALG_H_
#define ALG_H_

#include "state.h"

//define state
enum {
	Pressure_Check
}ALG_State_id;

//Declare state functions;
STATE_define(Pressure_Check);

// STATE PINTER TO FUNCTION
extern void (*ALG_state) ();


#endif /* ALG_H_ */


