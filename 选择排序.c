/*************************************************************************
>> File Name: SelectionSort.c
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.01.19
************************************************************************/

#include<stdio.h>
void Swap(int A[], int i, int j)
{
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

void SelectionSort(int A[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        int min =i;
        for(int j = i; j < n; j++)
        {
            if(A[j] < A[min])
                min = j;
        }
        if(min != i)
            Swap(A,i,min);
    }
}

int main(int argc,char *argv[])
{
    int A[] = {111,3,4,7,2,9,10,1,43,52,12,46};
    int n = sizeof(A)/sizeof(int);
    printf("排序前数组A为:\n");
    for(int i = 0; i < n; i++)
        printf("%5d",*(A+i));
        //printf("%5d",A[i]);
        //这两句等价

    printf("\n");
    SelectionSort(A,n);
    printf("排序后数组为:\n");
    for(int i = 0; i < n; i++)
        printf("%5d",A[i]);
    printf("\n");
    return 0;
}
