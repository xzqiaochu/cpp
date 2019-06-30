#include <cstdio>
#include <cstring>

bool g[155][155], vis[155], flag;
int ans[155], n, m;

void Hamilton(int a, int pos)
{
    if (flag == true)
        return;
    if (pos == n + 1)
    {
        if (g[ans[1]][ans[n]])
            flag = true;
    }
    else
        for (int i = 2; i <= n; ++i)
            if (g[a][i] && !vis[i] && !flag)
            {
                vis[i] = true;
                ans[pos] = i;
                Hamilton(i, pos + 1);
                vis[i] = false;
            }
}

int main()
{
    int a, b;
    while (~scanf("%d%d", &n, &m))
    {
        memset(vis, false, sizeof vis);
        memset(g, false, sizeof g);
        memset(ans, 0, sizeof ans);
        flag = false;
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d%d", &a, &b);
            g[a][b] = g[b][a] = true;
        }
        ans[1] = 1;
        Hamilton(1, 2);
        if (flag)
            for (int i = 1; i <= n; ++i)
                printf("%d%c", ans[i], i == n ? '\n' : ' ');
        else
            printf("no solution\n");
    }
    return 0;
}
