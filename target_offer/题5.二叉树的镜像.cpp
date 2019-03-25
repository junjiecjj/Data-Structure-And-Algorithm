/*************************************************************************
>> File Name: 二叉树的镜像.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.22


题目描述
操作给定的二叉树，将其变换为源二叉树的镜像。
输入描述:

二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11

    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5

************************************************************************/

#include<iostream>
using namespace std;
#include<deque>
#include<stack>

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
    void Mirror(TreeNode *pRoot){//递归版本
        if(pRoot == NULL)
            return;
        else
        {
            TreeNode *tmp = pRoot -> left;
            pRoot -> left = pRoot -> right;
            pRoot -> right = tmp;
            Mirror(pRoot -> left);
            Mirror(pRoot -> right);
            return;
        }
    }
    void Mirror1(TreeNode *pRoot){//非递归版本
        if(pRoot == NULL)
            return;
        stack<TreeNode *> Stack;
        Stack.push(pRoot);
        while(!Stack.empty())
        {
            TreeNode *node = Stack.top();
            Stack.pop();

            if(node != NULL)
            {
                TreeNode *tmp = node -> left;
                node -> left = node -> right;
                node -> right = tmp;
                Stack.push(node -> left);
                Stack.push(node -> right);
            }
        }
    }

};
