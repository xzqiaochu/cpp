/* 最近公共祖先(LCA) - 树上倍增法
时间复杂度: O(log n)
出处：算法竞赛-图论-树的直径与最近公共祖先 0x63 P371
最后修改时间：2019-11-13 */
#include <cstdio>
#include <cmath>
#include <cstdio>
#include <queue>
using std::queue;
const int VSZ = 1e5 + 7, ESZ = 2 * VSZ, MAXT = 25;

int n, m, a, b;

int head[VSZ];
struct Edge {
    int to, weight, next;
} edge[ESZ];

bool vis[VSZ];
int t, dis[VSZ], dep[VSZ], fa[VSZ][MAXT];

void mainInit()
{
    t = (int)(log2(n)) + 1;
}

void addEdge(int x, int y, int z)
{
    static int tot = 0;
    edge[++tot].to = y, edge[tot].weight = z;
    edge[tot].next = head[x], head[x] = tot;
}

// 清空 vis fa
void bfsInit() {
    for (int i = 1; i <= n; i++) {
        vis[i] = false;
        for (int k = 1; k <= t; k++)
            fa[i][k] = 0;
    }
}

// 预处理：dep dis fa
void bfs()
{
    bfsInit();
    queue<int> q;
    dep[1] = 1, dis[1] = 0, fa[1][0] = 0;
    vis[1] = true;
    q.push(1);
    while (!q.empty())
    {
        int x = q.front(); q.pop();
        for (int i = head[x]; i; i = edge[i].next)
        {
            int y = edge[i].to, z = edge[i].weight;
            if (vis[y])
                continue;
            vis[y] = true;
            dep[y] = dep[x] + 1;
            dis[y] = dis[x] + z;
            fa[y][0] = x;
            for (int k = 1; k <= t; k++)
                fa[y][k] = fa[ fa[y][k-1] ][k-1]; // y的2^k倍祖先 = y的2^(k-1)倍祖先 的 2^(k-1)倍祖先
            q.push(y);
        }
    }
}

int Lca(int x, int y)
{
    if (dep[x] < dep[y]) // 使得x的深度最大
        std::swap(x, y);
    for (int i = t; i >= 0; i--)
        if (dep[fa[x][i]] >= dep[y]) // 调整x（上升），使得x和y的深度相同
            x = fa[x][i];
    if (x == y) // 已经是同一个点，直接返回（一定要特判）
        return x;
    for (int i = t; i >= 0; i--) // x和y一起往上跳
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return fa[x][0]; // 此时x和y的父节点相同，其父节点即为最近公共祖先
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        addEdge(x, y, z), addEdge(y, x, z);
    }
    scanf("%d%d", &a, &b);
    mainInit();
    bfs();
    int lca = Lca(a, b);
    printf("%d", dis[a] + dis[b] - 2 * dis[lca]);
    return 0;
}