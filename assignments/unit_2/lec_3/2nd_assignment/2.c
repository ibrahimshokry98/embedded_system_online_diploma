/*
 * main.c
 *
 *  Created on: Jun 29, 2021
 *      Author: Shokry
 */

#include "stdio.h"

void main()
{
	char x;
	printf ("Enter an alphabet: ");
	fflush (stdout);
	scanf ("%c",&x);
	if (x=='a' || x=='A' || x=='e' || x=='E' || x=='i' || x=='I' || x=='o' || x=='O' || x=='u' || x=='u')
		printf ("%c is a vowel.",x);
	else
		printf ("%c is consonant.",x);

}
