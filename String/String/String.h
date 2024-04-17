#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct String String;

struct String {
	char* data;
	int length;
};

String* StringInit();	// 串的初始化

void StringAssign(String* s, char* data);	// 串--赋值

void StringPrint(String* s);	// 串--打印

void StringForceMatch(String* master, String* sub);	// 串--暴力匹配

int* GetNext(String* s);	// 计算、获取next数组

void PrintNext(int* next, int len);	// 打印next数组

void StringKMP_Match(String* master, String* sub, int* next);	// 串--KMP匹配算法
// KMP算法：
// 是一种高效的模式匹配算法。以牺牲一定空间为代价用于保存next数组，达到提高匹配效率的目的
// 同时kmp算法能更加智能的移动字符串，让字符串达到匹配状态
// KMP算法原理：
//		公共前后缀：用于寻找前后能够匹配的状态的位置
//		next数组：next[i] = i处的字符的公共前后缀值 + 1
//	所谓公共前后缀就是为了减少由于已经经历过成功匹配之后的无效错误匹配次数
//	核心：减少主串指针移动。并且快速找到前后匹配的状态
//

