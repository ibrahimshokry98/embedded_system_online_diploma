#include "stdio.h"
#define pi 3.1415
#define area(r)(pi*r*r)
int main()
{
    float radius,area;
    printf ("Enter the radius : ");
    scanf ("%f",&radius);
    area=area(radius);
    printf ("Area = %.2f",area);
}