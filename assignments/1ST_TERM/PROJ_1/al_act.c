#include "al_act.h"
//state pointer to fn
void (*ACT_state) ();
void ACT_init ()
{
	GPIO_INITIALIZATION();
}
//CONNECTION FUNCTION
void Start_Alarm()
{
	ACT_state = STATE(ACT_Alarm_ON);
	ACT_state();
}
void Stop_Alarm()
{
	ACT_state = STATE(ACT_Alarm_OFF);
	ACT_state();
}
//define states
STATE_define(ACT_idle)
{
	//state name
	ACT_State_id = ACT_idle;
}
STATE_define(ACT_Alarm_ON)
{
	//state name
	ACT_State_id = ACT_Alarm_ON;

	//state actions
	Set_Alarm_actuator(0);

	ACT_state = STATE(ACT_idle);
}
STATE_define(ACT_Alarm_OFF)
{
	//state name
	ACT_State_id = ACT_Alarm_OFF;

	//state actions
	Set_Alarm_actuator(1);

	ACT_state = STATE(ACT_idle);
}



