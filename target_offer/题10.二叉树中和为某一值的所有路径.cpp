/*************************************************************************
>> File Name: 二叉树中和为某一值的所有路径.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.22



题目描述
输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)
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
    vector<vector<int>> buffer;
    vector<int> tmp;

    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root == nullptr)
            return buffer;
        tmp.push_back(root -> val);
        if(expectNumber - root -> val == 0 && root -> left == NULL && root -> right == NULL)
        {
            buffer.push_back(tmp);
        }
        FindPath(root -> left, expectNumber- root -> val);
        FindPath(root -> right, expectNumber - root -> val);
        if(tmp.size() != 0)
            tmp.pop_back();
        return buffer;
    }
};
