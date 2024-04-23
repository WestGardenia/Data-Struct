#define _CRT_SECURE_NO_WARNINGS
#include"Tree.h"

void TreeCreative(TreeNode** RootNode,char* data,int* index)	// 创建二叉树
{
	if ((*RootNode) == NULL)
	{
		exit(-1);
	}
	// 由于创建二叉树的函数对形参RootNode结构内部造成了改变。所以需要传入二级指针
	char ch;
	ch = data[*index];
	(*index)++;	// 由于是递归调用，所以要想在递归时改变index索引位置，就必须传入index的指针
	if (ch == '#')
	{
		// 定义输入‘#’时，节点为空结点
		*RootNode = NULL;
	}
	else
	{
		// 递归定义左右子树（本质上，创建的树节点的左右孩子结点也是一棵树）
		*RootNode = (TreeNode*)malloc(sizeof(TreeNode));
		(*RootNode)->data = ch;
		(*RootNode)->flag = 0;
		TreeCreative(&((*RootNode)->LChild),data,index);
		TreeCreative(&((*RootNode)->RChild),data,index);
	}
}

void preOrder(TreeNode* RootNode)	// 二叉树--先序遍历--根-左-右
{
	if (RootNode == NULL)
	{
		return;
	}
	printf("%c->", RootNode->data);
	preOrder(RootNode->LChild);
	preOrder(RootNode->RChild);
}

void inOrder(TreeNode* RootNode)	// 二叉树--中序遍历--左-根-右
{
	if (RootNode == NULL)
	{
		return;
	}
	inOrder(RootNode->LChild);

	printf("%c->", RootNode->data);
	
	inOrder(RootNode->RChild);
}

void postOrder(TreeNode* RootNode)		// 二叉树--后序遍历--左-右-根
{
	if (RootNode == NULL)
	{
		return;
	}
	postOrder(RootNode->LChild);

	postOrder(RootNode->RChild);

	printf("%c->", RootNode->data);
}

// ——————————————————————————————————————————————————————————————————————————————————
void QueueInit(Queue* pq)	// 队列的定义
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}

void QueueDestroy(Queue* pq)	// 队列的销毁
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur->next != NULL)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}

void QueuePush(Queue* pq, Queue_DataType* x)	// 队列数据插入
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	newnode->data = x;
	newnode->next = NULL;
	if (QueueEmpty(pq))
	{
		pq->head = newnode;
		pq->tail = newnode;
	}
	else
	{
		newnode->next = pq->head;
		pq->head = newnode;
	}

}

void QueuePop(Queue* pq)	// 队列数据出队
 // 有BUG
{
	assert(pq);
	if (QueueEmpty(pq))
	{
		return;
	}
	if (pq->head == pq->tail)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* cur = pq->head;
		QNode* pre = pq->head;
		while (cur->next != NULL)
		{
			pre = cur;
			cur = cur->next;
		}
		free(cur);
		pre->next = NULL;
		pq->tail = pre;
	}
}

Queue_DataType* QueueFront(Queue* pq)	// 取队头数据
{
	assert(pq);
	if (QueueEmpty(pq))
	{
		return NULL;
	}
	return pq->head->data;
}

Queue_DataType* QueueBack(Queue* pq)		// 取队尾数据
{
	assert(pq);
	if (QueueEmpty(pq))
	{
		return NULL;
	}
	return pq->tail->data;
}

int QueueSize(Queue* pq)	// 计算队列长度
{
	assert(pq);
	int count = 0;
	QNode* cur = pq->head;
	while (cur != NULL)
	{
		cur = cur->next;
		count++;
	}
	return count;
}

// ——————————————————————————————————————————————————————————————————————
// 队列操作——Copy版本
//void QueueInit(Queue* pq)	// 队列的定义
//{
//	assert(pq);
//	pq->head = NULL;
//	pq->tail = NULL;
//}
//
//void QueueDestroy(Queue* pq)	// 队列的销毁
//{
//	assert(pq);
//	QNode* cur = pq->head;
//	while (cur != NULL)
//	{
//		QNode* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//	pq->head = pq->tail = NULL;
//}
//
//void QueuePush(Queue* pq, Queue_DataType* x)	// 队列数据插入
//{
//	assert(pq);
//	QNode* newnode = (QNode*)malloc(sizeof(QNode));
//	if (newnode == NULL)
//	{
//		printf("空间开辟--QueuePush函数出错!!!");
//		exit(-1);
//	}
//	newnode->data = x;
//	newnode->next = NULL;
//	if (pq->head == NULL)
//	{
//		// 如果队列中没有数据，即为空队列。此时将头结点和尾结点指向新malloc出来的结点
//		pq->head = pq->tail = newnode;
//	}
//	else
//	{
//		// 如果队列中有数据，就将新结点链接到tail的后面，并更新tail的位置，将tail指向newnode
//		pq->tail->next = newnode;
//		pq->tail = newnode;
//	}
//}
//
//void QueuePop(Queue* pq)	// 队列数据出队
//{
//	// 删除队头的数据，将head保存，更新head的位置，并且free掉旧的头节点
//	assert(pq);
//	// 为防止空队列删除造成越界访问，需要对队列是否为空进行判断
//	assert(!QueueEmpty(pq));
//	QNode* newhead = pq->head;
//	// 迭代head的位置
//	pq->head = pq->head->next;
//	free(newhead);
//	if (pq->head == NULL)
//	{
//		// 如果队列已经被删成了一个空队列。
//		// 由于头结点迭代时并没有对尾结点tail处理，此时tail就是一个野指针。需要将其置空
//		pq->tail = NULL;
//	}
//}
//
//Queue_DataType* QueueFront(Queue* pq)	// 取队头数据
//{
//	assert(pq);
//	// 为防止空队列删除造成越界访问，需要对队列是否为空进行判断
//	assert(!QueueEmpty(pq));
//
//	return pq->head->data;
//}
//
//Queue_DataType* QueueBack(Queue* pq)		// 取队尾数据
//{
//	assert(pq);
//	// 为防止空队列删除造成越界访问，需要对队列是否为空进行判断
//	assert(!QueueEmpty(pq));
//
//	return pq->tail->data;
//}
//
//int QueueSize(Queue* pq)	// 计算队列长度
//{
//	assert(pq);
//	if (pq->head == NULL)
//		return 0;
//	else
//	{
//		int count = 0;
//		QNode* cur = pq->head;
//		while (cur)
//		{
//			cur = cur->next;
//			count++;
//		}
//		return count;
//	}
//}

bool QueueEmpty(Queue* pq)	 //判断队列是否为空
{
	assert(pq);
	return pq->head == NULL;
}

void LevelTraverse(Queue* Q, TreeNode* RootNode)	// 二叉树--层次遍历
{
	QueuePush(Q,RootNode);
	// QueuePrint(q);
	while (!QueueEmpty(Q))
	{
		TreeNode* newnode = QueueBack(Q);
		QueuePop(Q);
		//if (QueueEmpty(Q))
		//{
		//	printf("\nQ队列为空\n");
		//}
		printf("%c->", newnode->data);
		if (newnode->LChild)
		{
			QueuePush(Q, newnode->LChild);
			// QueuePrint(q);
		}
		if (newnode->RChild)
		{
			QueuePush(Q, newnode->RChild);
			// QueuePrint(q);
		}
	}
}

StackNode* StackInit()	//  初始化栈
{
	StackNode* newnode = (StackNode*)malloc(sizeof(StackNode));
	if (newnode == NULL)
	{
		return NULL;
		exit(-1);
	}
	newnode->val = NULL;
	newnode->next = NULL;

	return newnode;
}

void StackPush(StackNode* ST, Stack_DataType* val)	// 压栈操作
{
	StackNode* newnode = (StackNode*)malloc(sizeof(StackNode));
	if (newnode == NULL)
	{
		return;
		exit(-1);
	}
	newnode->val = val;
	newnode->next = ST->next;
	ST->next = newnode;
	// 头插
	// 新的结点即是栈顶元素
}

StackNode* StackPop(StackNode* ST)		// 退栈操作
{
	if (IsStackEmpty(ST))
	{
		return NULL;
	}
	else
	{
		StackNode* cur = ST->next;
		ST->next = (cur->next == NULL ? NULL : cur->next);	// 更新栈顶
		return cur;
	}
}

StackNode* GetStackTop(StackNode* ST)		// 退栈操作
{
	if (IsStackEmpty(ST))
	{
		return NULL;
	}
	else
	{
		StackNode* cur = ST->next;
		return ST->next;
	}
}

bool IsStackEmpty(StackNode* ST)	// 判断栈空
{
	return ST->next == NULL;
}

void StackDestroy(StackNode* ST)	// 销毁栈
{
	while (!IsStackEmpty(ST))
	{
		StackNode* newnode = ST;
		ST = ST->next;
		newnode->val = NULL;
		free(newnode);
	}
}

void PreOrder_1(TreeNode* RootNode)	// 二叉树--先序遍历--根-左-右（非递归）
{
	StackNode* ST = StackInit();
	TreeNode* node = RootNode;
	while (node || !IsStackEmpty(ST))
	{
		if (node)
		{
			printf("%c->", node->data);
			StackPush(ST,node);
			node = node->LChild;
		}
		else
		{
			node = StackPop(ST)->val;
			node = node->RChild;
		}
	}
}

void InOrder_1(TreeNode* RootNode)	// 二叉树--中序遍历--左-根-右（非递归）
{
	StackNode* ST = StackInit();
	TreeNode* node = RootNode;
	while (node || !IsStackEmpty(ST))
	{
		if (node)
		{
			StackPush(ST, node);
			node = node->LChild;
		}
		else
		{
			node = StackPop(ST)->val;
			printf("%c->", node->data);
			node = node->RChild;
		}
	}
}

void PostOrder_1(TreeNode* RootNode)		// 二叉树--后序遍历--左-右-根（非递归）
{
	StackNode* ST = StackInit();
	TreeNode* node = RootNode;
	while (node || !IsStackEmpty(ST))
	{
		if (node)
		{
			StackPush(ST, node);
			node = node->LChild;
		}
		else
		{
			TreeNode* top = GetStackTop(ST)->val;
			if (top->RChild && top->RChild->flag == 0)
			{
				top = top->RChild;
				StackPush(ST, top);
				node = top->LChild;
			}
			else
			{
				top = StackPop(ST)->val;
				printf("%c->", top->data);
				top->flag = 1;
			}

		}

	}
}