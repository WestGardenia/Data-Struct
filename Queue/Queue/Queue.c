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
	QNode* cur = pq->head;
	while (cur != NULL)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}

void QueuePush(Queue* pq, QDataType x)	// 队列数据插入
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("空间开辟--QueuePush函数出错!!!");
		exit(-1);
	}
	newnode->val = x;
	newnode->next = NULL;
	if (pq->head == NULL)
	{
		// 如果队列中没有数据，即为空队列。此时将头结点和尾结点指向新malloc出来的结点
		pq->head = pq->tail = newnode;
	}
	else
	{
		// 如果队列中有数据，就将新结点链接到tail的后面，并更新tail的位置，将tail指向newnode
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

void QueuePop(Queue* pq)	// 队列数据出队
{
	// 删除队头的数据，将head保存，更新head的位置，并且free掉旧的头节点
	assert(pq);
	// 为防止空队列删除造成越界访问，需要对队列是否为空进行判断
	assert(!QueueEmpty(pq));
	QNode* newhead = pq->head;
	// 迭代head的位置
	pq->head = pq->head->next;
	free(newhead);
	if (pq->head == NULL)
	{
		// 如果队列已经被删成了一个空队列。
		// 由于头结点迭代时并没有对尾结点tail处理，此时tail就是一个野指针。需要将其置空
		pq->tail = NULL;
	}
}

QDataType QueueFront(Queue* pq)	// 取队头数据
{
	assert(pq);
	// 为防止空队列删除造成越界访问，需要对队列是否为空进行判断
	assert(!QueueEmpty(pq));

	return pq->head->val;
}

QDataType QueueBack(Queue* pq)		// 取队尾数据
{
	assert(pq);
	// 为防止空队列删除造成越界访问，需要对队列是否为空进行判断
	assert(!QueueEmpty(pq));

	return pq->tail->val;
}

int QueueSize(Queue* pq)	// 计算队列长度
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

bool QueueEmpty(Queue* pq)	 //判断队列是否为空
{
	assert(pq);
	return pq->head == NULL;
}