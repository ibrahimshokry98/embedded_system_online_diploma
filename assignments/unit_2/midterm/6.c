#include "stdio.h"

int unique(int size,int arr[]);
int main()
{
    int arr[100],size;
    printf ("Enter the number of elements : ");
    scanf ("%d",&size);
    printf("Enter elements of the array : ");
    for (int i=0;i<size;i++)
    {
        scanf ("%d",&arr[i]);
    }
    printf ("the unique element = %d",unique(size,arr));
}
int unique(int size,int arr[])
{
    int uniq_num=0;
    for (int i=0;i<size;i++)
    {
        uniq_num^=arr[i];
    }
   return uniq_num;
}