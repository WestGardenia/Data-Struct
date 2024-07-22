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
// Kruskal算法
static void test_02()
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
	int* visit = (int*)malloc(sizeof(int) * G->vex_num);	// 顶点访问标记集合
	for (int i = 0; i < G->vex_num; i++)
	{
		// 初始化标记集合
		visit[i] = 0;
	}
	int num = 0;
	printf("图的以'%d'为起点深度优先遍历结果示例：\n", num);
	DFS(G, visit, num);
	printf("\n");

	printf("Prim算法以'%d'为起点测试用例：\n", num);
	Prim_MST(G, num);

	printf("\nKruskal算法测试用例：\n");
	Kruskal_MST(G);
}

// 最短路径测试用例
static void test_03()
{
	printf("3.图----计算最短路径算法测试用例：\n");
	Graph_01* G = Graph_Init(7);
	int arr_01[7][7] = {
		0,12,MAX,MAX,MAX,16,14,
		12,0,10,MAX,MAX,7,MAX,
		MAX,10,0,3,5,6,MAX,
		MAX,MAX,3,0,4,MAX,MAX,
		MAX,MAX,5,4,0,2,8,
		16,7,6,MAX,2,0,9,
		14,MAX,MAX,MAX,8,9,0
	};
	Graph_Create(G, (int*)arr_01, "123456");
	printf("Dijkstra算法数组示例：\n");
	printf("计算前：\n");

	D_arr* arr =  initD_arr(G, 0);
	printf("是否有最小路径\t最小路径的前驱\t最小路径权值\n");
	for(int i = 0;i<G->vex_num;i++)
	{
		printf("%d\t\t%d\t\t%d\n", arr[i].judge, arr[i].prev, arr[i].path);
	}
	printf("\n");
	printf("计算后：\n");
	Dijkstra(G, 0);

	Floyd(G);
}

// 拓扑排序测试用例
void test_04()
{
	printf("4.图----拓扑排序测试用例：\n");
	Graph_01* G = Graph_Init(6);
	int arr_01[6][6] = {
		0,1,1,1,0,0,
		0,0,0,0,0,0,
		0,1,0,0,1,0,
		0,0,0,0,1,0,
		0,0,0,0,0,0,
		0,0,0,1,1,0
	};
	Graph_Create(G, (int*)arr_01, "123456");
	int* visit = (int*)malloc(sizeof(int) * G->vex_num);	// 顶点访问标记集合
	for (int i = 0; i < G->vex_num; i++)
	{
		// 初始化标记集合
		visit[i] = 0;
	}
	int num = 0;
	printf("图的以'%d'为起点深度优先遍历结果示例：\n", num);
	DFS(G, visit, num);

	printf("\n");
	printf("图的拓扑排序结果示例：\n");
	toposort(G);
}

int main()
{
	//test_01();
	//test_02();
	//test_03();
	test_04();

	return 0;
}