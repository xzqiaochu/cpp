// 秀秀的森林（forest）
#include <cstdio>

typedef long long ll;

const int MAXN = 1e5 + 7;
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

int tot, anses[MAXN]; // 答案序列

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
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        dia[i] = a[i];
        dPoint[i].a = dPoint[i].b = i;
    }
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

int dis[MAXN], dep[MAXN], pa[MAXN][25];

int bfs(int root)
{
}

int Lca(int x, int y)
{
}

int getDis(int x, int y)
{
    int lca = Lca(x, y);
    return dis[x] + dis[y] - 2 * dis[lca] + a[lca];
}

void buildNewDiameter(int num)
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
        scanf("%d%d", &edge[i].x, &edge[i].y);
    for (int i = 1; i <= n - 1; i++)
        scanf("%d", del_list + i);
    // 读入完成
    init(); //初始化
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = ans + a[i] % P;
    anses[++tot] = ans;
    for (int i = n - 1; i >= 1; i--) // 倒序加边
    {
        int fTreeX = getRoot(edge[i].x), fTreeY = getRoot(edge[i].y);
        int temp = (dia[fTreeX] + dia[fTreeY]) % P; // 暂存两数的直径之积
        ans = (ll)ans * zpow(temp, P - 2) % P;      // 上次的 ans 除两棵树的直径（乘法逆元）
        buildNewDiameter(i);
        temp = dia[fTreeX];       // 暂存新树的直径
        ans = (ll)ans * temp % P; // ans * 新树的直径
        anses[++tot] = ans;
    }
    for (int i = tot; i >= 1; i--)
        printf("%d\n", anses[tot]);
    return 0;
}