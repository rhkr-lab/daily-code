#include <stdio.h>
//LNode*与LinkList都可以表示指针变量类型，但一般强调单链表的时候用LinkList，强调某个结点时候用LNode*
struct LNode*p=(struct LNode*)malloc(sizeof(struct LNode));
//不带头结点的单链表
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

bool InitList(LinkList &L)  //初始化
{
    L=NULL;
    return true;
}

bool Empty(LinkList L)  //判空操作
{
    if(L==NULL)
        return true;
    else
        return false;
}
//simplify the empty(L)
bool Empty(LinkList L)
{
    return (L=NULL);
}
