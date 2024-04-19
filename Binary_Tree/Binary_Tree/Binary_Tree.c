#define _CRT_SECURE_NO_WARNINGS
#include"Tree.h"

void TreeCreative(TreeNode** RootNode,char* data,int* index)	// ����������
{
	if ((*RootNode) == NULL)
	{
		exit(-1);
	}
	// ���ڴ����������ĺ������β�RootNode�ṹ�ڲ�����˸ı䡣������Ҫ�������ָ��
	char ch;
	ch = data[*index];
	(*index)++;	// �����ǵݹ���ã�����Ҫ���ڵݹ�ʱ�ı�index����λ�ã��ͱ��봫��index��ָ��
	if (ch == '#')
	{
		// �������롮#��ʱ���ڵ�Ϊ�ս��
		*RootNode = NULL;
	}
	else
	{
		// �ݹ鶨�����������������ϣ����������ڵ�����Һ��ӽ��Ҳ��һ������
		*RootNode = (TreeNode*)malloc(sizeof(TreeNode));
		(*RootNode)->data = ch;
		TreeCreative(&((*RootNode)->LChild),data,index);
		TreeCreative(&((*RootNode)->RChild),data,index);
	}
}

void preOrder(TreeNode* RootNode)	// ������--�������--��-��-��
{
	if (RootNode == NULL)
	{
		return;
	}
	printf("%c->", RootNode->data);
	preOrder(RootNode->LChild);
	preOrder(RootNode->RChild);
}

void inOrder(TreeNode* RootNode)	// ������--�������--��-��-��
{
	if (RootNode == NULL)
	{
		return;
	}
	inOrder(RootNode->LChild);

	printf("%c->", RootNode->data);
	
	inOrder(RootNode->RChild);
}

void postOrder(TreeNode* RootNode)		// ������--�������--��-��-��
{
	if (RootNode == NULL)
	{
		return;
	}
	postOrder(RootNode->LChild);

	postOrder(RootNode->RChild);

	printf("%c->", RootNode->data);
}