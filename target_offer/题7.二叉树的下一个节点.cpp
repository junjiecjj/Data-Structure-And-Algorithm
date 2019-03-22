/*************************************************************************
>> File Name: 二叉树的下一个节点.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.21


题目描述
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
************************************************************************/

#include<iostream>
using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;                  //当前节点的父节点
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == NULL)
            return NULL;
        TreeLinkNode *ptr = pNode;
        if(ptr -> right != NULL)
        {
            ptr = ptr -> right;
            while(ptr -> left != NULL)
            {
                ptr = ptr -> left;
            }
        }
        else
        {
            while(ptr -> next != NULL && ptr == ptr -> next -> right)
                ptr = ptr -> next;
            ptr = ptr -> next;
        }
        return ptr;
    }
}
