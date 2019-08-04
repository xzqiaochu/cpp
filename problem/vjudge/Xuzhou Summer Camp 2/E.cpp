// E - Dollar Dayz (https://vjudge.net/contest/316500#problem/E)
// POJ 3181
// from: USACO 2006 January Silver
// author: xzqiaochu
// status: WA
// 需要高精度 
#include <cstdio>
#include <algorithm>

using std::max;

const int SZN = 107, SZM = 1007, INF = 0x3f3f3f3f;

int n, m, c[SZN], f[SZM];

int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++)
        c[i] = i;
    for (int i = 1; i <= m; i++)
    	f[i] = -INF;
    f[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = c[i]; j <= m; j++)
        	f[j] = max(f[j], f[j - c[i]] + 1);
    printf("%d", f[m]);
    return 0;
}
