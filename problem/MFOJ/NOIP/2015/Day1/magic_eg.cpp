// 神奇的幻方(magic) (http://www.mfstem.org/contest/21/problem/A)
// author: luogu
// status: AC
#include <cstdio>

int n, a[40][40], x, y;

int main()
{
    // freopen("magic.in", "r", stdin);
    // freopen("magic.out", "w", stdout);
    scanf("%d", &n);
    x = 1, y = (n + 1) / 2;
    for (int i = 1; i <= n * n; i++)
    {
        a[x][y] = i;
        if (!a[(x - 2 + n) % n + 1][y % n + 1])
            x = (x - 2 + n) % n + 1, y = y % n + 1;
        else
            x = x % n + 1; //数学运算
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}