#pragma once
#include"Tree_Function.h"
#include"heap.h"


int Tree_size(TreeNode* RootNode);	// 计算二叉树节点个数

int Tree_depth(TreeNode* RootNode);	// 计算二叉树最大深度

bool isSameTree(TreeNode* p, TreeNode* q);	// 判断两树是否相同（包括形态结构和数值分布）

bool isSubtree(TreeNode* root, TreeNode* subRoot);	// 判断subRoot是否是root的一棵子树

// 判断二叉树是否为平衡二叉树
int height(struct TreeNode* root);	// 计算二叉树高度函数
bool isBalanced(struct TreeNode* root);

// 重建二叉树
TreeNode* create_Tree(char* str, int* index);

// 计算第k层结点个数
int Tree_Ksize(TreeNode* root,int k);

// 二叉树查找值为k的结点
TreeNode* TreeNode_Find(TreeNode* root, int key);

// 销毁一棵树
void Destory_Tree(TreeNode* root);