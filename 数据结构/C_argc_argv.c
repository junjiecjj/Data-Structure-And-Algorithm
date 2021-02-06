/*************************************************************************
>> File Name: C_argc_argv.c
>> Author: 陈俊杰
>> Mail: 2716705056qq.com
 
>> Created Time: 2021年02月06日 星期六 19时22分05秒
>> Last Modified : 2021年02月06日 星期六 19时22分49秒
>> 此程序的功能是：
************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<float.h>
#include<limits.h>
#include<math.h>
#include<string.h>
#include<sys/socket.h>
#include<stddef.h>
#include<locale.h>
#include<time.h>
#include<complex.h>


int main(int argc, char *argv[])
{
    int a = atoi(argv[1]);
    printf("%d\n",a);
    printf("***************分割线********************");
    for (int i = 0; i < argc; ++i)
    {
        printf("%s\n",argv[i]);
    }
    return 0;
}
