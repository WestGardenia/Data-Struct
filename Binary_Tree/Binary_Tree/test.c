#define _CRT_SECURE_NO_WARNINGS
#include"Tree.h"

static void test_01()
{
	TreeNode* pTree;
	int index = 0;
	char* data = "abd##e##cf##g##";

	TreeCreative(&pTree,data,&index);
	printf("Create Tree Successfully!!\n");

	printf("先序遍历：");
	preOrder(pTree);
	printf("先序遍历成功\n");

	printf("中序遍历：");
	inOrder(pTree);
	printf("中序遍历成功\n");

	printf("后序遍历：");
	postOrder(pTree);
	printf("后序遍历成功\n");
}

static void test_02()
{
	Queue* q;
	TreeNode* pTree;
	int index = 0;
	char* data = "abd##e##cf##g##";

	Create_Queue(&q);
	TreeCreative(&pTree,data,&index);

	printf("先序遍历：");
	preOrder(pTree);
	printf("先序遍历成功\n");

	LevelTraverse(q, pTree);

	 
}

int main()
{
	// test_01();
	test_02();
	return 0;
}