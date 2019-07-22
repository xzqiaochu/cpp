// 联合权值(link) (http://www.mfstem.org/contest/18/problem/B)
// author: xzqiaochu
// status: AC
#include <cstdio>
#include <algorithm>

using std::max;

const int SZP = 2e5 + 7, SZE = 2 * SZP, P = 10007;

int n;
int w[SZP];
struct Edge
{
    int x, y, next;
    Edge() {}
    Edge(int _x, int _y, int _n) : x(_x), y(_y), next(_n) {}

} edge[SZE];
int head[SZP];
int ans1, ans2;

inline void addEdge(int x, int y)
{
    static int tot;
    edge[++tot] = Edge(x, y, head[x]);
    head[x] = tot;
}

int main()
{
    // freopen("link.in", "r", stdin);
    // freopen("link.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        addEdge(x, y), addEdge(y, x);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", w + i);

    for (int x = 1; x <= n; x++)
    {
        int max1 = 0, max2 = 0;
        int sum = 0, sqrs = 0;
        for (int i = head[x]; i; i = edge[i].next)
        {
            int y = edge[i].y;
            if (w[y] > max1)
            {
                max2 = max1;
                max1 = w[y];
            } else if (w[y] > max2)
                max2 = w[y];
            sum = (sum + w[y]) % P;
            sqrs = (sqrs + w[y] * w[y]) % P;
        }
        ans1 = max(ans1, max1 * max2);
        ans2 = (ans2 + sum * sum - sqrs) % P;
    }

    printf("%d %d", ans1, ans2);
    return 0;
}