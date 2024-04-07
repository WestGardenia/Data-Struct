#define _CRT_SECURE_NO_WARNINGS
#include"Function.h"

// ����������ʵ��ջ

typedef struct {
    Queue q1;
    Queue q2;
} MyStack;


MyStack* myStackCreate() {
    // ����ṹ�������
    // �����ں����ж���ֲ�������Ϊ��ֹ��ջ���٣���Ҫ������ʹ��malloc��̬���ٿռ�
    MyStack* st = (MyStack*)malloc(sizeof(MyStack));
    // ����ջ���г�ʼ������Ҫ����ṹ���ַ��
    // �����st->q1������q1��������ṹ�塣���ں�����Ҫ�ṹ��ָ�룬����Ҫ����ȡ��ַ��
    if (st == NULL)
    {
        exit(-1);
    }
    QueueInit(&st->q1);
    QueueInit(&st->q2);

    return st;
}

// ����˼·��
// 1�������ݣ������ݴ���յĶ����У�ͷ�壩�����ұ�֤��һ������ʼ��Ϊ��
// 2�������ݣ��������ݵĶ����е����ݴӶ�β����ȡ����βɾ������������һ���ն����еõ����棨ͷ�壩��ͬʱ�������һ�����ݣ�������ݾ�����Ҫɾ��������
//
void myStackPush(MyStack* obj, int x) {
    // �����ݴ���ն�����
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
        // ���������󡣻���
        empty = &obj->q2;
        nonempty = &obj->q1;
    }
    while (QueueSize(nonempty) > 1)
    {
        // ����ǿն��������������������1���ͽ���β�����ݴ����ն��У�����ԭ�����е�����ɾ��
        QueuePush(empty, QueueFront(nonempty));
        QueuePop(nonempty);
    }

    // ���ǿն��е�ʣ�µ����һ�����ݱ�����Ϊ����ֵ���ء������ɾ��
    int top = QueueFront(nonempty);
    QueuePop(nonempty);

    return top;
}

int myStackTop(MyStack* obj) {
    // ����ջ�ṹ�Ƚ�����Ͷ��нṹ�Ƚ��ȳ��Ľṹ���ԣ����Ե�֪����νMyStack��ջ��Ԫ�ؾ��Ƕ����еĶ�βԪ��
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
