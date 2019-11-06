// 跳石头(stone) (http://www.mfstem.org/contest/22/problem/A)
// author: xzqiaochu
// status: AC
#include <cstdio>

const int SZ = 5e4 + 7;

int L, n, m, a[SZ];

int getRemoved(int num)
{
    int sum = 0, st = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] - a[st] < num)
            sum++;
        else
            st = i;
    return sum;
}

int main()
{
    // freopen("stone.in", "r", stdin);
    // freopen("stone.out", "w", stdout);
    scanf("%d%d%d", &L, &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    a[++n] = L;
    for (int i = 1; i <= L; i++)
    {
        int need_removed = getRemoved(i);
        if (need_removed > m)
        {
            printf("%d", i - 1);
            return 0;
        }
    }
    printf("%d", L);
    return 0;
}