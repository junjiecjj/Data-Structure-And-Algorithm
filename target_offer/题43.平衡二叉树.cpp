/*************************************************************************
>> File Name: 平衡二叉树.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.04.01
题目描述
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
************************************************************************/

#include<iostream>
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution
{
    public:
        bool IsBalanced_Solution(TreeNode* pRoot)
        {
            int depth;
            return IsBalanceTree(pRoot, &depth);
        }
    private:
        bool IsBalanceTree(const TreeNode *Root,int *depth)//判断是否是平衡二叉树
        {
        if(Root == NULL)
        {
            *depth = 0;
            return true;
        }
        int left,right;
        if(IsBalanceTree(Root -> left, &left) && IsBalanceTree(Root -> right,&right))
        {
            int diff = left - right;
            if(diff <= 1 && diff >= -1)
            {
                *depth = (left > right ? left +1 : right +1);
                return true;
            }
        }
        return false;
    }

};
