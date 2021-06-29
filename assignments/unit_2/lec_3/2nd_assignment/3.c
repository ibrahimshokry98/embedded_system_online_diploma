/*
 * main.c
 *
 *  Created on: Jun 29, 2021
 *      Author: Shokry
 */

#include "stdio.h"

void main()
{
	float x,y,z;
	printf ("Enter three numbers: ");
	fflush (stdout);
	scanf ("%f %f %f",&x,&y,&z);
	if (x>y)
	{
		if (x>z)
			printf ("Largest number = %.2f ",x);
		else
			printf ("Largest number = %.2f ",z);
	}
	else
	{
		if (y>z)
			printf ("Largest number = %.2f ",y);
		else
			printf ("Largest number = %.2f ",z);
	}

}
