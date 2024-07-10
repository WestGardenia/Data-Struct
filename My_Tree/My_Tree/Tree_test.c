#define _CRT_SECURE_NO_WARNINGS

#include"Tree_Function.h"

// 先、中、后序遍历测试代码
static void test_01()	
{
	TreeNode* RootNode = NULL;
	TreeNode* parent = NULL;
	char* val = "abd##e##cf##g##";
	int index = 0;
	Create_BinaryTree(&RootNode, val, &index, parent);

	PreOrder(RootNode);
	printf("\n");
	InOrder(RootNode);
	printf("\n");
	PostOrder(RootNode);
	printf("\n");
}

// 层次遍历测试代码
static void test_02()	
{
	TreeNode* RootNode = NULL;
	char* val = "abd##e##cf##g##";
	TreeNode* parent = NULL;
	int index = 0;
	Create_BinaryTree(&RootNode, val, &index, parent);

	PreOrder(RootNode);
	printf("\n");

	BinaryTree_LevelOrder(RootNode);
}

// 线索二叉树测试代码
// 1、二叉树线索化
// 2、线索二叉树查找前驱和后继

static void test_03()	
{
	TreeNode* RootNode_in = NULL;
	TreeNode* parent = NULL;
	char* val_in = "abd##e##cf##g##";
	int index_in = 0;
	Create_BinaryTree(&RootNode_in, val_in, &index_in, parent);

	InOrder(RootNode_in);
	printf("\n");

	TreeNode* pre_in = NULL;
	InOrder_Thread(RootNode_in, &pre_in);
	printf("\n");

	printf("寻找中序线索二叉树的首个节点：%c \n", First_InOrder(RootNode_in)->data);
	printf("寻找中序线索二叉树的尾部节点：%c \n", Last_InOrder(RootNode_in)->data);

	printf("中序线索二叉树遍历测试：");
	InOrder_ThreadTree(RootNode_in);

	printf("\n");

	printf("中序线索二叉树逆遍历测试：");
	InOrder_ThreadTree_Rev(RootNode_in);

}

static void test_04()
{
	TreeNode* RootNode_pre = NULL;
	TreeNode* parent = NULL;
	char* val_pre = "abd##e##cf##g##";
	int index_pre = 0;
	Create_BinaryTree(&RootNode_pre, val_pre, &index_pre, parent);

	TreeNode* pre_pre = NULL;
	PreOrder_Thread(RootNode_pre, &pre_pre);
	printf("\n");

	printf("寻找先序线索二叉树的首个节点：%c \n", First_PreOrder(RootNode_pre)->data);
	printf("寻找先序线索二叉树的尾部节点：%c \n", Last_PreOrder(RootNode_pre)->data);

	printf("先序线索二叉树遍历测试：");
	PreOrder_ThreadTree(RootNode_pre);

	printf("\n");

	printf("先序线索二叉树逆遍历测试：");
	PreOrder_ThreadTree_Rev(RootNode_pre);
}

static void test_05()
{
	// d e b f g c a
	TreeNode* RootNode_post = NULL;
	TreeNode* parent = NULL;
	char* val_post = "abd##e##cf##g##";
	int index_post = 0;
	Create_BinaryTree(&RootNode_post, val_post, &index_post,parent);

	TreeNode* pre_post = NULL;
	PostOrder_Thread(RootNode_post, &pre_post);
	printf("\n");

	printf("寻找后序线索二叉树的首个节点：%c \n", First_PostOrder(RootNode_post)->data);
	printf("寻找后序线索二叉树的尾部节点：%c \n", Last_PostOrder(RootNode_post)->data);


	printf("后序线索二叉树遍历测试：");
	PostOrder_ThreadTree(RootNode_post);

	printf("\n");

	printf("后序线索二叉树逆遍历测试：");
	PostOrder_ThreadTree_Rev(RootNode_post);
}



int main()
{
	//test_01();
	//test_02();
	//test_03();
	//test_04();
	test_05();
	return 0;
}