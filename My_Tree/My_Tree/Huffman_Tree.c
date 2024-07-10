#define _CRT_SECURE_NO_WARNINGS

#include"Tree_Function.h"
#include"Huffman_Tree_Function.h"
// 在含有n个带权叶结点的二叉树中，带权路径长度和最小的的二叉树称为哈夫曼树（Huffman_Tree），也叫做最优二叉树

Huffman_Tree* Huffman_TreeInit(int* weight, int length)
{
	Huffman_Tree* HF = (Huffman_Tree*)malloc(sizeof(Huffman_Tree));
	if (HF == NULL)
	{
		return NULL;
		exit(-1);
	}
	HF->data = (H_TreeNode*)malloc(sizeof(H_TreeNode) * (2 * length - 1));
	if (HF->data == NULL)
	{
		return NULL;
		exit(-1);
	}
	HF->length = length;
	for (int i = 0; i < length; i ++ )
	{
		HF->data[i].weight = weight[i];
		HF->data[i].lchild = -1;
		HF->data[i].rchild = -1;
		HF->data[i].parent = 0;
	}
	return HF;
}

void Sort(int* weight, int length)	// 对字符集权值数组进行排序
{
	int min = 0;
	for (int i = 0; i < length; i++)
	{
		for (int j = i; j < length; j++)
		{
			if (weight[j] < weight[i])
			{
				min = weight[j];
				weight[j] = weight[i];
				weight[i] = min;
			}
		}
	}
}

int* Select(Huffman_Tree* HT)	// 选择权值数组中最小的两个值并赋给哈夫曼树结点的权值中
{
	int min = INT_MAX;
	int sec_min = INT_MAX;
	int MinIndex = 0;
	int second_MinIndex = 0;

	for (int i = 0; i < HT->length; i++)
	{
		if(HT->data[i].parent == 0)
		{
			if (min > HT->data[i].weight)
			{
				min = HT->data[i].weight;
				MinIndex = i;
			}
		}
	}	
	for (int i = 0; i < HT->length; i++)
	{
		if (HT->data[i].parent == 0)
		{
			if (sec_min > HT->data[i].weight && i != MinIndex)
			{
				sec_min = HT->data[i].weight;
				second_MinIndex = i;
			}
		}
	}
	int* arr = (int*)malloc(sizeof(int) * 2);
	if (arr == NULL)
	{
		return NULL;
		exit(-1);
	}
	arr[0] = MinIndex;
	arr[1] = second_MinIndex;

	return arr;
}

Huffman_Tree* Huffman_Treecreative(Huffman_Tree* HT)	// 创建哈夫曼树
{
	//int min = 0;
	//int sec_min = 0;
	int length = HT->length * 2 - 1;
	for (int i = HT->length; i < length; i++)
	{
		int* arr = Select(HT);
		
		HT->data[i].weight = HT->data[arr[0]].weight + HT->data[arr[1]].weight;
		HT->data[i].lchild = arr[0];
		HT->data[i].rchild = arr[1];
		HT->data[i].parent = 0;

		HT->data[arr[0]].parent = i;
		HT->data[arr[1]].parent = i;

		HT->length++;
	}

	return HT;
}

void Huffman_Tree_pre(Huffman_Tree* HT,int index)
{
	if (index != -1)
	{
		printf("%d-> ", HT->data[index].weight);
		Huffman_Tree_pre(HT, HT->data[index].lchild);
		Huffman_Tree_pre(HT, HT->data[index].rchild);
	}
}