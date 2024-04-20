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

void Create_Queue(Queue** q)	// ��������
{
	assert(*q);
	(*q) = (Queue*)malloc(sizeof(Queue));
	(*q)->data = NULL;
	(*q)->next = NULL;
}

void QueuePush(Queue** q,Queue_DataType* x)	// ���в�������--ͷ��
{
	assert(*q);
	Queue* newnode = (Queue*)malloc(sizeof(Queue));
	if (newnode == NULL)
	{
		exit(-1);
	}
	newnode->next = (*q)->next;
	newnode->data = x;

	(*q) = newnode;
}

TreeNode* QueuePop(Queue** q)	// ����--ȡ��β����
{
	assert(*q);

	if (IsQueueEmpty(*q))
	{
		return NULL;
	}
	else
	{
		TreeNode* DirectionData = NULL;
		Queue* pre = (*q);
		Queue* cur = (*q);
		
		while (cur->next != NULL)
		{
			pre = cur;
			cur = cur->next;
		}
		DirectionData = cur->data;
		pre->next = NULL;

		free(cur);
		return DirectionData;
	}
}

bool IsQueueEmpty(Queue* q)	// ����--�ж϶����Ƿ�Ϊ��
{
	if (q == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void QueuePrint(Queue* q)	// ��ӡ����
{
	if (IsQueueEmpty(q))
	{
		printf("Queue is empty!!!!!\n");
	}
	else
	{
		while (!IsQueueEmpty(q))
		{
			printf("%c->", q->data->data);
			q = q->next;
		}
	}
}

void LevelTraverse(Queue* Q, TreeNode* RootNode)	// ������--��α���
{
	QueuePush(&Q,RootNode);
	// QueuePrint(q);
	while (!IsQueueEmpty(Q))
	{
		TreeNode* newnode = QueuePop(&Q);
		printf("%c->", newnode->data);
		if (newnode->LChild)
		{
			QueuePush(&Q, newnode->LChild);
			// QueuePrint(q);
		}
		if (newnode->RChild)
		{
			QueuePush(&Q, newnode->RChild);
			// QueuePrint(q);
		}
	}
}