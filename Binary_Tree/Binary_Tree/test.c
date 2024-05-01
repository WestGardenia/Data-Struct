#define _CRT_SECURE_NO_WARNINGS
#include"Tree.h"
#include"Threaded_BinaryTree.h"
#include"Binary_SortTree.h"

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

	//QueueDestroy(q);
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

static void test_04()
{
	Thread_TreeNode* pTree;
	Thread_TreeNode* parent = NULL;
	int index = 0;
	char* data = "ABD##E##CF##G##";
	Thread_TreeNode* pre = NULL;


	// ��������������
	Thread_TreeCreative(&pTree, data, &index, parent);
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

static void test_05()
{
	// �����������������
	Thread_TreeNode* pTree;
	Thread_TreeNode* parent = NULL;
	int index = 0;
	char* data = "ABD##E##CF##G##";
	Thread_TreeNode* pre = NULL;


	// ��������������
	Thread_TreeCreative(&pTree, data, &index, parent);
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

static void test_06()
{
	// �����������������
	Thread_TreeNode* pTree;
	Thread_TreeNode* parent = NULL;
	int index = 0;
	char* data = "ABD##E##CF##G##";
	Thread_TreeNode* pre = NULL;


	// ��������������
	Thread_TreeCreative(&pTree, data, &index, parent);
	// ���������������������
	PostThread_Tree(pTree, &pre);
	//pre->RFlag = 1;
	//pre->RChild = NULL;


	// �����������������
	Thread_TreeNode* cur_post = NULL;

	cur_post = Post_GetFirst(pTree);
	printf("���������������������ͷ��㣨����㣩�ǣ�%c\n", cur_post->data);

	printf("�����������������������");
	for (Thread_TreeNode* node = cur_post; node != NULL; node = Post_GetNext(node))
	{
		printf("%c->", node->data);
	}
	printf("\n");
}

static void test_07()
{
	BST* RootNode = NULL;
	int num[6] = { 8,6,10,9,11,23 };
	for (int i = 0; i < 6; i++)
	{
		BST_Insert(&RootNode, num[i]);
	}

	PreOrder_BST(RootNode);
	printf("\n");

	BST* Search_Node = BST_Search(RootNode, 11);
	printf("����ֵΪ��%d\n", Search_Node->val);

}

int main()
{
	//test_01();
	//test_02();
	//test_03();
	//test_04();
	//test_05();
	//test_06();
	test_07();
	return 0;
}