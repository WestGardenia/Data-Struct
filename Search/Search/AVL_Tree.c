#define _CRT_SECURE_NO_WARNINGS

#include"AVL_Tree.h"

AVLnode* AVLNode_Init(int val)
{
	AVLnode* newnode = (AVLnode*)malloc(sizeof(AVLnode));

	newnode->data = val;
	newnode->height = 0;
	newnode->lchild = NULL;
	newnode->rchild = NULL;

	return newnode;
}

int Get_Height(AVLnode* node)
{
	if (node == NULL)
		return 0;
	else
		return node->height;
}

int Get_Max(int a, int b)
{
	return a > b ? a : b;
}

void LL_Rotation(AVLnode* node, AVLnode** root)
{
	AVLnode* temp = node->lchild;
	node->lchild = temp->rchild;
	temp->rchild = node;
	node->height = Get_Max(Get_Height(node->lchild), Get_Height(node->rchild)) + 1;
	temp->height = Get_Max(Get_Height(temp->lchild), Get_Height(temp->rchild)) + 1;
	(*root) = temp;
}

void RR_Rotation(AVLnode* node, AVLnode** root)
{
	AVLnode* temp = node->rchild;
	node->rchild = temp->lchild;
	temp->lchild = node;
	node->height = Get_Max(Get_Height(node->lchild), Get_Height(node->rchild)) + 1;
	temp->height = Get_Max(Get_Height(temp->lchild), Get_Height(temp->rchild)) + 1;
	(*root) = temp;
}

void AVL_Tree_Insert(AVLnode** T, int val)
{
	if ((*T) == NULL)
	{
		(*T) = AVLNode_Init(val);
		printf("插入成功\n");
	}
	
	else if (val > (*T)->data)
	{
		AVL_Tree_Insert(&((*T)->rchild), val);
		int L_height = Get_Height((*T)->lchild);
		int R_height = Get_Height((*T)->rchild);
		if(R_height - L_height == 2)
		{
			if (val > (*T)->rchild->data)
			{
				// RR 调整
				RR_Rotation(*T, T);
			}
			else
			{
				// RL 调整
				LL_Rotation((*T)->rchild, &((*T)->rchild));
				RR_Rotation(*T, T);
			}
		}
	}

	else if (val < (*T)->data)
	{
		AVL_Tree_Insert(&((*T)->lchild), val);
		int L_height = Get_Height((*T)->lchild);
		int R_height = Get_Height((*T)->rchild);
		if (L_height - R_height == 2)
		{
			if (val < (*T)->lchild->data)
			{
				// LL 调整
				LL_Rotation(*T, T);
			}
			else
			{
				// LR 调整
				RR_Rotation((*T)->lchild, &((*T)->lchild));
				LL_Rotation(*T, T);
			}
		}
	}

	(*T)->height = Get_Max(Get_Height((*T)->lchild), Get_Height((*T)->rchild))+1;
}

void AVL_Tree_InOrder(AVLnode* T)
{
	if (T != NULL)
	{
		AVL_Tree_InOrder(T->lchild);
		printf("%d -> ", T->data);
		AVL_Tree_InOrder(T->rchild);
	}
}

void AVL_Tree_PreOrder(AVLnode* T)
{
	if (T != NULL)
	{
		printf("%d -> ", T->data);
		AVL_Tree_PreOrder(T->lchild);
		AVL_Tree_PreOrder(T->rchild);
	}
}