/*
 * main.c
 *
 *  Created on: Jun 27, 2021
 *      Author: Shokry
 */

#include "stdio.h"

void main()
{
	float x,y;
	printf ("Enter two numbers: ");
	fflush (stdout);
	scanf ("%f %f",&x,&y);
	printf ("Pruduct: %f",x*y);
}
