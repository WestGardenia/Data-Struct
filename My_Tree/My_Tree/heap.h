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

void AdjustDown(int* arr,int n,int root);	// ��--���µ���--���ڹ�����

void AdjustUp(int* arr,int n,int child);		// ��--���ϵ���--���ڵ�����

void Heap_Sort(heap* php, int n);

void Heap_Destory(heap* php);

void Heap_Push(heap* php, HPDataType data);		// ��--���ݲ��루β�壩

void Heap_Print(heap* php);		

void Heap_Pop(heap* php);	// ��--����ɾ����ͷɾ��