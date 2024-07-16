#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define MAX_Vnum 100

typedef struct Graph_Adjacent_Matrix Graph_Adjacent_Matrix;

struct Graph_Adjacent_Matrix {
	char vex[MAX_Vnum];
	int edge[MAX_Vnum][MAX_Vnum];
	int vex_num;
	int edge_num;
};
// 邻接矩阵法：空间复杂度为n的二次方，适合存储稠密图，否则会造成大量空间浪费
// 
// 记邻接矩阵为A
// A*A 的逻辑意义是得到的矩阵中a[i][j]代表一个路径数量：从顶点集中的顶点vex[i]到vex[j]的路径长度为2的个数
// A*A*A*A*A……（n个A矩阵相乘）则是对应顶点之间路径长度为n的路径个数


