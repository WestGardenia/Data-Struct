#define _CRT_SECURE_NO_WARNINGS
#include"Sort.h"

void PrintArray(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int Partition(int* arr, int front, int behind)
{
	int x = arr[front];
	while(front < behind)
	{
		while (front < behind && x <= arr[behind])
		{
			behind--;
		}
		if (front < behind)
		{
			arr[front] = arr[behind];
			front++;
		}
		while (front<behind && x>arr[front])
		{
			front++;
		}
		if (front < behind)
		{
			arr[behind] = arr[front];
			behind--;
		}
	}
	arr[front] = x;
	return front;
}

void Quick_Sort(int* arr, int front, int behind)
{
	if (front < behind)
	{
		int index = Partition(arr, front, behind);
		PrintArray(arr, 8);
		Quick_Sort(arr, front, index - 1);
		Quick_Sort(arr, index+1,behind);
	}
}

void Insert_Sort(int* arr, int length)	// 插入排序
{
	if (arr == NULL)
	{
		printf("传入数组为空，排序出错！！！\n");
		return;
	}
	for (int i = 1; i < length; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[i])
			{
				int temp = arr[i];
				for (int n = i-1; n >= j; n--)
				{
					arr[n + 1] = arr[n];
				}
				arr[j] = temp;
			}

		}
		Print_Sort(arr, length);
	}
}

void Shell_Sort(int* arr, int length, int step)	// 希尔排序
{
	for (int i = 0; i < length; i++)
	{
		for (int j = i + step; j < length; j += step)
		{
			for (int k = i; k < j; k += step)
			{
				if (arr[j] < arr[k])
				{
					int temp = arr[j];
					for (int l = j - step; l >= k; l -= step)
					{
						arr[l + step] = arr[l];
					}
					arr[k] = temp;
				}
			}
		}
	}
}

void Print_Sort(int* arr, int length)	// 打印函数
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}