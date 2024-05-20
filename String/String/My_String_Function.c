#define _CRT_SECURE_NO_WARNINGS

#include"My_String.h"


My_String* My_String_Init()
{
	My_String* S = (My_String*)malloc(sizeof(My_String));
	assert(S);
	S->data = 0;
	S->length = 0;

	return S;
}

void My_String_Assign(My_String* s, char* data)
{
	assert(s);
	if (s->data)
	{
		s->data = NULL;
	}
	int length = 0;
	char* temp = data;

	while (*temp != '\0')
	{
		temp++;
		length++;
	}
	if (length == 0)
	{
		s->data = NULL;
		s->length = 0;
	}
	else
	{
		temp = data;
		s->data = (char*)malloc(sizeof(char) * (length + 1));
		for (int i = 0; i < length; i++)
		{
			s->data[i] = temp[i];
		}
		s->length = length;
	}
}

void My_String_Print(My_String* s)
{
	char* temp = s->data;

	for (int i = 0; i < s->length; i++)
	{
		printf(i == 0 ? "%c" : "->%c", temp[i]);
	}
	printf("\n");
}

void My_String_ForceMatch(My_String* s,My_String* sub)
{
	int i = 0;
	int j = 0;
	while (i<s->length && j<sub->length)
	{
		if (s->data[i] == sub->data[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j == sub->length)
		printf("success\n");
	else
		printf("false\n");
}

int* My_String_GetNext(My_String* s)
{
	int* next = (int*)malloc(sizeof(int) * s->length);

	int i = 0;
	int j = -1;

	next[i] = j;
	while (i < s->length - 1)
	{
		if (j == -1 || s->data[i] == s->data[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
	return next;
}

int* My_String_GetNextval(My_String* s)
{
	int* next = My_String_GetNext(s);

	int* nextval = (int*)malloc(sizeof(int) * s->length);
	int i = 1;
	nextval[0] = -1;
	while (i < s->length)
	{
		if (s->data[i] == s->data[next[i]])
		{
			nextval[i] = nextval[next[i]];
		}
		else
		{
			nextval[i] = next[i];
		}
		i++;
	}
	return nextval;
}

void My_String_KMP_Match(My_String* s, My_String* sub)
{

	//int* next = My_String_GetNext(sub);	// 取得模式串的next数组
	int* next = My_String_GetNextval(sub);	// 取得模式串的nextval数组

	int i = 0;
	int j = 0;
	while (j < sub->length && i < s->length)
	{
		if (j == -1 || s->data[i] == sub->data[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j == sub->length)
	{
		printf("KMP_Match is succesful!!!!\n");
	}
	else
	{
		printf("KMP_Match is false!!!!\n");
	}

}