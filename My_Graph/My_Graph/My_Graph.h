#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

#define MAX INT_MAX
// ���ͼ�е�ĳ�������㲻��ͨ����·������ΪMAX

// �ڽӾ��󷨱�ʾͼ
typedef struct Graph_Adjacent_Matrix Graph_01;	

// �ڽӱ�

// ʮ��������ʾ����ͼ

// ����������ʾ����ͼ

struct Graph_Adjacent_Matrix {
	char* vex;
	int** edge;
	int vex_num;
	int edge_num;
};
// �ڽӾ��󷨣��ռ临�Ӷ�Ϊn�Ķ��η����ʺϴ洢����ͼ���������ɴ����ռ��˷�
// 
// ���ڽӾ���ΪA
// A*A ���߼������ǵõ��ľ�����a[i][j]����һ��·���������Ӷ��㼯�еĶ���vex[i]��vex[j]��·������Ϊ2�ĸ���
// A*A*A*A*A������n��A������ˣ����Ƕ�Ӧ����֮��·������Ϊn��·������


// BFS ������ȱ����������нӿں���
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

// �ڽӾ��󡪡��ӿں���
Graph_01* Graph_Init(int vex_num);	// ͼ�ĳ�ʼ��

Graph_01* Graph_Create(Graph_01* G, int* edge, char* vex);	// ͼ�Ĵ���

void DFS(Graph_01* G, int* visit, int index);	// DFS--������ȱ���

void BFS(Graph_01* G, int* visit, int index);	// BFS--������ȱ���

// Prim�㷨
// �����µĽṹ������ά��Prim�㷨���ҵ�ĳ�������е���СȨֵ��·��
typedef struct Edge {
	char vex;
	int weight;
}Edge;

Edge* Edge_Init(Graph_01* G, int index);	// ��ʼ��

int Get_MinEdge(Edge* edge, Graph_01* G);	// ������Ӧ�ߵļ����У�Ѱ����С��

void Prim_MST(Graph_01* G, int index);		// ��С������---Prim�㷨


// Kruskal�㷨
// �����µĽṹ������ά��Kruskal�㷨���ҵ���ÿһ����
typedef struct K_Edge {
	int start;
	int end;
	int weight;
	int num;
}K_Edge;

K_Edge* initK_Edge(Graph_01* G);

void sortK_Edge(Graph_01* G, K_Edge* edge);

void Kruskal_MST(Graph_01* G);


// Dijkstra�㷨
//
typedef struct D_arr {
	int judge;	// �ж��Ƿ�õ������·��
	int path;	// ��ѡ����ǰ���·����ֵ
	int prev;	// ѡȡ��ǰ���·���£�ͨ���յ�ıߵ����
}D_arr;

D_arr* initD_arr(Graph_01* G, int index);

int min_path(D_arr* arr, Graph_01* G);

void Dijkstra(Graph_01* G, int index);