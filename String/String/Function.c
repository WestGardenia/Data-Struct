#define _CRT_SECURE_NO_WARNINGS

#include"String.h"

String* StringInit()	// 串的初始化
{
	String* s = (String*)malloc(sizeof(String));
	if (s == NULL)
	{
		exit(-1);
	}
	s->data = 0;
	s->length = 0;

	return s;
}

void StringAssign(String* s,char* data)	// 串--赋值
{
	assert(s);
	if (s->data)
	{
		free(s);	// 如果指针中data有值，需要将其free掉，防止野指针
	}
	int len = 0;
	char* temp = data;
	while (*temp)
	{
		// 循环遍历传入的字符串，并记录字符串的长度
		len++;
		temp++;
	}
	if (len == 0)
	{
		// len为空，表示传入的是空指针
		s->data = NULL;
		s->length = 0;
	}
	else
	{
		// len不为空，则正常将形参data中的值传给串
		temp = data;	// 重新处理temp指针位置（经过上面的循环，现在temp指向data字符串的最后
		s->length = len;
		s->data = (char*)malloc(sizeof(char) * (len + 1));	// 开辟的空间需要保存字符串中的值以及标志字符串结束的'\0'
		assert(s->data);
		for (int i = 0; i < len; i++)
		{
			s->data[i] = temp[i];	// s->data[i] = *(temp+i)
		}
	}
}

void StringPrint(String* s)	// 串--打印
{
	assert(s);
	for (int i = 0; i < s->length; i++)
	{
		printf(i == 0 ?  "%c" : "->%c", s->data[i]);
	}
	printf("\n");
}

void StringForceMatch(String* master, String* sub)	// 串--暴力匹配
{
	assert(master && sub);
	int i = 0;
	int j = 0;
	while (i < master->length && j < sub->length)
	{
		if (master->data[i] == sub->data[j])
		{
			// 如果对应位置字符相等，则指针迭代后移
			i++;
			j++;
		}
		else
		{
			// 如果没有匹配成功，则指针发生回溯
			j = 0;
			i = i - j + 1;	// master字符串由于在之前匹配过程中，已经将sub字符串指针的移动数据走过，所以需要进行处理
			//	a	b	a	b	c	d	e	f	g
			//	a	b	c	d	e
		}
	}
	if (j == sub->length)
	{
		printf("force match success.\n");
	}
	else
	{
		printf("forec match fail.\n");
	}
}