// 运输计划(transport) (http://www.mfstem.org/contest/22/problem/C)
// author: xzqiaochu (Rewrite frome kelvin's)
// status: PAC(90% AC)
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int SZP = 3e5 + 7, SZE = 2 * SZP, SZT = 25;

int n, m;
int t;

struct Edge
{
    int x, y, z, next;
    Edge() {}
    Edge(int _x, int _y, int _z, int _n) : x(_x), y(_y), z(_z), next(_n) {}
} edge[SZE];
int sumz; // 所有边权和
int head[SZP]; // 邻接表表头
int dis[SZP], tid[SZP], depth[SZP], fa[SZP][SZT]; // dfs需要处理的数据
/*
dis: 到根的距离
tid: dfs时间戳
depth: 深度
fa[i][j]: i 的 2^j 倍父亲
*/

struct Plan
{
    int x, y, lca, dis;
} plan[SZP];
int cf[SZP]; // 树上差分

// 快读
int readInt()
{
    int ans = 0;
    bool neg = false;
    char c = getchar();
    while (c != '-' && (c < '0' || c > '9'))
        c = getchar();
    if (c == '-')
        neg = true, c = getchar();
    while (c >= '0' && c <= '9')
        ans = ans * 10 + c - '0', c = getchar();
    return neg ? -ans : ans;
}

// 深搜和t的初始化
void init()
{
    dis[1] = 0;
    t = (int)(log2(n)) + 1;
}

inline void addEdge(int x, int y, int z)
{
    static int tot = 1; // 正向边偶数，反向边奇数
    /* 初始编号为2的好处：
    编号为a的边，其反向边为a^1 */
    edge[++tot] = Edge(x, y, z, head[x]);
    head[x] = tot;
}

// 深搜预处理
void dfs(int x, int pa, int dep)
{
    static int cnt = 0; // 若不赋初值，默认为0（和全局变量一样）
    tid[++cnt] = x; // dfs时间戳
    depth[x] = dep;
    for (int i = 1; i <= t; i++) // 计算当前点的 1, 2, 4, 8, 16... 倍父亲
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    for (int i = head[x]; i; i = edge[i].next)
    {
        int y = edge[i].y;
        if (y != pa)
        {
            fa[y][0] = x;
            dis[y] = dis[x] + edge[i].z;
            dfs(y, x, dep + 1);
        }
    }
}

int lca(int x, int y)
{
    if (depth[x] > depth[y])
        swap(x, y);
    int d = depth[y] - depth[x];

    // for (int i = t; i >= 0; i--)
    //     if (depth[fa[y][i]] >= depth[x])
    //         y = fa[y][i];

    for (int i = 0; i <= t; i++)
        if ((1 << i) & d)
            y = fa[y][i];

    if (x == y)
        return x;
    for (int i = t; i >= 0; i--)
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}

bool check(int mid)
{
    int cnt = 0, ans = 0;
    memset(cf, 0, sizeof(cf));
    for (int i = 1; i <= m; i++)
        if (plan[i].dis > mid)
        {
            cf[plan[i].x]++, cf[plan[i].y]++;
            cf[plan[i].lca] -= 2;
            ans = max(ans, plan[i].dis - mid);
            cnt++;
        }
    if (cnt == 0)
        return true;
    for (int i = n; i >= 1; i--)
        cf[fa[tid[i]][0]] += cf[tid[i]];
    for (int i = 2; i <= n; i++)
        if (cf[i] == cnt && dis[i] - dis[ fa[i][0] ] >= ans)
            return true;
    return false;
}

int main()
{
    // freopen("transport.in", "r", stdin);
    // freopen("transport.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n - 1; i++)
    {
        int x = readInt(), y = readInt(), z = readInt();
        addEdge(x, y, z), addEdge(y, x, z);
        sumz += z;
    }
    init();
    dfs(1, 0, 1);
    for (int i = 1; i <= m; i++)
    {
        plan[i].x = readInt(), plan[i].y = readInt();
        plan[i].lca = lca(plan[i].x, plan[i].y);
        plan[i].dis = dis[plan[i].x] + dis[plan[i].y] - 2 * dis[plan[i].lca];
    }
    int low = 0, high = sumz;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (check(mid))
            high = mid - 1;
        else
            low = mid + 1;
    }
    printf("%d", low);
    return 0;
}