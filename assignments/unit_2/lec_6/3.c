#include "stdio.h"

struct Scomplex
{
    float rnum;
    float inum;
};
struct Scomplex enterData (char name[]);
struct Scomplex add(struct Scomplex a,struct Scomplex b);
void print (struct Scomplex c);
int main()
{
   struct Scomplex x = enterData("1st");
   struct Scomplex y = enterData("2nd");
   struct Scomplex z = add(x,y);
   printf ("sum = ");
   print (z);
}
struct Scomplex enterData (char name[])
{
    struct Scomplex c;
    printf ("\nfor %s complex number\n",name);
    printf ("Enter real and imaginary respectively : ");
    scanf ("%f%f",&c.rnum,&c.inum);
    printf ("\n");
    return c;
}
struct Scomplex add(struct Scomplex a,struct Scomplex b)
{
    struct Scomplex c;
    c.rnum = a.rnum + b.rnum;
    c.inum = a.inum + b.inum;
    return c;
}
void print (struct Scomplex c)
{
    printf ("%.1f+%.1fi",c.rnum,c.inum);
}