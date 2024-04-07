#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDataType;
typedef struct QueueNode QNode;

struct QueueNode
{
	QNode* next;	// 定义链表结点结构体中指针域next
	QDataType val;	// 定义结点链表数据域
};

typedef struct Queue Queue;

struct Queue
{
	QNode* head;
	QNode* tail;
};
// 这里用了两次结构体定义。
// 第一次定义的结构体是队列中的每个元素类型（结构体）。用链表类型的结构体是为了便于队列结构的实现
// 第二次定义的结构体是队列的结构体，代表了整个队列
// 这样定义的好处在于，实现接口函数时，可以避免多次二级指针的调用



void QueueInit(Queue* pq);	// 队列的定义

void QueueDestroy(Queue* pq);	// 队列的销毁

void QueuePush(Queue* pq, QDataType x);	// 队列数据插入

void QueuePop(Queue* pq);	// 队列数据出队

QDataType QueueFront(Queue* pq);	// 取队头数据

QDataType QueueBack(Queue* pq);		// 取队尾数据

int QueueSize(Queue* pq);	// 计算队列长度

bool QueueEmpty(Queue* pq);	 //判断队列是否为空




