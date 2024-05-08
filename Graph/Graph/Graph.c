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
		for (int j = 0; j < MyGraph->arcNum; j++)
		{
			// ���ڽӾ���ֵ
			MyGraph->arcs[i][j] = *(arcs + i * MyGraph->vexNum * j);
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