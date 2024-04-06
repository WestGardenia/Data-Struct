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
	QNode* cur = pq->head;
	while (cur != NULL)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}

void QueuePush(Queue* pq, QDataType x)	// �������ݲ���
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("�ռ俪��--QueuePush��������!!!");
		exit(-1);
	}
	newnode->val = x;
	newnode->next = NULL;
	if (pq->head == NULL)
	{
		// ���������û�����ݣ���Ϊ�ն��С���ʱ��ͷ����β���ָ����malloc�����Ľ��
		pq->head = pq->tail = newnode;
	}
	else
	{
		// ��������������ݣ��ͽ��½�����ӵ�tail�ĺ��棬������tail��λ�ã���tailָ��newnode
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

void QueuePop(Queue* pq)	// �������ݳ���
{
	// ɾ����ͷ�����ݣ���head���棬����head��λ�ã�����free���ɵ�ͷ�ڵ�
	assert(pq);
	// Ϊ��ֹ�ն���ɾ�����Խ����ʣ���Ҫ�Զ����Ƿ�Ϊ�ս����ж�
	assert(!QueueEmpty(pq));
	QNode* newhead = pq->head;
	// ����head��λ��
	pq->head = pq->head->next;
	free(newhead);
	if (pq->head == NULL)
	{
		// ��������Ѿ���ɾ����һ���ն��С�
		// ����ͷ������ʱ��û�ж�β���tail������ʱtail����һ��Ұָ�롣��Ҫ�����ÿ�
		pq->tail = NULL;
	}
}

QDataType QueueFront(Queue* pq)	// ȡ��ͷ����
{
	assert(pq);
	// Ϊ��ֹ�ն���ɾ�����Խ����ʣ���Ҫ�Զ����Ƿ�Ϊ�ս����ж�
	assert(!QueueEmpty(pq));

	return pq->head->val;
}

QDataType QueueBack(Queue* pq)		// ȡ��β����
{
	assert(pq);
	// Ϊ��ֹ�ն���ɾ�����Խ����ʣ���Ҫ�Զ����Ƿ�Ϊ�ս����ж�
	assert(!QueueEmpty(pq));

	return pq->tail->val;
}

int QueueSize(Queue* pq)	// ������г���
{
	assert(pq);
	if (pq->head == NULL)
		return 0;
	else
	{
		int count = 0;
		QNode* cur = pq->head;
		while (cur)
		{
			cur = cur->next;
			count++;
		}
		return count;
	}
}

bool QueueEmpty(Queue* pq)	 //�ж϶����Ƿ�Ϊ��
{
	assert(pq);
	return pq->head == NULL;
}