/*************************************************************************
>> File Name: C_string.c
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.25
************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[])
{
    char S1[20] = "hello world";
    char S2[20] = {'h','e','l','l','o',' ','w','o','r','l','d','\0'};
    char S3[] = "hello\0 world";
    char S4[] = {'h','e','l','l','o','\0',' ','w','o','r','l','d','\0'};
    char *S5 = "hello world";
    printf("strlen(S1) = %zd , strlen(S2) = %zd , strlen(S3) = %zd , strlen(S4) = %zd , strlen(S5) = %zd\n",
            strlen(S1),strlen(S2),strlen(S3),strlen(S4),strlen(S5));

    printf("sizeof(S1) = %zd , sizeof(S2) = %zd , sizeof(S3) = %zd , sizeof(S4) = %zd , sizeof(S5) = %zd\n",
            sizeof(S1),sizeof(S2),sizeof(S3),sizeof(S4),sizeof(S5));
    return 0;
}
/*
输出为：

strlen(S1) = 11 , strlen(S2) = 11 , strlen(S3) = 5 , strlen(S4) = 5 , strlen(S5) = 11
sizeof(S1) = 20 , sizeof(S2) = 20 , sizeof(S3) = 13 , sizeof(S4) = 13 , sizeof(S5) = 8
 */
