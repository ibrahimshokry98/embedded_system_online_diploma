#include "stdio.h"

int ones(int num);
int main()
{
    int num;
    printf ("Enter the number : ");
    scanf ("%d",&num);
    printf("max number of ones : %d",ones(num));
  
}
int ones(int num)
{
    int count=0,max_count=0;
   while (num!=0)
   {
        if (num&1)
        {
            count++;
            if (count>max_count)
                max_count=count;
        }
        else
        {
            count=0;
        }
    num>>=1;
   }
   return max_count;
}