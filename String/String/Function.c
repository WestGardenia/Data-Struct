#define _CRT_SECURE_NO_WARNINGS

#include"String.h"

String* StringInit()	// ���ĳ�ʼ��
{
	String* s = (String*)malloc(sizeof(String));
	s->data = 0;
	s->length = 0;

	return s;
}

void StringAssign(String* s,char* data)	// ��--��ֵ
{
	if (s->data)
	{
		free(s);
	}

}
