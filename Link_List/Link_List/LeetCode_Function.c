#define _CRT_SECURE_NO_WARNINGS
#include"Function.h"



// 函数实现：实现链表的原地翻转，并在函数结束后返回新链表
STList* STListFilp_1(STList* phead)// 链表--原地翻转
{
	// 翻转思路：
	// 1、创建三个连续的链表结点，分别记录对应结点的信息
	// 2、将原本prev->current->next 的结构变成prev<-current<-next 的结构，即可实现原地翻转
	//
	if (phead == NULL)  // 判断传入的链表是不是空链表。如果是空链表，返回NULL
		return NULL;

	STList* preview, *current, *next ;
	preview = NULL;
	current = phead;
	next = phead->next;

	while (current)
	{
		// 翻转过程：
		current->next = preview;
		// 迭代过程：
		preview = current;
		current = next;
		if(next)	// 最后一步迭代时，next已经指向BULL，再次进行循环，会造成解引用空指针
			next = next->next;
	}
	return preview;		
}

STList* STListFilp_2(STList* phead)// 链表--原地翻转方法二
{
	// 翻转思路：头插
	// 1、首先创建一个指向NULL的新结点newnode
	// 2、将原链表的头结点取下并指向新结点newnode
	// 3、不断迭代（可以用递归，将函数返回值作为参数重新传入。但是当链表长度过长之后，会大量消耗内存，甚至栈溢出）
	STList* newnode = NULL;
	STList* current = phead;

	while (current)
	{
		// 头插之前将current的结点信息记录下来
		STList* next = current->next;
		// 头插
		current->next = newnode;
		newnode = current;
		// 迭代
		current = next;
	}
	return newnode;
}

struct Single_List* STList_MiddleNode(struct Single_List* phead)// 链表--寻找链表中间节点（偶数节点个数时，找中间的前一个结点）
{
	//思路一：暴力求解，两次遍历链表找到链表的中间值
	//思路二：快慢指针
	// 1、快指针一次走两步，慢指针一次走一步，相同时间，当快指针走到尾结点时，慢指针恰好在中间节点处
	// 2、结束条件：当快指针的next指向NULL时
	//
	struct Single_List* quick = phead;
	struct Single_List* slow = phead;
	struct Single_List* cur = NULL;
	while (quick && (quick->next))
	{
		quick = quick->next->next;
		cur = slow;
		slow = slow->next;
	}
	return cur;
}

STList* STList_Merge(STList* phead_1, STList* phead_2)//链表--归并两个有序链表，合成一个新的有序链表
{
	// 思路：
	// 1.生成新的头结点，作为返回新链表的头结点
	// 2.每次在新结点之后插入节点之前，对当前指针所在的两个原始链表的结点中的数值进行比较----较小数值的结点先插
	// 3.尾插法
	// 4.如果其中一个链表遍历已经结束，而另一个链表还未结束，那么将另一个链表剩下的所有结点插入新链表中
	//
	STList* newhead = NULL;	//保存头结点，以便于在函数最后将其返回
	// 在开始归并之前，将新链表的头部先做一次处理，以免造成空指针调用
	if (phead_1->data <= phead_2->data)
	{
		newhead = phead_1;
		phead_1 = phead_1->next;
	}
	else
	{
		newhead = phead_2;
		phead_2 = phead_2->next;
	}
	STList* tail = newhead;	//保存头结点，以便于在函数最后将其返回

	while ((phead_1 != NULL) && (phead_2 != NULL))
	{
		if (phead_1->data <= phead_2->data)
		{
			STList* newnode = phead_1;
			// 每次取得新链表的结点，将其链接到新链表后
			tail->next = newnode;
			tail = tail->next;
			// 将链表一迭代
			phead_1 = phead_1->next;

		}
		else
		{
			STList* newnode = phead_2;
			// 每次取得新链表的结点，将其链接到新链表后
			tail->next = newnode;
			tail = tail->next;
			// 将链表二迭代
			phead_2 = phead_2->next;
		}
	}
	if (phead_1 == NULL)
	{
		tail->next = phead_2;
	}	
	if (phead_2 == NULL)
	{
		tail->next = phead_1;
	}
	return newhead;
}

STList* STList_Partition(STList* phead, int x)// 链表--将链表中的数据按照传入的参数大小为标准进行排序，要求：大的在后面，小的在前面，但是相对顺序不变
{
	// 思路：
	// 1.创建两个新链表，用于分别存储比参数大的结点和比参数小的结点
	// 2.遍历链表，并将链表中每个结点的数值与参数进行比较，并分别存储
	// 3.最后将greater链表链接到less链表的尾部
	// 4.注意在函数结束前，要将greater的最后一个结点指向NULL，否则，会导致死循环
	//
	return phead;
}

bool CheckPalindrom(STList* phead)
{
	// 要求：在时间复杂度O(n)，空间复杂度O(1)的情况下，判断链表是否为回文结构
	// 思路：
	// 1、找到链表的中间结点
	// 2、从中间节点的下一个结点开始，将后续链表逆置。
	// 3、将逆置链表与原链表比较（从头结点开始遍历）。当某一方指向NULL之前链表结构中的数值都相等，则是回文结构
	//
	STList* mid = STList_MiddleNode(phead);
	STList* newhead = STListFilp_1(mid);

	STList* curA = phead;
	STList* curN = newhead;
	while (curA && curN)
	{
		if (curA->data == curN->data)
		{
			curA = curA->next;
			curN = curN->next;
		}
		else
			return false;
	}
	return true;
}

STList* getIntersectionNode_1(STList* headA, STList* headB)  // 求两个链表交点。如果有交点，则返回交点之后的链表；如果没有交点，则返回NULL
{
	// 思路一：暴力求解
	// 将A链表的每一个结点与B链表进行比较，只要有相同的，就返回第一个符合条件的交点
	return NULL;
}

STList* getIntersectionNode_2(STList* headA, STList* headB)  // 求两个链表交点。如果有交点，则返回交点之后的链表；如果没有交点，则返回NULL
{
	// 思路二：
	// 1、遍历两个链表，找到他们各自的尾结点并进行比较。如果有相同的，则至少有一个尾结点是交点。并记录下两次遍历得到的次数   -------判断过程
	// 2、通过遍历得到的次数并做差。将更长的链表先走差的步数。然后开始两个链表同步遍历										------寻找交点过程
	STList* curA = headA;
	STList* curB = headB;
	int lenA = 1;
	int lenB = 1;

	// 遍历链表
	while (curA->next)
	{
		lenA++;
		curA = curA->next;
	}
	while (curB->next)
	{
		lenB++;
		curB = curB->next;
	}
	// 找到链表长度差
	int gap = abs(lenA - lenB);
	STList* longList = headA;
	STList* shortList = headB;
	assert(longList);
	assert(shortList);
	if (lenA < lenB)
	{
		longList = headB;
		shortList = headA;
	}

	// 利用长度差，让长链表先遍历长度差距步
	while (gap--)
	{
		longList = longList->next;
	}
	// 比较两个链表是否相等
	while (longList != shortList)
	{
		longList = longList->next;
		shortList = shortList->next;
	}
	return longList;
}

bool hasCycle(STList* phead)
{
	// 利用快慢指针判断链表是否带环
	// 当快指针的步长为2n而慢指针的步长为n时。
	// 如果链表带环，则快指针一定能在追上慢指针。
	// 如果链表不带环，则快指针一定先比慢指针走到NULL
	STList* fast = phead;
	STList* slow = phead;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return true;
	}
	return false;
}

STList* detectCycle(STList* phead)
{
	STList* fast = phead;
	STList* slow = phead;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			STList* meet = slow;
			while (meet != phead)
			{
				meet = meet->next;
				slow = slow->next;
			}
			return meet;
		}
	}
	return NULL;
}



RandonList* copyRandomList(RandonList* phead)
{
	RandonList* cur = phead;
	while (cur != NULL)
	{
		//创建新结点
		RandonList* copyHead = (RandonList*)malloc(sizeof(RandonList));
		//拷贝节点
		copyHead->val = cur->val;
		//插入结点
		copyHead->next = cur->next;
		cur->next = copyHead;

		//迭代
		cur = copyHead->next;
	}

	cur = phead;
	while (cur)
	{
		RandonList* copy = cur->next;
		//处理random
		if (cur->random)
		{
			copy->random = cur->random->next;
		}
		else
		{
			copy->random = NULL;
		}
		cur = copy->next;
	}
	RandonList* pos = phead;
	RandonList* newhead = NULL;
	RandonList* newcur = NULL;
	RandonList* newtail = NULL;
	while (pos && pos->next)
	{
		// 分离拷贝节点
		newcur = pos->next;
		pos->next = pos->next->next;
		pos = pos->next;
		// 尾插法将拷贝节点插入拷贝链表中
		if (newtail == NULL)
		{
			newhead = newcur;
			newtail = newcur;
		}
		else
		{
			newcur->next = NULL;
			newtail->next = newcur;
			newtail = newcur;
		}
	}
	return newhead;
}