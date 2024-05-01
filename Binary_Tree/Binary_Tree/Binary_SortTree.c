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