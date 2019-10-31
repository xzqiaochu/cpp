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
    int low = 1, high = L;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int need_removed = getRemoved(mid);
        if (need_removed <= m)
            low = mid + 1; // 需要的小于等于可以提供的，mid合法，但不是最优解
        else
            high = mid - 1; // 需要的大于可以提供的，mid非法
    }
    printf("%d", high); // 最后 high = [mid(刚刚非法) - 1] 一定合法且最优
    return 0;
}