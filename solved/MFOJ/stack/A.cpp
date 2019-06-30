//表达式括号匹配
#include <cstdio>

char s[256];

int main()
{
    scanf("%s", s);
    int top = 0;
    for (int i = 0; s[i] != '@'; i++)
    {
        char c = s[i];
        if (c == '(')
            top++;
        if (c == ')')
            top--;
        if (top < 0)
        {
            printf("NO");
            return 0;
        }
    }
    if (top != 0)
        printf("NO");
    else
        printf("YES");
    return 0;
}