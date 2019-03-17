/*************************************************************************
>> File Name: 树.c
>> Author: chenjunjie
>> Mail: 2716705056qq.com
>> Created Time: 2019.03.08
************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXTREENODE  100


typedef struct BTreeNode
{
    int value;
    struct BTreeNode *left;
    struct BTreeNode *right;
}Node;

typedef struct BTree
{
    Node *Root;
    int size;
}Tree;

typedef struct PAIR
{
    Node *parent;
    Node *child;
}Pair;

void TreeInitial(Tree *tree)//初始化
{
    tree -> Root = NULL;
    tree -> size = 0;
}

bool TreeIsFull(const Tree *tree)//判断树是否已满
{
    return tree -> size <= MAXTREENODE? false : true ;
}

bool TreeIsEmpty(const Tree *tree)//判断树是否为空
{
    return tree -> size ==0;
}

bool Insert(Tree *tree, int value)//二插搜索树插入节点,循环实现
{
    Node *node = (Node *)malloc(sizeof(Node));
    if(node == NULL)
        return false;
    node -> value = value;
    node -> left = NULL;
    node -> right = NULL;
    tree -> size ++;
    Node *tmp = tree -> Root;
    if(tree -> Root == NULL)
    {
        tree -> Root = node;
        return true;
    }
    else
    {
        while(tmp != NULL)
        {
            if(value > tmp -> value)
            {
                if(tmp -> right == NULL)
                {
                    tmp -> right = node;
                    return true;
                }
                else
                {
                    tmp = tmp -> right;
                }
            }
            else
            {
                if(tmp -> left == NULL)
                {
                    tmp -> left = node;
                    return true;
                }
                else
                    tmp = tmp -> left;
            }

        }
    }
}

Node *CreatBitTree()//递归前序建立二叉树(一般二叉树，不一定是搜索树)
{
    int x;
    Node *pr;
    scanf("%d",&x);
    if(x < 0)
    {
        b = NUL;
    }
    else
    {
        pr = (Node *)malloc(sizeof(Node));
        pr -> value = x;
        b ->left = CreatBitTree();
        b - >right = CreatBitTree();
    }

    return b;
}


void show(int value)
{
    printf("%d  ",value);
}

void PreOrder(Node *node,void (*pfun)(int value))//先序遍历，递归实现
{
    if(node != NULL)
    {
        (*pfun)(node -> value);
        PreOrder(node -> left,pfun);
        PreOrder(node -> right,pfun);
    }
    else
        printf("#  ");
}

void PreOrderNoRecurse1(Node *Root)//先序遍历，非递归实现，版本一
{
    Node *stack[MAXTREENODE];//stack保留的是未打印的节点
    int top = -1;
    Node *p = NULL;
    if(Root != NULL)
    {
        top++;
        stack[top] = Root;
        while(top > -1)
        {
            p = stack[top];
            top --;
            printf("%d  ",p -> value);
            if( p -> right != NULL)
            {
                top ++;
                stack[top] = p -> right;
            }
            if(p -> left != NULL)
            {
                top++;
                stack[top] = p -> left;
            }
        }
        printf("\n\n");
    }
}

void PreOrderNoRecurse2(Node *Root)//先序遍历，非递归实现，版本二
{
    Node *stack[MAXTREENODE];//stack保留的是已经打印的节点
    Node *p = Root;
    int num = 0;
    while(p != NULL || num  > 0)
    {
        while(p != NULL)
        {
            printf("%d  ",p -> value);
            stack[num++] = p;
            p = p -> left;
        }
        num --;
        p = stack[num];
        p = p -> right;
    }
    printf("\n\n");
}

void InOrder(Node *node,void (*pfun)(int value))//中序遍历，递归实现
{
    if(node != NULL)
    {
        InOrder(node -> left,pfun);
        (*pfun)(node -> value);
        InOrder(node -> right,pfun);
    }
    else
        printf("#  ");
}

void InOrderNORecurse1(Node *Root)//中序遍历,非递归实现,版本一
{
    Node *stack[MAXTREENODE];//stack保留的是未打印的节点
    Node *p;
    int top = -1;
    if(Root != NULL)
    {
        p = Root;
        while(top > -1 || p != NULL)
        {
            while(p != NULL)
            {
                top ++;
                stack[top] = p;
                p = p -> left;
            }
            if(top > -1)
            {
                p = stack[top];
                top --;
                printf("%d  ",p -> value);
                p = p -> right;
            }
        }
    }
}

void InOrderNORecurse2(Node *Root)//中序遍历,非递归实现,版本二,与版本一等效
{
    Node *stack[MAXTREENODE];//stack保留的是未打印的节点

    num = 0;
    Node *p = Root;
    while(p != NULL || num > 0)
    {
        while(p != NULL)
        {
            stack[num++] = p;
            p = p -> left;
        }
        num --;
        p = stack[num];
        printf("%d  ",p -> value);
        p = p -> right;
    }
}


void PostOrder(Node *node,void (*pfun)(int value))//后序遍历，递归实现
{
    if(node != NULL)
    {
        PostOrder(node -> left,pfun);
        PostOrder(node -> right,pfun);
        (*pfun)(node -> value);
    }
    else
        printf("#  ");
}

void PostOrderNoRecurse1(Node *Root)//后续遍历，非递归实现，版本1
{
    Node *stack[MAXTREENODE];
    Node *p;
    Node *b = Root;
    int sign, top = -1;
    if(b != NULL)
    {
        do
        {
            while(b != NULL)
            {
                top ++;
                stack[top] = b;
                b = b -> left;
            }

            p = NULL;
            sign = 1;
            while(top != -1 && sign == 1)
            {
                b = stack[top];
                if(b -> right == p)
                {
                    printf("%d  ",b -> value);
                    top --;
                     p = b;
                }
                else
                {
                    b = b -> right;
                    sign = 0;
                }
            }
        }while(top != -1)
    }
}

void PostOrderNoRecurse2(Node *Root)//后续遍历，非递归实现，版本2
{
    Node *p = Root;
    Node *stack[MAXTREENODE];//在0-num之前的值都是没有打印的，所以此栈的作用是维护未打印的节点
    int num = 0;
    Node *have_visit = NULL;
    while(p != NULL || num > 0)
    {
        while(p != NULL)
        {
            stack[num++] = p;
            p = p -> left;
        }
        p = stack[num - 1];
        if(p -> right == NULL || p -> right == have_visit)
        {
            printf("%d  ",p -> value);
            num --;
            have_visit = p;
            p = NULL;
        }
        else
        {
            p = p -> right;
        }
    }
    printf("\n\n");
}

void LevelOrder(Node *Root)//从上到下，从左到右，层次遍历
{

}
int getDeep(const Node *node)//得到树的深度,从根节点到叶节点的长度的最大值
{
    if(node == NULL)
        return 0;
    else
    {
        int leftDeep = getDeep(node -> left);
        int rightDeep = getDeep(node -> right);
        return leftDeep > rightDeep ? leftDeep +1 :rightDeep + 1;
    }
}

Pair SeekItem(const Tree *tree, const int  *value)//寻找是否已有即将插入的节点
{
    Pair look;
    look.parent = NULL;
    look.child = tree -> Root;
    if(look.child == NULL)
        return look;
    while(look.child != NULL)
    {
        if( *value > look.child -> value)
        {
            look.parent = look.child;
            look.child = look.child -> right;
        }
        else if( *value < look.child -> value)
        {
            look.parent = look.child;
            look.child = look.child -> left;
        }
        else
            break;
    }
    return look;
}

static void DeleteNode(Node **node)//删除节点
{
    Node *tmp = NULL;
    if((*node) -> left == NULL)
    {
        tmp = *node;
        *node = (*node) -> right;
        free(tmp);
    }
    else if((*node) -> right == NULL)
    {
        tmp = *node;
        *node = (*node) -> left;
        free(tmp);
    }
    else
    {
        for(tmp = (*node) -> left; tmp -> right != NULL; tmp = tmp -> right)
            continue;
        tmp -> right = (*node) -> right;
        tmp = *node;
        (*node) = (*node) -> left;
        free(tmp);
    }
}

bool DeleteItem(const int *value, Tree *tree)//删除项
{
    Pair look;
    look = SeekItem(tree, value);
    if(look.child == NULL)
        return false;
    if(look.parent == NULL)
    {
        DeleteNode(&look.child);
    }
    else if(look.parent -> left == look.child )
    {
        DeleteNode( &look.parent -> left );
    }
    else
    {
        DeleteNode(&look.parent -> right);
    }
    tree -> size --;
    return true;
}

/*
 * 输入:树的根节点
 * */
bool IsBalanceTree(const Node *Root,int *depth)//判断是否是平衡二叉树
{
    if(Root == NULL)
    {
        *depth = 0;
        return true;
    }
    int left,right;
    if(IsBalanceTree(Root -> left, &left) && IsBalanceTree(Root -> right,&right))
    {
        int diff = left - right;
        if(diff <= 1 && diff >= -1)
        {
            *depth = (left > right ? left +1 : right +1);
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    int B;
    Tree *mytree = (Tree *)malloc(sizeof(Tree));
    TreeInitial(mytree);
    B = Insert(mytree,10);
    Insert(mytree,6);Insert(mytree,14);Insert(mytree,3);Insert(mytree,8);Insert(mytree,12);Insert(mytree,16);Insert(mytree,1);Insert(mytree,4);Insert(mytree,7);
    Insert(mytree,9);Insert(mytree,11);Insert(mytree,13);Insert(mytree,15);Insert(mytree,17);Insert(mytree,21);Insert(mytree,20);

    printf("Tree size = %d\n",mytree -> size);

    printf("递归先序遍历\n");
    PreOrder(mytree -> Root,&show);
    printf("\n\n");

    printf("非递归先序遍历\n");
    PreOrderNoRecurse(mytree -> Root);
    printf("\n\n");

    printf("递归中序遍历\n");
    InOrder(mytree -> Root,&show);
    printf("\n\n");

    printf("递归后序遍历\n");
    PostOrder(mytree -> Root,&show);
    printf("\n\n");

    printf("树深度为%d\n",getDeep(mytree -> Root));

    return 0;
}
