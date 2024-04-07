#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDataType;
typedef struct QueueNode QNode;

struct QueueNode
{
	QNode* next;	// ����������ṹ����ָ����next
	QDataType val;	// ����������������
};

typedef struct Queue Queue;

struct Queue
{
	QNode* head;
	QNode* tail;
};
// �����������νṹ�嶨�塣
// ��һ�ζ���Ľṹ���Ƕ����е�ÿ��Ԫ�����ͣ��ṹ�壩�����������͵Ľṹ����Ϊ�˱��ڶ��нṹ��ʵ��
// �ڶ��ζ���Ľṹ���Ƕ��еĽṹ�壬��������������
// ��������ĺô����ڣ�ʵ�ֽӿں���ʱ�����Ա����ζ���ָ��ĵ���



void QueueInit(Queue* pq);	// ���еĶ���

void QueueDestroy(Queue* pq);	// ���е�����

void QueuePush(Queue* pq, QDataType x);	// �������ݲ���

void QueuePop(Queue* pq);	// �������ݳ���

QDataType QueueFront(Queue* pq);	// ȡ��ͷ����

QDataType QueueBack(Queue* pq);		// ȡ��β����

int QueueSize(Queue* pq);	// ������г���

bool QueueEmpty(Queue* pq);	 //�ж϶����Ƿ�Ϊ��




