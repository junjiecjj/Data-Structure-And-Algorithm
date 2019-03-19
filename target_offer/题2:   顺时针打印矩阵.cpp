/*************************************************************************
>> File Name: 顺时针打印矩阵.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.18


题目描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，
如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
     则依次打印出数字:  1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
************************************************************************/

#include<iostream>
using namespace std;
#include<vector>


class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {

        int raw = matrix.size();                          //矩阵行数
        int col = matrix[0].size();                       //矩阵列数
        vector<int> result;
        if(raw == 0|| col == 0)
            return result;
        int lr = 0;
        int lc = 0;
        int rr = raw - 1;
        int rc = col - 1;
        while(lr <= rr && lc <= rc)
        {
            for(int i  = lc; i <= rc; i++)
                result.push_back(matrix[lr][i]);
            if(lr < rr)
                for(int i = lr+1; i <= rr; i++)
                    result.push_back(matrix[i][rc]);
            if(lr < rr && lc < rc)
                for(int i = rc-1; i >= lc; i--)
                    result.push_back(matrix[rr][i]);
            if(lc < rc && lr + 1 < rr)
                for(int i = rr-1; i >= lr+1; i--)
                    result.push_back(matrix[i][lc]);
            lr++;  lc++;  rr--;  rc--;
        }
        return result;
    }
};
