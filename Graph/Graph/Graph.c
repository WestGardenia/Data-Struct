#define _CRT_SECURE_NO_WARNINGS

#include"Graph.h"

Graph* GraphInit(int vexNum)	// ��ʼ��ͼ
{
	Graph* MyGraph = (Graph*)malloc(sizeof(Graph));
	if (MyGraph == NULL)
	{
		return NULL;
		exit(-1);
	}
	MyGraph->vexs = (char*)malloc(sizeof(char)*vexNum);
	if (MyGraph->vexs == NULL)
	{
		return NULL;
		exit(-1);
	}
	MyGraph->arcs = (int**)malloc(sizeof(int*)*vexNum);
	if (MyGraph->arcs == NULL)
	{
		return NULL;
		exit(-1);
	}
	for (int i = 0; i < vexNum; i++)
	{
		MyGraph->arcs[i] = (int*)malloc(sizeof(int) * vexNum);
		if (MyGraph->arcs[i] == NULL)
		{
			return NULL;
			exit(-1);
		}
	}
	MyGraph->vexNum = vexNum;
	MyGraph->arcNum = 0;

	return MyGraph;
}

void GraphCreate(Graph* MyGraph, char* vexs, int* arcs)	// ����ͼ
{
	for (int i = 0; i < MyGraph->vexNum; i++)
	{
		MyGraph->vexs[i] = vexs[i];
		for (int j = 0; j < MyGraph->vexNum; j++)
		{
			// ���ڽӾ���ֵ
			//MyGraph->arcs[i][j] = *(arcs + i * MyGraph->vexNum + j);
			MyGraph->arcs[i][j] = arcs[i * MyGraph->vexNum+j];
			// �жϣ����
			if (MyGraph->arcs[i][j] != 0)
			{
				MyGraph->arcNum++;
			}
		}
	}
	// ����ͼʱ��ÿ��һ�Զ��㣬�ͻᴴ��һ�Աߡ���������ͼ��һ�Ա�û����������Ҫ��2
	MyGraph->arcNum /= 2;
}

void DFS(Graph* G, int* visit, int index)	// ͼ--������ȱ���DFS
{
	printf("%c\t", G->vexs[index]);
	visit[index] = 1;
	for (int i = 0; i < G->vexNum; i++)
	{
		if (G->arcs[index][i] == 1 && visit[i] != 1)
		{
			DFS(G, visit, i);
		}
	}
}


Queue* InitQueue()
{
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	if (Q == NULL)
	{
		return NULL;
		exit(-1);
	}
	Q->front = Q->tail = NULL;

	return Q;
}

void PrintQueue(Queue* Q)
{
	assert(Q);
	Node* cur = Q->front;
	while (cur)
	{
		printf("%d\t", cur->data);
		cur = cur->next;
	}
}

bool isEmpty(Queue* Q)
{
	if (Q->front == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void enQueue(Queue* Q, NodeType val)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode == NULL)
	{
		return;
		exit(-1);
	}
	if (isEmpty(Q))
	{
		newnode->data = val;
		newnode->next = Q->front;

		Q->front = newnode;

		Q->tail = Q->front;
	}
	else
	{
		newnode->data = val;
		newnode->next = Q->front;

		Q->front = newnode;
	}
}

NodeType deQueue(Queue** Q)
{
	NodeType x = (*Q)->tail->data;
	if (isEmpty(*Q))
	{
		return -1;
	}
	else
	{
		Node* cur = (*Q)->front;
		if ((*Q)->front != (*Q)->tail)
		{
			while (cur->next != (*Q)->tail)
			{
				cur = cur->next;
			}
			(*Q)->tail = cur;
		}
		else
		{
			(*Q)->front = (*Q)->tail = NULL;
		}
		return x;
	}
}

void BFS(Graph* G, int* visit, int index)	// ͼ--������ȱ���BFS
{
	Queue* Q = InitQueue();
	printf("%c\t", G->vexs[index]);
	enQueue(Q, index);
	visit[index] = 1;
	while (!isEmpty(Q))
	{
		int i = deQueue(&Q);
		for (int j = 0; j < G->vexNum; j++)
		{
			if (G->arcs[i][j] == 1 && visit[j] != 1)
			{
				printf("%c\t", G->vexs[j]);
				visit[j] = 1;
				enQueue(Q, j);
			}
		}
	}
}
