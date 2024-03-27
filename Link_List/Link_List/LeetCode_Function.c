#define _CRT_SECURE_NO_WARNINGS
#include"Function.h"



// ����ʵ�֣�ʵ�������ԭ�ط�ת�����ں��������󷵻�������
STList* STListFilp_1(STList* phead)// ����--ԭ�ط�ת
{
	// ��ת˼·��
	// 1���������������������㣬�ֱ��¼��Ӧ������Ϣ
	// 2����ԭ��prev->current->next �Ľṹ���prev<-current<-next �Ľṹ������ʵ��ԭ�ط�ת
	//
	if (phead == NULL)  // �жϴ���������ǲ��ǿ���������ǿ���������NULL
		return NULL;

	STList* preview, *current, *next ;
	preview = NULL;
	current = phead;
	next = phead->next;

	while (current)
	{
		// ��ת���̣�
		current->next = preview;
		// �������̣�
		preview = current;
		current = next;
		if(next)	// ���һ������ʱ��next�Ѿ�ָ��BULL���ٴν���ѭ��������ɽ����ÿ�ָ��
			next = next->next;
	}
	return preview;		
}

STList* STListFilp_2(STList* phead)// ����--ԭ�ط�ת������
{
	// ��ת˼·��ͷ��
	// 1�����ȴ���һ��ָ��NULL���½��newnode
	// 2����ԭ�����ͷ���ȡ�²�ָ���½��newnode
	// 3�����ϵ����������õݹ飬����������ֵ��Ϊ�������´��롣���ǵ������ȹ���֮�󣬻���������ڴ棬����ջ�����
	STList* newnode = NULL;
	STList* current = phead;

	while (current)
	{
		// ͷ��֮ǰ��current�Ľ����Ϣ��¼����
		STList* next = current->next;
		// ͷ��
		current->next = newnode;
		newnode = current;
		// ����
		current = next;
	}
	return newnode;
}

struct Single_List* STList_MiddleNode(struct Single_List* phead)// ����--Ѱ�������м�ڵ㣨ż���ڵ����ʱ�����м��ǰһ����㣩
{
	//˼·һ��������⣬���α��������ҵ�������м�ֵ
	//˼·��������ָ��
	// 1����ָ��һ������������ָ��һ����һ������ͬʱ�䣬����ָ���ߵ�β���ʱ����ָ��ǡ�����м�ڵ㴦
	// 2����������������ָ���nextָ��NULLʱ
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

STList* STList_Merge(STList* phead_1, STList* phead_2)//����--�鲢�������������ϳ�һ���µ���������
{
	// ˼·��
	// 1.�����µ�ͷ��㣬��Ϊ�����������ͷ���
	// 2.ÿ�����½��֮�����ڵ�֮ǰ���Ե�ǰָ�����ڵ�����ԭʼ����Ľ���е���ֵ���бȽ�----��С��ֵ�Ľ���Ȳ�
	// 3.β�巨
	// 4.�������һ����������Ѿ�����������һ������δ��������ô����һ������ʣ�µ����н�������������
	//
	STList* newhead = NULL;	//����ͷ��㣬�Ա����ں�������䷵��
	// �ڿ�ʼ�鲢֮ǰ�����������ͷ������һ�δ���������ɿ�ָ�����
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
	STList* tail = newhead;	//����ͷ��㣬�Ա����ں�������䷵��

	while ((phead_1 != NULL) && (phead_2 != NULL))
	{
		if (phead_1->data <= phead_2->data)
		{
			STList* newnode = phead_1;
			// ÿ��ȡ��������Ľ�㣬�������ӵ��������
			tail->next = newnode;
			tail = tail->next;
			// ������һ����
			phead_1 = phead_1->next;

		}
		else
		{
			STList* newnode = phead_2;
			// ÿ��ȡ��������Ľ�㣬�������ӵ��������
			tail->next = newnode;
			tail = tail->next;
			// �����������
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

STList* STList_Partition(STList* phead, int x)// ����--�������е����ݰ��մ���Ĳ�����СΪ��׼��������Ҫ�󣺴���ں��棬С����ǰ�棬�������˳�򲻱�
{
	// ˼·��
	// 1.�����������������ڷֱ�洢�Ȳ�����Ľ��ͱȲ���С�Ľ��
	// 2.������������������ÿ��������ֵ��������бȽϣ����ֱ�洢
	// 3.���greater�������ӵ�less�����β��
	// 4.ע���ں�������ǰ��Ҫ��greater�����һ�����ָ��NULL�����򣬻ᵼ����ѭ��
	//
	return phead;
}

bool CheckPalindrom(STList* phead)
{
	// Ҫ����ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)������£��ж������Ƿ�Ϊ���Ľṹ
	// ˼·��
	// 1���ҵ�������м���
	// 2�����м�ڵ����һ����㿪ʼ���������������á�
	// 3��������������ԭ����Ƚϣ���ͷ��㿪ʼ����������ĳһ��ָ��NULL֮ǰ����ṹ�е���ֵ����ȣ����ǻ��Ľṹ
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

STList* getIntersectionNode_1(STList* headA, STList* headB)  // �����������㡣����н��㣬�򷵻ؽ���֮����������û�н��㣬�򷵻�NULL
{
	// ˼·һ���������
	// ��A�����ÿһ�������B������бȽϣ�ֻҪ����ͬ�ģ��ͷ��ص�һ�����������Ľ���
	return NULL;
}

STList* getIntersectionNode_2(STList* headA, STList* headB)  // �����������㡣����н��㣬�򷵻ؽ���֮����������û�н��㣬�򷵻�NULL
{
	// ˼·����
	// 1���������������ҵ����Ǹ��Ե�β��㲢���бȽϡ��������ͬ�ģ���������һ��β����ǽ��㡣����¼�����α����õ��Ĵ���   -------�жϹ���
	// 2��ͨ�������õ��Ĵ�����������������������߲�Ĳ�����Ȼ��ʼ��������ͬ������										------Ѱ�ҽ������
	STList* curA = headA;
	STList* curB = headB;
	int lenA = 1;
	int lenB = 1;

	// ��������
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
	// �ҵ������Ȳ�
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

	// ���ó��Ȳ�ó������ȱ������Ȳ�ಽ
	while (gap--)
	{
		longList = longList->next;
	}
	// �Ƚ����������Ƿ����
	while (longList != shortList)
	{
		longList = longList->next;
		shortList = shortList->next;
	}
	return longList;
}

bool hasCycle(STList* phead)
{
	// ���ÿ���ָ���ж������Ƿ����
	// ����ָ��Ĳ���Ϊ2n����ָ��Ĳ���Ϊnʱ��
	// ���������������ָ��һ������׷����ָ�롣
	// ����������������ָ��һ���ȱ���ָ���ߵ�NULL
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
		//�����½��
		RandonList* copyHead = (RandonList*)malloc(sizeof(RandonList));
		//�����ڵ�
		copyHead->val = cur->val;
		//������
		copyHead->next = cur->next;
		cur->next = copyHead;

		//����
		cur = copyHead->next;
	}

	cur = phead;
	while (cur)
	{
		RandonList* copy = cur->next;
		//����random
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
		// ���뿽���ڵ�
		newcur = pos->next;
		pos->next = pos->next->next;
		pos = pos->next;
		// β�巨�������ڵ���뿽��������
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