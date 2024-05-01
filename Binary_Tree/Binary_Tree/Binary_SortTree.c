#define _CRT_SECURE_NO_WARNINGS
#include"Binary_SortTree.h"

BST* BST_Search(BST* RootNode, int key)	// 在二叉排序树中查找key值
{
	int count = 0;
	count++;
	if(RootNode)
	{
		if (key > RootNode->val)
		{
			return BST_Search(RootNode->Rchild, key);
		}
		else if (key < RootNode->val)
		{
			return BST_Search(RootNode->Lchild, key);
		}
		else if (RootNode->val == key)
		{
			return RootNode;
		}
	}
	else if (RootNode == NULL)
	{
		// 如果传入的节点为空
		// 1、表示传入的树是一颗空树
		// 2、表示已经遍历到了叶子节点却仍然没有找到存储相应的值的结点。说明没有对应结点
		if (count == 0)
		{
			printf("树为空，无法寻找\n");
		}
		else
		{
			printf("未找到相应值\n");
		}
		return NULL;
	}
}

void BST_Insert(BST** RootNode, int data)	// 创建二叉排序树结点
{
	if (*RootNode == NULL)
	{
		// 如果二叉树是空的，那么首先需要将根结点进行初始化操作
		*RootNode = (BST*)malloc(sizeof(BST));
		if ((*RootNode) == NULL)
		{
			return;
		}
		(*RootNode)->val = data;
		(*RootNode)->Lchild = NULL;
		(*RootNode)->Rchild = NULL;
	}
	else
	{
		if ((*RootNode)->val > data)
		{
			BST_Insert(&((*RootNode)->Lchild), data);
		}
		else if ((*RootNode)->val == data)
		{
			// 二叉排序树中不允许有相同的值的结点
			// 所以，如果有相同值，则不做处理
			return;
		}
		else if ((*RootNode)->val < data)
		{
			BST_Insert(&((*RootNode)->Rchild), data);
		}
	}
}

void PreOrder_BST(BST* RootNode)
{
	if(RootNode)
	{
		printf("%d->", RootNode->val);

		PreOrder_BST(RootNode->Lchild);
		PreOrder_BST(RootNode->Rchild);
	}
}