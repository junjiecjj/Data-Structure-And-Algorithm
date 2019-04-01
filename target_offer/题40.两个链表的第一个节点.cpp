/*************************************************************************
>> File Name: 两个链表的第一个公共节点.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.04.01

题目描述
输入两个链表，找出它们的第一个公共结点。
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
        ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2)
        {
            ListNode *pt1 = pHead1;
            ListNode *pt2 = pHead2;
            int len1 = 0;
            int len2 = 0;
            int diff = 0;
            while(pt1)
            {
                ++len1;
                pt1 = pt1 -> next;
            }

            while(pt2)
            {
                ++len2;
                pt2 = pt2 -> next;
            }
            if(len1 > len2)
            {
                diff = len1 - len2;
                pt1 = pHead1;
                pt2 = pHead2;
            }
            else
            {
                diff = len2 -len1;
                pt1 = pHead2;
                pt2 = pHead1;
            }

            for(int i = 0; i < diff; ++i)
            {
                pt1 = pt1 -> next;
            }

            while(pt1 != NULL && pt2 != NULL)
            {
                if(pt1 == pt2)
                    break;
                pt1 = pt1 -> next;
                pt2 = pt2 -> next;
            }
            return pt1;
        }
};
