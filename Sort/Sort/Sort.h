#pragma once
#include<stdio.h>
#include<stdlib.h>

void PrintArray(int* arr, int length);

// ��������˼�룺
// �ҵ�һ����ֵ��Ϊ���ֵ�����жϣ������ϵ����ҵ��ڸ������������ֵ����ȷ���λ��
//	��ν��ȷ���λ�ã����Ǵ���ں��棬С����ǰ��
// ÿһ���жϲ�ȷ���������ֵ����ȷ���λ�ú󣬾͵���һ���µ����ֵ�������ϵݹ�
//
int Partition(int* arr, int front, int behind);	// Ѱ���±�Ϊfront�����ݵ���ȷ���λ�ã�������ȷλ�õ��±귵�أ��Ա����ʹ��

void Quick_Sort(int* arr, int front, int behind);	// ��������������

void Insert_Sort(int* arr, int length);	// ��������

void Shell_Sort(int* arr, int length, int step);	// ϣ������

void Print_Sort(int* arr, int length);	// ��ӡ����