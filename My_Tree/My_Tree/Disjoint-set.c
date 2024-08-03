#define _CRT_SECURE_NO_WARNINGS

#include"Disjoint-set.h"

Gather* InitGather(Gather* G, char* element, int length)	// ���鼯��ʼ��
{
	G = (Gather*)malloc(sizeof(Gather));
	assert(G);

	G->array = (G_Node*)malloc(sizeof(G_Node)*length);
	assert(G->array);

	for (int i = 0; i < length; i++)
	{
		G->array[i].data = element[i];
		G->array[i].parent = -1;
	}

	return G;
}

G_Node Find_RootNode(Gather* G, G_Node* element)	// ���Ҳ��鼯�еĸ����
{
	int x = element->parent;
	while (x >= 0)
	{
		x = G->array[x].parent;
	}

	return G->array[x];
}

G_Node Find_RootNode_Optimize(Gather* G, G_Node* element)	// ���Ҳ��鼯�еĸ����--�Ż���
{
	int x = element->parent;
	int root = x;
	while (x >= 0)
	{
		x = G->array[x].parent;
	}
	while (root != x)
	{
		int t = G->array[x].parent;
		G->array[x].parent = root;
		x = t;
	}
	return G->array[x];
}

void Union(Gather* G,int x1, int x2)	// �ϲ����鼯Ԫ��
{
	if (x1 == x2)
		return;
	else
	{
		G->array[x1].parent = x2;
	}
}

void Union_Optimize(Gather* G, int x1, int x2)	// �ϲ����鼯Ԫ��--�Ż�
{
	if (x1 == x2)
		return;
	else if (abs(G->array[x1].parent) <= abs(G->array[x2].parent))
	{
		G->array[x2].parent += G->array[x1].parent;
		G->array[x1].parent = G->array[x2].parent;
	}
	else
	{
		G->array[x1].parent += G->array[x2].parent;
		G->array[x2].parent = G->array[x1].parent;
	}
}