#define _CRT_SECURE_NO_WARNINGS

#include"String.h"

#include"My_String.h"

static void test_01()
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
} // ¥Æ--±©¡¶∆•≈‰ƒ£ Ω≤‚ ‘

static void test_02()
{
	String* ps = StringInit();
	String* s_test_02 = StringInit();

	char* string = "abaccababb";
	char* string_test_02 = "bbrs";

	StringAssign(ps, string);
	StringAssign(s_test_02, string_test_02);

	StringPrint(ps);
	StringPrint(s_test_02);

	int* next = GetNext(ps);
	PrintNext(next, ps->length);

	StringKMP_Match(ps, s_test_02, next);
} // ¥Æ--KMP∆•≈‰ƒ£ Ω≤‚ ‘

static void test_03()
{
	My_String* S = My_String_Init();
	My_String* S_test = My_String_Init();
	My_String* sub = My_String_Init();

	char* string_01 = "hello";

	char* string_02 = "llo";

	char* string_03 = "abaccababb";

	My_String_Assign(S, string_01);

	My_String_Print(S);

	My_String_Assign(sub, string_02);

	My_String_Print(sub);

	My_String_Assign(S_test, string_03);

	My_String_Print(S_test);

	My_String_ForceMatch(S, sub);

	int* next = My_String_GetNext(S_test);
	for (int i = 0; i < S_test->length; i++)
	{
		printf("%d ", next[i]);
	}
	printf("\n");

	My_String_KMP_Match(S, sub);

	int* nextval = My_String_GetNextval(S_test);
	for (int i = 0; i < S_test->length; i++)
	{
		printf("%d ", nextval[i]);
	}
}

int main()
{
	// test_01();

	//test_02();

	test_03();

	return 0;
}