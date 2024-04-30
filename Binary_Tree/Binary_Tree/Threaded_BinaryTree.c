#define _CRT_SECURE_NO_WARNINGS
#include"Threaded_BinaryTree.h"

void Thread_TreeCreative(Thread_TreeNode** RootNode, char* data, int* index,Thread_TreeNode* parent)	// 创建二叉树
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
		(*RootNode)->Parent = parent;
		Thread_TreeCreative(&((*RootNode)->LChild), data, index, (*RootNode));
		Thread_TreeCreative(&((*RootNode)->RChild), data, index, (*RootNode));
	}
}

void PreThread_Tree(Thread_TreeNode* RootNode, Thread_TreeNode** pre)	// 线索二叉树--先序遍历--左-根-右
{
	// 由于要将传入的根节点（每次递归传入的都是子树的根结点）与其前驱相连接
	// 所以需要将每次在中序遍历得到的前一个结点记录下来
	if (RootNode)
	{
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

		// 左、右子树
		// 注意这里与中序遍历的区别
		// 由于在遍历之前已经对二叉树的结构（叶子结点的左右孩子结点）进行了改变
		// 比如结点D	D->LChild = B
		//				B->LChild = D
		// 这样进行了结构上的改变之后，会让递归调用的函数循环递归，造成死循环
		// 所以需要在递归之前进行一次对于Flag值的判断
		if (RootNode->LFlag == 0)
		{
			// 如果LFlag值为0，则表示该结点的LChild节点中存放的是原始二叉树中的结点，而非线索化之后的前驱
			PreThread_Tree(RootNode->LChild, pre);
		}
		PreThread_Tree(RootNode->RChild, pre);
	}
}

Thread_TreeNode* Pre_GetNext(Thread_TreeNode* RootNode)
{
	if (RootNode->RFlag == 1)
	{
		// 如果传入节点的RFlag = 1，则表示该结点为叶子节点并且RChild节点中存放的是某个后继结点，即就是我们所需要的next结点
		return RootNode->RChild;
	}
	else
	{
		// 如果传入节点的RFlag = 0，则表示该结点存在右孩子，那么根据先序遍历顺序（根左右），next结点只有两种情况
		if (RootNode->LFlag == 1)
		{
			// 1、当LFlag = 1，此时表明RootNode结点有右孩子而无左孩子（左孩子作为前驱指向某个前驱节点）。根据先序遍历顺序（根左右），此时next结点就是RChild结点
			return RootNode->RChild;
		}
		else
		{
			// 2、当LFlag = 0，此时表明RootNode结点有左孩子。那么根据先序遍历顺序（根左右），此时next结点就是LChild结点
			return RootNode->LChild;
		}
	}
	// 精简版本：
	//if (RootNode->RFlag == 1 || RootNode->LFlag == 0)
	//	return RootNode->RChild;
	//else
	//	return RootNode->LChild;
}

void InThread_Tree(Thread_TreeNode* RootNode, Thread_TreeNode** pre)	// 二叉树线索化--中序遍历--左-根-右
{
	// 由于要将传入的根节点（每次递归传入的都是子树的根结点）与其前驱相连接
	// 所以需要将每次在中序遍历得到的前一个结点记录下来
	if (RootNode)
	{
		// 左子树
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

		// 右子树
		InThread_Tree(RootNode->RChild, pre);
	}
}

Thread_TreeNode* In_GetFirst(Thread_TreeNode* RootNode)
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
		return In_GetFirst(RootNode->LChild);
	}
}

Thread_TreeNode* In_GetNext(Thread_TreeNode* RootNode)
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
		return In_GetFirst(RootNode->RChild);
	}
}

void PostThread_Tree(Thread_TreeNode* RootNode, Thread_TreeNode** pre)	// 线索二叉树--后序遍历--左-根-右
{
	if (RootNode)
	{
		// 左子树
		PostThread_Tree(RootNode->LChild, pre);
		// 右子树
		PostThread_Tree(RootNode->RChild, pre);
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
	}
}

Thread_TreeNode* Post_GetFirst(Thread_TreeNode* RootNode)
{
	// 后序（左右根）线索二叉树的头节点First有以下两；种情况：
	// 1、最左边的一棵子二叉树的根结点有左孩子
	// 2、最左边的一颗子二叉树的根结点只有右孩子
	// 方法：1、先找到最左边的结点：当cur->LChild == NULL时，表示cur就是该树的最左边的结点
	//		 2、然后判断该结点（cur）是否有右子树。如果有右子树，那么右子树就是First；如果没有，cur就是First
	// 循环版本：
	Thread_TreeNode* cur = RootNode;
	while (cur->LFlag == 0)
	{
		// 注意，这里while的判断条件必须是用LFlag去判断。
		// 因为在二叉树线索化之后，叶子结点的左右孩子指针中已经存放了相应的前驱后继节点
		// 而在二叉树的非叶子节点中的LFlag值必为0，所以只要有一个LFlag = 1，就代表其没有左孩子结点，取而代之的是它的前驱
		cur = cur->LChild;
	}
	if (cur->RFlag == 0)
	{
		// 经过上面的循环之后，如果cur结点中RFlag = 0，则表示cur有右孩子结点，那么需要判断它的右孩子节点之下是否还有子树
		// 这里就需要用到递归函数
		cur = Post_GetFirst(cur->RChild);
		return cur;
	}
	else
		// 如果cur->RFlag = 1，则表示cur就是一个叶子节点，那么就将其返回
		return cur;
}

Thread_TreeNode* Post_GetNext(Thread_TreeNode* RootNode)
{
	if (RootNode->RFlag == 1)
	{
		// 如果RFlag = 1，表示该结点无右子树而有在链表意义上的后继节点，那么就将这个节点的RChild结点返回
		return RootNode->RChild;
	}
	else
	{
		// 如果RFlag = 0，表示该节点有右孩子
		// 那么它（cur）有三种情况：
		// 1、是根结点----->next = NULL			二叉树后序遍历后，它的根结点必是排在末尾，而根结点有一定会有左右孩子，所以根结点的next就是NULL
		if (RootNode->Parent == NULL)
		{
			return NULL;
		}
		// 2、是某一个结点的左孩子------>判断这个父亲结点的右孩子是否为空，
		//											   右孩子为空则：next = parent
		//											   右孩子不为空：next就是右孩子结点构成的子树的最左边的结点
		else if (RootNode->Parent->LChild == RootNode&&RootNode->Parent->LFlag == 0)
		{
			if (RootNode->Parent->RFlag == 1)
			{
				return RootNode->Parent;
			}
			else
			{
				return Post_GetFirst(RootNode->Parent->RChild);
			}
		}
		// 3、是某一个结点的右孩子------>next就是这个父亲节点
		else if (RootNode->Parent->RChild == RootNode&&RootNode->Parent->RFlag == 0)
		{
			return RootNode->Parent;
		}
		// 由于后序遍历取next结点涉及到父亲结点，所以在数据结构定义中，需要增加一个指针域指向父亲结点
	}
}