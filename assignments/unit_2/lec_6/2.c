#include "stdio.h"

struct Sdistance
{
    int feet;
    float inch;
};
struct Sdistance enterData (char name[]);
struct Sdistance add(struct Sdistance a,struct Sdistance b);
void print (struct Sdistance c);
int main()
{
   struct Sdistance x = enterData("1st");
   struct Sdistance y = enterData("2nd");
   struct Sdistance z = add(x,y);
   printf ("sum of distances = ");
   print (z);
}
struct Sdistance enterData (char name[])
{
    struct Sdistance c;
    printf ("\nEnter Information for %s distance\n",name);
    printf ("Enter Feet : ");
    scanf ("%d",&c.feet);
    printf ("Enter inch : ");
    scanf ("%f",&c.inch);
    return c;
}
struct Sdistance add(struct Sdistance a,struct Sdistance b)
{
    struct Sdistance c;
    c.feet = a.feet + b.feet;
    c.inch = a.inch + b.inch;
    if (c.inch>=12)
    {
        c.inch-=12;
        c.feet++;
    }
    return c;
}
void print (struct Sdistance c)
{
    printf (" %d'- %.1f\"",c.feet,c.inch);
}