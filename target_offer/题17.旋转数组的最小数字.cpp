/*************************************************************************
>> File Name: 旋转数组的最小数字.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.27

题目描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
************************************************************************/

#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        if(rotateArray.size() == 0)
            return 0;
        int low = 0;
        int high = rotateArray.size() - 1;
        while(low < high)
        {
            int mid = (low + high )/2;
            if(rotateArray[mid] < rotateArray[high])
                high = mid;
            else if(rotateArray[mid] > rotateArray[high])
                low = mid +1;
            else
                high = mid;
        }
        return rotateArray[low];
    }
};
