#define _CRT_SECURE_NO_WARNINGS
#include"Sort.h"
#include"Stack.h"

void PrintArray(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int Partition(int* arr, int front, int behind)
{
	int x = arr[front];
	while(front < behind)
	{
		while (front < behind && x <= arr[behind])
		{
			behind--;
		}
		if (front < behind)
		{
			arr[front] = arr[behind];
			front++;
		}
		while (front<behind && x>arr[front])
		{
			front++;
		}
		if (front < behind)
		{
			arr[behind] = arr[front];
			behind--;
		}
	}
	arr[front] = x;
	return front;
}

void Quick_Sort(int* arr, int front, int behind)	// 快速排序
{
	if (front < behind)
	{
		int index = Partition(arr, front, behind);
		PrintArray(arr, 8);
		Quick_Sort(arr, front, index - 1);
		Quick_Sort(arr, index+1,behind);
	}
}

void Insert_Sort(int* arr, int length)	// 插入排序
{
	if (arr == NULL)
	{
		printf("传入数组为空，排序出错！！！\n");
		return;
	}
	for (int i = 1; i < length; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[i])
			{
				int temp = arr[i];
				for (int n = i-1; n >= j; n--)
				{
					arr[n + 1] = arr[n];
				}
				arr[j] = temp;
			}
		}
	}
}

void Shell_Sort(int* arr, int length, int step)	// 希尔排序
{
	// 只有一趟的希尔排序（没有对step进行处理）
	for (int i = 0; i < length; i++)
	{
		// 整体排序
		for (int j = i + step; j < length; j += step)
		{
			// 每组组间排序
			for (int k = i; k < j; k += step)
			{
				// 每组组内预排序
				if (arr[j] < arr[k])
				{
					int temp = arr[j];
					for (int l = j - step; l >= k; l -= step)
					{
						arr[l + step] = arr[l];
					}
					arr[k] = temp;
				}
			}
		}
	}
}

void Shell_Sort_01(int* arr, int length)	// 希尔排序
{
	// step>1相当于预排序，让数组接近有序
	// step = 1就相当于直接插入排序
	//int count = 0;
	int gap = length;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < length - gap; i++)
		{
			int end = i;
			int temp = arr[end + gap];
			while (end >= 0)
			{
				if (temp < arr[end])
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
					break;
			}
			arr[end + gap] = temp;
		}
		//printf("第%d次希尔排序：",count++);
		//PrintArray(arr, length);
	}
}

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Select_Sort(int* arr, int length) // 直接选择排序
{
	assert(arr);

	int begin = 0;
	int end = length - 1;
	while (begin < end)
	{
		// 在[begin，end]之间，找到最大值和最小值的下标，用于后续的交换
		int maxi = begin;
		int mini = begin;
		for (int i = begin+1; i < end; i++)
		{
			if (arr[i] < arr[mini])
				mini = i;
			if (arr[i] > arr[maxi])
				maxi = i;
		}
		int tmp = 0;

		swap(&arr[begin], &arr[mini]);
		// 如果max和begin位置重叠，那么此时最小值交换就会把最大值换走到原来最小值的位置上去
		if (begin == maxi)
			maxi = mini;
		swap(&arr[end], &arr[maxi]);

		begin++;
		end--;
	}
}

void AdjustDown(int* arr, int n, int root)	// 向下调整算法
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child] < arr[child + 1])
		{
			child = child + 1;
		}

		if (arr[child] > arr[parent])
		{
			swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break; 
		}
	}
}

void Heap_Sort(int* arr, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		// 从倒数第二层结点（最后一个非叶子节点开始，进行向上调整算法，不断地自底向上的将堆变成大堆
		// 最后完成建堆
		AdjustDown(arr, n, i);
	}

	int end = n - 1;
	// 将堆中的最后一个节点找到并记录，每次将堆顶数据和end位置的数据交换
	// 此时就得到了堆中的最大值
	// 然后再对堆进行向下调整算法
	// 
	while (end>0)
	{
		swap(&arr[0], &arr[end]);
		// 每次进行交换，，就将堆中的最大值换到了堆中（当前数组）的最后位置
		// 由于每次循环之后，调整的长度会一直进行改变，所以数组的最后位置也在不断改变
		AdjustDown(arr, end, 0);
		end--;
	}
}

void Bubble_Sort(int* arr, int n)	// 冒泡排序
{
	int end = n;
	while (end > 0)
	{
		int exchange = 0;
		for (int i = 1; i < end; i++)
		{
			if (arr[i] < arr[i - 1])
			{
				swap(&arr[i], &arr[i - 1]);
				exchange = 1;
			}
		}
		// 如果一趟冒泡排序的过程中，没有发生交换，则说明前面的数据已经有序
		if (exchange == 0)
			break;

		end--;
	}
}

int GetMidIndex(int* arr, int begin, int end)
{
	int mid = (begin + end) / 2;
	if (arr[begin] < arr[mid])
	{
		if (arr[mid] < arr[end])
		{
			// begin < mid < end
			return mid;
		}
		else if (arr[begin] > arr[end])
		{
			// end < begin < mid
			return begin;
		}
		else 
		{
			// begin < end < mid
			return end;
		}
	}
	else
	{
		// arr[begin] > arr[mid]
		if (arr[mid] > arr[end])
		{
			return mid;
		}
		else if (arr[begin] < arr[end])
		{
			return end;
		}
		else
			return begin;
	}
}

int Part_Sort(int* arr, int begin, int end)	// 快速排序--单趟排序
{
	int midindex = GetMidIndex(arr, begin, end);
	swap(&arr[midindex], &arr[end]);
	// 用于将中间数的下标更新到end位置，以便于选取合适的key值
	int keyindex = end;
	while (begin < end)
	{
		// keyindex的选取位置决定了begin和end谁先找
		// 例如
		// key在右边，那么最终将key换到中间的位置一定是比key大的元素，而这个元素一定是begin找到的位置
		// 18,15,2,61,56,5,468,8	记key = 8
		// 第一次：5，15，2，61，56，81，468，8
		// 第二次：5，2，15，61，56，81，468，8
		// 加入end先找
		// 经过交换之后，下一次循环后，end和begin相遇，此时循环停止
		// 此时begin指向2，end也指向2
		// 此时进行最重要交换的key和end的值分别时8和2
		// 故而经过交换后，下一次先走的一定是end索引。但是这个索引最终会遇到begin索引。
		// 而此时的begin索引时经过了寻找小于key值的end索引交换得来的
		//
		while (begin < end && arr[begin] <= arr[keyindex])
		{
			// begin找比key值大的索引下标
			begin++;
		}
		while (begin < end && arr[end] >= arr[keyindex])
		{
			// end找比key值小的索引下标
			end--;
		}
		swap(&arr[begin], &arr[end]);
	}
	swap(&arr[begin], &arr[keyindex]);

	//将最终相遇的位置（完成有序排序的元素的下标）返回
	return begin;
}

int Part_Sort2(int* arr, int begin, int end)
{
	int midindex = GetMidIndex(arr, begin, end);
	swap(&arr[midindex], &arr[end]);
	// 用于将中间数的下标更新到end位置，以便于选取合适的key值
	int keyindex = end;
	int key = arr[end];

	while (begin < end)
	{
		while (begin < end && arr[begin] <= arr[keyindex])
		{
			begin++;
		}
		// begin指针遇见比key大的数据，就把begin指向的元素放到key这个坑（第一次的坑，后面的坑都是end迭代的旧坑）里，begin所在的位置就形成了新的坑
		arr[end] = arr[begin];
		while (begin < end && arr[end] >= arr[keyindex])
		{
			end--;
		}
		// end指针遇见比key小的数据，就把end指向的元素放到旧坑（begin指向的位置）里，end所在的位置就形成了新的坑
		arr[begin] = arr[end];
	}
	arr[begin] = key;

	return begin;
}

int Part_Sort3(int* arr, int begin, int end)	// 快速排序--单趟排序--前后指针法
{
	int midindex = GetMidIndex(arr, begin, end);
	swap(&arr[midindex], &arr[end]);
	// 用于将中间数的下标更新到end位置，以便于选取合适的key值
	int keyindex = end;

	int cur = begin;
	int prev = begin - 1;

	while (cur < end)
	{
		// 将所有比key值小的数据都放到整个数组的前面去
		if (arr[cur] <= arr[keyindex] && ++prev != cur)
			swap(&arr[prev], &arr[cur]);

		cur++;
	}
	// ++prev表示循环交换后的数组中第一个比key值大的数字，将这个数据和key互换，则将key放到了中间位置
	// 此时，数组中，key前面的数据都小于key，后面的数据都大于key
	swap(&arr[++prev], &arr[keyindex]);

	return prev;
}

void Quick_Sort_01(int* arr, int left, int right)	// 快速排序
{
	assert(arr);

	if (left >= right)
		return;
	if((right - left + 1) > 10)
	{
		// 如果数组中元素数量大于10，就使用快速排序

		// 左右指针法
		// int div = Part_Sort(arr, left, right);
		// 挖坑法
		// int div = Part_Sort2(arr, left, right);
		// 前后指针法
		int div = Part_Sort3(arr, left, right);
		//PrintArray(arr, 6);
		//printf("[%d %d] %d [%d %d]\n", left, div-1, div, div+1, right);
		// 将数组分为[left,div-1] div [div+1,right]三个部分
		// 然后不断递归排序，知道left>right，此时递归结束
		Quick_Sort_01(arr, left, div - 1);
		Quick_Sort_01(arr, div + 1, right);
	}
	else
	{
		// 如果数量小于十，此时划分区间，递归遍历就会占用大量时间。此时快排并不合理
		// 同时，多次的迭代会让这些小区间中的元素接近有序，此时应采用直接插入排序
		Insert_Sort(arr + left, right - left + 1);
	}
}

// 递归改非递归
// 方法：
// 1、改循环（斐波那契数列求解）--针对一些比较简单的递归问题
// 2、数据结构栈模拟递归实现
// 
// 非递归意义：
// 1、提高效率（递归需要建立栈帧），但是对于现代计算机而言，这个优化可以忽略不计
// 2、递归的最大缺点是：如果栈帧的最大深度太深，可能导致栈溢出。这是由于系统的栈空间一般在 M 级别
//		而数据结构栈模拟递归实现，数据就会存储在堆空间。而堆的空间一般在 G 级别
//
void Quick_Sort_02(int* arr, int left, int right)	// 快速排序--非递归实现
{
	assert(arr);

	if (left >= right)
		return;

	SK stack;
	StackInit(&stack);

	StackPush(&stack, left);
	StackPush(&stack, right);

	while (!StackEmpty(&stack))
	{
		int end = StackTop(&stack);
		StackPop(&stack);
		int begin = StackTop(&stack);
		StackPop(&stack);

		int div = Part_Sort(arr, begin, end);

		if (end > div + 1)
		{
			StackPush(&stack, end);
			StackPush(&stack, div+1);
		}

		if (div - 1 > begin)
		{
			StackPush(&stack, div - 1);
			StackPush(&stack, begin);
		}
	}
	StackDestroy(&stack);
}

void Merge_Arr(int* arr, int begin1, int end1, int begin2, int end2, int* temp)	// 合并函数
{
	int left = begin1;
	int right = end2;
	int index = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
			temp[index++] = arr[begin1++];
		else
			temp[index++] = arr[begin2++];
	}
	// 处理一下两个数组长度不一样时出现的遗漏问题
	while (begin1 <= end1)
		temp[index++] = arr[begin1++];
	while (begin2 <= end2)
		temp[index++] = arr[begin2++];

	// 将合并的数组拷贝回原数组
	for (int i = left; i <= right; i++)
	{
		arr[i] = temp[i];
	}
}

void Part_Merge_Sort(int* arr, int left, int right, int* temp)	// 归并排序子函数--合并两个有序数组
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	Part_Merge_Sort(arr, left, mid, temp);
	Part_Merge_Sort(arr, mid + 1, right, temp);

	// 将两个有序数组合并成一个有序数组
	// 这两个有序数组，本质上将一个数组arr看成了两个有序部分：[left,mid] [mid+1,right]
	Merge_Arr(arr, left, mid, mid + 1, right, temp);
}

void Merge_Sort(int* arr, int n)
{
	assert(arr);

	int* temp = (int*)malloc(sizeof(int) * n);
	Part_Merge_Sort(arr, 0, n - 1, temp);

	free(temp);
}

void Merge_Sort02(int* arr, int n)	// 归并排序--非递归实现
{
	assert(arr);

	int* temp = (int*)malloc(sizeof(int) * n);
	int gap = 1;
	while(gap < n)
	{
		// 同时，由于要控制不同个数情况下分组之后的数组。得到的gap并不完全是二分情况，所以gap会出现超过n/2的情况·
		for (int i = 0; i < n; i += gap * 2)
		{
			// 在这里gap*2有越界风险，当数组个数为奇数时，比如为3个
			// 此时i+gap*2-1 = 3 > 3-1 = 2。此时就会发生越界
			// 所以在合并数组之前需要对合并的数组的首尾进行控制
			// 同时，合并的数组中，只有第二组数组可能出现越界情况。由于gap控制了范围，第一组数组不可能越界
			// 两种情况：
			// 1、合并时只有第一组，没有第二组。
			//		此时相当于合并合并完成
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + gap * 2 - 1;
			if (i + gap >= n)
				break;
			// 2、合并时第二组只有部分数据在边界以内，即i+gap*2-1越界
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			Merge_Arr(arr, begin1, end1, begin2, end2, temp);
		}
		gap *= 2;
		//PrintArray(arr, n);
	}
	free(temp);
}

void Count_Sort(int* arr, int n)	// 计数排序
{
	int min = arr[0];
	int max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	// range表示映射数组的范围大小
	// 相对映射是最小值min -- 0  最大值max -- range
	int range = max - min + 1;

	int* countArr = (int*)malloc(sizeof(int) * range);
	if (countArr == NULL)
	{
		printf("malloc is fail!!!");
		exit(-1);
	}
	memset(countArr, 0, sizeof(int) * range);

	// 统计数据出现个数
	for (int i = 0; i < n; i++)
	{
		countArr[arr[i] - min]++;
	}

	int index = 0;
	for (int i = 0; i < range; i++)
	{
		// 这里的循环表示的是，我需要遍历整个countArr数组，来确保原来的数组中每个数据值都能够出现并且被计数到
		while (countArr[i] != 0)
		{
			// countArr数组中，
			// 数组下标表示的是原来待排序数组中的每个数据
			// 数组中的数据代表的是原数组中的数据出现的次数
			// i表示的待排序的数据
			// 对应的countArr[i]表示的是i这个数据出现的次数
			arr[index++] = i+min;
			countArr[i]--;
		}
	}
	free(countArr);
}