/*
 * main.c
 *
 *  Created on: Jun 29, 2021
 *      Author: Shokry
 */

#include "stdio.h"

void main()
{
	float x;
	printf ("Ennter a number: ");
	fflush (stdout);
	scanf ("%f",&x);
	if (x>0)
		printf ("%.2f is positive.",x);
	else if (x<0)
		printf ("%.2f is negative.",x);
	else
		printf ("you entered zero.");


}
