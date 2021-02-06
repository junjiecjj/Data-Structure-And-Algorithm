/*************************************************************************
    >> File Name: HeapSort.c
    >> Author: chenjunjie
    >> Mail: 2716705056qq.com
    >> Created Time: 2019.01.20

    https://mp.weixin.qq.com/s?__biz=MzAxODI5ODMwOA==&mid=2666542297&idx=1&sn=4a7d873c5e67d94daf397ece24acfe2a&chksm=80dcf072b7ab796450f3cb0b13703fd872a0c65bcdfa0427babeb97e81c7f67dfb7e46f8d189&mpshare=1&scene=1&srcid=0527Udc3QQbqdbMdv0gWUs3Q&sharer_sharetime=1610613806850&sharer_shareid=0d5c82ce3c8b7c8f30cc9a686416d4a8#rd

    堆排序是指利用堆这种数据结构所设计的一种选择排序算法。堆是一种近似完全二叉树的结构（通常堆是通过一维数组来实现的），并满足性质：以最大堆（也叫大根堆、大顶堆）为例，其中父结点的值总是大于它的孩子节点。

    我们可以很容易的定义堆排序的过程：

    由输入的无序数组构造一个最大堆，作为初始的无序区

    把堆顶元素（最大值）和堆尾元素互换

    把堆（无序区）的尺寸缩小 1，并调用 heapify (A, 0) 从新的堆顶元素开始进行堆调整

    重复步骤 2，直到堆的尺寸为 1


    堆排序是不稳定的排序算法，不稳定发生在堆顶元素与 A [i] 交换的时刻。

    比如序列：{9, 5, 7, 5}，堆顶元素是 9，堆排序下一步将 9 和第二个 5 进行交换，得到序列 { 5, 5, 7, 9 }，再进行堆调整得到 { 7, 5, 5, 9 }，重复之前的操作最后得到 { 5, 5, 7, 9 } 从而改变了两个 5 的相对次序。
    堆排序的代码如下：

    ************************************************************************/
    // 分类 -------------- 内部比较排序
    // 数据结构 ---------- 数组
    // 最差时间复杂度 ---- O (nlogn)
    // 最优时间复杂度 ---- O (nlogn)
    // 平均时间复杂度 ---- O (nlogn)
    // 所需辅助空间 ------ O (1)
    // 稳定性 ------------ 不稳定
    #include <stdio.h>
    void Swap(int A[], int i, int j)
    {
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }

    void Heapify(int A[], int i, int size)
    {
        int left_child = 2 * i + 1;
        int right_chile = 2 * i + 2;
        int max = i;
        if (left_child < size && A[left_child] > A[max])
            max = left_child;
        if (right_chile < size && A[right_chile] > A[max])
            max = right_chile;
        if (max != i)
        {
            Swap(A, i, max);
            Heapify(A, max, size);
        }
    }

    int BuildHeap(int A[], int n)
    {
        int heap_size = n;
        for (int i = heap_size / 2 - 1; i >= 0; i--)
            Heapify(A, i, heap_size);
        return heap_size;
    }

    void HeapSort(int A[], int n)
    {
        int heap_size = BuildHeap(A, n);
        while (heap_size > 1)
        {
            Swap(A, 0, --heap_size);
            Heapify(A, 0, heap_size);
        }
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
        HeapSort(A, n);
        printf("排序后数组为:\n");
        for (int i = 0; i < n; i++)
            printf("%5d", A[i]);
        printf("\n");
        return 0;
    }
