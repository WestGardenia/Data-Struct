#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDataType;

struct QueueNode
{
	QNode* next;	// ����������ṹ����ָ����next
	QDataType x;	// ����������������
};

typedef struct QueueNode QNode;

struct Queue
{
	QNode* head;
	QNode* tail;
};
// �����������νṹ�嶨�塣
// ��һ�ζ���Ľṹ���Ƕ����е�ÿ��Ԫ�����ͣ��ṹ�壩�����������͵Ľṹ����Ϊ�˱��ڶ��нṹ��ʵ��
// �ڶ��ζ���Ľṹ���Ƕ��еĽṹ�壬��������������
// ��������ĺô����ڣ�ʵ�ֽӿں���ʱ�����Ա����ζ���ָ��ĵ���

typedef struct Queue Queue;

void QueueInit(Queue* pq);	// ���еĶ���

void QueueDestroy(Queue* pq);	// ���е�����

void QueuePush(Queue* pq, QDataType x);	// �������ݲ���

void QueuePop(Queue* pq);	// �������ݳ���

QDataType QueueFront(Queue* pq);	// ȡ��ͷ����

QDataType QueueBack(Queue* pq);		// ȡ��β����

size_t QueueSize(Queue* pq);	// ������г���

bool QueueEmpty(Queue* pq);	 //�ж϶����Ƿ�Ϊ��


