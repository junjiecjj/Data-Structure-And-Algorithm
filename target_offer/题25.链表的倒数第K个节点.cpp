/*************************************************************************
>> File Name: 链表的倒数第K个节点.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.31

题目描述
输入一个链表，输出该链表中倒数第k个结点。
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
    {
        if( pListHead == NULL || k == 0 )
            return NULL;
        ListNode *ptr1 = pListHead;
        ListNode *ptr2 = pListHead;
        for(int i = 0; i < k; i++)
        {
            if(ptr1 != NULL)
                ptr1 = ptr1 -> next;
            else
                return NULL;
        }
        while(ptr1 != NULL)
        {
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }
        return ptr2;
    }
};
