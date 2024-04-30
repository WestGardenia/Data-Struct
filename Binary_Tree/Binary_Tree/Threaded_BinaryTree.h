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
//     B		 C
// D	  E	  F		G	
// ����������һ�Ŷ���������
// ����������Ϊ��
// A	B	D	E	C	F	G
// ����������Ϊ��
// D	B	E	A	F	C	G
// ����������Ϊ��
// D	E	B	F	G	C	A
// ����������õ��Ľ������Ϊһ�����Խṹ��������������ô���ǿ��Եõ�����һ������˫����ʵ��Ϊ���������������Խṹ
// NULL	<----- D <----> B <----> E <----> A <----> C ----> NULL
// ������һ�����ݽṹ�� D ��ǰ��Ϊ��ָ�루�������ڱ�λ��ͷ��㣩
//						E �ĺ��Ϊ��ָ�룬��Ϊ����Ľ�β��־
// ������Щ����ָ��ǰ���ͺ�̵�ָ�����ԭ����������ΪҶ�ӽڵ��û�����ϵĿյ����Һ��ӽڵ㣨������ n+1 ��ָ�룩
// �յ�RChildָ�����ĺ�̡������ĳ���ڵ��RChild�д�ŵ����Һ��ӽڵ㣬����RFlag��0���෴�������ŵ�������ڵ�ĺ�̣���RFlag��1
// �յ�LChildָ������ǰ���������ĳ���ڵ��LChild�д�ŵ������ӽڵ㣬����LFlag��0���෴�������ŵ�������ڵ��ǰ������LFlag��1
// 
// ������һ���߼��ṹ��Ϊ��������ṹΪ��������ݽṹ�������
// 

typedef struct Thread_TreeNode Thread_TreeNode;

struct Thread_TreeNode {
	char data;
	Thread_TreeNode* LChild;	// �������ӽ��
	Thread_TreeNode* RChild;	// �����Һ��ӽڵ�
	Thread_TreeNode* Parent;	// ����˫�׽��----�����������
	int LFlag;	// �ж����ӽ��ָ��λ��
	int RFlag;	// �ж��Һ��ӽ��ָ��λ��

};

void Thread_TreeCreative(Thread_TreeNode** RootNode, char* data, int* index, Thread_TreeNode* parent);	// ����������

void InThread_Tree(Thread_TreeNode* RootNode, Thread_TreeNode** pre);	// ������������

void PreThread_Tree(Thread_TreeNode* RootNode, Thread_TreeNode** pre);	// ����������--�������--��-��-��

//Thread_TreeNode* Pre_GetFirst(Thread_TreeNode* RootNode);
// ����Ҫȥȡ��㺯��������Ϊͷ�����Ƕ����������

Thread_TreeNode* Pre_GetNext(Thread_TreeNode* RootNode);

void InThread_Tree(Thread_TreeNode* RootNode, Thread_TreeNode** pre);	// ����������--�������--��-��-��

Thread_TreeNode* In_GetFirst(Thread_TreeNode* RootNode);

Thread_TreeNode* In_GetNext(Thread_TreeNode* RootNode);

void PostThread_Tree(Thread_TreeNode* RootNode, Thread_TreeNode** pre);	// ����������--�������--��-��-��

Thread_TreeNode* Post_GetFirst(Thread_TreeNode* RootNode);

Thread_TreeNode* Post_GetNext(Thread_TreeNode* RootNode);
