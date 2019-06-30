// 城市路(Dijkstra) AC
#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>

#define next Next

using namespace std;

const int MAXN = 2007, MAXM = 20007;

int n, m;
int tot, head[MAXN], edge[MAXM], to[MAXM], next[MAXM];
int d[MAXN];
bool v[MAXN];
priority_queue< pair<int, int> > q;

inline void add(int x, int y, int z)
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
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z), add(y, x, z);
    }
    if (dijkstra())
        printf("%d", d[n]);
    else
        printf("-1");
    return 0;
}