// 子串(substring) (http://www.mfstem.org/contest/22/problem/B)
// author: kelvin
// status: std
#include <cstdio>
typedef long long int64;
const int64 M = 1e9 + 7;
int64 n, m, k, ans[207][207], last[207][207];
char a[1007], b[207];
int main()
{
    ans[0][0] = 1;
    scanf("%lld%lld%lld%s%s", &n, &m, &k, a + 1, b + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = m; j; --j)
            for (int u = k; u; --u)
                if (a[i] == b[j])
                {
                    last[j][u] = last[j - 1][u] + ans[j - 1][u - 1];
                    ans[j][u] = (ans[j][u] + last[j][u]) % M;
                }
                else
                    last[j][u] = 0;
    printf("%lld\n", ans[m][k]);
    return 0;
}