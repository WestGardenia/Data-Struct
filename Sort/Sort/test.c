#define _CRT_SECURE_NO_WARNINGS

#include"Sort.h"

// ���������������
static void test_01()
{
	int arr[8] = { 18,15,2,61,56,5,468,1 };
	printf("ԭʼ���У�");
	PrintArray(arr, 8);
	printf("Quick_Sort�м���̣�\n");
	Quick_Sort(arr, 0, 7);
	printf("Quick_Sort�������\n");
	PrintArray(arr, 8);
}

// ���������������
static void test_02()
{
	int arr[6] = { 4,3,5,1,9,6 };

	Insert_Sort(arr, 6);

}


// ϣ�������������
static void test_03()
{
	int arr[10] = { 49,38,65,97,76,13,27,49,55,4 };

	int step[3] = { 5,3,1 };
	for (int i = 0; i < 3; i++)
	{
		Shell_Sort(arr, 10, step[i]);
		Print_Sort(arr, 10);
	}
}

int main()
{
	// test_01();
	// test_02();
	test_03();
	return 0;
}