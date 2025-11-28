#include <stdio.h>
#define MaxSize 50
typedef struct
{
  ElemType data[MaxSize];
  int length;
}SqList;

//插入元素e到第i个位置上
bool ListInsert(SqList &L,int i,int/ElemType e)
{
    if(i<1||L.length+1)
        return false;
    if(L.length>=MaxSize)
        return false;
    for(int j=L.length;j>=i;j--)
        L.data[j]=L.data[j-1];
    L.data[i-1]=e;
    L.length++;
    return true;
}
//删除第i个元素，并用e带出来该元素的值
bool ListDelete(SqList &L,int i,int &e)
{
    if(i<1||i>L.length)
        return false;
    e=L.data[i-1];
    for(int j=i;j<L.length;j++)
        L.data[j-1]=L.data[j];
    L.length--;
    return true;
}
//这些基本操作的使用
int main()
{
    SqList L;
    InitList(L);
    //插入一系列元素
    int e=-1;
    if(ListDelete(L,3,e))
        printf("delete success,e=%d\n",e)
    else
        printf("delete failure");
    return 0;
}
