//刻录光盘(cdrom) AC
#include <cstdio>

const int SZ = 205;

bool g[SZ][SZ];
int n, cnt, fa[SZ];

void dfs(int x, int f)
{
    int k = (x == f) ? 1 : 0;
    fa[x] = f;
    for (int i = 1; i <= n; i++)
    {
        if (g[x][i] == false || i == f)
            continue;
        if (fa[i] == 0)
            dfs(i, f);
        if (fa[i] == i)
            fa[i] = f, k--;
    }
    cnt += k;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1, j; i <= n; i++)
        while (scanf("%d", &j) && j)
            g[i][j] = true;
    for (int i = 1; i <= n; i++)
        if (fa[i] == 0)
            dfs(i, i);
    printf("%d", cnt);
    return 0;
}