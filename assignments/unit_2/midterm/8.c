#include "stdio.h"

int reverse(int size,int arr[]);
int main()
{
    int arr[100],size;
    printf ("Enter the size of the array : ");
    scanf ("%d",&size);
    printf("Enter the array : ");
    for (int i=0;i<size;i++)
    {
        scanf ("%d",&arr[i]);
    }
    reverse(size,arr);
    for (int i=0;i<size;i++)
    {
        printf ("%d ",arr[i]);
    }
}
int reverse(int size,int arr[])
{
    int temp=0;
    for (int i=size-1,j=0;i>=size/2;i--,j++)
    {
        temp=arr[j];
        arr[j]=arr[i];
        arr[i]=temp;
    }
}