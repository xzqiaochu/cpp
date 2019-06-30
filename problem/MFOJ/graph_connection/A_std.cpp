//刻录光盘(cdrom)
#include <cstdio>

const int SZ = 207;

bool g[SZ][SZ];
int n, fa[SZ], cnt;

void dfs(int x, int f)
{
    //if x==f 你需要添加一个新的连通分支
    int k = (x == f) ? 1 : 0;
    fa[x] = f;
    for (int i = 1; i <= n; ++i)
    {
        if (g[x][i] == false || i == f)
            continue;
        //若发现一个新点，直接链接下去即可
        if (fa[i] == 0)
            dfs(i, f);
        //若发现一个已经拓展过的点，则可以节省一个连通分支
        if (fa[i] == i)
            fa[i] = f, --k;
    }
    cnt += k;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1, x; i <= n; ++i)
        while (scanf("%d", &x) && x)
            g[i][x] = true;
    for (int i = 1; i <= n; ++i)
        if (fa[i] == 0)
            dfs(i, i);
    printf("%d\n", cnt);
    return 0;
}