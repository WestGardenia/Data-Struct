#define _CRT_SECURE_NO_WARNINGS

#include"Tree_Function.h"

void Create_BinaryTree(TreeNode** RootNode, char* val, int* index)
{
	(*RootNode) = (TreeNode*)malloc(sizeof(TreeNode));
	if ((*RootNode) == NULL)
	{
		return;
	}
	char ch;
	ch = val[*index];
	(*index)++;
	if (ch == '#')
	{
		(*RootNode) = NULL;
	}
	else
	{
		//(*RootNode) = (TreeNode*)malloc(sizeof(TreeNode));
		(*RootNode)->data = ch;

		Create_BinaryTree(&((*RootNode)->lchild), val, index);
		Create_BinaryTree(&((*RootNode)->rchild), val, index);
	}

}

void PreOrder(TreeNode* RootNode)
{
	if (RootNode != NULL)
	{
		printf("%c -> ", RootNode->data);
		PreOrder(RootNode->lchild);
		PreOrder(RootNode->rchild);
	}
	else
	{
		return;
	}
}

void InOrder(TreeNode* RootNode)
{
	if (RootNode != NULL)
	{
		InOrder(RootNode->lchild);
		printf("%c -> ", RootNode->data);
		InOrder(RootNode->rchild);
	}
	else
	{
		return;
	}
}

void PostOrder(TreeNode* RootNode)
{
	if (RootNode != NULL)
	{
		PostOrder(RootNode->lchild);
		PostOrder(RootNode->rchild);
		printf("%c -> ", RootNode->data);
	}
	else
	{
		return;
	}
}