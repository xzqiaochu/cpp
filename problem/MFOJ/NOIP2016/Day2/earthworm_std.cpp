#include <cstdio>
#include <functional>
#include <algorithm>
const int SZ = 1e5 + 7, TSZ = 7e6 + 7;
int a[SZ], b[4][TSZ], h[4], tp[4], del;
int main()
{
    int n, m, q, u, v, t;
    scanf("%d%d%d%d%d%d", &n, &m, &q, &u, &v, &t);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);

    std::sort(a + 1, a + n + 1, std::greater<int>());

    for (int i = 1; i <= n; ++i)
        b[1][i] = a[i];

    h[1] = h[2] = h[3] = 1;
    tp[1] = n;
    for (int i = 1; i <= m; ++i)
    {
        int ans = -2e9, id = 0;
        for (int j = 1; j <= 3; ++j)
            if (h[j] <= tp[j] && b[j][h[j]] > ans)
                ans = b[j][h[j]], id = j;
        if (i % t == 0)
            printf("%d ", ans + del);
        ++h[id];
        b[2][++tp[2]] = 1LL * (ans + del) * u / v - del - q;
        b[3][++tp[3]] = ans + del - 1LL * (ans + del) * u / v - del - q;
        del += q;
    }
    puts("");
    for (int i = 1, end = n + m; i <= end; ++i)
    {
        int ans = -2e9, id = 0;
        for (int j = 1; j <= 3; ++j)
            if (h[j] <= tp[j] && b[j][h[j]] > ans)
                ans = b[j][h[j]], id = j;
        if (i % t == 0)
            printf("%d ", ans + del);
        ++h[id];
    }
    return 0;
}