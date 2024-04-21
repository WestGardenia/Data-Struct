#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef struct TreeNode TreeNode;

struct TreeNode {
	char data;
	TreeNode* LChild;	// 定义左孩子结点
	TreeNode* RChild;	// 定义右孩子节点
};

void TreeCreative(TreeNode** RootNode, char* data, int* index);	// 创建二叉树

// 三种遍历（先序、中序、后序）--递归遍历
void preOrder(TreeNode* RootNode);	// 二叉树--先序遍历--根-左-右

void inOrder(TreeNode* RootNode);	// 二叉树--中序遍历--左-根-右

void postOrder(TreeNode* RootNode);		// 二叉树--后序遍历--左-右-根

// 层次遍历
typedef struct Queue Queue;
typedef struct QNode QNode;
typedef TreeNode Queue_DataType;

struct QNode {
	QNode* next;
	Queue_DataType* data;
};

struct Queue {
	QNode* head;	// 指针域
	QNode* tail;	// 数据域
};	// 用链式队列存储树的不同层次的数据。依靠队列先进先出的特点进行遍历

//——————————————————————————————————————————————————————
// 队列---function部分
void QueueInit(Queue* pq);	// 队列的定义

void QueueDestroy(Queue* pq);	// 队列的销毁

void QueuePush(Queue* pq, Queue_DataType* x);	// 队列数据插入

void QueuePop(Queue* pq);	// 队列数据出队

Queue_DataType* QueueFront(Queue* pq);	// 取队头数据

Queue_DataType* QueueBack(Queue* pq);		// 取队尾数据

int QueueSize(Queue* pq);	// 计算队列长度

bool QueueEmpty(Queue* pq);	 //判断队列是否为空

//——————————————————————————————————————————————————————
// 树----function部分
void LevelTraverse(Queue* q, TreeNode* RootNode);	// 二叉树--层次遍历

//
// 二叉树--非递归遍历（顺序遍历）
