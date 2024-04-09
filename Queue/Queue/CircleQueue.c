#define _CRT_SECURE_NO_WARNINGS
#include"CircleQueue-Function.h"

MyCircularQueue* myCircularQueueCreate(int k)	// 创建循环队列
{
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->a = malloc(sizeof(int) * (k + 1));	// 多开一个空间区分空和满
	cq->front = cq->tail = 0;
	cq->k = k;

	return cq;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)	// 判断是否成功插入元素
{
	if (myCircularQueueIsFull(obj))
		// 如果循环队列已满，则无可用空间去插入数据，则判断插入失败。返回false
		return false;
	obj->a[obj->tail] = value;
	obj->tail++;
	obj->tail %= (obj->k + 1);	// 控制下标，防止下标越界
	
	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)	// 判断是否成功删除元素
{
	if (myCircularQueueIsEmpty(obj))
		// 如果循环队列已空，则无可用数据去删除，则判断删除失败。返回false
		return false;
	// 删除的情况相对简单
	// 由于循环队列的特点，只需要将front下标自加，那么原来front对应的数据就会被未来插入时的数据覆盖。同时不会被意外访问
	obj->front++;
	obj->front %= (obj->k + 1);

	return true;
}

int myCircularQueueFront(MyCircularQueue* obj)	// 循环队列--取对头数据
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj -> a[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj)	// 循环队列--取队尾数据
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	// 取队尾数据时，由于tail的前一个数据才是所求的队尾数据
	// 而循环队列的tail和队尾数据的相对位置并不统一。所以需要进行处理一下
	// 1、数据处理
	int realtail = (obj->tail+obj->k)%(obj->k+1);
	return obj->a[realtail];
	// 2、暴力判断
	//if (obj->tail == 0)
	//	return obj->a[obj->k];
	//else
	//	return obj->a[obj->tail - 1];

}

bool myCircularQueueIsEmpty(MyCircularQueue* obj)	// 循环队列--判空
{
	return obj->front == obj->tail;
}

bool myCircularQueueIsFull(MyCircularQueue* obj)	// 循环队列--判满
{
	return (obj->tail + 1) % (obj->k + 1) == obj->front;
}

void myCircularQueueFree(MyCircularQueue* obj)	// 销毁循环队列
{
	free(obj->a);
	free(obj);
}