#define _CRT_SECURE_NO_WARNINGS

#include"Leetcode_OJ.h"

int Tree_size(TreeNode* RootNode)	// ����������ڵ����
{
	if (RootNode == NULL)
		return 1;
	else
		return 1 + Tree_size(RootNode->lchild) + Tree_size(RootNode->rchild);
}

int Tree_depth(TreeNode* RootNode)	// ���������������
{
	if (RootNode == NULL)
		return 0;
	int rightdepth = Tree_depth(RootNode->rchild);
	int leftdepth = Tree_depth(RootNode->lchild);

	return rightdepth > leftdepth ? rightdepth + 1 : leftdepth + 1;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
        return true;
    else if (p == NULL && q != NULL)
        return false;
    else if (p != NULL && q == NULL)
        return false;
    else if (q->data != p->data)
        return false;

    else
    {
        return  isSameTree(p->lchild, q->lchild) && isSameTree(p->rchild, q->rchild);
    }
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (root == NULL)
    {
        return false;
    }
    if (isSameTree(root, subRoot))
    {
        return true;
    }
    return isSubtree(root->lchild, subRoot) || isSubtree(root->rchild, subRoot);
}

int height(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    // ���ú���������Ե����ϣ��ķ�ʽ������������ÿ�����������������ĸ߶ȼ��㲢����߶Ȳ
    // �������Ա����Զ����µķ����У���ζ��ڸ߶Ȳ������ظ�����
    // ʱ�临�Ӷ�ΪO��N��
    int left = height(root->lchild);
    int right = height(root->rchild);

    if (left == -1 || right == -1 || fabs(right - left) > 1)
        // �������ĳ��������ƽ�⣬�򷵻�-1
        return -1;
    else
        // �����ƽ�⣬�ͷ��������������߶�ֵ+1
        return (int)fmax(left, right) + 1;
}

bool isBalanced(struct TreeNode* root) {
    return height(root) >= 0;
}

TreeNode* create_Tree(char* str, int* index)
{
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));

    if (str == NULL)
    {
        return NULL;
    }

    else
    {
        if(str[*index] != '#')
        {
            root->data = str[*index];
            (*index)++;
            root->lchild = create_Tree(str, index);
            root->rchild = create_Tree(str, index);
            return root;
        }
        else
        {
            root = NULL;
            (*index)++;
        }
    }
}

int Tree_Ksize(TreeNode* root,int k)
{
    if (root == NULL)
        return 0;
    if (k == 1)
        return 1;
    else
        return Tree_Ksize(root->lchild, k - 1) + Tree_Ksize(root->rchild, k - 1);
}

TreeNode* TreeNode_Find(TreeNode* root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
        return root;

    root = TreeNode_Find(root->lchild, key);
    if (root)
        return root;

    root = TreeNode_Find(root->rchild, key);
    if (root)
        return root;

    return NULL;
}

void Destory_Tree(TreeNode* root)
{
    if (root == NULL)
        return;
    else
    {
        Destory_Tree(root->lchild);
        Destory_Tree(root->rchild);
        free(root);
    }
}