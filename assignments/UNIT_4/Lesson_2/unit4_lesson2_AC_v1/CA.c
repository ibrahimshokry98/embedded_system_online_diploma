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
int US_Get_distance_random (int l,int h, int count) ;

//define states

STATE_define(CA_waiting)
{
	//State name
	CA_State_id = CA_waiting ;
	//State action
	CA_speed = 0 ;
	//DC_motor (speed)
	//eventCheck
	//US_Get_distance (CA_distance)
	CA_distance = US_Get_distance_random (45,55,1) ;
	(CA_distance <= CA_threshold)? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving)) ;

	printf ("CA_waiting State: distance = %d	Speed = %d\n",CA_distance,CA_speed) ;

}

STATE_define(CA_driving)
{
	//State name
	CA_State_id = CA_driving ;
	//State action
	CA_speed = 30 ;
	//DC_motor (speed)

	//eventCheck
	//US_Get_distance (CA_distance)
	CA_distance = US_Get_distance_random (45,55,1) ;
	(CA_distance <= CA_threshold)? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving)) ;

	printf ("CA_driving State: distance = %d	Speed = %d\n",CA_distance,CA_speed) ;
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
