/*************************************************************************
>> File Name: 合并两个排序的链表.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.31

题目描述
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* pTail = NULL;//指向新链表的最后一个结点 pTail->next去连接
    
        ListNode* newHead = NULL;//指向合并后链表第一个结点
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        if (p1 == NULL)
        {
            return p2;
        }
        else if(p2 == NULL)
        {
            return p1;
        }
        else
        {
            //确定头指针
            if ( p1-> val < p2->val)
            {
                newHead = p1;
                p1 = p1->next;//指向链表的第二个结点
            }
            else
            {
                newHead = p2;
                p2 = p2->next;
            }
            pTail = newHead;//指向第一个结点
            while ( p1 && p2)
            {
                if ( p1->val < p2->val )
                {
                    pTail->next = p1;
                    p1 = p1->next;
                }
                else
                {
                    pTail->next = p2;
                    p2 = p2->next;
                }
                pTail = pTail->next;

            }
            if(p1 == NULL)
            {
                pTail->next = p2;
            }
            else if(p2 ==  NULL)
            {
                pTail->next = p1;
            }
            return newHead;
        }
    }
};
