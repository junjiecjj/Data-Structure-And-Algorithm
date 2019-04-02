/*************************************************************************
>> File Name: 把字符串转换成整数.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.04.02

题目描述
将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，
要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。
************************************************************************/

#include<iostream>
using namespace std;
#include<string>

class Solution
{
    public:
        int StrToInt(string str)
        {
            int len = str.size();
            if(len == 0)
                return 0;
            int flag = 0;
            int num = 0;
            int i =0;
            while(str[i] == ' ')
                i++;
            if(str[i] == '-')
            {
                i++;
                flag = -1;
            }
            else if(str[i] == '+')
            {
                i++;
                flag = 1;
            }
            while(str[i] != '\0')
            {
                if(str[i] >= '0' && str[i] <= '9')
                {
                    num = num*10 + (str[i]-'0');
                    ++i;
                }
                else
                    return 0;
            }
            num = flag*num;
            return num;
        }
};
