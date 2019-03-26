/*************************************************************************
>> File Name: 链表.c
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.01.22
************************************************************************/
/*
这是以下结构的链表，只含有头结点和节点数的链表

typedef struct List_Node
{
    int value;
    struct List_Node  *next;
}Node;

typedef struct LIST
{
    Node *head;
    int num;
}List;

 */
#include<iostream>
using namespace std;
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstdbool>
#include<stack>
#include<queue>

typedef struct List_Node
{
    int value;
    struct List_Node  *next;
}Node;

typedef struct LIST
{
    Node *head;
    int num;
}List;

void Initialize(List *list)//初始化链表
{
    list-> head = NULL;
    list-> num = 0;
}

bool ListIsFull(const List *list)//判断链表是否已满
{
    Node *node = (Node *)malloc(sizeof(Node));
    bool full;
    if(node== NULL)
        full = true;
    else
        full = false;
    free(node);
    node = NULL;
    return full;
}

bool ListIsEmpty(const List *list)//判断链表是否为空
{
    if(list -> head == NULL)
        return true;
    else
        return false;
}


void showNode(const Node *node)
{
    printf("%d  ",node->value);
}

void Traverse(const List *list, void(*pfun)(const Node *node))//以函数*pfun遍历链表的每个节点
{
    const Node *node = list-> head;
    while(node != NULL)
    {
        (*pfun)(node);
        node = node -> next;
    }
    printf("\n");
}

void Traverse1( Node *pHead, void(*pfun)(const Node *node))//以函数*pfun遍历链表的每个节点
{
    Node *node = pHead;
    while(node != NULL)
    {
        (*pfun)(node);
        node = node -> next;
    }
    printf("\n");
}

bool addFromHead(List *list,int value)//从链表头部添加数据
{
    Node *node = (Node *)malloc(sizeof(Node));
    if(node == NULL)
    {
        printf("无法分配内存，链表已满...\n");
        return false;
    }
    node->value = value;
    if(list -> head == NULL)
    {
        node->next = NULL;
        list -> head = node;

    }
    else
    {
        node -> next = list -> head;
        list->head = node;
    }

    list -> num ++;
    return true;
}

bool addFromEnd(List *list,int value)//在链表尾部添加节点
{
    Node *node = (Node *)malloc(sizeof(Node));
    Node *pr = list -> head;
    if(node == NULL)
        return false;
    node -> value = value;
    node -> next = NULL;

    if(pr == NULL)
        list -> head = node;
    else
    {
        while(pr -> next != NULL)
            pr = pr -> next;
        pr -> next = node;
    }

    list -> num ++;
    return true;
}

void getListNodeNum(const List *list)//计算链表节点数量
{
    int num = list -> num;
    printf("List has %d nodes\n",num);
}

int * deleteFromHead(List *list)//从头部删除链表的节点
{
    int *data = (int *)malloc(sizeof(int));
    Node *pr ;
    if(list -> head == NULL)
        data = NULL;
    else
    {
        *data = list -> head -> value;
        pr = list -> head -> next;
        free(list -> head);
        list -> head = pr;
    }
    list -> num --;
    return data;
}

void deleteFromEnd(List *list,int *x)//从链表尾部删除节点
{
    Node *pr = list -> head;
    if(list -> head == NULL)
        return;
    else
    {
        if(list -> head -> next == NULL)
        {
            *x = list->head->value;
            list->head = NULL;
        }
        else
        {
            while(pr->next->next != NULL)
            {
                pr = pr ->next;
            }
            *x = pr->next->value;
            free(pr->next);
            pr->next = NULL;
        }
        list -> num --;

    }
}

void emptyList(List *list)//清空链表
{
    Node *pr = (Node *)malloc(sizeof(Node));
    while(list-> head != NULL)
    {
        pr = list -> head -> next;
        free(list-> head);
        list -> head = pr;
        list -> num --;
    }
}

void reverseList(List *list)//反转链表：循环实现
{
    Node *next = NULL;
    Node *node = list -> head;
    Node *pre = NULL;
    while(node != NULL)
    {
        next = node -> next;
        node -> next = pre;
        pre = node;
        node  = next;
    }
    list -> head = pre;
}

Node *reverseListRecurse(Node *node)//反转链表:递归实现
{
    if(node == NULL || node -> next == NULL)
        return node;
    else
    {
        Node *tmpNode = reverseListRecurse(node -> next);
        node -> next -> next = node;
        node -> next = NULL;
        return tmpNode;
    }
}

Node * findKthTail1(Node *node,int k)//输出单链表的倒数第K个节点,递归实现
{
    static int num;
    num = k;
    if(node == NULL)
        return NULL;
    Node *ptr = findKthTail1(node -> next,k);
    if(ptr != NULL)
        return ptr;
    else
    {
        num--;
        if(num == 0)
            return node;
        return NULL;
    }
}

Node * findKthTail2(Node *pHead,int k)//输出单链表的倒数第K个节点,双指针实现
{
    if(pHead == NULL || k == 0)
        return NULL;
    Node *pt1 = pHead;
    Node *pt2 = pHead;
    for(int i = 0; i < k; i++)
    {
        if(pt1)
            pt1 = pt1 -> next;
        else
            return NULL;
    }
    while(pt1)
    {
        pt1 = pt1 -> next;
        pt2 = pt2 -> next;
    }
    return pt2;
}

bool IsExistLoop(Node *pHead)//判断链表是否有环
{
    Node *fast = pHead;
    Node *slow = pHead;
    while(slow != NULL && fast -> next!= NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(fast == slow)
            return true;
    }
    return false;
}

Node * getMeetingNode(Node *pHead)//判断链表是否有环
{
    Node *fast = pHead;
    Node *slow = pHead;
    while(slow != NULL && fast -> next!= NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(fast == slow)
            return slow;
    }
    return NULL;
}

Node *getEntryNodeofLoop(Node  *pHead)//得到环的入口节点
{
    Node *meet = getMeetingNode(pHead);
    if(meet == NULL)
        return NULL;
    Node *pt1 = meet;
    Node *pt2 = pHead;
    while(pt1 != pt2)
    {
        pt1 = pt1 -> next;
        pt2 = pt2 -> next;
    }
    return pt1;
}

int getLoopLength(Node* head){//计算环的长度
    Node* slow = head;
    Node* fast = head;
    while ( fast && fast->next ){
        slow = slow->next;
        fast = fast->next->next;
        if ( slow == fast )//第一次相遇
            break;
    }
    //slow与fast继续前进
    slow = slow->next;
    fast = fast->next->next;
    int length = 1;       //环长度
    while ( fast != slow )//再次相遇
    {
        slow = slow->next;
        fast = fast->next->next;
        length ++;        //累加
    }
    //当slow与fast再次相遇，得到环长度
    return length;
}


Node* MergeOrderList1(Node* pHead1, Node* pHead2)//会改变原来要合并的两个链表
{
    Node* pTail = NULL;//指向新链表的最后一个结点 pTail->next去连接
    Node* newHead = NULL;//指向合并后链表第一个结点
    Node *p1 = pHead1;
    Node *p2 = pHead2;
    if (p1 == NULL)
    {
        return p2;
    }
    else if(p2 == NULL)
    {
        return p1;
    }else
    {
        //确定头指针
        if ( p1-> value < p2->value)
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
            if ( p1->value < p2->value )
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


Node* MergeOrderList2(Node* pHead1, Node* pHead2){//会改变原来要合并的两个链表
    if (pHead1 == NULL)
    {
        return pHead2;
    }
    else if(pHead2 == NULL)
    {
        return pHead2;
    }
    Node* newHead = NULL;
    if (pHead1->value <= pHead2->value)
    {
        newHead = pHead1;
        newHead->next = MergeOrderList2(pHead1->next, pHead2);
    }
    else
    {
        newHead = pHead2;
        newHead->next = MergeOrderList2(pHead1, pHead2->next);
    }
        return newHead;
}


void deleteNode(List *list, Node *pDeleteNode)//删除节点,以时间复杂度O(1)完成
{
    if(pDeleteNode == NULL)
        return;

    if(pDeleteNode -> next != NULL)
    {
        Node *pNext = pDeleteNode -> next;
        pDeleteNode -> value= pNext -> value;
        pDeleteNode -> next = pNext -> next;
        delete pNext;
        pNext = nullptr;
    }
    else if(list -> head == pDeleteNode)
    {
        delete pDeleteNode;
        pDeleteNode = nullptr;
        list -> head = nullptr;
    }
    else
    {
        Node *ptr = list -> head;
        while(ptr -> next != pDeleteNode)
            ptr = ptr -> next;
        ptr -> next = NULL;
        delete pDeleteNode;
        pDeleteNode = NULL;
    }
}

vector<int> printListformTailtoHead1(List *list)//从尾到头打印链表,非递归实现
{
    vector<int> result;
    Node *ptr = list -> head;
    stack<int> Stack;
    while(ptr != NULL)
    {
        Stack.push(ptr -> value);
        ptr = ptr -> next;
    }

    while(!Stack.empty())
    {
        result.push_back(Stack.top());
        Stack.pop();
    }
    return result;
}

vector<int> printListformTailtoHead2(Node *pHead)//从尾到头打印链表,递归实现
{
    static vector<int> REsult;
    Node *pt = pHead;
    if(pt != NULL)
    {
        if(pt -> next != NULL)
            printListformTailtoHead2(pt -> next);
        REsult.push_back(pt -> value);
    }
    return REsult;
}



int main(int argc,char *argv[])
{
    List *myList = (List *)malloc(sizeof(List));
    //List myList;

    bool flag;
    Initialize( myList);
    addFromEnd( myList, 1);
    addFromEnd( myList, 3);
    addFromEnd( myList, 5);
    addFromEnd( myList, 7);
    addFromEnd( myList, 9);
    addFromEnd( myList, 11);
    addFromEnd( myList, 13);
    addFromEnd( myList, 15);

    getListNodeNum( myList);
    Traverse(myList,&showNode);
    cout << endl;

    printf("反转链表，非递归实现\n");
    reverseList(myList);
    getListNodeNum( myList);
    Traverse(myList,&showNode);
    cout << '\n';

    cout << "反转链表,递归实现\n";
    myList -> head = reverseListRecurse(myList -> head);
    getListNodeNum( myList);
    Traverse(myList,&showNode);
    cout << '\n';

    Node *ptr1 = findKthTail1(myList -> head,3);
    printf("倒数第三个节点为:%d\n",ptr1 -> value);

    Node *ptr2 = findKthTail2(myList -> head,3);
    printf("倒数第三个节点为:%d\n",ptr2 -> value);

    printf("删除头部两个和尾部最后两个元素\n");
    int *a;
    a = deleteFromHead( myList);
    int *b;
    b = deleteFromHead(myList);
    int c;
    deleteFromEnd( myList,&c);
    int d;
    deleteFromEnd(myList, &d);

    printf("a = %d,b = %d,c = %d,d = %d\n",*a,*b, c ,d);
    printf("\n");
    getListNodeNum( myList);
    Traverse(myList,&showNode);
    printf("\n");

    //emptyList( myList );

    cout << "逆序打印链表,非递归实现" << endl;
    vector<int> Result = printListformTailtoHead1(myList);
    for(auto i : Result)
    {
        cout << i << "  ";
    }
    cout << "\n\n";

    getListNodeNum( myList);
    Traverse(myList,&showNode);
    cout << endl;

    List *myList1 = (List *)malloc(sizeof(myList));
    Initialize( myList1);
    addFromEnd( myList1, 2);
    addFromEnd( myList1, 4);
    addFromEnd( myList1, 6);
    addFromEnd( myList1, 8);
    addFromEnd( myList1, 10);
    addFromEnd( myList1, 12);
    addFromEnd( myList1, 14);
    addFromEnd( myList1, 16);
    getListNodeNum( myList1);
    Traverse(myList1,&showNode);
    printf("\n");

    List *myList_copy = myList;

    printf("合并链表，非递归实现\n");
    Node *MergeList = MergeOrderList1(myList -> head, myList1 -> head);
    Traverse1(MergeList,&showNode);
    cout << '\n';

    Traverse(myList_copy,&showNode);
    Traverse(myList1,&showNode);

    cout << "逆序打印链表,递归实现" << endl;
    vector<int> REsult;
    REsult = printListformTailtoHead2(MergeList);
    for(auto i : REsult)
    {
        cout << i << "  ";
    }
    cout << endl;
/*
    printf("合并链表，递归实现\n");
    Node *MergeList1 = MergeOrderList2(myList -> head, myList1 -> head);
    Traverse1(MergeList1,&showNode);
    cout << '\n';

    Traverse(myList,&showNode);
    Traverse(myList1,&showNode);

    cout << "逆序打印链表,递归实现" << endl;
    vector<int> RESult;
    RESult = printListformTailtoHead2(MergeList1);
    for(auto i : RESult)
    {
        cout << i << "  ";
    }
    cout << endl;
*/
    return 0;
}

/*
输出为:
List has 8 nodes
1  3  5  7  9  11  13  15

反转链表，非递归实现
List has 8 nodes
15  13  11  9  7  5  3  1

反转链表,递归实现
List has 8 nodes
1  3  5  7  9  11  13  15

倒数第三个节点为:11
倒数第三个节点为:11
删除头部两个和尾部最后两个元素
a = 1,b = 3,c = 15,d = 13

List has 4 nodes
5  7  9  11

逆序打印链表,非递归实现
11  9  7  5

List has 4 nodes
5  7  9  11

List has 8 nodes
2  4  6  8  10  12  14  16

合并链表，非递归实现
2  4  5  6  7  8  9  10  11  12  14  16

5  6  7  8  9  10  11  12  14  16
2  4  5  6  7  8  9  10  11  12  14  16
逆序打印链表,递归实现
16  14  12  11  10  9  8  7  6  5  4  2

*/
