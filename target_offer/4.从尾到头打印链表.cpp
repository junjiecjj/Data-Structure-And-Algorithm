/*************************************************************************
>> File Name: 从尾到头打印链表.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.21

题目描述
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
************************************************************************/

#include<iostream>
using namespace std;
#include<vector>
#include<stack>

struct ListNode 
{
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result;
        stack<int> Stack;
        ListNode *pr = head;
        while(pr != NULL)
        {
            Stack.push(pr -> val);
            pr = pr -> next;
        }
        //int len = Stack.size();
        while(!Stack.empty())
        {
            result.push_back(Stack.top());
            Stack.pop();
        }
        return result;
    }
};
