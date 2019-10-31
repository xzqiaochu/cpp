//先序遍历计算逆波兰表达式
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <stack>

using namespace std;

char s[1001], temp[1001];
int p;
stack<double> num;

bool isnum()
{
    while (s[p] == ' ')
        p--;
    if (s[p] >= '0' && s[p] <= '9')
        return true;
    else
        return false;
}

double getnum()
{
    int len = 0;
    while (p >= 0 && s[p] != ' ')
        p--, len++;
    int j = 0;
    for (int i = p + 1; i <= p + len; i++, j++)
        temp[j] = s[i];
    temp[j + 1] = 0;
    double num = atof(temp);
    return num;
}

void op(char symbol)
{
    double a = num.top();
    num.pop();
    double b = num.top();
    num.pop();
    switch (symbol)
    {
    case '^':
        num.push(pow(a, b));
        break;
    case '*':
        num.push(a * b);
        break;
    case '/':
        num.push(a / b);
        break;
    case '+':
        num.push(a + b);
        break;
    case '-':
        num.push(a - b);
        break;
    }
}

double comp()
{
    while (p >= 0)
    {
        if (isnum())
            num.push(getnum());
        else
            op(s[p--]);
    }
    return num.top();
}

int main()
{
    scanf("%[^\n]", s);
    p = strlen(s) - 1;
    printf("%f\n", comp());
    return 0;
}