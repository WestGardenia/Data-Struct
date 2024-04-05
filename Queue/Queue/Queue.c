#define _CRT_SECURE_NO_WARNINGS
#include"Function.h"


void QueueInit(Queue* pq)	// 队列的定义
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}



void QueueDestroy(Queue* pq)	// 队列的销毁
{
	assert(pq);

}