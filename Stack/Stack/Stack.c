#define _CRT_SECURE_NO_WARNINGS
#include"Function.h"

void StackInit(SK* ps)	// 初始化栈
{
	assert(ps);
	ps->a = NULL;
	ps->top_val = 0;	// top栈顶值也可以是-1.区别在于top = 0时，代表指针指向栈顶数据的下一个；当top = -1时，指针指向栈顶元素，在放入数据时需要先自加再放数据
	ps->capacity = 0;
}

void StackPush(SK* ps, SKDataType x)	// 压栈操作
{
	if (ps->top_val == ps->capacity)
	{
		// 如果栈顶值达到上限，就需要进行扩容
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity*2;
		SKDataType* tmp = realloc(ps->a, sizeof(SKDataType) * newcapacity);
		// 利用realloc函数在原有的基础上开辟空间时：
		// 如果传入的ps->a为空指针，即代表此时为空栈第一次进行压栈操作。此时realloc函数可以看做成malloc函数
		// 如果传入的ps->a不为空指针，就按照realloc进行原地扩容或者异地扩容
		if (tmp == NULL)
		{
			printf("realoc fail!!!!");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top_val] = x;	// 将x压入栈顶，栈顶就是数组a中下标为top的位置
	ps->top_val++;	// 每次压栈完成，需要将栈顶位置自加
}

void StackDestroy(SK* ps)	// 销毁栈
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top_val = ps->capacity = 0;
}

void StackPop(SK* ps)	// 出栈操作
{
	assert(ps);
	// 出栈的本质实质上就是删除数组的最后一个元素
	assert(!StackEmpty(ps));
	if (ps->top_val > 0)
	{
		//printf("此时栈顶位置不在栈底，可以继续删除\n");
		ps->top_val--;
		ps->capacity--;
	}
	else
	{
		printf("Pop Fail!!!!!");
		exit(-1);
	}
}

SKDataType StackTop(SK* ps)	// 获得栈顶元素
{
	assert(ps);	// 以防传入空指针
	// 以防传入的栈为空栈，造成程序越界.两种方法进行断言，但由于不同程序之间结构体的定义差别，所以尽量使用接口函数而非直接访问结构体成员
	assert(!StackEmpty(ps));
	// assert(ps->top_val > 0);	

	return ps->a[ps->top_val - 1]; // 回去数组栈的最后一个元素
}

int StackSize(SK* ps)	// 获得栈的元素个数
{
	assert(ps);
	return ps->top_val;
}

bool StackEmpty(SK* ps)	// 判断栈是否为空栈
{
	assert(ps);

	return ps->top_val == 0;	// 如果是空栈，则返回1；如果不是空栈，则返回0
}