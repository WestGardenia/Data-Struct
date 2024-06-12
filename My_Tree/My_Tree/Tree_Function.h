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

// 二叉树先、中、后序遍历
void Create_BinaryTree(TreeNode** RootNode,char* val,int* index);
void PreOrder(TreeNode* RootNode);
void InOrder(TreeNode* RootNode);
void PostOrder(TreeNode* RootNode);

// 二叉树层序遍历
//	算法思想：
//	1、创建辅助队列
//	2、将根节点入队
//	3、若队列非空，则队头结点出队，并访问该节点；并将该结点的左右孩子结点（如果有的话）入队（队尾）
//	4、重复步骤3
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
