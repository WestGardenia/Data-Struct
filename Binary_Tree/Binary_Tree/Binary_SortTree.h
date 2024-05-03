#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

// 二叉排序树----BST（Binary Sort Tree）
// 一棵树的左子树上的所有结点的值都比根节点小；右子树上的所有结点的值都比根节点的值大；
// 同时，这个性质对于这棵树的所有子树都成立（递归性质）

// 构建BST：
// 对于这样一个数据：4、5、19、23、2、8
// 以4为根结点构建，然后将剩下的数字与4比较
//		5比4大：5作为4的右孩子
//		19比4大，同时比5大：19作为5的右孩子
//		23比4、5、19都大：23作为19的右孩子
//		2比4小：2作为4的左孩子
//		……
//		以此类推
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

void BST_Insert(BST** RootNode, int data);	// 创建二叉排序树结点

BST* BST_Search(BST* RootNode, int key);	// 在二叉排序树中查找值

void PreOrder_BST(BST* RootNode);	// 前序遍历


// AVL树是最先发明的自平衡二叉查找树。在AVL树中任何节点的两个儿子子树的高度最大差别为一，所以它也被称为高度平衡树。
// AVL树（自平衡二叉查找树）是一种合理的二叉排序树
// 所谓合理，就是指能够用更高的效率去查找一颗树中的值
// 比如，对于这样一个数组：1、2、3、4、5
// 普通二叉查找树：
//		1
//			2
//				3
//					4
//						5
// 自平衡二叉查找树：
//			3
//		2		4
//	1				5
// 显然，对于两棵树同样查找一个数 5 时，自平衡二叉树的效率更高
// 这种自平衡，就代表这棵二叉树的左右子树的高度差不超过 1
//
// 
// 1、构建一棵自平衡二叉排序树，本质上就是构建一棵普通二叉排序树
// 2、在构建过程中，如果发现树的高度差不符合特性（左右子树高度差不超过1），就需要进行调整
//		有四种情况：LL	RR	RL	 LR
// 3、判断调整类型（LL	RR	RL	 LR）
//		找到失衡树的根节点root
//		找到导致树失衡的结点node
//			判断node在root的哪一侧
//			判断node在root孩子的哪一侧
// 
// 
// 数组：1、2、3、4、5
// 构建树时：
// // 普通二叉查找树：
//		1
//			2
//				3
// 插入3后，此时，树已失衡
//		root是1
//		node是3（node结点插入，导致原本符合条件的树左右子树高度差超过了1，即发生失衡）
// 对于这种情况：
//				node在root的右侧--R
//				node在root孩子的右侧--R
//		此时调整类型是RR
// 
// RR调整手段
//	RR：取中间节点mid_node，将mid_node的父亲节点作为它的左孩子。
//		如果mid_node原本就有左孩子，那么将这个左孩子存放到mid_node原本父亲节点的右孩子中去
//		如果树和它的一棵子树同时失衡，那么优先处理子树部分。树有递归性质，子树在平衡后，才能保证树的平衡
// 
//	1					调整				3					
//		3			---------->			1		4
//	  2		4							  2
//		parent->rchild = node->lchild	---- 转移孩子
//		node->lchild = parent			---- 父亲节点连在孩子左节点上
//		RootNode = node				---- 根结点变更
//
// 
// 
// 数组：5、4、3、2、1
// 构建树时：
//	普通二叉查找树：
//				5
//			4
//		3
// 插入3后，此时，树已失衡
//		root是5
//		node是3（node结点插入，导致原本符合条件的树左右子树高度差超过了1，即发生失衡）
// 对于这种情况：
//				node在root的左侧--L
//				node在root孩子的左侧--L
//		此时调整类型是LL 
// 
// LL调整手段：
//	LL：取中间结点mid_node，将mid_node的父亲节点作为它的右孩子。
//		如果mid_node有右孩子，那么将这个右孩子节点链接到父亲节点的左孩子上
//		
//					5
//				4							4						4
//			3			------->		3		5	----->		2		5
//		2							2						1	  3	
//	1							1	
//		parent->lchild = node->rchild
//		node->rchild = root
// 
// 
// 数组：8、7、9、5、6
// 普通二叉树：
//			8
//		7		9
//	5
//	  6
// 插入6后，
//		root是7
//		node是6
//		node在root的左侧		----L
//		node在root的孩子的右侧	----R
//	调整类型是LR
// 
// LR调整手段：
//		取node（最后一个节点）作为父亲节点
//		将node的父亲作为这个节点的左孩子
//		将父亲的父亲作为这个节点的右孩子
//		如果它有左孩子或者右孩子的话
//				原本的左孩子链接到父亲的右孩子上
//				原本的右孩子链接到父亲的父亲的左孩子上
// 
//			10											10
//		9		11								7				11
//	5							---->		5		9
//	   7								     6     8		
//	  6 8
// 6和8作为7的左右孩子						6作为5的右孩子 / 8作为9的左孩子 
// 
// parent->rchild = node->lchild
// parent->parent->lchild = node->rchild
// node->rchild = parent->parent
// node->lchild = parent
// 
// 
// 数组：1、8、6、7、5
// 普通二叉树：
//			1
//				8
//			 6		
//		   5   7
//		root是1
//		node是6
//		node在root的右侧		----R
//		node在root孩子的左侧	----L
//		调整类型为RL
// 
// RL调整方式：
//		取node（最后一个节点）作为父亲节点
//		将node原先的父亲节点作为node的右孩子
//		将原先父亲的父亲结点作为node的左孩子
//		如果node原先有左右孩子
//				原先的左孩子子链接到父亲的父亲节点的右孩子
//				原先的右孩子链接到父亲的左孩子上
// 
// 		1									    6
//				8		   ---->			1		8	
//			6							     5    7
//		  5   7
//	5和7是6（node）的左右孩子			5作为1（父亲的父亲）的右孩子，7作为8（父亲）的左孩子

// 
// 建立平衡二叉树的过程就是建立一棵二叉排序树的过程
// 由于自平衡二叉排序树有高度差限定，所以结点的结构体中需要加入一个字段表示当前树的高度
// 确定调整方法
//

typedef struct AVL_Tree AVL_Tree;

struct AVL_Tree {
	int val;
	int height;
	AVL_Tree* Lchild;
	AVL_Tree* Rchild;
	AVL_Tree* parent;
};

int GetHeight(AVL_Tree* RootNode);	// 取当前结点的高度

void LL_Rotation(AVL_Tree** RootNode, AVL_Tree* node);	// LL调整函数

void RR_Rotation(AVL_Tree** RootNode, AVL_Tree* node);	// RR调整函数

//void LR_Rotation(AVL_Tree** RootNode, AVL_Tree* node);	// LR调整函数
//void RL_Rotation(AVL_Tree** RootNode, AVL_Tree* node);	// RL调整函数
// 本质上，LR就是先进行一次RR调整，再进行一次LL调整
//		   RR调整则是和LR调整逻辑相反 

void AVL_Insert(AVL_Tree** RootNode, int data);		// 创建AVL树

void AVL_PreOrder(AVL_Tree* RootNode);	// AVL先序遍历
