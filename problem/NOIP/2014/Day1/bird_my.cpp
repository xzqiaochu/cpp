// 飞扬的小鸟(bird) (http://www.mfstem.org/contest/18/problem/C)
// author: xzqiaochu
// status: AC
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1e4 + 7, MAXM = 1e3 + 7, INF = 0x3f3f3f3f;

int n, m, k;
struct Click
{
    int up, down;
} c[MAXN];
int f[MAXN][MAXM], cnt[MAXN];
int i, j;

void init()
{
    for (int i = 1; i <= n; i++)
        cnt[i] += cnt[i - 1];
    for (int i = 1; i <= m; i++)
        f[0][i] = 0;
}

inline void updateWith(int val, int j = j)
{
    if (val < 0)
        return;
    if (f[i][j] == -1)
        f[i][j] = val;
    else if (f[i][j] != -2)
        f[i][j] = min(f[i][j], val);
}

void check()
{
    for (int ii = 1; ii <= m; ii++)
        if (f[i][ii] >= 0)
            return;
    printf("0\n%d", cnt[i - 1]);
    exit(0);
}

void dp()
{
    for (i = 1; i <= n; i++)
    {
        for (int k = 1; k <= c[i].up; k++)
        {
            int best;
            if (f[i - 1][k] >= 0)
                best = f[i - 1][k] + 1;
            else
                best = -1;
            for (j = k + c[i].up; j <= m; j += c[i].up)
            {
                if (best >= 0)
                {
                    updateWith(best);
                    if (f[i - 1][j] >= 0)
                        best = min(f[i - 1][j], best) + 1;
                    else
                        best++;
                }
                else if (f[i - 1][j] >= 0)
                    best = f[i - 1][j] + 1;
            }
            updateWith(best, m);
        }
        for (j = 1; j <= m; j++)
        {
            int h = j + c[i].down;
            if (h <= m)
                updateWith(f[i - 1][h]);
        }
        check();
    }
}

int main()
{
    // freopen("bird.in", "r", stdin);
    // freopen("bird.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &c[i].up, &c[i].down);
    memset(f, -1, sizeof(f));
    for (int i = 1; i <= k; i++)
    {
        int P, L, H;
        scanf("%d%d%d", &P, &L, &H);
        for (int j = 1; j <= L; j++)
            f[P][j] = -2;
        for (int j = H; j <= m; j++)
            f[P][j] = -2;
        cnt[P] = 1;
    }
    init();
    dp();
    int ans = INF;
    for (int i = 1; i <= m; i++)
        if (f[n][i] >= 0)
            ans = min(ans, f[n][i]);
    printf("1\n%d", ans);
    return 0;
}