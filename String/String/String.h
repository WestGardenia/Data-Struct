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

int* GetNext(String* s);	// ���㡢��ȡnext����

void PrintNext(int* next, int len);	// ��ӡnext����

void StringKMP_Match(String* master, String* sub, int* next);	// ��--KMPƥ���㷨
// KMP�㷨��
// ��һ�ָ�Ч��ģʽƥ���㷨��������һ���ռ�Ϊ�������ڱ���next���飬�ﵽ���ƥ��Ч�ʵ�Ŀ��
// ͬʱkmp�㷨�ܸ������ܵ��ƶ��ַ��������ַ����ﵽƥ��״̬
// KMP�㷨ԭ��
//		����ǰ��׺������Ѱ��ǰ���ܹ�ƥ���״̬��λ��
//		next���飺next[i] = i�����ַ��Ĺ���ǰ��׺ֵ + 1
//	��ν����ǰ��׺����Ϊ�˼��������Ѿ��������ɹ�ƥ��֮�����Ч����ƥ�����
//	���ģ���������ָ���ƶ������ҿ����ҵ�ǰ��ƥ���״̬
//

