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

// Dijkstra算法
D_arr* initD_arr(Graph_01* G, int index)
{
	D_arr* arr = (D_arr*)malloc(sizeof(D_arr) * G->vex_num);
	for (int i = 0; i < G->vex_num; i++)
	{
		// 目标点等于起点时
		if (i == index)
		{
			arr[i].judge = 1;
			arr[i].path = 0;
			arr[i].prev = -1;
		}
		// 目标点与起点之间存在有效边时
		if (G->edge[index][i] > 0 && G->edge[index][i] < MAX)
		{
			arr[i].judge = 0;
			arr[i].path = G->edge[index][i];
			arr[i].prev = index;
		}
		// 目标点与起点之间不直接相连时
		if (G->edge[index][i] == MAX)
		{
			arr[i].judge = 0;
			arr[i].path = MAX;
			arr[i].prev = -1;
		}
	}
	return arr;
}

int min_path(D_arr* arr, Graph_01* G)
{
	int index = 0;
	int min = MAX;
	for (int i = 0; i < G->vex_num; i++)
	{
		if (!arr[i].judge && arr[i].path < min)
		{
			// 找到未确认最小路径的最小值
			index = i;
			min = arr[i].path;
		}
	}
	return index;
}

void Dijkstra(Graph_01* G, int index)
{
	D_arr* arr = initD_arr(G, index);
	for (int i = 0; i < G->vex_num - 1; i++)
	{
		int min_index = min_path(arr, G);
		arr[min_index].judge = 1;
		for (int j = 0; j < G->vex_num; j++)
		{
			if (!arr[j].judge && G->edge[min_index][j] != MAX && arr[min_index].path + G->edge[min_index][j] < arr[j].path)
			{
				// G->edge[min_index][j] != MAX
				// 判断条件要确保原始边集中，存在起点min_index到终点j的边，否则MAX+MAX会超出int类型表示范围而展示出一个负值
				// 这种情况显然并不符合需求但是却能够满足判断条件。
				arr[j].path = arr[min_index].path + G->edge[min_index][j];
				arr[j].prev = min_index;
			}
		}
	}
	printf("是否有最小路径\t最小路径的前驱\t最小路径权值\n");
	for (int i = 0; i < G->vex_num; i++)
	{
		printf("%d\t\t%d\t\t%d\n", arr[i].judge, arr[i].prev, arr[i].path);
	}
}


void Floyd(Graph_01* G)
{
	int x = 0;
	int path[7][7];
	int prev[7][7];
	for (int i = 0; i < G->vex_num; i++)
	{
		for (int j = 0; j < G->vex_num; j++)
		{
			path[i][j] = G->edge[i][j];
			if (G->edge[i][j] > 0 && G->edge[i][j] != MAX)
				prev[i][j] = i;
			else
				prev[i][j] = -1;
		}
	}

	printf("Floyd算法初始化path数组：\n");
	for (int i = 0; i < G->vex_num; i++)
	{
		for (int j = 0; j < G->vex_num; j++)
		{
			printf("%d\t", path[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("Floyd算法初始化prev数组：\n");
	for (int i = 0; i < G->vex_num; i++)
	{
		for (int j = 0; j < G->vex_num; j++)
		{
			printf("%d\t", prev[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < G->vex_num; i++)
	{
		for (int j = 0; j < G->vex_num; j++)
		{
			for (int k = 0; k < G->vex_num; k++)
			{
				if (path[j][k] > path[j][i] + path[i][k])
				{
					path[j][k] = path[j][i] + path[i][k];
					prev[j][k] = path[i][k];
				}
			}
		}
	}
	printf("\n");
	printf("Floyd算法结束后path数组：\n");
	for (int i = 0; i < G->vex_num; i++)
	{
		for (int j = 0; j < G->vex_num; j++)
		{
			printf("%d\t", path[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("Floyd算法结束后prev数组：\n");
	for (int i = 0; i < G->vex_num; i++)
	{
		for (int j = 0; j < G->vex_num; j++)
		{
			printf("%d\t", prev[i][j]);
		}
		printf("\n");
	}
}


// 拓扑排序算法

stack* Init_Stack()
{
	stacknode* snode = (stacknode*)malloc(sizeof(stacknode));
	snode->data = 0;
	snode->next = NULL;

	stack* Stack = (stack*)malloc(sizeof(stack));
	Stack->top = snode;
	Stack->node_num = 0;

	return Stack;
}

int PopStack(stack* S)
{
	if (Stack_Isempty(S))
	{
		return -1;
	}
	else
	{
		stacknode* newnode = S->top->next;
		S->top->next = newnode->next;
		S->node_num--;
		return newnode->data;
	}
}

void PushStack(stack* S, int data)
{
	stacknode* node = (stacknode*)malloc(sizeof(stacknode));
	if(!Stack_Isempty(S))
	{
		node->data = data;
		node->next = S->top->next;
		S->top->next = node;
	}
	else
	{
		node->data = data;
		node->next = NULL;
		S->top->next = node;
	}
	S->node_num++;
}

int Stack_Isempty(stack* S)
{
	if (!S->node_num)
		return 1;
	else
		return 0;
}

int* Find_Indegrees(Graph_01* G)
{
	int* InDegree = (int*)malloc(sizeof(int) * G->vex_num);
	for (int i = 0; i < G->vex_num; i++)
	{
		InDegree[i] = 0;
	}

	for (int i = 0; i < G->vex_num; i++)
	{
		for (int j = 0; j < G->vex_num; j++)
		{
			if (G->edge[i][j] == 1)
			{
				InDegree[j]++;
			}
		}
	}

	return InDegree;
}

void toposort(Graph_01* G)
{
	int* InDegree = Find_Indegrees(G);
	int* SortOut = (int*)malloc(sizeof(int) * G->vex_num);
	int index = 0;
	stack* S = Init_Stack();
	for (int i = 0; i < G->vex_num; i++)
	{
		SortOut[i] = 0;
	}

	for (int i = 0; i < G->vex_num; i++)
	{
		// 将所有入度为0的顶点的下标压栈
		if (InDegree[i] == 0)
		{
			PushStack(S, i);
		}
	}

	while (!Stack_Isempty(S))
	{
		int vex = PopStack(S);	// 将入度为0的顶点的下标出栈，并赋给SortOut数组
		SortOut[index++] = vex;	// 按照从前到后入度变0的顺序，将相应顶点的下标依次存放到SortOut数组中
		for (int i = 0; i < G->vex_num; i++)
		{
			// 此时以vex只能作为边的起点（没有入度）
			// 判断这样的边有多少，执行一次自减1
			if (G->edge[vex][i])
			{
				InDegree[i]--;
				if (InDegree[i] == 0)
				{
					// 如果下标为i的顶点检查并自减完成之后，入度为0则再次压栈
					PushStack(S, i);
				}
			}
		}
	}
	for (int i = 0; i < G->vex_num; i++)
	{
		printf("%c ", G->vex[SortOut[i]]);
	}
}
