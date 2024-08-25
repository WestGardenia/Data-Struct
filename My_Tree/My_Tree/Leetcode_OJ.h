#pragma once
#include"Tree_Function.h"
#include"heap.h"


int Tree_size(TreeNode* RootNode);	// 计算二叉树节点个数

int Tree_depth(TreeNode* RootNode);	// 计算二叉树最大深度

bool isSameTree(TreeNode* p, TreeNode* q);	// 判断两树是否相同（包括形态结构和数值分布）

bool isSubtree(TreeNode* root, TreeNode* subRoot);	// 判断subRoot是否是root的一棵子树