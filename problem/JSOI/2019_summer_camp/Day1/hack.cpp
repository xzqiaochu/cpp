// hack
#include <cstdio>

#define next Next

const int MAXN = 8e5 + 7, MAXM = 1.2e6 + 7;

int n, m;
int tot, head[MAXN], to[MAXM], next[MAXM];

void add(int x, int y)
{
    to[++tot] = y;
    next[tot] = head[x], head[x] = tot;
}

int main()
{
    freopen("hack.in", "r", stdin);
    freopen("hack.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &n, &m);
        add(n, m);
        add(m, n);
    }
    return 0;
}