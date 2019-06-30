//团伙(group) AC
#include <cstdio>

const int MAXN = 1007, MAXM = 100007;

int n, m, cnt, fa[MAXN], en[MAXN];

int get(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = get(fa[x]);
}

void merge(int x, int y)
{
    fa[get(x)] = get(y);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int p, x, y;
        scanf("%d%d%d", &p, &x, &y);
        if (p == 0)
            merge(x, y);
        else
        {
            if (en[x] == 0)
                en[x] = y;
            else
                merge(en[x], y);
            if (en[y] == 0)
                en[y] = x;
            else
                merge(en[y], x);
        }
    }
    for (int i = 1; i <= n; i++)
        if (fa[i] == i)
            cnt++;
    printf("%d", cnt);
    return 0;
}