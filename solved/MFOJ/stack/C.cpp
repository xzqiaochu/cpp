//字符串匹配问题
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

char s[256];
stack<char> sym;

int main()
{
    int t;
    scanf("%d", &t);
flag:
    while (t--)
    {
        while (!sym.empty())
            sym.pop();
        scanf("%s", s);
        for (int i = 0; i < strlen(s); i++)
        {
            char c = s[i];
            switch (c)
            {
            case '<':
                sym.push(c);
                break;
            case '(':
                if (sym.empty() || sym.top() == '(' || sym.top() == '[' || sym.top() == '{')
                {
                    sym.push(c);
                }
                else
                {
                    puts("NO");
                    goto flag;
                }
                break;
            case '[':
                if (sym.empty() || sym.top() == '[' || sym.top() == '{')
                {
                    sym.push(c);
                }
                else
                {
                    puts("NO");
                    goto flag;
                }
                break;
            case '{':
                if (sym.empty() || sym.top() == '{')
                {
                    sym.push(c);
                }
                else
                {
                    puts("NO");
                    goto flag;
                }
                break;
            case '>':
                if (!sym.empty() && sym.top() == '<')
                {
                    sym.pop();
                }
                else
                {
                    puts("NO");
                    goto flag;
                }
                break;
            case ')':
                if (!sym.empty() && sym.top() == '(')
                {
                    sym.pop();
                }
                else
                {
                    puts("NO");
                    goto flag;
                }
                break;
            case ']':
                if (!sym.empty() && sym.top() == '[')
                {
                    sym.pop();
                }
                else
                {
                    puts("NO");
                    goto flag;
                }
                break;
            case '}':
                if (!sym.empty() && sym.top() == '{')
                {
                    sym.pop();
                }
                else
                {
                    puts("NO");
                    goto flag;
                }
                break;
            }
        }
        if (sym.empty())
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}