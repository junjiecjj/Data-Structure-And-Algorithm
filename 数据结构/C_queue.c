/*************************************************************************
>> File Name: 队列.c
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.07
************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct NODE
{
    int value;
    struct NODE *next;
} Node;

typedef struct QUEUE
{
    Node *head;
    Node *tail;
    int num;
} Queue;

bool QueueInitial(Queue *queue)
{
    queue -> head = NULL;
    queue -> tail = NULL;
    queue -> num = 0;
}

bool QueueIsFull(const Queue *queue)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if(node == NULL)
        return true;
    else
        return false;
}

bool QueueIsEmpty(const Queue *queue)
{
    if(queue -> num == 0)
        return true;
    else
        return false;
}

bool enqueue(Queue *queue,int value)
{
    Node  *node = (Node *)malloc(sizeof(Node));
    if(node == NULL)
    {
        printf("没有足够内存");
        return false;
    }
    node -> value = value;
    node -> next =NULL;

    if(queue -> head == NULL)
    {
        queue -> head = node;
    }
    else
    {
        queue -> tail -> next = node;
    }
    queue -> tail = node;
    queue -> num ++;
    return true;
}

bool dequeue(int *x, Queue *queue)
{
    Node *node;
    if(queue -> head == NULL)
        return false;

    node = queue -> head;
    *x = node -> value;
    queue -> head = queue -> head -> next;
    free(node);
    queue -> num --;
    if(queue -> num ==0)
        queue -> tail = NULL;
    return true;
}


bool Dequeue(int *x,Queue *queue)
{
    Node *node;
    if(queue -> num == 0)
        return false;
    else if(queue -> num == 1)
    {
        *x = queue -> head -> value;
        queue -> head = NULL;
        queue -> tail = NULL;
        queue -> num = 0;
        return true;
    }
    else
    {
        node = queue -> head;
        *x = node -> value;
        queue -> head = queue -> head -> next;
        free(node);
        queue -> num --;
        return true;

    }
}

void showNode(const Node *node)
{
    printf("%d\n",node->value);
}

void Traverse(const Queue *queue,void (*pfun)(const Node *node))
{
    Node * pr = queue -> head;
    while(pr != NULL)
    {
        (*pfun)(pr);
        pr = pr -> next;
    }
    printf("\n");
}

int main(int argc,char *argv[])
{
    Queue *myque = (Queue *)malloc(sizeof(Queue));
    QueueInitial(myque);
    enqueue(myque, 1);
    enqueue(myque, 2);
    enqueue(myque, 3);
    enqueue(myque, 4);
    Traverse(myque,&showNode);
    int *a = (int *)malloc(sizeof(int));
    dequeue(a,myque);
    printf("a = %d, queue has %d node\n",*a,myque -> num);
    dequeue(a,myque);
    printf("a = %d, queue has %d node\n",*a,myque -> num);
    dequeue(a,myque);
    printf("a = %d, queue has %d node\n",*a,myque -> num);
    dequeue(a,myque);
    printf("a = %d, queue has %d node\n",*a,myque -> num);
    int *b = (int *)malloc(sizeof(int));
    dequeue(b,myque);
    printf("b = %d, queue has %d node\n",*b,myque -> num);
    return 0;

}

