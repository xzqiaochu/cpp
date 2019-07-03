// P1164 小A点菜 AC
#include <cstdio>

const int MAXN = 107, MAXM = 1e4 + 7;

int n, m, c[MAXN], dp[MAXN][MAXM];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", c + i);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (j == c[i])
                dp[i][j] = dp[i - 1][j] + 1;
            if (j > c[i])
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - c[i]];
            if (j < c[i])
                dp[i][j] = dp[i - 1][j];
        }
    printf("%d", dp[n][m]);
    return 0;
}