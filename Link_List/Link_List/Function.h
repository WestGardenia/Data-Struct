#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>  // ����bool���͵�ͷ�ļ�

typedef int STListdata;

typedef struct Single_List STList;

typedef struct Single_List
{
	STListdata data;
	STList* next;
}STList;


void STListPrint(STList* phead);//��ӡ����

void STListPushHead(STList** pphead, STListdata newdata);//����--ͷ�巨

void STListPopHead(STList** pphead);//����--ͷɾ��

void STListPushBack(STList** pphead, STListdata newdata);//����--β�巨

void STListPopBack(STList** pphead);//����--βɾ��

STList* STListFind(STList* phead, int position);// ����--���Ҷ�Ӧλ�õĽ��

void STListInsert(STList** pphead, STListdata newdata, STList** pos);// ����--���м�ָ��λ��(posָ�봦)�����

void STListDelete(STList** pos);// ����--���м�ָ��λ��(posָ�봦)��ɾ��

//  ----------------------------------------------------------------------------------------------------------------------------------------------

STList* STListFilp_1(STList* phead);// ����--ԭ�ط�ת����һ

STList* STListFilp_2(STList* phead);// ����--ԭ�ط�ת������

STList* STList_MiddleNode(STList* phead);// ����--Ѱ�������м�ڵ�

STList* STList_Merge(STList* phead_1, STList* phead_2);// ����--�鲢�������������ϳ�һ���µ���������

STList* STList_Partition(STList* phead, int x);// ����--�������е����ݰ��մ���Ĳ�����СΪ��׼��������Ҫ�󣺴���ں��棬С����ǰ�棬�������˳�򲻱�
// ʾ����2 3 6 9 15 5 4 7 8 5 -- ����     7 -- x    ������������2 3 6 5 4 5 7 9 15

bool CheckPalindrom(STList* phead);  // �ж������Ƿ�Ϊ���Ľṹ
// ���Ľṹ��1->2->3->3->2->1  ����  1->2->3->2->1

STList* getIntersectionNode_2(STList* phead_1, STList* plist_2);  // �����������㡣����н��㣬�򷵻ؽ���֮����������û�н��㣬�򷵻�NULL
// ˼·һ���������
// ��A�����ÿһ�������B������бȽϣ�ֻҪ����ͬ�ģ��ͷ��ص�һ�����������Ľ���
// �Է������г���ǰ����ͬ�Ľṹ��Ҫ���ڳɹ�ͨ���ȽϵĽ����в���
// 
// ˼·����
// 1���������������ҵ����Ǹ��Ե�β��㲢���бȽϡ��������ͬ�ģ���������һ��β����ǽ��㡣����¼�����α����õ��Ĵ���
// 2��ͨ�������õ��Ĵ�����������������������߲�Ĳ�����Ȼ��ʼ��������ͬ������
//

bool hasCycle(STList* phead);	// �ж������Ƿ�Ϊ���νṹ
// ���ڿ���ָ���ڴ��������е�����
// 1��Ϊʲô slow = 1 �� fast = 2 һ�����ڻ��������� �᲻���ڻ��д����Ȼ����Զ������
// ���ۣ�һ��������
// ֤����
//		1��slow��fast��һ����fast�Ƚ�������ʱslow�����뻷ǰ�����һ��
//		2����slow�뻷ʱ����������֮����ΪN��ÿ�ε���������fast��slow֮��Ĳ���֮��Ϊ1����ʱ����֮��ľ����ΪN-1
//		3��������������µĿ���ָ���Ȼ���ڻ�������
// 
// 2��ͬʱ��Ҳ�ܿ�������fast��slow�����Ϊ1ʱ��ÿ�ε���֮��ľ����Ͳ���1����n����ʱֻ�����뻷ʱ�����Ϊn��������ʱ����������
//

STList* detectCycle(STList* phead);		// ���ش���������뻷�ڽ��
// ����һ��
// ǰ�᣺��֪�����������fast = 2��slow = 1
// ���ۣ�һ��ָ��������㿪ʼ�ߣ���һ��ָ�������ͷ��ʼ�ߣ����ǻ����뻷������
// ֤����
//		�ǻ�֮ǰ����β����ΪL������ΪC����������뻷�ھ���ΪX
//		׷���жϴ������������
//		1����ָ��·�̣�S1 = L + X
//		2����ָ��·�̣�S2 = L + NC + X
//		����S2 = 2 * S1
//		����
//		2*(L+X) = L+NC+X
//	->  L+X = NC
//	->  L = NC - X
//  ->  L = (N-1)C + C-X
//		����C-X���Կ��������㵽�뻷���·�̲�
//		(N-1)C ���Կ�����ָ���ڻ����Ƶ�Ȧ��
// 
// ��������
// �����������һ������������֮������ӽ⿪����ʱ�ͽ�����ת���ɵ���������Ĺ����������
//


typedef struct Node RandonList;
struct Node {
	int val;
	RandonList* next;
	RandonList* random;
};
RandonList* copyRandomList(RandonList* phead);	// �������ָ��ĸ���
// ��Ŀ������
// ����һ������Ϊ n ������ÿ���ڵ����һ���������ӵ����ָ�� random ����ָ�����ָ�������е��κνڵ��սڵ㡣
// ��������������������Ӧ�������� n �� ȫ�½ڵ���ɣ�����ÿ���½ڵ��ֵ����Ϊ���Ӧ��ԭ�ڵ��ֵ��
// �½ڵ�� next ָ��� random ָ��Ҳ��Ӧָ���������е��½ڵ㣬��ʹԭ����͸��������е���Щָ���ܹ���ʾ��ͬ������״̬��
// ���������е�ָ�붼��Ӧָ��ԭ�����еĽڵ㡣
// 
// ������������ڣ�ÿ�ο�����ֻ�ܵõ�ԭ����Ӧrandom���ĵ�ַ�������㲻�ܸ��������ַ�õ������ڵ��random���Ϳ����ڵ�֮������λ��
// 
// ˼·��
// 1��������������������ÿ����㸴��һ�ݣ�������ԭ�ڵ�֮��
// 2����ʱ�������ڵ��random����ԭ����random��next
// 3����󽫿����Ľ�������ԭ�����ϲ��������õ�һ���µ�����
//
