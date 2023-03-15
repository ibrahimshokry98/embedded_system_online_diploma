/*
 * main.c
 *
 *  Created on: Jun 29, 2021
 *      Author: Shokry
 */

#include "stdio.h"

void main()
{
	int a[100];
	int n,x,i;
	printf ("enter no of elements : ");
	fflush (stdout);   fflush (stdout);
	scanf ("%d",&n);
	for (i=0;i<n;i++)
		scanf ("%d",&a[i]);
	printf ("enter the element to be searched : ");
	fflush (stdout);   fflush (stdout);
	scanf ("%d",&x);

	for (i=0;i<n;i++)
	{
		if (a[i]==x)
		{
			printf ("number found at location = %d\n",i+1);
			break;
		}
	}
	if (a[i]!=x)
		printf ("number not exist ");

	return 0;
}