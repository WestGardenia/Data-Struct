#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

// 设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。

// 循环队列的一个好处是我们可以利用这个队列之前用过的空间。
// 在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。
// 但是使用循环队列，我们能使用这些空间去存储新的值。这些空间往往是曾今存储过元素但是又经过删除后变为了空的空间

// 1、符合先进先出的特点
// 2、空间大小是固定的
// 3、可以用链表的指针控制表示循环结构；也可以使用数组的下标控制表示循环结构


// 重点：
// 循环队列无论是使用数组还是链表实现，都要多开一个空间
// 也就意味着，要存k个数据的循环队列，要开k+1个空间
// 否则无法实现判空和判满
// 
// 例如：
// 当使用链式结构实现循环队列。
// 判空的条件自然是tail == head。
// 但是当没有多余空间去判断时，tail == head也可以是判满的条件。
//	当创建了新空间时，判满条件为：
//		数组实现：(tail+1)%(k+1) == head
//		链表实现： tail->next == head
// 
// 
// ————————————————————————————————————————————————————————————————————————
// 
// 数组结构实现环形队列
//
typedef struct MyCircularQueue MyCircularQueue;

struct MyCircularQueue {
	int* a;		// 数组结构
	int front;
	int tail;
	int k;	// 环形队列的大小
};

MyCircularQueue* myCircularQueueCreate(int k);	// 创建循环队列

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value);	// 判断是否成功插入元素

bool myCircularQueueDeQueue(MyCircularQueue* obj);	// 判断是否成功删除元素

int myCircularQueueFront(MyCircularQueue* obj);	// 循环队列--取对头数据

int myCircularQueueRear(MyCircularQueue* obj);	// 循环队列--取队尾数据

bool myCircularQueueIsEmpty(MyCircularQueue* obj);	// 循环队列--判空

bool myCircularQueueIsFull(MyCircularQueue* obj);	// 循环队列--判满

void myCircularQueueFree(MyCircularQueue* obj);	// 销毁循环队列

/*
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/
