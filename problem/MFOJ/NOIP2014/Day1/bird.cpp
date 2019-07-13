// 飞扬的小鸟(bird) (http://www.mfstem.org/contest/18/problem/C)
// author: xzqiaochu (Rewrite by kelvin's)
// status: AC
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using std::min;

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
    // 前缀和处理，用于失败时检测穿过了几个管道
    for (int i = 1; i <= n; i++)
        cnt[i] += cnt[i - 1];
    // dp边界初值（“小鸟从游戏界面最左边任意整数高度位置出发”）
    for (int i = 1; i <= m; i++)
        f[0][i] = 0;
}

// 使用val更新当前
inline void updateWith(int val, int j = j)
{
    if (val < 0) // 非法值过滤
        return;
    if (f[i][j] == -1) // 当前未被更新过，直接更新
        f[i][j] = val;
    else if (f[i][j] != -2) // 当前不是墙
        f[i][j] = min(f[i][j], val);
}

// 检查当前阶段是否有解（任何一个高度有解都可以），若无解则中止
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
        // 按若干次转移来的
        for (int k = 1; k <= c[i].up; k++) // 枚举 转移前（上一阶段）的位置
        {
            int best = f[i - 1][k] < 0 ? -1 : f[i - 1][k] + 1; // 保存到当前的最优解
            for (j = k + c[i].up; j <= m; j += c[i].up)        // 按 1，2，3... 次
            {
                if (best >= 0) // 可以转移到当前
                {
                    updateWith(best);
                    // 为下一次循环做准备
                    if (f[i - 1][j] >= 0)
                        best = min(best, f[i - 1][j]) + 1;
                    else
                        best++;
                }
                else
                {
                    // 为下一次循环做准备
                    if (f[i - 1][j] >= 0)
                        best = f[i - 1][j] + 1;
                }
            }
            // 到达顶部
            if (best >= 0)
                updateWith(best, m);
        }
        // 不按转移来的
        for (j = 1; j <= m; j++)
        {
            int h = j + c[i].down; // 上一阶段的高度
            if (h <= m && f[i - 1][h] >= 0) // 如果枚举的上一阶段的状态合法
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