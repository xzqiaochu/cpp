#include <cstdio>
#include <cstring>
#include <queue>
const int POINTS = 1e5 + 7, EDGES = 1e6 + 7;
struct Point
{
    int id, pre, dis, head;
    Point()
    {
        id = pre = head = 0;
        dis = 2e9;
    }
    bool operator<(const Point &b) const
    {
        return dis > b.dis;
    }
} p[POINTS];
struct Edge
{
    int u, v, w, nxt;
} e[EDGES];
inline void addEdge(int x, int u, int v, int w)
{
    e[x].u = p[u].id = u, e[x].v = p[v].id = v;
    e[x].nxt = p[u].head, p[u].head = x, e[x].w = w;
}
bool Dijkstra(int st, int dt)
{
    std::priority_queue<Point> que;
    bool *vis = new bool[POINTS];
    memset(vis, false, sizeof *vis);
    p[st].dis = 0;
    que.push(p[st]);
    while (que.size())
    {
        Point pt = que.top();
        que.pop();
        if (vis[pt.id])
            continue;
        p[pt.id] = pt;
        vis[pt.id] = true;
        if (pt.id == dt)
            return true;
        for (int i = pt.head; i; i = e[i].nxt)
        {
            int u = e[i].u, v = e[i].v;
            if (p[v].dis > p[u].dis + e[i].w)
            {
                p[v].dis = p[u].dis + e[i].w;
                que.push(p[v]);
            }
        }
    }
    return false;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int u, v, w, cnt = 1;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &u, &v, &w);
        addEdge(++cnt, u, v, w);
        addEdge(++cnt, v, u, w);
    }
    if (Dijkstra(1, n))
        printf("%d\n", p[n].dis);
    else
        puts("-1");
    return 0;
}