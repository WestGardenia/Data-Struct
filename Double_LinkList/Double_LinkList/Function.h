#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<errno.h>

// ��ͷ˫��ѭ������

typedef int LTDataType;
typedef struct ListNode LTNode;

struct ListNode
{
	LTDataType val;
	LTNode* next;
	LTNode* prev;
};
// ˫������ṹ�嶨��

LTNode* ListInit(); // �����ʼ��

LTNode* BuyListNode(LTDataType x); // �����������½��

void ListDestroy(LTNode* phead); // ��������

void ListPrint(LTNode* phead); // �����ӡ

void ListPushBack(LTNode* phead, LTDataType x); // ����β�� 

void ListPopBack(LTNode* phead); // ����βɾ

void ListPushFront(LTNode* phead, LTDataType x); // ����ͷ��

void ListPopFront(LTNode* phead); // ����ͷɾ

LTNode* ListFind(LTNode* phead, LTDataType x);  // Ѱ�������е�ĳ��ֵ��������ظ��ģ��򷵻ص�һ���ҵ���ͬ��

void ListInsert(LTNode* pos, LTDataType x);	// ���м�λ�ò�������

void ListErase(LTNode* pos);	// ���м�λ��ɾ������

