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
