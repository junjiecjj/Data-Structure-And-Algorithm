/**********************************************************************
>> File Name: bubble_sort.c
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.01.19
************************************************************************/

#include<stdio.h>
//void Swap(int A[], int i,int j)
void Swap(int *A, int i, int j)
{
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

//void BubbleSort(int *A, int n)
void BubbleSort(int A[], int n)
{
    for(int j =0; j < n-1; j++)
    {
        for(int i =0; i < n-1-j; i++)
        {
            if(A[i]>A[i+1])
                Swap(A,i,i+1);
        }
    }
}

void swap1(int i,int j)
{
    int tmp = i;
    i = j;
    j = tmp;
}

void swap2(int *i, int *j)
{
    int tmp = *i;
    *i = *j;
    *j = tmp;
}
int main()
{
    int A[] = {111,2,1,6,4,3,7,5,9,10,19,34};
    int a = 212, b = 4324;
    printf("交换前:\n");
    printf("a = %d,b = %d.\n",a,b);
    printf("\n");

    swap1(a,b);
    printf("swap1交换后:\n");
    printf("a = %d,b = %d.\n",a,b);
    printf("\n");

    printf("swap2交换后:\n");
    swap2(&a,&b);
    printf("a = %d,b = %d.\n",a,b);
    printf("\n");

    int n = sizeof(A)/sizeof(int);
    printf("排序前数组A为:\n");
    for(int i = 0; i < n; i++)
        printf("%5d",*(A+i));
        //printf("%5d",A[i]);
        //这两句等价

    printf("\n");
    BubbleSort(A,n);
    printf("排序后数组为:\n");
    for(int i = 0; i < n; i++)
        printf("%5d",A[i]);
    printf("\n");
    return 0;
}

