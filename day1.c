#define MaxSize 50
typedef struct
{
  ElemType data[MaxSize];
  int length;
}SqList;

bool ListInsert(SqList &L, int i, ElemType e)
{
  if(i<1||i>L.length+1)
    return false;
  e=L.data[i-1];
  
}
