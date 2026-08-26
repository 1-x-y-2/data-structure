bool InitList(LinkList &L) {
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL) {
        return false;
    }

    L->next = L;
    return true;
}

bool Empty(LinkList L) {
    return L->next == L;
}


bool InitDLinkList(DLinkList &L) {
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL) return false;

    L->prior = L;
    L->next = L;
    return true;
}
