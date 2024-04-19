#define _CRT_SECURE_NO_WARNINGS
#include"Tree.h"

void test_01()
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

int main()
{
	test_01();
	return 0;
}