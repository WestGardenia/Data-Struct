#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

// 哈夫曼树:保证树中叶子节点的路径权值和最小
// 


// 生成哈夫曼树：
// 1、从结点列表中选出第一小和第二小的结点，并组成一棵树，父亲结点的权值 = 两节点权值之和
// 2、将生成的新树再次放入节点列表中，重复第一步，直到列表中只存在一个结点
//

// 哈夫曼编码：
// 每一个码元的熵就是哈夫曼树中的权值
// 而熵（权值）越大，路径也就越长
// 确保使用了字符集中不同字符的编码的同时，确保了每个字符都有其特定的更加合理的概率
//

// 哈夫曼树构建：
//	需要的几个函数：
//		1、使用指定权值的结点生成哈夫曼树
//		2、遍历哈夫曼树
//		3、取节点序列中最小的两个节点
//		4、考虑树的存储结构（顺序表）
//

typedef struct Huffman_Tree Huffman_Tree;

typedef struct TreeNode {
	int weight;
	int parent;
	int Lchild;
	int Rchild;
}TreeNode;

struct Huffman_Tree {
	TreeNode* data;
	int length;
};

Huffman_Tree* Huffman_TreeInit(int* weight,int length);	// weight是权值列表（数组），length是长度

void select_minweight(Huffman_Tree* HFTree);	// 选取最小权值的两个结点