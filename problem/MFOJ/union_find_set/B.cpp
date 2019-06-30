//打击犯罪(black) AC
#include <cstdio>

const int MAXN = 1007;

int n, g[MAXN][MAXN], fa[MAXN], sz[MAXN];

int get(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = get(fa[x]);
}

void merge(int x, int y)
{
    int fx = get(x), fy = get(y);
    if (fx == fy) return;
    fa[fy] = fx, sz[fx] += sz[fy]; // y 加入 x
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        fa[i] = i, sz[i] = 1;
    for (int x = 1; x <= n; x++)
    {
        int k;
        scanf("%d", &k);
        for (int i = 1; i <= k; i++)
        {
            int y;
            scanf("%d", &y);
            g[x][y] = true;
        }
    }
    int limit = n >> 1;
    for (int i = n; i >= 1; i--)
    {
        for (int j = i + 1; j <= n; j++)
            if (g[i][j])
                merge(i, j);
        if (sz[i] > limit)
        {
            printf("%d", i);
            break;
        }
    }
    return 0;
}