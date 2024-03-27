#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>  // 定义bool类型的头文件

typedef int STListdata;

typedef struct Single_List STList;

typedef struct Single_List
{
	STListdata data;
	STList* next;
}STList;


void STListPrint(STList* phead);//打印链表

void STListPushHead(STList** pphead, STListdata newdata);//链表--头插法

void STListPopHead(STList** pphead);//链表--头删法

void STListPushBack(STList** pphead, STListdata newdata);//链表--尾插法

void STListPopBack(STList** pphead);//链表--尾删法

STList* STListFind(STList* phead, int position);// 链表--查找对应位置的结点

void STListInsert(STList** pphead, STListdata newdata, STList** pos);// 链表--从中间指定位置(pos指针处)后插入

void STListDelete(STList** pos);// 链表--从中间指定位置(pos指针处)后删除

//  ----------------------------------------------------------------------------------------------------------------------------------------------

STList* STListFilp_1(STList* phead);// 链表--原地翻转方法一

STList* STListFilp_2(STList* phead);// 链表--原地翻转方法二

STList* STList_MiddleNode(STList* phead);// 链表--寻找链表中间节点

STList* STList_Merge(STList* phead_1, STList* phead_2);// 链表--归并两个有序链表，合成一个新的有序链表

STList* STList_Partition(STList* phead, int x);// 链表--将链表中的数据按照传入的参数大小为标准进行排序，要求：大的在后面，小的在前面，但是相对顺序不变
// 示例：2 3 6 9 15 5 4 7 8 5 -- 链表     7 -- x    函数最后输出：2 3 6 5 4 5 7 9 15

bool CheckPalindrom(STList* phead);  // 判断链表是否为回文结构
// 回文结构：1->2->3->3->2->1  或者  1->2->3->2->1

STList* getIntersectionNode_2(STList* phead_1, STList* plist_2);  // 求两个链表交点。如果有交点，则返回交点之后的链表；如果没有交点，则返回NULL
// 思路一：暴力求解
// 将A链表的每一个结点与B链表进行比较，只要有相同的，就返回第一个符合条件的交点
// 以防链表中出现前后相同的结构，要对于成功通过比较的结点进行测试
// 
// 思路二：
// 1、遍历两个链表，找到他们各自的尾结点并进行比较。如果有相同的，则至少有一个尾结点是交点。并记录下两次遍历得到的次数
// 2、通过遍历得到的次数并做差。将更长的链表先走差的步数。然后开始两个链表同步遍历
//

bool hasCycle(STList* phead);	// 判断链表是否为环形结构
// 对于快慢指针在带环链表中的问题
// 1、为什么 slow = 1 和 fast = 2 一定会在环中相遇？ 会不会在环中错过，然后永远遇不上
// 结论：一定会遇上
// 证明：
//		1、slow和fast，一定是fast先进环，此时slow走了入环前距离的一半
//		2、当slow入环时，假设两者之间差距为N。每次迭代，由于fast和slow之间的步长之差为1，此时两者之间的距离差为N-1
//		3、所以这种情况下的快慢指针必然能在环中相遇
// 
// 2、同时，也能看出，当fast和slow步长差不为1时，每次迭代之后的距离差就不是1而是n，此时只有在入环时距离差为n的整数倍时，才能相遇
//

STList* detectCycle(STList* phead);		// 返回带环链表的入环口结点
// 方法一：
// 前提：已知链表带环且有fast = 2和slow = 1
// 结论：一个指针从相遇点开始走，另一个指针从链表头开始走，他们会在入环口相遇
// 证明：
//		记环之前的拖尾长度为L，环长为C，相遇点距入环口距离为X
//		追击判断带环问题过程中
//		1、慢指针路程：S1 = L + X
//		2、快指针路程：S2 = L + NC + X
//		由于S2 = 2 * S1
//		所以
//		2*(L+X) = L+NC+X
//	->  L+X = NC
//	->  L = NC - X
//  ->  L = (N-1)C + C-X
//		其中C-X可以看作相遇点到入环点的路程差
//		(N-1)C 可以看作快指针在环中绕的圈数
// 
// 方法二：
// 将相遇点的下一个结点和相遇点之间的连接解开，此时就将问题转化成的两个链表的公共结点问题
//


typedef struct Node RandonList;
struct Node {
	int val;
	RandonList* next;
	RandonList* random;
};
RandonList* copyRandomList(RandonList* phead);	// 随机链表指针的复制
// 题目描述：
// 给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。
// 构造这个链表的深拷贝。深拷贝应该正好由 n 个 全新节点组成，其中每个新节点的值都设为其对应的原节点的值。
// 新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。
// 复制链表中的指针都不应指向原链表中的节点。
// 
// 深拷贝的问题在于：每次拷贝你只能得到原结点对应random结点的地址，但是你不能根据这个地址得到拷贝节点的random结点和拷贝节点之间的相对位置
// 
// 思路：
// 1、遍历整个复杂链表，将每个结点复制一份，并插入原节点之后
// 2、此时，拷贝节点的random就是原结点的random的next
// 3、最后将拷贝的结点从整个原链表上拆下来，得到一个新的链表
//
