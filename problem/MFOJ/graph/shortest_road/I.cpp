// 分糖果(candy) AC
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <queue>

#define next Next

using namespace std;

const int MAXN = 1e5 + 7, MAXM = 2e6 + 7;

int n, m, sta, b, ans;
int tot, head[MAXN], to[MAXM], next[MAXM];
int d[MAXM];
bool v[MAXM];
priority_queue< pair<int, int> > q;

void add(int x, int y)
{
    to[++tot] = y;
    next[tot] = head[x], head[x] = tot;
}

void dijkstra()
{
    memset(d, 0x3f, sizeof(d));
    d[sta] = 0;
    q.push(make_pair(0, sta));
    while (!q.empty())
    {
        int x = q.top().second;
        q.pop();
        if (v[x])
            continue;
        v[x] = true;
        for (int i = head[x]; i; i = next[i])
        {
            int y = to[i];
            if (d[x] + 1 < d[y])
            {
                d[y] = d[x] + 1;
                q.push(make_pair(-d[y], y));
            }
        }
    }
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &sta, &b);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
    }
    dijkstra();
    for (int i = 1; i <= n; i++)
        ans = max(ans, d[i]);
    ans += b + 1;
    printf("%d", ans);
    return 0;
}