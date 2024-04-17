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
} // ´®--±©Á¦Æ¥ÅäÄ£Ê½²âÊÔ

void test_02()
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
} // ´®--KMPÆ¥ÅäÄ£Ê½²âÊÔ

int main()
{
	// test_01();

	test_02();

	return 0;
}