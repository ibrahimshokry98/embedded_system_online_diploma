/*
 * main.c
 *
 *  Created on: Jun 29, 2021
 *      Author: Shokry
 */

#include "stdio.h"

void main()
{
	int n,sum = 0;
	printf ("Enter an integer: ");
	fflush (stdout);
	scanf ("%d",&n);
	for (int i=0;i<=n;i++)
	{
		sum += i;
	}
	printf("sum = %d ",sum);
}
