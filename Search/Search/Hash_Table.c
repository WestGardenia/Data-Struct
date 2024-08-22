#define _CRT_SECURE_NO_WARNINGS
#include"Hash_Table.h"



Hash* Hash_Init()
{
	Hash* H = (Hash*)malloc(sizeof(Hash));
	H->num = 0;
	H->data = (char*)malloc(sizeof(char) * NUM);

	for (int i = 0; i < NUM; i++)
	{
		H->data[i] = 0;
	}
	return H;
}

int Hash_Function(int data)
{
	return data % NUM;
}

void put(Hash* H, char data)
{
	int index = Hash_Function(data);
	if (H->data[index] != 0)
	{
		int count = 0;
		while (H->data[index] != 0)
		{
			index = Hash_Function(Hash_Function(data) + count);
			count++;
		}

	}
	H->data[index] = data;


}