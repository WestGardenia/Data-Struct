#define _CRT_SECURE_NO_WARNINGS

#include"Tree_Function.h"
#include"Huffman_Tree_Function.h"
#include"heap.h"
#include"Leetcode_OJ.h"


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

	printf("结点计算：%d\n",Tree_size(RootNode));

	printf("深度计算：%d\n", Tree_depth(RootNode));
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

// 哈夫曼树编码与译码测试用例
#define N 6
static void test_06()
{
	int weight[N] = { 0 };
	int sum = N;
	printf("请输入%d个权值: ", sum);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &weight[i]);
	}
	printf("输入的权值数组是：");
	//for (int i = 0; i < N; i++)
	//{
	//	printf("%d ", weight[i]);
	//}

	//Sort(weight, N);
	//printf("升序排序后的权值数组是：");
	for (int i = 0; i < N; i++)
	{
		printf("%d ", weight[i]);
	}
	printf("\n");

	Huffman_Tree* HT = Huffman_TreeInit(weight, N);
	HT = Huffman_Treecreative(HT);
	printf("Huffman_Tree先序遍历结果：");
	Huffman_Tree_pre(HT, HT->length - 1);

}

// 并查集测试用例
static void test_07()
{

}

// 堆--测试用例
static void test_08()
{
	int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	heap hp;
	heap hp_01;
	Heap_Init(&hp, a, (sizeof(a) / sizeof(int)));

	printf("初始堆的遍历序列：\n");
	Heap_Print(&hp);

	Heap_Sort(&hp, (sizeof(a) / sizeof(int)));

	printf("\n进行的小堆排序的测试用例：\n");
	Heap_Print(&hp);

	Heap_Init(&hp_01, a, (sizeof(a) / sizeof(int)));

	Heap_Push(&hp_01, 13);
	printf("\n堆--插入数据测试用例：\n");
	Heap_Print(&hp_01);

	Heap_Pop(&hp_01);
	printf("\n堆--删除数据测试用例\n");
	Heap_Print(&hp_01);
}

// 接口函数测试用例
static void test_09()
{
	TreeNode* RootNode = NULL;
	TreeNode* parent = NULL;
	char* val = "abd##e##cf##g##";
	int index = 0;
	Create_BinaryTree(&RootNode, val, &index, parent);
	int k = 3;
	printf("第%d层结点个数：%d",k,Tree_Ksize(RootNode, k));


	Destory_Tree(RootNode);
}

int main()
{
	test_01();
	//test_02();
	//test_03();
	//test_04();
	//test_05();
	//test_06();
	//test_07();
	//test_08();
	test_09();
	return 0;
}