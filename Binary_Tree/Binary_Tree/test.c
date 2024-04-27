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

void test_04()
{
	Thread_TreeNode* pTree;
	int index = 0;
	char* data = "D##BEA##F##CG##";
	Thread_TreeNode* pre = NULL;


	// ��������������
	Thread_TreeCreative(&pTree, data, &index);
	// ���������������������
	InThread_Tree(pTree, &pre);

	pre->RFlag = 1;
	pre->RChild = NULL;

	Thread_TreeNode* cur = NULL;

	cur = GetFirst(pTree);
	printf("���������������������ͷ��㣨����ߵĺ��ӽڵ㣩��%c\n", cur->data);
	printf("test sucess\n");

	cur = GetNext(pTree);
	printf("%c\n", cur->data);

	for (Thread_TreeNode* node = GetFirst(pTree); node != NULL; node = GetNext(node))
	{
		printf("%c->", node->data);
	}

}

int main()
{
	// test_01();
	// test_02();
	// test_03();
	test_04();
	return 0;
}