#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

// ��������:��֤����Ҷ�ӽڵ��·��Ȩֵ����С
// 


// ���ɹ���������
// 1���ӽ���б���ѡ����һС�͵ڶ�С�Ľ�㣬�����һ���������׽���Ȩֵ = ���ڵ�Ȩֵ֮��
// 2�������ɵ������ٴη���ڵ��б��У��ظ���һ����ֱ���б���ֻ����һ�����
//

// ���������룺
// ÿһ����Ԫ���ؾ��ǹ��������е�Ȩֵ
// ���أ�Ȩֵ��Խ��·��Ҳ��Խ��
// ȷ��ʹ�����ַ����в�ͬ�ַ��ı����ͬʱ��ȷ����ÿ���ַ��������ض��ĸ��Ӻ���ĸ���
//

// ��������������
//	��Ҫ�ļ���������
//		1��ʹ��ָ��Ȩֵ�Ľ�����ɹ�������
//		2��������������
//		3��ȡ�ڵ���������С�������ڵ�
//		4���������Ĵ洢�ṹ��˳���
//

typedef struct Huffman_Tree Huffman_Tree;

typedef struct HF_TreeNode {
	int weight;
	int parent;
	int Lchild;
	int Rchild;
}HF_TreeNode;

struct Huffman_Tree {
	HF_TreeNode* data;
	int length;
};

Huffman_Tree* Huffman_TreeInit(int* weight,int length);	// weight��Ȩֵ�б����飩��length�ǳ���

int* select_minweight(Huffman_Tree* HFTree);	// ѡȡ��СȨֵ���������

void createHFTree(Huffman_Tree* HFTree);	// ������������

void HFT_preOrder(Huffman_Tree* HFTree, int index);	// �����������������