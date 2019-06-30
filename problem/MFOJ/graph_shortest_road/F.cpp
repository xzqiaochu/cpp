// 最优乘车(bus) AC
#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>

#define next Next

using namespace std;

const int MAXN = 507, INF = 0x3f3f3f3f;

int n, m, s[MAXN];
int tot, head[MAXN], edge[MAXN], to[MAXN], next[MAXN];
int d[MAXN];
bool v[MAXN];
priority_queue< pair<int, int> > q;

void add(int x, int y, int z)
{
    edge[++tot] = z, to[tot] = y;
    next[tot] = head[x], head[x] = tot;
}

bool dijkstra()
{
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    q.push(make_pair(0, 1));
    while (!q.empty())
    {
        int x = q.top().second;
        q.pop();
        if (x == n)
            return true;
        if (v[x])
            continue;
        v[x] = true;
        for (int i = head[x]; i; i = next[i])
        {
            int y = to[i], z = edge[i];
            if (d[x] + z < d[y])
            {
                d[y] = d[x] + z;
                q.push(make_pair(-d[y], y));
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
    {
        int p = 0;
        for (char c = 1; c != '\n'; c = getchar())
            scanf("%d", &s[++p]);
        for (int j = 1; j <= p - 1; j++)
            for (int k = j + 1; k <= p; k++)
                add(s[j], s[k], 1); // 巴士单向运行，无需添加反向边
    }
    if (dijkstra())
        printf("%d", d[n] - 1);
    else
        printf("NO");
    return 0;
}