#define _CRT_SECURE_NO_WARNINGS
#include"Tree.h"

void TreeCreative(TreeNode** RootNode,char* data,int* index)	// ����������
{
	if ((*RootNode) == NULL)
	{
		exit(-1);
	}
	// ���ڴ����������ĺ������β�RootNode�ṹ�ڲ�����˸ı䡣������Ҫ�������ָ��
	char ch;
	ch = data[*index];
	(*index)++;	// �����ǵݹ���ã�����Ҫ���ڵݹ�ʱ�ı�index����λ�ã��ͱ��봫��index��ָ��
	if (ch == '#')
	{
		// �������롮#��ʱ���ڵ�Ϊ�ս��
		*RootNode = NULL;
	}
	else
	{
		// �ݹ鶨�����������������ϣ����������ڵ�����Һ��ӽ��Ҳ��һ������
		*RootNode = (TreeNode*)malloc(sizeof(TreeNode));
		(*RootNode)->data = ch;
		TreeCreative(&((*RootNode)->LChild),data,index);
		TreeCreative(&((*RootNode)->RChild),data,index);
	}
}

void preOrder(TreeNode* RootNode)	// ������--�������--��-��-��
{
	if (RootNode == NULL)
	{
		return;
	}
	printf("%c->", RootNode->data);
	preOrder(RootNode->LChild);
	preOrder(RootNode->RChild);
}

void inOrder(TreeNode* RootNode)	// ������--�������--��-��-��
{
	if (RootNode == NULL)
	{
		return;
	}
	inOrder(RootNode->LChild);

	printf("%c->", RootNode->data);
	
	inOrder(RootNode->RChild);
}

void postOrder(TreeNode* RootNode)		// ������--�������--��-��-��
{
	if (RootNode == NULL)
	{
		return;
	}
	postOrder(RootNode->LChild);

	postOrder(RootNode->RChild);

	printf("%c->", RootNode->data);
}

// ��������������������������������������������������������������������������������������������������������������������������������������������������������������������
void QueueInit(Queue* pq)	// ���еĶ���
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}

void QueueDestroy(Queue* pq)	// ���е�����
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur->next != NULL)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}

void QueuePush(Queue* pq, Queue_DataType* x)	// �������ݲ���
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	newnode->data = x;
	newnode->next = NULL;
	if (QueueEmpty(pq))
	{
		pq->head = newnode;
		pq->tail = newnode;
	}
	else
	{
		newnode->next = pq->head;
		pq->head = newnode;
	}

}

void QueuePop(Queue* pq)	// �������ݳ���
 // ��BUG
{
	assert(pq);
	if (QueueEmpty(pq))
	{
		return;
	}
	if (pq->head == pq->tail)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* cur = pq->head;
		QNode* pre = pq->head;
		while (cur->next != NULL)
		{
			pre = cur;
			cur = cur->next;
		}
		free(cur);
		pre->next = NULL;
		pq->tail = pre;
	}
}

Queue_DataType* QueueFront(Queue* pq)	// ȡ��ͷ����
{
	assert(pq);
	if (QueueEmpty(pq))
	{
		return NULL;
	}
	return pq->head->data;
}

Queue_DataType* QueueBack(Queue* pq)		// ȡ��β����
{
	assert(pq);
	if (QueueEmpty(pq))
	{
		return NULL;
	}
	return pq->tail->data;
}

int QueueSize(Queue* pq)	// ������г���
{
	assert(pq);
	int count = 0;
	QNode* cur = pq->head;
	while (cur == NULL)
	{
		cur = cur->next;
		count++;
	}
	return count;
}

// ��������������������������������������������������������������������������������������������������������������������������������������������
// ���в�������Copy�汾
//void QueueInit(Queue* pq)	// ���еĶ���
//{
//	assert(pq);
//	pq->head = NULL;
//	pq->tail = NULL;
//}
//
//void QueueDestroy(Queue* pq)	// ���е�����
//{
//	assert(pq);
//	QNode* cur = pq->head;
//	while (cur != NULL)
//	{
//		QNode* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//	pq->head = pq->tail = NULL;
//}
//
//void QueuePush(Queue* pq, Queue_DataType* x)	// �������ݲ���
//{
//	assert(pq);
//	QNode* newnode = (QNode*)malloc(sizeof(QNode));
//	if (newnode == NULL)
//	{
//		printf("�ռ俪��--QueuePush��������!!!");
//		exit(-1);
//	}
//	newnode->data = x;
//	newnode->next = NULL;
//	if (pq->head == NULL)
//	{
//		// ���������û�����ݣ���Ϊ�ն��С���ʱ��ͷ����β���ָ����malloc�����Ľ��
//		pq->head = pq->tail = newnode;
//	}
//	else
//	{
//		// ��������������ݣ��ͽ��½�����ӵ�tail�ĺ��棬������tail��λ�ã���tailָ��newnode
//		pq->tail->next = newnode;
//		pq->tail = newnode;
//	}
//}
//
//void QueuePop(Queue* pq)	// �������ݳ���
//{
//	// ɾ����ͷ�����ݣ���head���棬����head��λ�ã�����free���ɵ�ͷ�ڵ�
//	assert(pq);
//	// Ϊ��ֹ�ն���ɾ�����Խ����ʣ���Ҫ�Զ����Ƿ�Ϊ�ս����ж�
//	assert(!QueueEmpty(pq));
//	QNode* newhead = pq->head;
//	// ����head��λ��
//	pq->head = pq->head->next;
//	free(newhead);
//	if (pq->head == NULL)
//	{
//		// ��������Ѿ���ɾ����һ���ն��С�
//		// ����ͷ������ʱ��û�ж�β���tail������ʱtail����һ��Ұָ�롣��Ҫ�����ÿ�
//		pq->tail = NULL;
//	}
//}
//
//Queue_DataType* QueueFront(Queue* pq)	// ȡ��ͷ����
//{
//	assert(pq);
//	// Ϊ��ֹ�ն���ɾ�����Խ����ʣ���Ҫ�Զ����Ƿ�Ϊ�ս����ж�
//	assert(!QueueEmpty(pq));
//
//	return pq->head->data;
//}
//
//Queue_DataType* QueueBack(Queue* pq)		// ȡ��β����
//{
//	assert(pq);
//	// Ϊ��ֹ�ն���ɾ�����Խ����ʣ���Ҫ�Զ����Ƿ�Ϊ�ս����ж�
//	assert(!QueueEmpty(pq));
//
//	return pq->tail->data;
//}
//
//int QueueSize(Queue* pq)	// ������г���
//{
//	assert(pq);
//	if (pq->head == NULL)
//		return 0;
//	else
//	{
//		int count = 0;
//		QNode* cur = pq->head;
//		while (cur)
//		{
//			cur = cur->next;
//			count++;
//		}
//		return count;
//	}
//}


bool QueueEmpty(Queue* pq)	 //�ж϶����Ƿ�Ϊ��
{
	assert(pq);
	return pq->head == NULL;
}

void LevelTraverse(Queue* Q, TreeNode* RootNode)	// ������--��α���
{
	QueuePush(Q,RootNode);
	// QueuePrint(q);
	while (!QueueEmpty(Q))
	{
		TreeNode* newnode = QueueBack(Q);
		QueuePop(Q);
		//if (QueueEmpty(Q))
		//{
		//	printf("\nQ����Ϊ��\n");
		//}
		printf("%c->", newnode->data);
		if (newnode->LChild)
		{
			QueuePush(Q, newnode->LChild);
			// QueuePrint(q);
		}
		if (newnode->RChild)
		{
			QueuePush(Q, newnode->RChild);
			// QueuePrint(q);
		}
	}
}