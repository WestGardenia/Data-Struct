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
};

void TreeCreative(TreeNode** RootNode, char* data, int* index);	// ����������

// ���ֱ������������򡢺���--�ݹ����
void preOrder(TreeNode* RootNode);	// ������--�������--��-��-��

void inOrder(TreeNode* RootNode);	// ������--�������--��-��-��

void postOrder(TreeNode* RootNode);		// ������--�������--��-��-��

// ��α���
typedef struct Queue Queue;
typedef TreeNode Queue_DataType;

struct Queue {
	Queue* next;	// ָ����
	Queue_DataType* data;	// ������
};	// ����ʽ���д洢���Ĳ�ͬ��ε����ݡ����������Ƚ��ȳ����ص���б���

// ����---function����
void Create_Queue(Queue** q);	// ��������

void QueuePush(Queue** q, Queue_DataType* x);	// ���в�������--ͷ��

TreeNode* QueuePop(Queue** q);	// ����--ȡ��β����

bool IsQueueEmpty(Queue* q);	// ����--�ж϶����Ƿ�Ϊ��

void QueuePrint(Queue* q);	// ��ӡ����

// ��----function����
void LevelTraverse(Queue* q, TreeNode* RootNode);	// ������--��α���
