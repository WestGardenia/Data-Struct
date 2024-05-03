#define _CRT_SECURE_NO_WARNINGS
#include"Binary_SortTree.h"

BST* BST_Search(BST* RootNode, int key)	// �ڶ����������в���keyֵ
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
		// �������Ľڵ�Ϊ��
		// 1����ʾ���������һ�ſ���
		// 2����ʾ�Ѿ���������Ҷ�ӽڵ�ȴ��Ȼû���ҵ��洢��Ӧ��ֵ�Ľ�㡣˵��û�ж�Ӧ���
		if (count == 0)
		{
			printf("��Ϊ�գ��޷�Ѱ��\n");
		}
		else
		{
			printf("δ�ҵ���Ӧֵ\n");
		}
		return NULL;
	}
}

void BST_Insert(BST** RootNode, int data)	// �����������������
{
	if (*RootNode == NULL)
	{
		// ����������ǿյģ���ô������Ҫ���������г�ʼ������
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
			// �����������в���������ͬ��ֵ�Ľ��
			// ���ԣ��������ֵͬ����������
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

int GetHeight(AVL_Tree* RootNode)	// ȡ��ǰ���ĸ߶�
{
	return RootNode ? RootNode->height : 0;
}

int GetMax(int a, int b)
{
	return a > b ? a : b;
}

void RR_Rotation(AVL_Tree** RootNode, AVL_Tree* node)	// RR��������
{
	AVL_Tree* temp = node->Rchild;
	node->Rchild = temp->Lchild;
	temp->Lchild = node;

	node->height = max(GetHeight(node->Rchild), GetHeight(node->Lchild)) + 1;
	temp->height = max(GetHeight(temp->Rchild), GetHeight(temp->Lchild)) + 1;

	(*RootNode) = temp;
}

void LL_Rotation(AVL_Tree** RootNode, AVL_Tree* node)	// LL��������
{
	AVL_Tree* temp = node->Lchild;
	node->Lchild = temp->Rchild;
	temp->Rchild = node;

	node->height = max(GetHeight(node->Rchild), GetHeight(node->Lchild)) + 1;
	temp->height = max(GetHeight(temp->Rchild), GetHeight(temp->Lchild)) + 1;

	(*RootNode) = temp;
}

void AVL_Insert(AVL_Tree** RootNode, int data)		// ����AVL��
{
	if (*RootNode == NULL)
	{
		(*RootNode) = (AVL_Tree*)malloc(sizeof(AVL_Tree));
		if (*RootNode == NULL)
		{
			return;
			exit(-1);
		}
		(*RootNode)->val = data;
		(*RootNode)->height = 0;
		(*RootNode)->Lchild = NULL;
		(*RootNode)->Rchild = NULL;
	}
	else
	{
		if (data < (*RootNode)->val)
		{
			AVL_Insert(&((*RootNode)->Lchild), data);
			int L_Height = GetHeight((*RootNode)->Lchild);
			int R_Height = GetHeight((*RootNode)->Rchild);

			if (L_Height - R_Height == 2)
			{
				if (data < (*RootNode)->Lchild->val)
				{
					// LL����
					LL_Rotation(RootNode, *RootNode);
				}
				else
				{
					// LR����
					RR_Rotation(&(*RootNode)->Lchild, (*RootNode)->Lchild);
					LL_Rotation(RootNode, *RootNode);
				}
			}
		}
		if (data > (*RootNode)->val)
		{
			AVL_Insert(&((*RootNode)->Rchild), data);
			int L_Height = GetHeight((*RootNode)->Lchild);
			int R_Height = GetHeight((*RootNode)->Rchild);

			if (R_Height - L_Height == 2)
			{
				if (data > (*RootNode)->Rchild->val)
				{
					// RR����
					RR_Rotation(RootNode, *RootNode);
				}
				else
				{
					// RL����
					LL_Rotation(&(*RootNode)->Rchild, (*RootNode)->Rchild);
					RR_Rotation(RootNode, *RootNode);
				}
			}
		}
	}
	(*RootNode)->height = GetMax(GetHeight((*RootNode)->Rchild), GetHeight((*RootNode)->Lchild))+1;
}

void AVL_PreOrder(AVL_Tree* RootNode)	// AVL�������
{
	if(RootNode)
	{
		printf("%d->", RootNode->val);

		AVL_PreOrder(RootNode->Lchild);
		AVL_PreOrder(RootNode->Rchild);
	}
}