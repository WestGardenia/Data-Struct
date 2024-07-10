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

void Sort(int* weight, int length);	// 对字符集权值数组进行排序

Huffman_Tree* Huffman_TreeInit(int* weight, int length);

int* Select(Huffman_Tree* HT);	// 选择权值数组中最小的两个值

Huffman_Tree* Huffman_Treecreative(Huffman_Tree* HT);	// 创建哈夫曼树

void Huffman_Tree_pre(Huffman_Tree* HT,int index);	// 哈夫曼树先序遍历