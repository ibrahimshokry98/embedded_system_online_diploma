/*
 * US.c
 *
 *  Created on: May 1, 2023
 *      Author: Shokry
 */
#include "US_sensor.h"
//variables


int US_distance = 0 ;

//STATE pointer to fn
void (*US_state) () ;
int US_Get_distance_random (int l,int h, int count) ;

//define states

void US_init ()
{
	//init US driver
	printf("US init\n") ;
}

STATE_define(US_busy)
{
	//State name
	US_State_id = US_busy ;
	//State action
	US_distance = US_Get_distance_random (45,55,1) ;
	printf ("US_busy State: distance = %d\n",US_distance) ;
	US_set_distance (US_distance) ;
	//DC_motor (speed)
	//eventCheck
	//US_Get_distance (US_distance)
	US_state = STATE(US_busy) ;
}



int US_Get_distance_random (int l,int h, int count)
{
	int i ;
	for (i=0;i<count;i++)
	{
		int rand_num = (rand() % (h-l+1) ) + l ;
		return rand_num ;
	}
}
