#define _CRT_SECURE_NO_WARNINGS
#include"Tree.h"
#include"Threaded_BinaryTree.h"

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
	Queue* q = (Queue*)malloc(sizeof(Queue));
	TreeNode* pTree;
	int index = 0;
	char* data = "abd##e##cf##g##";

	QueueInit(q);
	TreeCreative(&pTree,data,&index);

	printf("先序遍历：");
	preOrder(pTree);
	printf("先序遍历成功\n");

	LevelTraverse(q, pTree);
	printf("层次遍历成功！！！\n");

	QueueDestroy(q);
}

static void test_03()
{
	TreeNode* pTree;
	int index = 0;
	char* data = "ABD##E##CF##G##";

	TreeCreative(&pTree, data, &index);
	printf("Create Tree Successfully!!\n");

	printf("先序遍历：");
	PreOrder_1(pTree);
	printf("先序遍历成功\n");

	printf("中序遍历：");
	InOrder_1(pTree);
	printf("中序遍历成功\n");

	printf("后序遍历：");
	PostOrder_1(pTree);
	printf("后序遍历成功\n");
}

void test_04()
{
	Thread_TreeNode* pTree;
	int index = 0;
	char* data = "ABD##E##CF##G##";
	Thread_TreeNode* pre = NULL;
	pre->RFlag = 1;
	pre->RChild = NULL;

	Thread_TreeCreative(&pTree, data, &index);

}

int main()
{
	// test_01();
	// test_02();
	test_03();
	test_04();
	return 0;
}