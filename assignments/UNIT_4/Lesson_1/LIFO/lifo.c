/*
 * lifo.c
 *
 *  Created on: Apr 30, 2023
 *      Author: Shokry
 */


#include "lifo.h"



LIFO_status LIFO_init (LIFO_Buf_t* lifo_buf ,element_type *buf ,uint32 length)
{
	if ( (lifo_buf == NULL) || (buf == NULL) )
		return LIFO_NULL ;
	else
	{
		lifo_buf ->base = buf ;
		lifo_buf ->head = buf ;
		lifo_buf ->count = 0 ;
		lifo_buf ->length = length ;
		return LIFO_no_error ;
	}
}

LIFO_status LIFO_add_item (LIFO_Buf_t* lifo_buf,element_type item)
{
	if ( (lifo_buf == NULL) || (lifo_buf->base == NULL) || (lifo_buf->head == NULL) )
		return LIFO_NULL ;
	else
	{
		if (lifo_buf->count == lifo_buf->length)
			return LIFO_is_full ;
		else
		{

			*(lifo_buf ->head) = item ;
			lifo_buf ->head++ ;
			lifo_buf ->count++ ;
			return LIFO_no_error ;
		}
	}
}


LIFO_status LIFO_get_item (LIFO_Buf_t* lifo_buf,element_type *item)
{
	if ( (lifo_buf == NULL) || (lifo_buf->base == NULL) || (lifo_buf->head == NULL) )
		return LIFO_NULL ;
	else
	{
		if (lifo_buf->count == 0)
			return LIFO_is_empty ;
		else
		{
			lifo_buf ->head-- ;			
			*item = *(lifo_buf ->head) ;
			lifo_buf ->count-- ;
			return LIFO_no_error ;
		}
	}
}

