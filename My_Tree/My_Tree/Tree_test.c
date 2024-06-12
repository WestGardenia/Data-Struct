#define _CRT_SECURE_NO_WARNINGS

#include"Tree_Function.h"

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

int main()
{
	//test_01();
	test_02();
	return 0;
}