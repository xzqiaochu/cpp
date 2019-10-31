//亲戚(relation) AC
#include <cstdio>

const int MAXN = 1e6 + 5;

int n, m, q;
int fa[MAXN];

int getRoot(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = getRoot(fa[x]);
}

void merge(int x, int y)
{
    int fx = getRoot(x), fy = getRoot(y);
    if (fx != fy)
        fa[fx] = fy;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        merge(x, y);
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (getRoot(x) == getRoot(y))
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}