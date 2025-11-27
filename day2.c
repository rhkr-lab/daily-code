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
    InitSize(L);
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
//查找元素
