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

void AdjustDown(int* arr,int n,int root);	// �ѣ�С�ѣ�--���µ���--���ڹ�����

void AdjustUp(int* arr,int n,int child);		// �ѣ�С�ѣ�--���ϵ���--���ڵ�����

void Heap_Sort(heap* php, int n);

void Heap_Destory(heap* php);

void Heap_Push(heap* php, HPDataType data);		// ��--���ݲ��루β�壩

void Heap_Print(heap* php);		

void Heap_Pop(heap* php);	// ��--����ɾ����ͷɾ��


//Leetcode OJ�⣺���һ���㷨���ҳ���������С��k������������˳�򷵻���k�������ɡ�
void AdjustDowm_01(int* arr, int k, int root);	// ��ѵ����µ����㷨
int* smallestK(int* arr, int arrSize, int k, int* returnSize);