#define _CRT_SECURE_NO_WARNINGS
#include"Function.h"

void StackInit(SK* ps)	// ��ʼ��ջ
{
	assert(ps);
	ps->a = NULL;
	ps->top_val = 0;	// topջ��ֵҲ������-1.��������top = 0ʱ������ָ��ָ��ջ�����ݵ���һ������top = -1ʱ��ָ��ָ��ջ��Ԫ�أ��ڷ�������ʱ��Ҫ���Լ��ٷ�����
	ps->capacity = 0;
}

void StackPush(SK* ps, SKDataType x)	// ѹջ����
{
	if (ps->top_val == ps->capacity)
	{
		// ���ջ��ֵ�ﵽ���ޣ�����Ҫ��������
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity*2;
		SKDataType* tmp = realloc(ps->a, sizeof(SKDataType) * newcapacity);
		// ����realloc������ԭ�еĻ����Ͽ��ٿռ�ʱ��
		// ��������ps->aΪ��ָ�룬�������ʱΪ��ջ��һ�ν���ѹջ��������ʱrealloc�������Կ�����malloc����
		// ��������ps->a��Ϊ��ָ�룬�Ͱ���realloc����ԭ�����ݻ����������
		if (tmp == NULL)
		{
			printf("realoc fail!!!!");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top_val] = x;	// ��xѹ��ջ����ջ����������a���±�Ϊtop��λ��
	ps->top_val++;	// ÿ��ѹջ��ɣ���Ҫ��ջ��λ���Լ�
}

void StackDestroy(SK* ps)	// ����ջ
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top_val = ps->capacity = 0;
}

void StackPop(SK* ps)	// ��ջ����
{
	assert(ps);
	// ��ջ�ı���ʵ���Ͼ���ɾ����������һ��Ԫ��
	assert(!StackEmpty(ps));
	if (ps->top_val > 0)
	{
		//printf("��ʱջ��λ�ò���ջ�ף����Լ���ɾ��\n");
		ps->top_val--;
		ps->capacity--;
	}
	else
	{
		printf("Pop Fail!!!!!");
		exit(-1);
	}
}

SKDataType StackTop(SK* ps)	// ���ջ��Ԫ��
{
	assert(ps);	// �Է������ָ��
	// �Է������ջΪ��ջ����ɳ���Խ��.���ַ������ж��ԣ������ڲ�ͬ����֮��ṹ��Ķ��������Ծ���ʹ�ýӿں�������ֱ�ӷ��ʽṹ���Ա
	assert(!StackEmpty(ps));
	// assert(ps->top_val > 0);	

	return ps->a[ps->top_val - 1]; // ��ȥ����ջ�����һ��Ԫ��
}

int StackSize(SK* ps)	// ���ջ��Ԫ�ظ���
{
	assert(ps);
	return ps->top_val;
}

bool StackEmpty(SK* ps)	// �ж�ջ�Ƿ�Ϊ��ջ
{
	assert(ps);

	return ps->top_val == 0;	// ����ǿ�ջ���򷵻�1��������ǿ�ջ���򷵻�0
}