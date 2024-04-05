#define _CRT_SECURE_NO_WARNINGS
#include"Function.h"

bool isValid(char* s)
{
    SK st;
    StackInit(&st);
    while (*s)
    {
        if (*s == '('
            || *s == '['
            || *s == '{')
        {
            // 遇到左括号符号将其入栈，此时栈顶元素就是某一个左括号
            StackPush(&st, *s);
            s++;
        }
        else
        {
            if (StackEmpty(&st))
            {
                // 如果在栈为空栈时，直接遇到了右括号，此时无法匹配，则直接返回false
                StackDestroy(&st);
                return false;
            }
            // 遇到右括号，就将栈中的栈顶元素取出
            SKDataType top = StackTop(&st);
            StackPop(&st);
            if ((*s == '}' && top != '{')
                || (*s == ']' && top != '[')
                || (*s == ')' && top != '('))
            {
                // 将取出的栈顶元素与遇到的右括号进行匹配。同时，将栈顶元素出栈（删除），以便于为后边的未匹配元素的匹配做准备
                // 如果匹配错误，则返回false；如果匹配正确，则继续迭代。数组下标向后自加，栈顶元素由原来栈中的第二层顶替
                StackDestroy(&st);
                return false;
            }
            else
            {
                s++;
            }
        }
    }
    // 如果栈不为空，则栈中还有左括号未进行匹配，则此时必然为false
    bool ret = StackEmpty(&st);
    StackDestroy(&st);
    return ret;
}