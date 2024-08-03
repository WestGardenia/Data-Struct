#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Binary_Sort_Tree BST;

struct Binary_Sort_Tree {
	int data;
	BST* lchild;
	BST* rchild;
};

BST* BST_Init(int val);

void BST_InOrder(BST* T);

BST* BST_Search(BST* T, int val);

void BST_Insert(BST** T, int val);

BST* FindMin(BST* node);

BST* BST_Delete(BST* T, int val);

void BST_Creat(BST** T, int arr[], int num);