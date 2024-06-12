#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

// abd##e##cf##g##

//			a		
//		b		c
//	  d	  f	  f	  g
//


typedef struct TreeNode TreeNode;

struct TreeNode {
	TreeNode* lchild;
	TreeNode* rchild;
	char data;
};

// �������ȡ��С��������
void Create_BinaryTree(TreeNode** RootNode,char* val,int* index);
void PreOrder(TreeNode* RootNode);
void InOrder(TreeNode* RootNode);
void PostOrder(TreeNode* RootNode);

// �������������
//	�㷨˼�룺
//	1��������������
//	2�������ڵ����
//	3�������зǿգ����ͷ�����ӣ������ʸýڵ㣻�����ý������Һ��ӽ�㣨����еĻ�����ӣ���β��
//	4���ظ�����3
// 

typedef struct QueueNode QueueNode;
typedef TreeNode QueueNode_Type;

struct QueueNode {
	QueueNode* next;
	QueueNode_Type* data;
};

typedef struct Queue Queue;

struct Queue {
	QueueNode* head;
	QueueNode* tail;
};

Queue* Queue_Init();
QueueNode* QueueNode_Init(TreeNode* T);
bool Queue_IsEmpty(Queue* Q);
void Queue_PushTail(Queue* Q, QueueNode* pQ);
void Queue_PopHead(Queue* Q);
QueueNode_Type* Get_QueueHead(Queue* Q);
void Queue_Destroy(Queue* Q);
void QueueNode_Destroy(QueueNode* pQ);

void BinaryTree_LevelOrder(TreeNode* T);
