/*************************************************************************
>> File Name: IO_1.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.14
************************************************************************/

#include<iostream>
using namespace std;
#include<cstdlib>
#include<cstdio>
#include<new>
#include<string>

int main()
{
    int L,W;
    char ch;
    int count = 0;
    cin >> L >> W;
    int Z = (L >W ? L : W);
    printf("L = %d, W = %d, Z = %d\n",L,W,Z);
    int *A = (int *)malloc(4*Z*sizeof(int));
    int *B = new int[4*Z];

    while(cin >> *(B+count))
    {
        ++count; 
        if(getchar() == '\n')
            break;
    }
    cout << "count = " << count << endl;
    for(int i =0; i < count; i++)
        cout << B[i] << " ";
    cout << endl;
    return 0;
}
