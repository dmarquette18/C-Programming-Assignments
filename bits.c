/* 
 * CS:APP Data Lab 
 * 
 * David Marquette dmm6247
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
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

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
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
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
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

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Bit manipulations */
/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) 
{
  //says "the opposite of not x and not y" which could be said as "neither x nor y"
  //the opposite of that being "either x or y" which is bit or
       return ~(~x&~y);
}
/* 
 * thirdBits - return word with every third bit (starting from the LSB) set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int thirdBits(void) {
  int y;
  int x;
  //creates a bit pattern of every third bit but with the 8 bits we are allowed to use
  x = 73;
  //shifts 9 to account for the 0 at the end of the first bit section and the extra 0 we have to add
  //in order to preserve the pattern
  x = x<<9;
  x = x+73;
  y = x<<18;
  return x+y;

}
/* 
 * oddBits - return word with all odd-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int oddBits(void) {
  int odd_bit = 170;
  odd_bit = 170 + (170 << 8);
  odd_bit = odd_bit+(odd_bit<<16);
  return odd_bit;
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) 
{
  //creates a bit pattern of 8 1's
  int k = 255;
  //exploites shift left to create powers of 2 to multiply n by 8
  x = x>>(n<<3);
  //and this section of 8 bits with 8 bits of all 1's to preserve only the bits we care about
  return x&k;
}
/* 
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {
  //b is going to give us the section of code we want by multiplying n by 8
  int b = n<<3;
  //pattern of all 1s
  int k = 255;
  //this section creates a pattern of all 1's but 32 bits long
  int j = k<<8;
  int m = 255;
  k = k+j;
  k = (k<<16)+k;
  //create a section of all 1's in the section we want to change
  m = m<<(b);
  //xor that with the all 1's to get a section of 0 in the section we want to change
  k = k^m;
  //& our number to clear out the seciton were changin
  x = x&k;
  //put the new number in position
  c = c<<(b);
  //add the section to our original with the section were changing cleared out
  return c+x;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) 
{
  //exploites the property of 1 that the inverse plus one inverted will be the same as the inverse
  //anding these together will create the only situation where
  //the inverse and the inverse plus one inverted will have a 1 in the left most position
  int y = ~x;
  int z = y+1;
  int k;
  z= ~z;
  k = (y&z);
  k = k>>31;
  return k&1;
}
/* Two's complement arithmetic */
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) 
{
  int y = x+1;
  x = ~(x+y);
  x = (!y)+x;
  return !x;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x)
{
  //the negation of a number is the bitwise negation plus one
  int y = ~x;
  y = y+1;
  return y;
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) 
{
  //explotes the property that addition is okay if the signs of the numbers are different
  //also uses the fact that overflow only occurs if the sign changes
  int z = x^y;
  int j ;
  int u;
  z = z>>31;
  z = z&1;
  j = x+y;
  u = j^x;
  u = ~u;
  u = u>>31;
  u = u&1;
  return z|u;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  //exploites the fact that x is positive so long as the left most digit is not 1
  int y = x>>31;
  int z;
  y = y&1;
  z = !x;
  z = ~(z|y);
  return z&1;
}
/* 
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4 
 */
int isNonZero(int x) {
  //if x is zero y will be all ones
  int y = ~x;
  //if x is 0 the inverse plus one is zero
  y = y+1;
  //if x is 0 or withe the inverse plus one will result in sequence of all ones
  x = x|y;
  x=x>>31;
  return x&1;
}
/* FP operations */
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) 
{
  //removes the s value and checks if uf is greater than the min nan valye
  unsigned min_nan = 0xff<<24;
  unsigned ufc = uf<<1;
  unsigned k;
  if(ufc>min_nan)
    {
      return uf;
    }
  //if s is 0 it turns to 1 and vice versa
  k = 0x80;
  k=k<<24;
  if(uf>>31)
  {
    uf = uf-k;
  }
  else{
    uf=uf+k;
  }
  return uf;
}
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) 
{
  //same logic as above but only checks for negatives
  unsigned min_nan = 0xff<<24;
  unsigned ufc = uf<<1;
  int k;
  if(ufc>min_nan)
    {
      return uf;
    }

  k = 0x80;
  k = k<<24;
  if(uf>>31)
    {
      return uf-k;
    }
  return uf;

}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anythng out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) 
{
  //parses through the uf through the >> and &1 to create the interger representation
  unsigned bias = 127;
  unsigned sign_bit = (uf >> 31) & 1;
  unsigned exp_bits = (uf >> 23) & 255;
  unsigned m_bits = (uf & 8388607);
  unsigned answer = m_bits;

  if(exp_bits == 255)
    {
      return 0x80000000u;
    }

  if(exp_bits == 0)
    {
      return 0;
    }

  if(exp_bits<bias)
    {
      return 0;
    }

  exp_bits = exp_bits - bias;

  if(exp_bits>32)
    {
      return 0x80000000u;
    }

  if(exp_bits>22)
    {
      answer = m_bits <<(exp_bits-23);
    }
  else
    {
      answer = m_bits >> (23 - exp_bits);
    }

  answer = answer + (1<<exp_bits);

  if(sign_bit == 1)
    {
      answer = ~answer + 1;
    }

  return answer;
}
