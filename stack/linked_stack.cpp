typedef int ElemType;

typedef struct Linknode {
    ElemType data;
    struct Linknode *next;
} Linknode, *LiStack;

void InitStack(LiStack &S) {
    S = NULL;
}

bool Empty(LiStack S) {
    return S == NULL;
}

bool Push(LiStack &S, ElemType x) {
    Linknode *s = (Linknode *)malloc(sizeof(Linknode));
    if (s == NULL) return false;
    s->data = x;
    s->next = S;
    S = s;
    return true;
}

bool Pop(LiStack &S, ElemType &x) {
    if (S == NULL) return false;
    Linknode *q = S;
    S = S->next;
    x = q->data;
    free(q);
    return true;
}

bool GetTop(LiStack S, ElemType &x) {
    if (S == NULL) return false;
    x = S->data;
    return true;
}

