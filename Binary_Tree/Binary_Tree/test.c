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

	//QueueDestroy(q);
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

static void test_04()
{
	Thread_TreeNode* pTree;
	Thread_TreeNode* parent = NULL;
	int index = 0;
	char* data = "ABD##E##CF##G##";
	Thread_TreeNode* pre = NULL;


	// 创建线索二叉树
	Thread_TreeCreative(&pTree, data, &index, parent);
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

static void test_05()
{
	// 先序遍历线索二叉树
	Thread_TreeNode* pTree;
	Thread_TreeNode* parent = NULL;
	int index = 0;
	char* data = "ABD##E##CF##G##";
	Thread_TreeNode* pre = NULL;


	// 创建线索二叉树
	Thread_TreeCreative(&pTree, data, &index, parent);
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

static void test_06()
{
	// 后序遍历线索二叉树
	Thread_TreeNode* pTree;
	Thread_TreeNode* parent = NULL;
	int index = 0;
	char* data = "ABD##E##CF##G##";
	Thread_TreeNode* pre = NULL;


	// 创建线索二叉树
	Thread_TreeCreative(&pTree, data, &index, parent);
	// 线索二叉树——后序遍历
	PostThread_Tree(pTree, &pre);
	//pre->RFlag = 1;
	//pre->RChild = NULL;


	// 后序遍历线索二叉树
	Thread_TreeNode* cur_post = NULL;

	cur_post = Post_GetFirst(pTree);
	printf("先序遍历下线索二叉树的头结点（根结点）是：%c\n", cur_post->data);

	printf("先序遍历——线索二叉树：");
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
	printf("搜索值为：%d\n", Search_Node->val);

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