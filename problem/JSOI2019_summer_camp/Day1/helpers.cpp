// helpers
#include <cstdio>

const int MAXN = 1e7 + 7, MOD = 998244354;

int n, a[MAXN];

int main()
{
    freopen("helpers.in", "r", stdin);
    freopen("helpers.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    if (n == 1)
    {
        printf("1");
        return 0;
    }
    printf("%d", (int)((double)MOD / n + 0.5));
    return 0;
}