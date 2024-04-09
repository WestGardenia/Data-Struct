#define _CRT_SECURE_NO_WARNINGS
#include"CircleQueue-Function.h"

MyCircularQueue* myCircularQueueCreate(int k)	// ����ѭ������
{
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->a = malloc(sizeof(int) * (k + 1));	// �࿪һ���ռ����ֿպ���
	cq->front = cq->tail = 0;
	cq->k = k;

	return cq;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)	// �ж��Ƿ�ɹ�����Ԫ��
{
	if (myCircularQueueIsFull(obj))
		// ���ѭ���������������޿��ÿռ�ȥ�������ݣ����жϲ���ʧ�ܡ�����false
		return false;
	obj->a[obj->tail] = value;
	obj->tail++;
	obj->tail %= (obj->k + 1);	// �����±꣬��ֹ�±�Խ��
	
	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)	// �ж��Ƿ�ɹ�ɾ��Ԫ��
{
	if (myCircularQueueIsEmpty(obj))
		// ���ѭ�������ѿգ����޿�������ȥɾ�������ж�ɾ��ʧ�ܡ�����false
		return false;
	// ɾ���������Լ�
	// ����ѭ�����е��ص㣬ֻ��Ҫ��front�±��Լӣ���ôԭ��front��Ӧ�����ݾͻᱻδ������ʱ�����ݸ��ǡ�ͬʱ���ᱻ�������
	obj->front++;
	obj->front %= (obj->k + 1);

	return true;
}

int myCircularQueueFront(MyCircularQueue* obj)	// ѭ������--ȡ��ͷ����
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj -> a[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj)	// ѭ������--ȡ��β����
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	// ȡ��β����ʱ������tail��ǰһ�����ݲ�������Ķ�β����
	// ��ѭ�����е�tail�Ͷ�β���ݵ����λ�ò���ͳһ��������Ҫ���д���һ��
	// 1�����ݴ���
	int realtail = (obj->tail+obj->k)%(obj->k+1);
	return obj->a[realtail];
	// 2�������ж�
	//if (obj->tail == 0)
	//	return obj->a[obj->k];
	//else
	//	return obj->a[obj->tail - 1];

}

bool myCircularQueueIsEmpty(MyCircularQueue* obj)	// ѭ������--�п�
{
	return obj->front == obj->tail;
}

bool myCircularQueueIsFull(MyCircularQueue* obj)	// ѭ������--����
{
	return (obj->tail + 1) % (obj->k + 1) == obj->front;
}

void myCircularQueueFree(MyCircularQueue* obj)	// ����ѭ������
{
	free(obj->a);
	free(obj);
}