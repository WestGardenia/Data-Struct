#define _CRT_SECURE_NO_WARNINGS 
#include"Graph.h"

static void test_01()
{
	Graph* G = GraphInit(5);
	int arcs[5][5] = {
		0,1,1,1,0,
		1,0,1,1,1,
		1,1,0,0,0,
		1,1,0,0,1,
		0,1,0,1,0
	};
	int* visit = (int*)malloc(sizeof(int) * G->vexNum);
	for (int i = 0; i < G->vexNum; i++)
	{
		visit[i] = 0;
	}

	GraphCreate(G, "ABCDE", (int*)arcs);
	DFS(G, visit, 0);
	printf("\n");
	for (int i = 0; i < G->vexNum; i++)
	{
		visit[i] = 0;
	}

	BFS(G, visit, 0);
}

void test_02()
{
	Queue* Q = InitQueue();
	int  ch[5] = { 1,2,3,4,5 };
	for (int i = 0; i < 5; i++)
	{
		enQueue(Q, ch[i]);
	}
	PrintQueue(Q);
	printf("\n");
	int test_QueueTail = deQueue(Q);
	printf("%d ", test_QueueTail);
}

int main()
{
	test_01();
	//test_02();
}