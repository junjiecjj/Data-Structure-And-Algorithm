/*************************************************************************
>> File Name: InsertionSort.c
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.01.19
************************************************************************/

#include<stdio.h>
void InsertionSort(int A[],int n)
{
    for(int i=1; i < n; i++)
    {
        int get = A[i];
        int j = i-1;
        while(j >= 0 && A[j] > get)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = get;
    }
}

int main(int argc,char * argv[])
{
    int A[] = {21,12,43,46,76,3,1,4,2,9,8,6,7,494};
    int n = sizeof(A)/sizeof(int);
    printf("排序前为:\n");
    for(int i = 0; i < n; i++)
        printf("%5d",A[i]);
    printf("\n");
    InsertionSort(A,n);
    printf("排序后为:\n");
    for(int i = 0; i < n; i++)
        printf("%5d",A[i]);
    printf("\n");
    return 0;
}
