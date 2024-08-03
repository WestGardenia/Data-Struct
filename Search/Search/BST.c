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
	int count = 0;	// 用于判断查找次数
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
			printf("二叉排序树为空，查找失败！！！\n");
		else
			printf("查找成功，val值为二叉排序树中的根节点中存放的值：%d\n", cur->data);
	}
	if (count != 0)
	{
		if (cur == NULL)
			printf("已经按需搜索过二叉排序树，未能检测到对应节点，查找失败\n");
		else
			printf("查找成功！！！\n");
	}

	return cur;
}

void BST_Insert(BST** T, int val)
{
	// 1、二叉排序树为空，则将插入节点记为根结点
	if (!(*T))
	{
		(*T) = BST_Init(val);
		(*T)->data = val;
	}
	else
	{
		// 2、若存在相同节点，则插入失败
		if ((*T)->data == val)
		{
			printf("二叉排序树中存在插入节点值：%d，插入失败\n", val);
			return;
		}
		// 3、插入值比根结点大
		if ((*T)->data < val)
		{
			BST_Insert(&((*T)->rchild), val);
		}
		// 4、插入值比根节点小
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


// 辅助函数，用于查找要删除节点的直接前驱
BST* FindMin(BST* node) {
	while (node->lchild != NULL) {
		node = node->lchild;
	}
	return node;
}

BST* BST_Delete(BST* T, int val) {
	if (!T) {
		printf("删除失败，没有找到要删除的值！！！\n");
		return T;
	}

	BST* parent = NULL;
	BST* current = T;	// 待删除结点
	BST* temp;
	while (current != NULL && current->data != val) {
		// 在遍历二叉搜索树的过程中，顺带将父节点parent找到
		parent = current;
		if (val < current->data) {
			current = current->lchild;
		}
		else {
			current = current->rchild;
		}
	}

	if (!current) {
		printf("删除失败，没有找到要删除的值！！！\n");
		return T;
	}

	// 找到要删除的节点
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
			T = temp; // 如果删除的是根节点
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
			T = temp; // 如果删除的是根节点
		}
	}
	else {
		// 找到右子树的最小节点，即直接后继，将这个节点的值作为替代放在待删除结点中，表示删除成功
		BST* successor = FindMin(current->rchild);
		current->data = successor->data; // 用直接后继的值替换当前节点的值
		temp = successor;
		// 递归删除直接后继节点
		current->rchild = BST_Delete(current->rchild, successor->data);
	}

	return T;
}