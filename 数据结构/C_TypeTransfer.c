/*************************************************************************
>> File Name: C_TypeTransfer.c
>> Author: 陈俊杰
>> Mail: 2716705056qq.com
 
>> Created Time: 2021/5/29 22:26:54

>> 此程序的功能是：
************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<float.h>
#include<limits.h>
#include<math.h>
#include<string.h>
#include<stddef.h>
#include<locale.h>
#include<time.h>
#include<complex.h>


int main(int argc, char *argv[])
{
    printf("*************************隐式自动类型转换***************************\n");
    char ch;
    int i;
    float fl;
    fl = i = ch = 'C';
    printf("ch = %c, i = %d, fl = %2.2f\n",ch, i, fl);

    ch = ch + 1;
    i = fl + 2*ch;
    fl = 2.0*ch + i;
    printf("ch = %c, i = %d, fl = %2.2f\n",ch, i, fl);

    ch = 1107;
    printf("Now ch = %c\n",ch);
    ch = 80.89;
    printf("Now ch = %c\n",ch);

    printf("***************************强制类型转换**********************************\n");




    return 0;
}
