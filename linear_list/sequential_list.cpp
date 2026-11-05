typedef int ElemType;

#define MaxSize 100
typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;

void InitList(SqList &L) {
    L.length = 0;
}

bool Empty(SqList &L) {
    return L.length == 0;
}

bool ListInsert(SqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1 || L.length >= MaxSize) return false;

    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }

    L.data[i - 1] = e;

    L.length++;
    return true;
}

bool ListDelete(SqList &L, int i, ElemType &e) {
    if (i < 1 || i > L.length) return false;

    e = L.data[i - 1];

    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }

    L.length--;
    return true;
}

bool GetElem(SqList L, int i, ElemType &e) {
    if (i < 1 || i > L.length) return false;

    e = L.data[i - 1];
    return true;
}

int LocateElem(SqList L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i + 1;
        }
    }
    return -1;
}