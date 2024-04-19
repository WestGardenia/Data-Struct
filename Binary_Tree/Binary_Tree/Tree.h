#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

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

// 层次遍历（深度优先、广度优先）

