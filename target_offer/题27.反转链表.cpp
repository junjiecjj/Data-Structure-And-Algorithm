/*************************************************************************
>> File Name: 反转链表.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.31

题目描述
输入一个链表，反转链表后，输出新链表的表头。
************************************************************************/

#include<iostream>
using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};


class Solution {
public:
    ListNode* ReverseList(ListNode* pHead)
    {
        ListNode *pre = NULL;
        ListNode *current = pHead;
        ListNode *Next = NULL;
        while(current != NULL)
        {
            Next = current -> next;
            current -> next = pre;
            pre = current;
            current = Next;
        }
        return pre;
    }
};
