/*
 * DC.h
 *
 *  Created on: May 1, 2023
 *      Author: Shokry
 */

#ifndef DC_H_
#define DC_H_

#include "state.h"
//define States
enum  {
	DC_idle,
	DC_busy

}DC_State_id;

//declare state fn DC
STATE_define(DC_idle) ;
STATE_define(DC_busy) ;

//STATE pointer to fn
extern void (*DC_state) () ;
void DC_init () ;


#endif /* DC_H_ */
