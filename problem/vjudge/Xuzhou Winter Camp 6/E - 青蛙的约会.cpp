#include <cstdio>
#include <algorithm>

int exgcd(int a, int b, int &x, int &y)
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
    int x, y, m, n, L, rx, ry;
    scanf("%d%d%d%d%d", &x, &y, &m, &n, &L);
    if (n > m) std::swap(m, n), std::swap(x, y);
    int gcd = exgcd(m - n, L, rx, ry);
    int pd = (y - x) / gcd, pL = L / gcd;
    if ((y - x) % gcd != 0)
    {
        printf("Impossible");
        return 0;
    }
    rx = 1LL * rx * pd % pL;
    if (rx <= 0) rx += pL;
    printf("%d", rx);
    return 0;
}