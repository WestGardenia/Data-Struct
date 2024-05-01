#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

// 二叉排序树----BST（Binary Sort Tree）
// 一棵树的左子树上的所有结点的值都比根节点小；右子树上的所有结点的值都比根节点的值大；
// 同时，这个性质对于这棵树的所有子树都成立（递归性质）

// 构建BST：
// 对于这样一个数据：4、5、19、23、2、8
// 以4为根结点构建，然后将剩下的数字与4比较
//		5比4大：5作为4的右孩子
//		19比4大，同时比5大：19作为5的右孩子
//		23比4、5、19都大：23作为19的右孩子
//		2比4小：2作为4的左孩子
//		……
//		以此类推
//			4
//		2		5
//		  	  		19
//				  8		23
//


typedef struct Binary_SortTree BST;

struct Binary_SortTree {
	int val;
	BST* Lchild;
	BST* Rchild;
};

void BST_Insert(BST** RootNode, int data);	// 创建二叉排序树结点

BST* BST_Search(BST* RootNode, int key);	// 在二叉排序树中查找值

void PreOrder_BST(BST* RootNode);	// 前序遍历