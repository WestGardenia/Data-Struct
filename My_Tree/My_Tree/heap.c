#define _CRT_SECURE_NO_WARNINGS
#include"heap.h"


void Heap_Init(heap* php, HPDataType* arr, int n)
{
	php->arr = (HPDataType*)malloc(sizeof(HPDataType) * n);

	memcpy(php->arr, arr, sizeof(HPDataType) * n);

	php->capacity = n;
	php->size = n;

	// 构建堆（小堆）
	for (int i = (n - 1 - 1)/2; i >= 0; i--)
	{
		AdjustDown(php->arr, php->size, i);
	}
}

void swap(HPDataType* a, HPDataType* b)
{
	HPDataType i = *a;
	*a = *b;
	*b = i;
}

void Heap_Print(heap* php)
{
	printf("此次堆的打印结果是：");
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->arr[i]);
	}
}

void AdjustDown(int* arr, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;

	while (child < n)
	{
		if (child + 1 < n && arr[child] > arr[child + 1])
		{
			// 在左右孩子之间选取较小值作为向上交换的结点
			child++;
		}
		if (arr[child] < arr[parent])
		{
			swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void Heap_Sort(heap* php, int n)
{
	// 小堆排序--降序序列
	// 思路：
	// 1、将堆顶数据（小堆之中最小值）与数组中下标最大值进行互换
	// 2、互换完成之后，将最小值排除在原来的堆之外，此时，堆的长度为n-1
	// 3、将剩余堆利用Adjustdowm函数进行重排，得到一个新的小堆
	// 4、在新的小堆的基础上重复前三步
	// 5、重复堆的高度次后，得到一个降序序列
	//

	int end = n - 1;
	while (end > 0)
	{
		// 1、交换数据
		swap(&php->arr[0], &php->arr[end]);
		// 2、找次小值，对剩余堆进行重排
		AdjustDown(php->arr, end, 0);
		end--;
	}
}

void Heap_Destory(heap* php)
{
	assert(php);
	free(php->arr);
	php->arr = NULL;
	php->capacity = php->size = 0;
}

void AdjustUp(int* arr, int n, int child)		// 堆--向上调整--用于调整堆
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (arr[child] < arr[parent])
		{
			swap(&arr[child], &arr[parent]);

			child = parent;
			// 这里面parent不会为负数。
			// 当child为0时，由于整数的特点，最后parent始终为0
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void Heap_Push(heap* php, HPDataType data)
{
	assert(php);

	if (php->capacity == php->size)
	{
		php->capacity *= 2;
		HPDataType* temp = (HPDataType*)realloc(php->arr, sizeof(HPDataType) * php->capacity);
		php->arr = temp;
	}
	php->arr[php->size++] = data;

	AdjustUp(php->arr, php->size, php->size-1);
}

void Heap_Pop(heap* php)
{
	assert(php);
	assert(php->size > 0);

	swap(&php->arr[0], &php->arr[php->size - 1]);

	php->size--;
	AdjustDown(php->arr, php->size, 0);
}