/*************************************************************************
>> File Name: 第一个只出现一次的字符.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.04.01

题目描述
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
************************************************************************/

#include<iostream>
using namespace std;
#include<string>
#include<map>

class Solution
{
    public:
        int FirstNotRepeatingChar(string str)
        {
            if(str.size()==0)
                return -1;
            map<char,int> dict;
            for(string::size_type i = 0; i < str.size(); ++i)
            {
                ++dict[str[i]];
            }
            string::size_type index = 0;
            for(string::size_type i = 0; i< str.size(); ++i)
            {
                if(dict[str[i]]==1)
                {
                    index = i;
                    break;
                }
            }
            return index;
        }
};
