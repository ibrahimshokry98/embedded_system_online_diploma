#include "stdio.h"

int prime(int num1,int num2);
int main()
{
    int num1,num2;
    printf ("Enter n1 : ");
    scanf ("%d",&num1);
     printf ("Enter n2 : ");
    scanf ("%d",&num2);
    printf ("prime numbers : ");
    prime (num1,num2);
  
}
int prime(int num1,int num2)
{
    int check;
   for (int i =num1;i<=num2;i++)
   {
    check=0;
    for (int j=1;j<i;j++)
    {
        if (i%j==0)
            check++;
    }
    if (check ==0||check==1)
        printf ("%d ",i);
   }
}