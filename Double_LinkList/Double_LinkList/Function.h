#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int LTDateType;
typedef struct ListNode ListNode;

struct ListNode
{
	LTDateType val;
	ListNode* next;
	ListNode* prev;
};
// ˫������ṹ�嶨��

void ListInit(ListNode* phead); // �����ʼ��

void ListPushBack(ListNode* phead, int x); // ����β�� 