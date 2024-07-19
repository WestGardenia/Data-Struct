#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

#define MAX INT_MAX
// 如果图中的某两个顶点不连通，则路径长度为MAX

// 邻接矩阵法表示图
typedef struct Graph_Adjacent_Matrix Graph_01;	

// 邻接表法

// 十字链表法表示有向图

// 多重链表法表示无向图

struct Graph_Adjacent_Matrix {
	char* vex;
	int** edge;
	int vex_num;
	int edge_num;
};
// 邻接矩阵法：空间复杂度为n的二次方，适合存储稠密图，否则会造成大量空间浪费
// 
// 记邻接矩阵为A
// A*A 的逻辑意义是得到的矩阵中a[i][j]代表一个路径数量：从顶点集中的顶点vex[i]到vex[j]的路径长度为2的个数
// A*A*A*A*A……（n个A矩阵相乘）则是对应顶点之间路径长度为n的路径个数


// BFS 广度优先遍历辅助队列接口函数
typedef struct QueueNode QueueNode;
typedef int QueueNode_Type;

struct QueueNode {
	QueueNode* next;
	QueueNode_Type data;
};

typedef struct Queue Queue;

struct Queue {
	QueueNode* head;
	QueueNode* tail;
};

Queue* Queue_Init();
QueueNode* QueueNode_Init(int T);
bool Queue_IsEmpty(Queue* Q);
void Queue_PushTail(Queue* Q, QueueNode* pQ);
void Queue_PopHead(Queue* Q);
QueueNode_Type Get_QueueHead(Queue* Q);
void Queue_Destroy(Queue* Q);
void QueueNode_Destroy(QueueNode* pQ);

// 邻接矩阵——接口函数
Graph_01* Graph_Init(int vex_num);	// 图的初始化

Graph_01* Graph_Create(Graph_01* G, int* edge, char* vex);	// 图的创建

void DFS(Graph_01* G, int* visit, int index);	// DFS--深度优先遍历

void BFS(Graph_01* G, int* visit, int index);	// BFS--广度优先遍历

// Prim算法
// 定义新的结构体用于维护Prim算法中找到某个顶点中的最小权值的路径
typedef struct Edge {
	char vex;
	int weight;
}Edge;

Edge* Edge_Init(Graph_01* G, int index);	// 初始化

int Get_MinEdge(Edge* edge, Graph_01* G);	// 在起点对应边的集合中，寻找最小边

void Prim_MST(Graph_01* G, int index);		// 最小生成树---Prim算法


// Kruskal算法
// 定义新的结构体用于维护Kruskal算法中找到的每一个边
typedef struct K_Edge {
	int start;
	int end;
	int weight;
	int num;
}K_Edge;

K_Edge* initK_Edge(Graph_01* G);

void sortK_Edge(Graph_01* G, K_Edge* edge);

void Kruskal_MST(Graph_01* G);


// Dijkstra算法
//
typedef struct D_arr {
	int judge;	// 判断是否得到了最短路径
	int path;	// 挑选出当前最短路径的值
	int prev;	// 选取当前最短路径下，通向终点的边的起点
}D_arr;

D_arr* initD_arr(Graph_01* G, int index);

int min_path(D_arr* arr, Graph_01* G);

void Dijkstra(Graph_01* G, int index);