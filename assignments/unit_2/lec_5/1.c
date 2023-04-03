/*
 * main.c
 *
 *  Created on: Jun 29, 2021
 *      Author: Shokry
 */

#include "stdio.h"
#include "string.h"
void prime (int min,int max);
int main()
{
	int x,y;
	printf ("Enter two numbers: ");
	fflush (stdin);  fflush (stdout);
	scanf ("%d %d",&x,&y);
	printf ("prime numbers between %d and %d are: ",x,y);
	prime (x,y);
	return 0;
}
void prime (int min,int max)
{
	if (min%2==0)
		min++;

	for(int i = min; i<=max;i++)
	{
		printf ("%d ",i++);
	}
}
