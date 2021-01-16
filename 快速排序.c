/*************************************************************************
>> File Name: QuickSort.c
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.01.20

快速排序是由东尼・霍尔所发展的一种排序算法。在平均状况下，排序 n 个元素要 O (nlogn) 次比较。在最坏状况下则需要 O (n^2) 次比较，但这种状况并不常见。事实上，快速排序通常明显比其他 O (nlogn) 算法更快，因为它的内部循环可以在大部分的架构上很有效率地被实现出来。

快速排序使用分治策略 (Divide and Conquer) 来把一个序列分为两个子序列。步骤为：

从序列中挑出一个元素，作为” 基准”(pivot).

把所有比基准值小的元素放在基准前面，所有比基准值大的元素放在基准的后面（相同的数可以到任一边），这个称为分区 (partition) 操作。

对每个分区递归地进行步骤 1~2，递归的结束条件是序列的大小是 0 或 1，这时整体已经被排好序了。

快速排序的代码如下：

快速排序是不稳定的排序算法，不稳定发生在基准元素与 A [tail+1] 交换的时刻。

比如序列：{1, 3, 4, 2, 8, 9, 8, 7, 5}，基准元素是 5，一次划分操作后 5 要和第一个 8 进行交换，从而改变了两个元素 8 的相对次序。

Java 系统提供的 Arrays.sort 函数。对于基础类型，底层使用快速排序。对于非基础类型，底层使用归并排序。请问是为什么？

答：这是考虑到排序算法的稳定性。对于基础类型，相同值是无差别的，排序前后相同值的相对位置并不重要，所以选择更为高效的快速排序，尽管它是不稳定的排序算法；而对于非基础类型，排序前后相等实例的相对位置不宜改变，所以选择稳定的归并排序。
************************************************************************/
//这是快速排序算法https://mp.weixin.qq.com/s/ruVOK3iwyPuDjxSTs7JFvA
#include <stdio.h>
// 分类 ------------ 内部比较排序
// 数据结构 --------- 数组
// 最差时间复杂度 ---- 每次选取的基准都是最大（或最小）的元素，导致每次只划分出了一个分区，需要进行 n-1 次划分才能结束递归，时间复杂度为 O (n^2)
// 最优时间复杂度 ---- 每次选取的基准都是中位数，这样每次都均匀的划分出两个分区，只需要 logn 次划分就能结束递归，时间复杂度为 O (nlogn)
// 平均时间复杂度 ---- O (nlogn)
// 所需辅助空间 ------ 主要是递归造成的栈空间的使用 (用来保存 left 和 right 等局部变量)，取决于递归树的深度，一般为 O (logn)，最差为 O (n)
// 稳定性 ---------- 不稳定
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
    for (int i = left; i < right; i++)
    {
        if (A[i] <= pivot)
            Swap(A, ++tail, i);
    }

    Swap(A, tail + 1, right);
    return tail + 1;
}

void QuickSort(int A[], int left, int right)
{
    if (left >= right)
        return;
    int pivot_index = Partion(A, left, right);
    QuickSort(A, left, pivot_index - 1);
    QuickSort(A, pivot_index + 1, right);
}

int main(int argc, char *argv[])
{
    int A[] = {111, 2, 1, 6, 4, 3, 7, 5, 9, 10, 19, 34};
    int n = sizeof(A) / sizeof(int);

    printf("排序前数组A为:\n");
    for (int i = 0; i < n; i++)
        printf("%5d", *(A + i));
    //printf("%5d",A[i]);
    //这两句等价

    printf("\n");
    QuickSort(A, 0, n - 1);
    printf("排序后数组为:\n");
    for (int i = 0; i < n; i++)
        printf("%5d", A[i]);
    printf("\n");
    return 0;
}
