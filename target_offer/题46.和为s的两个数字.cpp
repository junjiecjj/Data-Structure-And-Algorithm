/*************************************************************************
>> File Name: 和为s的两个数.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.04.02

题目描述
输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。

输出描述:
对应每个测试案例，输出两个数，小的先输出。
************************************************************************/

#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:
        vector<int> FindNumbersWithSum(vector<int> Array,int sum)
        {
            vector<int> result;
            int len = Array.size();
            if(len < 1)
                return result;

            int i = 0;
            int j = len - 1;

            while(i < j)
            {
                int cursum = Array[i] + Array[j];
                if(cursum == sum)
                {
                    result.push_back(Array[i]);
                    result.push_back(Array[j]);
                    break;
                }
                else if(cursum < sum)
                    i++;
                else
                    j--;
            }
            return result;
        }
};
