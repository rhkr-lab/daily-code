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

bool LinkInsert(LinkList & L,int i,ElemType e)    //在不带头结点的单链表中的第i个位置插入元素e
{
    if(i<1)
        return false;
    if(i==1)
    {    
        LNode*s=(LNode*)malloc(sizeof(LNode));
        s->data=e;
        s->next=L;
        L=s;
        return true;
    }
    LNode*p;
    int j=1;
    p=L;
    while(p!=NULL&&<i-1)
    {
        p=p->next;
        j++;
    }
    if(p==NULL)
        return false;
    LNode* s=(LNode*)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
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

bool ListDelete(LinkList &L,int i,ElemType &e)    //带头结点的单链表删除，按位序删除，用e带出删除元素
{
   if(i<1)
      return false;
   LNode *p;
   int j=0;
   p=L;
   while (p!=NULL&&j<i-1)
   {
      p=p->next;
      j++;
   }
   if(p==NULL)
      return false;
   if(p->next==NULL)
      return false;
   LNode *q=p->next;
   p->next=q->next;
   e=q->data;
   q->next=NULL;  //可以不写
   free(q);
   return true;
}

LNode * GetElem(LinkList &L,int i)    //按位查找，返回第i个元素，带头结点的情况
{
    if(i<0)
        return NULL;
    LNode *p;
    p=L;
    int j=0;
    while(p!=NULL && j<i)
    {
        p=p->next;
        j++;
    }
    if(p==NULL)
        return NULL;    //返回NULL就代表操作失败
    return p;
}

LNode * LocateElem(LinkList &L,ElemType e)    //按值查找
{
    LNode *p;
    p=L->next;
    int j=0;
    while(p->data!=e && p!=NULL)
    {
        p=p->next;
        j++;
    }
    return p;
}

int Length(LinkList &L)    //返回单链表的表长
{
    LNode *p=L;
    int length=0;
    while(p->next!=NULL)    //头结点不算进长度中
    {
        p=p->next;
        length++;
    }
    return length;
}

//后插操作，给定一个结点p，将元素e插入到结点p的后面（适用于有头结点与无头结点的单链表）
bool InsertNextNode(LNode *P,ElemType e)
{
    if(p==NULL)
        return false;
    LNode *s=(LNode *)malloc(sizeof(LNode));
    if(s==NULL)     //内存分配失败
        return false;
    s->data=e;
    s->next=p->next;
    return true;
}

//指定结点的前插操作==后插操作+前后互换数据（结点s与给定的p结点）
bool InsertPriorNode(LNode *p,ElemType e)
{
    if(p==NULL)
        return false;
    LNode *s=(LNode *)malloc(sizeof(LNode));
    if (s==NULL)
        return false;
    s->next=p->next;
    p->next=s;
    s->data=p->data;
    p->data=e;
    return true;
}

bool InsertPriorNode(LNode *p,LNode *s)
{
    if(p==NULL||s==NULL)
        return false;
    s->next=p->next;
    p->next=s;
    ElemType temp;
    temp=p->data;
    p->data=s->data;
    s->data=p;
    return true;
}

//删除指定结点（适用于带头结点和不带头结点的单链表）
bool DeleteNode(LNode *p)
{
   if(p==NULL)
      return false;
   LNode *q=p->next;
   p->data=q->data;  //通过数据交换把应删除的结点转换为他的后继结点
   p->next=q->next;
   free(q);
   return true;
}
