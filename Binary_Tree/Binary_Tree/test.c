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

	printf("递归遍历——先序遍历：");
	preOrder(pTree);
	printf("递归遍历——先序遍历成功\n");

	printf("递归遍历——中序遍历：");
	inOrder(pTree);
	printf("递归遍历——中序遍历成功\n");

	printf("递归遍历——后序遍历：");
	postOrder(pTree);
	printf("递归遍历——后序遍历成功\n");
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

	printf("非递归遍历——先序遍历：");
	PreOrder_1(pTree);
	printf("非递归遍历——先序遍历成功\n");

	printf("非递归遍历——中序遍历：");
	InOrder_1(pTree);
	printf("非递归遍历——中序遍历成功\n");

	printf("非递归遍历——后序遍历：");
	PostOrder_1(pTree);
	printf("非递归遍历——后序遍历成功\n");
}

void test_04()
{
	Thread_TreeNode* pTree;
	int index = 0;
	char* data = "ABD##E##CF##G##";
	Thread_TreeNode* pre = NULL;


	// 创建线索二叉树
	Thread_TreeCreative(&pTree, data, &index);
	// 线索二叉树——中序遍历
	InThread_Tree(pTree, &pre);

	pre->RFlag = 1;
	pre->RChild = NULL;

	// 中序遍历线索二叉树
	Thread_TreeNode* cur_in = NULL;

	cur_in = In_GetFirst(pTree);
	printf("中序遍历下线索二叉树的头结点（最左边的孩子节点）：%c\n", cur_in->data);
	printf("test sucess\n");

	cur_in = In_GetNext(pTree);
	printf("中序遍历下线索二叉树头结点（D）的下一个节点：%c\n", cur_in->data);

	printf("中序遍历——线索二叉树：");
	for (Thread_TreeNode* node = In_GetFirst(pTree); node != NULL; node = In_GetNext(node))
	{
		printf("%c->", node->data);
	}
	printf("\n");
}

void test_05()
{
	// 先序遍历线索二叉树
	Thread_TreeNode* pTree;
	int index = 0;
	char* data = "ABD##E##CF##G##";
	Thread_TreeNode* pre = NULL;


	// 创建线索二叉树
	Thread_TreeCreative(&pTree, data, &index);
	// 线索二叉树——先序遍历
	PreThread_Tree(pTree, &pre);

	pre->RFlag = 1;
	pre->RChild = NULL;

	// 先序遍历线索二叉树
	Thread_TreeNode* cur_pre = NULL;

	cur_pre = pTree;
	printf("先序遍历下线索二叉树的头结点（根结点）是：%c\n", cur_pre->data);

	printf("先序遍历——线索二叉树：");
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