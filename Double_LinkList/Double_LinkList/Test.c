#include"Function.h"

void test1()
{
	LTNode* plist = ListInit();

	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPushBack(plist, 6);
	ListPushBack(plist, 7);
	ListPushBack(plist, 8);
	ListPushBack(plist, 9);
	printf("β�����:");
	ListPrint(plist);	// β�����

	ListPopBack(plist);	// βɾ����
	ListPopBack(plist);	// βɾ����
	ListPopBack(plist);	// βɾ����
	ListPopBack(plist);	// βɾ����
	ListPopBack(plist);	// βɾ����
	printf("βɾ����:");
	ListPrint(plist);

	ListPushFront(plist, 1); // ͷ�����
	ListPushFront(plist, 2); // ͷ�����
	ListPushFront(plist, 3); // ͷ�����
	ListPushFront(plist, 4); // ͷ�����
	ListPushFront(plist, 5); // ͷ�����
	ListPushFront(plist, 6); // ͷ�����
	ListPushFront(plist, 7); // ͷ�����
	ListPushFront(plist, 8); // ͷ�����
	ListPushFront(plist, 9); // ͷ�����
	printf("ͷ�����:");
	ListPrint(plist);

	ListPopFront(plist); // ͷɾ����
	ListPopFront(plist); // ͷɾ����
	ListPopFront(plist); // ͷɾ����
	ListPopFront(plist); // ͷɾ����
	ListPopFront(plist); // ͷɾ����
	ListPopFront(plist); // ͷɾ����
	ListPopFront(plist); // ͷɾ����
	printf("ͷɾ����:");
	ListPrint(plist);

	LTNode* findnode = ListFind(plist, 1);
	assert(findnode);
	printf("���Ҳ��ԣ�%d", findnode->val);
}


int main()
{
	test1();
} 