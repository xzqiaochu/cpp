//最短路(spfa) AC
#include <cstdio>
#include <iostream>
#include <utility>
#include <queue>

#define next Next

using namespace std;

const int MAXN = 1e5 + 7, MAXM = (5e5 + 7) * 2, INF = 0x3f3f3f3f;

int n, m;
int tot, head[MAXN], edge[MAXM], to[MAXM], next[MAXM];
int d[MAXN];
bool v[MAXN];
priority_queue< pair<int, int> > q;

inline void add(int x, int y, int z)
{
    edge[++tot] = z, to[tot] = y;
    next[tot] = head[x], head[x] = tot;
}

bool dijkstra()
{
    for (int i = 1; i <= n; i++)
        d[i] = INF;
    d[1] = 0;
    q.push(make_pair(0, 1)); // 第一维 距离（相反数），第二维 编号
    while (!q.empty())
    {
        int x = q.top().second;
        q.pop();
        if (v[x])
            continue;
        v[x] = true; // 标记节点x已被用过
        if (x == n)
            return true;
        for (int i = head[x]; i; i = next[i])
        {
            int y = to[i], z = edge[i];
            if (d[x] + z < d[y])
            {
                d[y] = d[x] + z;
                q.push(make_pair(-d[y], y));
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
        add(y, x, z);
    }
    if (dijkstra())
        printf("%d", d[n]);
    else
        printf("%d", -1);
    return 0;
}