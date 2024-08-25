#define _CRT_SECURE_NO_WARNINGS

#include"Leetcode_OJ.h"

int Tree_size(TreeNode* RootNode)	// 计算二叉树节点个数
{
	if (RootNode == NULL)
		return 1;
	else
		return 1 + Tree_size(RootNode->lchild) + Tree_size(RootNode->rchild);
}

int Tree_depth(TreeNode* RootNode)	// 计算二叉树最大深度
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