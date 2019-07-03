// P1060 开心的金明 AC
#include <cstdio>
#include <algorithm>

const int MAXN = 25, MAXM = 30007;

int n, money, price[MAXN], val[MAXN], dp[MAXM];

int main()
{
    scanf("%d%d", &money, &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", price + i, val + i);
        val[i] *= price[i];
    }
    for (int i = 1; i <= n; i++)
        for (int j = money; j - price[i] > 0; j--)
            dp[j] = std::max(dp[j], dp[j - price[i]] + val[i]);
    printf("%d", dp[money]);
    return 0;
}