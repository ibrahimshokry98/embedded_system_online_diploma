/*
 * fifo.h
 *
 *  Created on: Apr 30, 2023
 *      Author: Shokry
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "stdlib.h"
#include "platform_types.h"

// the type of data you want to save in FIFO (uint8 - uint16 -uint32 ...... )
#define element_type uint32
// type definition
typedef struct {
	element_type *base ;
	element_type *head ;
	element_type *tail ;
	uint32 count ;
	uint32 length ;
}FIFO_Buf_t;

typedef enum {
	FIFO_no_error,
	FIFO_is_full,
	FIFO_is_empty,
	FIFO_NULL
}FIFO_status;

//APIs

FIFO_status FIFO_enqueue (FIFO_Buf_t *fifo_buf,element_type item) ;

FIFO_status FIFO_dequeue (FIFO_Buf_t *fifo_buf,element_type *item) ;

FIFO_status FIFO_init (FIFO_Buf_t *fifo_buf,element_type *buf , uint32 length ) ;

void FIFO_print (FIFO_Buf_t *fifo_buf) ;

#endif /* FIFO_H_ */
