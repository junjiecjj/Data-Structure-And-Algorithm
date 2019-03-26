/*************************************************************************
>> File Name: 用两个栈实现队列.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.26

题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
************************************************************************/

#include<iostream>
using namespace std;
#include<stack>

class Solution
{
public:
    void push(int node)
    {
        stack1.push(node);
    }

    int pop()
    {
        int res;
        if(!stack2.empty())
        {
            ;
        }
        else
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        res = stack2.top();
        stack2.pop();
        return res;
    }

private:
    stack<int> stack1;//push()进这个栈
    stack<int> stack2;//从这个栈出
};
