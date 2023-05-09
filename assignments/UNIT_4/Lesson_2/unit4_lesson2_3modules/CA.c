/*
 * CA.c
 *
 *  Created on: May 1, 2023
 *      Author: Shokry
 */
#include "CA.h"
//variables

int CA_speed = 0 ;
int CA_distance = 0 ;
int CA_threshold = 50 ;

//STATE pointer to fn
void (*CA_state) () ;

void US_set_distance (int distance )
{
	CA_distance  = distance ;
	(CA_distance <= CA_threshold)? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving)) ;
	printf("US ------distance = %d----------> CA\n",CA_distance) ;
}

//define states

STATE_define(CA_waiting)
{
	//State name
	CA_State_id = CA_waiting ;
	printf ("CA_waiting State: distance = %d	Speed = %d\n",CA_distance,CA_speed) ;
	//State action
	CA_speed = 0 ;
	DC_motor_Set (CA_speed) ;
}

STATE_define(CA_driving)
{
	//State name
	CA_State_id = CA_driving ;
	printf ("CA_driving State: distance = %d	Speed = %d\n",CA_distance,CA_speed) ;
	//State action
	CA_speed = 30 ;
	DC_motor_Set (CA_speed) ;
	//DC_motor (speed)
}

