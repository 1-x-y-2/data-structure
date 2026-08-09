typedef struct DNode {
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

// 初始化(带头结点)
bool InitDLinkList(DLinkList &L) {
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL) return false;

    L -> prior = NULL;
    L -> next = NULL;
    return true;
}

// 判空(带头结点)
bool Empty(DLinkList L) {
    return L -> next == NULL;
}

// 插入结点
bool InsertNextDNode(DNode *p, DNode *s) {
    if (p == NULL || s == NULL ) return false;

    s -> next = p -> next;
    if (p -> next != NULL) {
        p -> next -> prior = s;
    }
    s -> prior = p;
    p -> next = s;
    return true;
}

// 删除结点
bool DeleteNode(DNode *p) {
    if (p == NULL || p -> next == NULL) return false;

    DNode *q = p -> next;
    p -> next = q -> next;
    if (q -> next != NULL) {
        q -> next -> prior = p;
    }
    free(q);
    return true;
}


