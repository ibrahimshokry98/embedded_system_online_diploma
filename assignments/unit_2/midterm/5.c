#include "stdio.h"

int ones(int num);
int main()
{
    int num;
    printf ("Enter the number : ");
    scanf ("%d",&num);
    printf("reversed number is : %d",ones(num));
  
}
int ones(int num)
{
    int i=0,j=0;
   while (num!=0)
   {
    if (num&1)
    j++;
    num>>=1;
    i++;
   }
   return j;
}