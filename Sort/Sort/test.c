#define _CRT_SECURE_NO_WARNINGS

#include"Sort.h"

void test_01()
{
	int arr[8] = { 18,15,2,61,56,5,468,1 };
	printf("ԭʼ���У�");
	PrintArray(arr, 8);
	printf("Quick_Sort�м���̣�\n");
	Quick_Sort(arr, 0, 7);
	printf("Quick_Sort�������\n");
	PrintArray(arr, 8);
}


int main()
{
	test_01();
	return 0;
}