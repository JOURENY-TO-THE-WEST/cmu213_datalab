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
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  return ~(~x|~y);
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
int con=0xff;
x>>=(n<<3);
return x&con;

}
/* 
 * logicalShift -  shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
int changeBit=0x1<<31;
int firstBit=(x>>31)&0x1;
  return ((~changeBit&x)>>n)|(firstBit<<(31+(~n+1)));
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bittCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
int xl=x;
int x0101=(0x55)+(0x55<<8)+(0x55<<16)+(0x55<<24);
int x0011=(0x33)+(0x33<<8)+(0x33<<16)+(0x33<<24);
int x1111=(0x0f)+(0x0f<<8)+(0x0f<<16)+(0x0f<<24);
xl=xl+(~(((xl>>1)&x0101))+1);
xl=(xl&x0011)+((xl>>2)&x0011);
xl=(xl&x1111)+((xl>>4)&x1111);
xl=xl+(xl>>8);
xl=xl+(xl>>16);
  return xl&0x3f;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
int temp=~x;
temp=(temp>>16)&temp;
temp=(temp>>8)&temp;
temp=(temp>>4)&temp;
temp=(temp>>2)&temp;
temp=(temp>>1)&temp;
  return temp&0x01;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {

  return 0x01<<31;
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
int k=32+(~n+1);
int x2=x<<k;
int x3=(~x2)>>k;
int x4=x3+1+x;
  return !x4;
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
int fb=((0x01<<31)&x)>>31;
int app=(0x01<<n)+(~0x01+1);
int x2=(x+(app&fb))>>n;
    return x2;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x+1;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x){
int fb=(0x01<<31)&x;
  return !fb&(!!x);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
int z=y+(~x+1);
int fb=(0x01<<31);
int fbz=fb&z;
int fbx=fb&x;
int fby=fb&y;
  return (!fbz|!!((~fby)&fbx))&(!(fby&(~fbx)));
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
int cnt = 0;
int ffff=~(0xff|0xff<<8);
int x1;
int ff00=(0xff<<8)|(0xff<<24);
int x2;
int f0f0=0xf0+(0xf0<<8)+(0xf0<<16)+(0xf0<<24);
int x3;
int cccc=(0xcc<<8)+(0xcc<<16)+(0xcc<<24)+0xcc;
int x4;
int aaaa=0xaa+(0xaa<<8)+(0xaa<<16)+(0xaa<<24);
int x5;
x1=ffff&x;
cnt+=(~(!!x1)+1)&0x10;
x=x1|(x&(~(!x1)+1));
x2=ff00&x;
cnt+=(~(!!x2)+1)&0x8;
x=x2|(x&(~(!x2)+1));
x3=f0f0&x;
cnt+=(~(!!x3)+1)&0x4;
x=x3|(x&(~(!x3)+1));
x4=cccc&x;
cnt+=(~(!!x4)+1)&0x2;
x=x4|(x&(~(!x4)+1));
x5=aaaa&x;
cnt+=(~(!!x5)+1)&0x1;
return cnt;
}
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
unsigned float_neg(unsigned uf) {
unsigned fb=0x7fffffff;
unsigned x=~(fb^uf);
unsigned nan1=0x7f800000;
unsigned nan2=0x7fffffff;
unsigned nan3=0xff800000;
unsigned nan4=0xffffffff;
if ((uf>nan1&&uf<=nan2)||(uf>nan3&&uf<=nan4))
{
x=uf;
}
 return x;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
unsigned fb=0x80000000&x;
unsigned fnz=31;
unsigned exp=0x3f800000;
unsigned temp;
unsigned length=0x0;
unsigned length2;
unsigned result;
unsigned temp1;
unsigned temp2;
unsigned temp3;
unsigned temp4;
unsigned delta1;
unsigned delta2;
unsigned fnz2;
if(x==0x80000000)
{
result=0xcf000000;
return result;
}
else if(fb==0x80000000)
{
x=~x+1;
}
temp=0x7fffffff&x;
while(((temp&0x80000000)==0)&&(fnz>=1))
{
fnz-=1;
temp<<=1;
}
temp=0x7fffffff&x;
length2=length+fnz;
if(x==0)
{
result=0x0;
}
else if(fnz<23)
{
x<<=(23-fnz);
x|=exp;
length2<<=23;
x+=length2;
result=x|fb;
}
else
{
fnz2=fnz-23;
temp1=temp>>fnz2;
temp4=temp1+1;
temp3=temp1<<fnz2;
temp2=(temp4<<fnz2);
delta1=temp2-temp;
delta2=temp-temp3;
if(delta1>delta2)
{
temp=temp1;
}
else if(delta1<delta2)
{
temp=temp4;
}
else if((temp4&0x00000001)==0)
{
temp=temp4;
}
else
{
temp=temp1;
}
if(temp==0x01000000)
{
temp=0x0;
length2+=1;
}
temp|=exp;
length2<<=23;
temp+=length2;
result=temp|fb;
}
  return result;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
unsigned sep=0x7f800000;
unsigned fb=0x80000000&uf;
unsigned u1=sep&uf;
unsigned u2=0x007fffff&uf;
unsigned x;
unsigned nan1=0x7f800000;
unsigned nan2=0x7fffffff;
unsigned nan3=0xff800000;
unsigned nan4=0xffffffff;
if (((u1|u2)==0)||(uf>=nan1&&uf<=nan2)||(uf>=nan3&&uf<=nan4))
{
x=uf;
}

else if((u2<=0x003fffff)&&(u1==0))
{
u2<<=1;
x=u1|u2|fb;
}
else if((u2>0x003fffff)&&(u1==0))
{
u2=u2<<1;
u1+=0x00800000;
x=u1|u2|fb;
}
else {
u1+=0x00800000;
x=u1|u2|fb;
}
  return x;
}
