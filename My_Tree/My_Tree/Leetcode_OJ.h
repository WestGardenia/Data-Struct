#pragma once
#include"Tree_Function.h"
#include"heap.h"


int Tree_size(TreeNode* RootNode);	// ����������ڵ����

int Tree_depth(TreeNode* RootNode);	// ���������������

bool isSameTree(TreeNode* p, TreeNode* q);	// �ж������Ƿ���ͬ��������̬�ṹ����ֵ�ֲ���

bool isSubtree(TreeNode* root, TreeNode* subRoot);	// �ж�subRoot�Ƿ���root��һ������