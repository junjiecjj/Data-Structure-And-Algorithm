/*************************************************************************
>> File Name: test.c
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.01.22
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int L, W, Z;
    int count = 0;
    int ch;
    scanf("%d %d", &L, &W);
    Z = (L > W ? L : W);
    //printf("L = %d, W = %d\n",L,W);
    int *A = (int *)malloc(4 * Z * sizeof(int));
    while ((ch = getchar()) != '\n') //这两行可有可无
    {
        putchar(ch);
        //continue;
        //if(getchar() == '\n')
        //   printf("读取了一个回车\n");
    }

    while (scanf("%d", A + count) == 1 && count < 4 * Z)
    {
        printf("成功读取一个整数\n");
        count++;
        //if(count >= 4*Z)
        //    break;
        if (getchar() == '\n')
            break;
    }

    //while((ch = getchar()) != '\n')
    //{
    //    putchar(ch);
    //    printf("跳过了\n");
    //    continue;
    //}
    printf("count = %d\n", count);
    for (int j = 0; j < 4 * Z; j++)
        printf("%d  ", A[j]);
    printf("\n");

    return 0;
}
