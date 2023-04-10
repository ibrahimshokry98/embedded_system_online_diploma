#include <stdio.h>

int main()
{
	int m=29;
	int* ab;
	printf ("Address of m = 0x%p\n",&m);
	printf ("value of m = %d\n",m);
	ab = &m;
	printf ("\nNow ab is assigned with the address of m\n");
	printf ("Address of ab = 0x%p\n",ab);
	printf ("content of pointer = %d\n",*ab);
	m= 34;
	printf ("\nthe value of m is assigned to 34 now\n");
	printf ("Address of ab = 0x%p\n",ab);
	printf ("content of pointer = %d\n",*ab);
	*ab = 7;
	printf ("\nthe pointer variable ab is assigned with the value 7 now\n");
	printf ("Address of m = 0x%p\n",&m);
	printf ("value of m = %d\n",m);
return 0;
}
