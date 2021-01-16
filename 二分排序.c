/*************************************************************************
>> File Name: InsertionSortDichotomy.c
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.01.19
对于插入排序，如果比较操作的代价比交换操作大的话，可以采用二分查找法来减少比较操作的次数，我们称为二分插入排序，代码如下：


当 n 较大时，二分插入排序的比较次数比直接插入排序的最差情况好得多，但比直接插入排序的最好情况要差，所当以元素初始序列已经接近升序时，直接插入排序比二分插入排序比较次数少。二分插入排序元素移动次数与直接插入排序相同，依赖于元素初始序列。
************************************************************************/

#include <stdio.h>
// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O (n^2)
// 最优时间复杂度 ---- O (nlogn)
// 平均时间复杂度 ---- O (n^2)
// 所需辅助空间 ------ O (1)
// 稳定性 ------------ 稳定
void InsertionSortDichotomy(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int get = A[i];
        int left = 0;
        int right = i - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (A[mid] > get)
                right = mid - 1;
            else
                left = mid + 1;
        }
        for (int j = i - 1; j >= left; j--)
        {
            A[j + 1] = A[j];
        }
        A[left] = get;
    }
}

int main(int argc, char *argv[])
{
    int A[] = {21, 12, 43, 46, 76, 3, 1, 4, 2, 9, 8, 6, 7, 494};
    int n = sizeof(A) / sizeof(int);
    printf("排序前为:\n");
    for (int i = 0; i < n; i++)
        printf("%5d", A[i]);
    printf("\n");
    InsertionSortDichotomy(A, n);
    printf("排序后为:\n");
    for (int i = 0; i < n; i++)
        printf("%5d", A[i]);
    printf("\n");
    return 0;
}
