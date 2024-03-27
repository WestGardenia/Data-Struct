#define _CRT_SECURE_NO_WARNINGS
#include"Function.h"



static STList* BuyNewnode(STListdata newdata) //�����½�㺯��
{
	STList* newnode = (STList*)malloc(sizeof(STList));
	// assert(newnode);	//��malloc�����������½����assert����
	if (newnode == NULL)
	{
		printf("error!!!");
		exit(-1);
	}
	newnode->data = newdata;
	newnode->next = NULL;//����������newnodeʵ������һ���ṹ��ָ�룬�á�->�����Ŷ�newnodeָ��Ľṹ���е��������ָ������г�ʼ��
	return newnode;
}

void STListPrint(STList* phead)
{
	// ��ӡ����˼·��
	// 1������һ���µĽ�㣬��ʼ��Ϊͷ�ڵ�
	// 2��������ָ���ͷ��ʼ���������������õ������ݴ�ӡ����
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
	//ͷ�巨˼·��
	// 1�������µĽ��
	// 2�����½ڵ�ָ��ͷ�ڵ㣻
	// 3�����½ڵ����µ�ͷ�ڵ�

	// ע��㣺���ں����д����ı�������ʱ����������������ʱ�������溯�����������١�
	// ��ͷ�巨������ͷɾ��������Դ����ͷ�������������ı䡣����������Ҫ��ͷ���ĵ�ַ���뺯����Ҳ���ǽ�����ָ����Ϊ�βδ���
	STList* newnode = BuyNewnode(newdata);
	newnode->next = *pphead;//���½���nextָ��ָ��ԭͷ�ڵ㣬����½��Ĳ������
	*pphead = newnode;//���½��ĵ�ַ��ͷ�ڵ㣬����½����ͷ�ڵ�Ĳ���
}

void STListPopHead(STList** pphead)//����--ͷɾ��
{
	//ͷɾ��˼·��
	// 1���ҵ��ڶ�����㣬����¼�¸ý���ַ
	// 2�����ý����ͷ���
	// 3��free���½��
	assert(*pphead);
	// �����pphead��������Ϊ����������Ҫ��pphead�����ã��Է������ָ���ǿ�ָ�룬�Ӷ��γ�Ұָ��
	STList* current = (*pphead)->next;
	free(*pphead);
	*pphead = current;
}

void STListPushBack(STList** pphead, STListdata newdata)//����--β�巨
{
	// β�巨˼·��
	// 1���ҵ�β��㣬������һ���µĽ��
	// 2����β����nextָ���½�㣬�����½���nextָ��NULL
	// 3���������ڵ��ǿս�㣬��ֱ�ӽ���ͷ�巨
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

void STListPopBack(STList** pphead)//����--βɾ��
{
	// βɾ��˼·��
	// 1�������ҵ������������һ���ڵ㣬�Լ�����һ���ڵ㡣
	// 2����¼�µ����ڶ����ڵ㣬������nextָ��NULL
	// 3��free��β���
	assert(*pphead);
	
	// �������ֻ��һ����㣬��ʱ����ͷɾ����
	// �������βɾ������whileѭ���оͲ���ִ�У�Ҳ����˵preview��ѭ����������NULL��
	// �ͻ���preview->next = NULL;���д��봦���ʿ�ָ��
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
			// ����preview�ڳ�ʼ��ʱΪNULL���������ﲻ��ʹ�����е�nextָ�롣��������൱�ڽ������˿�ָ�룬�γ�Ұָ��
			// ���⣬һ��ѭ������current�ͻᱻ��next��ĵ�ַ���ǣ�����Ҳ����Ҫʹ��preview��next
			current = current->next;
		}
		preview->next = NULL;
		free(current);
	}
}

STList* STListFind(STList* phead, int position)// ����--���Ҷ�Ӧλ�õĽ��
{
	// �������˼·��
	// 1����ͷ��㿪ʼ����������position��
	// 2���ҵ���Ӧ�Ľ�㣬�����ý�㷵��
	//
	while (position)
	{
		if (phead->next)// �жϴ����λ���Ƿ��������д��ڣ���������ڣ��򷵻�error position
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

void STListInsert(STList** pphead, STListdata newdata, STList** pos)// ����--���м�ָ��λ��(posָ�봦)�����
{
	// �м����˼·��
	// 1������һ���½��newnode����Ҫ��������ݴ����½����
	// 2���жϲ����λ���ǲ���ͷ���
	// 3�������ͷ��㣬�ͽ���ͷ�巨
	// 4���������ͷ��㣬�ҵ�pos����next��㣬�������¼��������Ϊcurrent����pos����nextָ���½��newnode����newnode��next���ָ��current
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

void STListDelete(STList** pos)// ����--���м�ָ��λ��(posָ�봦)��ɾ��
{
	// �м�ɾ��˼·��
	// 1���ж�Ҫɾ����λ���ǲ���β��㡣�����β��㣬����
	// 2���������ͷ��㡣�����ҵ�pos���ĺ�һ����㣬��Ϊcurrent��
	// 3����current��next��㸳��pos��next���
	// 4��free��pos->next���
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