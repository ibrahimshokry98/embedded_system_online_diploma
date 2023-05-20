/*
 * al_mon.c
 *
 *  Created on: May 20, 2023
 *      Author: Shokry
 */
#include "al_mon.h"

//state pointer to fn
void (*AL_MON_State) ();

//CONNECTION FUNCTIONS
void High_Pressure_Detected ()
{
	AL_MON_State = STATE(MON_Alarm_ON);
}

//define states

STATE_define(MON_Alarm_ON)
{
	//state name
	AL_MON_State_id = MON_Alarm_ON ;

	//State Actions
	Start_Alarm();
	Delay(2000000);
	Stop_Alarm();

	AL_MON_State = STATE(MON_Alarm_OFF);

}
STATE_define(MON_Alarm_OFF)
{
	AL_MON_State_id = MON_Alarm_OFF;

	//State Actions
	Stop_Alarm();

}



