#define _CRT_SECURE_NO_WARNINGS
#include"Tree.h"

void test_01()
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

int main()
{
	test_01();
	return 0;
}