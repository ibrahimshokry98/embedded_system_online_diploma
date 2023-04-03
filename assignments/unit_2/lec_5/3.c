/*
 * main.c
 *
 *  Created on: Jun 29, 2021
 *      Author: Shokry
 */

#include "stdio.h"
#include "string.h"
void reverse (char str[],int i,int j);
int main()
{
	char str[100];
	int i,j=0;
	printf ("Enter a sentence: ");
	gets(str);
	for (i=0;str[i]!=0;i++);
	i--;
	reverse (str,i,j);
	printf ("reversed sentence is: %s",str);
}
void reverse (char str[],int i,int j)
{

	char temp;
	temp =str[j];
	str[j]=str[i];
	str[i]=temp;
	i--;
	j++;
	if (j<i)
	reverse (str,i,j);
}