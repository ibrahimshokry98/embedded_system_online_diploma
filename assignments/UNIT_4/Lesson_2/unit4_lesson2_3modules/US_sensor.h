/*
 * US.h
 *
 *  Created on: May 1, 2023
 *      Author: Shokry
 */

#ifndef US_H_
#define US_H_

#include "state.h"
//define States
enum  {
	US_busy

}US_State_id;

//declare state fn US
STATE_define(US_busy) ;

//STATE pointer to fn
extern void (*US_state) () ;
void US_init () ;


#endif /* US_H_ */
