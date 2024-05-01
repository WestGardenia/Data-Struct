#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

// ����������----BST��Binary Sort Tree��
// һ�������������ϵ����н���ֵ���ȸ��ڵ�С���������ϵ����н���ֵ���ȸ��ڵ��ֵ��
// ͬʱ��������ʶ���������������������������ݹ����ʣ�

// ����BST��
// ��������һ�����ݣ�4��5��19��23��2��8
// ��4Ϊ����㹹����Ȼ��ʣ�µ�������4�Ƚ�
//		5��4��5��Ϊ4���Һ���
//		19��4��ͬʱ��5��19��Ϊ5���Һ���
//		23��4��5��19����23��Ϊ19���Һ���
//		2��4С��2��Ϊ4������
//		����
//		�Դ�����
//			4
//		2		5
//		  	  		19
//				  8		23
//


typedef struct Binary_SortTree BST;

struct Binary_SortTree {
	int val;
	BST* Lchild;
	BST* Rchild;
};

void BST_Insert(BST** RootNode, int data);	// �����������������

BST* BST_Search(BST* RootNode, int key);	// �ڶ����������в���ֵ

void PreOrder_BST(BST* RootNode);	// ǰ�����