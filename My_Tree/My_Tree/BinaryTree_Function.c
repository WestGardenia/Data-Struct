#define _CRT_SECURE_NO_WARNINGS

#include"Tree_Function.h"

void Create_BinaryTree(TreeNode** RootNode, char* val, int* index, TreeNode* parent)
{
	(*RootNode) = (TreeNode*)malloc(sizeof(TreeNode));
	if ((*RootNode) == NULL) {
		// 如果(*RootNode)是NULL，说明malloc失败了
		fprintf(stderr, "Memory allocation failed!\n");
		// 可以选择返回错误码或者执行其他错误处理
		return;
	}
	char ch;
	if (val == NULL)
	{
		return;
	}
	ch = val[*index];
	(*index)++;
	if (ch == '#')
	{
		(*RootNode) = NULL;
	}
	else
	{
		//(*RootNode) = (TreeNode*)malloc(sizeof(TreeNode));
		(*RootNode)->data = ch;
		(*RootNode)->ltag = 0;
		(*RootNode)->rtag = 0;
		(*RootNode)->parent = parent;
		Create_BinaryTree(&((*RootNode)->lchild), val, index, (*RootNode));
		Create_BinaryTree(&((*RootNode)->rchild), val, index, (*RootNode));
	}
}

void PreOrder(TreeNode* RootNode)
{
	if (RootNode != NULL)
	{
		printf("%c -> ", RootNode->data);
		PreOrder(RootNode->lchild);
		PreOrder(RootNode->rchild);
	}
	else
	{
		return;
	}
}

void InOrder(TreeNode* RootNode)
{
	if (RootNode != NULL)
	{
		InOrder(RootNode->lchild);
		printf("%c -> ", RootNode->data);
		InOrder(RootNode->rchild);
	}
	else
	{
		return;
	}
}

void PostOrder(TreeNode* RootNode)
{
	if (RootNode != NULL)
	{
		PostOrder(RootNode->lchild);
		PostOrder(RootNode->rchild);
		printf("%c -> ", RootNode->data);
	}
	else
	{
		return;
	}
}

bool Tree_IsEmpty(TreeNode* RootNode)
{
	return (RootNode == NULL);
}

void Destroy_BinaryTree(TreeNode* node) {
	if (node) {
		Destroy_BinaryTree(node->lchild);
		Destroy_BinaryTree(node->rchild);
		free(node);
	}
}

// 层序遍历
Queue* Queue_Init()
{
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	if (Q == NULL) {
		fprintf(stderr, "Memory allocation failed!\n");
		return NULL;
	}
	Q->head = Q->tail = NULL;

	return Q;
}

QueueNode* QueueNode_Init(TreeNode* T)
{
	QueueNode* pQ = (QueueNode*)malloc(sizeof(QueueNode));
	assert(pQ);

	pQ->data = T;
	pQ->next = NULL;

	return pQ;
}

bool Queue_IsEmpty(Queue* Q)
{
	if (Q->head == NULL)
		return true;
	else
		return false;
}

void Queue_PushTail(Queue* Q, QueueNode* pQ)
{
	assert(Q);
	if (!Queue_IsEmpty(Q))
	{
		Q->tail->next = pQ;
		Q->tail = pQ;
	}
	else
	{
		Q->head = Q->tail = pQ;
	}
}

void Queue_PopHead(Queue* Q)
{
	assert(Q);

	if ((!Queue_IsEmpty(Q)) && (Q->head != Q->tail))
	{
		QueueNode* newnode = Q->head;
		Q->head = Q->head->next;

		free(newnode);
	}
	else if (Queue_IsEmpty(Q))
	{
		printf("Queue is empty!!!!\n");
	}
	else if (Q->head == Q->tail)
	{
		QueueNode* newnode = Q->head;
		Q->head = Q->tail = NULL;
		free(newnode);
	}
}

QueueNode_Type* Get_QueueHead(Queue* Q)
{
	assert(!Queue_IsEmpty(Q));
	return Q->head->data;
}

void QueueNode_Destroy(QueueNode* pQ)
{
	if (pQ != NULL)
	{
		free(pQ);
	}
}

void Queue_Destroy(Queue* Q)
{
	while (Q->head != Q->tail)
	{
		QueueNode* newnode = Q->head;
		Q->head = newnode->next;
		QueueNode_Destroy(newnode);
	}
	free(Q->head);
	free(Q);
}

void BinaryTree_LevelOrder(TreeNode* T)
{
	Queue* Q = Queue_Init();
	QueueNode* pQ = QueueNode_Init(T);
	Queue_PushTail(Q, pQ);
	while (!Queue_IsEmpty(Q))
	{
		TreeNode* newnode = Get_QueueHead(Q);
		printf("%c -> ", newnode->data);
		Queue_PopHead(Q);
		if (newnode->lchild != NULL)
		{
			pQ = QueueNode_Init(newnode->lchild);

			Queue_PushTail(Q, pQ);
		}
		if (newnode->rchild != NULL)
		{
			pQ = QueueNode_Init(newnode->rchild);

			Queue_PushTail(Q, pQ);
		}
	}
	Queue_Destroy(Q);
}


// 线索二叉树
void InOrder_Thread(TreeNode* T, TreeNode** pre)	// 中序线索化
{
	if (T != NULL)
	{
		InOrder_Thread(T->lchild, pre);
		if (T->lchild == NULL)	// 左孩子为空，则左孩子线索化（指向前驱）
		{
			T->lchild = *pre;
			T->ltag = 1;
			//if(*pre != NULL)
			//	printf("%c的前驱是:%c\n", T->data, (*pre)->data);
		}
		if (*pre != NULL && (*pre)->rchild == NULL && !(*pre)->rtag)	// 右孩子为空，则右孩子线索化（指向后继）
		{
			// 这里要确保pre不为空，原因是pre是从空结点开始迭代的，可能引用空结点造成野指针
			(*pre)->rchild = T;
			(*pre)->rtag = 1;
			//if(T != NULL)
			//	printf("%c的后继是:%c\n", (*pre)->data, T->data);
		}	
		*pre = T;
		InOrder_Thread(T->rchild, pre);
	}
}

TreeNode* First_InOrder(TreeNode* T)	// 寻找中序遍历的第一个节点
{
	while (T && (T->ltag == 0))
		T = T->lchild;
	return T;
}

TreeNode* Next_InOrder(TreeNode* T)	// 寻找中序遍历的后继节点
{
	if (T->rtag == 1)
		return T->rchild;
	else
		return First_InOrder(T->rchild);
}

void InOrder_ThreadTree(TreeNode* T)	// 中序线索二叉树遍历
{
	for (TreeNode* p = First_InOrder(T); p != NULL; p = Next_InOrder(p))
		printf("%c -> ", p->data);
}

TreeNode* Last_InOrder(TreeNode* T)	// 寻找中序线索的最后一个结点
{
	while ((T->rtag == 0) && (T->rchild))
		T = T->rchild;
	return T;
}

TreeNode* Pre_InOrder(TreeNode* T)		// 寻找中序线索的前驱节点
{
	if (T->ltag == 1)
		return T->lchild;
	else
		return Last_InOrder(T->lchild);
}

void InOrder_ThreadTree_Rev(TreeNode* T)	// 线索化中序逆遍历
{
	for (TreeNode* p = Last_InOrder(T); p != NULL; p = Pre_InOrder(p))
		printf("%c -> ", p->data);
}



void PreOrder_Thread(TreeNode* T, TreeNode** pre)	// 先序线索化
{
	if (T != NULL)
	{
		if (T->lchild == NULL)	// 左孩子为空，则左孩子线索化（指向前驱）
		{
			T->lchild = *pre;
			T->ltag = 1;
			//if (*pre != NULL)
			//	printf("%c的前驱是:%c\n", T->data, (*pre)->data);
		}
		if (*pre != NULL && (*pre)->rchild == NULL)	// 右孩子为空，则右孩子线索化（指向后继）
		{
			// 这里要确保pre不为空，原因是pre是从空结点开始迭代的，可能引用空结点造成野指针
			(*pre)->rchild = T;
			(*pre)->rtag = 1;
			//if (T != NULL)
			//	printf("%c的后继是:%c\n", (*pre)->data, T->data);
		}
		*pre = T;
		if(T->ltag ==0)
			PreOrder_Thread(T->lchild, pre);
		PreOrder_Thread(T->rchild, pre);
	}
}

TreeNode* First_PreOrder(TreeNode* T)	// 寻找先序线索的第一个节点
{
	return T;
}

TreeNode* Next_PreOrder(TreeNode* T)	// 寻找先序线索的后继节点
{
	if (T->rtag == 1)
		return T->rchild;
	else
	{
		// T->rtag != 1代表了传入的指针必有右孩子（叶子结点的rtag必为1）
		if (T->ltag == 0)
			return T->lchild;
		else
			return T->rchild;
	}
}


TreeNode* Last_PreOrder(TreeNode* T)	// 寻找先序线索的最后一个结点
{
	while ((T->rtag == 0) && (T->rchild))
		T = T->rchild;
	return T;
}

TreeNode* Pre_PreOrder(TreeNode* T)		// 寻找先序线索的前驱节点
{
	if(T->parent)
	{
		if (T->ltag == 1)
			return T->lchild;
		else
		{
			if (T == T->parent->lchild || ((T->parent->ltag == 1 && T->parent->rchild == T)))
				return T->parent;
			else if (T->parent->ltag == 0 && T->parent->rchild == T)
				return Last_PreOrder(T->parent->lchild);
		}
	}
	else
		return NULL;
}

void PreOrder_ThreadTree(TreeNode* T)	// 线索化先序遍历
{
	for (TreeNode* p = First_PreOrder(T); p != NULL; p = Next_PreOrder(p))
		printf("%c -> ", p->data);
}

void PreOrder_ThreadTree_Rev(TreeNode* T)	// 线索化先序逆遍历
{
	for (TreeNode* p = Last_PreOrder(T); p != NULL; p = Pre_PreOrder(p))
		printf("%c -> ", p->data);
}


void PostOrder_Thread(TreeNode* T, TreeNode** pre)	// 后序线索化
{
	if (T != NULL)
	{
		PostOrder_Thread(T->lchild, pre);
		PostOrder_Thread(T->rchild, pre);
		if (T->lchild == NULL)	// 左孩子为空，则左孩子线索化（指向前驱）
		{
			T->lchild = *pre;
			T->ltag = 1;
			//if (*pre != NULL)
			//	printf("%c的前驱是:%c\n", T->data, (*pre)->data);
		}
		if (*pre != NULL && (*pre)->rchild == NULL)	// 右孩子为空，则右孩子线索化（指向后继）
		{
			// 这里要确保pre不为空，原因是pre是从空结点开始迭代的，可能引用空结点造成野指针
			(*pre)->rchild = T;
			(*pre)->rtag = 1;
			//if (T != NULL)
			//	printf("%c的后继是:%c\n", (*pre)->data, T->data);
		}
		*pre = T;
	}
}