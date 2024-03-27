#define _CRT_SECURE_NO_WARNINGS

#include"Function.h"

void test_1()	//链表用例测试
{
	STList* plist = NULL;// 定义头结点
	STList* pos_1 = NULL;// 定义中间自由结点
	STList* pos_2 = NULL;// 定义中间自由结点

	STListPushHead(&plist, 1);
	STListPushHead(&plist, 2);
	STListPushHead(&plist, 3);
	STListPushHead(&plist, 4);
	STListPushHead(&plist, 5);
	STListPushHead(&plist, 6);
	STListPushHead(&plist, 7);
	STListPushHead(&plist, 8);
	STListPushHead(&plist, 9);
	STListPushHead(&plist, 10);
	printf("头插法测试用例：");
	STListPrint(plist);  
	// 头插法测试

	STListPopHead(&plist);
	printf("头删法测试用例：");
	STListPrint(plist);
	// 头删法测试

	STListPushBack(&plist, 11);
	printf("尾插法测试用例：");
	STListPrint(plist);
	// 尾插法测试

	STListPopBack(&plist);
	printf("尾删法测试用例：");
	STListPrint(plist);
	// 尾删法测试

	pos_1= STListFind(plist, 5);
	STListInsert(&plist, 100, &pos_1);
	printf("中间插入测试用例：");
	STListPrint(plist);

	pos_2= STListFind(plist, 1);
	STListDelete(&pos_2);
	printf("中间删除测试用例：");
	STListPrint(plist);
}

void test_2()
{
	struct Single_List* plist = NULL;

	STListPushHead(&plist, 1);
	STListPushHead(&plist, 2);
	STListPushHead(&plist, 3);
	STListPushHead(&plist, 4);
	STListPushHead(&plist, 5);
	STListPushHead(&plist, 6);
	STListPushHead(&plist, 7);
	STListPushHead(&plist, 8);
	STListPushHead(&plist, 9);
	STListPushHead(&plist, 10);

	printf("翻转之前链表：");
	STListPrint(plist);

	printf("第1次翻转：");
	STList* plist_1 = STListFilp_1(plist);
	STListPrint(plist_1);

	printf("第2次翻转：");
	STList* plist_2 = STListFilp_2(plist_1);
	STListPrint(plist_2);

	printf("中间节点的数值是：");
	struct Single_List* Node_Middle = STList_MiddleNode(plist);
	printf("%d\n", Node_Middle->data);

}

void test_3()
{
	STList* plist_1 = NULL;
	STList* plist_2 = NULL;
	STList* plist_3 = NULL;

	STListPushBack(&plist_1, 1);
	STListPushBack(&plist_1, 2);
	STListPushBack(&plist_1, 43);
	STListPushBack(&plist_1, 54);
	STListPushBack(&plist_1, 57);
	STListPushBack(&plist_1, 76);
	STListPushBack(&plist_1, 79);
	STListPushBack(&plist_1, 88);
	STListPushBack(&plist_1, 99);
	STListPushBack(&plist_1, 100);

	STListPushBack(&plist_2, 5);
	STListPushBack(&plist_2, 24);
	STListPushBack(&plist_2, 58);
	STListPushBack(&plist_2, 64);
	STListPushBack(&plist_2, 75);
	STListPushBack(&plist_2, 80);
	STListPushBack(&plist_2, 94);
	STListPushBack(&plist_2, 814);

	STListPrint(plist_1);
	STListPrint(plist_2);

	plist_3 = STList_Merge(plist_1, plist_2);
	STListPrint(plist_3);

}

void test_4() // 判断回文结构
{
	STList* plist = NULL;// 定义头结点

	STListPushHead(&plist, 1);
	STListPushHead(&plist, 2);
	STListPushHead(&plist, 3);
	STListPushHead(&plist, 4);
	STListPushHead(&plist, 5);

	STListPushHead(&plist, 6);

	STListPushHead(&plist, 5);
	STListPushHead(&plist, 4);
	STListPushHead(&plist, 3);
	STListPushHead(&plist, 2);
	STListPushHead(&plist, 1);

	bool whether = CheckPalindrom(plist);

	printf("%d/n", whether);


}

int main()
{
	//test_1();
	test_2();
	//test_3();
	test_4();
	return 0;
}
