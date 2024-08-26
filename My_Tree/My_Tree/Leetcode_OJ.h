#pragma once
#include"Tree_Function.h"
#include"heap.h"


int Tree_size(TreeNode* RootNode);	// ����������ڵ����

int Tree_depth(TreeNode* RootNode);	// ���������������

bool isSameTree(TreeNode* p, TreeNode* q);	// �ж������Ƿ���ͬ��������̬�ṹ����ֵ�ֲ���

bool isSubtree(TreeNode* root, TreeNode* subRoot);	// �ж�subRoot�Ƿ���root��һ������

// �ж϶������Ƿ�Ϊƽ�������
int height(struct TreeNode* root);	// ����������߶Ⱥ���
bool isBalanced(struct TreeNode* root);

// �ؽ�������
TreeNode* create_Tree(char* str, int* index);

// �����k�������
int Tree_Ksize(TreeNode* root,int k);

// ����������ֵΪk�Ľ��
TreeNode* TreeNode_Find(TreeNode* root, int key);

// ����һ����
void Destory_Tree(TreeNode* root);