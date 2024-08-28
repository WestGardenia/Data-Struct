#define _CRT_SECURE_NO_WARNINGS
#include"Function.h"

static void test01()
{
	SK st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	StackPush(&st, 6);

	StackPop(&st);
	StackPop(&st);

	printf("%d\n", StackTop(&st));
	
	StackDestroy(&st);	// ÿ��ʹ����ջ��Ҫ�������١��������ɿռ�ռ��

}


static void test02()
{
	SK st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);

	printf("%d ", StackTop(&st));
	StackPop(&st);
	
	printf("%d ", StackTop(&st));
	StackPop(&st);

	StackPush(&st, 6);

	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));	// ȡջ�����ݣ��������ӡ
		StackPop(&st);	// ÿ��ȡ��ջ�����ݺ󣬽�ջ��λ�õ������õ��µ�ջ��
	}

	StackDestroy(&st);
}

int main()
{
	test01();
	test02();
	return 0;
}