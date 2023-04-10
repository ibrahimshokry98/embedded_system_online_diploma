#include <stdio.h>
#include <string.h>
int main()
{
	char str[50],rvs[50],z;
	char* str_ptr = str;
	char* rvs_ptr=rvs;
	printf ("Input a string : ");
	gets (str);
	z = strlen(str);
	str_ptr +=z;
	int i;
	for (i=0;i<z;i++)
	{
		str_ptr--;
		*rvs_ptr = *str_ptr;
		rvs_ptr++;
	}
	*rvs_ptr = 0;
	rvs_ptr=rvs;
	printf ("Reveses of the string : %s",rvs_ptr);
	return 0;
}
