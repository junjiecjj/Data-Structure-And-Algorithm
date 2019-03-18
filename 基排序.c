/*************************************************************************
>> File Name: 基数排序.c
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.01.21
************************************************************************/

#include<stdio.h>
#include<stdlib.h>

const int dn = 3;
const int k = 10;

int GetDigit(int x, int d)
{
    int radix[] = {1,1,10,100};
    return (x/radix[d])%10;
}

void CountingSort(int A[], int n, int d)
{
    int C[k];
    for(int i = 0; i < k; i++)
        C[i] = 0;

    for(int i = 0; i < n; i++)
        C[GetDigit(A[i],d)]++;

    for(int i = 1; i < k; i++)
        C[i] = C[i] + C[i-1];

    int *B = (int *)malloc(n * sizeof(int));
    for(int i = n-1; i >= 0; i--)
    {
        int dight = GetDigit(A[i],d);
        B[--C[dight]] = A[i];
    }
    for(int i = 0; i < n; i++)
        A[i] = B[i];
    free(B);
}

void LsdRadixSort(int A[], int n)
{
    for(int d = 1; d <= dn; d++)
        CountingSort(A, n, d);
}

int main()
{
    int A[] = { 20, 90, 64, 289, 998, 365, 852, 123, 789, 456 };// 针对基数排序设计的输入
    int n = sizeof(A) / sizeof(int);
    printf("排序前:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    LsdRadixSort(A, n);
    printf("基数排序结果：");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;

}
