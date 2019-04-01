/*************************************************************************
>> File Name: 复杂链表的复制.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.04.01

题目描述
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
************************************************************************/

#include<iostream>
using namespace std;


struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL)
            return NULL;
        RandomListNode *cur = pHead;
        while(cur)
        {
            RandomListNode *node = new RandomListNode(cur -> label);
            node -> next = cur -> next;
            cur -> next = node;
            cur = node -> next;
        }
        cur = pHead;
        RandomListNode *ptr;
        while(cur != NULL)
        {
            ptr = cur -> next;
            if(cur -> random != NULL)
                ptr -> random = cur -> random -> next;
            cur = ptr -> next;
        }
        RandomListNode *newHead = pHead -> next;
        RandomListNode *tmp;
        cur = pHead;
        while(cur -> next)
        {
            tmp = cur -> next;
            cur -> next = tmp -> next;
            cur = tmp;
        }
        return newHead;

    }
};
