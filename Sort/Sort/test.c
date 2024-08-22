#define _CRT_SECURE_NO_WARNINGS

#include"Sort.h"

// 快速排序测试用例
static void test_01()
{
	int arr[8] = { 18,15,2,61,56,5,468,1 };
	printf("原始序列：");
	PrintArray(arr, 8);
	printf("Quick_Sort中间过程：\n");
	Quick_Sort(arr, 0, 7);
	printf("Quick_Sort最后结果：\n");
	PrintArray(arr, 8);
}

// 插入排序测试用例
static void test_02()
{
	int arr[6] = { 4,3,5,1,9,6 };

	Insert_Sort(arr, 6);

}


// 希尔排序测试用例
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