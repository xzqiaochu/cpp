/* 中缀表达式求值
时间复杂度：O(n)
出处：原创
最后修改时间：2019-04-06 */
#include <cstdio>
#include <cmath>
#include <cstring>
#include <stack>

using namespace std;

char s[100]; //保存中缀表达式
int p; //下一个位置的字符（运算过程中）

stack<int> num; //操作数栈
stack<char> sym; //操作符栈

bool isnum() //判断下一个字符是否为数字
{
    if (p < (int)strlen(s) && s[p] >= '0' && s[p] <= '9')
        return true;
    else
        return false;
}

int getnum() //读入一个操作数
{
    int rst = 0;
    while (isnum())
    {
        rst = rst * 10 + s[p] - '0';
        p++;
    }
    return rst;
}

int getfirst(char symbol) //获取操作符优先级
{
    switch (symbol)
    {
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
    case '(':
        return 3;
        break;
    }
    return -1; //未知操作符
}

bool can(char now_sym) //判断操作符是否可以入栈
{
    if (sym.empty())
        return true;
    int now_first = getfirst(now_sym);
    char top_sym = sym.top();
    int top_first = getfirst(top_sym);
    return now_first < top_first; //目前操作符优先级 > 栈顶操作符优先级，则可入栈
}

void op() //在栈顶进行一次运算
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
        num.push((int)(a / b)); //这里的除法是整除，即舍弃小数
        break;
    case '+':
        num.push(a + b);
        break;
    case '-':
        num.push(a - b);
        break;
    }
}

int comp() //主运算函数
{
    if (s[p] == '-') //判断第一个字符是否为'-'（负号）
    {
        num.push(0);
        sym.push('-');
        p++;
    }
    while (p < (int)strlen(s)) //遍历中缀表达式
    {
        if (isnum()) //如果是操作数则入栈
        {
            num.push(getnum());
        }
        else //如果是操作符
        {
            char symbol = s[p++];
            if (symbol == '(') //'('处理
            {
                sym.push('(');
                continue;
            }
            if (symbol == ')') //')'处理
            {
                while (sym.top() != '(')
                    op();
                sym.pop();
                continue;
            }
            while (!can(symbol)) //五则运算符处理
                op();
            sym.push(symbol);
        }
    }
    while (!sym.empty()) //处理栈中尚未运算的部分
        op();
    return num.top();
}


bool isopsymbol(char sym) //判断是否为五则运算符
{
    if (sym == '^' || sym == '*' || sym == '/' || sym == '+' || sym == '-')
        return true;
    else
        return false;
}

bool checkbracket() //检查括号是否合法
{
    int top = 0;
    for (int i = 0; i < (int)strlen(s); i++) //遍历中缀表达式
    {
        char c = s[i];
        if (c == '(')
        {
            if (i == 0) //如果是第一个符号，检查后继是否合法
            {
                if ((s[i + 1] >= '0' && s[i + 1] <= '9') || s[i + 1] == '(')
                    top++;
                else
                    return false;
                continue;
            }
            if (i == (int)strlen(s) - 1) //如果是最后一个符号，肯定非法
                return false;
            if ((isopsymbol(s[i - 1]) || s[i - 1] == '(') && ((s[i + 1] >= '0' && s[i + 1] <= '9') || s[i + 1] == '(')) //检查前驱和后继
                top++;
            else
                return false;
        }
        if (c == ')')
        {
            if (i == 0) //如果是第一个符号，肯定非法
                return false;
            if (i == (int)strlen(s) - 1) //如果是最后一个符号，检查前驱是否合法
            {
                if ((s[i - 1] >= '0' && s[i - 1] <= '9') || s[i - 1] == ')')
                    top--;
                else
                    return false;
                continue;
            }
            if ((isopsymbol(s[i + 1]) || s[i + 1] == ')') && ((s[i - 1] >= '0' && s[i - 1] <= '9') || s[i - 1] == ')')) //检查前驱和后继
                top--;
            else
                return false;
        }
        if (top < 0) //检查括号是否匹配（右括号是否过多）
        {
            return false;
        }
    }
    if (top != 0) //检查括号是否匹配（左括号是否过多）
        return false;
    return true;
}

bool checkopsymbol() //检查五则运算符是否合法
{
    if (isopsymbol(s[strlen(s) - 1])) //如果最后一个符号是五则运算符，肯定非法
        return false;
    for (int i = 0; i < (int)strlen(s); i++) //遍历中缀表达式
    {
        if (isopsymbol(s[i]) && isopsymbol(s[i + 1])) //如果出现两个相邻的五则运算符，则非法
            return false;
    }
    return true;
}

int main()
{
    scanf("%s", s);
    if (!checkbracket() || !checkopsymbol()) //中缀表达式合法性检查
        printf("ERROR");
    else
        printf("%d", comp()); //合法则进行运算
    return 0;
}