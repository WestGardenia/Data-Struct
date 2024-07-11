#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<math.h>



// ���鼯�ڴ���������µ��������ж�Ԫ�������ļ���
// ����ʹ��˫�ױ�ʾ���ܹ���Ч�Ŀ��ٵ��ҵ�ĳ��Ԫ�صĸ����

typedef struct GatherNode G_Node;

struct GatherNode {
	char data;
	int parent;
};

typedef struct Gather Gather;

struct Gather {
	G_Node* array;
};


Gather* InitGather(Gather* G, char* element,int length);	// ���鼯��ʼ��

G_Node Find_RootNode(Gather* G, G_Node* element);	// ���Ҳ��鼯�еĸ����

G_Node Find_RootNode_Optimize(Gather* G, G_Node* element);	// ���Ҳ��鼯�еĸ����--�Ż���
// ԭ�� ��
// ���ҵ���ӦԪ�ظ��ڵ�֮�󣬽����Ԫ�ص����е�parentȫ�����ӵ����ڵ���
// ���ڲ��Ҳ���ʱ����·��ѹ��

void Union(Gather* G, int x1, int x2);	// �ϲ����鼯Ԫ��

void Union_Optimize(Gather* G, int x1, int x2);	// �ϲ����鼯Ԫ��--�Ż�
// �Ż�ԭ��
// ���ڲ��鼯�Ĳ�����˵��ʱ�临�ӶȺ����ɵ����������ֱ�ӹ�ϵ
// ������ÿ�ν��в�����ʱ��ֻ��Ҫȷ���ý�������ٵ�С�����ڴ����ϣ��Ϳ����������ɵ��������
// �����ڵ��parent�ľ���ֵ��ʾ�ÿ����Ľ�������Ƚϵ�ʱ����absȡ����ֵ���бȽ�
// ʱ�临�Ӷ�ΪO(log2n)
//