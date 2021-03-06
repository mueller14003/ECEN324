/***********************************************************************
* Program:
*    Lab Datalab
*    Brother Jones, ECEN 324
* Authors:
*    Kyle Mueller, Atsushi Jindo
* Summary:
*    This program implements a number of operators and functions, using
*    only select bitwise operators. The functions and operators would
*    be trivial to implement using regular code, but they become much
*    more challenging when implementing them in a very limited number
*    of operators.
***********************************************************************/

/* 
 * CS:APP Data Lab 
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *          Even though you may work as a team, all students should
 *          individually submit a solution.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#include "btest.h"
#include <limits.h>

/*
 * Instructions to Students:
 *
 * STEP 1: Fill in the following struct with your identifying info.
 */
team_struct team =
{
   /* Team name: Replace with either:
      Your login ID (Linux Lab username) if working as a one person team
      or, ID1+ID2 where ID1 is the login ID of the first team member
      and ID2 is the login ID of the second team member.
       Example: joestudent+zmename */
    "kylemueller+ajindo", 
   /* Student name 1: Replace with the name of first team member */
   "Kyle Mueller",
   /* Login ID 1: Replace with the login ID of first team member */
   "kylemueller",

   /* The following should only be changed if there are two team members */
   /* Student name 2: Name of the second team member */
   "Atsushi Jindo",
   /* Login ID 2: Login ID of the second team member */
   "ajindo"
};

#if 0
/*
 * STEP 2: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Note that in order to make the dlc (data lab checker) happy you need
  to declare all variables at the first of the function.
      dlc happy with:                 dlc not happy with:
      ---------------                 -------------------
      int Funct( arg1, arg2) {          int Funct( arg1, arg2) {
         int varA = ~0;                    int varA = ~0;
         int varB = 1;                     varA = varA + 4;
         varA = varA + 4;                  int varB = 1;
          ...                               ...

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
     NOTE: You may create big constants using code.  
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
     NOTE: You may define additional functions while you are working to
           solve the problems, but the final submission should not have any.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
#endif

/*
 * STEP 3: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest test harness to check that your solutions produce 
 *      the correct answers. Watch out for corner cases around Tmin and Tmax.
 */
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
   // This is the literal equivalent of the bitwise nor operator
   // using the ~ and & operators.

   return ~x & ~y;
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 2
 */
int bitXor(int x, int y) {
   // Using the definition of the | operator, we devised a simple, yet 
   // effective way to implement the bitwise xor operator, using only ~ and &.

   return ~(x & y) & ~(~x & ~y);
}
/* 
 * isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
   // The xor operator already checks for equality. However, we needed to 
   // convert the answer into a 1 or a 0. For this reason, we use two of
   // the ! operators.

   return !!(x ^ y);
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
   // Shifting n to the left 3 times multiplies the value by 8. Shifting x to
   // the right n * 8 times isolates the desired byte in the least significant 
   // byte. Using the & operator with the last value and the hexadecimal value 
   // 0xff 'ands' the desired byte with 1's and the rest of the bytes with 0's,
   // yielding the desired outcome.

   return (x >> (n << 3)) & 0xFF;
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
   // This function was fairly simple to implement. Shifting x to the left 31
   // times moves the originally least significant bit to the most significant
   // bit. Shifting this value to the right 31 times will either fill the values 
   // with 1's or 0's. This is due to the fact that we are using an arithmetic 
   // right shift.

   return (x << 31) >> 31;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 1 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  // To implement a logical right shift, first an arithmetic right shift must be
  // performed. Next, the resulting value from the arithmetic right shift is anded
  // with a mask. The mask will have the appropriate amount of zeros in the most 
  // significant bits. The mask was created in order to change any possible 1's 
  // that resulted from the arithmetic right shift to 0's.
  int mask = ~((1 << 31) >> n << 1);

  return (x >> n) & mask;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  // Two 8 bit masks are initially created. The masks are expanded to cover 32 bits.
  // The first mask is applied to the input value by summing x shifted right 0-3 
  // times, each anded with the first mask separately. The resulting value is then 
  // added to itself shifted right 4 times, and anded with the second mask. The value
  // stored in x is then copied through the rest of the 32 bits. The final result is 
  // anded with 0x3f to isolate the 6 least significant bits before being returned.
  int n1 = 0x11;
  int n3 = 0x0F;

  n1 += (n1 << 8);
  n1 += (n1 << 16);
  n3 += (n3 << 8);
  n3 += (n3 << 16);

  x = (x & n1) + ((x >> 1) & n1) + ((x >> 2) & n1) + ((x >> 3) & n1);
  
  x = (x + (x >> 4)) & n3;
  x += (x >> 8);
  x += (x >> 16);     
  
  return x & 0x3F;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  // An or operation is performed with x and the inverse two's complement of x. This
  // value is negated, and shifted right 31 times. The value is then anded with 1 and 
  // returned.

  return 1 & (~((~x + 1) | x) >> 31);
}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 4 
 */
int leastBitPos(int x) {
  // A mask is created by bit-flipping the value of x and adding one. The mask is
  // anded with x and returned.

  return (~x + 1) & x;
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
   // Since we are dealing with two's complement, and we desire the largest possible
   // integer, we must keep the value of the most significant bit at 0, while filling
   // the rest of the bits with 1's. To accomplish this, one can take the value of 1,
   // and shift it left 31 times, resulting in the value of 0x80000000. Then, one can
   // flip the bits, resulting in the value 0x7fffffff, the largest 2's complement 
   // value (using 32 bits).

   return ~(1 << 31);
}
/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
  // The most significant bit of x is isolated by shifting right 31 times. Then the 
  // result is negated and returned.

  return !(x >> 31);
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  // The value of bit-flipped y is added to x and then bit-flipped. This value is 
  // anded with an or of bit-flipped x and y. An or operation is then performed 
  // with this value and bit-flipped x anded with y. The value is then shifted 
  // right 31 times, and finally anded with 1 before being returned.
  int nx = ~x;

  return 1 & (((nx & y) | (~(x + ~y) & (nx | y))) >> 31);
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
  // A fix is created to compensate for two's complement. The value of x is added 
  // to this, and then shifted right n times. This value is then returned.
  int fix = ((1 << n) + ~0) & (x >> 31);

  return (x + fix) >> n;
}
/* 
 * abs - absolute value of x (except returns TMin for TMin)
 *   Example: abs(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int abs(int x) {
  // A variable is created that stores the sign of x. Then one is added to the 
  // bit-flipped sign. This value is then added to x xor the sign, and returned.
  int s = x >> 31;

  return (1 + ~s) + (x ^ s);
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
  // A variable is created to store the sum of x and y. An xor is performed 
  // between the sum and x and y respectively, and the values are anded together.
  // This value is then shifted to the right 31 times. Then the value is inversed 
  // and returned.
  int sum = x + y;

  return !(((sum ^ x) & (sum ^ y)) >> 31);
}
