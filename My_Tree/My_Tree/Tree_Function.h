#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

// abd##e##cf##g##

//			a		
//		b		c
//	  d	  e	  f	  g
//

// 

typedef struct TreeNode TreeNode;

struct TreeNode {
	TreeNode* lchild;
	TreeNode* rchild;
	TreeNode* parent;
	int ltag;
	int rtag;	// ���ұ�־λ�������ж����Һ���ָ����ָ��ǰ����̣�tag == 1���������Һ��ӣ�tag == 0��
	char data;
};

// �������ȡ��С��������
void Create_BinaryTree(TreeNode** RootNode,char* val,int* index, TreeNode* parent);

bool Tree_IsEmpty(TreeNode* RootNode);

void PreOrder(TreeNode* RootNode);

void InOrder(TreeNode* RootNode);

void PostOrder(TreeNode* RootNode);

void Destroy_BinaryTree(TreeNode* node);

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

// ������������
void InOrder_Thread(TreeNode* T, TreeNode** pre);	// ����������
TreeNode* First_InOrder(TreeNode* T);	// Ѱ�����������ĵ�һ���ڵ�
TreeNode* Next_InOrder(TreeNode* T);	// Ѱ�����������ĺ�̽ڵ�
TreeNode* Last_InOrder(TreeNode* T);	// Ѱ���������������һ�����
TreeNode* Pre_InOrder(TreeNode* T);		// Ѱ������������ǰ���ڵ�

void InOrder_ThreadTree(TreeNode* T);	// �������������
void InOrder_ThreadTree_Rev(TreeNode* T);	// ���������������

void PreOrder_Thread(TreeNode* T, TreeNode** pre);	// ����������
TreeNode* First_PreOrder(TreeNode* T);	// Ѱ�����������ĵ�һ���ڵ�
TreeNode* Next_PreOrder(TreeNode* T);	// Ѱ�����������ĺ�̽ڵ�
TreeNode* Last_PreOrder(TreeNode* T);	// Ѱ���������������һ�����
TreeNode* Pre_PreOrder(TreeNode* T);		// Ѱ������������ǰ���ڵ�

void PreOrder_ThreadTree(TreeNode* T);	// �������������
void PreOrder_ThreadTree_Rev(TreeNode* T);	// ���������������


void PostOrder_Thread(TreeNode* T, TreeNode** pre);	// ����������
TreeNode* First_PostOrder(TreeNode* T);	// Ѱ�Һ��������ĵ�һ���ڵ�
TreeNode* Next_PostOrder(TreeNode* T);	// Ѱ�Һ��������ĺ�̽ڵ�
TreeNode* Last_PostOrder(TreeNode* T);	// Ѱ�Һ������������һ�����
TreeNode* Pre_PostOrder(TreeNode* T);		// Ѱ�Һ���������ǰ���ڵ�

void PostOrder_ThreadTree(TreeNode* T);	// �������������
void PostOrder_ThreadTree_Rev(TreeNode* T);	// ���������������
