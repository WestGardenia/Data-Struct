#define _CRT_SECURE_NO_WARNINGS
#include"Function.h"

// 用两个队列实现栈结构

typedef struct {
    SK pushST;
    SK popST;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    StackInit(&q->pushST);
    StackInit(&q->popST);

    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    StackPush(&obj->pushST, x);
}

int myQueuePop(MyQueue* obj) {
    if (StackEmpty(&obj->popST))
    {
        // 如果pop为空栈，则从push栈中传数据到pop栈中
        while (!StackEmpty(&obj->pushST))
        {
            StackPush(&obj->popST, StackTop(&obj->pushST));
            StackPop(&obj->pushST);
        }
    }
    // 如果pop栈不为空栈，则直接返回栈顶值
    int top = StackTop(&obj->popST);
    StackPop(&obj->popST);
    return top;
}

int myQueuePeek(MyQueue* obj) {
    // 如果pop栈不为空，则所谓的队尾数据就是pop栈中的栈顶数据
    if (StackEmpty(&obj->popST))
    {
        while (!StackEmpty(&obj->pushST))
        {
            StackPush(&obj->popST, StackTop(&obj->pushST));
            StackPop(&obj->pushST);
        }

    }
    return StackTop(&obj->popST);
}

bool myQueueEmpty(MyQueue* obj) {
    return StackEmpty(&obj->pushST) && StackEmpty(&obj->popST);
}

void myQueueFree(MyQueue* obj) {
    StackDestroy(&obj->pushST);
    StackDestroy(&obj->popST);

    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/