/*************************************************************************
>> File Name: C_string.c
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.25

const char * pt1 = "Something is pointing at me.";
该声明和下面的声明几乎相同：
const char ar1[] = "Something is pointing at me.";
以上两个声明表明，pt1和ar1都是该字符串的地址。在这两种情况下，带双引号的字符串本身决定了预留给字符串的存储空间。尽管如此，这两种形式并不完全相同。
数组和指针
数组形式和指针形式有何不同？以上面的声明为例，数组形式（ar1[]）在计算机的内存中分配为一个内含29个元素的数组（每个元素对应一个字符，还加上一个末尾的空字符'\0'），每个元素被初始化为字符串字面量对应的字符。通常，字符串都作为可执行文件的一部分存储在数据段中。当把程序载入内存时，也载入了程序中的字符串。字符串存储在静态存储区（static memory）中。但是，程序在开始运行时才会为该数组分配内存。此时，才将字符串拷贝到数组中（第12章将详细讲解）。注意，此时字符串有两个副本。一个是在静态内存中的字符串字面量，另一个是存储在ar1数组中的字符串。
此后，编译器便把数组名ar1识别为该数组首元素地址（&ar1[0]）的别名。这里关键要理解，在数组形式中，ar1是地址常量。不能更改ar1，如果改变了ar1，则意味着改变了数组的存储位置（即地址）。可以进行类似ar1+1这样的操作，标识数组的下一个元素。但是不允许进行++ar1这样的操作。递增运算符只能用于变量名前（或概括地说，只能用于可修改的左值），不能用于常量。
指针形式（*pt1）也使得编译器为字符串在静态存储区预留29个元素的空间。另外，一旦开始执行程序，它会为指针变量pt1留出一个存储位置，并把字符串的地址存储在指针变量中。该变量最初指向该字符串的首字符，但是它的值可以改变。因此，可以使用递增运算符。例如，++pt1将指向第2个字符（o）。
字符串字面量被视为const数据。由于pt1指向这个const数据，所以应该把pt1声明为指向const数据的指针。这意味着不能用pt1改变它所指向的数据，但是仍然可以改变pt1的值（即，pt1指向的位置）。如果把一个字符串字面量拷贝给一个数组，就可以随意改变数据，除非把数组声明为const。
总之，初始化数组把静态存储区的字符串拷贝到数组中，而初始化指针只把字符串的地址拷贝给指针。
总之，如果打算修改字符串，就不要用指针指向字符串字面量。

初始化字符串的方式：
char S[91];
char S[]="hello,jack!!!";
char *p = (char *)malloc(sizeof(char)*Len);

************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
       char S1[20] = "hello world";
       char S2[20] = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '\0'};
       char S3[20] = {'h', 'e', 'l', 'l', 'o', '\0', 'w', 'o', 'r', 'l', 'd', '\0'};
       char S4[20] = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
       char S5[] = "hello\0world";
       char S6[] = {'h', 'e', 'l', 'l', 'o', '\0', ' ', 'w', 'o', 'r', 'l', 'd', '\0'};
       char S7[] = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '\0'};
       char S8[] = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'}; //strlen(S8)产生未定义的结果，因为S8不是以'\0'结尾，strlen可能一直向前查找直到遇到空字符

       char *S9 = "hello world";
       printf("strlen(S1) = %zd , strlen(S2) = %zd , strlen(S3) = %zd , strlen(S4) = %zd , strlen(S5) = %zd , strlen(S6) = %zd , strlen(S7) = %zd , strlen(S8) = %zd , strlen(S9) = %zd\n",
              strlen(S1), strlen(S2), strlen(S3), strlen(S4), strlen(S5), strlen(S6), strlen(S7), strlen(S8), strlen(S9));

       printf("sizeof(S1) = %zd , sizeof(S2) = %zd , sizeof(S3) = %zd , sizeof(S4) = %zd , sizeof(S5) = %zd ,sizeof(S6) = %zd , sizeof(S7) = %zd , sizeof(S8) = %zd ,sizeof(S9) = %zd\n",
              sizeof(S1), sizeof(S2), sizeof(S3), sizeof(S4), sizeof(S5), sizeof(S6), sizeof(S7), sizeof(S8), sizeof(S9));
       return 0;

       //  strlen()只能以char *作为参数,不能以类型作为参数,该函数实际完成的功能是从代表该字符串的第一个地址开始遍历，直到遇到结束符'\0'。返回的长度大小不包括'\0'。
       //  c/c++ strlen(str)和str.length()和str.size()都可以求字符串长度。
       //  其中str.length()和str.size()是用于求string类对象长度的成员函数
       //  strlen(str)是用于求字符数组的长度，其参数是char*
}
/*
输出为：

strlen(S1) = 11 , strlen(S2) = 11 , strlen(S3) = 5 , strlen(S4) = 11 , strlen(S5) = 5 , strlen(S6) = 5 ,
strlen(S7) = 11 , strlen(S8) = 22 , strlen(S9) = 11

sizeof(S1) = 20 , sizeof(S2) = 20 , sizeof(S3) = 20 , sizeof(S4) = 20 , sizeof(S5) = 12 ,sizeof(S6) = 13 ,
sizeof(S7) = 12 , sizeof(S8) = 11 ,sizeof(S9) = 8
sizeof(S9)是求字符指针的字节数，为8个字节


 */
