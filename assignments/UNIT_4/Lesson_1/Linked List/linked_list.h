/*
 * linked_list.h
 *
 *  Created on: Apr 30, 2023
 *      Author: Shokry
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "stdio.h"
#include "platform_types.h"
#include "stdlib.h"
#include "string.h"



#define DRINTF(...) { fflush(stdout); \
					  fflush(stdin); \
					  printf (__VA_ARGS__); \
					  fflush(stdout); \
					  fflush(stdin); }


// types defentinos
typedef struct {
	char name[40] ;
	uint32 id ;
	float height ;
}Sdata;
typedef struct sstudent{
	Sdata student ;
	struct sstudent* pnextstudent ;
}Sstudent;

extern Sstudent *gpFirstStudent ;

//APIs
void  AddStudent () ;

void DeleteStudent () ;

void ViewStudent () ;

void DeleteAll () ;

void find_by_ID () ;

void NumberOFStudents () ;

uint32 NumberOFStudentsRECUR (Sstudent *pSelectedStudent) ;

void find_from_end () ;

void middle_of_list () ;

void ReverseList () ;


#endif /* LINKED_LIST_H_ */
