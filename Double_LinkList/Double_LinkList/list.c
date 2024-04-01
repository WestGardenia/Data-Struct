#include"Function.h"

LTNode* ListInit()  // �����ʼ��
{
	// ��ʼ����ͷ˫��ѭ������
	// ˫��ѭ�������ͷ����prev��nextָ����Ҫָ������
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
	// malloc�������ܻῪ�ٿռ�ʧ�ܣ����������ڴ治������������Ҫ��malloc�������ٵĿռ���м��
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

void ListPrint(LTNode* phead)  // �����ӡ
{
	assert(phead);
	// ���������ͷ��������Ҫ��phead->next��ʼ����
	// ������ѭ������Ľṹ�ص㣬������Ҫpos�����׽����ͬʱ��ѭ������
	LTNode* pos = phead->next;
	if (phead->next == phead)
	{
		printf("������βΪ�գ�������");
	}
	while (pos != phead)
	{
		printf("%d->", pos->val);
		pos = pos->next;
	}
	printf("\n");
}

void ListPushBack(LTNode* phead, LTDataType x) // ����β��
{
	// �Դ����ͷ�����ж���
	assert(phead);
	// ����ѭ��˫������Ľṹ�����ҵ�β���
	LTNode* tail = phead->prev;
	// ����һ���½������β���µ�����
	LTNode* newtail = BuyListNode(x);
	newtail->val = x;
	// β�壺��newnode����phead��tail֮��	(��Ҫ���ν������ڵ��е��ĸ�ָ���е��������θı䣩
	tail->next = newtail;
	newtail->next = phead;
	newtail->prev = tail;
	phead->prev = newtail;
}

void ListPopBack(LTNode* phead) // ����βɾ
{
	assert(phead);
	// ��������ͷ��㱻ɾ������£�����
	assert(phead->next != phead);
	LTNode* tail = phead->prev;
	LTNode* newtail = tail->prev;
	// ɾ������
	phead->prev = newtail;
	newtail->next = phead;
	// �ͷű�ɾ�����Ŀռ�
	free(tail);
}

void ListPushFront(LTNode* phead, LTDataType x) // ����ͷ��
{
	assert(phead);
	// �����½��
	LTNode* newnode = BuyListNode(x);
	newnode->val = x;
	// ���½�����phead֮��
	LTNode* head = phead->next;
	newnode->next = head;
	newnode->prev = phead;
	head->prev = newnode;
	phead->next = newnode;
}

void ListPopFront(LTNode* phead) // ����ͷɾ
{
	assert(phead);
	assert(phead->next != phead);
	// Ѱ��ͷ���
	LTNode* head = phead->next;
	LTNode* newhead = head->next;
	// ����������
	phead->next = newhead;
	newhead->prev = phead;
	// �ͷ�ԭͷ���ռ�
	free(head);
}

LTNode* ListFind(LTNode* phead, LTDataType x)  // Ѱ�������е�ĳ��ֵ��������ظ��ģ��򷵻ص�һ���ҵ���ͬ��
{
	LTNode* pos = phead->next;
	while (pos != phead)
	{
		if (pos->val == x)
			return pos;
		pos = pos->next;
	}
	printf("û����ֵͬ�����Ҵ���\n");
	return 0;
}