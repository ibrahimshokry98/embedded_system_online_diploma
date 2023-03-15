/*
 * main.c
 *
 *  Created on: Jun 29, 2021
 *      Author: Shokry
 */

#include "stdio.h"

void main()
{
	float a[2][2],b[2][2],s[2][2];
	int r,c;
	printf ("the elements of the 1st matrix \n");
	for (r=0;r<2;r++)
	{
		for (c=0;c<2;c++)
		{
			printf ("enter a%d%d ",r+1,c+1);
			scanf ("%f",&a[r][c]);
		}
	}
	printf ("the elements of the 2nd matrix \n");
	for (r=0;r<2;r++)
	{
		for (c=0;c<2;c++)
		{
			printf ("enter b%d%d ",r+1,c+1);
			scanf ("%f",&b[r][c]);
		}
	}
	for (r=0;r<2;r++)
	{
		for (c=0;c<2;c++)
			s[r][c] = a[r][c] + b[r][c];
	}
	printf ("sum of matrix \n");
	for (r=0;r<2;r++)
	{
		for (c=0;c<2;c++)
		{
			printf ("%2.1f\t",s[r][c]);
		}
		printf ("\n");
	}
}
