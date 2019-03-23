/*************************************************************************
>> File Name: 按之字形顺序打印二叉树.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.23


题目描述
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，
第三行按照从左到右的顺序打印，其他行以此类推。
************************************************************************/

#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

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
        bool flag = false;
        while(!Queue.empty())
        {
            vector<int> vec;
            int size = Queue.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode *tmp = Queue.front();
                vec.push_back(tmp -> val);
                Queue.pop();
                if(tmp -> left != nullptr)
                    Queue.push(tmp -> left);
                if(tmp -> right != nullptr)
                    Queue.push(tmp -> right);
            }
            if(flag)
                reverse(vec.begin(),vec.end());
            result.push_back(vec);
            flag = !flag;
        }
        return result;
    }
    vector<vector<int> > Print1(TreeNode* pRoot) {

        vector<vector<int>> result;
        if(pRoot == nullptr)
            return result;
        stack<TreeNode *> tmp[2];
        int current = 0;
        int Next = 1;
        tmp[current].push(pRoot);
        vector<int> vec;
        while(!tmp[current].empty() || !tmp[Next].empty())
        {
            TreeNode *ptr = tmp[current].top();
            tmp[current].pop();
            vec.push_back(ptr -> val);
            if(current == 0)
            {
                if(ptr -> left != NULL)
                    tmp[Next].push(ptr -> left);
                if(ptr -> right != NULL)
                    tmp[Next].push(ptr -> right);
            }
            if(current == 1)
            {
                if(ptr -> right != NULL)
                    tmp[Next].push(ptr -> right);
                if(ptr -> left != NULL)
                    tmp[Next].push(ptr -> left);
            }
            if(tmp[current].empty())
            {
                result.push_back(vec);
                vec.clear();
                current = 1 - current;
                Next = 1 -Next;
            }
        }
        return result;
    }
};
