#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>


typedef struct heap heap;

typedef int HPDataType;

struct heap {
	HPDataType* arr;
	int size;
	int capacity;
};

void Heap_Init(heap* php, HPDataType* arr, int n);

void swap(HPDataType* a, HPDataType* b);

void AdjustDown(int* arr,int n,int root);	// 堆--向下调整--用于构建堆

void AdjustUp(int* arr,int n,int child);		// 堆--向上调整--用于调整堆

void Heap_Sort(heap* php, int n);

void Heap_Destory(heap* php);

void Heap_Push(heap* php, HPDataType data);		// 堆--数据插入（尾插）

void Heap_Print(heap* php);		

void Heap_Pop(heap* php);	// 堆--数据删除（头删）