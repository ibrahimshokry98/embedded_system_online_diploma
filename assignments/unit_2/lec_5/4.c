/*
 * main.c
 *
 *  Created on: Jun 29, 2021
 *      Author: Shokry
 */

#include "stdio.h"
#include "string.h"
int power (int x,int y);
int main()
{
	int x,y;
	printf ("Enter base number: ");
	scanf ("%d",&x);
	printf ("Enter power number (positive integer): ");
	scanf ("%d",&y);
	printf ("%d ^ %d = %d ",x,y,power(x,y));
}
int power (int x, int y)
{
	if (y>=1)
		return x * power (x,y-1);
	else
		return 1;
}
