#include <cstdio>

int n, k, num, a[1000001];

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    while (~scanf("%d%d", &n, &k))
    {
        num = 0;
        for (int i = 1; i < n; i++)
        {
            if (gcd(n, i) == 1)
                a[++num] = i;
        }
        a[0] = a[num];
        printf("%d\n", a[k % num] + n * (int)(k / num));
    }
    return 0;
}