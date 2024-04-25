#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

// ��������һ�ַ����Ե����ݽṹ
// ���Խṹ����ǰ���ͺ�̵ġ�����������ֻ�к�̣�û��ǰ��
// ��������������������һ�ֽ���ģ����������Խṹ
// ����һ������˵��������� 2n ����㡣��ô������ n-1 ��ָ��ָ����Щ���
// ��ô��ʣ�µ�Ҷ�ӽ���У�����ʣ�� 2n - �� n - 1 �� ��ָ��û��ʹ�á����� n + 1 ��ָ��ָ���������ǰ��
// �������ν������������

//          A
//     B		C
// D		E
// ����������һ�Ŷ�������������������Ϊ��
// D	B	E	A	C
// ����������õ��Ľ������Ϊһ�����Խṹ��������������ô���ǿ��Եõ�����һ������˫����ʵ��Ϊ���������������Խṹ
// NULL	<----- D <----> B <----> E <----> A <----> C ----> NULL
// ������һ�����ݽṹ�� D ��ǰ��Ϊ��ָ�루�������ڱ�λ��ͷ��㣩
//						E �ĺ��Ϊ��ָ�룬��Ϊ����Ľ�β��־
// ������Щ����ָ��ǰ���ͺ�̵�ָ�����ԭ����������ΪҶ�ӽڵ��û�����ϵĿյ����Һ��ӽڵ㣨������ n+1 ��ָ�룩
// ������һ���߼��ṹ��Ϊ��������ṹΪ��������ݽṹ�������
// 

typedef struct Thread_TreeNode Thread_TreeNode;

struct Thread_TreeNode {
	char data;
	Thread_TreeNode* LChild;	// �������ӽ��
	Thread_TreeNode* RChild;	// �����Һ��ӽڵ�
	int LFlag;	// �ж����ӽ��ָ��λ��
	int RFlag;	// �ж��Һ��ӽ��ָ��λ��

};

void Thread_TreeCreative(Thread_TreeNode** RootNode, char* data, int* index);	// ����������

void InThread_Tree(Thread_TreeNode* RootNode, Thread_TreeNode** pre);	// ������������

void PreOrder_2(Thread_TreeNode* RootNode);	// ������--�������--��-��-��

void InOrder_2(Thread_TreeNode* RootNode);	// ������--�������--��-��-��

void PostOrder_2(Thread_TreeNode* RootNode);		// ������--�������--��-��-��
