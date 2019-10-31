//牛的旅行(traval) AC
#include <cstdio>
#include <iostream>
#include <cmath>

const int SZ = 155;
const double INF = 1e18;

int n, x[SZ], y[SZ];
double ans = INF, dis[SZ][SZ], m[SZ];

inline double calcDis(int &i, int &j)
{
    return sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
}

void floyed()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", x + i, y + i);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int reach;
            scanf("%1d", &reach);
            if (reach)
                dis[i][j] = calcDis(i, j);
            else if (i != j)
                dis[i][j] = INF;
        }
    floyed();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (dis[i][j] != INF)
                m[i] = std::max(m[i], dis[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (dis[i][j] == INF)
                ans = std::min(ans, m[i] + m[j] + calcDis(i, j));
    for (int i = 1; i <= n; i++)
        ans = std::max(ans, m[i]);
    printf("%.6f", ans);
    return 0;
}