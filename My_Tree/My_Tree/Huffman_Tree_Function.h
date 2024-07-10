#define _CRT_SECURE_NO_WARNINGS

typedef struct Huffman_Tree_Node H_TreeNode;

struct Huffman_Tree_Node {
	int weight;
	int	lchild;
	int rchild;
	int parent;
};

typedef struct Huffman_Tree Huffman_Tree;

struct Huffman_Tree {
	H_TreeNode* data;
	int length;
};

void Sort(int* weight, int length);	// ���ַ���Ȩֵ�����������

Huffman_Tree* Huffman_TreeInit(int* weight, int length);

int* Select(Huffman_Tree* HT);	// ѡ��Ȩֵ��������С������ֵ

Huffman_Tree* Huffman_Treecreative(Huffman_Tree* HT);	// ������������

void Huffman_Tree_pre(Huffman_Tree* HT,int index);	// ���������������