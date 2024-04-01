#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>  // 定义bool类型的头文件

typedef int SKDataType;
typedef struct Stack SK;

struct Stack
{
	SKDataType* a;
	int top;	// 栈顶位置
	int capacity;	// 栈的容量
};

void StackInit(SK* ps);	// 初始化栈

void StackDestroy(SK* ps);	// 销毁栈

void StackPush(SK* ps,SKDataType x);	// 压栈操作

void StackPop(SK* ps);	// 出栈操作

SKDataType StackTop(SK* ps);	// 获得栈顶元素

int StackSize(SK* ps);	// 获得栈的元素个数

bool StackEmpty(SK* ps);	// 判断栈是否为空栈

