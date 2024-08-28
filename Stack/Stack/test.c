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
	
	StackDestroy(&st);	// 每次使用完栈需要将其销毁。否则会造成空间占用

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
		printf("%d ", StackTop(&st));	// 取栈顶数据，并将其打印
		StackPop(&st);	// 每次取出栈顶数据后，将栈顶位置迭代，得到新的栈顶
	}

	StackDestroy(&st);
}

int main()
{
	test01();
	test02();
	return 0;
}