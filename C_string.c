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
    char S3[20] = {'h','e','l','l','o','\0','w','o','r','l','d','\0'};
    char S4[20] = {'h','e','l','l','o',' ','w','o','r','l','d'};
    char S5[] = "hello\0 world";
    char S6[] = {'h','e','l','l','o','\0',' ','w','o','r','l','d','\0'};
    char S7[] = {'h','e','l','l','o',' ','w','o','r','l','d','\0'};
    char S8[] = {'h','e','l','l','o',' ','w','o','r','l','d'};//strlen(S10)产生未定义的结果，因为S10不是以'\0'结尾，strlen可能一直向前查找直到遇到空字符

    char *S9 = "hello world";
    printf("strlen(S1) = %zd , strlen(S2) = %zd , strlen(S3) = %zd , strlen(S4) = %zd , strlen(S5) = %zd , strlen(S6) = %zd , strlen(S7) = %zd , strlen(S8) = %zd , strlen(S9) = %zd\n",
            strlen(S1),strlen(S2),strlen(S3),strlen(S4),strlen(S5),strlen(S6),strlen(S7),strlen(S8),strlen(S9));

    printf("sizeof(S1) = %zd , sizeof(S2) = %zd , sizeof(S3) = %zd , sizeof(S4) = %zd , sizeof(S5) = %zd ,sizeof(S6) = %zd , sizeof(S7) = %zd , sizeof(S8) = %zd ,sizeof(S9) = %zd\n",
            sizeof(S1),sizeof(S2),sizeof(S3),sizeof(S4),sizeof(S5),sizeof(S6),sizeof(S7),sizeof(S8),sizeof(S9));
    return 0;

    //  strlen()只能以char *作为参数,不能以类型作为参数,该函数实际完成的功能是从代表该字符串的第一个地址开始遍历，直到遇到结束符'\0'。返回的长度大小不包括'\0'。
    //  c/c++ strlen(str)和str.length()和str.size()都可以求字符串长度。
    //  其中str.length()和str.size()是用于求string类对象长度的成员函数
    //  strlen(str)是用于求字符数组的长度，其参数是char*
}
/*
输出为：

strlen(S1) = 11 , strlen(S2) = 11 , strlen(S3) = 5 , strlen(S4) = 11 , strlen(S5) = 5 , strlen(S6) = 5 , strlen(S7) = 11 , strlen(S8) = 22 , strlen(S9) = 11
sizeof(S1) = 20 , sizeof(S2) = 20 , sizeof(S3) = 20 , sizeof(S4) = 20 , sizeof(S5) = 13 ,sizeof(S6) = 13 , sizeof(S7) = 12 , sizeof(S8) = 11 ,sizeof(S9) = 8


 */
