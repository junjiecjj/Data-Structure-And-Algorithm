/*************************************************************************
>> File Name: solution.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.18


题目描述
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

************************************************************************/

#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    bool Find(int target, vector<vector<int>>  Array) {
        int m = Array.size();          //Array的行数
        int n = Array[0].size();        //Array的列数

        if(m != 0 && n != 0)
        {
            int raw = 0;
            int col = n-1;
            while(col >=0 && raw <= m-1)
            {
                if(target == Array[raw][col])
                    return true;
                else if(target > Array[raw][col])
                {
                    raw ++;
                }
                else
                {
                    col --;
                }
            }
        }
        return false;
    }
};
