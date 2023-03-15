/*
 * main.c
 *
 *  Created on: Jun 29, 2021
 *      Author: Shokry
 */

#include "stdio.h"

void main()
{
	float a[100];
	float sum = 0;
	int n,i;
	printf ("enter the number of data : ");
	fflush (stdout);    fflush (stdin);
	scanf ("%d",&n);
	while (n>100||n==0)
	{
		printf ("wrong number!!! Enter again the number of data : ");
		fflush (stdout);    fflush (stdin);
		scanf ("%d",&n);
	}
	for (i=0;i<n;i++)
	{
		printf ("%d. Enter number: ",i+1);
		fflush (stdout);    fflush (stdin);
		scanf ("%f",&a[i]);
		sum += a[i];
	}
	printf ("Average = %.2f",sum/n);
}
