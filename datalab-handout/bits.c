// Finished on 2021-12-9 15:10
// Author: Ruoyao Xue

/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
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
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


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

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

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
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
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
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  // xor = (~x & y) | (x & ~y);
  // or = ~(~x & ~y);
  int var1 = ~(~x & y);
  int var2 = ~(x & ~y);
  return ~(var1 & var2);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 0x1 << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  // use overflow, namely Tmax + 1 = Tmin
  // only Tmin and zero has equation -x = x
  // so we let y = x + 1, return (~y + 1) == y && y != 0
  int var1 = x + 0x1;
  int is_tmin_or_zero = !((~var1 + 0x1) ^ var1);
  int not_zero = !!var1;
  return is_tmin_or_zero & not_zero ;
}
/* 
 * allOddBits return 1 - if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  // use & and 0xAAAAAAAA to judge, use !(a ^ b) to compute a == b
  int reference = 0xAA + (0xAA << 8) + (0xAA << 16) + (0xAA << 24);
  return !((x & reference) ^ reference);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  // first guarantee the high 28 bits are 0x0000003, if true set high_bits_flag to be 1
  // then, if low 4 bits add 6 has a carry bit 1, means > 9, then set low_bits_flag to be 1
  int high_bits_flag = !((x >> 4) ^ 0x3);
  int low_4bits = x & 0xF;
  int low_bits_flag = !((low_4bits + 6) & 0x10);
  return high_bits_flag & low_bits_flag;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  // when x = 0, set flag = 0x00000000; 0xFFFFFFFF otherwise.
  // return (flag & y) + (~flag & z)
  int flag = ((!!x) << 31) >> 31;
  return (flag & y) + (~flag & z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  // y - x could be expressed as y + (~x + 1), 
  // then we can judge due to sign bit of the output
  // classified discussion: 
  // 1) y_sign = 0, x_sign = 1 ==> 1
  // 2) y_sign = 1, x_sign = 0 ==> 0
  // 3) y_sign = 0, x_sign = 0 ==> !output_sign
  // 4) y_sign = 1, x_sign = 1 ==> !output_sign
  int x_sign = (x >> 31) & 0x1;
  int y_sign = (y >> 31) & 0x1;
  int output_sign = ((y + (~x + 1)) >> 31) & 0x1;
  return ((x_sign ^ y_sign) & x_sign) | (!(x_sign ^ y_sign) & !(output_sign));
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  // (~x + 1) ^ x, only zero and tmin could get zero sign bit
  return ((x | (~x + 1)) >> 31) + 0x1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  // reference: https://zhuanlan.zhihu.com/p/59534845
  int b16,b8,b4,b2,b1,b0;
  int sign=x>>31;
  x = (sign&~x)|(~sign&x);
  b16 = !!(x>>16)<<4;
  x = x>>b16;
  b8 = !!(x>>8)<<3;
  x = x>>b8;
  b4 = !!(x>>4)<<2;
  x = x>>b4;
  b2 = !!(x>>2)<<1;
  x = x>>b2;
  b1 = !!(x>>1);
  x = x>>b1;
  b0 = x;
  return b16+b8+b4+b2+b1+b0+1;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */ 
unsigned floatScale2(unsigned uf) {
  // denorm: sign_bit retains, others left shift 1 bit
  // norm: exp_bits + 1, others retains
  // inf, nan: itself
  int exp_bits = (uf >> 23) & 0xFF;
  int sign_bit = uf & 0x80000000;
  int frac_bits = uf & 0x007FFFFF;
  if(!exp_bits)  // denorm
    return (uf << 1) + sign_bit;
  else if(exp_bits != 0xFF)  // norm
    return (((uf >> 23) + 1) << 23) + frac_bits;
  else  // inf, nan
    return uf;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  // the exponent decides the stride and direction of shift, 
  // while fraction decides precision
  int sign_bit = uf >> 31;
  int exp_bits = (uf >> 23) & 0xFF;
  int frac_bits = (uf & 0x007FFFFF) + 0x00800000;  // used for shifting
  int tem;
  if(exp_bits < 127)  // (0, 127): float < 1
    return 0;
  else if(exp_bits > 158)  // (158, 255): int has 32bits, can only afford 2^31 in float which has a leading one
    return 0x80000000;
  else if(exp_bits >= 150)  // [150, 158]: frac_bits left shift
  {
    tem = frac_bits << (exp_bits - 150);
    if(sign_bit)  // negative
      return -tem;
    else  //positive
      return tem;
  }
  else  // [127, 149]: frac_bits right shift
  {
    tem = frac_bits >> (150 - exp_bits);
    if(sign_bit)  // negative
      return -tem;
    else  //positive
      return tem;
  }
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  if(x < -149)  // (Tmin, -149): too small to be represented by denorm
   return 0;
  else if(x > 127)  // (127, Tmax): too large to be represented by norm
    return 0x7F800000;
  else if(x < -126)  // [-149, -127]: represented by denorm
    return 1 << (150 + x);
  else  // [-126, 127]: represented by norm
    return (127 + x) << 23;
}

