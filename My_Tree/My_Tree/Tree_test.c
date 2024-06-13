#define _CRT_SECURE_NO_WARNINGS

#include"Tree_Function.h"

// 先、中、后序遍历测试代码
static void test_01()	
{
	TreeNode* RootNode = NULL;
	char* val = "abd##e##cf##g##";
	int index = 0;
	Create_BinaryTree(&RootNode, val, &index);

	PreOrder(RootNode);
	printf("\n");
	InOrder(RootNode);
	printf("\n");
	PostOrder(RootNode);
	printf("\n");
}

// 层次遍历测试代码
static void test_02()	
{
	TreeNode* RootNode = NULL;
	char* val = "abd##e##cf##g##";
	int index = 0;
	Create_BinaryTree(&RootNode, val, &index);

	PreOrder(RootNode);
	printf("\n");

	BinaryTree_LevelOrder(RootNode);
}

// 线索二叉树测试代码
// 1、二叉树线索化
// 2、线索二叉树查找前驱和后继
static void test_03()	
{
	TreeNode* RootNode_in = NULL;
	char* val_in = "abd##e##cf##g##";
	int index_in = 0;
	Create_BinaryTree(&RootNode_in, val_in, &index_in);

	InOrder(RootNode_in);
	printf("\n");

	TreeNode* pre_in = NULL;
	InOrder_Thread(RootNode_in, &pre_in);
	printf("\n");

	TreeNode* RootNode_pre = NULL;
	char* val_pre = "abd##e##cf##g##";
	int index_pre = 0;
	Create_BinaryTree(&RootNode_pre, val_pre, &index_pre);

	TreeNode* pre_pre = NULL;
	PreOrder_Thread(RootNode_pre, &pre_pre);
	printf("\n");

	TreeNode* RootNode_post = NULL;
	char* val_post = "abd##e##cf##g##";
	int index_post = 0;
	Create_BinaryTree(&RootNode_post, val_post, &index_post);

	TreeNode* pre_post = NULL;
	PostOrder_Thread(RootNode_post, &pre_post);
	printf("\n");
}

int main()
{
	//test_01();
	//test_02();
	test_03();
	return 0;
}