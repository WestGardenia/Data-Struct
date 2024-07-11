#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<math.h>



// 并查集在大多数场合下的作用是判断元素所处的集合
// 所以使用双亲表示法能够有效的快速的找到某个元素的根结点

typedef struct GatherNode G_Node;

struct GatherNode {
	char data;
	int parent;
};

typedef struct Gather Gather;

struct Gather {
	G_Node* array;
};


Gather* InitGather(Gather* G, char* element,int length);	// 并查集初始化

G_Node Find_RootNode(Gather* G, G_Node* element);	// 查找并查集中的根结点

G_Node Find_RootNode_Optimize(Gather* G, G_Node* element);	// 查找并查集中的根结点--优化版
// 原理 ：
// 在找到对应元素根节点之后，将这个元素的所有的parent全部连接到根节点上
// 即在查找操作时进行路径压缩

void Union(Gather* G, int x1, int x2);	// 合并并查集元素

void Union_Optimize(Gather* G, int x1, int x2);	// 合并并查集元素--优化
// 优化原理：
// 对于并查集的操作来说，时间复杂度和生成的树的深度有直接关系
// 所以在每次进行并操作时，只需要确保让结点数更少的小树并在大树上，就可以限制生成的树的深度
// 将根节点的parent的绝对值表示该棵树的结点数，比较的时候用abs取绝对值进行比较
// 时间复杂度为O(log2n)
//