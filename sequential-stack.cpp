// 顺序栈：使用固定大小数组保存元素，top 指向当前栈顶下标。
typedef struct{
    ElemType data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack &S){
    // 初始化为空栈。
    S.top = -1;
}

bool Push(SqStack &S, ElemType x){
    // 栈未满时将元素压入栈顶。
    if(S.top == MaxSize - 1)
        return false;
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S, ElemType &x){
    // 移除并返回栈顶元素；空栈时返回 false。
    if(S.top == -1)
        return false;
    x = S.data[S.top--];
    return true;
}

bool GetTop(SqStack S, ElemType &x){
    // 读取栈顶元素但不删除；空栈时返回 false。
    if(S.top == -1)
        return false;
    x = S.data[S.top];
    return true;
}
