// 暗的连锁(chain) (http://www.mfstem.org/contest/36/problem/B)
// author: xzqiaochu
// status: dev
#include <cstdio>

#define next Next

const int MAXN = 1e5 + 7, MAXM = 2 * MAXN;

int n, m;
int tot, head[MAXN], ver[MAXM], next[MAXM];

void add(int x, int y)
{
    ver[++tot] = y;
    next[tot] = head[x], head[x] = tot;
}

void deal(int x, int y)
{

}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        deal(x, y);
    }
    return 0;
}