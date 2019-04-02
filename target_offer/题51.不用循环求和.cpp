/*************************************************************************
>> File Name: 不用循环求和.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.04.02

题目描述
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
************************************************************************/

#include<iostream>
using namespace std;
class Solution {
public:
    int Sum_Solution(int n) {
        //if(n == 1) return 1;
        int res = 0;
        n > 0 && (res = (n + Sum_Solution(n - 1)));
        return res;
    }
};
