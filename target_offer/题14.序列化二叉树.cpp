/*************************************************************************
>> File Name: 序列化二叉树.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.24

题目描述
请实现两个函数，分别用来序列化和反序列化二叉树
************************************************************************/

#include<iostream>
using namespace std;
#include<string>
#include<cstring>
#include<vector>
#include<queue>
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

    private:
    TreeNode* deserialize(char *&str)//str是字符指针的引用,这里必须用引用，因为在函数里得逐步后移指针,即需要改变指针
    {
        if(*str == '#')
        {
            str++;
            return NULL;
        }
        int num = 0;
        while(*str != ',')
        {
            num = num * 10 + (*(str++) - '0');
        }
        str++;
        TreeNode *root  = new TreeNode(num);
        root -> left = deserialize(str);
        root -> right = deserialize(str);
        return root;
    }
    public:
        char* Serialize(TreeNode *root)
        {
            if(!root)
                return "#";
            string S = to_string(root -> val);
            S.push_back(',');
            char *left = Serialize(root -> left);
            char *right = Serialize(root -> right);
            char *res = new char[strlen(left) + strlen(right) + S.size()];      //求指针型的字符串或字符数组只能用strlen(char *),求string类对象的长度
            strcpy(res,S.c_str());                                              //用str.size()
            strcat(res, left);
            strcat(res,right);
            return res;
        }

        TreeNode* Deserialize(char *str)
        {
            return deserialize(str);
        }
};
