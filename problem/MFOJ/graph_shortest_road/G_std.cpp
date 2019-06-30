#include <cstdio>
#include <cstring>
#include <cstdlib>
typedef long long int64;
int64 f[100][100];
int main()
{
    int64 n, v0, a;
    memset(f, 0x3f, sizeof f);
    scanf("%lld%lld", &n, &v0);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            char c[20];
            scanf("%s", c);
            if (c[0] == '-' && not c[1])
                continue;
            f[i][j] = atoll(c);
        }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (f[i][k] + f[k][j] < f[i][j])
                    f[i][j] = f[i][k] + f[k][j];
    for (int i = 1; i <= n; ++i)
        if (i != v0)
            printf("(%lld -> %lld) = %lld\n", v0, i, f[v0][i]);
    return 0;
}