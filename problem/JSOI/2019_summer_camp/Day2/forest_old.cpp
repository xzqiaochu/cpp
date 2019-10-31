// 秀秀的森林（forest）
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <queue>

#define next Next

using namespace std;

typedef long long ll;

const int MAXN = 100007, P = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int n, point[MAXN];
int tot, head[MAXN], to[MAXN], num[MAXN], next[MAXN];
ll d[MAXN];
int deal_cnt, deal[MAXN];
int cnt[MAXN];

inline void add(int x, int y, int f)
{
    to[++tot] = y, num[tot] = f;
    next[tot] = head[x], head[x] = tot;
}

void dijkstra(int sta)
{
    priority_queue< pair<int, int> > q;
    bool v[MAXN];
    memset(d, 0x3f, sizeof(d));
    memset(v, 0, sizeof(v));
    d[sta] = point[sta];
    q.push(make_pair(-d[sta], sta));
    while (!q.empty())
    {
        int x = q.top().second;
        q.pop();
        if (v[x])
            continue;
        v[x] = true;
        if (!deal[x]) // 函数getD()处理标记
            deal[x] = true, deal_cnt++;
        for (int i = head[x]; i; i = next[i])
        {
            if (cnt[num[i]]) // 如果边i被砍掉
                continue;
            int y = to[i];
            if (d[x] + point[y] < d[y])
            {
                d[y] = d[x] + point[y];
                q.push(make_pair(-d[y], y));
            }
        }
    }
}

ll getTreeD(int sta)
{
    ll maxn = 0, rst = 0;
    int maxp;
    dijkstra(sta);
    for (int i = 1; i <= n; i++)
        if (d[i] != INF && d[i] > maxn)
            maxp = i, maxn = d[i];
    dijkstra(maxp);
    for (int i = 1; i <= n; i++)
        if (d[i] != INF)
            rst = max(rst, d[i]);
    return rst;
}

ll getD()
{
    ll d = 1;
    memset(deal, 0, sizeof(deal));
    deal_cnt = 0;
    while (deal_cnt < n)
    {
        int now_d;
        for (int i = 1; i <= n; i++)
            if (!deal[i])
            {
                now_d = getTreeD(i) % P;
                break;
            }
        d = d * now_d % P;
    }
    return d;
}

int main()
{
    // freopen("forest.in", "r", stdin);
    // freopen("forest.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", point + i);
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y, i), add(y, x, i);
    }
    printf("%lld\n", getD());
    for (int i = 1; i <= n - 1; i++)
    {
        int temp;
        scanf("%d", &temp);
        cnt[temp] = true;
        printf("%lld\n", getD());
    }
    return 0;
}