// F - Wooden Sticks (https://vjudge.net/contest/316356#problem/F)
// from: POJ 1065
// author: xzqiaochu
// status: AC
#include <cstdio>
#include <cstring>
#include <algorithm>

const int SZ = 5007;

using std::sort;

int n;
struct Node
{
    int l, w;
} a[SZ];
bool v[SZ];

bool cmp(Node a, Node b)
{
    if (a.l != b.l)
        return a.l > b.l;
    else
        return a.w > b.w;
}

int calc()
{
    memset(v, 0, sizeof(v));
    int rst = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!v[i])
        {
            rst++, v[i] = true;
            int limit = a[i].w;
            for (int j = i + 1; j <= n; j++)
                if (!v[j] && a[j].w <= limit)
                    v[j] = true, limit = a[j].w;
        }
    }
    return rst;
}

int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            a[i].l = x, a[i].w = y;
        }
        sort(a + 1, a + n + 1, cmp);
        printf("%d\n", calc());
    }
    return 0;
}