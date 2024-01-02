/* 
 * CS:APP Data Lab 
 * 
 * <JONGMIN BAEK 2018142029>
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
/* Copyright (C) 1991-2020 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
  /* operation ~(x+y) = ~x~y is always true */      
  int var1 = (~x) & (~y);
  return var1;
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (least significant) to 3 (most significant)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
/* rights shift x by n*3, then lsb byte will be the answer */
  int var1 = n << 3;  
  int var2 = x >> var1;
  int var3 = var2 & 0xFF;
  return var3;
}
/* 
 * bitMask - Generate a mask consisting of all 1's 
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {

  int var1 = ~(0x0) << (highbit+1);
  int var2 = ~(0x0) << lowbit;
 /* mostly ~var1 & var2 will be the answer */
  int var3 = (highbit + 1) >> 5;
 /* but when hightbit is 31, var1 becomes -1, in fact it should be 0
  * so only when hightbit is 32, 1 must be added to var1 to become 0 
  * var3 becomes 1 only when hight bit is 31 otherwise, zero*/
  int var4 = (~(var1 + var3)) & var2;
	return var4;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
	int var1 = x >> 16;
	int var2 = var1 | x;
	/* if x is not zero, var2[16 : 0] is not zero */ 
	int var3 = var2 >> 9;
	int var4 = var3 | var2;
	/* if var2 is not zero, var4[9,0] is not zero */
	int var5 = var4 >> 5;
	int var6 = 0x1 >> var4;
	/* var6 will be 0 if var4[4:0] is not zero */
	int var7 = 0x1 >> var5;
	/* var7 will be 0 of var4[9:5] is not zero */
	int var8 = var6 & var7;
	/* if var6 and var7 is both 1, x is zero. otherwise, var8 will be 0*/
  return var8;
}
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
	/* if x has odd number of 0's,
	 * xor operation of x[15:0] and x[31,16] will have odd number of 1's */
	int var1 = x ^ (x >> 16) ;
	/* if var1 has odd number of 1's, var2 will have odd number of 1's
	 * and keep doing this until it reduces to 1 bit */
	int var2 = var1 ^ (var1 >> 8);
	int var3 = var2 ^ (var2 >> 4);
	int var4 = var3 ^ (var3 >> 2);
	int var5 = var4 ^ (var4 >> 1);
	/* LSB of var5 will be 1 if x has odd nuber of 0's, otherwise var5 is 0 */
	int var6 = var5 & 0x1;
	/* extract LSB of var5 */
  return var6;
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
	/* maximum when sign bit is zero and other bits are all 1's */
	int var1 = ~ (0x1 << 31);
  return var1;
}
/* 
 * isNegative - return 1 if x < 0, return 0 otherwise 
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNegative(int x) {
	/* if x<0, sign bit is 1, otherwise aero */
	int var1 = x >> 31;
	/* var1 will be -1 if x<0, otherwise var1 is 0 */
	int var2 = !(~var1);
  return var2;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
	/* if x[31, n-1] is all 1's or all 0's, x can be represented as an n-bit */ 
	int var1 = ~0x0 + n;
	int var2 = x >> var1;
	/* if var2 is -1 or 0, answer is 1 */
	int var3 = (!var2) | (!(~var2));
  return var3;
}
/* 
 * dividePower2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: dividePower2(15,1) = 7, dividePower2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int dividePower2(int x, int n) {
	int var1 = x >> n;
	/* if x is positive, answer is var1 */
	int var2 = !(~(x >> 31));
	/* if x is negative, var2 is 1 otherwise, zero */
	int var3 = ~((~0x0) << n);
	int var4 = !!(var3 & x);
	/* if x[n-1,0] is all 0's, var4 will be 0 
	 * if x is negative, mostly answer is var1 + 1 but if
	 * x is negative and x[n-1,0] is all 0's, answer is calculated like positive x */
	int var5 = (var4 & var2) + var1;
	/* answer is added by 1 only when x is negative and x[n-1,0] is not all 0's */
    return var5;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
	int var1 = !!x;
	int var2 = (~0x0) + var1;
	/* var2 will be -1 if x is zero, otherwise it will be 0 */
	int answer = (var2 & z) + ((~var2) & y);
	/* if x is zero, answer will be z, otherwise y */
  return answer;
}
/*
 * ezThreeFourths - multiplies by 3/4 rounding toward 0,
 *   Should exactly duplicate effect of C expression (x*3/4),
 *   including overflow behavior.
 *   Examples: ezThreeFourths(11) = 8
 *             ezThreeFourths(-9) = -6
 *             ezThreeFourths(1073741824) = -268435456 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int ezThreeFourths(int x) {
	int var1 = x + x + x;
	int var2 = var1 >> 2;
	/* if 3x is positive, var2 will be the answer */
  	int var3 = !(~(var1 >> 31));
        int var4 = !!(3 & var1);
	/* if 3x is negtaive and 3x[1:0] is not all 0's, 1 should be added to answer 
	 * this also include over flow behavior*/
        int var5 = (var4 & var3) + var2;
    return var5;

}
/* 
 * signMag2TwosComp - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: signMag2TwosComp(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int signMag2TwosComp(int x) {
  int var1 = (0x1 << 31)^((~x) + 1);
  /* var2 is 2's complement of negative x*/
  int var2 = ~(0x0) + !(~(x >> 31));
  /* var2 is conditional value which become 0 when x is negative,
   * and -1 when x is positive value */
  int var3 = (var2 & x) + ((~var2) & var1);
  /* answer is conditionally differs. if x is negative, answer will be var1,
   * and if x is positive or zero, x will be the answer */
	return var3;
}
/* 
 * floatAbsVal - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatAbsVal(unsigned uf) {
	unsigned var1 = (uf << 1) >> 1;
/* set var1 as a return value by removing sign bit*/
	int var2 = !(~uf & (0xff << 23));
/* when EXP bits are all 1, it's NaN. and var2 will become True*/
	int var3 = !(uf << 9);
/* But if frac bits are all 0, it's not a NaN and var3 will become TRUE*/
	if(var2 && !var3){/* if var2 is True and var3 is not True, it's NaN case*/
		var1 = uf;} /* in this case var1 is reassigned as original argument*/
	return var1;
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
  	int E = ~0x7e + ((uf << 1) >> 24);
	/* E = -127 + EXP */
	int s = uf >> 31;
	/* sign bit */
	int frac = (uf << 9) >> 9;
	/* fraction bits */
	int M = (frac + (0x1 << 23)) << 7;
	/* This value will be modified including shiftting and will be returned*/
	int var1 = !~((~0x1e + E) >> 31);
	/* E should be smaller than 31 in order to fit the range of int*/
	if(var1){
		M = M >> (30 + (~E +1));}
	/* if E is in range of int M will be shifted by E value*/ 
	if(s){
                M = ~M + 1;}
	/* if sign bit is 1 it should be negative value*/
	if(!var1){
		M = 0x1 << 31;}
	/* if E is bigger than 31 it is out of range or infinite. in fact, if E is 31 and frac bits are all 0 and sign bit is 1, it is in range. it should return -2^31. But fortunately it is same with error return value. So this case can be ignored*/  	
	if(!~(E >> 31)){
		M = 0;}
	/* if E is negative value, uf is always in range 0~1. So it should return 0*/
	return M;
}

/*
 * floatScale4 - Return bit-level equivalent of expression 4*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale4(unsigned uf) {
	unsigned scale4 = 0;
	int exp = (uf << 1) >> 24;
	int frac = (uf << 9) >> 9;
	int sign = (uf >> 31) << 31;

	int frac1 = frac;
	int exp1 = 0;
	int var1 = frac1 >> 21;
	/* frac1 and exp1 will be used in case when exp is 0 
	 * var1 is two msb of frac which is 00,01,10,11 */

	scale4 = uf + (0x1 << 24);
	/* mostly, multiplying 4 means that exp is added by 2*/

	if((exp + 3) >> 8){
	/* if exp is bigger than 11111101, it returns different value*/	
		scale4 = sign + (0xff << 23);
		/* if it;s not NaN, result overflow, it returns infinity */
		if(!(((uf^sign) + 0x80800000)>>31)){
		/* if uf is NaN, it reutrns argument */
			scale4 = uf;}}

	if(!exp){
	/* if exp is zero, E = E1+E2 = -126 + 2 = -124 */
		frac1 = frac << 2;
		/* if var1 is 0, frac is left shifted twice and M = 0.xx 
		 * and E = -126 which means exp is 0 */
		if(var1){
		/* when var1 is 11,10,01 */
			frac1 = (frac^(0x1<<21))<<2;
			/* if var1 is 01, frac1 left shifted twice and M = 1.xx 
			 * and E = -126, which means that exp = -126 + 127 = 1 */
                        exp1 = 1;
			if(frac >> 22){
			/* if var is 10 or 11, frac1 is left shifted once and M = 1.xx
			 * and E = -125 whi means that exp = -125 + 127 -2 */
				frac1 = (frac^(0x1<<22))<<1;
				exp1 = 2;}
			}
		scale4 = sign + (exp1 << 23) + frac1;} 
		/*final scale4 for wxp zero case */
		
	return scale4;
}
