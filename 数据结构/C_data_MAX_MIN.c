******************
>> File Name: 换钱的最小货币数.c
>> Author: 陈俊杰
>> Mail: 2716705056qq.com
# Created Time: Fri 13 Sep 2019 04:46:47 PM CST
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <float.h>


/*
从“limits”这个名称就可以看出，<limits.h> 的初衷应该不仅仅是定义与整型有关的宏，它希望为更多类型添加宏。
当C语言标准委员会决定为浮点数增加一些类似的宏的时候，他们通过投票决定不覆盖 <limits.h> 中已经存在的内容，而是添加了新的头文件 <float.h>。
也许应该把已经存在的 <limits.h> 改名为 <integer.h>，但是C语言标准委员会并没有这样做，历史的连贯性、用户的习惯性战胜了命名的规范性。

<limits.h> 头文件只对整数类型的取值范围进行了收集：
如果想获取与浮点数有关的特性，请转到 <float.h> 头文件；
如果查看指定长度的整数类型，请转到 <stdin.h> 头文件。
*/

void MAX_MIN() //此函数是自动显示C语言中基本数据类型的最大值最小值和字节数
{
	printf("**********************字符和整型***********************\n");
	printf("char的位数:%d\n", CHAR_BIT);
	char A;
	printf("sizeof(char) = %lu\n\n", sizeof(A));

	printf("signed char 类型所能表示的最小值:%d\n", SCHAR_MIN);
	printf("signed char 类型所能表示的最大值:%d\n", SCHAR_MAX);
	signed char B;
	printf("sizeof(signed char) = %lu\n\n", sizeof(B));

	printf("unsigned char 类型所能表示的最大值:%d\n", UCHAR_MAX);
	unsigned char C;
	printf("sizeof(unsigned char) = %lu\n\n", sizeof(C));

	printf("char 类型所能表示的最小值:%d\n", CHAR_MIN);
	printf("char 类型所能表示的最大值:%d\n", CHAR_MAX);
	printf("一个多字节字符最多能包含多少个字节:%d\n", MB_LEN_MAX);

	printf("short int 类型所能表示的最小值:%d\n", SHRT_MIN);
	printf("short int 类型所能表示的最大值:%d\n", SHRT_MAX);
	short int D;
	printf("sizeof(short int) = %lu\n\n", sizeof(D));

	printf("unsigned short int 类型所能表示的最大值:%d\n", USHRT_MAX);
	unsigned short int E;
	printf("sizeof(unsigned short int) = %lu\n\n", sizeof(E));

	printf("int 类型所能表示的最小值:%d\n", INT_MIN);
	printf("int 类型所能表示的最大值:%d\n", INT_MAX);
	int F;
	printf("sizeof(int) = %lu\n\n", sizeof(F));

	printf("unsigned int 类型所能表示的最大值:%u\n", UINT_MAX);
	unsigned int G;
	printf("sizeof(unsigned int) = %lu\n\n", sizeof(G));

	printf("long int 类型所能表示的最小值:%ld\n", LONG_MIN);
	printf("long int 类型所能表示的最大值:%ld\n", LONG_MAX);
	long int H;
	printf("sizeof(long int) = %lu\n\n", sizeof(H));

	printf("unsigned long int 类型所能表示的最大值:%lu\n", ULONG_MAX);
	unsigned long int I;
	printf("sizeof(unsigned long int) = %lu\n\n", sizeof(I));

	printf("long long int 类型所能表示的最小值:%lld\n", LLONG_MIN);
	printf("long long int 类型所能表示的最大值:%lld\n", LLONG_MAX);
	long long int J;
	printf("sizeof(long long int) = %lu\n\n", sizeof(J));

	printf("unsigned long long int 类型所能表示的最大值:%llu\n", ULLONG_MAX);
	unsigned long long int K;
	printf("sizeof(unsigned long long int) = %lu\n\n", sizeof(K));

	printf("**********************浮点数***********************\n");
	/*
	flt = (-1)^sign × mantissa × base^exponent
	对各个部分的说明：
	flt 是要表示的浮点数。
	sign 用来表示 flt 的正负号，它的取值只能是 0 或 1：取值为 0 表示 flt 是正数，取值为 1 表示 flt 是负数。
	base 是基数，或者说进制，它的取值大于等于 2（例如，2 表示二进制、10 表示十进制、16 表示十六进制……）。数学中常见的科学计数法是基于十进制的，例如 6.93 × 1013；计算机中的科学计数法可以基于其它进制，例如 1.001 × 27 就是基于二进制的，它等价于 1001 0000。
	mantissa 为尾数，或者说精度，是 base 进制的小数，并且 1 ≤ mantissa ＜ base，这意味着，小数点前面只能有一位数字；
	exponent 为指数，是一个整数，可正可负，并且为了直观一般采用十进制表示。
	*/
	printf("flt = (-1)^sign × mantissa × base^exponent\n");

	printf("基数或者进制数，上面的base:%d\n", FLT_RADIX);
	printf("浮点数的舍入模式:%d\n", FLT_ROUNDS);
	printf("基数（进制）为 FLT_RADIX 时，float 尾数 mantissa 的最大长度（最大位数），也可以说是浮点数的精度:%d\n", FLT_MANT_DIG);
	printf("基数（进制）为 FLT_RADIX 时，double 尾数 mantissa 的最大长度（最大位数），也可以说是浮点数的精度:%d\n", DBL_MANT_DIG);
	printf("基数（进制）为 FLT_RADIX 时，long double 尾数 mantissa 的最大长度（最大位数），也可以说是浮点数的精度:%d\n\n", LDBL_MANT_DIG);

	printf("float 转换成十进制形式后，小数点后精确数字（能够保证精度的数字）的位数:%d\n", FLT_DIG);
	printf("double 转换成十进制形式后，小数点后精确数字（能够保证精度的数字）的位数:%d\n", DBL_DIG);
	printf("long float 转换成十进制形式后，小数点后精确数字（能够保证精度的数字）的位数:%d\n\n", LDBL_DIG);

	printf("基数（进制）为 FLT_RADIX 时，规格化float浮点数的指数（也即 exponent）的最小值（为负数）:%d\n", FLT_MIN_EXP);
	printf("基数（进制）为 FLT_RADIX 时，规格化double浮点数的指数（也即 exponent）的最小值（为负数）:%d\n", DBL_MIN_EXP);
	printf("基数（进制）为 FLT_RADIX 时，规格化long double浮点数的指数（也即 exponent）的最小值（为负数）:%d\n\n", LDBL_MIN_EXP);

	printf("转换成十进制形式后，规格化float浮点数的指数的最小值（为负数）:%d\n", FLT_MIN_10_EXP);
	printf("转换成十进制形式后，规格化double浮点数的指数的最小值（为负数）:%d\n", DBL_MIN_10_EXP);
	printf("转换成十进制形式后，规格化long double浮点数的指数的最小值（为负数）:%d\n\n", LDBL_MIN_10_EXP);

	printf("基数（进制）为 FLT_RADIX 时，规格化float浮点数的指数（也即 exponent）的最大值（为正数）:%d\n", FLT_MAX_EXP);
	printf("基数（进制）为 FLT_RADIX 时，规格化double浮点数的指数（也即 exponent）的最大值（为正数）:%d\n", DBL_MAX_EXP);
	printf("基数（进制）为 FLT_RADIX 时，规格化long float浮点数的指数（也即 exponent）的最大值（为正数）:%d\n\n", LDBL_MAX_EXP);

	printf("转换成十进制形式后，规格化float浮点数的指数的最大值（为正数）:%d\n", FLT_MAX_10_EXP);
	printf("转换成十进制形式后，规格化double浮点数的指数的最大值（为正数）:%d\n", DBL_MAX_10_EXP);
	printf("转换成十进制形式后，规格化long double浮点数的指数的最大值（为正数）:%d\n\n", LDBL_MAX_10_EXP);

	printf("float最大的有效浮点数的值（为正数），也即浮点数的最大值:%f\n", FLT_MAX);
	printf("float最大的有效浮点数的值（为正数），也即浮点数的最大值:%e\n", FLT_MAX);
	printf("double最大的有效浮点数的值（为正数），也即浮点数的最大值:%f\n", DBL_MAX);
	printf("double最大的有效浮点数的值（为正数），也即浮点数的最大值:%e\n", DBL_MAX);
	printf("long double最大的有效浮点数的值（为正数），也即浮点数的最大值:%Lf\n\n", LDBL_MAX);
	printf("long double最大的有效浮点数的值（为正数），也即浮点数的最大值:%LE\n\n", LDBL_MAX);

	printf("float最大的有效浮点数的值（为正数），也即浮点数的最大值:%e\n", FLT_MAX);
	printf("double最大的有效浮点数的值（为正数），也即浮点数的最大值:%e\n", DBL_MAX);
	printf("long double最大的有效浮点数的值（为正数），也即浮点数的最大值:%Le\n\n", LDBL_MAX);

	printf("float最小的有效浮点数的值（为正数），也即浮点数的最小值:%.30f\n", FLT_MIN);
	printf("double最小的有效浮点数的值（为正数），也即浮点数的最小值:%.30f\n", DBL_MIN);
	printf("long double最小的有效浮点数的值（为正数），也即浮点数的最小值:%.30Lf\n\n", LDBL_MIN);

	printf("float最小的有效浮点数的值（为正数），也即浮点数的最小值:%.20e\n", FLT_MIN);
	printf("double最小的有效浮点数的值（为正数），也即浮点数的最小值:%.20e\n", DBL_MIN);
	printf("long double最小的有效浮点数的值（为正数），也即浮点数的最小值:%.20Le\n\n", LDBL_MIN);

	printf("float 的 1 和大于 1 的最小浮点数之间的差值:%.30f\n", FLT_EPSILON);
	printf("double 的 1 和大于 1 的最小浮点数之间的差值:%.30f\n", DBL_EPSILON);
	printf("long double 的 1 和大于 1 的最小浮点数之间的差值:%.30Lf\n\n", LDBL_EPSILON);

	printf("float 的 1 和大于 1 的最小浮点数之间的差值:%.20e\n", FLT_EPSILON);
	printf("double 的 1 和大于 1 的最小浮点数之间的差值:%.20e\n", DBL_EPSILON);
	printf("long double 的 1 和大于 1 的最小浮点数之间的差值:%.20Le\n\n", LDBL_EPSILON);
}

int main(int argc, char *argv[])
{
	long long int N = 100000;
	double x = 0.0, step = 1.0 / (double)N;
	double pi = 0;

	printf("step = %.20lf\n", step);
	for (int i = 0; i < N; ++i)
	{
		x = (i + 0.5) * step;
		pi += 4.0 / (1.0 + x * x);
	}

	printf("Pi = %.20lf\n", pi);
	pi = pi * step;
	printf("Pi = %.20lf\n", pi);
	printf("hello, world, !!\n");
	printf("*************************************以下是格式化打印各种数据类型*************************************\n");

    	int a = 9;
    	unsigned int a1 = 10;
    	long int a2 = 11;
    	long long int a3 = 12;
    	unsigned long int a3 = 13;
    	unsigned long long int a4 = 14;




	printf("*************************************以下是各种数据类型的最大最小值*************************************\n");
    	/* MAX_MIN(); */

	return 0;
}
