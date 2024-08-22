#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

#define MAX SHRT_MAX
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
// 思路：
// 1、将图中结点0 作为起点到达各个结点的路径作为最小路径长度记录在D_arr结构体的一维数组path中。
//		将path数组的下标作为目标节点的编号。例如结点0 到达结点1 的当前最短路径就是path[1]的值		注意：数组下标从0开始
//		path数组中，如果结点0 能够直接到达目标节点，则直接将路径长度填入对应数组位置；
//					如果目标节点i 是其本身或者没有直接到达目标结点的路径，就将路径长度，即对应path[i]值设为MAX，意味无穷大
// 2、在第一步骤得到的path数组中，找到其中的最小值path[j]，则结点j 作为此次的起点，并将节点j 的标志位置为1，表示此时已经找到了最短路径。
//	  重复第一步中的寻找最短路径的工作。
//		注意：
//			1、此时如果结点j 作为起点到各个目标节点i 没有直接路径，就将上一步的path[i]继承到这一步
//			2、此时如果……有直接路径，那么需要进行计算：
//				（edge[j][i]表示结点j 到结点i 的路径长度）
//				路径长度edge[j][i] + edge[0][j]  和	edge[0][i] 的大小关系：
//					如果前者大于后者，那么原来path中的数据就不需要改变
//					如果前者小于后者，那么就将原来path数组中的数据更新为新的数据： edge[j][i] + edge[0][j]
//				这一步的计算本质上是去判断：结点0 到结点i 的路径是直接路径更短，还是依靠某个节点作为中转后的路径更短
// 3、重复第二步的寻找path数组中最小值、判断前一次的数据和此次计算的数据的大小
//		并更新path数组
// 
// 4、图中有n个节点，那么就将执行上述操作n次，最后得到的path数组就是结点0 到不同节点的最短路径数组。其中存储的就是最短路径
//		
//
typedef struct D_arr {
	int judge;	// 判断是否得到了最短路径
	int path;	// 挑选出当前最短路径的值
	int prev;	// 选取当前最短路径下，通向终点的边的起点
}D_arr;

D_arr* initD_arr(Graph_01* G, int index);	// 结构体初始化函数

int min_path(D_arr* arr, Graph_01* G);		// 寻找path数组中最小值，并将其下标（节点标号）返回函数

void Dijkstra(Graph_01* G, int index);		// 迪杰斯特拉算法


// Floyd算法

void Floyd(Graph_01* G);


// 拓扑排序算法

typedef struct stack stack;
typedef struct stacknode stacknode;

struct stack {
	stacknode* top;
	int node_num;
};

struct stacknode {
	int data;
	stacknode* next;
};

stack* Init_Stack();

void PushStack(stack* S, int data);

int PopStack(stack* S);

int Stack_Isempty(stack* S);

int* Find_Indegrees(Graph_01* G);

void toposort(Graph_01* G);