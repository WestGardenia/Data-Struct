#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

typedef struct AVL_Tree AVLnode;

struct AVL_Tree {
	int data;
	int height;
	AVLnode* lchild;
	AVLnode* rchild;
};

AVLnode* AVLNode_Init(int val);

void AVL_Tree_Insert(AVLnode** T,int val);

void LL_Rotation(AVLnode* node, AVLnode** root);

void RR_Rotation(AVLnode* node, AVLnode** root);

void AVL_Tree_InOrder(AVLnode* T);

void AVL_Tree_PreOrder(AVLnode* T);

