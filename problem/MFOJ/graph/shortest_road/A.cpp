//最短路(short) AC
#include <cstdio>
#include <cstring>
#include <cmath>

const int MAXN = 105;

int n, m, s, t, x[105], y[105];
double dis[MAXN][MAXN];

int main()
{
    memset(dis, 0x7f, sizeof(dis));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", x + i, y + i);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int from, to;
        scanf("%d%d", &from, &to);
        double d = sqrt(pow(x[from] - x[to], 2) + pow(y[from] - y[to], 2));
        dis[from][to] = d, dis[to][from] = d;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (k != i && k != j && i != j)
                    if (dis[i][j] > dis[i][k] + dis[k][j])
                        dis[i][j] = dis[i][k] + dis[k][j];
    scanf("%d%d", &s, &t);
    printf("%.2f", dis[s][t]);
    return 0;
}