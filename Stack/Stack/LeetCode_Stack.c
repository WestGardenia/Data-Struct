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
            // ���������ŷ��Ž�����ջ����ʱջ��Ԫ�ؾ���ĳһ��������
            StackPush(&st, *s);
            s++;
        }
        else
        {
            if (StackEmpty(&st))
            {
                // �����ջΪ��ջʱ��ֱ�������������ţ���ʱ�޷�ƥ�䣬��ֱ�ӷ���false
                StackDestroy(&st);
                return false;
            }
            // ���������ţ��ͽ�ջ�е�ջ��Ԫ��ȡ��
            SKDataType top = StackTop(&st);
            StackPop(&st);
            if ((*s == '}' && top != '{')
                || (*s == ']' && top != '[')
                || (*s == ')' && top != '('))
            {
                // ��ȡ����ջ��Ԫ���������������Ž���ƥ�䡣ͬʱ����ջ��Ԫ�س�ջ��ɾ�������Ա���Ϊ��ߵ�δƥ��Ԫ�ص�ƥ����׼��
                // ���ƥ������򷵻�false�����ƥ����ȷ������������������±�����Լӣ�ջ��Ԫ����ԭ��ջ�еĵڶ��㶥��
                StackDestroy(&st);
                return false;
            }
            else
            {
                s++;
            }
        }
    }
    // ���ջ��Ϊ�գ���ջ�л���������δ����ƥ�䣬���ʱ��ȻΪfalse
    bool ret = StackEmpty(&st);
    StackDestroy(&st);
    return ret;
}