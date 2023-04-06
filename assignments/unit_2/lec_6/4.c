#include "stdio.h"

struct Sstudent
{
    char name[50];
    int roll;
    int marks;
};
struct Sstudent enterData (int i);
void displayData (struct Sstudent x,int i);




int main()
{
    struct Sstudent students[10];
    printf ("\nEnter information for student :\n");
    for (int i=0;i<10;i++)
    {
        students[i]=enterData(i+1);
    }
    
    printf ("\n Displaying information\n");
    for (int i=0;i<10;i++)
    {
        displayData(students[i],i+1);
    }
    
    return 0;

}
struct Sstudent enterData (int i)
{
struct Sstudent x;
   printf (" \nFor roll number %d:\n",i); 
   x.roll = i;
    printf ("Enter name : ");
    scanf ("%s",x.name);
    printf ("Enter marks : ");
    scanf ("%d",&x.marks);
    return x;
}
void displayData (struct Sstudent x,int i)
{
    printf ("\ninformation For roll number %d:\n",i);
    printf ("name : %s\n",x.name);
    printf ("marks : %d\n",x.marks);

}
