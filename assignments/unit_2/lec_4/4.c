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
	int n,x,i,y;
	printf ("enter no of elements : ");
	fflush (stdout);   fflush (stdout);
	scanf ("%d",&n);
	for (i=0;i<n;i++)
		scanf ("%d",&a[i]);
	printf ("enter the element to be inserted : ");
	fflush (stdout);   fflush (stdout);
	scanf ("%d",&x);
	printf ("enter the location : ");
	fflush (stdout);   fflush (stdout);
	scanf ("%d",&y);
	for (i=n;i>=y;i--)
	{
		a[i]=a[i-1];
	}
	a[i]= x;
	for (i=0;i<=n;i++)
		printf("%d ",a[i]);

	return 0;
}
