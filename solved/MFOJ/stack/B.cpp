//括弧匹配检验
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

char s[256];
stack<char> sym;

int main()
{
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i++)
    {
        char c = s[i];
        if (c == '(' || c == '[')
            sym.push(c);
        if (c == ')')
        {
            if (!sym.empty() && sym.top() == '(')
            {
                sym.pop();
            }
            else
            {
                printf("Wrong");
                return 0;
            }
        }
        if (c == ']')
        {
            if (!sym.empty() && sym.top() == '[')
            {
                sym.pop();
            }
            else
            {
                printf("Wrong");
                return 0;
            }
        }
    }
    if (sym.empty())
        printf("OK");
    else
        printf("Wrong");
    return 0;
}