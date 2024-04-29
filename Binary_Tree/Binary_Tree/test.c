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

	printf("�ݹ�����������������");
	preOrder(pTree);
	printf("�ݹ����������������ɹ�\n");

	printf("�ݹ�����������������");
	inOrder(pTree);
	printf("�ݹ����������������ɹ�\n");

	printf("�ݹ�����������������");
	postOrder(pTree);
	printf("�ݹ����������������ɹ�\n");
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

	printf("�ǵݹ�����������������");
	PreOrder_1(pTree);
	printf("�ǵݹ����������������ɹ�\n");

	printf("�ǵݹ�����������������");
	InOrder_1(pTree);
	printf("�ǵݹ����������������ɹ�\n");

	printf("�ǵݹ�����������������");
	PostOrder_1(pTree);
	printf("�ǵݹ����������������ɹ�\n");
}

void test_04()
{
	Thread_TreeNode* pTree;
	int index = 0;
	char* data = "ABD##E##CF##G##";
	Thread_TreeNode* pre = NULL;


	// ��������������
	Thread_TreeCreative(&pTree, data, &index);
	// ���������������������
	InThread_Tree(pTree, &pre);

	pre->RFlag = 1;
	pre->RChild = NULL;

	// �����������������
	Thread_TreeNode* cur_in = NULL;

	cur_in = In_GetFirst(pTree);
	printf("���������������������ͷ��㣨����ߵĺ��ӽڵ㣩��%c\n", cur_in->data);
	printf("test sucess\n");

	cur_in = In_GetNext(pTree);
	printf("�������������������ͷ��㣨D������һ���ڵ㣺%c\n", cur_in->data);

	printf("�����������������������");
	for (Thread_TreeNode* node = In_GetFirst(pTree); node != NULL; node = In_GetNext(node))
	{
		printf("%c->", node->data);
	}
	printf("\n");
}

void test_05()
{
	// �����������������
	Thread_TreeNode* pTree;
	int index = 0;
	char* data = "ABD##E##CF##G##";
	Thread_TreeNode* pre = NULL;


	// ��������������
	Thread_TreeCreative(&pTree, data, &index);
	// ���������������������
	PreThread_Tree(pTree, &pre);

	pre->RFlag = 1;
	pre->RChild = NULL;

	// �����������������
	Thread_TreeNode* cur_pre = NULL;

	cur_pre = pTree;
	printf("���������������������ͷ��㣨����㣩�ǣ�%c\n", cur_pre->data);

	printf("�����������������������");
	for (Thread_TreeNode* node = cur_pre; node != NULL; node = Pre_GetNext(node))
	{
		printf("%c->", node->data);
	}
	printf("\n");

}

int main()
{
	// test_01();
	// test_02();
	// test_03();
	// test_04();
	test_05();
	return 0;
}