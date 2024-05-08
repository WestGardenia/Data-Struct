#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

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

// BFS--广度优先遍历