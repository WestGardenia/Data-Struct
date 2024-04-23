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
	int flag;	// 判断对应位置节点是否被访问过
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
// 利用栈的先进后出的结构特点去实现
// 本质上，递归遍历也是对编译器函数栈帧的使用。也是利用栈实现
// 非递归遍历需要创建一个数据结构---栈
// 非递归（前序、中序）遍历思路：
// 1、入栈根节点
// 2、循环——直到左孩子为空
// 3、出栈，访问节点，入栈右孩子
// 4、循环上述操作，直到栈空为止
// 5、前序遍历遍历顺序为进栈顺序（先访问，再进栈，再出栈）   //  中序遍历遍历顺序为出栈顺序（先进栈，再访问，再进栈）
//
typedef struct StackNode StackNode;
typedef TreeNode Stack_DataType;

struct StackNode {
	Stack_DataType* val;
	StackNode* next;
};	// 这里采用链表的形式定义栈是因为并不能确定数的层次。链表的动态开辟内存可以很好的避免溢出问题

StackNode* StackInit();	//  初始化栈

void StackPush(StackNode* ST, Stack_DataType* val);	// 压栈操作

StackNode* StackPop(StackNode* ST);	// 退栈操作

bool IsStackEmpty(StackNode* ST);	// 判断栈空

void StackDestroy(StackNode* ST);	// 销毁栈

void PreOrder_1(TreeNode* RootNode);	// 二叉树--先序遍历--根-左-右（非递归）

void InOrder_1(TreeNode* RootNode);	// 二叉树--中序遍历--左-根-右（非递归）

void PostOrder_1(TreeNode* RootNode);		// 二叉树--后序遍历--左-右-根（非递归）
