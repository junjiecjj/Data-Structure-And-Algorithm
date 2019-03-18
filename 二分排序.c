/*************************************************************************
>> File Name: InsertionSortDichotomy.c
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.01.19
************************************************************************/

#include<stdio.h>

void InsertionSortDichotomy(int A[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int get = A[i];
        int left = 0;
        int right = i-1;
        while(left<=right)
        {
            int mid = (left + right)/2;
            if(A[mid] >  get)
                right = mid-1;
            else
                left = mid + 1;
        }
        for(int j = i-1; j >= left; j--)
        {
            A[j+1] = A[j];
        }
        A[left] = get;

    }
}

int main(int argc, char *argv[])
{
    int A[] = {21,12,43,46,76,3,1,4,2,9,8,6,7,494};
    int n = sizeof(A)/sizeof(int);
    printf("排序前为:\n");
    for(int i = 0; i < n; i++)
        printf("%5d",A[i]);
    printf("\n");
    InsertionSortDichotomy(A,n);
    printf("排序后为:\n");
    for(int i = 0; i < n; i++)
        printf("%5d",A[i]);
    printf("\n");
    return 0;
}
