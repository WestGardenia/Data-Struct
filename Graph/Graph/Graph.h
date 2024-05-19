#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef struct Graph Graph;

struct Graph {
	char* vexs;	// 顶点
	int** arcs;	// 边 -- 二维数组，连接两个顶点，所以需要二级指针
	int vexNum;	// 顶点数
	int arcNum;	// 边数
};

// 邻接矩阵创建图
// 邻接矩阵存储方式使用两个数组来表示图。
//	一维数组（vexs）表示图的顶点信息；二维数组（arcs）表示图的边或弧（有向图的边）信息
// 
// 对于无向图G来说，可以这样表示：
//	G = （V，{E}）
//		V = {A, B, C,D……}		E = {(A, B), (B, C), (A, C), (A, D), ……）
// 邻接矩阵就是所谓的二维数组arc[i][j]
//				1	，表示矩阵对应的边（顶点对）在集合E中
// arc[i][j] = 
//				0	，其他
// 
// 无向图的邻接矩阵也是对称矩阵
//	其主对角线上的值都是0-------不存在顶点到自身的边
//				
Graph* GraphInit(int vexNum);	// 初始化图

void GraphCreate(Graph* MyGraph, char* vexs, int* arcs);	// 创建图

// DFS--深度优先遍历
//	1、找一个节点访问
//	2、找这个节点可以到达的节点
//	3、回到第一步，并判断这个结点是否被访问过
//		如果被访问过，那么将另选一个未被访问的结点
//	4、直到图中所有结点都被访问
// 
// 所以本质上是一种类似于树的层次遍历
//
void DFS(Graph* G, int* visit, int index);	// 图--深度优先遍历DFS

// BFS--广度优先遍历
void BFS(Graph* G, int* visit, int index);	// 图--广度优先遍历BFS

typedef struct Queue Queue;
typedef int NodeType;
typedef struct Node Node;
struct Node {
	NodeType data;
	Node* next;
};

struct Queue {
	Node* front;
	Node* tail;
};

Queue* InitQueue();
void PrintQueue(Queue* Q);
bool isEmpty(Queue* Q);
void enQueue(Queue* Q, NodeType val);
NodeType deQueue(Queue** Q);


// 最小生成树
//		最小生成树其实是最小权重生成树的简称。
//		在连通网的所有生成树中，所有边的代价和最小的生成树，称为最小生成树。
// 连通图
//		如果某张无向图的任意两个节点都有路径相通（不一定直接相连），则称为连通图
// 
// 用最小生成树解决的实际问题：
//		如在n各城市之间铺设光缆，要求每个城市都要覆盖，同时费用要最小，这时就可以用最小生成树解决问题
// 
// Prim算法（普利姆算法）
//		此算法可以称为“加点法”，每次迭代权值最小的边对应的点，加入到最小生成树中。算法从某一个顶点s开始，逐渐长大覆盖整个连通网的所有顶点。
//
//		1、图的所有顶点集合为VV；初始令集合u = { s }, v = V−uu = { s }, v = V−u;
//		2、在两个集合u, vu, v能够组成的边中，选择一条代价最小的边(u0, v0)(u0, v0)，加入到最小生成树中，并把v0v0并入到集合u中。
//		3、重复上述步骤，直到最小生成树有n - 1条边或者n个顶点为止。
//		4、由于不断向集合u中加点，所以最小代价边必须同步更新；需要建立一个辅助数组closedge, 用来维护集合v中每个顶点与集合u中最小代价边信息
//


// 如果两个顶点之间不通，那么权值为MAX
// 如果定点是自己本身，那么权值为0
#define MAX 32767

typedef struct MST_Graph MST_Graph;

struct MST_Graph {
	char* vexs;	// 顶点
	int** arcs;	// 边
	int vexNum;	// 顶点数
	int arcNum;	// 边数
};

MST_Graph* MST_Graph_Init(int vexNum);	// 图--初始化

void MST_Graph_Creative(MST_Graph* MG, char* vexs, int* arcs);	// 图--创建	

void MST_DFS(MST_Graph* MG, int* visit, int index);	// 图--深度优先遍历

void Prim_MST();	// 最小生成树--普利姆算法
// 记录当前U集合的状态
// 选择最小边以及顶点加入到U集合中

typedef struct Edge {
	char vex;	// 记录U集合到最小边的起始节点
	int weight;	// 记录最小边
}Edge;

Edge* Edge_Init(MST_Graph* MG, int index);	// 初始化边

int getMinEdge(Edge* edge, MST_Graph* MG);

void Prim_MST(MST_Graph* MG, int index);	// 最小生成树--普利姆算法

typedef struct K_MST K_MST;

struct K_MST {
	char* vexs;
	int** arcs;
	int vexNum;
	int arcNum;
};


K_MST* K_MST_Init(int vexNum);
void K_MST_Creative(K_MST* K_MG, char* vex, int* arc);
void K_MST_DFS(K_MST* K_MG, int index, int* visit);

typedef struct K_Edge K_Edge;

struct K_Edge {
	int start;
	int end;
	int weight;
};

K_Edge* K_Edge_Init(K_MST* K_MG);

void K_Edge_Sort(K_Edge* edge, K_MST* K_MG);

void kruskal(K_MST* K_MG);	// 最小生成树--克鲁斯卡尔算法

// 克鲁斯卡尔算法
// 1、对边排序
// 2、选边--确保选出来的边相连不会得到回路
// 
// 需要维护一个边的数组，并对其中的边进行排序
// 判断图是否连通（生成树中是否有回路）：
//		需要一个辅助数组，去记录当前索引的结点所属于哪个连通分量
// 
// 
// 