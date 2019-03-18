/*************************************************************************
>> File Name: MergeSort.c
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.01.20
************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void Merge(int A[], int left, int mid, int right)
{
    int len = right - left + 1;
    int *tmp = (int *)malloc(sizeof(int)*len);
    int index = 0;
    int i = left;
    int j = mid+1;
    while(i <= mid && j <= right)
        tmp[index++] = A[i] <= A[j] ? A[i++] : A[j++];
    while(i<=mid)
        tmp[index++] = A[i++];
    while(j<=right)
        tmp[index++] = A[j++];
    for(int k=0; k<len; k++)
        A[left++] = tmp[k];
}

void MergeSortRecursion(int A[], int left, int right)
{
    if(left == right)
        return;
    int mid = (left+right)/2;
    MergeSortRecursion(A,left,mid);
    MergeSortRecursion(A,mid+1,right);
    Merge(A,left,mid,right);
}

void MergeSortIteration(int A[], int len)
{
    int left, mid, right;
    for(int i=1; i < len; i*=2)
    {
        left = 0;
        while(left+i < len)
        {
            mid = left + i -1;
            right = mid+i < len ? mid+i: len-1;
            Merge(A,left,mid,right);
            left = right+1;
        }
    }

}

int main()

{

    int A1[] = { 6, 5, 3, 1, 8, 7, 2, 4 };      // 从小到大归并排序
    int A2[] = { 6, 5, 3, 1, 8, 7, 2, 4 };
    int n1 = sizeof(A1) / sizeof(int);
    int n2 = sizeof(A2) / sizeof(int);
    MergeSortRecursion(A1, 0, n1 - 1);          // 递归实现
    MergeSortIteration(A2, n2);                 // 非递归实现
    printf("排序前：");
    for (int i = 0; i < n1; i++)
    {
        printf("%d ", A1[i]);
    }
    printf("\n");

    printf("递归实现的归并排序结果：");
    for (int i = 0; i < n1; i++)
    {
        printf("%d ", A1[i]);
    }
    printf("\n");
    printf("非递归实现的归并排序结果：");
    for (int i = 0; i < n2; i++)
    {
        printf("%d ", A2[i]);
    }
    printf("\n");
    return 0;

}
