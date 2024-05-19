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
	printf("\n");
}

static void test_02()
{
	Queue* Q = InitQueue();
	int  ch[5] = { 1,2,3,4,5 };
	for (int i = 0; i < 5; i++)
	{
		enQueue(Q, ch[i]);
	}
	PrintQueue(Q);
	printf("\n");
	int test_QueueTail = deQueue(&Q);
	printf("%d ", test_QueueTail);
}

// 待定
static void test_03()
{
	MST_Graph* MG = MST_Graph_Init(6);
	int arc[6][6] = {
		0,6,1,5,MAX,MAX,
		6,0,5,MAX,3,MAX,
		1,5,0,5,6,4,
		5,MAX,5,0,MAX,2,
		MAX,3,6,MAX,0,6,
		MAX,MAX,4,2,6,0
	};
	MST_Graph_Creative(MG, "123456", (int*)arc);

	int* visit = (int*)malloc(sizeof(int) * MG->vexNum);
	for (int i = 0; i < MG->vexNum; i++)
	{
		visit[i] = 0;
	}
	MST_DFS(MG, visit, 5);
	printf("\n");

	Prim_MST(MG, 0);	// 最小生成树--普利姆算法
}

// 待定
static void test_04()
{
	K_MST* K_MG = K_MST_Init(6);
	int arc[6][6] = {
		0,6,1,5,MAX,MAX,
		6,0,5,MAX,3,MAX,
		1,5,0,5,6,4,
		5,MAX,5,0,MAX,2,
		MAX,3,6,MAX,0,6,
		MAX,MAX,4,2,6,0
	};
	K_MST_Creative(K_MG, "123456", (int*)arc);

	int* visit = (int*)malloc(sizeof(int) * K_MG->vexNum);
	for (int i = 0; i < K_MG->vexNum; i++)
	{
		visit[i] = 0;
	}
	K_MST_DFS(K_MG, 0, visit);
	printf("\n");

	kruskal(K_MG);
}

int main()
{
	//test_01();
	//test_02();
	//test_03();
	test_04();
}