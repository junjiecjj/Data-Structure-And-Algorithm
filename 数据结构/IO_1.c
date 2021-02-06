/*************************************************************************
>> File Name: test.c
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.01.22
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int L, W, Z;
    int i = 0;
    int ch;
    scanf("%d %d", &L, &W);
    Z = (L > W ? L : W);
    printf("L = %d, W = %d", L, W);
    int *A = (int *)malloc(4 * Z * sizeof(int));
    while ((ch = getchar()) != '#')
        putchar(ch);
    if (getchar() == '\n')
        printf("读取了一个回车\n");
    while ((ch = getchar()) != '#')
    {
        putchar(ch);
        printf("进入成功\n");
        while (scanf("%d", A + i) == 1)
        {
            printf("成功读取一个整数\n");
            i++;
        }
        while ((ch = getchar()) != '\n')
        {
            putchar(ch);
            printf("跳过了\n");
            continue;
        }
    }
    for (int j = 0; j < 4 * Z; j++)
        printf("%d  ", A[j]);
    printf("\n");
    printf("i = %d\n", i);
    return 0;
}

/*
int main(int argc,char *argv[])
{
    int L,W,Z;
    char ch[20];
    char *pch = ch;
    printf("sizeof ch = %zd\n",sizeof(ch));
    printf("strlen ch = %zd\n",strlen(ch));

    printf("sizeof pch = %zd\n",sizeof(pch));
    printf("strlen pch = %zd\n",strlen(pch));

    scanf("%d %d",&L,&W);
    scanf("%s",ch);
    printf("L = %d, W = %d\n",L,W);
    printf("%s\n",ch);

    printf("sizeof ch = %zd\n",sizeof(ch));
    printf("strlen ch = %zd\n",strlen(ch));

    printf("sizeof pch = %zd\n",sizeof(pch));
    printf("strlen pch = %zd\n",strlen(pch));

    printf("sizeof 'jack' = %zd\n",sizeof("jack"));
    printf("strlen 'jack' = %zd\n",strlen("jack"));

    return 0;
}
*/
