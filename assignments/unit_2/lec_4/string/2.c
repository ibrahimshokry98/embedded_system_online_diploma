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
	int i;
	printf ("enter a string : ");
	fflush (stdout);   fflush (stdin);
	gets (text);
	for (i=0;text[i]!=0;i++)
	{
	}
	printf ("length of string : %d",i);

	return 0;
}
