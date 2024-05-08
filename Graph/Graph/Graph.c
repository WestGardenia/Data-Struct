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
		for (int j = 0; j < MyGraph->arcNum; j++)
		{
			// 给邻接矩阵赋值
			MyGraph->arcs[i][j] = *(arcs + i * MyGraph->vexNum * j);
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