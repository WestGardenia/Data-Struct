#define _CRT_SECURE_NO_WARNINGS

#include"My_Graph.h"

static void test_01()
{
	printf("1.ͼ----�����㷨����������\n");
	Graph_01* G = Graph_Init(5);
	int arr_01[5][5] = {
		0,1,1,1,0,
		1,0,1,1,1,
		1,1,0,0,0,
		1,1,0,0,1,
		0,1,0,1,0
	};	// �ڽӾ���
	int* visit = (int*)malloc(sizeof(int) * G->vex_num);	// ������ʱ�Ǽ���
	for (int i = 0; i < G->vex_num; i++)
	{
		// ��ʼ����Ǽ���
		visit[i] = 0;
	}
	char arr_02[5] = { 'a','b','c','d','e' };
	G = Graph_Create(G, (int*)arr_01, arr_02);

	for (int i = 0; i < G->vex_num; i++)
	{
		printf("%c ", G->vex[i]);
	}
	printf("\n");
	printf("��ӡ�ڽӾ���\n");
	for (int m = 0; m < G->vex_num; m++)
	{
		for (int n = 0; n < G->vex_num; n++)
		{
			printf("%d ", G->edge[m][n]);
		}
		printf("\n");
	}

	int num = 2;
	printf("��%cΪ��㣬������ȱ������н���ǣ�",G->vex[num]);
	DFS(G, visit, num);
	printf("\n");

	for (int i = 0; i < G->vex_num; i++)
	{
		// ��ʼ����Ǽ���
		visit[i] = 0;
	}
	printf("��%cΪ��㣬������ȱ������н���ǣ�", G->vex[num]);
	DFS(G, visit, num);
	printf("\n");
}

// ��С��������������
// Prim�㷨
// Kruskal�㷨
static void test_02()
{
	printf("2.ͼ----����С����������������\n");
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
	int* visit = (int*)malloc(sizeof(int) * G->vex_num);	// ������ʱ�Ǽ���
	for (int i = 0; i < G->vex_num; i++)
	{
		// ��ʼ����Ǽ���
		visit[i] = 0;
	}
	int num = 0;
	printf("ͼ����'%d'Ϊ���������ȱ������ʾ����\n", num);
	DFS(G, visit, num);
	printf("\n");

	printf("Prim�㷨��'%d'Ϊ������������\n", num);
	Prim_MST(G, num);

	printf("\nKruskal�㷨����������\n");
	Kruskal_MST(G);
}

// ���·����������
static void test_03()
{
	printf("3.ͼ----�������·���㷨����������\n");
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
	printf("Dijkstra�㷨����ʾ����\n");
	printf("����ǰ��\n");

	D_arr* arr =  initD_arr(G, 0);
	printf("�Ƿ�����С·��\t��С·����ǰ��\t��С·��Ȩֵ\n");
	for(int i = 0;i<G->vex_num;i++)
	{
		printf("%d\t\t%d\t\t%d\n", arr[i].judge, arr[i].prev, arr[i].path);
	}
	printf("\n");
	printf("�����\n");
	Dijkstra(G, 0);

	Floyd(G);
}

// ���������������
void test_04()
{
	printf("4.ͼ----�����������������\n");
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
	int* visit = (int*)malloc(sizeof(int) * G->vex_num);	// ������ʱ�Ǽ���
	for (int i = 0; i < G->vex_num; i++)
	{
		// ��ʼ����Ǽ���
		visit[i] = 0;
	}
	int num = 0;
	printf("ͼ����'%d'Ϊ���������ȱ������ʾ����\n", num);
	DFS(G, visit, num);

	printf("\n");
	printf("ͼ������������ʾ����\n");
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