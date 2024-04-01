#include"Function.h"

void test1()
{
	LTNode* plist = ListInit(); // ³õÊ¼»¯Á´±í

	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPushBack(plist, 6);
	ListPushBack(plist, 7);
	ListPushBack(plist, 8);
	ListPushBack(plist, 9);
	printf("Î²²å²âÊÔ:");
	ListPrint(plist);	// Î²²å²âÊÔ

	ListPopBack(plist);	// Î²É¾²âÊÔ
	ListPopBack(plist);	// Î²É¾²âÊÔ
	ListPopBack(plist);	// Î²É¾²âÊÔ
	ListPopBack(plist);	// Î²É¾²âÊÔ
	ListPopBack(plist);	// Î²É¾²âÊÔ
	printf("Î²É¾²âÊÔ:");
	ListPrint(plist);

	ListPushFront(plist, 1); // Í·²å²âÊÔ
	ListPushFront(plist, 2); // Í·²å²âÊÔ
	ListPushFront(plist, 3); // Í·²å²âÊÔ
	ListPushFront(plist, 4); // Í·²å²âÊÔ
	ListPushFront(plist, 5); // Í·²å²âÊÔ
	ListPushFront(plist, 6); // Í·²å²âÊÔ
	ListPushFront(plist, 7); // Í·²å²âÊÔ
	ListPushFront(plist, 8); // Í·²å²âÊÔ
	ListPushFront(plist, 9); // Í·²å²âÊÔ
	printf("Í·²å²âÊÔ:");
	ListPrint(plist);

	ListPopFront(plist); // Í·É¾²âÊÔ
	ListPopFront(plist); // Í·É¾²âÊÔ
	ListPopFront(plist); // Í·É¾²âÊÔ
	ListPopFront(plist); // Í·É¾²âÊÔ
	ListPopFront(plist); // Í·É¾²âÊÔ
	ListPopFront(plist); // Í·É¾²âÊÔ
	ListPopFront(plist); // Í·É¾²âÊÔ
	printf("Í·É¾²âÊÔ:");
	ListPrint(plist);

	LTNode* findnode = ListFind(plist, 1); // ²éÕÒ²âÊÔ
	assert(findnode);
	printf("²éÕÒ²âÊÔ£º%d\n", findnode->val);

	ListInsert(findnode, 100);
	printf("ÖĞ¼ä²åÈë²âÊÔ£º");
	ListPrint(plist); // ÖĞ¼ä²åÈë²âÊÔ

	ListErase(findnode);
	printf("ÖĞ¼äÉ¾³ı²âÊÔ£º");
	ListPrint(plist); // ÖĞ¼äÉ¾³ı²âÊÔ

	ListDestroy(plist);
	plist = NULL;
}


int main()
{
	test1();
} 