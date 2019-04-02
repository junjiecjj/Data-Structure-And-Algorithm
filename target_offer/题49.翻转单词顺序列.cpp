/*************************************************************************
>> File Name: 翻转单词顺序列.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.04.02
题目描述
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，
有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，
正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
************************************************************************/

#include<iostream>
using namespace std;
#include<string>

class Solution
{
    public:

        void reversestr(string &S,int start,int end)
        {
            while(start < end)
                swap(S[start++], S[end--]);
        }
        string ReverseSentence(string str)
        {
            int len = str.size();
            if(len == 0)
                return "";
            int begin = 0;
            int end = 0;
            reversestr(str, 0, len-1);
            begin = end = 0;
            while(str[begin] != '\0')
            {
                if(str[begin] == ' ')
                {
                    begin++;
                    end++;
                }
                else if(str[end] ==' ' || str[end] == '\0')
                {
                    reversestr(str,begin,--end);
                    begin = ++end;
                }
                else
                    end++;
            }

            return str;
        }
};
