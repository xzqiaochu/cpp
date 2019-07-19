// 换教室(classroom) (http://www.mfstem.org/contest/23/problem/C)
// author: xzqiaochu (Copy from kelvin's)
// status: AC
#include <cstdio>
#include <cstring>
#include <algorithm>

using std::min;

const int SZN = 2e3 + 7, SZV = 307;
const double INF = 1e100 + 7;

int n, m, v, e;
int cs1[SZN], cs2[SZN], g[SZV][SZV];
double k[SZN][2], f[SZN][SZN][2];
/* f[i][j][k]
i: 第i时间段
j: 申请了j次
k: 0/1 当前(第i时间段)是否申请
*/

void floyd()
{
    for (int k = 1; k <= v; k++)
        for (int i = 1; i <= v; i++)
            if (k != i)
                for (int j = 1; j <= v; j++)
                    if (k != j && i != j)
                        if (g[i][k] + g[k][j] < g[i][j])
                            g[i][j] = g[i][k] + g[k][j];
}

void dp()
{
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            f[i][j][0] = f[i][j][1] = INF;
    f[1][0][0] = f[1][1][0] = f[1][1][1] = 0;
    for (int i = 2; i <= n; i++)
    {
        int c1 = cs1[i-1], c1d = cs2[i-1];
        int c2 = cs1[i], c2d = cs2[i];
        f[i][0][0] = f[i-1][0][0] + g[c1][c2];
        for (int j = 1, end = min(i, m); j <= end; j++)
        {
            double z0 = f[i-1][j][0] + g[c1][c2];
            double z1 = f[i-1][j][1] + g[c1][c2] * k[i-1][1] + g[c1d][c2] * k[i-1][0];
            f[i][j][0] = min(f[i][j][0], min(z0, z1));
            z0 = f[i-1][j-1][0] + g[c1][c2d] * k[i][0] + g[c1][c2] * k[i][1];
            z1 = f[i-1][j-1][1]
                + g[c1][c2]   * k[i-1][1] * k[i][1]
                + g[c1][c2d]  * k[i-1][1] * k[i][0]
                + g[c1d][c2]  * k[i-1][0] * k[i][1]
                + g[c1d][c2d] * k[i-1][0] * k[i][0];
            f[i][j][1] = min(f[i][j][1], min(z0, z1));
        }
    }
}

int main()
{
    // freopen("classroom.in", "r", stdin);
    // freopen("classroom.out", "w", stdout);
    scanf("%d%d%d%d", &n, &m, &v, &e);
    for (int i = 1; i <= n; i++)
        scanf("%d", cs1 + i);
    for (int i = 1; i <= n; i++)
        scanf("%d", cs2 + i);
    for (int i = 1; i <= n; i++)
        scanf("%lf", &k[i][0]), k[i][1] = 1 - k[i][0];
    memset(g, 0x3f, sizeof(g));
    for (int i = 1; i <= e; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        g[x][y] = g[y][x] = min(g[x][y], z);
    }
    // 必须把 g[i][i] 赋值为0，因为dp的过程中有可能 下一节课的教室和当前课的教室相同
    for (int i = 1; i <= v; i++)
        g[i][i] = 0;
    floyd();
    dp();
    double ans = INF;
    for (int i = 0; i <= m; i++)
        ans = min(ans, min(f[n][i][0], f[n][i][1]));
    printf("%.2lf", ans);
    return 0;
}