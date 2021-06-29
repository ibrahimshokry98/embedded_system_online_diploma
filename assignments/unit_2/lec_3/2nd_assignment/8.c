/*
 * main.c
 *
 *  Created on: Jun 29, 2021
 *      Author: Shokry
 */

#include "stdio.h"

void main()
{
	char c;
	float x,y;
	printf ("Enter operator either + or - or * or /: ");
	fflush (stdin); fflush (stdout);
	scanf ("%c",&c);
	printf ("Enter twe operands: ");
	fflush (stdin); fflush (stdout);
	scanf ("%f %f",&x,&y);
	switch (c)
	{
	case ('+') :
		{
		printf ("%.1f %c %.1f = %.1f",x,c,y,x+y);
		}
	break;
	case ('-') :
		{
		printf ("%.1f %c %.1f = %.1f",x,c,y,x-y);
		}
	break;
	case ('*') :
		{
		printf ("%.1f %c %.1f = %.1f",x,c,y,x*y);
		}
	break;
	case ('/') :
		{
		printf ("%.1f %c %.1f = %.1f",x,c,y,x/y);
		}
	break;
	default :
		printf ("wrong choice.");
		break;
	}

}