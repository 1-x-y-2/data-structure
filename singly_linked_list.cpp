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
bool InsertPriorLNode(LNode *p, ElemType e) {
    if (p == NULL) return false;

    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) return false;

    s->next = p->next;
    p->next = s;

    s->data = p->data;  // 先保存 p 原来的数据
    p->data = e;        // p 改成新插入的数据

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
    LNode *s, *r;
    int x;

    L = (LinkList)malloc(sizeof(LNode)); // 创建头结点
    r = L;                              // r初始指向头结点

    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;

        r->next = s;   // 新结点接到表尾
        r = s;         // r指向新的尾结点

        scanf("%d", &x);
    }

    r->next = NULL;
    return L;
}


// 尾插法建立单链表(不带头结点)
LinkList List_TailInsert(LinkList &L) {
    LNode *s, *r;
    int x;
    L = NULL;
    r = NULL;

    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = NULL;

        if (L == NULL)
            L = s;
        else
            r->next = s;

        r = s;
        scanf("%d", &x);
    }

    return L;
}


// 头插法建立单链表(带头结点)
LinkList List_HeadInsert(LinkList &L) {
    LNode *s;
    int x;

    L = (LinkList)malloc(sizeof(LNode));  // 创建头结点
    L->next = NULL;

    scanf("%d", &x);
    while (x != 9999) {                   // 9999作为结束标志
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;

        s->next = L->next;               // 新结点插到头结点之后
        L->next = s;

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
