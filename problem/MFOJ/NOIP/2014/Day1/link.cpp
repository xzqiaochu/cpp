// 联合权值(link) (http://www.mfstem.org/contest/18/problem/B)
// author: xzqiaochu
// status: AC
#include <cstdio>
#include <algorithm>

#define next Next

using std::max;

const int MAXN = 2e5 + 7, MAXM = 2 * MAXN, P = 10007;

int n, point[MAXN];
int tot, head[MAXN], ver[MAXM], next[MAXM];
int maxL, sum;

inline void add(int x, int y)
{
    ver[++tot] = y;
    next[tot] = head[x], head[x] = tot;
}

int main()
{
    // freopen("link.in", "r", stdin);
    // freopen("link.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", point + i);
    for (int x = 1; x <= n; x++)
    {
        int s1 = 0, s2 = 0, max1 = 0, max2 = 0;
        for (int i = head[x]; i; i = next[i])
        {
            int y = ver[i];
            s1 = (s1 + point[y]) % P;
            s2 = (s2 + point[y] * point[y]) % P;
            if (point[y] > max1)
                max2 = max1, max1 = point[y];
            else if (point[y] > max2)
                max2 = point[y];
        }
        maxL = max(maxL, max1 * max2);
        sum = (sum + s1 * s1 - s2) % P;
    }
    printf("%d %d", maxL, sum);
    return 0;
}