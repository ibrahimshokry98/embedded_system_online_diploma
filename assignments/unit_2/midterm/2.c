#include "stdio.h"
#include "math.h"

float root(int num);
int main()
{
    int num;
    printf ("Enter the number : ");
    scanf ("%d",&num);
    float result = root(num);
    printf ("root = %.3f",result);
    return 0;
}
float root(int num)
{
    float root = num/2;
    while ((root*root)!=num)
    {
        root = (root+(num/root))/2;
    }
    return root;
}