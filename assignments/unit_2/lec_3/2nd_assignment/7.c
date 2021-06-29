/*
 * main.c
 *
 *  Created on: Jun 29, 2021
 *      Author: Shokry
 */

#include "stdio.h"

void main()
{
	int n;
	long factorial = 1;
	printf ("Enter an integer: ");
	fflush (stdout);
	scanf ("%d",&n);
	if (n>0)
	{
		for (int i=1;i<=n;i++)
		{
			factorial *= i;
		}
		printf ("factorial = %lu ",factorial);
	}
	else if (n<0)
		printf ("Error!!! Factorial of negative number doesn't exist.");

}
