#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct String String;

struct String {
	char* data;
	int length;
};

String* StringInit();	// 串的初始化

void StringAssign(String* s, char* data);	// 串--赋值
