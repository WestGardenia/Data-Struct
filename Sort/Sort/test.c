#define _CRT_SECURE_NO_WARNINGS

#include"Sort.h"


// ���������Բ�ͬ�����㷨ʱ��Ч��
static void TestOP()
{
	srand(time(0));
	const int N = 1000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}

	int begin1 = clock();
	Insert_Sort(a1, N);
	int end1 = clock();	

	int begin2 = clock();
	Shell_Sort_01(a2, N);
	int end2 = clock();

	int begin3 = clock();
	Select_Sort(a3, N);
	int end3 = clock();
		
	int begin4 = clock();
	Heap_Sort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	Bubble_Sort(a5, N);
	int end5 = clock();

	int begin6 = clock();
	Quick_Sort_01(a5, 0, N - 1);
	int end6 = clock();
	
	int begin7 = clock();
	Quick_Sort_02(a5, 0, N - 1);
	int end7 = clock();


	printf("ֱ�Ӳ�������ʱ������%d\n", end1 - begin1);
	printf("ϣ������ʱ������%d\n", end2 - begin2);
	printf("ֱ��ѡ������ʱ������%d\n", end3 - begin3);
	printf("������ʱ������%d\n", end4 - begin4);
	printf("ð������ʱ������%d\n", end5 - begin5);
	printf("�������򣨵ݹ�汾��ʱ������%d\n", end6 - begin6);
	printf("�������򣨷ǵݹ�汾��ʱ������%d\n", end7 - begin7);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);

}

// ���������������
static void test_01()
{
	int arr[8] = { 18,15,2,61,56,5,468,8 };
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
	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };

	int step[3] = { 5,3,1 };
	for (int i = 0; i < 3; i++)
	{
		Shell_Sort(arr, 10, step[i]);
		PrintArray(arr, 10);
	}

	Shell_Sort_01(arr, 10);
	PrintArray(arr, 10);
}

// ѡ���������
static void test_04()
{
	int arr[6] = { 4,3,5,1,9,6 };

	Select_Sort(arr, 6);
	PrintArray(arr, 6);
}

// ���������������
static void test_05()
{
	int arr[6] = { 4,3,5,1,9,6 };

	Heap_Sort(arr, 6);
	PrintArray(arr, 6);
}

// ð�������������
static void test_06()
{
	int arr[6] = { 4,3,5,1,9,6 };

	Bubble_Sort(arr, 6);
	PrintArray(arr, 6);
}

// ���������������
static void test_07()
{
	int arr[6] = { 4,3,5,1,9,6 }; 
	PrintArray(arr, 6);
	Quick_Sort_02(arr, 0, sizeof(arr)/sizeof(int)-1);
	PrintArray(arr, 6);
}

int main()
{
	TestOP();
	// test_01();
	// test_02();
	// test_03();
	// test_04();
	// test_05();
	// test_06();
	//test_07();
	return 0;
}