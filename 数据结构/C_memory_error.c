/*************************************************************************
>> File Name: C_memory.c
>> Author: 陈俊杰
>> Mail: 2716705056qq.com
>> Created Time: 2021年01月21日 星期四 19时45分50秒
>> 此程序的功能是：


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

void getmemory(char *p)
{
    p = (char *)malloc(100);
    strcpy(p, "hello world");
}

int main(int argc, char *argv[])
{
    char *str = NULL;
    getmemory(str);
    printf("%s ", str);
    free(str);
    return 0;
    /*
答案：程序崩溃， getmemory 中的 malloc 不不能返回动态内存， free（）对 str 操作很危险，程序会崩溃，出现段错误这道题目初一看跟我们前面的一道题目非常相像，但是却又截然不同。

在该程序中， getmemory 中 p 是形参，所谓形参在运行中会产生一个临时变量，只会把外界传入的参数的值接收到，所有的改变不会影响外界的实际参数。 getmemory 函数中，因为我们要改变传入的 str 指针的指向，也就是说要改变 str 指针变量的值，应该传入的是指针变量的地址。

因此在函数的形参中不应该写 char *p ，而是应该是 char **p 。getmemory (str) 调用后，传入的是指针变量保存的对象地址，p=(char *) malloc (100) 实际上是把申请的动态内存空间的首地址付给 p 这个临时变量，改变了 p 的指向，对于外界的 str 是没有影响的，因此这个是错误的。

应该修改成指向指针的指针 void getmemory (char **p) ，这样 malloc 返回的地址付给 p（即 str 变量本身）。
    */
}

/*
来看另外的一道题目：

下面函数有什么问题，应该怎么修改
char *strA()
{
char str[] ="hello world";
return str;
}

分析：
因为这个函数返回的是局部变量的地址，当调用这个函数后，这个局部变量 str 就释放了，所以返回的结果是不不确定的且不不安全，随时都有被收回的可能。这个 str 里存在的地址是函数 strA 栈里 “hello world” 的首地址。

函数调用完成，栈帧恢复调用 strA 之前的状态，临时空间被重置，堆栈 “回缩”，strA 栈帧不再属于应该访问的范围。

这段程序可以正确输出结果，但是这种访问方法违背了函数的栈帧机制。但是只要另外一个函数调用的话，你就会发现，这种方式的不合理及危险性。

如果想获得正确的函数，改成下面这样就可以：
char *strA()

{

char * str ="hello world";

return str;

}

首先要搞清楚 char *str 和 char str [] ：

1、

char str[] = "hello world";

是分配一个局部数组。局部数组是局部变量，它所对应的是内存中的栈。局部变量的生命周期结

束后该变量不存在了。

2、
char * str = "hello world";
是指向了了常量区的字符串，位于静态存储区，它在程序生命期内恒定不变，所以字符串还在。

无论什么时候调用 strA，它返回的始终是同一个 “只读” 的内存块。

另外想要修改，也可以这样：通过 static 开辟一段静态存贮空间。

char *strA()
{
static char str[] ="hello world";
return str;
}

*/
