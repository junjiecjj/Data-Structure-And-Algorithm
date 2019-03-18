/*************************************************************************
>> File Name: HeapSort.c
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

void Heapify(int A[], int i, int size)
{
    int left_child = 2*i+1;
    int right_chile = 2*i+2;
    int max = i;
    if(left_child < size && A[left_child] > A[max])
        max = left_child;
    if(right_chile < size && A[right_chile] > A[max])
        max = right_chile;
    if(max != i)
    {
        Swap(A, i, max);
        Heapify(A, max, size);
    }
}

int BuildHeap(int A[], int n)
{
    int heap_size = n;
    for(int i = heap_size/2-1; i >= 0; i--)
        Heapify(A, i, heap_size);
    return heap_size;
}

void HeapSort(int A[], int n)
{
    int heap_size = BuildHeap(A, n);
    while(heap_size>1)
    {
        Swap(A, 0, --heap_size);
        Heapify(A, 0, heap_size);
    }
}

int main(int argc,char *argv[])
{
    int A[] = {111,2,1,6,4,3,7,5,9,10,19,34};
    int n = sizeof(A)/sizeof(int);
    printf("排序前数组A为:\n");
    for(int i = 0; i < n; i++)
        printf("%5d",*(A+i));
        //printf("%5d",A[i]);
        //这两句等价

    printf("\n");
    HeapSort(A,n);
    printf("排序后数组为:\n");
    for(int i = 0; i < n; i++)
        printf("%5d",A[i]);
    printf("\n");
    return 0;

}
