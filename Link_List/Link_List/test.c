#define _CRT_SECURE_NO_WARNINGS

#include"Function.h"

void test_1()	//������������
{
	STList* plist = NULL;// ����ͷ���
	STList* pos_1 = NULL;// �����м����ɽ��
	STList* pos_2 = NULL;// �����м����ɽ��

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
	printf("ͷ�巨����������");
	STListPrint(plist);  
	// ͷ�巨����

	STListPopHead(&plist);
	printf("ͷɾ������������");
	STListPrint(plist);
	// ͷɾ������

	STListPushBack(&plist, 11);
	printf("β�巨����������");
	STListPrint(plist);
	// β�巨����

	STListPopBack(&plist);
	printf("βɾ������������");
	STListPrint(plist);
	// βɾ������

	pos_1= STListFind(plist, 5);
	STListInsert(&plist, 100, &pos_1);
	printf("�м�������������");
	STListPrint(plist);

	pos_2= STListFind(plist, 1);
	STListDelete(&pos_2);
	printf("�м�ɾ������������");
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

	printf("��ת֮ǰ����");
	STListPrint(plist);

	printf("��1�η�ת��");
	STList* plist_1 = STListFilp_1(plist);
	STListPrint(plist_1);

	printf("��2�η�ת��");
	STList* plist_2 = STListFilp_2(plist_1);
	STListPrint(plist_2);

	printf("�м�ڵ����ֵ�ǣ�");
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

void test_4() // �жϻ��Ľṹ
{
	STList* plist = NULL;// ����ͷ���

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
