/*************************************************************************
>> File Name: 基数排序.c
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.01.21
基数排序的发明可以追溯到 1887 年赫尔曼・何乐礼在打孔卡片制表机上的贡献。它是这样实现的：将所有待比较正整数统一为同样的数位长度，数位较短的数前面补零。然后，从最低位开始进行基数为 10 的计数排序，一直到最高位计数排序完后，数列就变成一个有序序列（利用了计数排序的稳定性）。

基数排序的时间复杂度是 O (n * dn)，其中 n 是待排序元素个数，dn 是数字位数。这个时间复杂度不一定优于 O (n log n)，dn 的大小取决于数字位的选择（比如比特位数），和待排序数据所属数据类型的全集的大小；dn 决定了进行多少轮处理，而 n 是每轮处理的操作数目。

如果考虑和比较排序进行对照，基数排序的形式复杂度虽然不一定更小，但由于不进行比较，因此其基本操作的代价较小，而且如果适当的选择基数，dn 一般不大于 log n，所以基数排序一般要快过基于比较的排序，比如快速排序。由于整数也可以表达字符串（比如名字或日期）和特定格式的浮点数，所以基数排序并不是只能用于整数排序。

基数排序的实现代码如下：

************************************************************************/
// 分类 ------------- 内部非比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O (n * dn)
// 最优时间复杂度 ---- O (n * dn)
// 平均时间复杂度 ---- O (n * dn)
// 所需辅助空间 ------ O (n * dn)
// 稳定性 ----------- 稳定
#include <stdio.h>
#include <stdlib.h>

const int dn = 3;
const int k = 10;

int GetDigit(int x, int d)
{
    int radix[] = {1, 1, 10, 100};
    return (x / radix[d]) % 10;
}

void CountingSort(int A[], int n, int d)
{
    int C[k];
    for (int i = 0; i < k; i++)
        C[i] = 0;

    for (int i = 0; i < n; i++)
        C[GetDigit(A[i], d)]++;

    for (int i = 1; i < k; i++)
        C[i] = C[i] + C[i - 1];

    int *B = (int *)malloc(n * sizeof(int));
    for (int i = n - 1; i >= 0; i--)
    {
        int dight = GetDigit(A[i], d);
        B[--C[dight]] = A[i];
    }
    for (int i = 0; i < n; i++)
        A[i] = B[i];
    free(B);
}

void LsdRadixSort(int A[], int n)
{
    for (int d = 1; d <= dn; d++)
        CountingSort(A, n, d);
}

int main()
{
    int A[] = {20, 90, 64, 289, 998, 365, 852, 123, 789, 456}; // 针对基数排序设计的输入
    int n = sizeof(A) / sizeof(int);
    printf("排序前:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    LsdRadixSort(A, n);
    printf("基数排序结果：");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
