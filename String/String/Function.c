#define _CRT_SECURE_NO_WARNINGS

#include"String.h"

String* StringInit()	// 串的初始化
{
	String* s = (String*)malloc(sizeof(String));
	s->data = 0;
	s->length = 0;

	return s;
}

void StringAssign(String* s,char* data)	// 串--赋值
{
	if (s->data)
	{
		free(s);
	}

}
