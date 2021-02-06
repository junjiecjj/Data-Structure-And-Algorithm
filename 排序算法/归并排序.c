/*************************************************************************
>> File Name: MergeSort.c
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.01.20

归并排序是创建在归并操作上的一种有效的排序算法，效率为 O (nlogn)，1945 年由冯・诺伊曼首次提出。

归并排序的实现分为递归实现与非递归 (迭代) 实现。递归实现的归并排序是算法设计中分治策略的典型应用，我们将一个大问题分割成小问题分别解决，然后用所有小问题的答案来解决整个大问题。非递归 (迭代) 实现的归并排序首先进行是两两归并，然后四四归并，然后是八八归并，一直下去直到归并了整个数组。

归并排序算法主要依赖归并 (Merge) 操作。归并操作指的是将两个已经排序的序列合并成一个序列的操作，归并操作步骤如下：

申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列

设定两个指针，最初位置分别为两个已经排序序列的起始位置

比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置

重复步骤 3 直到某一指针到达序列尾

将另一序列剩下的所有元素直接复制到合并序列尾



归并排序的代码如下：


************************************************************************/
// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O (nlogn)
// 最优时间复杂度 ---- O (nlogn)
// 平均时间复杂度 ---- O (nlogn)
// 所需辅助空间 ------ O (n)
// 稳定性 ------------ 稳定
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void Merge(int A[], int left, int mid, int right)
{
    int len = right - left + 1;
    int *tmp = (int *)malloc(sizeof(int) * len);
    int index = 0;
    int i = left;
    int j = mid + 1;
    while (i <= mid && j <= right)
        tmp[index++] = A[i] <= A[j] ? A[i++] : A[j++];
    while (i <= mid)
        tmp[index++] = A[i++];
    while (j <= right)
        tmp[index++] = A[j++];
    for (int k = 0; k < len; k++)
        A[left++] = tmp[k];
}

void MergeSortRecursion(int A[], int left, int right)
{
    if (left == right)
        return;
    int mid = (left + right) / 2;
    MergeSortRecursion(A, left, mid);
    MergeSortRecursion(A, mid + 1, right);
    Merge(A, left, mid, right);
}

void MergeSortIteration(int A[], int len)
{
    int left, mid, right;
    for (int i = 1; i < len; i *= 2)
    {
        left = 0;
        while (left + i < len)
        {
            mid = left + i - 1;
            right = mid + i < len ? mid + i : len - 1;
            Merge(A, left, mid, right);
            left = right + 1;
        }
    }
}

int main()

{

    int A1[] = {6, 5, 3, 1, 8, 7, 2, 4}; // 从小到大归并排序
    int A2[] = {6, 5, 3, 1, 8, 7, 2, 4};
    int n1 = sizeof(A1) / sizeof(int);
    int n2 = sizeof(A2) / sizeof(int);
    MergeSortRecursion(A1, 0, n1 - 1); // 递归实现
    MergeSortIteration(A2, n2);        // 非递归实现
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
