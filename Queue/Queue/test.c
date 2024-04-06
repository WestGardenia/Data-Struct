#define _CRT_SECURE_NO_WARNINGS
#include"Function.h"

static void test01()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePush(&q, 6);
	QueuePush(&q, 7);
	// ����--β�����

	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	// ����--βɾ����

	printf("��β���ݳ�ȡ��%d\n", QueueBack(&q));
	
	printf("��ͷ���ݳ�ȡ��%d\n", QueueFront(&q));

	QueuePush(&q, 5);
	QueuePush(&q, 6);
	QueuePush(&q, 7);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);

	printf("�������Ȳ��ԣ�%d\n", QueueSize(&q));

	QueueDestroy(&q);
}

static void test02()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePush(&q, 6);
	QueuePush(&q, 7);

	while (!QueueEmpty(&q))
	{
		QDataType data = QueueFront(&q);
		printf(" %d", data);
		QueuePop(&q);
	}
	QueueDestroy(&q);
}

int main()
{
	// test01();
	test02();
	return 0;
}