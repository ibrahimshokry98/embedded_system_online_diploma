/*
 * DC.c
 *
 *  Created on: May 1, 2023
 *      Author: Shokry
 */
#include "DC_motor.h"
//variables

int DC_speed = 0 ;

//STATE pointer to fn
void (*DC_state) () ;

void DC_init ()
{
	//init PWM
	printf ("DC motor init \n") ;
}

void DC_motor_Set (int speed)
{
	DC_speed = speed ;
	DC_state = STATE(DC_busy) ;
	printf("CA ------speed = %d----------> DC\n",DC_speed) ;
}

//define states

STATE_define(DC_idle)
{
	//State name
	DC_State_id = DC_idle ;

	//State action
		// call PWM to make speed = DC_speed

	printf ("DC_idle State: Speed = %d\n",DC_speed) ;

}

STATE_define(DC_busy)
{
	//State name
	DC_State_id = DC_busy ;
	//State action
		// call PWM to make speed = DC_speed
	DC_speed = 30 ;


	printf ("DC_busy State: Speed = %d\n",DC_speed) ;

	DC_state = STATE(DC_idle) ;
}

