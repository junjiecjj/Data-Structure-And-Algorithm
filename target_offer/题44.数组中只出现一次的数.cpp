/*************************************************************************
>> File Name: 数组中只出现一次的数.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.04.02

题目描述
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
************************************************************************/

#include<iostream>
using namespace std;
#include<vector>
#include<map>


class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
         
        int len=data.size();
        if(len<=2) return;
         
        int one=0;
        for(int i=0;i<len;i++)
        {
            one=one^data[i];
        }
         
        int pos=0;
        int flag=1;
        while(flag)
        {
            if(one&flag)
                break;
            flag=flag<<1;
            pos++;
        }
         
        for(int i=0;i<len;i++)
        {
            if((data[i]&flag)) *num1=*num1^data[i];
            else *num2=*num2^data[i];
        }
    }
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    int size=data.size();
    map<int,int>mp;
    for(int i=0;i<size;++i)
    {
        mp[data[i]]++;
    }
    map<int,int>::iterator it;
    int m=0;
    for(it=mp.begin();it!=mp.end();++it)
    {
        if(it->second==1)
        {
            if(m==0)
            {
                *num1=it->first;
                ++m;
            }
            else
            {
                *num2=it->first;
                break;
            }
              
        }
    }
    }
};
