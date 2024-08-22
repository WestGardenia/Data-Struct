#define _CRT_SECURE_NO_WARNINGS



#include"BST_Function.h"
#include"AVL_Tree.h"
#include"Red_Black_Tree.h"
#include"Hash_Table.h"
// ���������� BST ��������
static void test_01()
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

// ����ƽ���� AVL ��������
static void test_02()
{
	AVLnode* T = NULL;
	printf("ƽ���������������\n");
	int arr[5] = { 1,2,3,4,5 };

	for (int i = 0; i < 5; i++)
	{
		AVL_Tree_Insert(&T, arr[i]);
	}

	printf("��������Ľ���ǣ�\n");
	AVL_Tree_InOrder(T);
	printf("\n");
	printf("��������Ľ���ǣ�\n");
	AVL_Tree_PreOrder(T);
	printf("\n");
}

// ��ϣ�� Hash ��������
void test_03()
{
	Hash* H = Hash_Init();
	put(H, 'A');
	put(H, 'F');
	printf("��ϣ�����������\n");
	printf("��ϣ���һ��Ԫ��ֵ��%c\n", H->data[0]);
	printf("��ϣ��ڶ���Ԫ��ֵ��%c\n", H->data[1]);
}

int main()
{
	//test_01();
	test_02();
	test_03();
	return 0;
}