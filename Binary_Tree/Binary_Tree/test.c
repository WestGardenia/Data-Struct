#define _CRT_SECURE_NO_WARNINGS
#include"Tree.h"

static void test_01()
{
	TreeNode* pTree;
	int index = 0;
	char* data = "abd##e##cf##g##";

	TreeCreative(&pTree,data,&index);
	printf("Create Tree Successfully!!\n");

	printf("���������");
	preOrder(pTree);
	printf("��������ɹ�\n");

	printf("���������");
	inOrder(pTree);
	printf("��������ɹ�\n");

	printf("���������");
	postOrder(pTree);
	printf("��������ɹ�\n");
}

static void test_02()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	TreeNode* pTree;
	int index = 0;
	char* data = "abd##e##cf##g##";

	QueueInit(q);
	TreeCreative(&pTree,data,&index);

	printf("���������");
	preOrder(pTree);
	printf("��������ɹ�\n");

	LevelTraverse(q, pTree);
	printf("��α����ɹ�������\n");

	QueueDestroy(q);
}

static void test_03()
{
	TreeNode* pTree;
	int index = 0;
	char* data = "ABD##E##CF##G##";

	TreeCreative(&pTree, data, &index);
	printf("Create Tree Successfully!!\n");

	printf("���������");
	PreOrder_1(pTree);
	printf("��������ɹ�\n");

	printf("���������");
	InOrder_1(pTree);
	printf("��������ɹ�\n");

	printf("���������");
	PostOrder_1(pTree);
	printf("��������ɹ�\n");
}

int main()
{
	// test_01();
	// test_02();
	test_03();
	return 0;
}