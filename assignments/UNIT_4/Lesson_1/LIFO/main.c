/*
 * main.c
 *
 *  Created on: Apr 30, 2023
 *      Author: Shokry
 */

#include "lifo.h"
#define Buf_Length 5



element_type buffer1[Buf_Length] ;

void main()
{
	element_type x = 0 ;
	LIFO_status status = LIFO_no_error ;
	LIFO_Buf_t lifo_buf1 ,lifo_buf2;

	element_type *buffer2 = (element_type*) malloc(Buf_Length * sizeof (element_type)) ;

	status = LIFO_init(&lifo_buf1, buffer1,(uint32) Buf_Length) ;
	status = LIFO_init(&lifo_buf2, buffer2,(uint32) Buf_Length) ;
	for (int i = 1; i<8;i++)
	{
		status = LIFO_add_item(&lifo_buf1, i) ;
		if (status==LIFO_no_error)
		{
			printf ("x = %d is added successfully\n",i) ;
		}
		else if (status==LIFO_is_full)
		{
			printf ("buffer is full\n") ;
		}
	}

	printf ("===================================================\n") ;


	for (int i = 1; i<8;i++)
	{
		status = LIFO_get_item(&lifo_buf1, (element_type*) &x) ;
		if (status==LIFO_no_error)
		{
			printf ("x = %d is added successfully\n",x) ;
		}
		else if (status==LIFO_is_empty)
		{
			printf ("buffer is empty\n") ;
		}
	}


}

