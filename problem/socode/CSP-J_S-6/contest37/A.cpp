//A-��ʮ�ĵ�
//http://socode.online/problems/366?contest=37
//author: xzqiaochu
//status: AC 
//time: 2019/11/08
#include <cstdio>
#include <cmath>
#include <cstring>
#include <stack>
 
using namespace std;

int n;
char s[100]; //������׺���ʽ
int p; //��һ��λ�õ��ַ�����������У�

stack<int> num; //������ջ
stack<char> sym; //������ջ

bool isnum() //�ж���һ���ַ��Ƿ�Ϊ����
{
    if (p < (int)strlen(s) && s[p] >= '0' && s[p] <= '9')
        return true;
    else
        return false;
}

int getnum() //����һ��������
{
    int rst = 0;
    while (isnum())
    {
        rst = rst * 10 + s[p] - '0';
        p++;
    }
    return rst;
}

int getfirst(char symbol) //��ȡ���������ȼ�
{
    switch (symbol)
    {
    case '^':
        return 0;
        break;
    case 'x':
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
    return -1; //δ֪������
}

bool can(char now_sym) //�жϲ������Ƿ������ջ
{
    if (sym.empty())
        return true;
    int now_first = getfirst(now_sym);
    char top_sym = sym.top();
    int top_first = getfirst(top_sym);
    return now_first < top_first; //Ŀǰ���������ȼ� > ջ�����������ȼ��������ջ
}

void op() //��ջ������һ������
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
    case 'x':
        num.push(a * b);
        break;
    case '/':
        num.push((int)(a / b)); //����ĳ�����������������С��
        break;
    case '+':
        num.push(a + b);
        break;
    case '-':
        num.push(a - b);
        break;
    }
}

int comp() //�����㺯��
{
    if (s[p] == '-') //�жϵ�һ���ַ��Ƿ�Ϊ'-'�����ţ�
    {
        num.push(0);
        sym.push('-');
        p++;
    }
    while (p < (int)strlen(s)) //������׺���ʽ
    {
        if (isnum()) //����ǲ���������ջ
        {
            num.push(getnum());
        }
        else //����ǲ�����
        {
            char symbol = s[p++];
            if (symbol == '(') //'('����
            {
                sym.push('(');
                continue;
            }
            if (symbol == ')') //')'����
            {
                while (sym.top() != '(')
                    op();
                sym.pop();
                continue;
            }
            while (!can(symbol)) //�������������
                op();
            sym.push(symbol);
        }
    }
    while (!sym.empty()) //����ջ����δ����Ĳ���
        op();
    return num.top();
}

bool isopsymbol(char sym) //�ж��Ƿ�Ϊ���������
{
    if (sym == '^' || sym == 'x' || sym == '/' || sym == '+' || sym == '-')
        return true;
    else
        return false;
}

int main()
{
	scanf("%d", &n);
	while (n--) {
		scanf("%s", s);
		while (!num.empty())
			num.pop();
		while (!sym.empty())
			sym.pop();
		p = 0;
		if (comp() == 24)
			puts("Yes");
		else
			puts("No");
	}
    return 0;
}
