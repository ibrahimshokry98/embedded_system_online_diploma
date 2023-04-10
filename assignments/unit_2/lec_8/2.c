#include <stdio.h>

int main()
{
	char arr[26];
	char* ptr=arr;
	char i;
	for (i=0;i<26;i++)
	{
		*ptr = 'A'+i;
		ptr++;
	}
	ptr = arr;
	printf ("The alphabets are :\n\n");
	for (i=0;i<26;i++)
	{
		printf ("  %c  ",*ptr);
		ptr++;
	}

return 0;
}
