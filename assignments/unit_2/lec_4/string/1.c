/*
 * main.c
 *
 *  Created on: Jun 29, 2021
 *      Author: Shokry
 */

#include "stdio.h"
#include "string.h"

void main()
{
	char text [100];
	char x;
	int i,j;
	printf ("enter a string : ");
	fflush (stdout);   fflush (stdin);
	gets (text);
	printf ("enter a character to find frequency : ");
	fflush (stdout);   fflush (stdin);
	scanf ("%c",&x);
	for (i=0,j=0;text[i]!=0;i++)
	{
		if (text[i]==x)
			j++;
	}
	printf ("frequency of %c = %d",x,j);

	return 0;
}
