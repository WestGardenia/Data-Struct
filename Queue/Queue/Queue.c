#define _CRT_SECURE_NO_WARNINGS
#include"Function.h"


void QueueInit(Queue* pq)	// ���еĶ���
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}



void QueueDestroy(Queue* pq)	// ���е�����
{
	assert(pq);

}