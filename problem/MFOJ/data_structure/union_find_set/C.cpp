// 搭配购买(buy) AC
#include <cstdio>
#include <algorithm>

const int MAXN = 1e4 + 7;

int n, m, w, fa[MAXN], wa[MAXN], va[MAXN];
int tot, prc[MAXN], val[MAXN], dp[MAXN];
// dp[i][j] 前i件物品供选择时，花费不超过j元 可以买到的最大价值

int get(int x)
{
    return fa[x] == x ? x : (fa[x] = get(fa[x]));
}

void merge(int x, int y)
{
    int rtx = get(x), rty = get(y);
    if (rtx == rty)
        return;
    fa[rty] = rtx;
    wa[rtx] += wa[rty];
    va[rtx] += va[rty];
}

int main()
{
    scanf("%d%d%d", &n, &m, &w);
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        scanf("%d%d", wa + i, va + i);
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        merge(x, y);
    }
    for (int i = 1; i <= n; i++)
        if (fa[i] == i)
            prc[++tot] = wa[i], val[tot] = va[i];
    for (int i = 1; i <= tot; i++)
        for (int j = w; j >= prc[i]; j--)
            dp[j] = std::max(dp[j], dp[j - prc[i]] + val[i]);
    printf("%d", dp[w]);
    return 0;
}