#define _CRT_SECURE_NO_WARNINGS
#include"Huffman_Tree.h"

Huffman_Tree* Huffman_TreeInit(int* weight, int length)
{
	Huffman_Tree* HFTree = (Huffman_Tree*)malloc(sizeof(Huffman_Tree));
	HFTree->data = (TreeNode*)malloc(sizeof(TreeNode) * (2 * length - 1));
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

void select_minweight(Huffman_Tree* HFTree)	// 选取最小权值的两个结点
{
	
}