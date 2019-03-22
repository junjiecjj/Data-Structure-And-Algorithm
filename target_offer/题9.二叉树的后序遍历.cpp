/*************************************************************************
>> File Name: 二叉树的后序遍历.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.22


题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
************************************************************************/

#include<iostream>
using namespace std;
#include<vector>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    int flag = 0;//一定要设置这个变量，当第一次迭代时为0，防止最开始就是空序列，之后变为1，随后的子序列可以为空
    bool VerifySquenceOfBST(vector<int> sequence) {
        int len = sequence.size();
        if(len == 0 && flag == 0)
            return false;
        flag = 1;
        if(len <= 2)
            return true;
        vector<int> left;
        vector<int> right;
        int mid = 0;
        while(sequence[mid] < sequence[len-1])
        {
            left.push_back(sequence[mid]);
            ++mid;
        }
        for(int i = mid; i < len-1; i++)
        {
            if(sequence[i] <= sequence[len-1])
            {
                return false;
            }
            else
            {
                right.push_back(sequence[i]);
            }
        }
        return VerifySquenceOfBST(left) && VerifySquenceOfBST(right);
    }
};
