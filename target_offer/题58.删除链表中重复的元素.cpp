/*************************************************************************
>> File Name: 删除链表中重复的节点.cpp
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.04.02

题目描述
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
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
        ListNode* deleteDuplication(ListNode* pHead)
        {
            if( pHead == NULL ) return pHead;
 
            ListNode *pre = NULL; //指向前面最晚访问过的不重复结点
            ListNode *p = pHead; //指向当前处理的结点
        ListNode *q = NULL; //指向当前处理结点后面结点
 
        while( p != NULL )
        {
            //当前结点p，（其实是p指向当前结点），与它下一个结点p->next的val相同，说明要删掉有这个val的所有结点
            if( p->next != NULL && p->next->val == p->val )
            {
                q = p->next;
 
                //找到q，它指向最后一个与p val相同的结点，那p 到 q （包含） 都是要删除的
                while( q != NULL && q->next != NULL && q->next->val == p->val )
                {
                    q = q->next;
                }
 
                //如果p指向链表中第一个元素，p -> ... -> q ->... , 要删除p到q, 将指向链表第一个元素的指针pHead指向q->next。
                if( p == pHead )
                {
                    pHead = q->next;
                }
                else//如果p不指向链表中第一个元素，pre -> p ->...->q ->... ，要删除p到q，即pre->next = q->next
                {
                    pre->next = q->next;
                }
                //当前处理的p要向链表尾部移动
                p = q->next;
            }
            else
            {
                pre = p;
                p = p->next;
            }
        }
        return pHead;
    }
 
};
