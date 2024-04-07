#define _CRT_SECURE_NO_WARNINGS
#include"Function.h"

// ����������ʵ��ջ�ṹ

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
        // ���popΪ��ջ�����pushջ�д����ݵ�popջ��
        while (!StackEmpty(&obj->pushST))
        {
            StackPush(&obj->popST, StackTop(&obj->pushST));
            StackPop(&obj->pushST);
        }
    }
    // ���popջ��Ϊ��ջ����ֱ�ӷ���ջ��ֵ
    int top = StackTop(&obj->popST);
    StackPop(&obj->popST);
    return top;
}

int myQueuePeek(MyQueue* obj) {
    // ���popջ��Ϊ�գ�����ν�Ķ�β���ݾ���popջ�е�ջ������
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