/*************************************************************************
>> File Name: 数组中出现次数超过一半的数字.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.04.01

题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
************************************************************************/

#include<iostream>
using namespace std;
#include<vector>


class Solution
{
    public:
        int MoreThanHalfNum_Solution(vector<int> numbers)
        {
            int val = numbers[0];
            unsigned int Count = 1;
            for(unsigned int i = 0; i < numbers.size(); ++i)
            {
                if(Count == 0)
                {
                    val = numbers[i];
                    Count = 1;
                }
                else if(numbers[i] == val)
                    ++Count;
                else
                    --Count;
            }
            Count = 0;
            for(unsigned int i = 0; i < numbers.size(); ++i)
            {
                if(numbers[i] == val)
                    ++Count;
            }
            return Count > numbers.size()/2 ? val : 0;
        }
};
