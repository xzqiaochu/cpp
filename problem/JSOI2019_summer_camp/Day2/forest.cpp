// 秀秀的森林（forest）
#include <cstdio>
#include <cmath>
#include <queue>

#define next Next

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 7, MAXM = MAXN, MAXK = 25;
const ll P = 1e9 + 7;

int n, a[MAXN];
struct Edge
{
    int x, y;
} edge[MAXN];
int del_list[MAXN];
// 以上为保存读入数据所用

int fa[MAXN];
int dia[MAXN]; // 每棵树的直径
struct DPoint
{
    int a, b;
} dPoint[MAXN]; // 每棵树的直径端点

int tot, head[MAXN], ver[MAXM], next[MAXM]; // 邻接表保存未砍的树
int t, dis[MAXN], dep[MAXN], f[MAXN][MAXK]; // LCA相关
queue<int> q;

int p, anses[MAXN]; // 答案序列

int zpow(int a, int b)
{
    int ans = 1;
    for (; b; b >>= 1)
    {
        if (b & 1)
            ans = (ll)ans * a % P;
        a = (ll)a * a % P;
    }
    return ans;
}

void init()
{
    t = (int)(log2(n)) + 1;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        dia[i] = a[i];
        dPoint[i].a = dPoint[i].b = i;
    }
}

void add(int x, int y)
{
    ver[++tot] = y;
    next[tot] = head[x], head[x] = tot;
}

int getRoot(int x)
{
    return fa[x] == x ? x : (fa[x] = getRoot(fa[x]));
}

void merge(int x, int y)
{
    int rtx = getRoot(x), rty = getRoot(y);
    if (rtx == rty)
        return;
    fa[rty] = rtx; // y加入x
}

void bfs()
{
    q.push(1), dep[1] = a[1];
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = next[i])
        {
            int y = ver[i];
            if (dep[y])
                continue;
            dep[y] = dep[x] + 1;
            dis[y] = dis[x] + a[y];
            f[y][0] = x;
            for (int j = 1; j <= t; j++)
                f[y][j] = f[f[y][j - 1]][j - 1];
            q.push(y);
        }
    }
}

int Lca(int x, int y)
{
    if (dep[x] > dep[y])
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

int getDis(int x, int y)
{
    int lca = Lca(x, y);
    return dis[x] + dis[y] - 2 * dis[lca] + a[lca];
}

void build(int num)
{
    int rst = 0;
    int fTreeX = getRoot(edge[num].x), fTreeY = getRoot(edge[num].y);
    int p[5];
    p[1] = dPoint[fTreeX].a, p[2] = dPoint[fTreeX].b;
    p[3] = dPoint[fTreeY].a, p[4] = dPoint[fTreeY].b;
    for (int i = 1; i <= 4; i++)
        for (int j = i + 1; j <= 4; j++)
        {
            int temp = getDis(p[i], p[j]);
            if (temp > rst)
            {
                rst = temp;
                dPoint[fTreeX].a = p[i];
                dPoint[fTreeX].b = p[j]; // 保存新树的直径端点
            }
        }
    dia[fTreeX] = rst;               // 保存新树直径
    merge(edge[num].x, edge[num].y); // 加边合并
}

int main()
{
    // freopen("forest.in", "r", stdin);
    // freopen("forest.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
        edge[i].x = x, edge[i].y = y;
    }
    for (int i = 1; i <= n - 1; i++)
        scanf("%d", del_list + i);
    // 读入完成
    init(); // 初始化
    bfs(); // 预处理
    int ans = 1;
    for (int i = 1; i <= n; i++)
        ans = (ll)ans * a[i] % P;
    anses[++p] = ans;
    for (int i = n - 1; i >= 1; i--) // 倒序加边
    {
        int now = del_list[i];
        int fTreeX = getRoot(edge[now].x), fTreeY = getRoot(edge[now].y);
        int temp = ((ll)dia[fTreeX] * dia[fTreeY]) % P; // 暂存两数的直径之积
        ans = (ll)ans * zpow(temp, P - 2) % P;      // 上次的 ans 除两棵树的直径（乘法逆元）
        build(now);
        temp = dia[fTreeX];       // 暂存新树的直径
        ans = (ll)ans * temp % P; // ans * 新树的直径
        anses[++p] = ans;
    }
    for (int i = p; i >= 1; i--)
        printf("%d\n", anses[i]);
    return 0;
}