/*************************************************************************
>> File Name: 变态跳台阶.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.29

题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。
************************************************************************/

#include<iostream>
using namespace std;
#include<cmath>

class Solution {
public:
    int jumpFloorII(int number)
    {
        int f0 = 0;
        int f1 = 1;
        int f2 = 2;

        if(number == 0)
            return f0;
        else
        {
            int sum = pow(2, number-1);
            return sum;
        }
    }
};
