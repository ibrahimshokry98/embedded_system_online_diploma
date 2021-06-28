/*
 * main.c
 *
 *  Created on: Jun 28, 2021
 *      Author: Shokry
 */

#include "stdio.h"

void main()
{
	float a,b,x ;
	printf ("Enter value of a: ");
	fflush (stdin); fflush (stdout);
	scanf ("%f",&a);
	printf ("Enter value of b: ");
	fflush (stdin); fflush (stdout);
	scanf ("%f",&b);
	x = a;
	a = b;
	b = x;
	printf ("After swapping, value of a = %.2f\n",a);
	printf ("After swapping, value of b = %.2f\n",b);
}

