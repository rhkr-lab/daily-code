//顺序表的静态实现，各种基本操作
#include <stdio.h>
#define MaxSize 10
typedef struct
{
    Elemtype data[MaxSize];
    int length;
}SqList;
void InitList(SqList &L)
{
    for(int i=1;i<=MaxSize;i++)
    {
        L.data[i]=0;
    }
    L.length=0;    
}
int main()
{
    SqList L;
    InitList(L);
    return 0;
}
// 打印链表
void PrintList(SqList &L)
{
    for(int i=0;i<L.length;i++)
    {
        printf("%d ",L.data[i]);
    }
    printf("\n");
}
//插入元素
bool ListInsert(SqList &L,int i,ElemType e)
{
    if(i<1||i>L.length+1)
    {
        return false;
    }
    if(L.length>=MaxSize)
    {
        return false;
    }
    for(int j=L.length;j>=i;j--)
    {
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;
    L.length++;
    return true;
}
//查找第i个元素
ElemType GetElem(SeqList &L,int i)
{
    return L.data[i-1];
}
//查找元素e在顺序表中的位置
int LocateElem(SeqList &L,ElemType e)
{
    for(int i=0;i<L.length;i++)
    {
        if(L.data[i]==e)//C语言中，对比两个结构体元素不能直接用==；但是考研中手写代码的时候可以直接写==
            return i+1;
    }
    return 0;
}
---
//顺序表的动态实现，各种基本操作
#include <stdio.h>
#define InitSize 10
typedef Struct
{
    Elemtype * data;
    int length;
}Seqlist;
InitSize(Seqlist &L)
{
    L.data=(ElemType *)malloc(sizeof(ElemType)*InitSize);
    L.length=0;
    L.MaxSize=InitSize;
}
int main()
{
    Seqlist L;
    InitSize(L,5);
    //插入元素到顺序表中，此处代码省略
    IncreaseSize(L);
    ListInsert(L,i,e);
    return 0;
}
IncreaseSize(SeqList &L,int len)
{
    ElemType* p=L.data;
    L.data=(ElemType *)malloc(sizeof(ElemType)*(InitSize+len));
    for(i=1;i<=L.length;i++)
        L.data[i-1]=p[i-1];
    L.MaxSize=L.MaxSize+len;
    free(p);
}
