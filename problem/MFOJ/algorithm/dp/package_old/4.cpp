// 分组背包 (http://www.mfstem.org/contest/25/problem/4)
// author: xzqiaochu
// status: AC
#include <cstdio>
#include <algorithm>

const int MAXN = 37, MAXK = 17, MAXV = 207;

int n, V, K, w[MAXN], c[MAXN], a[MAXK][MAXN], f[MAXV];

int main()
{
    scanf("%d%d%d", &V, &n, &K);
    for (int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d%d%d", w + i, c + i, &t);
        a[t][++a[t][0]] = i;
    }
    for (int k = 1; k <= K; k++)
        for (int v = V; v >= 1; v--)
            for (int i = 1; i <= a[k][0]; i++)
                if (v - w[a[k][i]] >= 0)
                    f[v] = std::max(f[v], f[v - w[a[k][i]]] + c[a[k][i]]);
    printf("%d", f[V]);
    return 0;
}