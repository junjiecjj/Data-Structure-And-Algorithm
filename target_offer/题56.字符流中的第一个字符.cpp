/*************************************************************************
>> File Name: 字符流中第一个不重复的字符.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.04.02
题目描述
请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
输出描述:
如果当前字符流没有存在出现一次的字符，返回#字符。
************************************************************************/

#include<iostream>
using namespace std;
#include<string>
#include<vector>

class Solution
{
    public:
        vector<char> a;
        //Insert one char from stringstream
        void Insert(char ch)
        {
            a.push_back(ch);
        }
        //return the first appearence once char in current stringstream
        char FirstAppearingOnce()
        {
            int  C[255] = {0};
            char N = '#';
            //  int i;
            for(unsigned int i = 0;i < a.size();i++)
            {
                C[a[i]]++;
            }
         
            for(int i = 0;i < a.size();i++)
            {
                if( C[a[i]] == 1 )
                    return a[i];
            }
            return N;
    }
 
};
