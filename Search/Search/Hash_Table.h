#pragma once

#include<stdio.h>
#include<stdlib.h>

#define NUM 5

typedef struct Hash Hash;

struct Hash {
	int num;
	char* data;
};

Hash* Hash_Init();

int Hash_Function(int data);

void put(Hash* H, char data);
