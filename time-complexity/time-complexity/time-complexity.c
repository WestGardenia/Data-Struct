#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
////有一种数组，里面有一些数字会重复出现。编写一个函数，将重复出现的数字删除
////思路一：暴力求解：将数组遍历，将每个数字和value比较，如果有相同值，就将其覆盖
////对于这种暴力求解，时间复杂度是O(N^2),由于遍历完数组之后，还要对数组进行整体的移动覆盖value的值，所以其运算效率是十分低下的
//void removeelement1(int* str, int size, int value)
//{
//	int count = 0;
//	for (int i = 0; i < (size-count);)
//	{
//		if (str[i] == value)
//		{
//			count++;
//			for (int j = i; j < (size-count); j++)
//			{
//				str[j] = str[j + 1];
//			}
//		}
//		else
//			i++;
//	}
//	for (int i = 0; i < size - count; i++)
//	{
//		printf("%d ", str[i]);
//	}
//	printf("\n");
//}
//
////思路二：开辟一个新的临时空间，将遍历得到不等于value的值全部放入这个临时空间中去，最后将这个空间返回
////显然这种方法，开辟新的临时空间，可以将时间复杂度降低到O(N).
////但是，这是一种空间换时间的方法，需要多余的空间。
//void removeelement2(int* str, int size, int value)
//{
//	int destination[10] = { 0 }; int j = 0; int count = 0;
//	for (int i = 0; i < size; i++)
//	{
//		if (str[i] != value)
//		{
//			destination[j] = str[i];
//			j++;
//			count++;
//		}
//	}
//	for (j = 0; j < count;j++)
//	{
//		printf("%d ", destination[j]);
//	}
//	printf("\n");
//}
//
////思路三：利用双指针求解。将不等于value的值拷贝到另一个指针中，然后将这个指针作为新的数组
//// 这种方法只需要将数组遍历一次，变例的同时就可以完成指针值的拷贝。时间复杂度是O(1),同时也不需要开辟临时空间
//void removeelement3(int* str, int size, int value)
//{
//	int* num = str; int j = 0; int count = 0;
//	for (int i = 0; i < size; i++)
//	{
//		if (*(str + i) != value)
//		{
//			*(num + j) = *(str + i);
//			j++; count++;
//		}
//	}
//	for (j = 0; j < count; j++)
//	{
//		printf("%d ", num[j]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[8] = { 1,2,3,3,4,5,3,6 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	//removeelement1(arr,size,3);
//	removeelement2(arr,size,3);
//	//removeelement3(arr,size,3);
//	return 0;
//}


//对有序数组进行去重操作
//和上面的去重类似，这里也有不同的解法。但是这些解法大多效率较低。这里采用多指针快慢移动的方法，进行优化解题
//int RemoveDuplicates(int* str, int size)
//{
//	int num1 = 0, num2 = 0;
//	int destination = 0;
//	while (num2 < size)
//	{
//		if (str[num1] == str[num2])
//		{
//			num2++;
//		}
//		else
//		{
//			str[destination++] = str[num1];
//			num1 = num2;
//			num2++;
//		}
//	}
//	str[destination++] = str[num1];//当数组最后一个不是重复值时，需要将这个数也拷贝到目标空间中，以免漏掉
//	return destination;
//}
//int main()
//{
//	int arr[10] = { 1,1,2,2,3,4,5,5,6,7 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	int newsize = RemoveDuplicates(arr, size);
//	for (int i = 0; i < newsize; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//合并两个有序数组，合并成一个新的有序数组
//思路：
//将两个数组的最后一个非0元素进行比较，将两数较大值放入数组arr1的最后一位中
//注意：当arr1数组的搜索指针到头时，需要继续将arr2的搜索指针继续搜索遍历，否则会出现不能完全排序成功的情况
//void merge(int* num1, int* num2, int size1, int size2)
//{
//	int end1 = size1 - size2 - 1; int end2 = size2 - 1;
//	int end = size1 - 1;
//	while (end1 >= 0 && end2 >= 0)
//	{
//		if (num1[end1] < num2[end2])
//		{
//			num1[end--] = num2[end2--];
//		}
//		else
//		{
//			num1[end--] = num1[end1--];
//		}
//	}
//	while (end2 >= 0)
//	{
//		num1[end--] = num2[end2--];
//	}
//
//}
//int main()
//{
//	int arr1[6] = { 1,4,5,0,0,0 };
//	int arr2[3] = { 2,3,6 };
//	int size1 = sizeof(arr1) / sizeof(arr1[0]);
//	int size2 = sizeof(arr2) / sizeof(arr2[0]);
//	merge(arr1, arr2, size1, size2);
//	for (int i = 0; i < size1; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}