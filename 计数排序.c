/*************************************************************************
>> File Name: 计数排序.c
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.01.21
************************************************************************/

#include<stdio.h>
#include<stdlib.h>

const int K = 100;

void CountingSort(int A[], int n)
{
    int *C = (int *)malloc(K * sizeof(int));
    for(int i = 0; i < K; i++)
        C[i] = 0;

    for(int i = 0; i < n; i++)
        C[A[i]]++;

    for(int i = 1; i < K; i++)
        C[i] = C[i] + C[i-1];

    int *B = (int *)malloc(n*sizeof(int));

    for(int i = n-1; i >= 0; i--)
        B[--C[A[i]]] = A[i];

    for(int i = 0; i < n; i++)
        A[i] = B[i];

    free(B);
}

int main(int argc,char *argv[])
{
    int A[] = { 15, 22, 19, 46, 27, 73, 1, 19, 8 };  // 针对计数排序设计的输入，每一个元素都在[0,100]上且有重复元素
    int n = sizeof(A) / sizeof(int);
    CountingSort(A, n);
    printf("计数排序结果：");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
