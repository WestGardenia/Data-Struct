#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

#define MAX SHRT_MAX
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
// ˼·��
// 1����ͼ�н��0 ��Ϊ��㵽���������·����Ϊ��С·�����ȼ�¼��D_arr�ṹ���һά����path�С�
//		��path������±���ΪĿ��ڵ�ı�š�������0 ������1 �ĵ�ǰ���·������path[1]��ֵ		ע�⣺�����±��0��ʼ
//		path�����У�������0 �ܹ�ֱ�ӵ���Ŀ��ڵ㣬��ֱ�ӽ�·�����������Ӧ����λ�ã�
//					���Ŀ��ڵ�i ���䱾�����û��ֱ�ӵ���Ŀ�����·�����ͽ�·�����ȣ�����Ӧpath[i]ֵ��ΪMAX����ζ�����
// 2���ڵ�һ����õ���path�����У��ҵ����е���Сֵpath[j]������j ��Ϊ�˴ε���㣬�����ڵ�j �ı�־λ��Ϊ1����ʾ��ʱ�Ѿ��ҵ������·����
//	  �ظ���һ���е�Ѱ�����·���Ĺ�����
//		ע�⣺
//			1����ʱ������j ��Ϊ��㵽����Ŀ��ڵ�i û��ֱ��·�����ͽ���һ����path[i]�̳е���һ��
//			2����ʱ���������ֱ��·������ô��Ҫ���м��㣺
//				��edge[j][i]��ʾ���j �����i ��·�����ȣ�
//				·������edge[j][i] + edge[0][j]  ��	edge[0][i] �Ĵ�С��ϵ��
//					���ǰ�ߴ��ں��ߣ���ôԭ��path�е����ݾͲ���Ҫ�ı�
//					���ǰ��С�ں��ߣ���ô�ͽ�ԭ��path�����е����ݸ���Ϊ�µ����ݣ� edge[j][i] + edge[0][j]
//				��һ���ļ��㱾������ȥ�жϣ����0 �����i ��·����ֱ��·�����̣���������ĳ���ڵ���Ϊ��ת���·������
// 3���ظ��ڶ�����Ѱ��path��������Сֵ���ж�ǰһ�ε����ݺʹ˴μ�������ݵĴ�С
//		������path����
// 
// 4��ͼ����n���ڵ㣬��ô�ͽ�ִ����������n�Σ����õ���path������ǽ��0 ����ͬ�ڵ�����·�����顣���д洢�ľ������·��
//		
//
typedef struct D_arr {
	int judge;	// �ж��Ƿ�õ������·��
	int path;	// ��ѡ����ǰ���·����ֵ
	int prev;	// ѡȡ��ǰ���·���£�ͨ���յ�ıߵ����
}D_arr;

D_arr* initD_arr(Graph_01* G, int index);	// �ṹ���ʼ������

int min_path(D_arr* arr, Graph_01* G);		// Ѱ��path��������Сֵ���������±꣨�ڵ��ţ����غ���

void Dijkstra(Graph_01* G, int index);		// �Ͻ�˹�����㷨


// Floyd�㷨

void Floyd(Graph_01* G);


// ���������㷨

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