#define _CRT_SECURE_NO_WARNINGS

#include"BST_Function.h"

BST* BST_Init(int val)
{
	BST* T = (BST*)malloc(sizeof(BST));
	if (!T)
	{
		return NULL;
		exit(-1);
	}
	T->data = val;
	T->lchild = NULL;
	T->rchild = NULL;
	return T;
}

void BST_InOrder(BST* T)
{
	if (T != NULL)
	{
		BST_InOrder(T->lchild);
		printf("%d->", T->data);
		BST_InOrder(T->rchild);
	}
}

BST* BST_Search(BST* T, int val)
{
	BST* cur = T;
	int count = 0;	// �����жϲ��Ҵ���
	while (cur != NULL && cur->data != val)
	{
		count++;
		if (val < cur->data)
		{
			cur = cur->lchild;
		}
		else if (val > cur->data)
		{
			cur = cur->rchild;
		}
	}
	if (count == 0)
	{
		if (cur == NULL)
			printf("����������Ϊ�գ�����ʧ�ܣ�����\n");
		else
			printf("���ҳɹ���valֵΪ�����������еĸ��ڵ��д�ŵ�ֵ��%d\n", cur->data);
	}
	if (count != 0)
	{
		if (cur == NULL)
			printf("�Ѿ�����������������������δ�ܼ�⵽��Ӧ�ڵ㣬����ʧ��\n");
		else
			printf("���ҳɹ�������\n");
	}

	return cur;
}

void BST_Insert(BST** T, int val)
{
	// 1������������Ϊ�գ��򽫲���ڵ��Ϊ�����
	if (!(*T))
	{
		(*T) = BST_Init(val);
		(*T)->data = val;
	}
	else
	{
		// 2����������ͬ�ڵ㣬�����ʧ��
		if ((*T)->data == val)
		{
			printf("�����������д��ڲ���ڵ�ֵ��%d������ʧ��\n", val);
			return;
		}
		// 3������ֵ�ȸ�����
		if ((*T)->data < val)
		{
			BST_Insert(&((*T)->rchild), val);
		}
		// 4������ֵ�ȸ��ڵ�С
		if ((*T)->data > val)
		{
			BST_Insert(&((*T)->lchild), val);
		}
	}
}

void BST_Creat(BST** T, int arr[], int num)
{
	*T = NULL;
	for (int i = 0; i < num; i++)
	{
		BST_Insert(T, arr[i]);
	}
}


// �������������ڲ���Ҫɾ���ڵ��ֱ��ǰ��
BST* FindMin(BST* node) {
	while (node->lchild != NULL) {
		node = node->lchild;
	}
	return node;
}

BST* BST_Delete(BST* T, int val) {
	if (!T) {
		printf("ɾ��ʧ�ܣ�û���ҵ�Ҫɾ����ֵ������\n");
		return T;
	}

	BST* parent = NULL;
	BST* current = T;	// ��ɾ�����
	BST* temp;
	while (current != NULL && current->data != val) {
		// �ڱ��������������Ĺ����У�˳�������ڵ�parent�ҵ�
		parent = current;
		if (val < current->data) {
			current = current->lchild;
		}
		else {
			current = current->rchild;
		}
	}

	if (!current) {
		printf("ɾ��ʧ�ܣ�û���ҵ�Ҫɾ����ֵ������\n");
		return T;
	}

	// �ҵ�Ҫɾ���Ľڵ�
	if (current->lchild == NULL) {
		temp = current->rchild;
		free(current);
		if (parent) {
			if (parent->lchild == current) {
				parent->lchild = temp;
			}
			else {
				parent->rchild = temp;
			}
		}
		else {
			T = temp; // ���ɾ�����Ǹ��ڵ�
		}
	}
	else if (current->rchild == NULL) {
		temp = current->lchild;
		free(current);
		if (parent) {
			if (parent->lchild == current) {
				parent->lchild = temp;
			}
			else {
				parent->rchild = temp;
			}
		}
		else {
			T = temp; // ���ɾ�����Ǹ��ڵ�
		}
	}
	else {
		// �ҵ�����������С�ڵ㣬��ֱ�Ӻ�̣�������ڵ��ֵ��Ϊ������ڴ�ɾ������У���ʾɾ���ɹ�
		BST* successor = FindMin(current->rchild);
		current->data = successor->data; // ��ֱ�Ӻ�̵�ֵ�滻��ǰ�ڵ��ֵ
		temp = successor;
		// �ݹ�ɾ��ֱ�Ӻ�̽ڵ�
		current->rchild = BST_Delete(current->rchild, successor->data);
	}

	return T;
}