// 组合数问题(problem) (http://www.mfstem.org/contest/24/problem/A)
// author: xzqiaochu
// status: AC
#include <cstdio>

const int SZ = 2003;

int t, k, n, m;
int c[SZ][SZ], s[SZ][SZ];

void init(int k)
{
    c[1][1] = 1;
    for (int i = 0; i <= 2000; i++)
        c[i][0] = 1;
    for (int i = 2; i <= 2000; i++)
        for (int j = 1; j <= i; j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % k;
    // for (int i = 1; i <= 10; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //         printf("%d ", c[i][j]);
    //     puts("");
    // }
    for (int i = 2; i <= 2000; i++)
    {
        for (int j = 1; j <= i; j++)
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (c[i][j] == 0);
        s[i][i + 1] = s[i][i];
    }
}

int main()
{
    // freopen("problem.in", "r", stdin);
    // freopen("problem.out", "w", stdout);
    scanf("%d%d", &t, &k);
    init(k);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        m = m > n ? n : m;
        printf("%d\n", s[n][m]);
    }
    // init(100);
    return 0;
}