/***********************************************************************
* Program:
*    Lab C_lab, ECEN 324 Learning C Lab
*    Brother Jones, ECEN 324
* Author:
*    Kyle Mueller
* Summary:
*    This lab consisted of converting C++ code into C code. In some instances,
*    the C code is easier to write, and is more intuitive (printf). In other
*    instances, the C code seemed rather outdated and was not intuitive
*    (pointers, for loop can not define int i).
*    This program prints integers, floats, and a variety of other data types
*    in various ways. It receives input from the user and stores it into a variable.
*    The program prints a table of octal, hexadecimal, decimal, and ASCII values.
*    The program also creates pointers, allocates memory for the pointers, and
*    manipulates their values.
* This lab took me about 3 hours to complete.
************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415926

/***********************************************************************
* The main function prints a variety of data types in a few different ways.
* The function prompts the user for input, and stores the input in a variable.
* The function prints a table of values and creates and manipulates pointers.
***********************************************************************/
int main (void)
{
   const char LETTER = 'A';
   printf("%d\n%.5f\n%c\n", 24, PI, LETTER);
 
   float payRate = 10.50;
   int hours = 40;
   int pay = hours * payRate; // Created this variable to show the value as an int
 
   printf("Users pay rate: $%.1f\n", payRate);
   printf(" Hours worked: %d\n", hours);
   printf("    Gross Pay: $%d\n", pay);
 
   int number;
   fprintf(stderr, "Enter number: ");
   scanf("%d", &number);
   printf("Twice %d is %d\n", number,  number * 2);
   
 
   /*********************************************************************
    *********************** Output an Integer ***************************
    *********************************************************************/
   int anInt = 99;
   float aFloat = 43.2;
 
   printf("\nInteger: %d ###", anInt);
   printf("\nInteger: %10d ###", anInt);
   printf("\nInteger: %-10d ###\n\n", anInt);
   
   /*********************************************************************
    ************************* Output a Float ****************************
    *********************************************************************/
 
   printf("  Float: %.1f ###\n", aFloat);
   printf("  Float: %-10.1f ###\n", aFloat);
   printf("  Float: %10.2f ###\n", aFloat);
   printf("  Float: %.3f ###\n", aFloat);
   printf("  Float: %10.3f ###\n", aFloat);
   printf("  Float: %-10.4f ###\n", aFloat);
   
   /*********************************************************************
    *************** Create some code to output a table ******************
    *********************************************************************
 
    * The following table has a leading tab.
 
        Oct   Dec   Hex   Char
        ----------------------
        141   97    61    a
        142   98    62    b
        143   99    63    c
        144   100   64    d
        145   101   65    e
        146   102   66    f
        147   103   67    g
        150   104   68    h
        151   105   69    i
        152   106   6a    j
        153   107   6b    k
        154   108   6c    l
        155   109   6d    m
        156   110   6e    n
        157   111   6f    o
        160   112   70    p
        161   113   71    q
        162   114   72    r
        163   115   73    s
        164   116   74    t
        165   117   75    u
        166   118   76    v
        167   119   77    w
        170   120   78    x
        171   121   79    y
        172   122   7a    z
 
   *********************************************************************/
   printf("\n\tOct   Dec   Hex   Char\n\t----------------------\n");
   int i; // Have to declare this before, unlike C++
   // Loops through decimal values, displaying them as various types
   for (i = 97; i <= 122; i++) {
      printf("\t%-6o%-6d%-6x%c\n", i, i, i, i);
   }
 
   /*********************************************************************
    *************** Now play with pointers to finish up *****************
    *********************************************************************/
   int *p1, *p2; // Declared the pointers
   p1 = (int*) malloc(sizeof (int)); // Same as doing a new int
   p2 = (int*) malloc(sizeof (int));
 
   *p1 = 42;
   p2 = p1;
   printf("\n*p1 == %d\n*p2 == %d\n", *p1, *p2);

   *p2 = 53;
   printf("*p1 == %d\n*p2 == %d\n", *p1, *p2);
   
   p1 = (int*) malloc(sizeof (int));
   *p1 = 88;
   printf("*p1 == %d\n*p2 == %d\n", *p1, *p2);
    
   printf("Hope you got the point of this example!\n");
 
   free(p1); // Frees up memory
   free(p2);

   return 0;
}

