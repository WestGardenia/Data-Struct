#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct String String;

struct String {
	char* data;
	int length;
};

String* StringInit();	// ���ĳ�ʼ��

void StringAssign(String* s, char* data);	// ��--��ֵ

void StringPrint(String* s);	// ��--��ӡ

void StringForceMatch(String* master, String* sub);	// ��--����ƥ��
