#pragma once
#include<stdio.h>
#include<stdlib.h>

void PrintArray(int* arr, int length);

// 快速排序思想：
// 找到一个数值作为相对值进行判断，并不断迭代找到在该数组中这个数值的正确相对位置
//	所谓正确相对位置，就是大的在后面，小的在前面
// 每一次判断并确定好这个数值的正确相对位置后，就迭代一个新的相对值，并不断递归
//
int Partition(int* arr, int front, int behind);	// 寻找下标为front的数据的正确相对位置，并将正确位置的下标返回，以便后续使用

void Quick_Sort(int* arr, int front, int behind);	// 快速排序函数主体

void Insert_Sort(int* arr, int length);	// 插入排序

void Shell_Sort(int* arr, int length, int step);	// 希尔排序

void Print_Sort(int* arr, int length);	// 打印函数