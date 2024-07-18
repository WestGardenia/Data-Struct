#define _CRT_SECURE_NO_WARNINGS

#include"My_Graph.h"

Graph_01* Graph_Init(int vex_num)	// 图的初始化
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

Graph_01* Graph_Create(Graph_01* G, int* edge, char* vex)	// 创建图
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

void DFS(Graph_01* G, int* visit, int index)	// DFS--深度优先遍历
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

void BFS(Graph_01* G, int* visit, int index)	// BFS--广度优先遍历
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

Edge* Edge_Init(Graph_01* G, int index)	// 初始化
{
	Edge* edge = (Edge*)malloc(sizeof(Edge) * G->vex_num);

	for (int i = 0; i < G->vex_num; i++)
	{
		edge[i].vex = G->vex[index];
		edge[i].weight = G->edge[index][i];
	}

	return edge;
}

int Get_MinEdge(Edge* edge, Graph_01* G)	// 在起点对应边的集合中，寻找最小边
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
	return index;	// 返回最小边的目的地的编号
}

void Prim_MST(Graph_01* G, int index)		// 最小生成树---Prim算法
{
	Edge* edge = Edge_Init(G, index);
	int min = 0;
	for (int i = 0; i < G->vex_num - 1; i++)	// 这里循环n-1次是由于最小生成树的边数一定是结点数-1
	{
		min = Get_MinEdge(edge, G);
		printf("v%c -> v%c, weight is %d\n", edge[min].vex, G->vex[min], edge[min].weight);
		edge[min].weight = 0;
		// 如果发现新加入最小生成树的节点对应的路径有更小值，那么就将edge集合的起点位置改变，并将其路径权值更新
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

// Kruskal算法
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
	// 1.创建连通分量数组，用于表示每个顶点之间是否连通
	//		如果联通，则两顶点会有相同的连通分量，2其值为起点的连通分量
	//		初始状态下，每个顶点的连通分量就是顶点自身的编号
	int* connect = (int*)malloc(sizeof(int) * G->vex_num);
	for (int i = 0; i < G->vex_num; i++)
	{
		connect[i] = i;
	}

	K_Edge* edge = initK_Edge(G);
	sortK_Edge(G, edge);
	// 2.遍历经过排序后的K_Edge数组，从最小边开始不断加入最小生成树
	for(int i = 0;i<G->edge_num;i++)
	{
		// 循环从小到大找边
		int start = connect[edge[i].start];
		int end = connect[edge[i].end];
		// 取找到的边的起点和终点的联通分量
		if (start != end)
		{
			// 如果连通分量不相等，那么就将终点连通分量的值变为起点的，并将其加入到最小生成树之中
			printf("v%c -> v%c, weight = %d\n", G->vex[edge[i].start], G->vex[edge[i].end], edge[i].weight);
			for (int j = 0; j < G->vex_num; j++)
			{
				// 遍历连通分量数组，找到当前边所指向的终点对应的连通分量的位置，并将其置为起点的连通分量值
				if (connect[j] == end)
				{
					connect[j] = start;
				}
			}
		}
	}

}