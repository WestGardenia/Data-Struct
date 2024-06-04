#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

// abd##e##cf##g##

//			a		
//		b		c
//	  d	  f	  f	  g
//


typedef struct TreeNode TreeNode;

struct TreeNode {
	TreeNode* lchild;
	TreeNode* rchild;
	char data;
};

void Create_BinaryTree(TreeNode** RootNode,char* val,int* index);
void PreOrder(TreeNode* RootNode);
void InOrder(TreeNode* RootNode);
void PostOrder(TreeNode* RootNode);

