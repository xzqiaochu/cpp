// 飞扬的小鸟(bird) ((http://www.mfstem.org/contest/18/problem/C)
// author: xzqiaochu
// status: dev
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using std::min;

const int SZN = 1e4 + 7, SZM = 1e3 + 7, INF = 0x3f3f3f3f;

int n, m, k;
struct Click
{
    int up, down;
} c[SZN];
int cnt[SZN], f[SZN][SZM];
int i, j;

void initF()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            f[i][j] = -1;
}

void initPre()
{
    for (int i = 1; i <= n; i++)
        cnt[i] += cnt[i - 1];
}

void updateBy(int val, bool add = true, int i = i, int j = j)
{
    if (val < 0)
        return;
    if (f[i][j] == -2)
        return;
    if (f[i][j] < 0)
        f[i][j] = val + add;
    else
        f[i][j] = min(f[i][j], val + add);
}

void check()
{
    for (int k = 1; k <= m; k++)
        if (f[i][k] >= 0)
            return;
    printf("0\n%d", cnt[i - 1]);
    exit(0);
}

void dp()
{
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (f[i][j] == -2)
                continue;
            if (j + c[i].down <= m)
                updateBy(f[i - 1][j + c[i].down], false);
            for (int k = 1; j - k * c[i].up >= 1; k++)
                updateBy(f[i - 1][j - k * c[i].up]);
            for (int k = 0; k < c[i].up; k++)
                if (m - k >= 1)
                    updateBy(f[i - 1][m - k], i, m);
        }
        check();
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &c[i].up, &c[i].down);
    initF();
    for (int i = 1; i <= k; i++)
    {
        int P, L, H;
        scanf("%d%d%d", &P, &L, &H);
        for (int i = 1; i <= L; i++)
            f[P][i] = -2;
        for (int i = H; i <= m; i++)
            f[P][i] = -2;
        cnt[P] = 1;
    }
    initPre();
    dp();
    // int ans = INF;
    for (int i = 1; i <= m; i++)
        printf("%d\n", f[n][i]);
    // for (int i = 1; i <= m; i++)
    //     if (f[n][i] >= 0)
    //         ans = min(ans, f[n][i]);
    // printf("1\n%d", ans);
    return 0;
}