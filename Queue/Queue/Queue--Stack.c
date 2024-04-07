#define _CRT_SECURE_NO_WARNINGS
#include"Function.h"

// 用两个队列实现栈

typedef struct {
    Queue q1;
    Queue q2;
} MyStack;


MyStack* myStackCreate() {
    // 定义结构体变量。
    // 由于在函数中定义局部变量，为防止出栈销毁，需要在这里使用malloc动态开辟空间
    MyStack* st = (MyStack*)malloc(sizeof(MyStack));
    // 对新栈进行初始化，需要传入结构体地址。
    // 这里的st->q1代表了q1队列这个结构体。由于函数需要结构体指针，所以要加上取地址符
    if (st == NULL)
    {
        exit(-1);
    }
    QueueInit(&st->q1);
    QueueInit(&st->q2);

    return st;
}

// 核心思路：
// 1、入数据：将数据传入空的队列中（头插），并且保证另一个队列始终为空
// 2、出数据，将有数据的队列中的数据从队尾依次取出（尾删），并放在另一个空队列中得到保存（头插）。同时留下最后一个数据，这个数据就是需要删除的数据
//
void myStackPush(MyStack* obj, int x) {
    // 将数据传入空队列中
    if (!QueueEmpty(&obj->q1))
    {
        QueuePush(&obj->q1, x);
    }
    else
    {
        QueuePush(&obj->q2, x);
    }
}

int myStackPop(MyStack* obj) {
    Queue* empty = &obj->q1;
    Queue* nonempty = &obj->q2;
    if (QueueEmpty(nonempty))
    {
        // 如果假设错误。互换
        empty = &obj->q2;
        nonempty = &obj->q1;
    }
    while (QueueSize(nonempty) > 1)
    {
        // 如果非空队列里面的数据数量大于1，就将队尾的数据传给空队列，并将原队列中的数据删除
        QueuePush(empty, QueueFront(nonempty));
        QueuePop(nonempty);
    }

    // 将非空队列的剩下的最后一个数据保存作为返回值返回。最后将其删除
    int top = QueueFront(nonempty);
    QueuePop(nonempty);

    return top;
}

int myStackTop(MyStack* obj) {
    // 根据栈结构先进后出和队列结构先进先出的结构特性，可以得知，所谓MyStack的栈顶元素就是队列中的队尾元素
    if (!QueueEmpty(&obj->q1))
    {
        return QueueBack(&obj->q1);
    }
    else
    {
        return QueueBack(&obj->q2);
    }
}

bool myStackEmpty(MyStack* obj) {
    return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
    QueueDestroy(&obj->q1);
    QueueDestroy(&obj->q2);

    free(obj);
}
