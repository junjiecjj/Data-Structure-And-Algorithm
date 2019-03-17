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
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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


void addFormHead(List *list,int value)//从链表头部添加数据
{
    Node *node = (Node *)malloc(sizeof(Node));
    if(node == NULL)
    {
        printf("无法分配内存，链表已满...\n");
        return;
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
}

void showNode(const Node *node)
{
    printf("%d\n",node->value);
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

bool addFromEnd(List *list,int value)//在链表尾部添加节点
{
    Node *node = (Node *)malloc(sizeof(Node));
    if(node == NULL)
        return false;
    node -> value = value;
    node -> next = NULL;
    Node *pr = list -> head;

    if(list -> head == NULL)
        list -> head = node;
    else
    {
        while(pr -> next != NULL)
            pr = pr -> next;
    }

    pr -> next = node;
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

int main(int argc,char *argv[])
{
    List *myList = (List *)malloc(sizeof(myList));
    Initialize( myList);
    addFormHead( myList, 1);
    addFormHead( myList, 2);

    addFromEnd( myList, 5);
    addFromEnd( myList, 6 );

    getListNodeNum( myList);
    Traverse(myList,&showNode);

    reverseList(myList);
    Traverse(myList,&showNode);
    printf("\n");

    myList -> head = reverseListRecurse(myList -> head);
    Traverse(myList,&showNode);
    printf("\n");

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
    Traverse(myList,&showNode);

    //emptyList( myList );
    getListNodeNum( myList);
    return 0;
}
