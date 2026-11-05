typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;


bool InitList(LinkList &L) {
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL) return false;

    L->next = NULL;
    return true;
}

bool Empty(LinkList L) {
    return L->next == NULL;
}

bool ListInsert(LinkList &L, int i, ElemType e) {
    if (i < 1) return false;

    LNode *p = L;
    int j = 0;

    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }

    if (p == NULL) return false;

    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) return false;

    s->data = e;
    s->next = p->next;
    p->next = s;

    return true;
}

bool InsertNextNode(LNode *p, ElemType e) {
    if (p == NULL) return false;

    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) return false;

    s->data = e;
    s->next = p->next;
    p->next = s;

    return true;
}

bool InsertPriorNode(LNode *p, ElemType e) {
    if (p == NULL) return false;

    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) return false;

    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;

    return true;
}

bool ListDelete(LinkList &L, int i, ElemType &e) {
    if (i < 1) return false;

    LNode *p = L;
    int j = 0;

    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }

    if (p == NULL || p->next == NULL) return false;

    LNode *q = p->next;
    e = q->data;
    p->next = q->next;

    free(q);
    return true;
}

bool DeleteLNode(LNode *p) {
    if (p == NULL || p->next == NULL) return false;

    LNode *q = p->next;
    p->data = q->data;
    p->next = q->next;

    free(q);
    return true;
}

LNode* GetElem(LinkList L, int i) {
    if (i < 1) return NULL;

    LNode *p = L;
    int j = 0;

    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }

    return p;
}

LNode* LocateElem(LinkList L, ElemType e) {
    LNode *p = L->next;

    while (p != NULL && p->data != e) {
        p = p->next;
    }

    return p;
}

int Length(LinkList L) {
    int len = 0;

    LNode *p = L->next;

    while (p != NULL) {
        p = p->next;
        len++;
    }

    return len;
}

void DestroyList(LinkList &L) {
    LNode *p, *q;

    p = L;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }

    L = NULL;
}