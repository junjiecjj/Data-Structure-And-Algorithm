/************************************************************
>> File Name: 重建二叉树.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.21

题目描述
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*********************************************************/

#include<iostream>
using namespace std;
#include<vector>


 //Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int len = vin.size();               //这三行代码一定要在这里，不能在后面，否则递归无法结束
        if(len == 0)
            return NULL;

        TreeNode *Root = new TreeNode(pre[0]);
        vector<int> preLeft;
        vector<int> preRight;
        vector<int> InLeft;
        vector<int> InRight;
        int locate = 0;
        //int len = vin.size();              //这三行代码不能放在这里，只能出现在最开始，否则递归无法结束
        //if(len == 0)
        //    return NULL;
        for(int i = 0; i < len; i++)
        {
            if(vin[i] == pre[0])
            {
                locate = i;
                break;
            }
        }
        for(int i = 0; i < locate; i++)
        {
            InLeft.push_back(vin[i]);
            preLeft.push_back(pre[i+1]);
        }
        for(int i = locate+1; i < len; i++)
        {
            InRight.push_back(vin[i]);
            preRight.push_back(pre[i]);
        }
        Root -> left = reConstructBinaryTree(preLeft,InLeft);
        Root -> right = reConstructBinaryTree(preRight,InRight);
        return Root;
    }
};

int main()
{
    return 0;
}
