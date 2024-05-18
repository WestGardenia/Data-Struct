#define _CRT_SECURE_NO_WARNINGS
#include"Graph.h"

MST_Graph* MST_Graph_Init(int vexNum)	// ͼ--��ʼ��
{
	MST_Graph* MG = (MST_Graph*)malloc(sizeof(MST_Graph));
	MG->vexs = (char*)malloc(sizeof(char)*vexNum);
	MG->arcs = (int**)malloc(sizeof(int*) * vexNum);	// ��ʼ���ڽӾ����������

	for (int i = 0; i < vexNum; i++)
	{
		MG->arcs[i] = (int*)malloc(sizeof(int) * vexNum);	// ��ʼ���ڽӾ���ÿһ�е�Ԫ��
	}
	MG->vexNum = vexNum;
	MG->arcNum = 0;

	return MG;
}

void MST_Graph_Creative(MST_Graph* MG, char* vexs, int* arcs)	// ͼ--����	
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

void MST_DFS(MST_Graph* MG, int* visit, int index)	// ͼ--������ȱ���
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

Edge* Edge_Init(MST_Graph* MG, int index)	// ��ʼ����
{
	// ��edge.weight = 0ʱ����������뵽U������
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

void Prim_MST(MST_Graph* MG, int index)	// ��С������--����ķ�㷨
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
