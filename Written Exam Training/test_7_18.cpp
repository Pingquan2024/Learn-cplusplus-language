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
    //先将字符串整体翻转
    reverse(arr, arr + len - 1);
    char* a = arr;
    for (i = 0; i <= len; i++)
    {
        if (arr[i] == ' ' || arr[i] == '\0')
        {
            reverse(a, arr + i - 1);//空格之前的再一次翻转，两次翻转正好
            a = (arr + i + 1);
        }

    }
    printf("%s", arr);

    return 0;
}