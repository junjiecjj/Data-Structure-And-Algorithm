/*************************************************************************
>> File Name: 矩阵覆盖.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.30

题目描述
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    int rectCover(int number)
    {
        int f0 = 0;
        int f1 = 1;
        int f2 = 2;
        int f3;
        if( number == 0 )
            return f0;
        else if(number == 1)
            return f1;
        else if(number == 2)
            return f2;
        else
        {
            int i = 3;
            
            while(i <= number)
            {
                f3 = f1 + f2;
                f1 = f2;
                f2 = f3;
                i++;
            }
            return f3;
        }
    }
};
