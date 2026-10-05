typedef int ElemType;
#define MaxSize 10
typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;

void InitList(SqList &L) {
    L.length = 0;
}

#define InitSize 10
typedef struct {
    ElemType *data;
    int MaxSize;
    int length;
} SeqList;

void InitList(SeqList &L) {
    L.data = (ElemType *)malloc(InitSize * sizeof(ElemType));
    L.length = 0;
    L.MaxSize = InitSize;
}

void IncreaseSize(SeqList &L, int len) {
    int *p = L.data;
    L.data = (ElemType *)malloc((InitSize + len) * sizeof(ElemType));
    for (int i = 0; i < L.length; i++)
        L.data[i] = p[i];

    L.MaxSize = L.MaxSize + len;
    free(p);
}
