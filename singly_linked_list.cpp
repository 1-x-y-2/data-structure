typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

// 初始化(不带头结点)
bool InitList(LinkList &L) {
    L = NULL;
    return true;
}

// 判空(不带头结点)
bool Empty(LinkList L) {
    return L == NULL;
}

// 初始化(带头结点)
bool InitList(LinkList &L) {
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL) return false;

    L -> next = NULL;
    return true;
}

// 判空(带头结点)
bool Empty(LinkList L) {
    return L -> next == NULL;
}

// 按位序插入(带头结点)
bool ListInsert(LinkList &L, int i, ElemType e) {
    if (i < 1) return false;

    LNode *p = L;
    int j = 0;
    while (p != NULL && j < i - 1) {
        p = p -> next;
        j++;
    }
    if (p == NULL) return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s -> data = e;
    s -> next = p -> next;
    p -> next = s;
    return true;
    // return InsertNextNode(p, e);
}

// 按位序插入(不带头结点)
bool ListInsert(LinkList &L, int i, ElemType e) {
    if (i < 1) return false;

    if (i == 1) {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s -> data = e;
        s -> next = L;
        L = s;
        return true;
    }

    LNode *p = L;
    int j = 1;
    while (p != NULL && j < i - 1) {
        p = p -> next;
        j++;
    }
    if (p == NULL) return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s -> data = e;
    s -> next = p -> next;
    p -> next = s;
    return true;
    // return InsertNextNode(p, e);
}

// 指定结点的后插操作
bool InsertNextNode(LNode *p, ElemType e) {
    if (p == NULL) return false;

    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) return false;
    s -> data = e;
    s -> next = p -> next;
    p -> next = s;
    return true;
}

// 指定结点的前插操作
bool InsertPriorNode(LNode *p, ElemType e) {
    if (p == NULL) return false;
    
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) return false;
    s -> next = p -> next;
    p -> next = s;
    s -> data = p -> data;
    p -> data = e;
    return true;
}

// 按位序删除(带头结点)
bool ListDelete(LinkList &L, int i, ElemType &e) {
    if (i < 1) return false;

    int j = 0;
    LNode *p = L;
    while (p != NULL && j < i - 1) {
        p = p -> next;
        j++;
    }
    if (p == NULL || p -> next == NULL) return false;
    LNode *q = p -> next;
    p -> next = q -> next;
    e = q -> data;
    free(q);
    return true;
}

// 指定结点的删除
bool DeleteNode(LNode *p) {
    if (p == NULL) return false;

    LNode *q = p -> next;
    p -> data = q -> data;
    p -> next = q -> next;
    free(q);
    return true;
}

// 按位查找(带头结点)
LNode *GetElem(LinkList L, int i) {
    if (i < 0) return NULL;

    int j = 0;
    LNode *p = L;
    while (p != NULL && j < i) {
        p = p -> next;
        j++;
    }
    return p;
}

// 按值查找
LNode *LocateElem(LinkList L, ElemType e) {
    LNode *p = L -> next;
    while (p != NULL && p -> data != e) {
        p = p -> next;
    }
    return p;
}

// 求长度
int Length(LinkList L) {

    LNode *p = L;
    int len = 0;
    while (p -> next != NULL) {
        p = p -> next;
        len++;
    }
    return len;
}

// 尾插法建立单链表(带头结点)
LinkList List_TailInsert(LinkList &L) {
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *)malloc(sizeof(LNode));
        s -> data = x;
        r -> next = s;
        r = s;
        scanf("%d", &x);
    }
    r -> next = NULL;
    return L;
}

// 尾插法建立单链表(不带头结点)
LinkList List_TailIsert(LinkList &L) {
    int x;
    L = NULL;
    LNode *s, *r = NULL;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *)malloc(sizeof(LNode));
        s -> data = x;
        if (L == NULL) {
            L = s;
        } else {
            r -> next = s;
        }
        r = s;

        scanf("%d", &x);
    }

    if (r != NULL) r -> next = NULL;
    return L;
}

// 头插法建立单链表(带头结点)
LinkList List_HeadInsert(LinkList &L) {
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L -> next = NULL;
    scanf("%d", &x);
    while (x != 9999) {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s -> data = x;
        s -> next = L -> next;
        L -> next = s;
        scanf("%d", &x);
    }
    return L;
}

// 头插法建立单链表(不带头结点)
LinkList List_HeadInsert(LinkList &L) {
    int x;
    L = NULL;
    scanf("%d", &x);
    while (x != 9999) {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s -> data = x;
        s -> next = L;
        L = s;
        scanf("%d", &x);
    }
    return L;
}

// 反转
LinkList reverseList(LinkList L) {
    if (L == NULL || L -> next == NULL) return L; 

    LNode *p = L -> next;
    LNode *q;
    L -> next = NULL;

    while (p != NULL) {
        q = p -> next;
        p -> next = L -> next;
        L -> next = p;
        p = q;
    }

    return L;
}
