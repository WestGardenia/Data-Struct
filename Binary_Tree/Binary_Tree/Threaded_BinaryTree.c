#define _CRT_SECURE_NO_WARNINGS
#include"Threaded_BinaryTree.h"

void Thread_TreeCreative(Thread_TreeNode** RootNode, char* data, int* index)	// ����������
{
	char ch;
	ch = data[*index];
	(*index)++;
	if (ch == '#')
	{
		// ���壺����ַ��ǡ�#�������ʾ�ý��Ϊ��
		*RootNode = NULL;
	}
	else
	{
		*RootNode = (Thread_TreeNode*)malloc(sizeof(Thread_TreeNode));
		(*RootNode)->data = ch;
		// flagֵΪ1 ʱ����ʾ�ú��ӽڵ�ָ��ǰ���ڵ㣻ֵΪ0ʱ����ʾ�ú���ָ���̽ڵ�
		(*RootNode)->LFlag = 0;	
		(*RootNode)->RFlag = 0;
		Thread_TreeCreative(&((*RootNode)->LChild), &ch, index);
		Thread_TreeCreative(&((*RootNode)->RChild), &ch, index);
	}
}

void InThread_Tree(Thread_TreeNode* RootNode, Thread_TreeNode** pre)	// ������������
{
	// ����Ҫ������ĸ��ڵ㣨ÿ�εݹ鴫��Ķ��������ĸ���㣩����ǰ��������
	// ������Ҫ��ÿ������������õ���ǰһ������¼����
	if (RootNode)
	{
		InThread_Tree(RootNode->LChild, pre);
		// ������
		// ע�⣺���ӽڵ��ǰ����pre
		//		pre�ĺ�̽ڵ��Ǻ��ӽڵ�
		if (RootNode->LChild == NULL)
		{
			// ������ڵ������Ϊ�գ������ӽ��ָ��ǰ���ڵ�
			RootNode->LFlag = 1;
			RootNode->LChild = *pre;
		}
		if ((*pre) != NULL && (*pre)->RChild == NULL)
		{
			(*pre)->RFlag = 1;
			(*pre)->RChild = RootNode;
		}
		(*pre) = RootNode;

		InThread_Tree(RootNode->RChild, pre);
	}

}