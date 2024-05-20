#pragma once


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>


typedef struct My_String {
	char* data;
	int length;
}My_String;

My_String* My_String_Init();

void My_String_Assign(My_String* s, char* data);

void My_String_Print(My_String* s);

// 暴力匹配算法
void My_String_ForceMatch(My_String* s, My_String* sub);

// KMP模式匹配算法
int* My_String_GetNext(My_String* s);

int* My_String_GetNextval(My_String* s);

void My_String_KMP_Match(My_String* s, My_String* sub);