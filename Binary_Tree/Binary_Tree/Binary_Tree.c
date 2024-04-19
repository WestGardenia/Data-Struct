#define _CRT_SECURE_NO_WARNINGS
#include"Tree.h"

void TreeCreative(TreeNode** RootNode,char* data,int* index)	// 创建二叉树
{
	if ((*RootNode) == NULL)
	{
		exit(-1);
	}
	// 由于创建二叉树的函数对形参RootNode结构内部造成了改变。所以需要传入二级指针
	char ch;
	ch = data[*index];
	(*index)++;	// 由于是递归调用，所以要想在递归时改变index索引位置，就必须传入index的指针
	if (ch == '#')
	{
		// 定义输入‘#’时，节点为空结点
		*RootNode = NULL;
	}
	else
	{
		// 递归定义左右子树（本质上，创建的树节点的左右孩子结点也是一棵树）
		*RootNode = (TreeNode*)malloc(sizeof(TreeNode));
		(*RootNode)->data = ch;
		TreeCreative(&((*RootNode)->LChild),data,index);
		TreeCreative(&((*RootNode)->RChild),data,index);
	}
}

void preOrder(TreeNode* RootNode)	// 二叉树--先序遍历--根-左-右
{
	if (RootNode == NULL)
	{
		return;
	}
	printf("%c->", RootNode->data);
	preOrder(RootNode->LChild);
	preOrder(RootNode->RChild);
}

void inOrder(TreeNode* RootNode)	// 二叉树--中序遍历--左-根-右
{
	if (RootNode == NULL)
	{
		return;
	}
	inOrder(RootNode->LChild);

	printf("%c->", RootNode->data);
	
	inOrder(RootNode->RChild);
}

void postOrder(TreeNode* RootNode)		// 二叉树--后序遍历--左-右-根
{
	if (RootNode == NULL)
	{
		return;
	}
	postOrder(RootNode->LChild);

	postOrder(RootNode->RChild);

	printf("%c->", RootNode->data);
}