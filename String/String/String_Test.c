#define _CRT_SECURE_NO_WARNINGS

#include"String.h"

void test_01()
{
	String* ps = StringInit();
	String* s_test_01 = StringInit();
	char* string = "hello";
	char* string_test_01 = "ello";

	StringAssign(ps, string);

	StringPrint(ps);

	StringAssign(s_test_01, string_test_01);

	StringPrint(s_test_01);

	StringForceMatch(ps, s_test_01);
}

int main()
{
	test_01();
	return 0;
}