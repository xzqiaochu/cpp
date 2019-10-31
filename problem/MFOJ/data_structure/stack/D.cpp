//计算
#include <cstdio>
#include <cmath>
#include <cstring>
#include <stack>

using namespace std;

char s[100];
int p;

stack<int> num;
stack<char> sym;

bool isnum()
{
    if (p < strlen(s) && s[p] >= '0' && s[p] <= '9')
        return true;
    else
        return false;
}

int getnum()
{
    int rst = 0;
    while (isnum())
    {
        rst = rst * 10 + s[p] - '0';
        p++;
    }
    return rst;
}

int getfirst(char symbol)
{
    switch (symbol)
    {
    case '(':
        return 3;
        break;
    case '^':
        return 0;
        break;
    case '*':
        return 1;
        break;
    case '/':
        return 1;
        break;
    case '+':
        return 2;
        break;
    case '-':
        return 2;
        break;
    }
}

bool can(char now_sym)
{
    if (sym.empty())
        return true;
    int now_first = getfirst(now_sym);
    char top_sym = sym.top();
    int top_first = getfirst(top_sym);
    return now_first < top_first;
}

void op()
{
    int b = num.top();
    num.pop();
    int a = num.top();
    num.pop();
    char symbol = sym.top();
    sym.pop();
    switch (symbol)
    {
    case '^':
        num.push((int)(pow(a, b)));
        break;
    case '*':
        num.push(a * b);
        break;
    case '/':
        num.push((int)(a / b));
        break;
    case '+':
        num.push(a + b);
        break;
    case '-':
        num.push(a - b);
        break;
    }
}

int comp()
{
    // if (s[p] == '-')
    // {
    //     num.push(0);
    //     sym.push('-');
    //     p++;
    // }
    while (p < strlen(s))
    {
        if (isnum())
        {
            num.push(getnum());
        }
        else
        {
            char symbol = s[p++];
            if (symbol == '(')
            {
                sym.push('(');
                continue;
            }
            if (symbol == ')')
            {
                while (sym.top() != '(')
                    op();
                sym.pop();
                continue;
            }
            while (!can(symbol))
                op();
            sym.push(symbol);
        }
    }
    while (!sym.empty())
        op();
    return num.top();
}

int main()
{
    scanf("%s", s);
    printf("%d", comp());
    return 0;
}