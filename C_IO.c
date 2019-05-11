/*************************************************************************
>> File Name: C_IO.c
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.05.10

C语言中常用的几个输入输出函数的用法:
读取函数:
getchar(),putchar(),printf(),scanf()都是标准I/O包的成员,处理stdin和stdout这两个流.
scanf()函数返回成功读取的项数,如果读取失败,返回0,当scanf()检测到"文件结尾"时,返回EOF(EOF是stdio.h中的特殊值,通常用#define指令将EOF定义为-1)
getchar()函数读取文件检测到文件结尾时返回EOF.
gets(char *)和fgets(char *, size_t n, FILE *)读到文件结尾时都会返回空指针.
getc(FILE *)在读取一个文件时如果读到文件结尾,则返回EOF.
fscanf(FILE *, "%s", char *)在读取一个文件时如果读到文件结尾,则返回EOF.

************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define LEN 40

void showArray( int m, int n,int (*A)[n])
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%5d  ",A[i][j]);
        }
        printf("\n");
    }
}

void showArray(int m, int n, int (*A)[n]);

int main(int argc, char *argv[])
{
    FILE  *in, *out;
    int ch;
    printf("**********************************************\n");
    //读取.txt文件并显示在屏幕
    in = fopen("./In.txt","r");
    while((ch = getc(in)) != EOF)
    {
        putchar(ch);
    }

    fclose(in);

    printf("**********************************************\n");
    //用getc和putc先读取文件,再输出到另外的文件
    in = fopen("./In.txt","r");
    out = fopen("./out1.txt", "w");
    while((ch = getc(in)) != EOF)
    {
        putc(ch, out);
    }

    fclose(in);
    fclose(out);

    printf("**********************************************\n");
    //用fgets和fputs读取并写入文件
    char *cr = (char *)malloc(sizeof(char) * LEN);
    in = fopen("./In.txt","r");
    out = fopen("./out2.txt", "w");
    while(fgets(cr, LEN, in) != NULL)
    {
        fputs(cr, out);
    }

    fclose(in);
    fclose(out);

    printf("**********************************************\n");
    //从stdin读取文本并写入文件
    out = fopen("./out3.txt","w");
    while((ch = getchar()) != EOF)
    {
        putc(ch, out);
    }

    fclose(out);

    printf("**********************************************\n");
    //将数组写入.txt文件
    int m = 5, n =10;
    int A[m][n] ;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            A[i][j] = i*n+j;

    printf("打印数组\n");
    showArray(m,n,A);

    //重新读取这个数组
    out = fopen("./out4.txt","w");
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            fprintf(out, "%d  ",A[i][j]);//这里加两个空格,不然out4.txt各个数字之间每空格,无法阅读
        }
        putc('\n', out);
    }
    fclose(out);


    in = fopen("./out4.txt","r");
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            fscanf(in, "%d",&A[i][j]);
        }
    }
    fclose(in);
    showArray(m,n, A);
    printf("\n**********************************************\n");

    //从array.txt读取数组

    int B[4][6] = {0};
    printf("打印读取前的数组\n");
    showArray(4,6,B);
    in = fopen("./array.txt","r");
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            fscanf(in, "%d",&B[i][j]);
        }
    }
    fclose(in);
    printf("打印读取后的数组\n");
    showArray(4,6,B);

    printf("\n**********************************************\n");

    return 0;
}
