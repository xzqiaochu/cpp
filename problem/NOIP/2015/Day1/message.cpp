// 信息传递(message) (http://www.mfstem.org/contest/21/problem/B)
// author: xzqiaochu (Rewrite from luogu)
// status: AC
#include <cstdio>
#include <algorithm>

using std::min;

const int SZ = 2e5 + 7, INF = 0x3f3f3f3f;

int n, fa[SZ], d[SZ];
int minn = INF;

int getRoot(int x)
{
    if (fa[x] != x)
    {
        int last = fa[x];
        fa[x] = getRoot(fa[x]);
        d[x] += d[last];
    }
    return fa[x];
}

void check(int x, int y)
{
    int rtx = getRoot(x), rty = getRoot(y);
    if (rtx != rty)
        fa[rtx] = rty, d[x] = d[y] + 1;
    else
        minn = min(minn, d[x] + d[y] + 1);
}

int main()
{
    // freopen("message.in", "r", stdin);
    // freopen("message.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d", &t);
        check(i, t);
    }
    printf("%d", minn);
    return 0;
}