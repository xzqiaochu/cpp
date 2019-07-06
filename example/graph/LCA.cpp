/* 最近公共祖先(LCA) - 树上倍增法
时间复杂度: O(log n)
出处：算法竞赛-图论-树的直径与最近公共祖先 0x63 P371
最后修改时间：2019-07-06 */

#include <cstdio>
#include <cmath>
#include <queue>

using namespace std;

#define next Next

const int MAXN = 50007, MAXM = 2 * MAXN, MAXK = 25;

int n, m, a, b;
int tot, head[MAXN], ver[MAXM], edge[MAXM], next[MAXM];
int t, dis[MAXN], dep[MAXN], f[MAXN][MAXK];
queue<int> q;

void init()
{
    t = (int)(log2(n)) + 1;
}

void add(int x, int y, int z)
{
    ver[++tot] = y, edge[tot] = z;
    next[tot] = head[x], head[x] = tot;
}

void bfs()
{
    q.push(1), dep[1] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = next[i])
        {
            int y = ver[i], z = edge[i];
            if (dep[y]) // 若边y已被访问，即dep[y] != 0（dep[y] 初始值为0）
                continue;
            dep[y] = dep[x] + 1;
            dis[y] = dis[x] + z;
            f[y][0] = x;
            for (int j = 1; j <= t; j++)
                f[y][j] = f[f[y][j - 1]][j - 1]; // y的2^k倍祖先 = y的2^(k-1)倍祖先 的 2^(k-1)倍祖先
            q.push(y);
        }
    }
}

int lca(int x, int y)
{
    if (dep[y] > dep[x])
        swap(x, y);
    for (int i = t; i >= 0; i--)
        if (dep[f[y][i]] >= dep[x])
            y = f[y][i];
    if (x == y)
        return x;
    for (int i = t; i >= 0; i--)
        if (f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    return f[x][0];
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z), add(y, x, z);
    }
    scanf("%d%d", &a, &b);
    init();
    bfs();
    printf("%d", dis[a] + dis[b] - 2 * dis[lca(a, b)]);
    return 0;
}