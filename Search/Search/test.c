#define _CRT_SECURE_NO_WARNINGS

#include"BST_Function.h"
#include"AVL_Tree.h"
#include"Red_Black_Tree.h"
// 二叉排序树 BST 测试用例
void test_01()
{
	BST* T = NULL;
	int arr[6] = { 4,5,3,74,1,87 };

	BST_Creat(&T, arr, 6);
	
	BST_InOrder(T);
	printf("\n");

	BST_Search(T, 4);

	T = BST_Delete(T, 74);

	BST_InOrder(T);
	printf("\n");
}

// 二叉平衡树 AVL 测试用例
void test_02()
{
	AVLnode* T = NULL;
	printf("平衡二叉树测试用例\n");
	int arr[5] = { 1,2,3,4,5 };

	for (int i = 0; i < 5; i++)
	{
		AVL_Tree_Insert(&T, arr[i]);
	}

	printf("中序遍历的结果是：\n");
	AVL_Tree_InOrder(T);
	printf("\n");
	printf("先序遍历的结果是：\n");
	AVL_Tree_PreOrder(T);
}

// 红黑树 RBT 测试用例
void test_03()
{

}

int main()
{
	//test_01();
	test_02();
	return 0;
}