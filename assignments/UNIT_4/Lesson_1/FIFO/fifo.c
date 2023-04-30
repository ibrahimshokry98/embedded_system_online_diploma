/*
 * fifo.c
 *
 *  Created on: Apr 30, 2023
 *      Author: Shokry
 */

#include "fifo.h"

FIFO_status FIFO_init (FIFO_Buf_t *fifo_buf,element_type *buf , uint32 length )
{
	if ( (fifo_buf == NULL) || (buf == NULL) )
		return FIFO_NULL ;
	else
	{
		fifo_buf->base = buf ;
		fifo_buf->head = buf ;
		fifo_buf->tail = buf ;
		fifo_buf->count = 0 ;
		fifo_buf->length = length ;
		return FIFO_no_error ;
	}
}

FIFO_status FIFO_enqueue (FIFO_Buf_t *fifo_buf,element_type item)
{
	if ( (fifo_buf->base == NULL) || (fifo_buf->head == NULL) || (fifo_buf->tail == NULL ) )
		return FIFO_NULL ;
	else
	{
		if (fifo_buf->count == fifo_buf->length)
			return FIFO_is_full;
		else
		{
			*(fifo_buf->head) = item ;
			fifo_buf->count++ ;

			if (fifo_buf->head == (fifo_buf->base + fifo_buf->length-1))
				fifo_buf->head = fifo_buf->base ;
			else
				fifo_buf->head++ ;

			return FIFO_no_error ;
		}
	}
}

FIFO_status FIFO_dequeue (FIFO_Buf_t *fifo_buf,element_type *item)
{
	if ( (fifo_buf->base == NULL) || (fifo_buf->head == NULL) || (fifo_buf->tail == NULL ) )
		return FIFO_NULL ;
	else
	{
		if (fifo_buf->count == 0)
			return FIFO_is_empty;
		else
		{
			*item = *(fifo_buf->tail) ;
			fifo_buf->count-- ;

			if (fifo_buf->tail == (fifo_buf->base + fifo_buf->length-1))
				fifo_buf->tail = fifo_buf->base ;
			else
				fifo_buf->tail++ ;

			return FIFO_no_error ;
		}
	}
}

void FIFO_print (FIFO_Buf_t *fifo_buf)
{
	element_type *temp ;
	if ( (fifo_buf->base == NULL) || (fifo_buf->head == NULL) || (fifo_buf->tail == NULL ) )
		return FIFO_NULL ;
	else
	{
		if (fifo_buf->count == 0)
			printf ("queue is empty\n") ;
		else
		{
			temp = fifo_buf->tail ;
			for (int i=0;i<fifo_buf->count;i++)
			{
				printf ("%d\n",*temp) ;
				if (temp == (fifo_buf->base + fifo_buf->length-1))
					temp = fifo_buf->base;
				else
					temp++;
			}
		}

	}

}

