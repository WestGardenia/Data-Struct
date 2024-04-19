#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct TreeNode TreeNode;

struct TreeNode {
	char data;
	TreeNode* LChild;	// �������ӽ��
	TreeNode* RChild;	// �����Һ��ӽڵ�
};

void TreeCreative(TreeNode** RootNode, char* data, int* index);	// ����������

// ���ֱ������������򡢺���--�ݹ����
void preOrder(TreeNode* RootNode);	// ������--�������--��-��-��

void inOrder(TreeNode* RootNode);	// ������--�������--��-��-��

void postOrder(TreeNode* RootNode);		// ������--�������--��-��-��

// ��α�����������ȡ�������ȣ�

