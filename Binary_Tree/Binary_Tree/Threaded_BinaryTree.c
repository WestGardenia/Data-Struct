#define _CRT_SECURE_NO_WARNINGS
#include"Threaded_BinaryTree.h"

void Thread_TreeCreative(Thread_TreeNode** RootNode, char* data, int* index)	// 创建二叉树
{
	assert(*RootNode);
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
		// 标志位为1时表示Child指针指向左右子树；为1时表示Child指向其前驱或者后继
		(*RootNode)->LFlag = 0;	
		(*RootNode)->RFlag = 0;
		Thread_TreeCreative(&((*RootNode)->LChild), data, index);
		Thread_TreeCreative(&((*RootNode)->RChild), data, index);
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
			// 初始状态：即pre结点还未迭代过
			(*pre)->RFlag = 1;
			(*pre)->RChild = RootNode;
		}
		(*pre) = RootNode;

		InThread_Tree(RootNode->RChild, pre);
	}
}

Thread_TreeNode* GetFirst(Thread_TreeNode* RootNode)
{
	assert(RootNode);
	// 循环版本：
	//while (RootNode->LFlag == 0)
	//{
	//	// 在线索二叉树中，从根节点开始遍历。只要子树的根结点的左孩子有前驱，就说明在链表结构中没有遍历到头结点
	//	// 同时，也需要注意，线索二叉树形成的链表与常规链表不同，我们拥有的第一个索引是树的根结点，但并不一定是链表头节点

	//	// 循环过程中，如果LFlag值为0，则表示该结点有左孩子而无前驱，同时也说明该结点不是叶子节点
	//	// 反过来，叶子节点的Flag值至少有一个为1（线索二叉树定义）
	//	RootNode = RootNode->LChild;
	//}
	//return RootNode;
	
	// 迭代版本：
	if (RootNode->LFlag == 0)
	{
		return GetFirst(RootNode->LChild);
	}
}

Thread_TreeNode* GetNext(Thread_TreeNode* RootNode)
{
	// 在线索二叉树中，RootNode结点的next只有两种情况：
	// 1、非叶子节点
	//		此时RootNode->RFlag = 0
	// 2、叶子节点的RChild结点中存放的某个后继节点
	//		此时RootNode->RFlag = 1
	assert(RootNode);
	if (RootNode->RFlag == 1)
	{
		// 如果RFlag值为1，则表示该结点有后继节点next且存放于RChild中，则将其RChild作为next返回
		return RootNode->RChild;
	}
	else
	{
		// 如果RFlag值为0，则表示该结点的后继是RChild中存放的该节点的右孩子结点
		return GetFirst(RootNode->RChild);
	}
}