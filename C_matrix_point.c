/*************************************************************************
>> File Name: C_matrix.c
>> Author: 陈俊杰
>> Mail: 2716705056qq.com
>> Created Time: 2021年01月09日 星期六 19时06分00秒
>> 此程序的功能是：进行常见的矩阵操作，如矩阵生成，矩阵与数组的关系、矩阵的文件输入输出。
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <sys/socket.h>
#include <stddef.h>
#include <locale.h>
#include <time.h>
#include <complex.h>

#define MONTHS 12
#define SIZE 4

int sum(int ar[], int n) // how big an array?
{
    int i;
    int total = 0;

    for (i = 0; i < n; i++)
        total += ar[i];
    printf("The size of ar is %zd bytes.\n", sizeof(ar));

    return total;
}

int sum1(const int ar[], int n)
{
    int i;
    int total = 0;
    for (int i; i < n; ++i)
    {
        total += ar[i];
    }
    return total;
}
/*
以上代码中的const告诉编译器，该函数不能修改ar指向的数组中的内容。如果在函数中不小心使用类似ar[i]++的表达式，编译器会捕获这个错误，并生成一条错误信息。

这里一定要理解，这样使用const并不是要求原数组是常量，而是该函数在处理数组时将其视为常量，不可更改。这样使用const可以保护数组的数据不被修改，就像按值传递可以保护基本数据类型的原始值不被改变一样。一般而言，如果编写的函数需要修改数组，在声明数组形参时则不使用const；如果编写的函数不用修改数组，那么在声明数组形参时最好使用const。
*/
int sump(int *start, int *end)
{
    int total = 0;

    while (start < end)
    {
        total += *start; // add value to total
        start++;         // advance pointer to next element
    }

    return total;
}

void print_2D_matrix(int m, int n, int **A)
{
    printf("*********第1种打印二维数组的方法***************\n");
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%8d", A[i][j]);
        }
        printf("\n");
    }
}
void print_2D_matrix1(int m, int n, int (*A)[n])
{
    printf("*********第2种打印二维数组的方法***************\n");
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%8d", A[i][j]);
        }
        printf("\n");
    }
}

void print_2D_matrix2(int m, int n, int A[][n])
{
    printf("*********第3种打印二维数组的方法***************\n");
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%8d", A[i][j]);
        }
        printf("\n");
    }
}
void displayArray(int arr[], int size)
{
    printf("****************  一维数组：传递一维数组 方法1*********************\n");
    for (int i = 0; i < size; ++i)
    {
        printf("%5d", arr[i]);
    }
    printf("\n");
}

void displayArray1(int *arr, int size)
{
    printf("****************  一维数组：传递一维数组 方法2*********************\n");
    for (int i = 0; i < size; ++i)
    {
        printf("%5d ", arr[i]);
    }
    printf("\n");
}

void displayArray2(int *arr, int size)
{
    printf("****************  一维数组：传递一维数组 方法3*********************\n");
    for (int i = 0; i < size; ++i)
    {
        printf("%5d ", arr[i]);
    }
    printf("\n");
}
void displayArray3(int *arr, int size)
{
    printf("****************  一维数组：传递一维数组 方法4*********************\n");
    for (int i = 0; i < size; ++i)
    {
        printf("%5d ", *(arr + i));
    }
    printf("\n");
}
void displayArray4(int arr[], int size)
{
    printf("****************  一维数组：传递一维数组 方法5*********************\n");
    for (int i = 0; i < size; ++i)
    {
        printf("%5d ", *(arr + i));
    }
    printf("\n");
}
int main(int argc, char *argv[])
{
    printf("****************  一维数组 ：定义和初始化*********************\n");
    int a[5] = {1, 2, 3, 4, 5};
    displayArray(a, 5);
    displayArray1(a, 5);
    displayArray2(a, 5);
    displayArray3(a, 5);
    displayArray4(a, 5);
    /*下面的写法的花括号中有 5 个数，所以系统会自动定义数组b的长度为 5。但是要注意，只有在定义数组时就初始化才可以这样写。如果定义数组时不初始化，那么省略数组长度就是语法错误*/
    int b[] = {11, 21, 31, 41, 51};

    printf("****************  一维数组 *********************\n");
    int days[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int index;

    for (index = 0; index < MONTHS; index++)
    {
        printf("Month %2d has %d days.\n", index + 1, *(days + index)); // same as days[index]
        //printf("Month %2d has %d days.\n", index + 1, days[index]);     // same as days[index]
    }
    printf("****************  一维数组：malloc()分配内存 *********************\n");
    int *pv = (int *)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; ++i)
    {
        pv[i] = i + 1;
        // 或 *(pv + i) = i + 1;
    }

    printf("****************  一维数组 *********************\n");
    int no_data[SIZE]; /* uninitialized array */
    //  int no_data[SIZE] = {0};
    int i;

    printf("%2s%14s\n", "i", "no_data[i]");
    for (i = 0; i < SIZE; i++)
        printf("%2d  %14d\n", i, no_data[i]);
    /*

注意 存储类别警告数组和其他变量类似，可以把数组创建成不同的存储类别（storageclass）。第12章将介绍存储类别的相关内容，现在只需记住：本章描述的数组属于自动存储类别，意思是这些数组在函数内部声明，且声明时未使用关键字static。到目前为止，本书所用的变量和数组都是自动存储类别。在这里提到存储类别的原因是，不同的存储类别有不同的属性，所以不能把本章的内容推广到其他存储类别。对于一些其他存储类别的变量和数组，如果在声明时未初始化，编译器会自动把它们的值设置为0。

初始化列表中的项数应与数组的大小一致。如果不一致会怎样？我们还是以上一个程序为例，但初始化列表中缺少两个元素,如下所示，编译器做得很好。当初始化列表中的值少于数组元素个数时，编译器会把剩余的元素都初始化为0。也就是说，如果不初始化数组，数组元素和未初始化的普通变量一样，其中存储的都是垃圾值；但是，如果部分初始化数组，剩余的元素就会被初始化为0。如果初始化列表的项数多于数组元素个数，编译器可没那么仁慈，它会毫不留情地将其视为错误。*/

    int some_data[SIZE] = {1492, 1066};
    i = 0;
    printf("%2s%14s\n", "i", "some_data[i]");
    for (i = 0; i < SIZE; i++)
    {
        printf("%2d%14d\n", i, some_data[i]);
    }

    int marbles[10] = {20, 10, 5, 39, 4, 16, 19, 26, 31, 20};
    long answer;

    answer = sump(marbles, marbles + 10);
    printf("The total number of marbles is %ld.\n", answer);
    answer = sum(marbles, SIZE);
    printf("The total number of marbles is %ld.\n", answer);
    printf("The size of marbles is %zd bytes.\n", sizeof marbles);

    /*
 int a[10]={1};
 a代表数组首元素地址，相当于&a[0]，但&a代表整个数组的地址，即数组指针。
注意 声明数组形参因为数组名是该数组首元素的地址，作为实际参数的数组名要求形式参数是一个与之匹配的指针。只有在这种情况下，C才会把int ar[]和int * ar解释成一样。也就是说，ar是指向int的指针。由于函数原型可以省略参数名，所以下面4种原型都是等价的：
int sum(int *ar, int n);
int sum(int *, int );
int sum(int ar[], int n);
int sum(int  []  , int   );

但是，在函数定义中不能省略参数名。下面两种形式的函数定义等价：
int sum(int *ar, int n)
{
    其他代码省略
}
int sum(int ar[], int n)
{
    其他代码省略
}

至于C语言，ar[i]和*(ar+i)这两个表达式都是等价的。无论ar是数组名还是指针变量，这两个表达式都没问题。但是，只有当ar是指针变量时，才能使用ar++这样的表达式。

可以把sump()中的循环体缩写为：total  += *start++

使用后缀形式（即start++而不是++start）意味着先把指针指向位置上的值加到total上，然后再递增指针。如果使用*++start，顺序则反过来，先递增指针，再使用指针指向位置上的值。如果使用(*start)++，则先使用start指向的值，再递增该值，而不是递增指针。这样，指针将一直指向同一个位置，但是该位置上的值发生了变化。虽然*start++的写法比较常用，但是*(start++)这样写更清楚。下面的程序演示了这些优先级的情况。
 */

    int data[2] = {100, 200};
    int moredata[2] = {300, 400};

    int *p1, *p2, *p3;

    p1 = p2 = data;
    p3 = moredata;
    printf("  *p1 = %d,   *p2 = %d,     *p3 = %d\n", *p1, *p2, *p3);
    printf("*p1++ = %d, *++p2 = %d, (*p3)++ = %d\n", *p1++, *++p2, (*p3)++);
    printf("  *p1 = %d,   *p2 = %d,     *p3 = %d\n", *p1, *p2, *p3);

    printf("****************  一维数组_4 *********************\n");
    int urn[5] = {100, 200, 300, 400, 500};
    int *ptr1, *ptr2, *ptr3;

    ptr1 = urn;     // assign an address to a pointer
    ptr2 = &urn[2]; // ditto
    // dereference a pointer and take
    // the address of a pointer
    printf("\n pointer value, dereferenced pointer, pointer address:\n");
    printf("ptr1 = %p, *ptr1 =%d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);

    // pointer addition
    ptr3 = ptr1 + 4;
    printf("\nadding an int to a pointer:\n");
    printf("ptr1 + 4 = %p, *(ptr1 + 4) = %d\n", ptr1 + 4, *(ptr1 + 4));
    ptr1++; // increment a pointer
    printf("\nvalues after ptr1++:\n");
    printf("ptr1 = %p, *ptr1 =%d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);
    ptr2--; // decrement a pointer
    printf("\nvalues after --ptr2:\n");
    printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n", ptr2, *ptr2, &ptr2);
    --ptr1; // restore to original value
    ++ptr2; // restore to original value
    printf("\nPointers reset to original values:\n");
    printf("ptr1 = %p, ptr2 = %p\n", ptr1, ptr2);
    // subtract one pointer from another
    printf("\nsubtracting one pointer from another:\n");
    printf("ptr2 = %p, ptr1 = %p, ptr2 - ptr1 = %td\n", ptr2, ptr1, ptr2 - ptr1);
    // subtract an integer from a pointer
    printf("\nsubtracting an int from a pointer:\n");
    printf("ptr3 = %p, ptr3 - 2 = %p\n", ptr3, ptr3 - 2);
    /*
下面分别描述了指针变量的基本操作。
·赋值：可以把地址赋给指针。例如，用数组名、带地址运算符（&）的变量名、另一个指针进行赋值。在该例中，把urn数组的首地址赋给了ptr1，该地址的编号恰好是0x7fff5fbff8d0。变量ptr2获得数组urn的第3个元素（urn[2]）的地址。注意，地址应该和指针类型兼容。也就是说，不能把double类型的地址赋给指向int的指针，至少要避免不明智的类型转换。C99/C11已经强制不允许这样做。
·解引用：*运算符给出指针指向地址上存储的值。因此，*ptr1的初值是100，该值存储在编号为0x7fff5fbff8d0的地址上。

·取址：和所有变量一样，指针变量也有自己的地址和值。对指针而言，&运算符给出指针本身的地址。本例中，ptr1存储在内存编号为0x7fff5fbff8c8的地址上，该存储单元存储的内容是0x7fff5fbff8d0，即urn的地址。因此&ptr1是指向ptr1的指针，而ptr1是指向utn[0]的指针。

·指针与整数相加：可以使用+运算符把指针与整数相加，或整数与指针相加。无论哪种情况，整数都会和指针所指向类型的大小（以字节为单位）相乘，然后把结果与初始地址相加。因此ptr1+4与&urn[4]等价。如果相加的结果超出了初始指针指向的数组范围，计算结果则是未定义的。除非正好超过数组末尾第一个位置，C保证该指针有效。

·递增指针：递增指向数组元素的指针可以让该指针移动至数组的下一个元素。因此，ptr1++相当于把ptr1的值加上4（我们的系统中int为4字节），ptr1指向urn[1]（见图10.4，该图中使用了简化的地址）。现在ptr1的值是0x7fff5fbff8d4（数组的下一个元素的地址），*ptr的值为200（即urn[1]的值）。注意，ptr1本身的地址仍是0x7fff5fbff8c8。毕竟，变量不会因为值发生变化就移动位置。

·指针减去一个整数：可以使用-运算符从一个指针中减去一个整数。指针必须是第1个运算对象，整数是第2个运算对象。该整数将乘以指针指向类型的大小（以字节为单位），然后用初始地址减去乘积。所以ptr3 - 2与&urn[2]等价，因为ptr3指向的是&urn[4]。如果相减的结果超出了初始指针所指向数组的范围，计算结果则是未定义的。除非正好超过数组末尾第一个位置，C保证该指针有效。

·递减指针：当然，除了递增指针还可以递减指针。在本例中，递减ptr2使其指向数组的第2个元素而不是第3个元素。前缀或后缀的递增和递减运算符都可以使用。注意，在重置ptr1和ptr2前，它们都指向相同的元素urn[1]。

·指针求差：可以计算两个指针的差值。通常，求差的两个指针分别指向同一个数组的不同元素，通过计算求出两元素之间的距离。差值的单位与数组类型的单位相同。例如，程序清单10.13的输出中，ptr2 - ptr1得2，意思是这两个指针所指向的两个元素相隔两个int，而不是2字节。只要两个指针都指向相同的数组（或者其中一个指针指向数组后面的第1个地址），C都能保证相减运算有效。如果指向两个不同数组的指针进行求差运算可能会得出一个值，或者导致运行时错误。

·比较：使用关系运算符可以比较两个指针的值，前提是两个指针都指向相同类型的对象。

在递增或递减指针时还要注意一些问题。编译器不会检查指针是否仍指向数组元素。C只能保证指向数组任意元素的指针和指向数组后面第1个位置的指针有效。但是，如果递增或递减一个指针后超出了这个范围，则是未定义的。另外，可以解引用指向数组任意元素的指针。但是，即使指针指向数组后面一个位置是有效的，也不能保证可以解引用这样的越界指针。

解引用未初始化的指针说到注意事项，一定要牢记一点：千万不要解引用未初始化的指针。例如，考虑下面的例子：
*/
    // int *pt; //未初始化的指针
    // *pt = 5; //严重错误

    /*
为何不行？第2行的意思是把5存储在pt指向的位置。但是pt未被初始化，其值是一个随机值，所以不知道5将存储在何处。这可能不会出什么错，也可能会擦写数据或代码，或者导致程序崩溃。切记：创建一个指针时，系统只分配了存储指针本身的内存，并未分配存储数据的内存。因此，在使用指针之前，必须先用已分配的地址初始化它。例如，可以用一个现有变量的地址初始化该指针（使用带指针形参的函数时，就属于这种情况）。或者还可以使用第12章将介绍的malloc()函数先分配内存。无论如何，使用指针时一定要注意，不要解引用未初始化的指针！
*/
    //   double *pt1;  //未初始化的指针
    //    *pt1 = 2.4;  //严重错误
    printf("****************  const  与指针 *********************\n");

    double rates[5] = {8.9, 100.12, 59.45, 183.11, 340.5};
    double num1 = 2;
    const double *pd = rates;
    // 1...............指针指向的数据是const的，代表着不能通过pd改变pd指向的位置的值，但是pd可以指向别处；

    // 第2行代码把pd指向的double类型的值声明为const，这表明不能使用pd来更改它所指向的值：

    //  *pd = 29.89; //不允许
    // pd[2] = 222.22;   //不允许
    rates[0] = 99.99; //允许，因为rates不是const限定的
    pd = &num1;

    //2............指向const数据的指针pc可以指向const数据或非const数据的地址初，因为只要不通过指针pc改变它所指向的值就行，pc指向什么没有限制：
    // double rates[5] = {8.9, 100.12, 59.45, 183.11, 340.5};
    const double locked[4] = {0.08, 0.075, 0.0725, 0.07};
    const double *pc = rates; //有效
    pc = locked;              //有效
    pc = &rates[3];           //有效

    //3................ 然而，只能把非const数据的地址赋给普通指针，这个规则非常合理。否则，通过指针就能改变const数组中的数据。：
    // double rates[5] = {8.9, 100.12, 59.45, 183.11, 340.5};
    //  const double locked[4] = {0.08, 0.075, 0.0725, 0.07};
    double *pnc = rates; //有效
    //  pnc = locked;        //无效
    pnc = &rates[3]; //  有效

    //4................ 指针本身是const的，该指针不能指向别处，但是可以改变所指向位置的值：
    // double rates[5] = {8.9, 100.12, 59.45, 183.11, 340.5};
    double *const pc1 = rates; //pc1指向数组的开始
                               // pcpc1 = &rates[2];           //不允许，因为该指针不能指向别处
    *pc1 = 92.99;              //可以，

    //  最后，在创建指针时还可以使用const两次，该指针既不能更改它所指向的地址，也不能修改指向地址上的值：
    // double rates[5] = {8.9, 100.12, 59.45, 183.11, 340.5};
    const double *const pc2 = rates; //pc1指向数组的开始
    // pc = &rates[2];                  // 不允许
    // *pc = 92.99;                     // 不允许
    printf("****************  sizeof() 与指针 *********************\n");
    int vector[5] = {1, 2, 3, 4, 5};
    int *pv1 = vector;
    printf("sizeof(vector) = %ld \nsizeof(pv1) = %ld\n", sizeof(vector), sizeof(pv1));
    // "sizeof(vector)为一维数组的长度，sizeof(pv) 为指针pv的长度"

    printf("****************  一维指针数组 *********************\n");
    int *arr[5];
    for (int i = 0; i < 5; ++i)
    {
        arr[i] = (int *)malloc(sizeof(int));
        *arr[i] = i;
        //以上两行等效于：
        // *(arr+i) = (int *) malloc(sizeof(int));
        //  **(arr+i) = i;
        // （arr+i）表示数组的第i个元素的地址，我们需要修改这个地址中的内容，所以用了*(arr+i)，第一行语句我们将已经分配的内存赋给这个位置，
    }

    printf("****************  二维数组 *********************\n");
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    for (int i = 0; i < 2; ++i)
    {
        printf("&matrix[%d]: %p  sizeof(matrix[%d]): %ld\n", i, &matrix[i], i, sizeof(matrix[i]));
    }

    int Matrix[2][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            printf("地址&Matrix[%d][%d]: %p  值: %ld\n", i, j, &Matrix[i][j], Matrix[i][j]);
        }
    }

    printf("****************  动态分配可能不连续的二维数组 *********************\n");

    int rows = 2;
    int columns = 5;

    int **matrix1 = (int **)malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; ++i)
    {
        matrix1[i] = (int *)malloc(columns * sizeof(int));
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix1[i][j] = i + j;
        }
    }
    print_2D_matrix(rows, columns, matrix1);
    //   print_2D_matrix1(rows, columns, matrix1);   //此方法不行
    //   print_2D_matrix2(rows, columns, matrix1);    //此方法不行
    printf("**************** 传递二维数组 *********************\n");

    int B[2][5] = {0};
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            B[i][j] = i + j;
        }
    }
    //  print_2D_matrix(rows, columns, B); //此方法不行
    print_2D_matrix1(rows, columns, B);
    print_2D_matrix2(rows, columns, B);
    printf("****************  动态分配连续的二维数组 *********************\n");
    //   int rows = 2;
    //   int columns = 5;
    int **matrix2 = (int **)malloc(rows * sizeof(int *));
    matrix2[0] = (int *)malloc(rows * columns * sizeof(int));
    for (int i = 1; i < rows; ++i)
    {
        matrix2[i] = matrix[0] + i * columns;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix2[i][j] = i + j;
        }
    }
    print_2D_matrix(rows, columns, matrix2);

    printf("****************  二维数组 *********************\n");
    int zippo[4][2] = {{2, 4}, {6, 8}, {1, 3}, {5, 7}};

    printf("   zippo = %p,    zippo + 1 = %p\n",
           zippo, zippo + 1);
    printf("zippo[0] = %p, zippo[0] + 1 = %p\n",
           zippo[0], zippo[0] + 1);
    printf("  *zippo = %p,   *zippo + 1 = %p\n",
           *zippo, *zippo + 1);
    printf("zippo[0][0] = %d\n", zippo[0][0]);
    printf("  *zippo[0] = %d\n", *zippo[0]);
    printf("    **zippo = %d\n", **zippo);
    printf("      zippo[2][1] = %d\n", zippo[2][1]);
    printf("*(*(zippo+2) + 1) = %d\n", *(*(zippo + 2) + 1));
    /*
·因为zippo是数组首元素的地址，所以zippo的值和&zippo[0]的值相同。而zippo[0]本身是一个内含两个整数的数组，所以zippo[0]的值和它首元素（一个整数）的地址（即&zippo[0][0]的值）相同。简而言之，zippo[0]是一个占用一个int大小对象的地址，而zippo是一个占用两个int大小对象的地址。由于这个整数和内含两个整数的数组都开始于同一个地址，所以zippo和zippo[0]的值相同。

·给指针或地址加1，其值会增加对应类型大小的数值。在这方面，zippo和zippo[0]不同，因为zippo指向的对象占用了两个int大小，而zippo[0]指向的对象只占用一个int大小。因此，zippo + 1和zippo[0] + 1的值不同。

·解引用一个指针（在指针前使用*运算符）或在数组名后使用带下标的[]运算符，得到引用对象代表的值。因为zippo[0]是该数组首元素（zippo[0][0]）的地址，所以*(zippo[0])表示存储在zippo[0][0]上的值（即一个int类型的值）。与此类似，*zippo代表该数组首元素（zippo[0]）的值，但是zippo[0]本身是一个int类型值的地址。该值的地址是&zippo[0][0]，所以*zippo就是&zippo[0][0]。对两个表达式应用解引用运算符表明，**zippo与*&zippo[0][0]等价，这相当于zippo[0][0]，即一个int类型的值。简而言之，zippo是地址的地址，必须解引用两次才能获得原始值。地址的地址或指针的指针是就是双重间接（double indirection）的例子。

上述一段输出：
   zippo = 0x7ffd25c284c0,    zippo + 1 = 0x7ffd25c284c8
zippo[0] = 0x7ffd25c284c0, zippo[0] + 1 = 0x7ffd25c284c4
  *zippo = 0x7ffd25c284c0,   *zippo + 1 = 0x7ffd25c284c4
zippo[0][0] = 2
  *zippo[0] = 2
    **zippo = 2
      zippo[2][1] = 3
*(*(zippo+2) + 1) = 3

其他系统显示的地址值和地址形式可能不同，但是地址之间的关系与以上输出相同。该输出显示了二维数组zippo的地址和一维数组zippo[0]的地址相同。它们的地址都是各自数组首元素的地址，因而与&zippo[0][0]的值也相同。尽管如此，它们也有差别。在我们的系统中，int是4字节。前面讨论过，zippo[0]指向一个4字节的数据对象。zippo[0]加1，其值加4（十六进制中，38+4得3c）。数组名zippo是一个内含2个int类型值的数组的地址，所以zippo指向一个8字节的数据对象。因此，zippo加1，它所指向的地址加8字节（十六进制中，38+8得40）。该程序演示了zippo[0]和*zippo完全相同，实际上确实如此。然后，对二维数组名解引用两次，得到存储在数组中的值。使用两个间接运算符（*）或者使用两对方括号（[]）都能获得该值（还可以使用一个*和一对[]，但是我们暂不讨论这么多情况）。要特别注意，与zippo[2][1]等价的指针表示法是*(*(zippo+2) + 1)。看上去比较复杂，应最好能理解。下面列出了理解该表达式的思路：
*/
    printf("****************  指向多维数组的指针 *********************\n");
    int zipp[4][2] = {{2, 4}, {6, 8}, {1, 3}, {5, 7}};
    int(*pz)[2];
    pz = zipp;

    printf("   pz = %p,    pz + 1 = %p\n",
           pz, pz + 1);
    printf("pz[0] = %p, pz[0] + 1 = %p\n",
           pz[0], pz[0] + 1);
    printf("  *pz = %p,   *pz + 1 = %p\n",
           *pz, *pz + 1);
    printf("pz[0][0] = %d\n", pz[0][0]);
    printf("  *pz[0] = %d\n", *pz[0]);
    printf("    **pz = %d\n", **pz);
    printf("      pz[2][1] = %d\n", pz[2][1]);
    printf("*(*(pz+2) + 1) = %d\n", *(*(pz + 2) + 1));

    /*

    输出：
   pz = 0x7ffeeadf9e20,    pz + 1 = 0x7ffeeadf9e28
pz[0] = 0x7ffeeadf9e20, pz[0] + 1 = 0x7ffeeadf9e24
  *pz = 0x7ffeeadf9e20,   *pz + 1 = 0x7ffeeadf9e24
pz[0][0] = 2
  *pz[0] = 2
    **pz = 2
      pz[2][1] = 3
*(*(pz+2) + 1) = 3

系统不同，输出的地址可能不同，但是地址之间的关系相同。如前所述，虽然pz是一个指针，不是数组名，但是也可以使用pz[2][1]这样的写法。可以用数组表示法或指针表示法来表示一个数组元素，既可以使用数组名，也可以使用指针名：
zipp[m][n] ==  *(*(zipp+m)+n);
pz[m][n] ==  *(*(pz+m)+n);
*/

    printf("**************** 变长数组 *********************\n");
    int quarters = 4;
    int regions = 5;
    double sales[regions][quarters];

    /*
    鉴于此，C99新增了变长数组（variable-length array，VLA），允许使用变量表示数组的维度。如上所示，注意 变长数组不能改变大小变长数组中的“变”不是指可以修改已创建数组的大小。一旦创建了变长数组，它的大小则保持不变。这里的“变”指的是：在创建数组时，可以使用变量指定数组的维度。

    int sun2d(int rows, int cols, int  ar[rows][cols]);
    注意前两个形参（rows和cols）用作第3个形参二维数组ar的两个维度。因为ar的声明要使用rows和cols，所以在形参列表中必须在声明ar之前先声明这两个形参。因此，下面的原型是错误的：
    int sun2d( int  ar[rows][cols], int rows, int cols);

    */

    printf("****************  结束 *********************\n");
    return 0;
}
