/*************************************************************************
>> File Name: 包含min函数的栈.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.31

题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
************************************************************************/

#include<iostream>
using namespace std;
#include<stack>

class Solution {
public:
    void push(int value)
    {
        data.push(value);
        if(Min.size() == 0 || value < Min.top())
            Min.push(value);
        else
            Min.push(Min.top());
    }
    void pop()
    {
        if(!data.empty() && !Min.empty())
        {
            data.pop();
            Min.pop();
        }
    }
    int top()
    {
        return data.top();
    }
    int min()
    {
        return Min.top();
    }

private:
    stack<int> data;
    stack<int> Min;
};
