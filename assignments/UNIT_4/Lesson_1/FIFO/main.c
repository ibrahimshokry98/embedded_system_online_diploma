/*
 * main.c
 *
 *  Created on: Apr 30, 2023
 *      Author: Shokry
 */


/*
 * main.c
 *
 *  Created on: Apr 30, 2023
 *      Author: Shokry
 */

#include "fifo.h"
#define Buf_Length 5



element_type buffer1[Buf_Length] ;

void main()
{
	element_type x = 0 ;
	FIFO_status status = FIFO_no_error ;
	FIFO_Buf_t FIFO_buf1 ,FIFO_buf2;

	element_type *buffer2 = (element_type*) malloc(Buf_Length * sizeof (element_type)) ;

	status = FIFO_init(&FIFO_buf1, buffer1,(uint32) Buf_Length) ;
	status = FIFO_init(&FIFO_buf2, buffer2,(uint32) Buf_Length) ;
	for (int i = 1; i<8;i++)
	{
		status = FIFO_enqueue(&FIFO_buf1, i) ;
		if (status==FIFO_no_error)
		{
			printf ("x = %d is enqueued successfully\n",i) ;
		}
		else if (status==FIFO_is_full)
		{
			printf ("buffer is full\n") ;
		}
	}

	printf ("===================================================\n") ;

	/*
	for (int i = 1; i<8;i++)
	{
		status = FIFO_dequeue(&FIFO_buf1, (element_type*) &x) ;
		if (status==FIFO_no_error)
		{
			printf ("x = %d is dequeued successfully\n",x) ;
		}
		else if (status==FIFO_is_empty)
		{
			printf ("buffer is empty\n") ;
		}
	}
	 */

	printf ("===================================================\n") ;

	status = FIFO_dequeue(&FIFO_buf1, (element_type*) &x) ;
	if (status==FIFO_no_error)
	{
		printf ("x = %d is dequeued successfully\n",x) ;
	}
	else if (status==FIFO_is_empty)
	{
		printf ("buffer is empty\n") ;
	}

	status = FIFO_enqueue(&FIFO_buf1, 5) ;
	if (status==FIFO_no_error)
	{
		printf ("x = %d is enqueued successfully\n",5) ;
	}
	else if (status==FIFO_is_full)
	{
		printf ("buffer is full\n") ;
	}
	status = FIFO_dequeue(&FIFO_buf1, (element_type*) &x) ;

	if (status==FIFO_no_error)
	{
		printf ("x = %d is dequeued successfully\n",x) ;
	}
	else if (status==FIFO_is_empty)
	{
		printf ("buffer is empty\n") ;
	}
	FIFO_print(&FIFO_buf1) ;
}
