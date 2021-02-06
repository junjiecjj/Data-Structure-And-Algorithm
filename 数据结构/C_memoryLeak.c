/*************************************************************************
>> File Name: C_memoryLeak.c
>> Author: 陈俊杰
>> Mail: 2716705056qq.com
>> Created Time: 2021年01月21日 星期四 19时46分44秒
>> 此程序的功能是：

内存泄漏：
①访问已经释放的内存
②访问没有权限的内存


野指针：
指向内存被释放的内存或者没有访问权限的内存的指针。
“野指针” 的成因主要有 3 种：
（1）指针变量没有被初始化。任何指针变量刚被创建时不会自动成为 NULL 指针，它的缺省值是随机的，它会乱指一气。所以，指针变量在创建的同时应当被初始化，要么将指针设置为 NULL，要么让它指向合法的内存。例如
char *p = NULL;
char *str = new char(100);
（2）指针 p 被 free 或者 delete 之后，没有置为 NULL。
（3）指针操作超越了变量的作用范围。这种情况让人防不胜防，示例程序如下：
class A
{
 public:
void Func(void){ cout << “Func of class A” << endl; }
};
void Test(void)
{
 A *p;
 if(...)
 {
A a;
p = &a; // 注意 a 的生命期
 }
 p->Func(); // p是“野指针”
}
如何避免野指针：
一、对指针进行初始化

①将指针初始化为 NULL。

char * p = NULL;

②用 malloc 分配内存

char * p = (char * )malloc(sizeof(char));
③用已有合法的可访问的内存地址对指针初始化

char num[ 30] = {0};
char *p = num;


二、指针用完后释放内存，将指针赋 NULL。

delete(p);
p = NULL;
注：

malloc 函数分配完内存后需注意：

①检查是否分配成功（若分配成功，返回内存的首地址；分配不成功，返回 NULL。可以通过 if 语句来判断）

②清空内存中的数据（malloc 分配的空间里可能存在垃圾值，用 memset 或 bzero 函数清空内存）

void bzero（void *s, int n）;
s 是 需要置零的空间的起始地址； n 是 要置零的数据字节个数。

void memset(void *start, int value, int size);
如果要清空空间的首地址为 p，value 为值，size 为字节数。
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <sys/socket.h>
#include <stddef.h>
#include <locale.h>
#include <time.h>
#include <complex.h>

int main(int argc, char *argv[])
{

    return 0;
}
