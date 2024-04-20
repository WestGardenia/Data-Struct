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
	Queue* q;
	TreeNode* pTree;
	int index = 0;
	char* data = "abd##e##cf##g##";

	Create_Queue(&q);
	TreeCreative(&pTree,data,&index);

	printf("���������");
	preOrder(pTree);
	printf("��������ɹ�\n");

	LevelTraverse(q, pTree);

	 
}

int main()
{
	// test_01();
	test_02();
	return 0;
}