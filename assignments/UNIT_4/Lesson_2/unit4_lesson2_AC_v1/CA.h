/*
 * CA.h
 *
 *  Created on: May 1, 2023
 *      Author: Shokry
 */

#ifndef CA_H_
#define CA_H_

#include "state.h"
//define States
enum  {
	CA_waiting,
	CA_driving

}CA_State_id;

//declare state fn CA
STATE_define(CA_waiting) ;
STATE_define(CA_driving) ;

//STATE pointer to fn
void (*CA_state) () ;


#endif /* CA_H_ */
