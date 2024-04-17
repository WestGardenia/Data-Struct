#define _CRT_SECURE_NO_WARNINGS

#include"String.h"

String* StringInit()	// ���ĳ�ʼ��
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

void StringAssign(String* s,char* data)	// ��--��ֵ
{
	assert(s);
	if (s->data)
	{
		free(s->data);	// ���ָ����data��ֵ����Ҫ����free������ֹҰָ��
	}
	int len = 0;
	char* temp = data;
	while (*temp)
	{
		// ѭ������������ַ���������¼�ַ����ĳ���
		len++;
		temp++;
	}
	if (len == 0)
	{
		// lenΪ�գ���ʾ������ǿ�ָ��
		s->data = NULL;
		s->length = 0;
	}
	else
	{
		// len��Ϊ�գ����������β�data�е�ֵ������
		temp = data;	// ���´���tempָ��λ�ã����������ѭ��������tempָ��data�ַ��������
		s->length = len;
		s->data = (char*)malloc(sizeof(char) * (len + 1));	// ���ٵĿռ���Ҫ�����ַ����е�ֵ�Լ���־�ַ���������'\0'
		assert(s->data);
		for (int i = 0; i < len; i++)
		{
			s->data[i] = temp[i];	// s->data[i] = *(temp+i)
		}
	}
}

void StringPrint(String* s)	// ��--��ӡ
{
	assert(s);
	for (int i = 0; i < s->length; i++)
	{
		printf(i == 0 ?  "%c" : "->%c", s->data[i]);
	}
	printf("\n");
}

void StringForceMatch(String* master, String* sub)	// ��--����ƥ��
{
	assert(master && sub);
	int i = 0;
	int j = 0;
	while (i < master->length && j < sub->length)
	{
		if (master->data[i] == sub->data[j])
		{
			// �����Ӧλ���ַ���ȣ���ָ���������
			i++;
			j++;
		}
		else
		{
			// ���û��ƥ��ɹ�����ָ�뷢������
			j = 0;
			i = i - j + 1;	// master�ַ�����ָ����ݵ�������һ��λ��
			//	a	b	a	b	c	d	e	f	g
			//	a	b	c	d	e
		}
	}
	if (j == sub->length)
	{
		printf("force match success������������\n");
	}
	else
	{
		printf("forec match fail������������\n");
	}
}

int* GetNext(String* s)	// ���㡢��ȡnext����
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

void PrintNext(int* next, int len)	// ��ӡnext����
{
	assert(next);
	for (int i = 0; i < len; i++)
	{
		printf(i == 0 ? "%d" : "->%d", next[i]);
	}
	printf("\n");
}

void StringKMP_Match(String* master, String* sub,int* next)	// ��--KMPƥ���㷨
{
	int i = 0;
	int j = 0;
	while (i < master->length && j < sub->length)
	{
		if (j == -1 || master->data[i] == sub->data[j])
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
		printf("force match success������������\n");
	}
	else
	{
		printf("forec match fail������������\n");
	}
}