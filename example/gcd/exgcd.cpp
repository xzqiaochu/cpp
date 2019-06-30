//扩展欧几里得算法
#include <cstdio>

int exgcd(int a, int b, int &x, int &y) //这里 int &x, int &y 表示引用 
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    int gcd = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return gcd;
}

int main()
{
    int a, b, x, y;
    scanf("%d%d", &a, &b);
    exgcd(a, b, x, y);
    printf("%d %d", x, y);
    return 0;
}