/*************************************************************************
>> File Name: 把二叉树打印成多行.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.23


题目描述
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
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
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>> result;
            if(pRoot == nullptr)
                return result;
            queue<TreeNode *> Queue;
            Queue.push(pRoot);
            vector<int> vec;
            while(!Queue.empty())
            {
                int size = Queue.size();
                for(int i = 0; i < size; i++)
                {
                    TreeNode *ptr = Queue.front();
                    Queue.pop();
                    vec.push_back(ptr -> val);
                    if(ptr -> left != nullptr)
                        Queue.push(ptr -> left);
                    if(ptr -> right != nullptr)
                        Queue.push(ptr -> right);
                }
                result.push_back(vec);
                vec.clear();
            }
            return result;    
        }
    
};
