#include <stdio.h>

int neq(int x, int y) {
   return !!(x ^ y);
}

int main() {
   int x, y;
   printf("Enter a value for x: ");
   scanf("%x", &x);
   printf("Enter a value for y: ");
   scanf("%x", &y);

   printf("\nx & y = %x",(x & y));
   printf("\nx | y = %x",(x | y));
   printf("\n~x | ~y = %x",(~x | ~y));
   printf("\nx & !y = %x",(x & !y));
   printf("\nx && y = %x",(x && y));
   printf("\nx || y = %x",(x || y));
   printf("\n!x || !y = %x",(!x || !y));
   printf("\nx && ~y = %x",(x && ~y));
   printf("%d\n", neq(x, y));

   return 0;
}
