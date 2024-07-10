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
	int rtag;	// 左右标志位：用于判断左右孩子指针是指向前驱后继（tag == 1）还是左右孩子（tag == 0）
	char data;
};

// 二叉树先、中、后序遍历
void Create_BinaryTree(TreeNode** RootNode,char* val,int* index, TreeNode* parent);

bool Tree_IsEmpty(TreeNode* RootNode);

void PreOrder(TreeNode* RootNode);

void InOrder(TreeNode* RootNode);

void PostOrder(TreeNode* RootNode);

void Destroy_BinaryTree(TreeNode* node);

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

// 二叉树线索化
void InOrder_Thread(TreeNode* T, TreeNode** pre);	// 中序线索化
TreeNode* First_InOrder(TreeNode* T);	// 寻找中序线索的第一个节点
TreeNode* Next_InOrder(TreeNode* T);	// 寻找中序线索的后继节点
TreeNode* Last_InOrder(TreeNode* T);	// 寻找中序线索的最后一个结点
TreeNode* Pre_InOrder(TreeNode* T);		// 寻找中序线索的前驱节点

void InOrder_ThreadTree(TreeNode* T);	// 线索化中序遍历
void InOrder_ThreadTree_Rev(TreeNode* T);	// 线索化中序逆遍历

void PreOrder_Thread(TreeNode* T, TreeNode** pre);	// 先序线索化
TreeNode* First_PreOrder(TreeNode* T);	// 寻找先序线索的第一个节点
TreeNode* Next_PreOrder(TreeNode* T);	// 寻找先序线索的后继节点
TreeNode* Last_PreOrder(TreeNode* T);	// 寻找先序线索的最后一个结点
TreeNode* Pre_PreOrder(TreeNode* T);		// 寻找先序线索的前驱节点

void PreOrder_ThreadTree(TreeNode* T);	// 线索化先序遍历
void PreOrder_ThreadTree_Rev(TreeNode* T);	// 线索化先序逆遍历


void PostOrder_Thread(TreeNode* T, TreeNode** pre);	// 后序线索化
TreeNode* First_PostOrder(TreeNode* T);	// 寻找后序线索的第一个节点
TreeNode* Next_PostOrder(TreeNode* T);	// 寻找后序线索的后继节点
TreeNode* Last_PostOrder(TreeNode* T);	// 寻找后序线索的最后一个结点
TreeNode* Pre_PostOrder(TreeNode* T);		// 寻找后序线索的前驱节点

void PostOrder_ThreadTree(TreeNode* T);	// 线索化后序遍历
void PostOrder_ThreadTree_Rev(TreeNode* T);	// 线索化后序逆遍历
