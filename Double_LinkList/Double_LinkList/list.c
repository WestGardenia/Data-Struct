#include"Function.h"

LTNode* ListInit()  // 链表初始化
{
	// 初始化带头双向循环链表；
	// 双向循环链表的头结点的prev和next指针需要指向自身
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	if (phead == NULL)
		exit(1);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

LTNode* BuyListNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	// malloc函数可能会开辟空间失败（如果计算机内存不够），所以需要对malloc函数开辟的空间进行检查
	if (newnode == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	newnode->val = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

void ListPrint(LTNode* phead)  // 链表打印
{
	assert(phead);
	// 由于链表带头，所以需要从phead->next开始遍历
	// 又由于循环链表的结构特点，所以需要pos结点和首结点相同时，循环结束
	LTNode* pos = phead->next;
	if (phead->next == phead)
	{
		printf("此链表尾为空！！！！");
	}
	while (pos != phead)
	{
		printf("%d->", pos->val);
		pos = pos->next;
	}
	printf("\n");
}

void ListPushBack(LTNode* phead, LTDataType x) // 链表尾插
{
	// 对传入的头结点进行断言
	assert(phead);
	// 根据循环双向链表的结构特性找到尾结点
	LTNode* tail = phead->prev;
	// 开辟一个新结点用于尾插新的数据
	LTNode* newtail = BuyListNode(x);
	newtail->val = x;
	// 尾插：将newnode插入phead和tail之间	(需要依次将三个节点中的四个指针中的内容依次改变）
	tail->next = newtail;
	newtail->next = phead;
	newtail->prev = tail;
	phead->prev = newtail;
}

void ListPopBack(LTNode* phead) // 链表尾删
{
	assert(phead);
	// 考虑链表头结点被删掉情况下，报错
	assert(phead->next != phead);
	LTNode* tail = phead->prev;
	LTNode* newtail = tail->prev;
	// 删除操作
	phead->prev = newtail;
	newtail->next = phead;
	// 释放被删除结点的空间
	free(tail);
}

void ListPushFront(LTNode* phead, LTDataType x) // 链表头插
{
	assert(phead);
	// 创建新结点
	LTNode* newnode = BuyListNode(x);
	newnode->val = x;
	// 将新结点插入phead之后
	LTNode* head = phead->next;
	newnode->next = head;
	newnode->prev = phead;
	head->prev = newnode;
	phead->next = newnode;
}

void ListPopFront(LTNode* phead) // 链表头删
{
	assert(phead);
	assert(phead->next != phead);
	// 寻找头结点
	LTNode* head = phead->next;
	LTNode* newhead = head->next;
	// 断连与重连
	phead->next = newhead;
	newhead->prev = phead;
	// 释放原头结点空间
	free(head);
}

LTNode* ListFind(LTNode* phead, LTDataType x)  // 寻找链表中的某个值，如果有重复的，则返回第一个找到相同的
{
	LTNode* pos = phead->next;
	while (pos != phead)
	{
		if (pos->val == x)
			return pos;
		pos = pos->next;
	}
	printf("没有相同值，查找错误\n");
	return 0;
}