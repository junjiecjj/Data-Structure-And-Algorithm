/*************************************************************************
>> File Name: 二进制中1的个数.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.31

题目描述
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    int  NumberOf1(int n)
    {
        int count = 0;
        while(n != 0)
        {
            count++;
            n = n&(n-1);
        }
        return count;
     }
};
