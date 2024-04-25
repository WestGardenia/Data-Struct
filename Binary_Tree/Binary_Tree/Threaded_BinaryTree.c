#define _CRT_SECURE_NO_WARNINGS
#include"Threaded_BinaryTree.h"

void Thread_TreeCreative(Thread_TreeNode** RootNode, char* data, int* index)	// 创建二叉树
{
	char ch;
	ch = data[*index];
	(*index)++;
	if (ch == '#')
	{
		// 定义：如果字符是‘#’，则表示该结点为空
		*RootNode = NULL;
	}
	else
	{
		*RootNode = (Thread_TreeNode*)malloc(sizeof(Thread_TreeNode));
		(*RootNode)->data = ch;
		// flag值为1 时，表示该孩子节点指向前驱节点；值为0时，表示该孩子指向后继节点
		(*RootNode)->LFlag = 0;	
		(*RootNode)->RFlag = 0;
		Thread_TreeCreative(&((*RootNode)->LChild), &ch, index);
		Thread_TreeCreative(&((*RootNode)->RChild), &ch, index);
	}
}

void InThread_Tree(Thread_TreeNode* RootNode, Thread_TreeNode** pre)	// 二叉树线索化
{
	// 由于要将传入的根节点（每次递归传入的都是子树的根结点）与其前驱相连接
	// 所以需要将每次在中序遍历得到的前一个结点记录下来
	if (RootNode)
	{
		InThread_Tree(RootNode->LChild, pre);
		// 线索化
		// 注意：孩子节点的前驱是pre
		//		pre的后继节点是孩子节点
		if (RootNode->LChild == NULL)
		{
			// 如果根节点的左孩子为空，则将左孩子结点指向前驱节点
			RootNode->LFlag = 1;
			RootNode->LChild = *pre;
		}
		if ((*pre) != NULL && (*pre)->RChild == NULL)
		{
			(*pre)->RFlag = 1;
			(*pre)->RChild = RootNode;
		}
		(*pre) = RootNode;

		InThread_Tree(RootNode->RChild, pre);
	}

}