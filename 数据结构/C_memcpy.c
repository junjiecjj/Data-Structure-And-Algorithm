#include <stdio.h>
#include <string.h>



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

int main ()
{
    const int src[50] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int dest[50];

    memcpy(dest, src, sizeof(int)*6);

    displayArray(src, 15);
    displayArray(dest, 6);



    return(0);
}
