/*
 * al_mon.h
 *
 *  Created on: May 20, 2023
 *      Author: Shokry
 */

#ifndef AL_MON_H_
#define AL_MON_H_

#include "state.h"


//define state
enum {
	MON_Alarm_OFF,
	MON_Alarm_ON
}AL_MON_State_id;

//Declare state functions;
STATE_define(MON_Alarm_ON);
STATE_define(MON_Alarm_OFF);

// STATE PINTER TO FUNCTION
extern void (*AL_MON_State) ();



#endif /* AL_MON_H_ */


