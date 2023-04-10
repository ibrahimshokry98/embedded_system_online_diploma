#include <stdio.h>
#include <string.h>
int main()
{
	int arr[15],n,i;
	int* ptr =arr;
	printf("input the number of the elements to store in the array (max 15): ");
	scanf ("%d",&n);
	for (i=0;i<n;i++)
	{
		printf ("element - %d : ",i+1);
		scanf ("%d",ptr++);
	}
	printf("the elements of the array in reverse order :\n");
	for (i=n;i>0;i--)
	{
		ptr--;
		printf ("element - %d : %d \n",i,*ptr);
	}
	return 0;
}
