// 玩具谜题(toy) (http://www.mfstem.org/contest/23/problem/A)
// author: xzqiaochu (Copy from kelvin's)
// status: AC
#include <cstdio>

const int SZ = 100010;

int n, m, q[SZ];
int  d, k;
char ss[SZ][15];

int main()
{
    freopen("toy.in", "r", stdin);
    freopen("toy.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d%s", &q[i], ss[i]);
    int cur = 0;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &d, &k);
        if (q[cur] == d)
            cur = (cur - k + n) % n;
        else
            cur = (cur + k) % n;
    }
    printf("%s", ss[cur]);
    return 0;
}