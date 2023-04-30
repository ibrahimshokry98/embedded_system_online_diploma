/*
 * lifo.h
 *
 *  Created on: Apr 30, 2023
 *      Author: Shokry
 */

#ifndef LIFO_H_
#define LIFO_H_

#include "stdio.h"
#include "stdlib.h"
#include "platform_types.h"
// the type of data you want to save in lifo
#define element_type uint32
// type definition
typedef struct {
	element_type *base ;
	element_type *head ;
	uint32 count ;
	uint32 length ;
}LIFO_Buf_t;

typedef enum {
	LIFO_no_error,
	LIFO_is_full,
	LIFO_is_empty,
	LIFO_NULL
}LIFO_status;


//APIS

LIFO_status LIFO_init (LIFO_Buf_t* lifo_buf ,element_type *buf ,uint32 length) ;


LIFO_status LIFO_add_item (LIFO_Buf_t* lifo_buf,element_type item) ;


LIFO_status LIFO_get_item (LIFO_Buf_t* lifo_buf,element_type *item) ;


#endif /* LIFO_H_ */
