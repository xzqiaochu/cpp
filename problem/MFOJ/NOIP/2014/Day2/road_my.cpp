// 寻找道路(road)
// author: xzqiaochu
// status: AC
#include <cstdio>
#include <cstring>
#include <queue>

using std::queue;

const int SZP = 1e4 + 7, SZE = 2e5 + 7, INF = 0x3f3f3f3f;

int n, m, s, t;

struct Point
{
    int id, dis;
} pt[SZP];

struct Edge
{
    int x, y, next;
    Edge(int _x = 0, int _y = 0, int _next = 0) : x(_x), y(_y), next(_next) {}
} edge[SZE];
int tot, head[SZP];

queue<Point> q;
bool vis[SZP], valid[SZP];

inline void addEdge(int x, int y)
{
    edge[++tot] = Edge(x, y, head[x]);
    head[x] = tot;
}

void Dijkstra(int sta)
{
    q = queue<Point>();
    for (int i = 1; i <= n; i++)
        pt[i].id = i, pt[i].dis = INF;
    memset(vis, false, sizeof(vis));
    pt[sta].dis = 0;
    q.push(pt[sta]), vis[sta] = true;
    while (!q.empty())
    {
        Point ptx = q.front();
        q.pop();
        for (int i = head[ptx.id]; i; i = edge[i].next)
        {
            int y = edge[i].y;
            if (!vis[y])
            {
                pt[y].dis = pt[ptx.id].dis + 1;
                q.push(pt[y]), vis[y] = true;
            }
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
        int x, y;
        scanf("%d%d", &x, &y);
        addEdge(y, x);
    }
    scanf("%d%d", &s, &t);
    Dijkstra(t);
    for (int i = 1; i <= n; i++)
        valid[i] = vis[i];
    for (int i = 1; i <= m; i++)
        if (vis[edge[i].x] == false)
            valid[edge[i].y] = false;
    tot = 0;
    memset(head, 0, sizeof(head));
    for (int i = 1; i <= m; i++)
        if (valid[edge[i].x] && valid[edge[i].y])
            addEdge(edge[i].y, edge[i].x);
    Dijkstra(s);
    if (pt[t].dis == INF)
        printf("-1");
    else
        printf("%d", pt[t].dis);
    return 0;
}