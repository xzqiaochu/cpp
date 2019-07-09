// 决战钻石岛 (http://www.mfstem.org/contest/25/problem/2)
// author: xzqiaochu
// status: dev
#include <cstdio>
#include <algorithm>

int n, K, W, w[11000], c[11000], a[1100][1100], f[11000];

int main()
{
    scanf("%d%d%d", &n, &K, &W);
    for (int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d%d%d", c + i, w + i, &t);
        a[t][++a[t][0]] = i;
    }
    for (int k = 1; k <= K; k++)
        for (int v = W; v >= 1; v--)
            for (int i = 1; i <= a[k][0]; i++)
                if (v - w[a[k][i]] >= 0)
                    f[v] = std::max(f[v], f[v - w[a[k][i]]] + c[a[k][i]]);
    printf("%d", f[W]);
    return 0;
}