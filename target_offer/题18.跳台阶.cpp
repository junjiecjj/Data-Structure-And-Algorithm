/*************************************************************************
>> File Name: 跳台阶.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.28

题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。
求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    int jumpFloor(int number)
    {
        int f1 = 1;
        int f2 = 2;
        int f3 = 3;
        if(number <= 0)
            return -1;
        if(number == 1)
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
            return f2;
        }
    }
};
