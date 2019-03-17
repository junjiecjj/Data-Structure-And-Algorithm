/*************************************************************************
>> File Name: 栈.c
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.08
************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXQUEUE  100


typedef struct NODE
{
    int value;
    struct NODE *next;
}Node;

typedef struct STACK
{
    Node *head;
    Node *tail;
    int num;
}Stack;

void stackInitial(Stack *stack)//初始化
{
    stack -> head = NULL;
    stack -> tail = NULL;
    stack -> num = 0;
}

bool StackIsFull(const Stack *stack)//判断栈是否已满
{
    return  stack -> num ==100;
}

bool StackIsEmpty(const Stack *stack)//判断栈是否为空
{
    return stack -> num == 0;
}

bool push(Stack *stack,int x)//向栈添加元素
{
    Node *node = (Node *)malloc(sizeof(Node));
    if(node == NULL)
        return false;
    node -> value = x;
    if(stack -> head == NULL)
    {
        node -> next = NULL;
        stack -> tail = node;
    }
    else
    {
        node -> next = stack -> head;
    }
    stack -> head = node;
    stack -> num ++;
    return true;
}

int * pop(Stack *stack)//删除栈尾部元素
{
    int *data = (int *)malloc(sizeof(int));
    Node *node = stack -> head;
    if(node == NULL)
        return NULL;
    else if(node == stack -> tail)
    {
        *data = node -> value;
        stack -> head = stack -> tail = NULL;
        free(node);
    }
    else
    {
        *data = node -> value;
        stack -> head = stack -> head -> next;
        free(node);
    }
    stack -> num --;
    return data;
}

void showNode(const Node *node)
{
    printf("%d\n",node->value);
}

void Traverse(const Stack *stack,void (*pfun)(const Node *node))//遍历栈
{
    Node * pr = stack -> head;
    while(pr != NULL)
    {
        (*pfun)(pr);
        pr = pr -> next;
    }
    printf("\n");
}
/*
int main(int argc, char *argv[])
{
    Stack *mystack = (Stack *)malloc(sizeof(Stack));
    push(mystack,1);
    push(mystack,2);
    push(mystack,3);
    push(mystack,4);
    push(mystack,5);
    printf("mystack has %d node\n",mystack -> num);
    Traverse(mystack,&showNode);
    int *a ;//= (int *)malloc(sizeof(int));
    a = pop(mystack);
    printf("a = %d, mystack has %d node\n",*a,mystack -> num);
    return 0;

}
*/
