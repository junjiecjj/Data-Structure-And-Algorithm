/*************************************************************************
>> File Name: 左旋转字符串.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.04.02

题目描述
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，
即“XYZdefabc”。是不是很简单？OK，搞定它！
************************************************************************/

#include<iostream>
using namespace std;
#include<string>


class Solution
{
    public:
        void reversestr(string &S, int start, int end)
        {
            char tmp;
            while(start < end)
            {
                tmp = S[start];
                S[start] = S[end];
                S[end] = tmp;
                end--;
                start++;
            }
        }

        string LeftRotateString(string str, int n)
        {
            int len = str.size();
            if(len == 0 || n == 0)
                return str;
            string &temp = str;
            reversestr(temp, 0, n-1);
            reversestr(temp,n, len-1);
            reversestr(temp, 0, len-1);
            return str;
        }
};
