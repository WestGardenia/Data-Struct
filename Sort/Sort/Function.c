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