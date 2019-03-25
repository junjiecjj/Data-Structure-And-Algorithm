/*************************************************************************
>> File Name: 二叉搜索树的第k大节点.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.25


题目描述
给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8)中，
                                                     按结点数值大小顺序第三小结点的值为4。
************************************************************************/

#include<iostream>
using namespace std;
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
    int index = 0;
    TreeNode* KthNode(TreeNode* pRoot, int k)//递归实现
    {
        if(pRoot != NULL)
        {
            TreeNode *node = KthNode(pRoot -> left,k);
            if(node != NULL)
                return node;
            index++;
            if(index == k)
                return pRoot;
            node = KthNode(pRoot -> right ,k );
            if(node != NULL)
                return node;
        }
        return NULL;
    }

    TreeNode* KthNode1(TreeNode* pRoot, int k)//非递归实现
    {
        if(pRoot == NULL || k == 0)
            return NULL;
        stack<TreeNode *> Stack;
        int count = 0;
        TreeNode *node = pRoot;
        
        do
        {
            if(node != NULL)
            {
                Stack.push(node);
                node = node -> left;
            }
            else
            {
                node = Stack.top();
                Stack.pop();
                count++;
                if(count == k)
                    return node;
                node = node -> right;

            }
        }while(node != NULL || !Stack.empty());
        return NULL;
    }

    
};
