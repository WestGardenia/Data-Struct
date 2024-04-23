#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef struct TreeNode TreeNode;

struct TreeNode {
	char data;
	TreeNode* LChild;	// �������ӽ��
	TreeNode* RChild;	// �����Һ��ӽڵ�
	int flag;	// �ж϶�Ӧλ�ýڵ��Ƿ񱻷��ʹ�
};

void TreeCreative(TreeNode** RootNode, char* data, int* index);	// ����������

// ���ֱ������������򡢺���--�ݹ����
void preOrder(TreeNode* RootNode);	// ������--�������--��-��-��

void inOrder(TreeNode* RootNode);	// ������--�������--��-��-��

void postOrder(TreeNode* RootNode);		// ������--�������--��-��-��

// ��α���
typedef struct Queue Queue;
typedef struct QNode QNode;
typedef TreeNode Queue_DataType;

struct QNode {
	QNode* next;
	Queue_DataType* data;
};

struct Queue {
	QNode* head;	// ָ����
	QNode* tail;	// ������
};	// ����ʽ���д洢���Ĳ�ͬ��ε����ݡ����������Ƚ��ȳ����ص���б���

//������������������������������������������������������������������������������������������������������������
// ����---function����
void QueueInit(Queue* pq);	// ���еĶ���

void QueueDestroy(Queue* pq);	// ���е�����

void QueuePush(Queue* pq, Queue_DataType* x);	// �������ݲ���

void QueuePop(Queue* pq);	// �������ݳ���

Queue_DataType* QueueFront(Queue* pq);	// ȡ��ͷ����

Queue_DataType* QueueBack(Queue* pq);		// ȡ��β����

int QueueSize(Queue* pq);	// ������г���

bool QueueEmpty(Queue* pq);	 //�ж϶����Ƿ�Ϊ��

//������������������������������������������������������������������������������������������������������������
// ��----function����
void LevelTraverse(Queue* q, TreeNode* RootNode);	// ������--��α���

//
// ������--�ǵݹ������˳�������
// ����ջ���Ƚ�����Ľṹ�ص�ȥʵ��
// �����ϣ��ݹ����Ҳ�ǶԱ���������ջ֡��ʹ�á�Ҳ������ջʵ��
// �ǵݹ������Ҫ����һ�����ݽṹ---ջ
// �ǵݹ飨ǰ�����򣩱���˼·��
// 1����ջ���ڵ�
// 2��ѭ������ֱ������Ϊ��
// 3����ջ�����ʽڵ㣬��ջ�Һ���
// 4��ѭ������������ֱ��ջ��Ϊֹ
// 5��ǰ���������˳��Ϊ��ջ˳���ȷ��ʣ��ٽ�ջ���ٳ�ջ��   //  �����������˳��Ϊ��ջ˳���Ƚ�ջ���ٷ��ʣ��ٽ�ջ��
//
typedef struct StackNode StackNode;
typedef TreeNode Stack_DataType;

struct StackNode {
	Stack_DataType* val;
	StackNode* next;
};	// ��������������ʽ����ջ����Ϊ������ȷ�����Ĳ�Ρ�����Ķ�̬�����ڴ���Ժܺõı����������

StackNode* StackInit();	//  ��ʼ��ջ

void StackPush(StackNode* ST, Stack_DataType* val);	// ѹջ����

StackNode* StackPop(StackNode* ST);	// ��ջ����

bool IsStackEmpty(StackNode* ST);	// �ж�ջ��

void StackDestroy(StackNode* ST);	// ����ջ

void PreOrder_1(TreeNode* RootNode);	// ������--�������--��-��-�ң��ǵݹ飩

void InOrder_1(TreeNode* RootNode);	// ������--�������--��-��-�ң��ǵݹ飩

void PostOrder_1(TreeNode* RootNode);		// ������--�������--��-��-�����ǵݹ飩
