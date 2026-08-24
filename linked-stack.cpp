typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}*LiStack;

void InitStack(LiStack &S){
    S = NULL;
}

bool Push(LiStack &S, ElemType x){
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    if(p == NULL)
        return false;

    p->data = x;
    p->next = S;
    S = p;

    return true;
}

bool Pop(LiStack &S, ElemType &x){
    if(S == NULL)
        return false;

    LinkNode *p = S;
    x = p->data;
    S = S->next;
    free(p);

    return true;
}

bool GetTop(LiStack S, ElemType &x){
    if(S == NULL)
        return false;

    x = S->data;
    return true;
}
