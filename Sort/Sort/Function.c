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

void Quick_Sort(int* arr, int front, int behind)	// ��������
{
	if (front < behind)
	{
		int index = Partition(arr, front, behind);
		PrintArray(arr, 8);
		Quick_Sort(arr, front, index - 1);
		Quick_Sort(arr, index+1,behind);
	}
}

void Insert_Sort(int* arr, int length)	// ��������
{
	if (arr == NULL)
	{
		printf("��������Ϊ�գ������������\n");
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

void Shell_Sort(int* arr, int length, int step)	// ϣ������
{
	// ֻ��һ�˵�ϣ������û�ж�step���д���
	for (int i = 0; i < length; i++)
	{
		// ��������
		for (int j = i + step; j < length; j += step)
		{
			// ÿ���������
			for (int k = i; k < j; k += step)
			{
				// ÿ������Ԥ����
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

void Shell_Sort_01(int* arr, int length)	// ϣ������
{
	// step>1�൱��Ԥ����������ӽ�����
	// step = 1���൱��ֱ�Ӳ�������
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
		//printf("��%d��ϣ������",count++);
		//PrintArray(arr, length);
	}
}

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Select_Sort(int* arr, int length) // ֱ��ѡ������
{
	assert(arr);

	int begin = 0;
	int end = length - 1;
	while (begin < end)
	{
		// ��[begin��end]֮�䣬�ҵ����ֵ����Сֵ���±꣬���ں����Ľ���
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
		// ���max��beginλ���ص�����ô��ʱ��Сֵ�����ͻ�����ֵ���ߵ�ԭ����Сֵ��λ����ȥ
		if (begin == maxi)
			maxi = mini;
		swap(&arr[end], &arr[maxi]);

		begin++;
		end--;
	}
}

void AdjustDown(int* arr, int n, int root)	// ���µ����㷨
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
		// �ӵ����ڶ����㣨���һ����Ҷ�ӽڵ㿪ʼ���������ϵ����㷨�����ϵ��Ե����ϵĽ��ѱ�ɴ��
		// �����ɽ���
		AdjustDown(arr, n, i);
	}

	int end = n - 1;
	// �����е����һ���ڵ��ҵ�����¼��ÿ�ν��Ѷ����ݺ�endλ�õ����ݽ���
	// ��ʱ�͵õ��˶��е����ֵ
	// Ȼ���ٶԶѽ������µ����㷨
	// 
	while (end>0)
	{
		swap(&arr[0], &arr[end]);
		// ÿ�ν��н��������ͽ����е����ֵ�����˶��У���ǰ���飩�����λ��
		// ����ÿ��ѭ��֮�󣬵����ĳ��Ȼ�һֱ���иı䣬������������λ��Ҳ�ڲ��ϸı�
		AdjustDown(arr, end, 0);
		end--;
	}
}

void Bubble_Sort(int* arr, int n)	// ð������
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
		// ���һ��ð������Ĺ����У�û�з�����������˵��ǰ��������Ѿ�����
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

int Part_Sort(int* arr, int begin, int end)	// ��������--��������
{
	int midindex = GetMidIndex(arr, begin, end);
	swap(&arr[midindex], &arr[end]);
	// ���ڽ��м������±���µ�endλ�ã��Ա���ѡȡ���ʵ�keyֵ
	int keyindex = end;
	while (begin < end)
	{
		// keyindex��ѡȡλ�þ�����begin��end˭����
		// ����
		// key���ұߣ���ô���ս�key�����м��λ��һ���Ǳ�key���Ԫ�أ������Ԫ��һ����begin�ҵ���λ��
		// 18,15,2,61,56,5,468,8	��key = 8
		// ��һ�Σ�5��15��2��61��56��81��468��8
		// �ڶ��Σ�5��2��15��61��56��81��468��8
		// ����end����
		// ��������֮����һ��ѭ����end��begin��������ʱѭ��ֹͣ
		// ��ʱbeginָ��2��endҲָ��2
		// ��ʱ��������Ҫ������key��end��ֵ�ֱ�ʱ8��2
		// �ʶ�������������һ�����ߵ�һ����end��������������������ջ�����begin������
		// ����ʱ��begin����ʱ������Ѱ��С��keyֵ��end��������������
		//
		while (begin < end && arr[begin] <= arr[keyindex])
		{
			// begin�ұ�keyֵ��������±�
			begin++;
		}
		while (begin < end && arr[end] >= arr[keyindex])
		{
			// end�ұ�keyֵС�������±�
			end--;
		}
		swap(&arr[begin], &arr[end]);
	}
	swap(&arr[begin], &arr[keyindex]);

	//������������λ�ã�������������Ԫ�ص��±꣩����
	return begin;
}

int Part_Sort2(int* arr, int begin, int end)
{
	int midindex = GetMidIndex(arr, begin, end);
	swap(&arr[midindex], &arr[end]);
	// ���ڽ��м������±���µ�endλ�ã��Ա���ѡȡ���ʵ�keyֵ
	int keyindex = end;
	int key = arr[end];

	while (begin < end)
	{
		while (begin < end && arr[begin] <= arr[keyindex])
		{
			begin++;
		}
		// beginָ��������key������ݣ��Ͱ�beginָ���Ԫ�طŵ�key����ӣ���һ�εĿӣ�����ĿӶ���end�����ľɿӣ��begin���ڵ�λ�þ��γ����µĿ�
		arr[end] = arr[begin];
		while (begin < end && arr[end] >= arr[keyindex])
		{
			end--;
		}
		// endָ��������keyС�����ݣ��Ͱ�endָ���Ԫ�طŵ��ɿӣ�beginָ���λ�ã��end���ڵ�λ�þ��γ����µĿ�
		arr[begin] = arr[end];
	}
	arr[begin] = key;

	return begin;
}

int Part_Sort3(int* arr, int begin, int end)	// ��������--��������--ǰ��ָ�뷨
{
	int midindex = GetMidIndex(arr, begin, end);
	swap(&arr[midindex], &arr[end]);
	// ���ڽ��м������±���µ�endλ�ã��Ա���ѡȡ���ʵ�keyֵ
	int keyindex = end;

	int cur = begin;
	int prev = begin - 1;

	while (cur < end)
	{
		// �����б�keyֵС�����ݶ��ŵ����������ǰ��ȥ
		if (arr[cur] <= arr[keyindex] && ++prev != cur)
			swap(&arr[prev], &arr[cur]);

		cur++;
	}
	// ++prev��ʾѭ��������������е�һ����keyֵ������֣���������ݺ�key��������key�ŵ����м�λ��
	// ��ʱ�������У�keyǰ������ݶ�С��key����������ݶ�����key
	swap(&arr[++prev], &arr[keyindex]);

	return prev;
}

void Quick_Sort_01(int* arr, int left, int right)	// ��������
{
	assert(arr);

	if (left >= right)
		return;
	if((right - left + 1) > 10)
	{
		// ���������Ԫ����������10����ʹ�ÿ�������

		// ����ָ�뷨
		// int div = Part_Sort(arr, left, right);
		// �ڿӷ�
		// int div = Part_Sort2(arr, left, right);
		// ǰ��ָ�뷨
		int div = Part_Sort3(arr, left, right);
		//PrintArray(arr, 6);
		//printf("[%d %d] %d [%d %d]\n", left, div-1, div, div+1, right);
		// �������Ϊ[left,div-1] div [div+1,right]��������
		// Ȼ�󲻶ϵݹ�����֪��left>right����ʱ�ݹ����
		Quick_Sort_01(arr, left, div - 1);
		Quick_Sort_01(arr, div + 1, right);
	}
	else
	{
		// �������С��ʮ����ʱ�������䣬�ݹ�����ͻ�ռ�ô���ʱ�䡣��ʱ���Ų�������
		// ͬʱ����εĵ���������ЩС�����е�Ԫ�ؽӽ����򣬴�ʱӦ����ֱ�Ӳ�������
		Insert_Sort(arr + left, right - left + 1);
	}
}

// �ݹ�ķǵݹ�
// ������
// 1����ѭ����쳲�����������⣩--���һЩ�Ƚϼ򵥵ĵݹ�����
// 2�����ݽṹջģ��ݹ�ʵ��
// 
// �ǵݹ����壺
// 1�����Ч�ʣ��ݹ���Ҫ����ջ֡�������Ƕ����ִ���������ԣ�����Ż����Ժ��Բ���
// 2���ݹ�����ȱ���ǣ����ջ֡��������̫����ܵ���ջ�������������ϵͳ��ջ�ռ�һ���� M ����
//		�����ݽṹջģ��ݹ�ʵ�֣����ݾͻ�洢�ڶѿռ䡣���ѵĿռ�һ���� G ����
//
void Quick_Sort_02(int* arr, int left, int right)	// ��������--�ǵݹ�ʵ��
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

void Merge_Arr(int* arr, int begin1, int end1, int begin2, int end2, int* temp)	// �ϲ�����
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
	// ����һ���������鳤�Ȳ�һ��ʱ���ֵ���©����
	while (begin1 <= end1)
		temp[index++] = arr[begin1++];
	while (begin2 <= end2)
		temp[index++] = arr[begin2++];

	// ���ϲ������鿽����ԭ����
	for (int i = left; i <= right; i++)
	{
		arr[i] = temp[i];
	}
}

void Part_Merge_Sort(int* arr, int left, int right, int* temp)	// �鲢�����Ӻ���--�ϲ�������������
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	Part_Merge_Sort(arr, left, mid, temp);
	Part_Merge_Sort(arr, mid + 1, right, temp);

	// ��������������ϲ���һ����������
	// �������������飬�����Ͻ�һ������arr�������������򲿷֣�[left,mid] [mid+1,right]
	Merge_Arr(arr, left, mid, mid + 1, right, temp);
}

void Merge_Sort(int* arr, int n)
{
	assert(arr);

	int* temp = (int*)malloc(sizeof(int) * n);
	Part_Merge_Sort(arr, 0, n - 1, temp);

	free(temp);
}

void Merge_Sort02(int* arr, int n)	// �鲢����--�ǵݹ�ʵ��
{
	assert(arr);

	int* temp = (int*)malloc(sizeof(int) * n);
	int gap = 1;
	while(gap < n)
	{
		// ͬʱ������Ҫ���Ʋ�ͬ��������·���֮������顣�õ���gap������ȫ�Ƕ������������gap����ֳ���n/2�������
		for (int i = 0; i < n; i += gap * 2)
		{
			// ������gap*2��Խ����գ����������Ϊ����ʱ������Ϊ3��
			// ��ʱi+gap*2-1 = 3 > 3-1 = 2����ʱ�ͻᷢ��Խ��
			// �����ںϲ�����֮ǰ��Ҫ�Ժϲ����������β���п���
			// ͬʱ���ϲ��������У�ֻ�еڶ���������ܳ���Խ�����������gap�����˷�Χ����һ�����鲻����Խ��
			// ���������
			// 1���ϲ�ʱֻ�е�һ�飬û�еڶ��顣
			//		��ʱ�൱�ںϲ��ϲ����
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + gap * 2 - 1;
			if (i + gap >= n)
				break;
			// 2���ϲ�ʱ�ڶ���ֻ�в��������ڱ߽����ڣ���i+gap*2-1Խ��
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

void Count_Sort(int* arr, int n)	// ��������
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
	// range��ʾӳ������ķ�Χ��С
	// ���ӳ������Сֵmin -- 0  ���ֵmax -- range
	int range = max - min + 1;

	int* countArr = (int*)malloc(sizeof(int) * range);
	if (countArr == NULL)
	{
		printf("malloc is fail!!!");
		exit(-1);
	}
	memset(countArr, 0, sizeof(int) * range);

	// ͳ�����ݳ��ָ���
	for (int i = 0; i < n; i++)
	{
		countArr[arr[i] - min]++;
	}

	int index = 0;
	for (int i = 0; i < range; i++)
	{
		// �����ѭ����ʾ���ǣ�����Ҫ��������countArr���飬��ȷ��ԭ����������ÿ������ֵ���ܹ����ֲ��ұ�������
		while (countArr[i] != 0)
		{
			// countArr�����У�
			// �����±��ʾ����ԭ�������������е�ÿ������
			// �����е����ݴ������ԭ�����е����ݳ��ֵĴ���
			// i��ʾ�Ĵ����������
			// ��Ӧ��countArr[i]��ʾ����i������ݳ��ֵĴ���
			arr[index++] = i+min;
			countArr[i]--;
		}
	}
	free(countArr);
}