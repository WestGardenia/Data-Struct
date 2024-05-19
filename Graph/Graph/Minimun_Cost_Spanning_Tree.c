#define _CRT_SECURE_NO_WARNINGS
#include"Graph.h"

void Is_NULL(void* ptr)
{
	if (ptr == NULL)
	{
		return;
		exit(-1);
	}
}

MST_Graph* MST_Graph_Init(int vexNum)	// 图--初始化
{
	MST_Graph* MG = (MST_Graph*)malloc(sizeof(MST_Graph));
	MG->vexs = (char*)malloc(sizeof(char)*vexNum);
	Is_NULL((MST_Graph*)MG);
	MG->arcs = (int**)malloc(sizeof(int*) * vexNum);	// 初始化邻接矩阵的行数组

	for (int i = 0; i < vexNum; i++)
	{
		MG->arcs[i] = (int*)malloc(sizeof(int) * vexNum);	// 初始化邻接矩阵每一行的元素
		if (MG->arcs[i] == NULL)
		{
			return NULL;
			exit(-1);
		}
	}
	MG->vexNum = vexNum;
	MG->arcNum = 0;

	return MG;
}

void MST_Graph_Creative(MST_Graph* MG, char* vexs, int* arcs)	// 图--创建	
{
	for (int i = 0; i < MG->vexNum; i++)
	{
		MG->vexs[i] = vexs[i];
		for (int j = 0; j < MG->vexNum; j++)
		{
			MG->arcs[i][j] = arcs[i * MG->vexNum + j];

			if (MG->arcs[i][j] != 0 && MG->arcs[i][j] != MAX)
			{
				MG->arcNum++;
			}
		}
	}
	MG->arcNum /= 2;
}

void MST_DFS(MST_Graph* MG, int* visit, int index)	// 图--深度优先遍历
{
	printf("%c ", MG->vexs[index]);
	visit[index] = 1;
	for (int i = 0; i < MG->vexNum; i++)
	{
		if (visit[i] != 1 && MG->arcs[index][i] != 0 && MG->arcs[index][i] != MAX)
		{
			MST_DFS(MG, visit, i);
		}
	}
}

Edge* Edge_Init(MST_Graph* MG, int index)	// 初始化边
{
	// 当edge.weight = 0时，代表顶点加入到U集合中
	Edge* edge = (Edge*)malloc(sizeof(Edge) * MG->vexNum);
	for (int i = 0; i < MG->vexNum; i++)
	{
		edge[i].vex = MG->vexs[i];
		edge[i].weight = MG->arcs[index][i];
	}
	return edge;
}

int getMinEdge(Edge* edge, MST_Graph* MG)
{
	int index = 0;
	int min = MAX;
	for (int i = 0; i < MG->vexNum; i++)
	{
		if (edge[i].weight != 0 && min > edge[i].weight)
		{
			min = edge[i].weight;
			index = i;
		}
	}
	return index;
}

void Prim_MST(MST_Graph* MG, int index)	// 最小生成树--普利姆算法
{
	int min = MAX; 
	Edge* edge = Edge_Init(MG,index);
	for (int i = 0; i < MG->vexNum - 1; i++)
	{
		min = getMinEdge(edge, MG);
		printf("v%c->v%c, weight = %d\n", edge[min].vex, MG->vexs[min], edge[min].weight);
		edge[min].weight = 0;
		for (int j = 0; j < MG->vexNum; j++)
		{
			if (MG->arcs[min][j] < edge[j].weight)
			{
				edge[j].weight = MG->arcs[min][j];
				edge[j].vex = MG->vexs[min];
			}
		}
	}
}


K_MST* K_MST_Init(int vexNum)
{
	K_MST* K_MG = (K_MST*)malloc(sizeof(K_MST));
	K_MG->vexNum = vexNum;
	K_MG->vexs = (char*)malloc(sizeof(char) * vexNum);

	K_MG->arcs = (int**)malloc(sizeof(int*) * vexNum);

	for (int i = 0; i < vexNum; i++)
	{
		K_MG->arcs[i] = (int*)malloc(sizeof(int) * vexNum);
	}
	K_MG->arcNum = 0;

	return K_MG;
}

void K_MST_Creative(K_MST* K_MG, char* vex, int* arc)
{
	for (int i = 0; i < K_MG->vexNum; i++)
	{
		K_MG->vexs[i] = vex[i];
		for (int j = 0; j < K_MG->vexNum; j++)
		{
			K_MG->arcs[i][j] = arc[i * K_MG->vexNum + j];
			if (K_MG->arcs[i][j] != 0 && K_MG->arcs[i][j] != MAX)
			{
				K_MG->arcNum++;
			}
		}
	}
	K_MG->arcNum /= 2;
}

void K_MST_DFS(K_MST* K_MG, int index, int* visit)
{
	printf("%c ", K_MG->vexs[index]);
	visit[index] = 1;

	for (int i = 0; i < K_MG->vexNum; i++)
	{
		if (K_MG->arcs[index][i] != 0 && K_MG->arcs[index][i] != MAX && visit[i] != 1)
		{
			K_MST_DFS(K_MG, i, visit);
		}
	}
}

K_Edge* K_Edge_Init(K_MST* K_MG)
{
	int index = 0;
	K_Edge* K_edge = (K_Edge*)malloc(sizeof(K_Edge) * K_MG->arcNum);
	for (int i = 0; i < K_MG->vexNum; i++)
	{
		for (int j = i + 1; j < K_MG->vexNum; j++)
		{
			if (K_MG->arcs[i][j] != 0 && K_MG->arcs[i][j] != MAX)
			{
				K_edge[index].start = i;
				K_edge[index].end = j;
				K_edge[index].weight = K_MG->arcs[i][j];
				index++;
			}
		}
	}
	return K_edge;
}

void K_Edge_Sort(K_Edge* edge, K_MST* K_MG)
{
	K_Edge temp;
	for (int i = 0; i < K_MG->vexNum-1; i++)
	{
		for (int j = 0; j < K_MG->vexNum -i-1; j++)
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

void kruskal(K_MST* K_MG)
{
	int* connect = (int*)malloc(sizeof(int) * K_MG->vexNum);
	for (int i = 0; i < K_MG->vexNum; i++)
	{
		connect[i] = i;
	}
	K_Edge* edge = K_Edge_Init(K_MG);
	K_Edge_Sort(edge,K_MG);
	for (int i = 0; i < K_MG->vexNum; i++)
	{
		int start = connect[edge[i].start];
		int end = connect[edge[i].end];
		if (start != end)
		{
			printf("v%c --> v%c weight = %d\n", K_MG->vexs[edge[i].start], K_MG->vexs[edge[i].end], edge[i].weight);
			for (int j = 0; j < K_MG->vexNum; j++)
			{
				if (connect[j] == end)
				{
					connect[j] = start;
				}
			}
		}
	}
}

void Kruskal_MST(MST_Graph* MG, int index)		// 最小生成树--克鲁斯卡尔算法
{

}
