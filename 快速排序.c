/*************************************************************************
>> File Name: QuickSort.c
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.01.20
************************************************************************/
#include<stdio.h>

void Swap(int A[], int i, int j)
{
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

int Partion(int A[], int left, int right)
//实际上是单边排序，把左边大于pivot的值置换到右边去
{
    int pivot = A[right];
    int tail = left - 1;
    for(int i = left; i < right; i++)
    {
        if(A[i] <= pivot)
            Swap(A,++tail, i);
    }

    Swap(A, tail+1, right);
    return tail+1;
}

void QuickSort(int A[],int left, int right)
{
    if(left >= right)
        return;
    int pivot_index = Partion(A, left, right);
    QuickSort(A,left, pivot_index-1);
    QuickSort(A,pivot_index+1, right);
}

int main(int argc, char *argv[])
{
    int A[] = {111,2,1,6,4,3,7,5,9,10,19,34};
    int n = sizeof(A)/sizeof(int);

    printf("排序前数组A为:\n");
    for(int i = 0; i < n; i++)
        printf("%5d",*(A+i));
        //printf("%5d",A[i]);
        //这两句等价

    printf("\n");
    QuickSort(A, 0, n-1);
    printf("排序后数组为:\n");
    for(int i = 0; i < n; i++)
        printf("%5d",A[i]);
    printf("\n");
    return 0;
}
