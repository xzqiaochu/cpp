// 点的距离(distance) (http://www.mfstem.org/contest/36/problem/A)
// author: xzqiaochu
// status: AC
#include <cstdio>
#include <cmath>
#include <queue>

#define next Next

using namespace std;

const int MAXN = 1e5 + 7, MAXM = 2 * MAXN, MAXT = 25;

int n;
int tot, head[MAXN], ver[MAXM], next[MAXM];
int t, d[MAXN], f[MAXN][MAXT];
queue<int> q;

inline void add(int x, int y)
{
    ver[++tot] = y;
    next[tot] = head[x], head[x] = tot;
}

void bfs()
{
    d[1] = 1;
    q.push(1);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = next[i])
        {
            int y = ver[i];
            if (d[y])
                continue;
            d[y] = d[x] + 1;
            f[y][0] = x;
            for (int j = 1; j <= t; j++)
                f[y][j] = f[f[y][j - 1]][j - 1];
            q.push(y);
        }
    }
}

int Lca(int x, int y)
{
    if (d[x] > d[y])
        swap(x, y);
    for (int i = t; i >= 0; i--)
        if (d[f[y][i]] >= d[x])
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
    return d[x] + d[y] - 2 * d[lca];
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
    }
    t = (int)(log2(n)) + 1;
    bfs();
    int Q;
    scanf("%d", &Q);
    while (Q--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", getDis(x, y));
    }
    return 0;
}