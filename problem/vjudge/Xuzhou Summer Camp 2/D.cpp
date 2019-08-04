// D - Charm Bracelet (https://vjudge.net/contest/316500#problem/D)
// POJ 3624
// from: USACO 2007 December Silver
// author: xzqiaochu
// status: AC
#include <cstdio>
#include <algorithm>

const int MAXN = 3407, MAXM = 12887;

int n, m, w[MAXN], c[MAXN], f[MAXM];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", w + i, c + i);
    // 0/1 ±³°ü
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= w[i]; j--)
            f[j] = std::max(f[j], f[j - w[i]] + c[i]);
    printf("%d", f[m]);
    return 0;
}
