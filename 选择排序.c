/*************************************************************************
>> File Name: SelectionSort.c
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.01.19
选择排序也是一种简单直观的排序算法。它的工作原理很容易理解：初始时在序列中找到最小（大）元素，放到序列的起始位置作为已排序序列；然后，再从剩余未排序元素中继续寻找最小（大）元素，放到已排序序列的末尾。以此类推，直到所有元素均排序完毕。

注意选择排序与冒泡排序的区别：冒泡排序通过依次交换相邻两个顺序不合法的元素位置，从而将当前最小（大）元素放到合适的位置；而选择排序每遍历一次都记住了当前最小（大）元素的位置，最后仅需一次交换操作即可将其放到合适的位置。

选择排序的代码如下：
// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O (n^2)
// 最优时间复杂度 ---- O (n^2)
// 平均时间复杂度 ---- O (n^2)
// 所需辅助空间 ------ O (1)
// 稳定性 ------------ 不稳定
************************************************************************/

#include <stdio.h>
void Swap(int A[], int i, int j)
{
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

void SelectionSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i; j < n; j++)
        {
            if (A[j] < A[min])
                min = j;
        }
        if (min != i)
            Swap(A, i, min);
    }
}

int main(int argc, char *argv[])
{
    int A[] = {111, 3, 4, 7, 2, 9, 10, 1, 43, 52, 12, 46};
    int n = sizeof(A) / sizeof(int);
    printf("排序前数组A为:\n");
    for (int i = 0; i < n; i++)
        printf("%5d", *(A + i));
    //printf("%5d",A[i]);
    //这两句等价

    printf("\n");
    SelectionSort(A, n);
    printf("排序后数组为:\n");
    for (int i = 0; i < n; i++)
        printf("%5d", A[i]);
    printf("\n");
    return 0;
}
