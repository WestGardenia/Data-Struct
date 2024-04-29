#define _CRT_SECURE_NO_WARNINGS
#include"Threaded_BinaryTree.h"

void Thread_TreeCreative(Thread_TreeNode** RootNode, char* data, int* index)	// ����������
{
	assert(*RootNode);
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
		// ��־λΪ1ʱ��ʾChildָ��ָ������������Ϊ1ʱ��ʾChildָ����ǰ�����ߺ��
		(*RootNode)->LFlag = 0;	
		(*RootNode)->RFlag = 0;
		Thread_TreeCreative(&((*RootNode)->LChild), data, index);
		Thread_TreeCreative(&((*RootNode)->RChild), data, index);
	}
}

void PreThread_Tree(Thread_TreeNode* RootNode, Thread_TreeNode** pre)	// ����������--�������--��-��-��
{
	// ����Ҫ������ĸ��ڵ㣨ÿ�εݹ鴫��Ķ��������ĸ���㣩����ǰ��������
	// ������Ҫ��ÿ������������õ���ǰһ������¼����
	if (RootNode)
	{
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
			// ��ʼ״̬����pre��㻹δ������
			(*pre)->RFlag = 1;
			(*pre)->RChild = RootNode;
		}
		(*pre) = RootNode;

		// ��������
		// ע���������������������
		// �����ڱ���֮ǰ�Ѿ��Զ������Ľṹ��Ҷ�ӽ������Һ��ӽ�㣩�����˸ı�
		// ������D	D->LChild = B
		//				B->LChild = D
		// ���������˽ṹ�ϵĸı�֮�󣬻��õݹ���õĺ���ѭ���ݹ飬�����ѭ��
		// ������Ҫ�ڵݹ�֮ǰ����һ�ζ���Flagֵ���ж�
		if (RootNode->LFlag == 0)
		{
			// ���LFlagֵΪ0�����ʾ�ý���LChild�ڵ��д�ŵ���ԭʼ�������еĽ�㣬����������֮���ǰ��
			PreThread_Tree(RootNode->LChild, pre);
		}
		PreThread_Tree(RootNode->RChild, pre);
	}
}

Thread_TreeNode* Pre_GetNext(Thread_TreeNode* RootNode)
{
	if (RootNode->RFlag == 1)
	{
		// �������ڵ��RFlag = 1�����ʾ�ý��ΪҶ�ӽڵ㲢��RChild�ڵ��д�ŵ���ĳ����̽�㣬��������������Ҫ��next���
		return RootNode->RChild;
	}
	else
	{
		// �������ڵ��RFlag = 0�����ʾ�ý������Һ��ӣ���ô�����������˳�򣨸����ң���next���ֻ���������
		if (RootNode->LFlag == 1)
		{
			// 1����LFlag = 1����ʱ����RootNode������Һ��Ӷ������ӣ�������Ϊǰ��ָ��ĳ��ǰ���ڵ㣩�������������˳�򣨸����ң�����ʱnext������RChild���
			return RootNode->RChild;
		}
		else
		{
			// 2����LFlag = 0����ʱ����RootNode��������ӡ���ô�����������˳�򣨸����ң�����ʱnext������LChild���
			return RootNode->LChild;
		}
	}
	// ����汾��
	//if (RootNode->RFlag == 1 || RootNode->LFlag == 0)
	//	return RootNode->RChild;
	//else
	//	return RootNode->LChild;
}

void InThread_Tree(Thread_TreeNode* RootNode, Thread_TreeNode** pre)	// ������������--�������--��-��-��
{
	// ����Ҫ������ĸ��ڵ㣨ÿ�εݹ鴫��Ķ��������ĸ���㣩����ǰ��������
	// ������Ҫ��ÿ������������õ���ǰһ������¼����
	if (RootNode)
	{
		// ������
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
			// ��ʼ״̬����pre��㻹δ������
			(*pre)->RFlag = 1;
			(*pre)->RChild = RootNode;
		}
		(*pre) = RootNode;

		// ������
		InThread_Tree(RootNode->RChild, pre);
	}
}

Thread_TreeNode* In_GetFirst(Thread_TreeNode* RootNode)
{
	assert(RootNode);
	// ѭ���汾��
	//while (RootNode->LFlag == 0)
	//{
	//	// �������������У��Ӹ��ڵ㿪ʼ������ֻҪ�����ĸ�����������ǰ������˵��������ṹ��û�б�����ͷ���
	//	// ͬʱ��Ҳ��Ҫע�⣬�����������γɵ������볣������ͬ������ӵ�еĵ�һ�����������ĸ���㣬������һ��������ͷ�ڵ�

	//	// ѭ�������У����LFlagֵΪ0�����ʾ�ý�������Ӷ���ǰ����ͬʱҲ˵���ý�㲻��Ҷ�ӽڵ�
	//	// ��������Ҷ�ӽڵ��Flagֵ������һ��Ϊ1���������������壩
	//	RootNode = RootNode->LChild;
	//}
	//return RootNode;
	
	// �����汾��
	if (RootNode->LFlag == 0)
	{
		return In_GetFirst(RootNode->LChild);
	}
}

Thread_TreeNode* In_GetNext(Thread_TreeNode* RootNode)
{
	// �������������У�RootNode����nextֻ�����������
	// 1����Ҷ�ӽڵ�
	//		��ʱRootNode->RFlag = 0
	// 2��Ҷ�ӽڵ��RChild����д�ŵ�ĳ����̽ڵ�
	//		��ʱRootNode->RFlag = 1
	assert(RootNode);
	if (RootNode->RFlag == 1)
	{
		// ���RFlagֵΪ1�����ʾ�ý���к�̽ڵ�next�Ҵ����RChild�У�����RChild��Ϊnext����
		return RootNode->RChild;
	}
	else
	{
		// ���RFlagֵΪ0�����ʾ�ý��ĺ����RChild�д�ŵĸýڵ���Һ��ӽ��
		return In_GetFirst(RootNode->RChild);
	}
}