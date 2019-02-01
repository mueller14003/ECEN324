#include <stdio.h>
#include <stdlib.h>

int tadd_ok(int x, int y)
{
   int sum = x + y;
   return (sum-x==y)&&(sum-y==x);
}

int main()
{
   int x,y,t;
   printf("X: ");
   scanf("%d",&x);
   printf("Y: ");
   scanf("%d",&y);
   t = tadd_ok(x,y);
   printf("Out: %d\n",t);
   return 0;
}
