#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

// 树——是一种非线性的数据结构
// 线性结构是由前驱和后继的——而二叉树只有后继，没有前驱
// 而线索二叉树本质上是一种将树模拟出来的线性结构
// 对于一棵树来说，如果它有 2n 个结点。那么它将有 n-1 个指针指向这些结点
// 那么在剩下的叶子结点中，会有剩下 2n - （ n - 1 ） 个指针没有使用。而这 n + 1 个指针指向二叉树的前驱
// 这就是所谓的线索二叉树

//          A
//     B		 C
// D	  E	  F		G	
// 对于像这样一颗二叉树，其
// 先序遍历结果为：
// A	B	D	E	C	F	G
// 中序遍历结果为：
// D	B	E	A	F	C	G
// 后序遍历结果为：
// D	E	B	F	G	C	A
// 将中序遍历得到的结果看作为一种线性结构（比如链表），那么我们可以得到这样一种类似双链表（实际为二叉树）的类线性结构
// NULL	<----- D <----> B <----> E <----> A <----> C ----> NULL
// 在这样一种数据结构中 D 的前驱为空指针（可以是哨兵位的头结点）
//						E 的后继为空指针，作为链表的结尾标志
// 它们这些用来指向前驱和后继的指针就是原二叉树中作为叶子节点而没有用上的空的左右孩子节点（就是那 n+1 个指针）
// 空的RChild指向它的后继——如果某个节点的RChild中存放的是右孩子节点，则其RFlag置0；相反，如果存放的是这个节点的后继，则RFlag置1
// 空的LChild指向它的前驱——如果某个节点的LChild中存放的是左孩子节点，则其LFlag置0；相反，如果存放的是这个节点的前驱，则LFlag置1
// 
// 这样，一种逻辑结构上为树，物理结构为链表的数据结构就完成了
// 

typedef struct Thread_TreeNode Thread_TreeNode;

struct Thread_TreeNode {
	char data;
	Thread_TreeNode* LChild;	// 定义左孩子结点
	Thread_TreeNode* RChild;	// 定义右孩子节点
	Thread_TreeNode* Parent;	// 定义双亲结点----后序遍历特有
	int LFlag;	// 判断左孩子结点指向位置
	int RFlag;	// 判断右孩子结点指向位置

};

void Thread_TreeCreative(Thread_TreeNode** RootNode, char* data, int* index, Thread_TreeNode* parent);	// 创建二叉树

void InThread_Tree(Thread_TreeNode* RootNode, Thread_TreeNode** pre);	// 二叉树线索化

void PreThread_Tree(Thread_TreeNode* RootNode, Thread_TreeNode** pre);	// 线索二叉树--先序遍历--左-根-右

//Thread_TreeNode* Pre_GetFirst(Thread_TreeNode* RootNode);
// 不需要去取结点函数，是因为头结点就是二叉树根结点

Thread_TreeNode* Pre_GetNext(Thread_TreeNode* RootNode);

void InThread_Tree(Thread_TreeNode* RootNode, Thread_TreeNode** pre);	// 线索二叉树--中序遍历--左-根-右

Thread_TreeNode* In_GetFirst(Thread_TreeNode* RootNode);

Thread_TreeNode* In_GetNext(Thread_TreeNode* RootNode);

void PostThread_Tree(Thread_TreeNode* RootNode, Thread_TreeNode** pre);	// 线索二叉树--后序遍历--左-根-右

Thread_TreeNode* Post_GetFirst(Thread_TreeNode* RootNode);

Thread_TreeNode* Post_GetNext(Thread_TreeNode* RootNode);
