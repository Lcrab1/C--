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
// 1
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y)
{
  //德摩根律
  // a^b=~((~a)&(~b))&(~(x&y));
  return ~((~(x & (~y))) & (~(y & (~x))));
}

/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void)
{

  return 1 << 31;
}
// 2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x)
{
  //两个特殊值 INT_MAX+1=~INT_MAX
  //          -1+1=~(-1)
  //所以需要满足x+1的值和~x相等，同时这个值不是-1，即不是0b111111....111
  return (!((~(x + 1)) ^ x)) & !(!((x + 1) ^ 0x0));
}
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x)
{
  //错误点在于仅仅使用了与运算，在对2 4 6 8位进行与运算之后，还需要检验最后的结果是否是0xaa格式
  // return !!((x & 0xaa) & (x >> 2) & (x >> 4) & (x >> 6));
  //错误点在于移位应该分别是8 16 24
  // return !!(((x & 0xaa) & (x >> 2) & (x >> 4) & (x >> 6))^0xaa);
  return !(((x & 0xaa) & (x >> 8) & (x >> 16) & (x >> 24)) ^ 0xaa);
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
  return ~x + 1;
}
// 3
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x)
{
  int secondNum = (x >> 4);
  int isHex1 = !(secondNum ^ 0x3); //精确值
  //(x & 0xA) ^ 0xA  只要有0xA这样特征的位表示，表达式均为0
  int isHex2 = (!!(((x & 0xA) ^ 0xA)) & (!!((x & 0xC) ^ 0xC))); //范围
  return isHex1 & isHex2;
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z)
{
  int a = !!x;
  a = a << 31 >> 31;
  return (a & y) | (~a & z);
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y)
{
  // 1.x=y
  int isEqual = !(x ^ y);

  int signX = (x >> 31) & 0x1;
  int signY = (y >> 31) & 0x1;
  // 2.x- y+  return 1
  int cond2 = signX & (!signY); //
  // 3.x+ y-  return 0
  int cond3 = !((!signX) & signY);
  // 4.x-y- x+y+
  int cond4 = ((x + (~y) + 1) >> 31) & 0x1;
  return isEqual | (cond3 & (cond2 | cond4));
}
// 4
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x)
{
  // int a=0b1100
  //-a=0b0011+1=0b0100

  // 0和非0
  int negX = ~x + 1;
  int sign = (x | negX) >> 31; //非零值的sign此时全是-1  0的sign是0
  return sign + 1;             // sign+1对应着0和1
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5       01100 说明0也是需要保留的
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4       1011
 *            howManyBits(0)  = 1       0
 *            howManyBits(-1) = 1       1
 *            howManyBits(0x80000000) = 32  10000...
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x)
{
  //判断是正数还是负数
  int flag = x >> 31;
  int y = ((~flag) & x) | (flag & (~x)); //前面拿正数 后面拿负数
  int bits_16, bits_8, bits_4, bits_2, bits_1, bits_0;
  bits_16 = (!!(y >> 16)) << 4;
  y >>= bits_16;
  bits_8 = (!!(y >> 8)) << 3;
  y >>= bits_8;
  bits_4 = (!!(y >> 4)) << 2;
  y >>= bits_4;
  bits_2 = (!!(y >> 2)) << 1;
  y >>= bits_2;
  bits_1 = (!!(y >> 1));
  y >>= bits_1;
  bits_0 = y;

  int res = bits_16 + bits_8 + bits_4 + bits_2 + bits_1 + bits_0 + 1; //+1表示的是符号位 0 1 都要加

  return res;
}
// float
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
unsigned floatScale2(unsigned uf)
{

  unsigned sig = uf >> 31;
  unsigned exp = (uf >> 23) & 0xff;
  unsigned mask = (0x7 << 20) | (0xff << 12) | (0xff << 4) | (0xf);
  unsigned frac = uf & mask;
  unsigned bias = 0x7f;
  int isExpZero = !(exp ^ 0x0);
  int isFracZero = !(frac ^ 0x0);
  // NaN Infi
  unsigned NaN_or_Infi = !(exp ^ 0xff);

  if (NaN_or_Infi)
    return uf;

  // 0
  if (isExpZero && isFracZero)
  {
    return sig << 31;
  }
  // exp==0
  if (isExpZero && (!isFracZero))
  {
    frac <<= 1;
    return sig << 31 | exp << 23 | frac;
  }
  // exp!=0
  exp = exp + 1;
  unsigned res = sig << 31 | exp << 23 | frac;
  return res;
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
int floatFloat2Int(unsigned uf)
{
  unsigned bias = 0x7f;
  unsigned sig = uf >> 31;
  int exp = uf >> 23 & 0xff;
  unsigned frac = uf & 0x7fffff;
  int E = exp - bias;
  unsigned M;
  int num;
  // NaN and Infi
  unsigned NaNorInfi = !(exp ^ 0xff);
  // exp<bias+0 1.xxxxxx  直接返回0

  // bias+23<=exp<bias+31 frac可以完全被移位，并且int不会溢出
  // bias+31<=exp int会溢出
  // bias+0<=exp<bias+23  部分frac可以被移位
  if (NaNorInfi)
  {
    num = 0x80000000u;
  }
  else if (E < 0)
  {
    num = 0;
  }
  else if (E >= 31)
  {
    num = 0x80000000u;
  }
  else
  {
    //相当于1.xxxx直接变成1xxxx 即已经移了23位了
    M = frac | 0x8000000;
    if (E >= 23)
    {
      //所以如果E大于23，那么移动的位数不够，还需要再左移E-23位
      num = M << (E - 23);
    }
    else
    {
      //如果E小于23，那么此时移动的多了，还要右移(23-E)位，把多左移的位右移回来
      num = M >> (23 - E);
    }
  }
  if (sig)
  {
    return -num;
  }
  else
  {
    return num;
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
unsigned floatPower2(int x)
{
  int INF_POS = 0x7f800000;
  int bias = 0x7f;
  int exp;
  int num;
  int frac;
  int offset;
  if (x < -149)
  {
    num = 0;
  }
  else if (x > 128)
  {
    num = INF_POS;
  }
  else if (x > -126 && x <= 128)
  {
    exp = x + bias;
    num = exp << 23;
  }
  else
  {
    offset = -x - bias + 1;
    exp = 0;
    frac = 1 << (23 - offset);
    num = frac;
  }
  // x<-149 return 0
  //   -149<=x<=-126    denormalized
  // 0
  //-126<x<=128   normalized
  // x>128 return +INF
  //+INF=0111 1111 1000 000...... =0x7f800000;

  return num;
}
