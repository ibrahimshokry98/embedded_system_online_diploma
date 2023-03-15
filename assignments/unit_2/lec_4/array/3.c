/*
 * main.c
 *
 *  Created on: Jun 29, 2021
 *      Author: Shokry
 */

#include "stdio.h"

void main()
{
	float a[10][10],t[10][10];
	int r,c,i,j;
	printf ("enter rows and column of matrix : ");
	fflush(stdout);    fflush(stdin);
	scanf ("%d %d",&r,&c);
	printf ("Enter elements of the matrix:\n");
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			printf ("Enter element a%d%d : ",i+1,j+1);
			fflush(stdout);    fflush(stdin);
			scanf ("%f",&a[i][j]);
		}
	}
	printf ("Entered matrix: \n");
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			printf ("%.1f\t",a[i][j]);
		}
		printf ("\n");
	}
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			t[j][i]=a[i][j];
		}
	}
	printf ("transpose of matrix \n");
	for (i=0;i<c;i++)
	{
		for (j=0;j<r;j++)
		{
			printf ("%.1f\t",t[i][j]);
		}
		printf ("\n");
	}
	return 0;
}
