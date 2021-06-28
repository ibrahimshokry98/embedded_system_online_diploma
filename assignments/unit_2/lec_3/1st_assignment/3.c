/*
 * main.c
 *
 *  Created on: Jun 27, 2021
 *      Author: Shokry
 */

#include "stdio.h"

void main()
{
	int x,y;
	printf ("Enter two integer: ");
	fflush (stdout);
	scanf ("%d %d",&x,&y);
	printf ("Sum: %d",x+y);
}
