#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

void reverse(char* start, char* end)
{
    char tmp;
    while (start < end)
    {
        tmp = *start;
        *start = *end;
        *end = tmp;
        start++;
        end--;
    }
}
int main()
{
    char arr[100] = { 0 };
    gets(arr);
    int len = strlen(arr);
    int i = 0;
    //�Ƚ��ַ������巭ת
    reverse(arr, arr + len - 1);
    char* a = arr;
    for (i = 0; i <= len; i++)
    {
        if (arr[i] == ' ' || arr[i] == '\0')
        {
            reverse(a, arr + i - 1);//�ո�֮ǰ����һ�η�ת�����η�ת����
            a = (arr + i + 1);
        }

    }
    printf("%s", arr);

    return 0;
}