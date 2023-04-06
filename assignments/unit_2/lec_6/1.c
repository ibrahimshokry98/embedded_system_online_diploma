#include "stdio.h"

struct Sstudent
{
    char name[50];
    int roll;
    float marks;
};


int main()
{
    struct Sstudent x;
    printf ("\nEnter information for student :\n\n");
    printf ("Enter name : ");
    scanf ("%s",x.name);
    printf ("Enter roll : ");
    scanf ("%d",&x.roll);
    printf ("Enter marks : ");
    scanf ("%f",&x.marks);
    printf ("\n Displaying information\n\n");
    printf ("name : %s\n",x.name);
    printf ("roll : %d\n",x.roll);
    printf ("name = %.2f\n",x.marks);

}
