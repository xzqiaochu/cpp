// 热浪(heatwv) AC
#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>

#define next Next

using namespace std;

const int MAXN = 2507, MAXM = 6207 * 2;

int n, m, sta, tar;
int tot, head[MAXN], edge[MAXM], to[MAXM], next[MAXM];
int d[MAXN];
bool v[MAXN];

priority_queue< pair<int, int> > q;

void dijkstra()
{
    memset(d, 0x3f, sizeof(d));
    d[sta] = 0;
    q.push(make_pair(0, sta));
    while (!q.empty())
    {
        int x = q.top().second;
        q.pop();
        if (x == tar)
            return;
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
}

void add(int x, int y, int z)
{
    edge[++tot] = z, to[tot] = y;
    next[tot] = head[x], head[x] = tot;
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &sta, &tar);
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z), add(y, x, z);
    }
    dijkstra();
    printf("%d", d[tar]);
    return 0;
}