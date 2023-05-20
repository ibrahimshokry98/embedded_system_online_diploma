/*
 * ps.c
 *
 *  Created on: May 20, 2023
 *      Author: Shokry
 */
#include "ps.h"
//define variables
uint32_t PS_Pressure_Val = 0;

//state pointer to fn
void (*PS_state) ();

void PS_init()
{
	GPIO_INITIALIZATION();
}

//define states
STATE_define(PS_busy)
{
	//state name
	PS_State_id = PS_busy ;

	//state Actions
	PS_Pressure_Val =getPressureVal();
	Set_Pressure_Val (PS_Pressure_Val);
	Delay(200000);
}




