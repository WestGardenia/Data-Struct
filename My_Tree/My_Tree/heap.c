#define _CRT_SECURE_NO_WARNINGS
#include"heap.h"


void Heap_Init(heap* php, HPDataType* arr, int n)
{
	php->arr = (HPDataType*)malloc(sizeof(HPDataType) * n);

	memcpy(php->arr, arr, sizeof(HPDataType) * n);

	php->capacity = n;
	php->size = n;

	// �����ѣ�С�ѣ�
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
	printf("�˴ζѵĴ�ӡ����ǣ�");
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
			// �����Һ���֮��ѡȡ��Сֵ��Ϊ���Ͻ����Ľ��
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
	// С������--��������
	// ˼·��
	// 1�����Ѷ����ݣ�С��֮����Сֵ�����������±����ֵ���л���
	// 2���������֮�󣬽���Сֵ�ų���ԭ���Ķ�֮�⣬��ʱ���ѵĳ���Ϊn-1
	// 3����ʣ�������Adjustdowm�����������ţ��õ�һ���µ�С��
	// 4�����µ�С�ѵĻ������ظ�ǰ����
	// 5���ظ��ѵĸ߶ȴκ󣬵õ�һ����������
	//

	int end = n - 1;
	while (end > 0)
	{
		// 1����������
		swap(&php->arr[0], &php->arr[end]);
		// 2���Ҵ�Сֵ����ʣ��ѽ�������
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

void AdjustUp(int* arr, int n, int child)		// ��--���ϵ���--���ڵ�����
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (arr[child] < arr[parent])
		{
			swap(&arr[child], &arr[parent]);

			child = parent;
			// ������parent����Ϊ������
			// ��childΪ0ʱ�������������ص㣬���parentʼ��Ϊ0
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