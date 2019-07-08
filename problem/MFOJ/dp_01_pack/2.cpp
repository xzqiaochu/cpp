// 决战钻石岛 (http://www.mfstem.org/contest/25/problem/2)
// author: xzqiaochu
// status: dev
#include <cstdio>
#include <algorithm>

const int MAXN = 1e4 + 7, MAXV = 1e5 + 7;

int n, k, v, w[MAXN][MAXN], c[MAXN][MAXN], f[MAXV];

int main()
{
    scanf("%d%d%d", &n, &k, &v);
    for (int i = 1; i <= n; i++)
    {
        int nc, nw, nk;
        scanf("%d%d%d", &nc, &nw, &nk);
        c[nk][++c[nk][0]] = nc;
        w[nk][++w[nk][0]] = nw;
    }
    for (int i = 1; i <= k; i++)
        for (int j = v; j >= 1; j--)
            for (int kk = 1; kk <= w[i][0]; kk++)
                f[j] = std::max(f[j], f[std::max(j - w[i][kk], 0)] + c[i][kk]);
    printf("%d", f[v]);
    return 0;
}