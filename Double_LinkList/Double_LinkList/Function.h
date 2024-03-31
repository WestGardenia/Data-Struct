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
// 双向链表结构体定义

void ListInit(ListNode* phead); // 链表初始化

void ListPushBack(ListNode* phead, int x); // 链表尾插 