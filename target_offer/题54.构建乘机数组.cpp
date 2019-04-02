/*************************************************************************
>> File Name: 构建乘机数组.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.04.02
题目描述
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
************************************************************************/

#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:
        vector<int> multiply(const vector<int>& A)
        {
            int len = A.size();
            vector<int> B(len);
            int ret = 1;
            for(int i= 0; i < len;ret*=A[i++])
            {
                B[i] = ret;
            }
            ret = 1;
            for(int i = len-1; i >=0; ret *= A[i--])
                B[i] *= ret;

            return B;
        }
};
