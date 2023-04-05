#include "stdio.h"

int sum(int min,int max);
int main()
{
    int min=1,max=100;
    printf ("sum from 1 to 100 = %d",sum(min,max));
    
}
int sum(int min,int max)
{
    if (min<=max)
    return min+sum (min+1,max);
    else
    return 0;
}