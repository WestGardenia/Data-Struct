#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>  // ����bool���͵�ͷ�ļ�

typedef int SKDataType;
typedef struct Stack SK;

struct Stack
{
	SKDataType* a;	// ����ջ��Ӧ��������->a
	int top_val;	// ջ��λ��
	int capacity;	// ջ������
};

void StackInit(SK* ps);	// ��ʼ��ջ

void StackDestroy(SK* ps);	// ����ջ


void StackPush(SK* ps,SKDataType x);	// ѹջ����

void StackPop(SK* ps);	// ��ջ����

SKDataType StackTop(SK* ps);	// ���ջ��Ԫ��

int StackSize(SK* ps);	// ���ջ��Ԫ�ظ���

bool StackEmpty(SK* ps);	// �ж�ջ�Ƿ�Ϊ��ջ

bool isValid(char* s);	// �ж��ַ������Ƿ�Ϊ��Ч���ţ����������ƥ��
// (  ƥ��  )
// [  ƥ��  ]
// {  ƥ��  }
// ��������������ƥ���ͬʱ������Ҫ�����Ӧ���ŵ������ƥ��
//

