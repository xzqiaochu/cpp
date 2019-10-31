// 口袋妖怪 AC
#include <cstdio>
#include <algorithm>

const int MAXN = 107, MAXM = 1007;

int n, m, kk, w[MAXN], c[MAXN], f[MAXM][MAXN];

int main()
{
    scanf("%d%d%d", &n, &m, &kk);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", c + i, w + i);
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= w[i]; j--)
            for (int k = kk; k >= 1; k--)
                f[j][k] = std::max(f[j][k], f[j - w[i]][k - 1] + c[i]);
    printf("%d", f[m][kk]);
    return 0;
}