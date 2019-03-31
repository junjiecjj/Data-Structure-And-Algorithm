/*************************************************************************
>> File Name: 树的子结构.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.31

题目描述
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(!pRoot1 || !pRoot2)
            return false;
        return sametree(pRoot1,pRoot2) || HasSubtree(pRoot1 -> left,pRoot2) || HasSubtree(pRoot1 -> right,pRoot2);
    }

    bool sametree(TreeNode *pt1, TreeNode *pt2)
    {
        if(!pt2)
            return true;
        if(!pt1)
            return false;
        if(pt1 -> val != pt2 -> val)
            return false;
        return sametree(pt1 -> left,pt2 -> left) && sametree(pt1 -> right,pt2 -> right);
    }
};
