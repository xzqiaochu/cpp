#include <iostream>
#include <cstring>

using namespace std;

int n, m, v[101], w[101], dp[101][101];

int main()
{
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m + v[i]; j++)
        {
            if (j >= v[i])
            {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for (int i = m + 1; i <= m + v[n]; i++)
        cout << dp[n][i] << ' ';
    // cout << dp[n][m];
}