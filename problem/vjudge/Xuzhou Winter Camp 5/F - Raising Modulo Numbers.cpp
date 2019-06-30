#include <cstdio>

typedef long long ll;

ll qpow(ll a, ll b, ll m)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return ans;
}

int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--)
    {
        int m, h, ans = 0;
        scanf("%d%d", &m, &h);
        while (h--)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            ans = (ans + qpow(a, b, m)) % m;
        }
        printf("%d\n", ans);
    }
    return 0;
}