/*************************************************************************
>> File Name: 从上到下打印二叉树.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.22


题目描述
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
************************************************************************/

#include<iostream>
using namespace std;
#include<vector>
#include<queue>

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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> result;
        if(root == nullptr)
            return result;
        else
        {
            TreeNode *ptr;
            queue<TreeNode *> Queue;
            Queue.push(root);
            while(!Queue.empty())
            {
                ptr = Queue.front();
                Queue.pop();
                result.push_back(ptr -> val);
                if(ptr -> left != NULL)
                    Queue.push(ptr-> left);
                if(ptr -> right != NULL)
                    Queue.push(ptr -> right);
            }
        }
        return result;

    }
};
