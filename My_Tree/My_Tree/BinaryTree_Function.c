#define _CRT_SECURE_NO_WARNINGS

#include"Tree_Function.h"

void Create_BinaryTree(TreeNode** RootNode, char* val, int* index)
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

		Create_BinaryTree(&((*RootNode)->lchild), val, index);
		Create_BinaryTree(&((*RootNode)->rchild), val, index);
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