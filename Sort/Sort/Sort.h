#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>


void PrintArray(int* arr, int length);	// 打印函数

void swap(int* a, int* b); // 互换函数

// 快速排序思想：
// 找到一个数值作为相对值进行判断，并不断迭代找到在该数组中这个数值的正确相对位置
//	所谓正确相对位置，就是大的在后面，小的在前面
// 每一次判断并确定好这个数值的正确相对位置后，就迭代一个新的相对值，并不断递归
//
int Partition(int* arr, int front, int behind);	// 寻找下标为front的数据的正确相对位置，并将正确位置的下标返回，以便后续使用

void Quick_Sort(int* arr, int front, int behind);	// 快速排序函数主体


// 插入排序
// 1、直接插入排序
// 2、希尔排序
// O(N^2)
void Insert_Sort(int* arr, int length);	// 插入排序

// 多组并排，局部有序
// O(N^1.3-N^2)
// 只有当数组内的数据本身有序时，直接插入排序的速度要优于希尔排序
void Shell_Sort(int* arr, int length, int step);	// 希尔排序
void Shell_Sort_01(int* arr, int length);	// 希尔排序


// 选择排序
// 1、直接选择排序
// 2、堆排序
void Select_Sort(int* arr, int length); // 直接选择排序

void AdjustDown(int* arr, int n, int root);	// 向下调整算法

void Heap_Sort(int* arr, int n);


// 交换排序
// 1、冒泡排序
// 2、快速排序
void Bubble_Sort(int* arr, int n);	// 冒泡排序

// 最好情况下（选取的key正好在数组中间，中位数时）时间复杂度为O（N*logN)
// 极端情况下（最坏情况：每次选到的key都是最大值或者最小值，即数组有序或者接近有序）此时时间复杂度O（N^2）
// 空间复杂度： O（logN）主要和函数栈帧的深度有关


// 快速排序单趟排序三种方法：
// 1、左右指针法
// 2、挖坑法
// 3、前后指针法

int Part_Sort(int* a, int begin, int end);	// 快速排序--单趟排序--左右指针法
int Part_Sort2(int* a, int begin, int end);	// 快速排序--单趟排序--挖坑法
int Part_Sort3(int* a, int begin, int end);	// 快速排序--单趟排序--前后指针法

void Quick_Sort_01(int* arr, int left, int right);	// 快速排序
void Quick_Sort_02(int* arr, int left, int right);	// 快速排序--非递归实现

// 优化方法：三数取中
// 首先要明确：当数组中元素有序或者接近有序时，普通快速排序的效率极低，并且由于大量的递归可能会导致栈溢出
// 原因在于：当数组有序时，key的值会很容易选到最值，那么将数组分开成两个数组分别排序的目的就无法达到，此时就相当于不断区分后的交换（和直接插入排序效率相当）
// 
// 优化思路：
// 1、想办法在任意情况下，将key的值确保其不选到最值，甚至，让有序时变成最犹
//	  此时，最坏的情况不会再出现。时间复杂度为O（N*logN）
int GetMidIndex(int* a, int begin, int end);	// 三数取中函数
// 2、在大量元素时，快速排序的效率十分可观。但是递归次数过多后，划分的区间足够小时，此时划分区间的操作会占用大量时间
//	  又由于多次递归之后，划分的小区间中的数据已经接近有序，此时直接插入排序适合处理
// 
//
// 内部排序：主要是指在内存中进行排序的算法
// 外部排序：主要是指在磁盘中进行排序的算法

// 归并排序（二路归并）（外部排序）
// 单趟排序的思想：合并两段有序数组，合并之后依旧有序
// 时间复杂度O（N*logN）
// 空间复杂度O（N）
void Merge_Arr(int* arr, int begin1, int end1, int begin2, int end2, int* temp);	// 合并函数
void Part_Merge_Sort(int* arr, int left, int right, int* temp);	// 归并排序子函数--合并两个有序数组
void Merge_Sort(int* arr, int n);	// 归并排序--递归实现
void Merge_Sort02(int* arr, int n);	// 归并排序--非递归实现
// 假如：内存中只能存储1000w个数据，但是需要对10亿个数据进行排序，就可以利用归并排序
// 思路：将10亿数据放在100个文件中分别排好序（内部排序）。利用读文件的功能对不同文件的有序数组进行归并排序
// 注意：不要将所有的数据都放在磁盘上进行排序，CPU读取磁盘的数据要远远慢于读取内存的数据。所以应当尽量在内存中完成主要的排序工作

// 计数排序
// 思想：又称鸽巢原理，是对哈希直接定址法的变形应用
// 方法步骤：
// 1、统计相同元素出现的次数
// 2、根据统计的结果将序列回收到原来的序列中
