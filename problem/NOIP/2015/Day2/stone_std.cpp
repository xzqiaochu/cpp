// 跳石头(stone) (http://www.mfstem.org/contest/22/problem/A)
// author: kelvin
// status: std
#include <cstdio>
const int SZ = 5e4 + 7;
int rock[SZ];
int main()
{
    // freopen("stone.in", "r", stdin);
    // freopen("stone.out", "w", stdout);
    int L, m, n;
    scanf("%d%d%d", &L, &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", rock + i);
    int low = 0, high = L, mid, st, sum;
    rock[++n] = L;
    while (low <= high)
    {
        mid = (low + high) / 2;
        st = sum = 0;
        for (int i = 1; i <= n; ++i)
            if (rock[i] - rock[st] < mid)
                ++sum;
            else
                st = i;
        if (sum <= m)
            low = mid + 1;
        else
            high = mid - 1;
    }
    printf("%d\n", high);
    return 0;
}