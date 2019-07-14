// 寻找道路(road)
// author: xzqiaochu (Rewrite from kelvin's)
// status: AC
#include <cstdio>
#include <cstring>
#include <queue>

const int SZ = 1e4 + 7, ESZ = 2e5 + 7, INF = 0x3f3f3f3f;

int n, m, s, t;
int tot, head[SZ];
bool vis[SZ], valid[SZ];
struct Point
{
    int id, dis;
} pt[SZ];
struct Edge
{
    int u, v, next;
    Edge(int _u = 0, int _v = 0, int _n = 0) : u(_u), v(_v), next(_n) {}
} edge[ESZ];

inline void addEdge(int u, int v)
{
    edge[++tot] = Edge(u, v, head[u]);
    head[u] = tot;
}

void Dijkstra(int sta)
{
    std::queue<Point> q;
    pt[sta].dis = 0;
    q.push(pt[sta]);
    while (!q.empty())
    {
        Point u = q.front();
        q.pop();
        if (vis[u.id])
            continue;
        vis[u.id] = true;
        // pt[u.id] = u;
        for (int i = head[u.id]; i; i = edge[i].next)
        {
            int v = edge[i].v;
            // if (!vis[v] && u.dis + 1 < pt[v].dis)
            // {
            pt[v].dis = u.dis + 1;
            q.push(pt[v]);
            // }
        }
    }
}

int main()
{
    // freopen("road.in", "r", stdin);
    // freopen("road.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(v, u);
    }
    scanf("%d%d", &s, &t);
    for (int i = 1; i <= n; i++)
        pt[i].id = i, pt[i].dis = INF;
    Dijkstra(t);
    for (int i = 1; i <= n; i++)
        valid[i] = vis[i];
    for (int i = 1; i <= m; i++)
        if (vis[edge[i].u] == false)
            valid[edge[i].v] = false;
    memset(vis, false, sizeof(vis));
    memset(head, 0, sizeof(head));
    tot = 0;
    for (int i = 0; i <= n; i++)
        pt[i].dis = INF;
    for (int i = 1; i <= m; i++)
        if (valid[edge[i].u] && valid[edge[i].v])
            addEdge(edge[i].v, edge[i].u);
    Dijkstra(s);
    if (pt[t].dis == INF)
        printf("-1");
    else
        printf("%d", pt[t].dis);
}