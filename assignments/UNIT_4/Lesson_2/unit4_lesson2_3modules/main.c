/*
 * main.c
 *
 *  Created on: May 1, 2023
 *      Author: Shokry
 */

#include "CA.h"
#include "US_sensor.h"
#include "DC_motor.h"

void setup ()
{
	//init all the drivers
	//init IRQ...
	//init HAL US_Driver DC_Driver
	//init Block
	US_init() ;
	DC_init() ;
	//set state pointers for each block

	CA_state = STATE(CA_waiting) ;
	US_state = STATE(US_busy) ;
	DC_state = STATE(DC_idle) ;
}

void main()
{
	volatile int d ;

	setup () ;

	while (1)
	{
		//call state for each block
		US_state () ;
		CA_state () ;
		DC_state () ;
		//delay
		for (d=0;d<=1000 ; d++) ;
	}
}



