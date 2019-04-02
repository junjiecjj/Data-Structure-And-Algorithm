/*************************************************************************
>> File Name: 链表中环的入口节点.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.04.02

题目描述
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
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

class Solution
{
    public:
        ListNode * getMeetingNode(ListNode *pHead)//判断链表是否有环
        {
            ListNode *fast = pHead;
            ListNode *slow = pHead;
            while(slow != NULL && fast -> next!= NULL)
            {
                slow = slow -> next;
                fast = fast -> next -> next;
                if(fast == slow)
                    return slow;
            }
            return NULL;
        }
        ListNode* EntryNodeOfLoop(ListNode* pHead)
        {
            ListNode *meet = getMeetingNode(pHead);
            if(meet == NULL)
                return NULL;
            ListNode *pt1 = meet;
            ListNode *pt2 = pHead;
            while(pt1 != pt2)
            {
                pt1 = pt1 -> next;
                pt2 = pt2 -> next;
            }
            return pt1;
        }
};
