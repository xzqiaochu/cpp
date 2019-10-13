// 飞扬的小鸟(bird)
// http://www.mfstem.org/contest/18/problem/C
// https://www.luogu.org/problem/P1941
// author: xzqiaochu
// status: AC
// time: 2019/10/13
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

void updateBy(int val, int add)
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
        // 按若干次转移来的
        for (int k = 1; k <= c[i].up; k++) // 枚举 转移前（上一阶段）的位置 ？？？
        {
            int best = f[i - 1][k] < 0 ? -1 : f[i - 1][k] + 1; // 保存到当前的最优解
            for (j = k + c[i].up; j <= m; j += c[i].up)        // 按 1，2，3... 次
            {
                if (best >= 0) // 可以转移到当前
                {
                    updateBy(best, 0);
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
        }

        // 上一次未点击
        for (j = 1; j < m; j++)
        {
            if (f[i][j] == -2)
                continue;
            if (j + c[i].down <= m) // 上一次未点击
                updateBy(f[i - 1][j + c[i].down], 0);
        }
        // 碰顶（此时 j = m）
        for (int k = m, cnt = 1; k >= 1; k--)
        {
            updateBy(f[i - 1][k], cnt);
            if (k != m && (m - k) % c[i].up == 0)
                cnt++;
        }
        check();
    }
}

// void dp()
// {
//     for (i = 1; i <= n; i++)
//     {
//         for (j = 1; j <= m; j++)
//         {
//             if (f[i][j] == -2)
//                 continue;
//             if (j + c[i].down <= m) // 上一次未点击
//             	updateBy(f[i - 1][j + c[i].down], 0);
//             // 下面一个for循环浪费时间，时间复杂度为平方级
// 			for (int k = j - c[i].up, cnt = 1; k >= 1; k -= c[i].up, cnt++) // 上一次点击多次（但未上升到顶部）
// 				updateBy(f[i - 1][k], cnt);
// 			if (j == m) // 碰顶
// 				for (int k = m, cnt = 1; k >= 1; k--)
//                 {
//                     updateBy(f[i - 1][k], cnt);
//                     if (k != m && (m - k) % c[i].up == 0)
//                         cnt++;
//                 }
//         } 
//         check();
//     }
// }

void print_ans()
{
    int ans = INF;
    for (int i = 1; i <= m; i++)
        if (f[n][i] >= 0)
            ans = min(ans, f[n][i]);
    printf("1\n%d", ans);
}

void debug()
{
    for (int i = m; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
            printf("%2d ", f[j][i]);
        puts("");
    }
}

int main()
{
    // freopen("bird.in", "r", stdin);
    // freopen("bird.out", "w", stdout);
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
    // debug();
    print_ans();
    return 0;
}
