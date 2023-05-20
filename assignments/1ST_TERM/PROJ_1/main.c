#include <stdint.h>
#include <stdio.h>

#include "driver.h"
#include "alg.h"
#include "ps.h"
#include "al_mon.h"
#include "al_act.h"

void SETUP()
{
	//set state pointers for each block
	PS_state = STATE(PS_busy);
	ALG_state = STATE(Pressure_Check);
	AL_MON_State = STATE(MON_Alarm_OFF);
	ACT_state = STATE(ACT_idle);
}

int main (void){
	GPIO_INITIALIZATION();
	SETUP();
	while (1)
	{
		//Implement your Design 
		PS_state();
		ALG_state();
		AL_MON_State();
		ACT_state();
	}

}





