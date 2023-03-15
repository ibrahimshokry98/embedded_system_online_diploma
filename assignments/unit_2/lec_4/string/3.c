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
	int i,x;
	char temb;
	printf ("enter a string : ");
	fflush (stdout);   fflush (stdin);
	gets (text);
	x = strlen(text)-1;
	for (i=0;i<x;i++,x--)
	{
		temb = text[i];
		text[i]= text[x];
		text[x]=temb;
	}
	printf ("reverse string is : %s",text);

	return 0	;
}
