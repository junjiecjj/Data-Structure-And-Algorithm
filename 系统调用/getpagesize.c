/*************************************************************************
>> File Name: getpagesize.c
>> Author: 陈俊杰
>> Mail: 2716705056qq.com
>> Created Time: 2021年02月28日 星期日 20时11分52秒
>> 此程序的功能是：
************************************************************************/

#include<stdio.h>
#include<unistd.h>


int main(int argc, char *argv[])
{
    printf("page size = %d\n",getpagesize());
    return 0;
}
