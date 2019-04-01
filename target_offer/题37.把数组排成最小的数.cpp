/*************************************************************************
>> File Name: 把数组排成最小的数.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.04.01

题目描述
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
************************************************************************/

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    static bool compare(int a,int b)
    {
        string str1=to_string(a)+to_string(b);
        string str2=to_string(b)+to_string(a);
        return str1<str2;
    }
    string PrintMinNumber(vector<int> numbers) {
        if(numbers.size()==0)
            return "";
        sort(numbers.begin(),numbers.end(),compare);
        string result;
        for(unsigned int i=0;i<numbers.size();i++)
            {
            result+=to_string(numbers[i]);
        }
        return result;
    }
};
