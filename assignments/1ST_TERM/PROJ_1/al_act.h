/*
 * al_act.h
 *
 *  Created on: May 20, 2023
 *      Author: Shokry
 */

#ifndef AL_ACT_H_
#define AL_ACT_H_

#include "state.h"

//define state
enum {
	ACT_idle,
	ACT_Alarm_ON,
	ACT_Alarm_OFF
}ACT_State_id;

//Declare state functions;
STATE_define(ACT_idle);
STATE_define(ACT_Alarm_ON);
STATE_define(ACT_Alarm_OFF);
// STATE PINTER TO FUNCTION
extern void (*ACT_state) ();
void ACT_init();


#endif /* AL_ACT_H_ */


