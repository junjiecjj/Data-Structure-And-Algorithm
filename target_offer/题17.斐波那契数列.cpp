/*************************************************************************
>> File Name: 斐波那契数列.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.28

题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
n<=39
************************************************************************/

#include<iostream>
using namespace std;


class Solution {
public:
    int Fibonacci(int n)
    {
        int f0 = 0;
        int f1 = 1;
        int f2 = 1;
        if(n == 0)
            return f0;
        else if(n == 1)
            return f1;
        else
        {
            int i = 2;
            while(i <= n)
            {
                f2 = f0 + f1;
                f0 = f1;
                f1 = f2;
                i++;
            }
            return f2;
        }
    }
};
