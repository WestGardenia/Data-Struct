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
// �ڽӾ��󷨣��ռ临�Ӷ�Ϊn�Ķ��η����ʺϴ洢����ͼ���������ɴ����ռ��˷�
// 
// ���ڽӾ���ΪA
// A*A ���߼������ǵõ��ľ�����a[i][j]����һ��·���������Ӷ��㼯�еĶ���vex[i]��vex[j]��·������Ϊ2�ĸ���
// A*A*A*A*A������n��A������ˣ����Ƕ�Ӧ����֮��·������Ϊn��·������


