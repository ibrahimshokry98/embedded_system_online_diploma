#include "stdio.h"


int digit_sum(int num);
int main()
{
    int num;
    printf ("Enter the number : ");
    scanf ("%d",&num);
    int result = digit_sum(num);
    printf ("sum = %d",result);
    return 0;
}
int digit_sum(int num)
{
    int reminder = 0,sum = 0;
    while (num!=0)
    {
        reminder = num%10;
        num /=10;
        sum+=reminder;
    }
    return sum;
}