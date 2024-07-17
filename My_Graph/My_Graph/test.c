#define _CRT_SECURE_NO_WARNINGS

#include"My_Graph.h"

static void test_01()
{
	printf("1.图----遍历算法测试用例：\n");
	Graph_01* G = Graph_Init(5);
	int arr_01[5][5] = {
		0,1,1,1,0,
		1,0,1,1,1,
		1,1,0,0,0,
		1,1,0,0,1,
		0,1,0,1,0
	};	// 邻接矩阵
	int* visit = (int*)malloc(sizeof(int) * G->vex_num);	// 顶点访问标记集合
	for (int i = 0; i < G->vex_num; i++)
	{
		// 初始化标记集合
		visit[i] = 0;
	}
	char arr_02[5] = { 'a','b','c','d','e' };
	G = Graph_Create(G, (int*)arr_01, arr_02);

	for (int i = 0; i < G->vex_num; i++)
	{
		printf("%c ", G->vex[i]);
	}
	printf("\n");
	printf("打印邻接矩阵：\n");
	for (int m = 0; m < G->vex_num; m++)
	{
		for (int n = 0; n < G->vex_num; n++)
		{
			printf("%d ", G->edge[m][n]);
		}
		printf("\n");
	}

	int num = 2;
	printf("以%c为起点，深度优先遍历序列结果是：",G->vex[num]);
	DFS(G, visit, num);
	printf("\n");

	for (int i = 0; i < G->vex_num; i++)
	{
		// 初始化标记集合
		visit[i] = 0;
	}
	printf("以%c为起点，广度优先遍历序列结果是：", G->vex[num]);
	DFS(G, visit, num);
	printf("\n");
}

// 最小生成树测试用例
// Prim算法
void test_02()
{
	printf("2.图----求最小生成树测试用例：\n");
	Graph_01* G = Graph_Init(6);
	int arr_01[6][6] = {
		0,6,1,5,MAX,MAX,
		6,0,5,MAX,3,MAX,
		1,5,0,5,6,4,
		3,MAX,5,0,MAX,2,
		MAX,3,6,MAX,0,6,
		MAX,MAX,4,2,6,0
	};
	Graph_Create(G, (int*)arr_01,"123456");

	printf("Prim算法测试用例：\n");
	Prim_MST(G, 0);

}

int main()
{
	test_01();
	test_02();
	return 0;
}