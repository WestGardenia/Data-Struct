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

	printf("ÏÈĞò±éÀú£º");
	preOrder(pTree);
	printf("ÏÈĞò±éÀú³É¹¦\n");

	printf("ÖĞĞò±éÀú£º");
	inOrder(pTree);
	printf("ÖĞĞò±éÀú³É¹¦\n");

	printf("ºóĞò±éÀú£º");
	postOrder(pTree);
	printf("ºóĞò±éÀú³É¹¦\n");
}

static void test_02()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	TreeNode* pTree;
	int index = 0;
	char* data = "abd##e##cf##g##";

	QueueInit(q);
	TreeCreative(&pTree,data,&index);

	printf("ÏÈĞò±éÀú£º");
	preOrder(pTree);
	printf("ÏÈĞò±éÀú³É¹¦\n");

	LevelTraverse(q, pTree);
	printf("²ã´Î±éÀú³É¹¦£¡£¡£¡\n");

	QueueDestroy(q);
}

static void test_03()
{
	TreeNode* pTree;
	int index = 0;
	char* data = "ABD##E##CF##G##";

	TreeCreative(&pTree, data, &index);
	printf("Create Tree Successfully!!\n");

	printf("ÏÈĞò±éÀú£º");
	PreOrder_1(pTree);
	printf("ÏÈĞò±éÀú³É¹¦\n");

	printf("ÖĞĞò±éÀú£º");
	InOrder_1(pTree);
	printf("ÖĞĞò±éÀú³É¹¦\n");

	printf("ºóĞò±éÀú£º");
	PostOrder_1(pTree);
	printf("ºóĞò±éÀú³É¹¦\n");
}

void test_04()
{
	Thread_TreeNode* pTree;
	int index = 0;
	char* data = "D##BEA##F##CG##";
	Thread_TreeNode* pre = NULL;


	// ´´½¨ÏßË÷¶ş²æÊ÷
	Thread_TreeCreative(&pTree, data, &index);
	// ÏßË÷¶ş²æÊ÷¡ª¡ªÖĞĞò±éÀú
	InThread_Tree(pTree, &pre);

	pre->RFlag = 1;
	pre->RChild = NULL;

	Thread_TreeNode* cur = NULL;

	cur = GetFirst(pTree);
	printf("ÖĞĞò±éÀúÏÂÏßË÷¶ş²æÊ÷µÄÍ·½áµã£¨×î×ó±ßµÄº¢×Ó½Úµã£©£º%c\n", cur->data);
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