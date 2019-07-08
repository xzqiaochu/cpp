/*  扩展欧几里得算法 = 求逆元
时间复杂度: O(log n)
最后修改时间: 2019-07-08 */
#include <cstdio>

// 求解 a*x + b*y = gcd(a, b)
// 返回值为 a, b 的最大公约数
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

// 求 a (mod b) 的逆元
int inv(int a, int b)
{
    int x, y;
    exgcd(a, b, x, y);
    return x;
}

int main()
{
    int a, b, x, y;
    scanf("%d%d", &a, &b);
    exgcd(a, b, x, y);
    printf("%d %d", x, y);
    return 0;
}