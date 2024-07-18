#define _CRT_SECURE_NO_WARNINGS

#include"My_Graph.h"

Graph_01* Graph_Init(int vex_num)	// ͼ�ĳ�ʼ��
{
	Graph_01* G = (Graph_01*)malloc(sizeof(Graph_01));

	G->vex_num = vex_num;
	G->edge_num = 0;
	G->vex = (char*)malloc(sizeof(char)*vex_num);
	G->edge = (int**)malloc(sizeof(int*) * vex_num);
	for (int i = 0; i < vex_num; i++)
	{
		G->edge[i] = (int*)malloc(sizeof(int*));
	}

	return G;
}

Graph_01* Graph_Create(Graph_01* G, int* edge, char* vex)	// ����ͼ
{
	for (int i = 0; i < G->vex_num; i++)
	{
		G->vex[i] = vex[i];
		for (int j = 0; j < G->vex_num; j++)
		{
			G->edge[i][j] = *(edge + i * G->vex_num + j);
			if (G->edge[i][j] != 0 && G->edge[i][j] != MAX)
			{
				G->edge_num++;
			}
		}
	}
	G->edge_num /= 2;
	return G;
}

void DFS(Graph_01* G, int* visit, int index)	// DFS--������ȱ���
{
	printf("%c ", G->vex[index]);

	visit[index] = 1;
	for (int i = 0; i < G->vex_num; i++)
	{
		if (G->edge[index][i] != 0 && G->edge[index][i] != MAX && !visit[i])
		{
			DFS(G, visit, i);
		}
	}
}

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

QueueNode* QueueNode_Init(int T)
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

QueueNode_Type Get_QueueHead(Queue* Q)
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

void BFS(Graph_01* G, int* visit, int index)	// BFS--������ȱ���
{
	printf("%c ", G->vex[index]);
	Queue* Q = Queue_Init();

	QueueNode* pQ = QueueNode_Init(index);
	Queue_PushTail(Q, pQ);
	visit[index] = 1;

	while (!Queue_IsEmpty(Q))
	{
		int m = Get_QueueHead(Q);
		Queue_PopHead(Q);
		for (int i = 0; i < G->vex_num; i++)
		{
			if (G->edge[m][i] != 0 && G->edge[m][i] != MAX && !visit[i])
			{
				printf("%c ", G->vex[i]);
				visit[i] = 1;
				Queue_PushTail(Q, QueueNode_Init(i));
			}
		}
	}
	Queue_Destroy(Q);
}

Edge* Edge_Init(Graph_01* G, int index)	// ��ʼ��
{
	Edge* edge = (Edge*)malloc(sizeof(Edge) * G->vex_num);

	for (int i = 0; i < G->vex_num; i++)
	{
		edge[i].vex = G->vex[index];
		edge[i].weight = G->edge[index][i];
	}

	return edge;
}

int Get_MinEdge(Edge* edge, Graph_01* G)	// ������Ӧ�ߵļ����У�Ѱ����С��
{
	int index = 0;
	int min = INT_MAX;
	for (int i = 0; i < G->vex_num; i++)
	{
		if (edge[i].weight != 0 && edge[i].weight < min)
		{
			min = edge[i].weight;
			index = i;
		}
	}
	return index;	// ������С�ߵ�Ŀ�ĵصı��
}

void Prim_MST(Graph_01* G, int index)		// ��С������---Prim�㷨
{
	Edge* edge = Edge_Init(G, index);
	int min = 0;
	for (int i = 0; i < G->vex_num - 1; i++)	// ����ѭ��n-1����������С�������ı���һ���ǽ����-1
	{
		min = Get_MinEdge(edge, G);
		printf("v%c -> v%c, weight is %d\n", edge[min].vex, G->vex[min], edge[min].weight);
		edge[min].weight = 0;
		// ��������¼�����С�������Ľڵ��Ӧ��·���и�Сֵ����ô�ͽ�edge���ϵ����λ�øı䣬������·��Ȩֵ����
		for (int j = 0; j < G->vex_num; j++)
		{
			if (edge[j].weight != 0 && G->edge[min][j] < edge[j].weight)
			{
				edge[j].weight = G->edge[min][j];
				edge[j].vex = G->vex[min];
			}
		}
	}
}

// Kruskal�㷨
K_Edge* initK_Edge(Graph_01* G)
{
	K_Edge* edge = (K_Edge*)malloc(sizeof(K_Edge) * (G->edge_num));
	int index = 0;
	for (int i = 0; i < G->vex_num; i++)
	{
		for (int j = i+1; j < G->vex_num; j++)
		{
			if(G->edge[i][j] != MAX)
			{
				edge[index].start = i;
				edge[index].end = j;
				edge[index].weight = G->edge[i][j];
				index++;
			}
		}
	}
	return edge;
}

void sortK_Edge(Graph_01* G, K_Edge* edge)
{
	K_Edge temp;
	for (int i = 0; i < G->edge_num-1; i++)
	{
		for (int j = 0; j < G->edge_num - i - 1; j++)
		{
			if (edge[j].weight > edge[j + 1].weight)
			{
				temp = edge[j];
				edge[j] = edge[j + 1];
				edge[j + 1] = temp;
			}
		}
	}
}

void Kruskal_MST(Graph_01* G)
{
	// 1.������ͨ�������飬���ڱ�ʾÿ������֮���Ƿ���ͨ
	//		�����ͨ���������������ͬ����ͨ������2��ֵΪ������ͨ����
	//		��ʼ״̬�£�ÿ���������ͨ�������Ƕ�������ı��
	int* connect = (int*)malloc(sizeof(int) * G->vex_num);
	for (int i = 0; i < G->vex_num; i++)
	{
		connect[i] = i;
	}

	K_Edge* edge = initK_Edge(G);
	sortK_Edge(G, edge);
	// 2.��������������K_Edge���飬����С�߿�ʼ���ϼ�����С������
	for(int i = 0;i<G->edge_num;i++)
	{
		// ѭ����С�����ұ�
		int start = connect[edge[i].start];
		int end = connect[edge[i].end];
		// ȡ�ҵ��ıߵ������յ����ͨ����
		if (start != end)
		{
			// �����ͨ��������ȣ���ô�ͽ��յ���ͨ������ֵ��Ϊ���ģ���������뵽��С������֮��
			printf("v%c -> v%c, weight = %d\n", G->vex[edge[i].start], G->vex[edge[i].end], edge[i].weight);
			for (int j = 0; j < G->vex_num; j++)
			{
				// ������ͨ�������飬�ҵ���ǰ����ָ����յ��Ӧ����ͨ������λ�ã���������Ϊ������ͨ����ֵ
				if (connect[j] == end)
				{
					connect[j] = start;
				}
			}
		}
	}

}