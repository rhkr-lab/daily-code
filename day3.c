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

//**带头结点的单链表**
typedef struct LNode
{
    ElemType data;
    struct LNode * next;
}LNode,*LinkList;

bool InitList(LinkList &L)
{
    L=(LNode *)malloc(sizeof(LNode));
    if(L==NULL)
        return false;
    L->next=NULL;
    return true;
}

bool Empty(LinkList & L)    //判空操作
{
    if(L->next==NULL)
        return true;
    else    
        return false;
}

bool LinkInsert(LinkList &L,int i,ElemType e)    //在第i个位置插入元素e
{
    if(i<1)
        return false;
    LNode *p=L;
    int j=0;
    while(p!=NULL&&<i-1) //找到第i-1个结点
    {
        p=p->next;
        j++;
    }
    if(p==NULL) //i的值给的太大，超过了链表长度
        return false;
    LNode *s=(LNode*)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}
