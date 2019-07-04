/* helpers PAC(3WA)
author: xzqiaochu */
#include <cstdio>

typedef long long ll;

const int MAXN = 1e7 + 7, P = 998244353;

int n, s, a[MAXN];
ll sp;

int zpow(int a, int b, int p)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ll)ans * a % p;
        a = (ll)a * a % p;
        b >>= 1;
    }
    return ans;
}

int main()
{
    // freopen("helpers.in", "r", stdin);
    // freopen("helpers.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i), s += a[i];
    sp = zpow(s, P - 2, P);
    for (int i = 1; i <= n; i++)
        printf("%lld ", a[i] * sp % P);
    return 0;
}