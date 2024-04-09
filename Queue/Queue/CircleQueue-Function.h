#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

// ������ѭ������ʵ�֡� ѭ��������һ���������ݽṹ����������ֻ��� FIFO���Ƚ��ȳ���ԭ���Ҷ�β�������ڶ���֮�����γ�һ��ѭ������Ҳ����Ϊ�����λ���������

// ѭ�����е�һ���ô������ǿ��������������֮ǰ�ù��Ŀռ䡣
// ��һ����ͨ�����һ��һ���������ˣ����ǾͲ��ܲ�����һ��Ԫ�أ���ʹ�ڶ���ǰ�����пռ䡣
// ����ʹ��ѭ�����У�������ʹ����Щ�ռ�ȥ�洢�µ�ֵ����Щ�ռ�����������洢��Ԫ�ص����־���ɾ�����Ϊ�˿յĿռ�

// 1�������Ƚ��ȳ����ص�
// 2���ռ��С�ǹ̶���
// 3�������������ָ����Ʊ�ʾѭ���ṹ��Ҳ����ʹ��������±���Ʊ�ʾѭ���ṹ


// �ص㣺
// ѭ������������ʹ�����黹������ʵ�֣���Ҫ�࿪һ���ռ�
// Ҳ����ζ�ţ�Ҫ��k�����ݵ�ѭ�����У�Ҫ��k+1���ռ�
// �����޷�ʵ���пպ�����
// 
// ���磺
// ��ʹ����ʽ�ṹʵ��ѭ�����С�
// �пյ�������Ȼ��tail == head��
// ���ǵ�û�ж���ռ�ȥ�ж�ʱ��tail == headҲ������������������
//	���������¿ռ�ʱ����������Ϊ��
//		����ʵ�֣�(tail+1)%(k+1) == head
//		����ʵ�֣� tail->next == head
// 
// 
// ������������������������������������������������������������������������������������������������������������������������������������������������
// 
// ����ṹʵ�ֻ��ζ���
//
typedef struct MyCircularQueue MyCircularQueue;

struct MyCircularQueue {
	int* a;		// ����ṹ
	int front;
	int tail;
	int k;	// ���ζ��еĴ�С
};

MyCircularQueue* myCircularQueueCreate(int k);	// ����ѭ������

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value);	// �ж��Ƿ�ɹ�����Ԫ��

bool myCircularQueueDeQueue(MyCircularQueue* obj);	// �ж��Ƿ�ɹ�ɾ��Ԫ��

int myCircularQueueFront(MyCircularQueue* obj);	// ѭ������--ȡ��ͷ����

int myCircularQueueRear(MyCircularQueue* obj);	// ѭ������--ȡ��β����

bool myCircularQueueIsEmpty(MyCircularQueue* obj);	// ѭ������--�п�

bool myCircularQueueIsFull(MyCircularQueue* obj);	// ѭ������--����

void myCircularQueueFree(MyCircularQueue* obj);	// ����ѭ������

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
