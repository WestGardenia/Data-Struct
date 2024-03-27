#define _CRT_SECURE_NO_WARNINGS
#include"Function.h"



static STList* BuyNewnode(STListdata newdata) //创建新结点函数
{
	STList* newnode = (STList*)malloc(sizeof(STList));
	// assert(newnode);	//对malloc函数创建的新结点用assert断言
	if (newnode == NULL)
	{
		printf("error!!!");
		exit(-1);
	}
	newnode->data = newdata;
	newnode->next = NULL;//创建出来的newnode实际上是一个结构体指针，用“->”符号对newnode指向的结构体中的数据域和指针域进行初始化
	return newnode;
}

void STListPrint(STList* phead)
{
	// 打印函数思路：
	// 1、创建一个新的结点，初始化为头节点
	// 2、利用新指针从头开始遍历，并将遍历得到的数据打印下来
	STList* current = phead;
	while (current)
	{
		printf("%d->", current->data);
		current = current->next;
	}
	printf("NULL\n");
}

void STListPushHead(STList** pphead, STListdata newdata)
{
	//头插法思路：
	// 1、创建新的结点
	// 2、将新节点指向头节点；
	// 3、将新节点变成新的头节点

	// 注意点：由于函数中创建的变量是临时变量，函数结束临时变量会随函数结束而销毁。
	// 而头插法（包括头删法）都会对传入的头结点的内容有所改变。所以我们需要将头结点的地址传入函数，也就是将二级指针作为形参传入
	STList* newnode = BuyNewnode(newdata);
	newnode->next = *pphead;//将新结点的next指针指向原头节点，完成新结点的插入操作
	*pphead = newnode;//将新结点的地址给头节点，完成新结点变成头节点的操作
}

void STListPopHead(STList** pphead)//链表--头删法
{
	//头删法思路：
	// 1、找到第二个结点，并记录下该结点地址
	// 2、将该结点变成头结点
	// 3、free掉新结点
	assert(*pphead);
	// 这里对pphead断言是因为后续操作需要对pphead解引用，以防传入的指针是空指针，从而形成野指针
	STList* current = (*pphead)->next;
	free(*pphead);
	*pphead = current;
}

void STListPushBack(STList** pphead, STListdata newdata)//链表--尾插法
{
	// 尾插法思路：
	// 1、找到尾结点，并生成一个新的结点
	// 2、奖尾结点的next指向新结点，并将新结点的next指向NULL
	// 3、如果传入节点是空结点，则直接进行头插法
	if ((*pphead) == NULL)
	{
		STListPushHead(pphead, newdata);
	}

	else
	{
		STList* newnode = BuyNewnode(newdata);

		STList* current = *pphead;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newnode;
	}

}

void STListPopBack(STList** pphead)//链表--尾删法
{
	// 尾删法思路：
	// 1、首先找到整个链表最后一个节点，以及其上一个节点。
	// 2、记录下倒数第二个节点，并将其next指向NULL
	// 3、free掉尾结点
	assert(*pphead);
	
	// 如果链表只有一个结点，此时就是头删法。
	// 如果常规尾删法，在while循环中就不会执行，也就是说preview在循环结束后还是NULL。
	// 就会在preview->next = NULL;这行代码处访问空指针
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		STList* current = *pphead;
		STList* preview = NULL;
		while (current->next != NULL)
		{
			preview = current;
			// 由于preview在初始化时为NULL，所以这里不能使用其中的next指针。否则就是相当于解引用了空指针，形成野指针
			// 另外，一次循环过后，current就会被其next里的地址覆盖，所以也不需要使用preview的next
			current = current->next;
		}
		preview->next = NULL;
		free(current);
	}
}

STList* STListFind(STList* phead, int position)// 链表--查找对应位置的结点
{
	// 链表查找思路：
	// 1、从头结点开始遍历，遍历position次
	// 2、找到对应的结点，并将该结点返回
	//
	while (position)
	{
		if (phead->next)// 判断传入的位置是否在链表中存在，如果不存在，则返回error position
		{
			phead = phead->next;
			position --;
		}
		else
		{
			printf("error position!!!!");
			return NULL;
		}
	}
	return phead;
}

void STListInsert(STList** pphead, STListdata newdata, STList** pos)// 链表--从中间指定位置(pos指针处)后插入
{
	// 中间插入思路：
	// 1、创建一个新结点newnode，将要插入的数据传入新结点中
	// 2、判断插入的位置是不是头结点
	// 3、如果是头结点，就进行头插法
	// 4、如果不是头结点，找到pos结点的next结点，并将其记录下来，记为current。将pos结点的next指向新结点newnode，将newnode的next结点指向current
	//
	STList* newnode = BuyNewnode(newdata);
	assert(*pphead);
	assert(*pos);
	if (*pos == *pphead)
	{
		newnode->next = *pos;
		*pphead = newnode;
	}
	else
	{
		newnode->next = (*pos)->next;
		(*pos)->next = newnode;
	}
}

void STListDelete(STList** pos)// 链表--从中间指定位置(pos指针处)后删除
{
	// 中间删除思路：
	// 1、判断要删除的位置是不是尾结点。如果是尾结点，报错
	// 2、如果不是头结点。则先找到pos结点的后一个结点，记为current。
	// 3、将current的next结点赋给pos的next结点
	// 4、free掉pos->next结点
	//
	if ((*pos)->next == NULL)
	{
		printf("error delete!!!!\n");
		return NULL;
	}
	else
	{
		STList* current = (*pos)->next;
		(*pos)->next = current->next;
		free(current);
	}
}