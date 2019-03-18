/*************************************************************************
>> File Name: IO_1.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.14
************************************************************************/
/*
  此IO_1,IO_2等系列的代码是为了解决笔试过程中需要与用户交互式输入输出的
  程序的设计。
  而此代码解决的是这样的一个输入的问题:
  此代码需要用户输入,输入的形式如下，有两行输入，
  第一行是两个整数m,n，第二行是个数最大为4*max(m,n)的一行整数,但是具体数量不定
  如：2 3
      1 2 3 4 5 5 6 7
  或12 23
    21 32 100 199 10000 1324 74387
  等，此类问题不难，但是很容易因为回车符而出错，所以写了这系列的代码解决
  这类问题
*/


#include<iostream>
using namespace std;
#include<cstdlib>
#include<cstdio>
#include<new>
#include<string>

int main()
{
    int L,W;
    char ch;
    int count = 0;
    cin >> L >> W;
    int Z = (L >W ? L : W);
    printf("L = %d, W = %d, Z = %d\n",L,W,Z);
    int *A = (int *)malloc(4*Z*sizeof(int));
    int *B = new int[4*Z];

    while(cin >> *(B+count))
    {
        ++count; 
        if(getchar() == '\n')
            break;
    }
    cout << "count = " << count << endl;
    for(int i =0; i < count; i++)
        cout << B[i] << " ";
    cout << endl;
    return 0;
}
