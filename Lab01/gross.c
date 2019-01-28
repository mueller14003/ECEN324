#include <stdio.h>
#include <stdlib.h>

#define FULLTIME 40

int main()
{
   float h,r;
   printf("Hours: ");
   scanf("%f",&h);
   printf("Rate: ");
   scanf("%f",&r);
   float gross = (r*h) + (.5*r*(h-FULLTIME))*(h > FULLTIME);
   printf("Gross Pay: %.2f\n",gross);
   return 0;
}
