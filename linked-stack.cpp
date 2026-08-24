// 链式栈：栈顶位于链表头部，支持动态扩容。
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}*LiStack;

void InitStack(LiStack &S){
    // 初始化为空栈。
    S = NULL;
}

bool Push(LiStack &S, ElemType x){
    // 将元素压入栈顶；内存分配失败时返回 false。
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    if(p == NULL)
        return false;

    p->data = x;
    p->next = S;
    S = p;

    return true;
}

bool Pop(LiStack &S, ElemType &x){
    // 移除并返回栈顶元素；空栈时返回 false。
    if(S == NULL)
        return false;

    LinkNode *p = S;
    x = p->data;
    S = S->next;
    free(p);

    return true;
}

bool GetTop(LiStack S, ElemType &x){
    // 读取栈顶元素但不删除；空栈时返回 false。
    if(S == NULL)
        return false;

    x = S->data;
    return true;
}
