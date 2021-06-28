/*
 * main.c
 *
 *  Created on: Jun 27, 2021
 *      Author: Shokry
 */

#include "stdio.h"

void main()
{
	char x;
	printf ("Enter a character: ");
	fflush (stdin); fflush (stdout);
	scanf ("%c",&x);
	printf ("ASCII value of %c: %d",x,x);
}
