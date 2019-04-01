/*************************************************************************
>> File Name: 数字在排序数组中出现的次数.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.04.01

题目描述
统计一个数字在排序数组中出现的次数。
************************************************************************/

#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:
        int GetNumberOfK(vector<int> data ,int k)
        {
            int i = 0;
            unsigned int len = data.size();
            int left = 0;
            int right = len - 1;
            int mid = 0;
            int Count = 0;

            if(len == 0)
                return 0;

            while(left <= right)
            {
                mid = (left + right)>>1;

                if(k > data[mid])
                    left = mid +1;
                if(k < data[mid])
                    right = mid -1;
                if(k == data[mid])
                    break;
            }
            i = mid;
            while((i >= 0) && (k == data[i]))
            {
                i--;
                Count++;
            }

            i = mid + 1;
            while((i < len) && (k == data[i]))
            {
                i++;
                Count++;
            }
            return Count;
        }
};

int main()
{
    Solution test;
    vector<int> vec = {1,2,3,4,5,5,5,5,5,6,6,6,7,7,8,8,8,9,10};
    int a = test.GetNumberOfK(vec,6);
    cout << "a = " << a << endl;
    return 0;
}
