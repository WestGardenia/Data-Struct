#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
////��һ�����飬������һЩ���ֻ��ظ����֡���дһ�����������ظ����ֵ�����ɾ��
////˼·һ��������⣺�������������ÿ�����ֺ�value�Ƚϣ��������ֵͬ���ͽ��串��
////�������ֱ�����⣬ʱ�临�Ӷ���O(N^2),���ڱ���������֮�󣬻�Ҫ���������������ƶ�����value��ֵ������������Ч����ʮ�ֵ��µ�
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
////˼·��������һ���µ���ʱ�ռ䣬�������õ�������value��ֵȫ�����������ʱ�ռ���ȥ���������ռ䷵��
////��Ȼ���ַ����������µ���ʱ�ռ䣬���Խ�ʱ�临�ӶȽ��͵�O(N).
////���ǣ�����һ�ֿռ任ʱ��ķ�������Ҫ����Ŀռ䡣
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
////˼·��������˫ָ����⡣��������value��ֵ��������һ��ָ���У�Ȼ�����ָ����Ϊ�µ�����
//// ���ַ���ֻ��Ҫ���������һ�Σ�������ͬʱ�Ϳ������ָ��ֵ�Ŀ�����ʱ�临�Ӷ���O(1),ͬʱҲ����Ҫ������ʱ�ռ�
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


//�������������ȥ�ز���
//�������ȥ�����ƣ�����Ҳ�в�ͬ�Ľⷨ��������Щ�ⷨ���Ч�ʽϵ͡�������ö�ָ������ƶ��ķ����������Ż�����
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
//	str[destination++] = str[num1];//���������һ�������ظ�ֵʱ����Ҫ�������Ҳ������Ŀ��ռ��У�����©��
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


//�ϲ������������飬�ϲ���һ���µ���������
//˼·��
//��������������һ����0Ԫ�ؽ��бȽϣ��������ϴ�ֵ��������arr1�����һλ��
//ע�⣺��arr1���������ָ�뵽ͷʱ����Ҫ������arr2������ָ����������������������ֲ�����ȫ����ɹ������
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