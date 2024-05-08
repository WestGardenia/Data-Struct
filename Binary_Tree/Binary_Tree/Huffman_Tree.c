#define _CRT_SECURE_NO_WARNINGS
#include"Huffman_Tree.h"

Huffman_Tree* Huffman_TreeInit(int* weight, int length)
{
	Huffman_Tree* HFTree = (Huffman_Tree*)malloc(sizeof(Huffman_Tree));
	if (HFTree == NULL)
	{
		return NULL;
		exit(-1);
	}
	HFTree->data = (HF_TreeNode*)malloc(sizeof(HF_TreeNode) * (2 * length - 1));
	if (HFTree->data == NULL)
	{
		return NULL;
		exit(-1);
	}
	HFTree->length = length;
	for (int i = 0; i < length; i++)
	{
		HFTree->data[i].weight = weight[i];
		HFTree->data[i].parent = 0;
		HFTree->data[i].Lchild = -1;
		HFTree->data[i].Rchild = -1;
	}
	return HFTree;
}

int* select_minweight(Huffman_Tree* HFTree)	// 选取最小权值的两个结点
{
	int min = 10000;
	int secondmin = 10000;
	int minIndex = 0;
	int secondIndex = 0;
	for (int i = 0; i < HFTree->length; i++)
	{
		if (HFTree->data[i].parent == 0)
		{
			if (HFTree->data[i].weight < min)
			{
				min = HFTree->data[i].weight;
				minIndex = i;
			}
		}
	}
	for (int i = 0; i < HFTree->length; i++)
	{
		if (HFTree->data[i].parent == 0 && i != minIndex)
		{
			if (HFTree->data[i].weight < secondmin)
			{
				secondmin = HFTree->data[i].weight;
				secondIndex = i;
			}
		}
	}
	int* res = (int*)malloc(sizeof(int) * 2);
	if (res == NULL)
	{
		return NULL;
		exit(-1);
	}
	res[0] = minIndex;
	res[1] = secondIndex;
	return res;
}

void createHFTree(Huffman_Tree* HFTree)	// 创建哈夫曼树
{
	int* res;
	int min;
	int secondmin;
	int length = HFTree->length * 2 - 1;
	for (int i = HFTree->length; i < length; i++)
	{
		res = select_minweight(HFTree);
		min = res[0];
		secondmin = res[1];

		HFTree->data[i].weight = HFTree->data[min].weight + HFTree->data[secondmin].weight;
		// 选取最小权值的两个节点进行合并时，需要将合并的结点的parent置0，VS里的编译器并不能自动将其置0，会产生bug
		HFTree->data[i].parent = 0;
		HFTree->data[i].Lchild = min;
		HFTree->data[i].Rchild = secondmin;
		HFTree->data[min].parent = i;
		HFTree->data[secondmin].parent = i;

		HFTree->length++;
	}
}

void HFT_preOrder(Huffman_Tree* HFTree, int index)
{
	if (index != -1)
	{
		// 这里的index一开始实际上是指顺序表中逻辑上根结点的位置
		// 原本传入的权值表构成的结点中的权值会被当成哈夫曼树中非叶子节点的左右孩子的权值
		// 这样就可以直接访问节点权值而非再次遍历每个结点了
		printf("%d->", HFTree->data[index].weight);
		HFT_preOrder(HFTree, HFTree->data[index].Lchild);
		HFT_preOrder(HFTree, HFTree->data[index].Rchild);
	}
}