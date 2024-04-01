#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<errno.h>

// 带头双向循环链表

typedef int LTDataType;
typedef struct ListNode LTNode;

struct ListNode
{
	LTDataType val;
	LTNode* next;
	LTNode* prev;
};
// 双向链表结构体定义

LTNode* ListInit(); // 链表初始化

LTNode* BuyListNode(LTDataType x); // 船创建链表新结点

void ListDestroy(LTNode* phead); // 销毁链表

void ListPrint(LTNode* phead); // 链表打印

void ListPushBack(LTNode* phead, LTDataType x); // 链表尾插 

void ListPopBack(LTNode* phead); // 链表尾删

void ListPushFront(LTNode* phead, LTDataType x); // 链表头插

void ListPopFront(LTNode* phead); // 链表头删

LTNode* ListFind(LTNode* phead, LTDataType x);  // 寻找链表中的某个值，如果有重复的，则返回第一个找到相同的

void ListInsert(LTNode* pos, LTDataType x);	// 从中间位置插入数据

void ListErase(LTNode* pos);	// 从中间位置删除数据

