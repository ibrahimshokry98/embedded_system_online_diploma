/*
 * ALG.c
 *
 *  Created on: May 20, 2023
 *      Author: Shokry
 */
#include "alg.h"
//define variables

uint32_t ALG_Pressure_Val = 0;
uint32_t Pressure_Threshold = 20;

//state pointer to fn
void (*ALG_state) ();

//CONNECTION FUNCTIONS
void Set_Pressure_Val (int Pressure_Val)
{
	ALG_Pressure_Val = Pressure_Val;
}

//define states
STATE_define(Pressure_Check)
{
	//state name
	ALG_State_id = Pressure_Check ;

	//State actions
	if (ALG_Pressure_Val > Pressure_Threshold)
	{
		High_Pressure_Detected();
	}
	ALG_state = STATE(Pressure_Check) ;
}


