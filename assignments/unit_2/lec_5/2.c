/*
 * main.c
 *
 *  Created on: Jun 29, 2021
 *      Author: Shokry
 */

#include "stdio.h"
#include "string.h"
long int factorial (int x);
int main()
{
	int x;
	printf ("Enter an positive integer: ");
	scanf ("%d",&x);
	printf ("factorial of %d = %d: ",x,factorial(x));
	return 0;
}
long int factorial (int x)
{
	int f=1;
	for(int i=1; i<=x;i++)
	{
		f=f*i;
	}
	return f;
}
