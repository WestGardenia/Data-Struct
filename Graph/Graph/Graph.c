#define _CRT_SECURE_NO_WARNINGS

#include"Graph.h"

Graph* GraphInit(int vexNum)	// 初始化图
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

void GraphCreate(Graph* MyGraph, char* vexs, int* arcs)	// 创建图
{
	for (int i = 0; i < MyGraph->vexNum; i++)
	{
		MyGraph->vexs[i] = vexs[i];
		for (int j = 0; j < MyGraph->vexNum; j++)
		{
			// 给邻接矩阵赋值
			//MyGraph->arcs[i][j] = *(arcs + i * MyGraph->vexNum + j);
			MyGraph->arcs[i][j] = arcs[i * MyGraph->vexNum+j];
			// 判断，如果
			if (MyGraph->arcs[i][j] != 0)
			{
				MyGraph->arcNum++;
			}
		}
	}
	// 创建图时，每有一对顶点，就会创建一对边。但是无向图的一对边没有区别，所以要除2
	MyGraph->arcNum /= 2;
}

void DFS(Graph* G, int* visit, int index)	// 图--深度优先遍历DFS
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

void BFS(Graph* G, int* visit, int index)	// 图--广度优先遍历BFS
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
