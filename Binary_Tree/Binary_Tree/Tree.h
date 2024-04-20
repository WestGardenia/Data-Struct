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
typedef TreeNode Queue_DataType;

struct Queue {
	Queue* next;	// 指针域
	Queue_DataType* data;	// 数据域
};	// 用链式队列存储树的不同层次的数据。依靠队列先进先出的特点进行遍历

// 队列---function部分
void Create_Queue(Queue** q);	// 创建队列

void QueuePush(Queue** q, Queue_DataType* x);	// 队列插入数据--头插

TreeNode* QueuePop(Queue** q);	// 队列--取队尾数据

bool IsQueueEmpty(Queue* q);	// 队列--判断队列是非为空

void QueuePrint(Queue* q);	// 打印队列

// 树----function部分
void LevelTraverse(Queue* q, TreeNode* RootNode);	// 二叉树--层次遍历
