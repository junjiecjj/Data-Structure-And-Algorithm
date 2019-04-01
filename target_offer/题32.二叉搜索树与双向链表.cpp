/*************************************************************************
>> File Name: 二叉搜索树与双向链表.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.04.01

题目描述
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
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


class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode *pList = NULL;
        preorder(pRootOfTree,&pList);
        return pList;
    }
    void preorder(TreeNode *pRootOfTree,TreeNode **pList)
    {
        if(pRootOfTree == NULL)
            return;
        if(pRootOfTree -> right != NULL)
            preorder(pRootOfTree -> right, pList);

        pRootOfTree -> right = *pList;

        if(*pList != NULL)
            (*pList) -> left = pRootOfTree;

        *pList = pRootOfTree;
        if(pRootOfTree -> left != NULL)
            preorder(pRootOfTree -> left,pList);
    }
};
