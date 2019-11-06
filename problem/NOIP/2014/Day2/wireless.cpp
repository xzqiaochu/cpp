// 无线网路发射器选址(wireless)
// author: xzqiaochu
// status: AC
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 129;

int d, n, g[MAXN][MAXN];
int ans, cnt;

void init()
{
    for (int i = 0; i <= 128; i++)
        for (int j = 0; j <= 128; j++)
            g[i][j] = g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1] + g[i][j];
}

inline int getSum(int x1, int y1, int x2, int y2)
{
    x1 = max(0, x1), y1 = max(0, y1);
    x2 = min(128, x2), y2 = min(128, y2);
    return g[x2][y2] - g[x1 - 1][y2] - g[x2][y1 - 1] + g[x1 - 1][y1 - 1];
}

int main()
{
    // freopen("wireless.in", "r", stdin);
    // freopen("wireless.out", "w", stdout);
    scanf("%d%d", &d, &n);
    for (int i = 1; i <= n; i++)
    {
        int x, y, k;
        scanf("%d%d%d", &x, &y, &k);
        g[x][y] = k;
    }
    init();
    for (int i = 0; i <= 128; i++)
        for (int j = 0; j <= 128; j++)
        {
            int sum = getSum(i - d, j - d, i + d, j + d);
            if (sum > ans)
                ans = sum, cnt = 1;
            else if (sum == ans)
                cnt++;
        }
    printf("%d %d", cnt, ans);
    return 0;
}