#define _CRT_SECURE_NO_WARNINGS

#include"Tree_Function.h"

void Create_BinaryTree(TreeNode** RootNode, char* val, int* index, TreeNode* parent)
{
	(*RootNode) = (TreeNode*)malloc(sizeof(TreeNode));
	if ((*RootNode) == NULL) {
		// ���(*RootNode)��NULL��˵��mallocʧ����
		fprintf(stderr, "Memory allocation failed!\n");
		// ����ѡ�񷵻ش��������ִ������������
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

// �������
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


// ����������
void InOrder_Thread(TreeNode* T, TreeNode** pre)	// ����������
{
	if (T != NULL)
	{
		InOrder_Thread(T->lchild, pre);
		if (T->lchild == NULL)	// ����Ϊ�գ���������������ָ��ǰ����
		{
			T->lchild = *pre;
			T->ltag = 1;
			//if(*pre != NULL)
			//	printf("%c��ǰ����:%c\n", T->data, (*pre)->data);
		}
		if (*pre != NULL && (*pre)->rchild == NULL && !(*pre)->rtag)	// �Һ���Ϊ�գ����Һ�����������ָ���̣�
		{
			// ����Ҫȷ��pre��Ϊ�գ�ԭ����pre�Ǵӿս�㿪ʼ�����ģ��������ÿս�����Ұָ��
			(*pre)->rchild = T;
			(*pre)->rtag = 1;
			//if(T != NULL)
			//	printf("%c�ĺ����:%c\n", (*pre)->data, T->data);
		}	
		*pre = T;
		InOrder_Thread(T->rchild, pre);
	}
}

TreeNode* First_InOrder(TreeNode* T)	// Ѱ����������ĵ�һ���ڵ�
{
	while (T && (T->ltag == 0))
		T = T->lchild;
	return T;
}

TreeNode* Next_InOrder(TreeNode* T)	// Ѱ����������ĺ�̽ڵ�
{
	if (T->rtag == 1)
		return T->rchild;
	else
		return First_InOrder(T->rchild);
}

void InOrder_ThreadTree(TreeNode* T)	// ������������������
{
	for (TreeNode* p = First_InOrder(T); p != NULL; p = Next_InOrder(p))
		printf("%c -> ", p->data);
}

TreeNode* Last_InOrder(TreeNode* T)	// Ѱ���������������һ�����
{
	while ((T->rtag == 0) && (T->rchild))
		T = T->rchild;
	return T;
}

TreeNode* Pre_InOrder(TreeNode* T)		// Ѱ������������ǰ���ڵ�
{
	if (T->ltag == 1)
		return T->lchild;
	else
		return Last_InOrder(T->lchild);
}

void InOrder_ThreadTree_Rev(TreeNode* T)	// ���������������
{
	for (TreeNode* p = Last_InOrder(T); p != NULL; p = Pre_InOrder(p))
		printf("%c -> ", p->data);
}



void PreOrder_Thread(TreeNode* T, TreeNode** pre)	// ����������
{
	if (T != NULL)
	{
		if (T->lchild == NULL)	// ����Ϊ�գ���������������ָ��ǰ����
		{
			T->lchild = *pre;
			T->ltag = 1;
			//if (*pre != NULL)
			//	printf("%c��ǰ����:%c\n", T->data, (*pre)->data);
		}
		if (*pre != NULL && (*pre)->rchild == NULL)	// �Һ���Ϊ�գ����Һ�����������ָ���̣�
		{
			// ����Ҫȷ��pre��Ϊ�գ�ԭ����pre�Ǵӿս�㿪ʼ�����ģ��������ÿս�����Ұָ��
			(*pre)->rchild = T;
			(*pre)->rtag = 1;
			//if (T != NULL)
			//	printf("%c�ĺ����:%c\n", (*pre)->data, T->data);
		}
		*pre = T;
		if(T->ltag ==0)
			PreOrder_Thread(T->lchild, pre);
		PreOrder_Thread(T->rchild, pre);
	}
}

TreeNode* First_PreOrder(TreeNode* T)	// Ѱ�����������ĵ�һ���ڵ�
{
	return T;
}

TreeNode* Next_PreOrder(TreeNode* T)	// Ѱ�����������ĺ�̽ڵ�
{
	if (T->rtag == 1)
		return T->rchild;
	else
	{
		// T->rtag != 1�����˴����ָ������Һ��ӣ�Ҷ�ӽ���rtag��Ϊ1��
		if (T->ltag == 0)
			return T->lchild;
		else
			return T->rchild;
	}
}


TreeNode* Last_PreOrder(TreeNode* T)	// Ѱ���������������һ�����
{
	while ((T->rtag == 0) && (T->rchild))
		T = T->rchild;
	return T;
}

TreeNode* Pre_PreOrder(TreeNode* T)		// Ѱ������������ǰ���ڵ�
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

void PreOrder_ThreadTree(TreeNode* T)	// �������������
{
	for (TreeNode* p = First_PreOrder(T); p != NULL; p = Next_PreOrder(p))
		printf("%c -> ", p->data);
}

void PreOrder_ThreadTree_Rev(TreeNode* T)	// ���������������
{
	for (TreeNode* p = Last_PreOrder(T); p != NULL; p = Pre_PreOrder(p))
		printf("%c -> ", p->data);
}


void PostOrder_Thread(TreeNode* T, TreeNode** pre)	// ����������
{
	if (T != NULL)
	{
		PostOrder_Thread(T->lchild, pre);
		PostOrder_Thread(T->rchild, pre);
		if (T->lchild == NULL)	// ����Ϊ�գ���������������ָ��ǰ����
		{
			T->lchild = *pre;
			T->ltag = 1;
			//if (*pre != NULL)
			//	printf("%c��ǰ����:%c\n", T->data, (*pre)->data);
		}
		if (*pre != NULL && (*pre)->rchild == NULL)	// �Һ���Ϊ�գ����Һ�����������ָ���̣�
		{
			// ����Ҫȷ��pre��Ϊ�գ�ԭ����pre�Ǵӿս�㿪ʼ�����ģ��������ÿս�����Ұָ��
			(*pre)->rchild = T;
			(*pre)->rtag = 1;
			//if (T != NULL)
			//	printf("%c�ĺ����:%c\n", (*pre)->data, T->data);
		}
		*pre = T;
	}
}